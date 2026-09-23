# source: https://github.com/pytorch/pytorch/issues/186799
# title: `torch.compile` silently produces wrong gradient for `atan2(x, y).amin(dim)` on float32
# state: open  created: 2026-06-09
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch.manual_seed(0)
x_init = torch.randn(2, 3)
y = torch.randn(2, 3)

def fn(x, y):
    return torch.atan2(x, y).amin(dim=-1)

x_e = x_init.detach().clone().requires_grad_(True)
fn(x_e, y).sum().backward()

x_c = x_init.detach().clone().requires_grad_(True)
torch.compile(fn)(x_c, y).sum().backward()

print("eager grad   :", x_e.grad.flatten().tolist())
print("compiled grad:", x_c.grad.flatten().tolist())
print("max diff:", (x_e.grad - x_c.grad).abs().max().item())
