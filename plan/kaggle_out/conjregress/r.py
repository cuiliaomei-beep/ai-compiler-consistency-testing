import torch
from torch.utils._python_dispatch import TorchDispatchMode
class Forward(TorchDispatchMode):
    def __torch_dispatch__(self, func, types, args=(), kwargs=None): return func(*args, **(kwargs or {}))
torch.manual_seed(0)
A = torch.randn(4, 3, dtype=torch.complex64)
ref = torch.linalg.pinv(A); refP = torch.linalg.polar(A)[1]
with Forward(): m = torch.linalg.pinv(A); mP = torch.linalg.polar(A)[1]
try:
    torch._dynamo.reset(); c = torch.compile(torch.linalg.pinv, backend="aot_eager")(A); cd = (c - ref).abs().max().item()
except Exception as e: cd = type(e).__name__
print(f"torch {torch.__version__}: pinv |mode - eager| {(m - ref).abs().max().item():.3g}  polar P |mode - eager| {(mP - refP).abs().max().item():.3g}  pinv |aot_eager compile - eager| {cd}", flush=True)
