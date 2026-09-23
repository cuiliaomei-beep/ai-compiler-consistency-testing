# source: https://github.com/pytorch/pytorch/issues/194558
# title: [inductor] in-place padding optimization mishandles negative (shrinking) F.pad, producing a buffer with negative declared size and crashing with ValueRangeError: Invalid ranges
# state: closed  created: 2026-08-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = nn.Linear(3, 5)

    def forward(self, x):
        v = x + 0.0
        v = F.pad(v, (0, -2, 0, 0), mode='constant', value=0.5)
        return self.linear(v)

torch.manual_seed(420)
x = torch.randn(2, 5)
model = Model().eval()

with torch.no_grad():
    eager_out = model(x)
    print('eager OK:', eager_out.shape)
    compiled = torch.compile(model, backend='inductor')
    compiled_out = compiled(x)
    print('compiled OK:', compiled_out.shape)
