# source: https://github.com/pytorch/pytorch/issues/181688
# title: Heap corruption / SIGABRT when compiling `ConvTranspose2d` + normalization layers with `torch.compile(backend='inductor')`
# state: closed  created: 2026-04-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

torch.manual_seed(0)
x = torch.randn([9, 8, 14, 11])

conv_t = nn.ConvTranspose2d(8, 6, 2)
gn     = nn.GroupNorm(6, 6).eval()
ln1    = nn.LayerNorm([12])
ln2    = nn.LayerNorm([12])

def model():
    t = torch.clamp(x, min=-2.0, max=2.0)
    t = conv_t(t)
    t = gn(t)
    t = ln1(t)
    t = ln2(t)
    return t

# Eager forward works fine
out = model()
assert torch.isfinite(out).all()

# Compiled forward crashes the process
compiled = torch.compile(model, backend='inductor')
compiled()   # ← SIGABRT / heap corruption here
