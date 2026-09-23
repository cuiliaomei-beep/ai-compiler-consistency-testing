# source: https://github.com/pytorch/pytorch/issues/187018
# title: abs on uint8 silently miscompiled via std::abs integer promotion
# state: closed  created: 2026-06-11
# mined automatically; the harness records the torch.compile target and its first call

import sys, platform
import torch
import numpy as np

print(f"python   : {sys.version.split()[0]}")
print(f"platform : {platform.platform()}")
print(f"torch    : {torch.__version__}")
print("-" * 50)

def f_bug(x):
    y = -x.abs()
    return torch.cat([y, y]).sum()

def f_ok(x):
    return torch.cat([-x.abs(), -x.abs()]).sum()

x = torch.tensor([200, 200], dtype=torch.uint8)
print(torch.compile(f_bug)(x).item(),
      torch.compile(f_ok)(x).item())
