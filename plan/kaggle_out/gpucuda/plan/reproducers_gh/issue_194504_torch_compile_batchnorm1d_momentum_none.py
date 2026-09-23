# source: https://github.com/pytorch/pytorch/issues/194504
# title: [torch.compile] BatchNorm1d(momentum=None) training fails under fullgraph=True
# state: open  created: 2026-08-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch import nn

torch.manual_seed(0)
module = nn.BatchNorm1d(4, momentum=None).train()
input = torch.randn(3, 4)

print("eager shape:", module(input).shape)

module = nn.BatchNorm1d(4, momentum=None).train()
compiled = torch.compile(module, backend="inductor", fullgraph=True)
print("compiled shape:", compiled(input).shape)
