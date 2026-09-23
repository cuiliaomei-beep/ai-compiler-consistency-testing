# source: https://github.com/pytorch/pytorch/issues/185494
# title: [dynamo] LazyBatchNorm2d fails under torch.compile(dynamic=True) — "SymIntArrayRef expected to contain only concrete integers"
# state: open  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch, torch.nn as nn

class M(nn.Module):
    def __init__(self):
        super().__init__()
        self.bn = nn.LazyBatchNorm2d()
    def forward(self, x):
        return self.bn(x)

m = torch.compile(M(), dynamic=True)
m(torch.randn(1, 3, 16, 16))    # !crash here
