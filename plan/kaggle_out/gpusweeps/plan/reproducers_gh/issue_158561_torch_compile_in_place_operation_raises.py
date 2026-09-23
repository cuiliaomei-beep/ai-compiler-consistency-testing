# source: https://github.com/pytorch/pytorch/issues/158561
# title: `torch.compile` In-place operation raises Autograd error even when gradients are not required
# state: open  created: 2025-07-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.layer0 = torch.nn.Linear(1, 1)
        self.layer1 = torch.nn.ReLU()

    def forward(self, x):
        y = self.layer0(x)
        z = self.layer1(y)
        z.copy_(y)
        return z

x = torch.randn(1, 1)

model = Model()
out = model(x)
print(out)

compiled_model = torch.compile(model)
out = compiled_model(x)
print(out)
