# source: https://github.com/pytorch/pytorch/issues/182765
# title: `torch.compile` silently produces all-zero `x.grad` for `diagonal_scatter(...).sum().backward()`
# state: closed  created: 2026-05-07
# mined automatically; the harness records the torch.compile target and its first call

import torch

x = torch.randn(8, 8, device='cuda', requires_grad=True)
src = torch.randn(8, device='cuda', requires_grad=True)

def fn(x, src):
    return torch.diagonal_scatter(x, src, 0).sum()

# Eager: correct
x1 = x.clone().detach().requires_grad_(True)
s1 = src.clone().detach().requires_grad_(True)
fn(x1, s1).backward()
print(f"eager x.grad:\n{x1.grad}")
# tensor([[0., 1., 1., 1., 1., 1., 1., 1.],
#         [1., 0., 1., 1., 1., 1., 1., 1.],
#         ...])  # 1 everywhere except diagonal

# Compiled: wrong
torch._dynamo.reset()
x2 = x.clone().detach().requires_grad_(True)
s2 = src.clone().detach().requires_grad_(True)
torch.compile(fn)(x2, s2).backward()
print(f"compiled x.grad:\n{x2.grad}")
# tensor([[0., 0., 0., 0., 0., 0., 0., 0.],
#         [0., 0., 0., 0., 0., 0., 0., 0.],
#         ...])  # ALL ZEROS — incorrect
