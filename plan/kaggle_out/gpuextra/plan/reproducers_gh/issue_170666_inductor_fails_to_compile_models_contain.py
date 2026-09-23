# source: https://github.com/pytorch/pytorch/issues/170666
# title: Inductor Fails to Compile Models Containing `nn.RReLU` Due to Incorrect Meta Kernel for `aten.uniform.default`
# state: closed  created: 2025-12-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class TestModel(nn.Module):

    def __init__(self):
        super().__init__()
        self.rrelu = nn.RReLU()
        self.conv1 = nn.Conv2d(3, 64, kernel_size=3, stride=1, padding=1)
        self.fc = nn.Linear(64 * 32 * 32, 10)

    def forward(self, x):
        x = self.conv1(x)
        x = self.rrelu(x)
        x = x.view(x.size(0), -1)
        x = self.fc(x)
        return x

model = TestModel()
x = torch.randn(2, 3, 32, 32)

# Works
print(torch.compile(model, backend="aot_eager")(x))

# Fails
print(torch.compile(model, backend="inductor")(x))
