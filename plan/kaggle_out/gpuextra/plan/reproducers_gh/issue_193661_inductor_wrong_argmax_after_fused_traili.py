# source: https://github.com/pytorch/pytorch/issues/193661
# title: [inductor] Wrong argmax after fused trailing-dim reduction on non-contiguous inputs (incl. non-unit-stride reduction window) — generic reduction fusion ignores input strides, CPU and CUDA
# state: closed  created: 2026-08-15
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    return torch.argmax(torch.mean(x, dim=-1))

torch.manual_seed(123)
x = torch.rand([2, 4, 4, 8]).transpose(0, 1).contiguous().transpose(0, 1)[..., ::2]
# shape (2, 4, 4, 4), strides (32, 64, 8, 2)
# non-contiguous leading dims AND a stride-2 reduction window

print("eager   =", fn(x).item())                # 12 (correct)
print("compiled=", torch.compile(fn)(x).item()) # 24 (wrong)
