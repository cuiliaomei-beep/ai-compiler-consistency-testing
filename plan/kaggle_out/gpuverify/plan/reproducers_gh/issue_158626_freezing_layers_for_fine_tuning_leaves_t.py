# source: https://github.com/pytorch/pytorch/issues/158626
# title: Freezing layers for fine-tuning leaves TorchInductor Scheduler node mappings in inconsistent state
# state: closed  created: 2025-07-18
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch import nn

class Block(nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = nn.Linear(1, 1)
        self.bn = nn.BatchNorm1d(1)
        self.top_level_param = nn.Parameter(torch.zeros(1))

    def forward(self, x):
        x += self.top_level_param
        return self.bn(self.linear(x))

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.param = Block()
        self.head = Block()

    def forward(self, x):
        return self.head(self.param(x))

# Compile model then freeze parameters - this triggers the bug
model = torch.compile(Model())
model.param.requires_grad_(False)

# Error occurs during backward pass compilation
x = torch.zeros(4, 1)
loss = model(x).sum()
loss.backward()
