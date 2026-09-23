"""Complex-input gradients: eager vs torch.compile(backend="aot_eager") vs complex128 truth, over every OpInfo
operator that supports complex64 with autograd. No C++ compile involved (aot_eager), so ~1 s per operator.

Flag = compiled gradient error (vs complex128 eager) > max(4 x eager error, 1e-4 * scale). Seed of the angle: item 24
(torch.linalg.pinv). Loss = sum(|out|^2) over all tensor outputs.

    python scripts/complex_grad_sweep.py [--only pinv,svd] [--samples 2] [--out results/complex_grad]
"""
import argparse
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
import torch  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6


def loss_of(out):
    outs = out if isinstance(out, (tuple, list)) else [out]
    total = None
    for o in outs:
        if isinstance(o, torch.Tensor) and (o.is_floating_point() or o.is_complex()):
            term = (o.abs() ** 2).sum()
            total = term if total is None else total + term
    return total


def grads(fn, sample, dtype):
    """Run fn on a clone of the sample cast to dtype; return list of input grads (None where no grad)."""
    def cast(t):
        if isinstance(t, torch.Tensor) and t.is_complex():
            return t.detach().to(dtype).requires_grad_(t.requires_grad)
        if isinstance(t, torch.Tensor) and t.is_floating_point():
            real = torch.float64 if dtype == torch.complex128 else torch.float32
            return t.detach().to(real).requires_grad_(t.requires_grad)
        return t
    inp = cast(sample.input)
    args = [cast(a) for a in sample.args]
    kwargs = {k: cast(v) for k, v in sample.kwargs.items()}
    leaves = [t for t in [inp, *args, *kwargs.values()] if isinstance(t, torch.Tensor) and t.requires_grad]
    out = fn(inp, *args, **kwargs)
    total = loss_of(out)
    if total is None or not total.requires_grad:
        return None
    gs = torch.autograd.grad(total, leaves, allow_unused=True)
    return [g.detach() if g is not None else None for g in gs]


def err(gs, truth):
    worst, scale = 0.0, 1e-30
    for g, t in zip(gs, truth):
        if g is None or t is None:
            if (g is None) != (t is None):
                return float("inf"), 1.0
            continue
        if t.numel() == 0:
            continue
        d = (g.to(t.dtype) - t).abs().max().item()
        worst = max(worst, d)
        scale = max(scale, t.abs().max().item())
    return worst, scale


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--samples", type=int, default=2)
    ap.add_argument("--backend", default="aot_eager")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "complex_grad"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    print("torch", torch.__version__)
    only = set(a.only.split(",")) if a.only else None
    ops = [o for o in op_db if o.supports_autograd and torch.complex64 in o.dtypes and (not only or o.name in only or o.name.split(".")[-1] in only)]
    print(f"{len(ops)} OpInfo operators support complex64 + autograd")
    rows, flagged, t0, n = [], [], time.time(), 0
    for oi in ops:
        try:
            samples = list(oi.sample_inputs("cpu", torch.complex64, requires_grad=True))[: a.samples]
        except Exception as e:  # noqa: BLE001
            continue
        fn = oi.get_op()
        for si, s in enumerate(samples):
            n += 1
            try:
                truth = grads(fn, s, torch.complex128)
                ge = grads(fn, s, torch.complex64)
                if truth is None or ge is None:
                    continue
                torch._dynamo.reset()
                gc = grads(torch.compile(fn, backend=a.backend), s, torch.complex64)
                if gc is None:
                    continue
            except Exception as e:  # noqa: BLE001
                rows.append({"op": oi.name, "sample": si, "error": f"{type(e).__name__}: {str(e).splitlines()[0][:100]}"})
                continue
            ee, sc = err(ge, truth)
            ec, _ = err(gc, truth)
            rec = {"op": oi.name, "sample": si, "eager_err": ee, "compiled_err": ec, "scale": sc,
                   "shapes": [list(t.shape) for t in [s.input, *s.args] if isinstance(t, torch.Tensor)]}
            rec["flag"] = ec > max(4 * ee, 1e-4 * sc)
            rows.append(rec)
            if rec["flag"]:
                flagged.append(rec)
                print(f"  FLAG {oi.name:<36} sample {si} shapes={rec['shapes']} eager_err={ee:.1e} compiled_err={ec:.1e} (scale {sc:.1e})", flush=True)
        if len(rows) % 25 == 0:
            print(f"  ... {oi.name} ({time.time() - t0:.0f}s, {len(flagged)} flagged)", flush=True)
    json.dump(rows, open(os.path.join(a.out, "complex_grad.json"), "w"), indent=1)
    lines = [f"# complex-input gradients eager vs {a.backend} (torch {torch.__version__})", "",
             f"- operators: {len(ops)}, samples run: {n}, flagged: {len(flagged)}; wall {time.time() - t0:.0f} s", "",
             "| op | sample | shapes | eager err | compiled err | scale |", "|---|---|---|---|---|---|"]
    for r in flagged:
        lines.append(f"| {r['op']} | {r['sample']} | {r['shapes']} | {r['eager_err']:.1e} | {r['compiled_err']:.1e} | {r['scale']:.1e} |")
    errs = [r for r in rows if "error" in r]
    if errs:
        lines += ["", f"## errors ({len(errs)})", ""] + [f"- {r['op']} sample {r['sample']}: {r['error']}" for r in errs[:60]]
    open(os.path.join(a.out, "COMPLEX_GRAD.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"operators": len(ops), "samples": n, "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))
    print("written", os.path.join(a.out, "COMPLEX_GRAD.md"))


if __name__ == "__main__":
    main()
