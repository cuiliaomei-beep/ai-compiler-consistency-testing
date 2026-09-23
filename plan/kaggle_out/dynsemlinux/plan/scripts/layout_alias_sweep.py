"""7.1 Layout / view / alias sweep: same values, different memory layout; forward and backward.

For every OpInfo operator (float32 samples) the primary tensor input is rebuilt with the same values but another
layout, one layout at a time:
  transposed   non-contiguous strides of a transposed buffer
  offset       a view that starts at storage_offset 3 inside a larger buffer
  step2        every other element of a buffer twice as long in the last dim (stride 2)
  expanded     stride 0 along dim 0 (values of row 0 repeated; skipped for ops that write to the input)
  overlap      as_strided view whose elements share memory (strides 1; read-only ops)
  chlast       channels_last / channels_last_3d for 4-D / 5-D inputs
  alias_arg    another tensor argument of the same shape is replaced by the primary input itself (shared memory)
Each variant is executed in eager and under torch.compile (default inductor); forward outputs and the gradients
of all floating inputs are compared with sweep_common.compare against a float64 eager reference, so only results
that are much farther from the truth than eager are flagged.  Output strides and exception parity are recorded too.

    python scripts/layout_alias_sweep.py --isolate [--backend inductor] [--samples 1]
    python scripts/layout_alias_sweep.py --only addmm,nn.functional.linear --verbose
    python scripts/layout_alias_sweep.py --report
"""
import argparse
import json
import os
import re
import sys
import traceback

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402
from torch.utils._pytree import tree_map  # noqa: E402

from tcc.sweep_common import compare, exc_info, jsonl_append, run_isolated, tensors_of, to_double  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SKIP = re.compile(r"empty|rand|normal|bernoulli|dropout|multinomial|uniform|geometric|exponential|cauchy|poisson|"
                  r"^resize|^as_strided|set_|^to_sparse|sparse|^nn.functional.rrelu|^bfloat16|^view_as|_like$|^new_|"
                  r"^item$|^tolist|^unique|^nonzero|^masked_select|^argwhere|^jiterator|^torch.ops|^_|^fill|^zero_")


def rebuild(t, kind):
    """Return a tensor with t's values (except 'expanded') and the requested layout, or None if not applicable."""
    if kind == "transposed":
        if t.dim() < 2:
            return None
        return t.transpose(-1, -2).contiguous().transpose(-1, -2)
    if kind == "offset":
        buf = torch.full((t.numel() + 3,), 7.0, dtype=t.dtype)
        v = buf[3:].view(t.shape)
        v.copy_(t)
        return v
    if kind == "step2":
        if t.dim() < 1 or t.shape[-1] == 0:
            return None
        buf = torch.full((*t.shape[:-1], t.shape[-1] * 2), 7.0, dtype=t.dtype)
        v = buf[..., ::2]
        v.copy_(t)
        return v
    if kind == "expanded":
        if t.dim() < 1 or t.shape[0] < 2:
            return None
        return t[:1].clone().expand(t.shape)
    if kind == "overlap":
        if t.dim() < 2 or t.numel() < 2:
            return None
        need = sum(s - 1 for s in t.shape) + 1
        base = t.flatten()[:need].clone() if t.numel() >= need else None
        if base is None:
            return None
        return torch.as_strided(base, t.shape, (1,) * t.dim())
    if kind == "chlast":
        if t.dim() == 4:
            return t.contiguous(memory_format=torch.channels_last)
        if t.dim() == 5:
            return t.contiguous(memory_format=torch.channels_last_3d)
        return None
    raise ValueError(kind)


KINDS = ["transposed", "offset", "step2", "expanded", "overlap", "chlast", "alias_arg"]


def clone_like(x):
    """Clone a tensor preserving its layout (as_strided copy of the underlying storage region)."""
    if not isinstance(x, torch.Tensor):
        return x
    if x.numel() == 0 or not x.is_floating_point() and x.is_contiguous():
        return x.clone()
    st = x.untyped_storage()
    buf = torch.empty(st.nbytes() // x.element_size(), dtype=x.dtype)
    buf.copy_(torch.as_strided(x, (buf.numel(),), (1,), 0)) if buf.numel() else None
    return torch.as_strided(buf, x.shape, x.stride(), x.storage_offset())


def make_fn(op, n_args, kw_keys):
    def f(*flat):
        inp, args, kwv = flat[0], flat[1:1 + n_args], flat[1 + n_args:]
        return op.op(inp, *args, **dict(zip(kw_keys, kwv)))
    return f


def run_once(fn, flat, grad_idx, backend):
    flat = [clone_like(x) for x in flat]
    for i in grad_idx:
        flat[i] = flat[i].detach().requires_grad_(True)
    g = fn if backend is None else torch.compile(fn, backend=backend)
    out = g(*flat)
    outs = [t for t in tensors_of(out)]
    grads = []
    fouts = [o for o in outs if o.is_floating_point() and o.requires_grad]
    if grad_idx and fouts:
        loss = sum((o * torch.arange(1, o.numel() + 1, dtype=o.dtype).reshape(o.shape) / max(o.numel(), 1)).sum() for o in fouts)
        gs = torch.autograd.grad(loss, [flat[i] for i in grad_idx], allow_unused=True)
        grads = [torch.zeros(()) if x is None else x for x in gs]
    strides = [tuple(o.stride()) for o in outs]
    return [o.detach() for o in outs], [x.detach() for x in grads], strides


def check_variant(op, sample, kind, backend, verbose):
    inp = sample.input
    if not isinstance(inp, torch.Tensor) or not inp.is_floating_point():
        return None
    args, kwargs = list(sample.args), dict(sample.kwargs)
    if kind == "alias_arg":
        idx = [i for i, a in enumerate(args) if isinstance(a, torch.Tensor) and a.shape == inp.shape and a.dtype == inp.dtype and a.numel() > 0]
        if not idx:
            return None
        new_inp = inp.detach().clone()
        args[idx[0]] = new_inp
    else:
        new_inp = rebuild(inp.detach(), kind)
        if new_inp is None:
            return None
    kw_keys = list(kwargs)
    flat = [new_inp] + [a.detach() if isinstance(a, torch.Tensor) else a for a in args] + [kwargs[k] for k in kw_keys]
    if kind == "alias_arg":
        flat[1 + idx[0]] = flat[0]
    fn = make_fn(op, len(args), kw_keys)
    grad_idx = []
    if op.supports_autograd and kind not in ("expanded", "overlap", "alias_arg"):
        grad_idx = [i for i, x in enumerate(flat[:1 + len(args)]) if isinstance(x, torch.Tensor) and x.is_floating_point()]
    rec = {"kind": kind, "strides_in": tuple(new_inp.stride()), "shape": tuple(new_inp.shape)}

    def alias_fix(fl):
        if kind == "alias_arg":
            fl = list(fl)
            fl[1 + idx[0]] = fl[0]
        return fl

    def call(bk, dbl=False):
        fl = [to_double(x) if (dbl and isinstance(x, torch.Tensor)) else x for x in flat]
        return run_once(lambda *f_: fn(*alias_fix(f_)), fl, grad_idx, bk)

    e = c = e_exc = c_exc = None
    try:
        e = call(None)
    except Exception as ex:  # noqa: BLE001
        e_exc = ex
    torch._dynamo.reset()
    try:
        c = call(backend)
    except Exception as ex:  # noqa: BLE001
        c_exc = ex
    if e_exc is not None or c_exc is not None:
        if (e_exc is None) != (c_exc is None):
            rec.update(category="raise", eager=exc_info(e_exc)[:200] if e_exc else "returned", compiled=exc_info(c_exc)[:300] if c_exc else "returned")
            return rec
        return None
    try:
        ref = call(None, dbl=True)
    except Exception:  # noqa: BLE001
        ref = (None, None, None)
    v, d = compare(e[0], c[0], ref[0])
    if v != "ok":
        rec.update(category="forward_" + v, detail=d)
        return rec
    if grad_idx:
        v, d = compare(e[1], c[1], ref[1], rtol=1e-3, atol=1e-4)
        if v != "ok":
            rec.update(category="grad_" + v, detail=d)
            return rec
    if e[2] != c[2]:
        rec.update(category="stride", detail=f"eager {e[2]} vs compiled {c[2]}")
        return rec
    if verbose:
        print(f"      {kind}: ok", flush=True)
    return None


def report(path):
    from collections import Counter
    import glob
    rows = []
    for f in sorted(glob.glob(path.replace(".jsonl", "*.jsonl"))):
        rows += [json.loads(l) for l in open(f, encoding="utf-8") if l.strip()]
    print(len(rows), "ops |", dict(Counter(r["verdict"] for r in rows)))
    cats = Counter(f["category"] for r in rows for f in r.get("findings", []))
    print("findings by category:", dict(cats))
    for r in rows:
        if r["verdict"] == "CRASH":
            print(f"[CRASH] {r['op']} rc={r.get('returncode')} {r.get('tail', '')[-160:]!r}")
        for f in r.get("findings", []):
            if f["category"] in ("stride",):
                continue
            print(f"[{f['category']}] {r['op']} sample {f.get('sample')} {f['kind']} shape={f.get('shape')} strides={f.get('strides_in')}: "
                  f"{(f.get('detail') or (f.get('eager', '') + ' || ' + f.get('compiled', '')))[:230]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backend", default="inductor")
    ap.add_argument("--samples", type=int, default=1)
    ap.add_argument("--kinds", default=",".join(KINDS))
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--shard", default=None, help="i/n: run only every n-th operator starting at i (parallel drivers)")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "layout_alias", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    ops = [o for o in op_db if torch.float32 in o.dtypes and not SKIP.search(o.name)]
    names = a.only.split(",") if a.only else sorted({o.name for o in ops})
    if a.shard:
        i, n = map(int, a.shard.split("/"))
        names = names[i::n]
    if a.isolate:
        run_isolated(os.path.abspath(__file__), names, ["--backend", a.backend, "--samples", str(a.samples), "--kinds", a.kinds],
                     a.out_jsonl, timeout=2400)
        return
    kinds = a.kinds.split(",")
    for name in names:
        findings = []
        for op in [o for o in ops if o.name == name][:2]:
            try:
                samples = list(op.sample_inputs("cpu", torch.float32, requires_grad=False))
            except Exception as e:  # noqa: BLE001
                findings.append({"category": "harness", "kind": "-", "detail": exc_info(e)[:200]})
                continue
            # prefer samples whose input has >= 2 dims and > 1 element
            samples.sort(key=lambda s: -(isinstance(s.input, torch.Tensor) and s.input.dim() >= 2 and s.input.numel() > 1))
            for si, s in enumerate(samples[:a.samples]):
                for k in kinds:
                    try:
                        r = check_variant(op, s, k, a.backend, a.verbose)
                    except Exception as e:  # noqa: BLE001
                        r = {"category": "harness", "kind": k, "detail": exc_info(e)[:240], "tb": traceback.format_exc()[-400:]}
                    if r:
                        r["sample"] = si
                        r["variant_name"] = op.variant_test_name
                        findings.append(r)
        cats = sorted({f["category"] for f in findings})
        jsonl_append(a.out_jsonl, {"op": name, "verdict": ",".join(cats) or "ok", "findings": findings})
        real = [c for c in cats if c not in ("stride", "harness")]
        if real:
            print(f"  !! {name}: {real}", flush=True)


if __name__ == "__main__":
    main()
