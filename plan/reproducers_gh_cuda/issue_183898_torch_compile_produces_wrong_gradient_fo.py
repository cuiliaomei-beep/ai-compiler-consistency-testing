# source: https://github.com/pytorch/pytorch/issues/183898
# title: torch.compile produces wrong gradient for slice_scatter backward on CUDA
# state: closed  created: 2026-05-15
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x, y):
    return torch.slice_scatter(x, y, dim=0, start=1, end=4).sum()

if not torch.cuda.is_available():
    raise SystemExit(2)

x = torch.tensor(
    [2.0, 4.0, 6.0, 8.0, 10.0, 12.0],
    device="cuda",
    requires_grad=True,
)
y = torch.tensor(
    [30.0, 40.0, 50.0],
    device="cuda",
    requires_grad=True,
)

f(x, y).backward()
eager_grad = x.grad.detach().cpu()

x2 = x.detach().clone().requires_grad_(True)
y2 = y.detach().clone().requires_grad_(True)

compiled = torch.compile(f, backend="inductor")
compiled(x2, y2).backward()
torch.cuda.synchronize()

compiled_grad = x2.grad.detach().cpu()

print("x:", x.detach().cpu())
print("y:", y.detach().cpu())
print("eager_grad:", eager_grad)
print("compiled_grad:", compiled_grad)

if not torch.equal(eager_grad, compiled_grad):
    raise SystemExit(0)

raise SystemExit(1)
