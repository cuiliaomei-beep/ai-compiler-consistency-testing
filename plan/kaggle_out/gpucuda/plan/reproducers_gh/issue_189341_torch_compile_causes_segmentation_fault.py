# source: https://github.com/pytorch/pytorch/issues/189341
# title: torch.compile causes segmentation fault on XPU with all nightly builds
# state: closed  created: 2026-07-09
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    return x * 2 + 1

x = torch.randn(4, 4, device='xpu')
print(f"Eager mode: {fn(x).shape}")  # ✅ Works

compiled_fn = torch.compile(fn, backend="inductor")
result = compiled_fn(x)  # ❌ Segmentation fault (core dumped)
