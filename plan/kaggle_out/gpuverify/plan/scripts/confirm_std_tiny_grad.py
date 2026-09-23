"""Gradient of torch.std on 1e-30-scale float32 inputs: eager vs torch.compile vs float64 truth."""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)
base = torch.randn(5)


def run(scale, fn=torch.std, label="std"):
    x = (base * scale).detach()
    res = {}
    for name, f, dt in (("eager", fn, torch.float32), ("fp64", fn, torch.float64)):
        xx = x.to(dt).requires_grad_(True)
        y = f(xx)
        g, = torch.autograd.grad(y.sum(), xx)
        res[name] = (y.item(), g)
    torch._dynamo.reset()
    cf = torch.compile(fn)
    xx = x.clone().requires_grad_(True)
    y = cf(xx)
    g, = torch.autograd.grad(y.sum(), xx)
    res["compiled"] = (y.item(), g)
    print(f"[{label} scale={scale:g}]")
    for k, (yv, gv) in res.items():
        print(f"   {k:<9} out={yv:.4g}  grad={[f'{v:.4g}' for v in gv.tolist()]}")
    e = (res["eager"][1].double() - res["fp64"][1]).abs().max().item()
    c = (res["compiled"][1].double() - res["fp64"][1]).abs().max().item()
    print(f"   |grad err| eager={e:.3g} compiled={c:.3g}")


for s in (1.0, 1e-10, 1e-18, 1e-20, 1e-30):
    run(s)
run(1e-30, torch.var, "var")
run(1e-30, lambda x: torch.std(x, correction=0), "std c=0")
run(1e-30, lambda x: torch.std(x.view(1, 5), dim=1).sum(), "std dim=1")
