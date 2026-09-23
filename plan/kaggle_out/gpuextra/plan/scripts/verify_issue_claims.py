"""Verify every number / claim written into the ISSUE_FINAL.md drafts (2026-09-10)."""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)


def run(fn, *a, backend="inductor", **kw):
    torch._dynamo.reset()
    try:
        return torch.compile(fn, backend=backend, **kw)(*a)
    except Exception as e:  # noqa: BLE001
        inner = e
        while inner.__cause__ is not None:
            inner = inner.__cause__
        return f"{type(inner).__name__}: {str(inner)[:70]}"


print("== std large ==")
x = torch.randn(4, 8) * 1e30
print("eager    :", torch.std(x).item(), "fp64:", torch.std(x.double()).item())
print("aot_eager:", run(torch.std, x, backend="aot_eager"))
print("inductor :", run(torch.std, x))
for name in ("var", "var_mean", "std_mean"):
    print(f"inductor {name}:", run(getattr(torch, name), x))

print("== std tiny + grad ==")


def grads(fn, x):
    xx = x.clone().requires_grad_(True)
    y = fn(xx)
    (g,) = torch.autograd.grad(y, xx)
    return round(y.item(), 34), [round(v, 4) for v in g.tolist()]


x = torch.randn(5) * 1e-30
print("eager    :", grads(torch.std, x))
torch._dynamo.reset()
print("aot_eager:", grads(torch.compile(torch.std, backend="aot_eager"), x))
torch._dynamo.reset()
print("inductor :", grads(torch.compile(torch.std), x))

print("== vector_norm dim=None on (0,5) ==")
x = torch.empty(0, 5)
try:
    print("eager dim=None:", torch.linalg.vector_norm(x, ord=float("inf")))
except Exception as e:  # noqa: BLE001
    print("eager dim=None raises:", type(e).__name__, str(e)[:80])
print("eager dim=-1  :", torch.linalg.vector_norm(x, ord=float("inf"), dim=-1))
print("eager dim=(1,):", torch.linalg.vector_norm(x, ord=float("inf"), dim=(1,)))
print("inductor dim=(1,):", run(lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=(1,)), x))
print("inductor dim=-1  :", run(lambda x: torch.linalg.vector_norm(x, ord=float("inf"), dim=-1), x))
print("inductor linalg.norm ord=inf dim=-1:", run(lambda x: torch.linalg.norm(x, ord=float("inf"), dim=-1), x))

print("== argmin pow ==")
x, m = torch.randn(3, 4, 4), torch.randn(1, 4, 4)
f = lambda x, m: (x + m).argmin()  # noqa: E731
print("eager:", f(x, m).item(), "static:", run(f, x, m), "aot dyn:", run(f, x, m, backend="aot_eager", dynamic=True),
      "inductor dyn:", run(f, x, m, dynamic=True))
