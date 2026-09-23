# source: https://github.com/pytorch/pytorch/issues/185587
# title: [inductor] Numerical inconsistency: polygamma + cumulative_trapezoid under torch.compile(dynamic=True) produces wrong results after Conv2d + GroupNorm
# state: open  created: 2026-05-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

torch.set_grad_enabled(False)

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(3, 16, kernel_size=3, padding=1)
        self.gn1 = nn.GroupNorm(num_groups=4, num_channels=16)

    def forward(self, x):
        x = self.conv1(x)
        x = self.gn1(x)
        x = torch.polygamma(0, x + 0.1)
        x = x.unsqueeze(2)
        x = torch.cumulative_trapezoid(x)
        return x

model = Model()
x = torch.randn(1, 3, 32, 32)

res_eager = model(*[x])
res_compiled = torch.compile(model, dynamic=True)(x)

print("Max diff:", (res_eager - res_compiled).abs().max().item())
# Output: Max diff: 1420.1875
# The max diff is non-deterministic (varies between 31 and 1420 across runs due to random input), but always present.
