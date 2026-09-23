"""6.4c: second-order gradients under torch.compile. For every OpInfo operator with supports_gradgrad, compute
g = d loss/d x with create_graph=True, then h = d (g*w).sum() / d x, in eager and with the op compiled
(aot_eager by default; no C++). Compare g and h with float64 eager truth.

    python scripts/double_backward_sweep.py [--only ...] [--backend aot_eager] [--out results/double_backward]
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


def second_order(fn, sample, dtype):
    def cast(t):
        if isinstance(t, torch.Tensor) and t.is_floating_point():
            return t.detach().to(dtype).requires_grad_(t.requires_grad)
        return t
    inp, args = cast(sample.input), [cast(a) for a in sample.args]
    kwargs = {k: cast(v) for k, v in sample.kwargs.items()}
    leaves = [t for t in [inp, *args, *kwargs.values()] if isinstance(t, torch.Tensor) and t.requires_grad]
    if not leaves:
        return None
    out = fn(inp, *args, **kwargs)
    outs = out if isinstance(out, (tuple, list)) else [out]
    loss = None
    for o in outs:
        if isinstance(o, torch.Tensor) and o.is_floating_point() and o.requires_grad:
            term = (o.sin() * o).sum()          # non-quadratic so the second derivative is informative
            loss = term if loss is None else loss + term
    if loss is None:
        return None
    gs = torch.autograd.grad(loss, leaves, create_graph=True, allow_unused=True)
    gsum = None
    for g_, l in zip(gs, leaves):
        if g_ is not None and g_.requires_grad:
            w = torch.arange(g_.numel(), dtype=g_.dtype).reshape(g_.shape) / max(g_.numel(), 1) + 0.5
            term = (g_ * w).sum()
            gsum = term if gsum is None else gsum + term
    if gsum is None or not gsum.requires_grad:
        return [g_.detach() if g_ is not None else None for g_ in gs], None
    hs = torch.autograd.grad(gsum, leaves, allow_unused=True)
    return [g_.detach() if g_ is not None else None for g_ in gs], [h.detach() if h is not None else None for h in hs]


def maxerr(xs, truth):
    worst, scale = 0.0, 1e-30
    if xs is None or truth is None:
        return (0.0 if xs is truth else float("inf")), 1.0
    for x, t in zip(xs, truth):
        if (x is None) != (t is None):
            return float("inf"), 1.0
        if x is None or t.numel() == 0:
            continue
        fin = torch.isfinite(t)
        if not torch.equal(torch.isfinite(x), fin):
            return float("inf"), 1.0
        if fin.any():
            worst = max(worst, (x.double() - t.double())[fin].abs().max().item())
            scale = max(scale, t[fin].abs().max().item())
    return worst, scale


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backend", default="aot_eager")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "double_backward"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    only = set(a.only.split(",")) if a.only else None
    ops = [o for o in op_db if o.supports_autograd and o.supports_gradgrad and torch.float32 in o.dtypes and (not only or o.name in only)]
    print(f"torch {torch.__version__} | {len(ops)} ops with gradgrad | backend {a.backend}")
    rows, flagged, t0 = [], [], time.time()
    for i, oi in enumerate(ops):
        try:
            s = next(iter(oi.sample_inputs("cpu", torch.float32, requires_grad=True)))
        except Exception:
            continue
        fn = oi.get_op()
        try:
            truth = second_order(fn, s, torch.float64)
            eag = second_order(fn, s, torch.float32)
            if truth is None or eag is None:
                continue
            torch._dynamo.reset()
            comp = second_order(torch.compile(fn, backend=a.backend), s, torch.float32)
            if comp is None:
                continue
        except Exception as e:  # noqa: BLE001
            msg = f"{type(e).__name__}: {str(e).splitlines()[0][:120]}"
            rows.append({"op": oi.name, "error": msg})
            # eager itself raising is not a compile problem; only flag when eager worked
            try:
                second_order(fn, s, torch.float32)
                flagged.append({"op": oi.name, "error": msg}); print(f"  FLAG {oi.name:<34} compiled raised: {msg}", flush=True)
            except Exception:
                pass
            continue
        e1, sc1 = maxerr(eag[0], truth[0]); c1, _ = maxerr(comp[0], truth[0])
        e2, sc2 = maxerr(eag[1], truth[1]); c2, _ = maxerr(comp[1], truth[1])
        rec = {"op": oi.name, "grad_err": (e1, c1, sc1), "gradgrad_err": (e2, c2, sc2)}
        bad1 = c1 > max(4 * e1, 1e-4 * max(sc1, 1.0))
        bad2 = c2 > max(4 * e2, 1e-4 * max(sc2, 1.0))
        rec["flag"] = bad1 or bad2
        rows.append(rec)
        if rec["flag"]:
            flagged.append(rec)
            print(f"  FLAG {oi.name:<34} grad eager/compiled err {e1:.1e}/{c1:.1e}  gradgrad {e2:.1e}/{c2:.1e} (scale {sc2:.1e})", flush=True)
        if i % 50 == 49:
            print(f"  ... {i + 1}/{len(ops)} ({time.time() - t0:.0f}s, {len(flagged)} flagged)", flush=True)
    json.dump(rows, open(os.path.join(a.out, "double_backward.json"), "w"), indent=1, default=str)
    lines = [f"# double backward under compile ({a.backend}, torch {torch.__version__})", "", f"- ops: {len(ops)}, rows: {len(rows)}, flagged: {len(flagged)}; wall {time.time() - t0:.0f} s", "", "| op | finding |", "|---|---|"]
    for r in flagged:
        lines.append(f"| {r['op']} | {r.get('error') or f'grad {r['grad_err'][0]:.1e}/{r['grad_err'][1]:.1e}, gradgrad {r['gradgrad_err'][0]:.1e}/{r['gradgrad_err'][1]:.1e}'} |")
    open(os.path.join(a.out, "DOUBLE_BACKWARD.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"ops": len(ops), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))


if __name__ == "__main__":
    main()
