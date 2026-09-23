# source: https://github.com/pytorch/pytorch/issues/181428
# title: torch.compile + torch.func.grad: superlinear compile time with MaxPool2d → log/clamp → pow → AdaptiveAvgPool2d
# state: open  created: 2026-04-24
# mined automatically; the harness records the torch.compile target and its first call

import os, tempfile, time
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp())

import torch
import torch.nn as nn
import torch.func as F

torch.manual_seed(0)
t = torch.randn([12, 8, 5, 13])

m1 = nn.MaxPool2d(2)
m2 = nn.AdaptiveAvgPool2d((1, 1))

def fn(x):
    x = m1(x)
    x = torch.log(torch.clamp(x, min=1e-6))
    x = torch.pow(x, 2)
    x = m2(x)
    return x.mean()

# eager: fast
_ = F.grad(fn)(t)

# compiled: slow (~15s, superlinear relative to individual operators)
t0 = time.time()
torch.compile(F.grad(fn))(t)
elapsed = time.time() - t0
print(f"compile time: {elapsed:.1f}s")
