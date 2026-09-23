# source: https://github.com/pytorch/pytorch/issues/194444
# title: [inductor] SDPA fusion silently lost when a SymFloat scale is tensorified (dynamic shapes, e.g. head_dim ** 0.5)
# state: open  created: 2026-08-22
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._dynamo.utils import counters

def model(q, k, v):
    scale = q.size(0) ** 0.5
    return torch.nn.functional.softmax(
        q @ k.transpose(-2, -1) / scale, dim=-1) @ v

args = [torch.randn(8, 4, 4, 4) for _ in range(3)]
torch.compile(model, fullgraph=True, dynamic=True)(*args)
print(counters["inductor"]["fuse_attention"])  # 0 — fusion skipped
