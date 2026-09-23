# source: https://github.com/pytorch/pytorch/issues/185589
# title: [inductor] Severe numerical inconsistency: diag_embed + erf + normalize(p=-1) under torch.compile(dynamic=True) — max diff up to 565,248
# state: open  created: 2026-05-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.set_grad_enabled(False)

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv1 = nn.Conv2d(3, 8, kernel_size=3, padding=1)
        self.bn1 = nn.BatchNorm2d(8)

    def forward(self, x):
        x = self.conv1(x)
        x = self.bn1(x)
        x = F.relu(x)
        x = torch.diag_embed(x)
        x = torch.erf(x)
        x = F.normalize(x, p=-1, dim=-1)
        return x

model = Model()
x = torch.randn(2, 3, 16, 16)

res_eager = model(*[x])
res_compiled = torch.compile(model, dynamic=True)(x)

print("Max diff:", (res_eager - res_compiled).abs().max().item())
