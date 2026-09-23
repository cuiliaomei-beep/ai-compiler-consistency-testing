# source: https://github.com/pytorch/pytorch/issues/181693
# title: `nn.Hardswish` produces wrong output under `torch.compile(backend='inductor')`
# state: closed  created: 2026-04-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F

torch.manual_seed(0)
x = torch.randn([8, 2, 14, 16])

inst_norm  = nn.InstanceNorm2d(2)
pool       = nn.AdaptiveAvgPool2d((1, 1))
hardswish  = nn.Hardswish()

def model():
    t = inst_norm(x)
    t = pool(t)
    t = F.normalize(t, dim=0)
    t = torch.mul(t, torch.where(x > 0, x, x))
    t = hardswish(t)               # ← Inductor generates wrong kernel here
    t = F.normalize(t, dim=0)
    return t

eager_out    = model()
compiled_out = torch.compile(model, backend='inductor')()

print("max diff:", (eager_out - compiled_out).abs().max().item())
# Expected: ~0.0
# Actual:    1.821913
