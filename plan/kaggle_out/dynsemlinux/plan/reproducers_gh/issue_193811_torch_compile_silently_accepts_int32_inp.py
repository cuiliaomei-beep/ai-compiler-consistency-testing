# source: https://github.com/pytorch/pytorch/issues/193811
# title: torch.compile silently accepts int32 input to upsample_bilinear2d that eager correctly rejects
# state: open  created: 2026-08-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile
def fn(x):
    return torch.ops.aten.upsample_bilinear2d(x, [16, 15], False, None, None)

out = fn(torch.randn(1, 3, 1, 8).to(torch.int32))
print("compiled ran OK:", out.shape)
