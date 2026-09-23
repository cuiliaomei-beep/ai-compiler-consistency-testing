"""linalg.matrix_sqrth complex gradient: eager vs compile (same class as item 24?)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
torch.manual_seed(0)
def loss(a): return (torch.linalg.matrix_sqrth(a @ a.mH + torch.eye(a.shape[0], dtype=a.dtype)).abs() ** 2).sum()
def grad(fn, a):
    a = a.detach().clone().requires_grad_(); fn(a).backward(); return a.grad
for dt in (torch.float32, torch.complex64):
    a = torch.randn(4, 4, dtype=dt)
    truth = grad(loss, a.to(torch.complex128 if dt.is_complex else torch.float64))
    err = lambda g: (g.to(truth.dtype) - truth).abs().max().item()
    out = [f"eager {err(grad(loss, a)):.1e}"]
    for b in ("eager", "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            out.append(f"compile({b}) {err(grad(torch.compile(loss, backend=b), a)):.1e}")
        except Exception as e:
            out.append(f"compile({b}) raise {type(e).__name__}")
    print(f"[matrix_sqrth {str(dt).split('.')[-1]}] " + " | ".join(out))
from torch._dynamo.backends.common import aot_autograd
seen = []
def bw(gm, i):
    seen.extend(str(n.target) for n in gm.graph.nodes if n.op == "call_function"); return gm
a = torch.randn(4, 4, dtype=torch.complex64)
torch._dynamo.reset(); grad(torch.compile(loss, backend=aot_autograd(fw_compiler=lambda gm, i: gm, bw_compiler=bw)), a)
print("backward ops:", sorted(set(seen)))
