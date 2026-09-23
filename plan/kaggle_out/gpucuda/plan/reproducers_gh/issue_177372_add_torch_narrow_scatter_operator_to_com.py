# source: https://github.com/pytorch/pytorch/issues/177372
# title: Add torch.narrow_scatter operator to complete the *_copy/*_scatter operator family.
# state: open  created: 2026-03-13
# mined automatically; the harness records the torch.compile target and its first call

import torch

# Basic usage
x = torch.zeros(10)
src = torch.ones(5) * 2
result = torch.narrow_scatter(x, src, dim=0, start=2, length=5)
# tensor([0., 0., 2., 2., 2., 2., 2., 0., 0., 0.])

# Autograd support
x = torch.randn(10, 10, requires_grad=True)
src = torch.randn(5, 10, requires_grad=True)
result = torch.narrow_scatter(x, src, 0, 2, 5)
result.sum().backward()  # gradients computed correctly

# torch.compile support
@torch.compile
def fn(x, src):
    return torch.narrow_scatter(x, src, 0, 2, 5)
