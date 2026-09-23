# source: https://github.com/pytorch/pytorch/issues/183120
# title: torch.compile Inductor produces wrong output for BatchNorm2d + ELU + GroupNorm + log clamp chain
# state: open  created: 2026-05-10
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

bn = nn.BatchNorm2d(5).eval()
elu = nn.ELU()
gn = nn.GroupNorm(5, 5).eval()

def fn():
    x = torch.ones([4, 5, 6, 6])
    t = bn(x)
    t = elu(t)
    t = gn(t)
    return torch.log(torch.clamp(t, min=1e-6))

eager = fn()

torch._dynamo.reset()
compiled = torch.compile(fn, backend="inductor")()

diff = (eager - compiled).abs().max().item()
print(f"max_diff = {diff:.6f}")
print("BUG" if diff > 1e-4 else "OK")
