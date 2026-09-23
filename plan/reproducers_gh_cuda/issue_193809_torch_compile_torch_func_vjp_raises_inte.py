# source: https://github.com/pytorch/pytorch/issues/193809
# title: torch.compile` + `torch.func.vjp` raises internal error not seen in eager
# state: open  created: 2026-08-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile
def fn(x):
    return torch.func.vjp(lambda t: t.sin().sum(), x)

fn(torch.randn(4, 4, requires_grad=True))
# Also reproduces with: fn(torch.randn(256, 4, requires_grad=True))
