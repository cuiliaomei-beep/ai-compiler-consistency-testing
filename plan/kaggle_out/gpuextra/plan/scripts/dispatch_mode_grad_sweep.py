"""Gradients under a forwarding TorchDispatchMode vs plain eager, every OpInfo op that supports autograd for the given
dtypes.  Follow-up of #198118 (forward values of complex pinv/polar wrong under any mode): the C++ backward formulas of
the linear-algebra ops also build conjugate views internally.  Pure eager, no compiler.
    python scripts/dispatch_mode_grad_sweep.py --dtypes complex64,complex128,float64
"""
import argparse, itertools, json, os, torch
from torch.testing._internal.common_methods_invocations import op_db
from torch.utils._python_dispatch import TorchDispatchMode


class Forward(TorchDispatchMode):
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))


def flat(o):
    if isinstance(o, torch.Tensor): return [o]
    if isinstance(o, (list, tuple)) or hasattr(o, "_fields"): return [t for x in tuple(o) for t in flat(x)]
    if isinstance(o, dict): return [t for x in o.values() for t in flat(x)]
    return []


def grads(fn, s):
    leaves = [t for t in flat((s.input, s.args, s.kwargs)) if isinstance(t, torch.Tensor) and t.requires_grad]
    out = [o for o in flat(fn(s.input, *s.args, **s.kwargs)) if o.requires_grad and (o.is_floating_point() or o.is_complex())]
    if not leaves or not out: return None
    loss = sum((o.abs() ** 2).sum() for o in out)
    return [g if g is not None else torch.zeros(0) for g in torch.autograd.grad(loss, leaves, allow_unused=True)]


def diff(a, b):
    if a.shape != b.shape or a.dtype != b.dtype: return "shape/dtype"
    if a.numel() == 0: return None
    a, b = a.detach(), b.detach()
    if a.is_complex(): a, b = torch.view_as_real(a.resolve_conj()), torch.view_as_real(b.resolve_conj())
    a, b = a.double(), b.double()
    if not torch.equal(a.isnan(), b.isnan()): return "nan pattern"
    m = ~a.isnan()
    d = (a[m] - b[m]).abs().max().item() if m.any() else 0.0
    scale = max(1.0, a[m].abs().max().item()) if m.any() else 1.0
    return f"max abs diff {d:.3g} (scale {scale:.3g})" if d > 1e-4 * scale else None


def main():
    ap = argparse.ArgumentParser(); ap.add_argument("--dtypes", default="complex64,complex128,float64"); ap.add_argument("--only", default=None)
    ap.add_argument("--max-samples", type=int, default=4); ap.add_argument("--out", default="results/pairs/dispatch_mode_grad.jsonl"); a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    SKIP = ("empty", "rand", "normal", "bernoulli", "multinomial", "dropout", "rrelu", "uniform", "exponential", "geometric", "cauchy", "log_normal", "poisson", "new_empty", "resize", "unique", "nonzero", "signal.windows", "sparse")
    ops = [op for op in op_db if (a.only is None or op.name == a.only) and op.supports_autograd and not any(k in op.name for k in SKIP)]
    torch.manual_seed(0); n = hit = 0
    done = set()
    if os.path.exists(a.out):
        for l in open(a.out, encoding="utf-8"):
            try: r = json.loads(l); done.add((r["op"], r["dtype"]))
            except Exception: pass
    with open(a.out, "a", encoding="utf-8") as f:
        for op in ops:
            for dt in [getattr(torch, d) for d in a.dtypes.split(",")]:
                if not op.supports_dtype(dt, "cpu") or (op.name, str(dt).split(".")[-1]) in done: continue
                try: samples = list(itertools.islice(op.sample_inputs("cpu", dt, requires_grad=True), a.max_samples))
                except Exception: continue
                fn = op.get_op(); findings = []
                for si, s in enumerate(samples):
                    try:
                        g0 = grads(fn, s)
                        if g0 is None: continue
                        try:
                            with Forward(): g1 = grads(fn, s)
                        except Exception as e: findings.append({"i": si, "detail": f"raises under mode: {type(e).__name__}"}); continue
                        for x, y in zip(g0, g1):
                            d = diff(x, y)
                            if d: findings.append({"i": si, "detail": d, "sample": repr(s)[:160]}); break
                    except Exception as e:
                        findings.append({"i": si, "detail": f"tool error {type(e).__name__}"}) if False else None
                n += 1
                f.write(json.dumps({"op": op.name, "dtype": str(dt).split(".")[-1], "findings": findings}) + "\n")
                if findings:
                    hit += 1; print(f"!! {op.name:38s} {str(dt).split('.')[-1]:10s} {findings[0]['detail']}   ({len(findings)}/{len(samples)})", flush=True)
    print(f"{n} (op, dtype) pairs with autograd, {hit} differ in the gradient under a forwarding TorchDispatchMode")


if __name__ == "__main__":
    main()
