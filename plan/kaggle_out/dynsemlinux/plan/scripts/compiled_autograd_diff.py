"""6.4b: compiled_autograd (torch._dynamo.config.compiled_autograd=True) vs plain eager backward, over OpInfo operators
(float32, one sample each): the forward stays eager, only the backward graph is compiled by Dynamo+Inductor.

    python scripts/compiled_autograd_diff.py [--only ...] [--limit N] [--backend aot_eager|inductor] [--out results/compiled_autograd]
"""
import argparse, json, os, sys, time
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env
ensure_msvc_env()
import torch
from torch.testing._internal.common_methods_invocations import op_db

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6


def run_backward(fn, sample, compiled_autograd_backend=None):
    def cl(t):
        return t.detach().clone().requires_grad_(t.requires_grad) if isinstance(t, torch.Tensor) else t
    inp, args = cl(sample.input), [cl(a) for a in sample.args]
    kwargs = {k: cl(v) for k, v in sample.kwargs.items()}
    leaves = [t for t in [inp, *args, *kwargs.values()] if isinstance(t, torch.Tensor) and t.requires_grad]
    out = fn(inp, *args, **kwargs)
    outs = out if isinstance(out, (tuple, list)) else [out]
    loss = None
    for o in outs:
        if isinstance(o, torch.Tensor) and (o.is_floating_point() or o.is_complex()) and o.requires_grad:
            term = (o.abs() ** 2).sum() if o.is_complex() else (o ** 2).sum()
            loss = term if loss is None else loss + term
    if loss is None:
        return None
    if compiled_autograd_backend:
        with torch._dynamo.compiled_autograd._enable(torch.compile(backend=compiled_autograd_backend)):
            gs = torch.autograd.grad(loss, leaves, allow_unused=True)
    else:
        gs = torch.autograd.grad(loss, leaves, allow_unused=True)
    return [g.detach() if g is not None else None for g in gs]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None); ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--backend", default="aot_eager")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "compiled_autograd"))
    a = ap.parse_args(); os.makedirs(a.out, exist_ok=True)
    print("torch", torch.__version__, "| compiled_autograd backend", a.backend)
    only = set(a.only.split(",")) if a.only else None
    ops = [o for o in op_db if o.supports_autograd and torch.float32 in o.dtypes and (not only or o.name in only)]
    if a.limit:
        ops = ops[: a.limit]
    rows, flagged, t0 = [], [], time.time()
    for i, oi in enumerate(ops):
        try:
            s = next(iter(oi.sample_inputs("cpu", torch.float32, requires_grad=True)))
        except Exception:
            continue
        fn = oi.get_op()
        try:
            ge = run_backward(fn, s)
            if ge is None:
                continue
            torch._dynamo.reset()
            gc = run_backward(fn, s, a.backend)
        except Exception as e:
            rec = {"op": oi.name, "error": f"{type(e).__name__}: {str(e).splitlines()[0][:110]}"}
            rows.append(rec)
            if "eager" not in rec["error"].lower():
                flagged.append(rec); print(f"  FLAG {oi.name:<36} {rec['error']}", flush=True)
            continue
        worst, scale = 0.0, 1e-30
        bad = False
        for x, y in zip(ge, gc):
            if (x is None) != (y is None):
                bad = True; break
            if x is None or x.numel() == 0:
                continue
            if x.shape != y.shape or x.dtype != y.dtype or not torch.equal(torch.isfinite(x), torch.isfinite(y)):
                bad = True; break
            d = (x.double() - y.double()).abs()[torch.isfinite(x)].max().item() if torch.isfinite(x).any() else 0.0
            worst = max(worst, d); scale = max(scale, x.abs()[torch.isfinite(x)].max().item() if torch.isfinite(x).any() else 0.0)
        rec = {"op": oi.name, "max_diff": worst, "scale": scale, "flag": bad or worst > 1e-4 * max(scale, 1.0)}
        rows.append(rec)
        if rec["flag"]:
            flagged.append(rec); print(f"  FLAG {oi.name:<36} max_diff={worst:.2e} scale={scale:.2e} structural={bad}", flush=True)
        if i % 50 == 49:
            print(f"  ... {i + 1}/{len(ops)} ({time.time() - t0:.0f}s, {len(flagged)} flagged)", flush=True)
    json.dump(rows, open(os.path.join(a.out, "compiled_autograd.json"), "w"), indent=1)
    lines = [f"# compiled_autograd ({a.backend}) vs eager backward, torch {torch.__version__}", "", f"- operators: {len(ops)}, rows: {len(rows)}, flagged: {len(flagged)}; wall {time.time() - t0:.0f} s", "", "| op | finding |", "|---|---|"]
    for r in flagged:
        lines.append(f"| {r['op']} | {r.get('error') or f'max_diff {r['max_diff']:.2e} (scale {r['scale']:.2e})'} |")
    open(os.path.join(a.out, "COMPILED_AUTOGRAD.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"operators": len(ops), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))


if __name__ == "__main__":
    main()
