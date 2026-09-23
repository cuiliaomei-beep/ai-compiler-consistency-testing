# source: https://github.com/pytorch/pytorch/issues/183902
# title: torch.compile skips device mismatch error for index_add with CPU index and CUDA tensors
# state: closed  created: 2026-05-15
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x, y):
    idx = torch.randperm(x.size(0))[: y.size(0)]
    return torch.index_add(x, 0, idx, y)

if not torch.cuda.is_available():
    raise SystemExit(2)

torch.manual_seed(5)

x = torch.randn(6, 4, device="cuda")
y = torch.randn(3, 4, device="cuda")

try:
    eager_out = f(x.clone(), y.clone())
    eager = f"OK {tuple(eager_out.shape)}"
except Exception as exc:
    eager = f"{type(exc).__name__} {str(exc).splitlines()[0]}"

try:
    compiled_out = torch.compile(f, backend="inductor")(x.clone(), y.clone())
    compiled = f"OK {tuple(compiled_out.shape)}"
except Exception as exc:
    compiled = f"{type(exc).__name__} {str(exc).splitlines()[0]}"

print("x_device:", x.device)
print("y_device:", y.device)
print("eager:", eager)
print("compiled:", compiled)

if not eager.startswith("OK") and compiled.startswith("OK"):
    raise SystemExit(0)

raise SystemExit(1)
