# source: https://github.com/pytorch/pytorch/issues/181695
# title: `torch.where` with broadcast shapes produces wrong output under `torch.compile(backend='inductor')`
# state: closed  created: 2026-04-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

torch.manual_seed(0)
x = torch.randn([15, 13, 13, 13])

inst_norm = nn.InstanceNorm2d(13)
pool1     = nn.AdaptiveAvgPool2d((1, 1))
pool2     = nn.AdaptiveAvgPool2d((1, 1))

def model():
    normed = inst_norm(x)              # [15, 13, 13, 13]
    pooled = pool1(normed)             # [15, 13,  1,  1]
    pooled2 = pool2(pooled)            # [15, 13,  1,  1]
    # where broadcasts pooled [15,13,1,1] against normed [15,13,13,13]
    selected = torch.where(pooled > 0, pooled, normed)   # ← wrong in compiled
    return torch.sub(pooled2, selected)

eager_out    = model()
compiled_out = torch.compile(model, backend='inductor')()

print("max diff:", (eager_out - compiled_out).abs().max().item())
# Expected: ~0.0
# Actual:    4.175690
