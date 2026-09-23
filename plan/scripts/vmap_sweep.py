"""6.4e: torch.func.vmap through torch.compile vs eager vmap vs an explicit python loop, for OpInfo operators.

Three ways to batch the same operator over a leading dim of size B:
  loop      : torch.stack([f(x[i]) for i in range(B)])           (ground truth, eager)
  vmap      : torch.func.vmap(f)(x)                              (eager batching rules)
  cvmap     : torch.compile(lambda x: torch.func.vmap(f)(x))(x)  (Dynamo traces vmap; aot_eager by default)
Flag when cvmap differs from loop beyond tolerance while vmap agrees, or when cvmap raises and vmap does not.

    python scripts/vmap_sweep.py [--only ...] [--backend aot_eager] [--skip ...] [--out results/vmap]
"""
import argparse
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
B = 3


def outs_of(o):
    outs = o if isinstance(o, (tuple, list)) else [o]
    return [t for t in outs if isinstance(t, torch.Tensor)]


def run_three(fn, sample, backend):
    inp = sample.input
    if not isinstance(inp, torch.Tensor) or inp.dim() == 0:
        return None
    args, kwargs = sample.args, sample.kwargs
    x = torch.stack([inp.detach() * (1 + 0.1 * i) for i in range(B)])

    def f(a):
        return tuple(outs_of(fn(a, *args, **kwargs)))

    loop = [torch.stack(ts) for ts in zip(*[f(x[i]) for i in range(B)])]
    vm = list(torch.func.vmap(f)(x))
    torch._dynamo.reset()
    cv = list(torch.compile(lambda x: torch.func.vmap(f)(x), backend=backend)(x))
    return loop, vm, cv


def maxdiff(a, b):
    worst, scale = 0.0, 1e-30
    for x, y in zip(a, b):
        if x.shape != y.shape:
            return float("inf"), 1.0
        if x.numel() == 0:
            continue
        fx = torch.isfinite(x)
        if not torch.equal(fx, torch.isfinite(y)):
            return float("inf"), 1.0
        if fx.any():
            xd, yd = x.to(torch.complex128 if x.is_complex() else torch.float64), y.to(torch.complex128 if y.is_complex() else torch.float64)
            worst = max(worst, (xd - yd)[fx].abs().max().item())
            scale = max(scale, xd[fx].abs().max().item())
    return worst, scale


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--skip", default="")
    ap.add_argument("--backend", default="aot_eager")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "vmap"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    only = set(a.only.split(",")) if a.only else None
    skip = set(a.skip.split(",")) if a.skip else set()
    ops = [o for o in op_db if torch.float32 in o.dtypes and (not only or o.name in only) and o.name not in skip]
    print(f"torch {torch.__version__} | {len(ops)} ops | backend {a.backend}")
    rows, flagged, t0 = [], [], time.time()
    for i, oi in enumerate(ops):
        if a.verbose:
            print(f"  > {oi.name}", flush=True)
        try:
            s = next(iter(oi.sample_inputs("cpu", torch.float32, requires_grad=False)))
        except Exception:
            continue
        fn = oi.get_op()
        try:
            r = run_three(fn, s, a.backend)
            if r is None:
                continue
            loop, vm, cv = r
        except Exception as e:  # noqa: BLE001
            msg = f"{type(e).__name__}: {str(e).splitlines()[0][:120]}"
            # only interesting if eager vmap itself works
            try:
                inp = s.input
                x = torch.stack([inp.detach() * (1 + 0.1 * k) for k in range(B)])
                torch.func.vmap(lambda a_: tuple(outs_of(fn(a_, *s.args, **s.kwargs))))(x)
                rows.append({"op": oi.name, "error": msg}); flagged.append(rows[-1])
                print(f"  FLAG {oi.name:<34} compiled vmap raised: {msg}", flush=True)
            except Exception:
                rows.append({"op": oi.name, "skipped": msg})
            continue
        if len(loop) != len(cv):
            rows.append({"op": oi.name, "error": f"output count {len(loop)} vs {len(cv)}"}); flagged.append(rows[-1]); continue
        dv, sc = maxdiff(loop, vm)
        dc, _ = maxdiff(loop, cv)
        rec = {"op": oi.name, "vmap_err": dv, "cvmap_err": dc, "scale": sc}
        rec["flag"] = dc > max(4 * dv, 1e-4 * max(sc, 1.0))
        rows.append(rec)
        if rec["flag"]:
            flagged.append(rec)
            print(f"  FLAG {oi.name:<34} vmap err {dv:.1e} | compiled vmap err {dc:.1e} (scale {sc:.1e})", flush=True)
        if i % 50 == 49:
            print(f"  ... {i + 1}/{len(ops)} ({time.time() - t0:.0f}s, {len(flagged)} flagged)", flush=True)
    json.dump(rows, open(os.path.join(a.out, "vmap.json"), "w"), indent=1, default=str)
    lines = [f"# vmap through compile ({a.backend}, torch {torch.__version__})", "", f"- ops: {len(ops)}, rows: {len(rows)}, flagged: {len(flagged)}; wall {time.time() - t0:.0f} s", "", "| op | finding |", "|---|---|"]
    for r in flagged:
        lines.append(f"| {r['op']} | {r.get('error') or f'vmap {r['vmap_err']:.1e} vs compiled vmap {r['cvmap_err']:.1e} (scale {r['scale']:.1e})'} |")
    open(os.path.join(a.out, "VMAP.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"ops": len(ops), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))


if __name__ == "__main__":
    main()
