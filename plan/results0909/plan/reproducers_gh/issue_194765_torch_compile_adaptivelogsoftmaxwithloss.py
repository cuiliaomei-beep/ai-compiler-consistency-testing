# source: https://github.com/pytorch/pytorch/issues/194765
# title: [torch.compile] AdaptiveLogSoftmaxWithLoss.forward fails on valid inputs under fullgraph=True
# state: open  created: 2026-08-25
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch import nn

torch.manual_seed(0)
module = nn.AdaptiveLogSoftmaxWithLoss(
    in_features=8,
    n_classes=20,
    cutoffs=[5, 10],
)
input = torch.randn(4, 8)
target = torch.tensor([1, 2, 3, 4])

print("eager:", module(input, target))
compiled = torch.compile(module, backend="inductor", fullgraph=True)
print("compiled:", compiled(input, target))
