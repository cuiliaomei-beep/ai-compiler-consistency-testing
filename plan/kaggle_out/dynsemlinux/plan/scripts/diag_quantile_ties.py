"""quantile / nanquantile gradient with tied values: eager vs compiled (decomposition) vs fp64."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)


def grads(fn, x, **kw):
    out = {}
    torch._dynamo.reset()
    for name, f in [("eager", fn), ("inductor", torch.compile(fn)), ("aot_eager", torch.compile(fn, backend="aot_eager"))]:
        xx = x.clone().requires_grad_()
        try:
            f(xx, **kw).sum().backward()
            out[name] = xx.grad.clone()
        except Exception as e:
            out[name] = f"{type(e).__name__}: {str(e)[:80]}"
    return out


cases = [
    ("ties 1-d q=0.5", torch.tensor([1., 1., 1., 2., 2.]), dict(q=0.5)),
    ("ties 1-d q=0.5 dim=0", torch.tensor([1., 1., 1., 2., 2.]), dict(q=0.5, dim=0)),
    ("ties 2-d dim=0", torch.tensor([[1., 2.], [1., 2.], [1., 2.], [3., 4.], [3., 4.], [3., 4.], [3., 4.]]), dict(q=torch.tensor([0.25, 0.5, 0.75]), dim=0)),
    ("prime7 no ties dim=0", torch.arange(7 * 4, dtype=torch.float32).reshape(7, 2, 1, 2), dict(q=0.5, dim=0)),
    ("all equal", torch.ones(7, 2, 1, 2), dict(q=torch.tensor([0.3, 0.6]), dim=0)),
    ("all equal keepdim", torch.ones(7, 2, 1, 2), dict(q=0.5, dim=0, keepdim=True)),
]
for fn in (torch.quantile, torch.nanquantile):
    for label, x, kw in cases:
        g = grads(fn, x, **kw)
        e, i = g["eager"], g["inductor"]
        same = isinstance(e, torch.Tensor) and isinstance(i, torch.Tensor) and torch.equal(e, i)
        flag = "" if same else "   <-- DIFF"
        print(f"[{fn.__name__} {label}] eager={e.flatten().tolist() if isinstance(e, torch.Tensor) else e}")
        print(f"    inductor={i.flatten().tolist() if isinstance(i, torch.Tensor) else i}{flag}")
        a = g["aot_eager"]
        if isinstance(a, torch.Tensor) and isinstance(e, torch.Tensor) and not torch.equal(a, e):
            print(f"    aot_eager={a.flatten().tolist()}   <-- DIFF vs eager")
