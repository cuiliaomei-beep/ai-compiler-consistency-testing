# source: https://github.com/pytorch/pytorch/issues/182343
# title: Torch Inductor SearchSorted SliceView Bug
# state: closed  created: 2026-05-04
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile
def f(offsets, values):
    return torch.searchsorted(offsets[1:], values, right=True)

offsets = torch.tensor([0, 3, 7, 12], device="cuda")
values = torch.arange(12, device="cuda")

print(f(offsets, values))
# Compiled: [1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]  (WRONG, off by 1)
# Expected: [0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2]
