"""11.4  Every OpInfo op x edge-value inputs x low-precision / small-int dtypes: eager vs torch.compile (Inductor).

For each op and dtype, the OpInfo sample inputs are taken and every floating / integer tensor argument is overwritten
with a cycle of edge values of its dtype (0, -0.0, +-1, +-inf, nan, +-max, +-min, tiny, +-0.5, 2^24+1, ... for floats;
0, +-1, min, max, min+1, max-1, -128/127-crossing values for ints), keeping shape and strides.  Eager and compiled outputs
are compared exactly for bool / int outputs and by NaN pattern + infinities + sign of zero + relative 1e-3 for floats.
Self-contained (no project imports) so that the same file runs on Kaggle.

    python scripts/opinfo_edge_sweep.py --dtypes float16,bfloat16,int8,uint8,int16,bool --shard 0/4 --out results/opinfo_edge/cases_0.jsonl
    python scripts/opinfo_edge_sweep.py --report results/opinfo_edge/*.jsonl
"""
import argparse
import glob
import itertools
import json
import math
import os
import sys
import time
import traceback

import torch

try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env  # noqa: E402

    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass

from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

torch._dynamo.config.recompile_limit = 64
torch._dynamo.config.capture_scalar_outputs = True
torch._dynamo.config.capture_dynamic_output_shape_ops = True
torch._inductor.config.fallback_random = True

SKIP_SUBSTR = ("random", "rand", "bernoulli", "multinomial", "dropout", "rrelu", "normal", "uniform", "exponential", "geometric",
               "cauchy", "log_normal", "poisson", "empty", "new_empty", "resize", "_unsafe", "nondeterministic", "svd", "eig",
               "lstsq", "qr", "lu", "cholesky", "pinv", "matrix_rank", "inverse", "solve", "det", "logdet", "slogdet", "norm.nuc",
               "histogram", "fft", "stft", "istft", "unique", "nonzero", "argwhere", "masked_select", "index_reduce", "signal.windows",
               "sort", "argsort", "topk", "kthvalue", "msort", "median", "nanmedian", "mode", "searchsorted", "bucketize", "_chunk_cat",
               "nn.functional.embedding_bag", "nn.functional.ctc_loss", "nn.functional.grid_sample", "nn.functional.interpolate",
               "nn.functional.upsample", "nn.functional.max_unpool", "nn.functional.fractional_max_pool", "special.zeta")


def float_edges(dtype):
    fi = torch.finfo(dtype)
    return [0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 2.0, -2.5, float("inf"), float("-inf"), float("nan"), fi.max, -fi.max, fi.min if fi.min > 0 else fi.tiny,
            fi.tiny, -fi.tiny, fi.eps, 1.0 + fi.eps, 3.0, 65504.0, -65504.0, 1e4, -1e4, 0.1, 1e-3, 255.0, 256.0, 1e30 if fi.max > 1e30 else fi.max / 2]


def int_edges(dtype):
    ii = torch.iinfo(dtype)
    vals = [0, 1, -1, 2, -2, 3, 7, -7, ii.min, ii.max, ii.min + 1, ii.max - 1, 127, -128, 128, 255, 256, -129, 100, -100, 64, -64]
    return [v for v in vals if ii.min <= v <= ii.max]


def edge_fill(t, dtype):
    n = t.numel()
    if n == 0:
        return t
    if dtype == torch.bool:
        vals = [True, False, True, True, False]
    elif dtype.is_floating_point:
        vals = float_edges(dtype)
    elif dtype.is_complex:
        return t
    else:
        vals = int_edges(dtype)
    seq = list(itertools.islice(itertools.cycle(vals), n))
    new = torch.tensor(seq, dtype=dtype).reshape(t.shape)
    if t.is_contiguous():
        return new
    out = torch.empty_strided(t.shape, t.stride(), dtype=dtype)
    out.copy_(new)
    return out


def replace(sample, dtype):
    def rep(x):
        if isinstance(x, torch.Tensor) and x.dtype == dtype and not x.requires_grad:
            return edge_fill(x.detach().clone(), dtype)
        if isinstance(x, (list, tuple)):
            return type(x)(rep(y) for y in x)
        if isinstance(x, dict):
            return {k: rep(v) for k, v in x.items()}
        return x
    return rep(sample.input), rep(sample.args), rep(sample.kwargs)


def flat(o):
    if isinstance(o, torch.Tensor):
        return [o]
    if isinstance(o, (list, tuple)) or hasattr(o, "_fields"):
        return [t for x in tuple(o) for t in flat(x)]
    if isinstance(o, dict):
        return [t for x in o.values() for t in flat(x)]
    return []


def diff(e, c):
    if e.shape != c.shape or e.dtype != c.dtype:
        return f"shape/dtype {tuple(e.shape)} {e.dtype} vs {tuple(c.shape)} {c.dtype}"
    if e.numel() == 0:
        return None
    if e.is_complex():
        e, c = torch.view_as_real(e.resolve_conj()), torch.view_as_real(c.resolve_conj())
    if not e.dtype.is_floating_point:
        if not torch.equal(e, c):
            idx = (e != c).nonzero()[0].tolist()
            return f"value at {idx}: eager {e[tuple(idx)].item()!r} compiled {c[tuple(idx)].item()!r}"
        return None
    e64, c64 = e.double(), c.double()
    if not torch.equal(e64.isnan(), c64.isnan()):
        idx = (e64.isnan() != c64.isnan()).nonzero()[0].tolist()
        return f"nan pattern at {idx}: eager {e64[tuple(idx)].item()!r} compiled {c64[tuple(idx)].item()!r}"
    m = ~e64.isnan()
    if not torch.equal(e64[m].isinf(), c64[m].isinf()) or not torch.equal(e64[m][e64[m].isinf()], c64[m][c64[m].isinf()]):
        bad = ((e64.isinf() != c64.isinf()) | (e64.isinf() & (e64 != c64))) & m
        idx = bad.nonzero()[0].tolist()
        return f"inf at {idx}: eager {e64[tuple(idx)].item()!r} compiled {c64[tuple(idx)].item()!r}"
    fin = m & ~e64.isinf()
    a, b = e64[fin], c64[fin]
    rel = (a - b).abs() / (a.abs() + b.abs()).clamp(min=1.0)
    tol = 1e-2 if e.dtype in (torch.float16, torch.bfloat16) else 1e-4
    if rel.numel() and rel.max().item() > tol:
        k = rel.argmax().item()
        return f"value rel {rel.max().item():.3g}: eager {a[k].item()!r} compiled {b[k].item()!r}"
    z = fin & (e64 == 0)
    if z.any() and not torch.equal(torch.signbit(e64[z]), torch.signbit(c64[z])):
        return "sign of zero"
    return None


def run_one(op, dtype, max_samples, out_path):
    rec = {"op": op.name, "dtype": str(dtype).split(".")[-1], "samples": 0, "diffs": [], "errors": []}
    try:
        samples = list(itertools.islice(op.sample_inputs("cpu", dtype, requires_grad=False), max_samples))
    except Exception as e:  # noqa: BLE001
        rec["verdict"] = "NO_SAMPLES:" + type(e).__name__
        return rec
    fn = op.get_op()
    for si, s in enumerate(samples):
        try:
            inp, args, kwargs = replace(s, dtype)
        except Exception as e:  # noqa: BLE001
            rec["errors"].append(f"prep {type(e).__name__}"); continue
        try:
            eager = fn(inp, *args, **kwargs)
            eager_err = None
        except Exception as e:  # noqa: BLE001
            eager, eager_err = None, type(e).__name__
        torch._dynamo.reset()
        try:
            cf = torch.compile(fn, dynamic=False)
            comp = cf(inp, *args, **kwargs)
            comp_err = None
        except Exception as e:  # noqa: BLE001
            comp, comp_err = None, type(e).__name__
        rec["samples"] += 1
        if eager_err or comp_err:
            if eager_err and not comp_err:
                rec["diffs"].append({"i": si, "class": "SILENT", "detail": f"eager raises {eager_err}, compiled returns"})
            elif comp_err and not eager_err:
                if comp_err not in ("BackendCompilerFailed", "Unsupported", "InductorError", "LoweringException", "TorchRuntimeError"):
                    rec["diffs"].append({"i": si, "class": "RAISES", "detail": f"compiled raises {comp_err}"})
                else:
                    rec["errors"].append(f"compile {comp_err}")
            continue
        fe, fc = flat(eager), flat(comp)
        if len(fe) != len(fc):
            rec["diffs"].append({"i": si, "class": "STRUCT", "detail": f"{len(fe)} vs {len(fc)} tensors"}); continue
        for e, c in zip(fe, fc):
            d = diff(e, c)
            if d:
                rec["diffs"].append({"i": si, "class": "SIGNZERO" if d == "sign of zero" else "VALUE", "detail": d, "repr": repr(s)[:300]})
                break
    classes = sorted({d["class"] for d in rec["diffs"]})
    rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
    return rec


def done_keys(path):
    keys = set()
    if os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            try:
                r = json.loads(line); keys.add((r["op"], r["dtype"]))
            except Exception:  # noqa: BLE001
                pass
    return keys


def report(paths):
    rows = []
    for p in paths:
        for line in open(p, encoding="utf-8"):
            try:
                rows.append(json.loads(line))
            except Exception:  # noqa: BLE001
                pass
    print(f"{len(rows)} (op, dtype) pairs; verdicts:", {v: sum(1 for r in rows if r['verdict'].split(':')[0] == v) for v in sorted({r['verdict'].split(':')[0] for r in rows})})
    for r in sorted(rows, key=lambda r: (r["op"], r["dtype"])):
        if r["verdict"].startswith("DIFF"):
            print(f"\n[{r['verdict']}] {r['op']} {r['dtype']}  ({r['samples']} samples)")
            seen = set()
            for d in r["diffs"]:
                k = (d["class"], d["detail"][:40])
                if k in seen:
                    continue
                seen.add(k)
                print(f"    #{d['i']} {d['class']:6s} {d['detail'][:200]}" + (f"   <- {d['repr'][:160]}" if d.get("repr") else ""))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dtypes", default="float16,bfloat16,int8,uint8,int16,bool")
    ap.add_argument("--shard", default="0/1")
    ap.add_argument("--max-samples", type=int, default=3)
    ap.add_argument("--only", default=None)
    ap.add_argument("--out", default=None)
    ap.add_argument("--report", nargs="*", default=None)
    a = ap.parse_args()
    if a.report is not None:
        return report([p for pat in (a.report or ["results/opinfo_edge/*.jsonl"]) for p in glob.glob(pat)])
    k, n = map(int, a.shard.split("/"))
    out = a.out or f"results/opinfo_edge/cases_{k}.jsonl"
    os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
    dtypes = [getattr(torch, d) for d in a.dtypes.split(",")]
    ops = [op for op in op_db if not any(s in op.name for s in SKIP_SUBSTR) and (a.only is None or op.name == a.only)]
    work = [(op, dt) for op in ops for dt in dtypes if op.supports_dtype(dt, "cpu")]
    work = work[k::n]
    done = done_keys(out)
    marker = out + ".inprogress"          # a pair that was running when the process died (e.g. SIGFPE on int div by zero) is recorded as CRASH
    if os.path.exists(marker):
        crashed = open(marker, encoding="utf-8").read().strip().split("	")
        if len(crashed) == 2 and tuple(crashed) not in done:
            with open(out, "a", encoding="utf-8") as f:
                f.write(json.dumps({"op": crashed[0], "dtype": crashed[1], "samples": 0, "diffs": [{"i": -1, "class": "CRASH", "detail": "process died"}], "errors": [], "verdict": "DIFF:CRASH"}) + "
")
            done.add(tuple(crashed))
        os.remove(marker)
    todo = [(op, dt) for op, dt in work if (op.name, str(dt).split(".")[-1]) not in done]
    print(f"torch {torch.__version__}: {len(ops)} ops, {len(work)} (op, dtype) in shard {a.shard}, {len(todo)} to do", flush=True)
    t0 = time.time()
    for i, (op, dt) in enumerate(todo):
        t = time.time()
        with open(marker, "w", encoding="utf-8") as f:
            f.write(f"{op.name}	{str(dt).split('.')[-1]}")
        try:
            rec = run_one(op, dt, a.max_samples, out)
        except Exception as e:  # noqa: BLE001
            rec = {"op": op.name, "dtype": str(dt).split(".")[-1], "verdict": "TOOL_ERROR", "diffs": [], "errors": [traceback.format_exc()[-300:]]}
        with open(out, "a", encoding="utf-8") as f:
            f.write(json.dumps(rec) + "\n")
        print(f"[{i + 1}/{len(todo)}] {rec['verdict']:12s} {op.name} {rec['dtype']} ({time.time() - t:.0f}s, total {time.time() - t0:.0f}s)", flush=True)
    if os.path.exists(marker):
        os.remove(marker)
    print("SWEEP DONE", flush=True)


if __name__ == "__main__":
    main()
