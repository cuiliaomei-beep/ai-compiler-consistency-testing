# source: https://github.com/pytorch/pytorch/issues/183601
# title: torch.compile Inductor produces wrong output for InstanceNorm2d + normalize + hardswish chain
# state: closed  created: 2026-05-13
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(42)

x = torch.randn(4, 3, 10, 12)
inst_norm = nn.InstanceNorm2d(3)
pool = nn.AdaptiveAvgPool2d((1, 1))

def m():
    t = inst_norm(x)
    t = pool(t)
    t = F.normalize(t, dim=0)
    t = t * x
    t = F.hardswish(t)
    return F.normalize(t, dim=0)

torch._dynamo.reset()
eager = m()

torch._dynamo.reset()
compiled = torch.compile(m, backend="inductor")()

print("eager vs compile max_diff:", (eager - compiled).abs().max().item())
