# source: https://github.com/pytorch/pytorch/issues/194501
# title: [torch.compile][Inductor] smooth_l1_loss with negative beta bypasses eager validation
# state: open  created: 2026-08-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def fn(left, right):
    return F.smooth_l1_loss(left, right, beta=-1.0)

left = torch.tensor([1.0])
right = torch.tensor([0.0])

try:
    print("eager:", fn(left, right))
except Exception as error:
    print("eager error:", type(error).__name__, error)

compiled = torch.compile(fn, backend="inductor")
print("compiled:", compiled(left, right))
