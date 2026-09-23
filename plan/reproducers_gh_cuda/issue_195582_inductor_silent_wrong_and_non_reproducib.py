# source: https://github.com/pytorch/pytorch/issues/195582
# title: [inductor] Silent wrong and non-reproducible results: BatchNorm2d followed by a shrinking F.pad
# state: open  created: 2026-09-01
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

class M(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(1, 50, (2, 2))
        self.bn = nn.BatchNorm2d(50)
        self.fc = nn.Linear(50, 10)

    def forward(self, x):
        x = self.bn(self.conv(x))
        x = x.view(x.shape[0], -1)           # (3, 450)
        x = F.pad(x, (0, 50 - x.shape[-1]))  # pad of -400 -> (3, 50)
        return self.fc(x)

def run(compiled):
    torch.manual_seed(420)
    m = M().eval()
    x = torch.randn(3, 1, 4, 4)
    with torch.no_grad():
        g = torch.compile(m, backend="inductor") if compiled else m
        return g(x).clone()

e1, e2 = run(False), run(False)
print("eager  reproducible:", torch.equal(e1, e2), "| max|out| =", round(e1.abs().max().item(), 4))

outs = []
for _ in range(3):
    torch._dynamo.reset()
    outs.append(run(True))
print("compiled reproducible:", torch.equal(outs[0], outs[1]) and torch.equal(outs[1], outs[2]))
for i, o in enumerate(outs):
    print(f"  compiled run {i}: max|out| = {o.abs().max().item():.6g}")
