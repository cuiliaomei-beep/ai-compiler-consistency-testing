# source: https://github.com/pytorch/pytorch/issues/181694
# title: `torch.addcdiv` produces wrong output under `torch.compile(backend='inductor')`
# state: closed  created: 2026-04-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

bn1 = nn.BatchNorm1d(7).eval()
gn  = nn.GroupNorm(1, 7).eval()
bn2 = nn.BatchNorm1d(7).eval()

def model():
    x = torch.ones([7, 7])
    t = bn1(x)
    t = gn(t)
    # normalised residual: t + t / clamp(t, min=1e-6)
    t = torch.addcdiv(t, t, torch.clamp(t, min=1e-6))   # ← wrong in compiled
    t = bn2(t)
    return t

eager_out    = model()
compiled_out = torch.compile(model, backend='inductor')()

print("max diff:", (eager_out - compiled_out).abs().max().item())
# Expected: ~0.0
# Actual:    31.517422
