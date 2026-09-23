# source: https://github.com/pytorch/pytorch/issues/180771
# title: [inductor] `torch.compile` produces wrong gradients for `torch.slice_scatter` backward
# state: closed  created: 2026-04-19
# mined automatically; the harness records the torch.compile target and its first call

import torch

x = torch.tensor([1., 2., 3., 4., 5.], device='cuda', requires_grad=True)
y = torch.tensor([10., 20.], device='cuda', requires_grad=True)

def f(x, y):
    return torch.slice_scatter(x, y, dim=0, start=0, end=2).sum()

# Eager — correct
f(x, y).backward()
print(f"Eager x.grad = {x.grad}")
# tensor([0., 0., 1., 1., 1.])  ✅  positions 0:2 overwritten by y → grad=0

# Inductor — wrong
x2 = x.detach().clone().requires_grad_(True)
y2 = y.detach().clone().requires_grad_(True)
torch._dynamo.reset()
fn = torch.compile(f, backend='inductor')
fn(x2, y2).backward()
print(f"Inductor x.grad = {x2.grad}")
# tensor([0., 0., 0., 0., 0.])  ❌  positions 2:5 should be 1, not 0
