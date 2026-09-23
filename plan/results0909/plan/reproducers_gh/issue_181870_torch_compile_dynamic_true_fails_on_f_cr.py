# source: https://github.com/pytorch/pytorch/issues/181870
# title: `torch.compile(dynamic=True)` fails on `F.cross_entropy` with probability targets and class weight due to symbolic numel()
# state: closed  created: 2026-04-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def fn(x, target, weight):
    return F.cross_entropy(
        x,
        target,
        weight=weight,
        reduction="none",
    )

x = torch.randn(3, 5)
target = torch.rand(3, 5).softmax(dim=1)
weight = torch.rand(5)

eager_out = fn(x, target, weight)
print("EAGER_OK", eager_out.shape)

compiled = torch.compile(fn, dynamic=True, backend="eager")
compiled_out = compiled(x, target, weight)
print("COMPILED_OK", compiled_out.shape)
