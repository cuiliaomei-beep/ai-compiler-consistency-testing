# source: https://github.com/pytorch/pytorch/issues/187027
# title: flip after repeat_interleave generates negative (out-of-bounds) index under dynamic shapes
# state: closed  created: 2026-06-11
# mined automatically; the harness records the torch.compile target and its first call

import torch
f = lambda x: torch.repeat_interleave((x + 1).flatten(), 2).flip(0)
x = torch.randn(8, 8)
print(f(x))                                # correct
print(torch.compile(f, dynamic=True)(x))   # WRONG (OOB)
