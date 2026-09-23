# source: https://github.com/pytorch/pytorch/issues/191571
# title: `torch.compile` silently returns stale zeros when a size-1 `scatter_add_` is gathered from in the same graph (read-before-write in a fused Triton kernel)
# state: closed  created: 2026-07-30
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x, idx):
    res = torch.zeros(1, x.shape[1], device=x.device, dtype=x.dtype)
    res.scatter_add_(0, idx.unsqueeze(-1).expand(-1, x.shape[1]), x)
    return torch.index_select(res, 0, idx)

x = torch.randn(8, 4, device="cuda")
idx = torch.zeros(8, dtype=torch.long, device="cuda")

eager = f(x, idx)
compiled = torch.compile(f)(x, idx)

print("max |eager - compiled| =", (eager - compiled).abs().max().item())
print("eager row0    :", eager[0].tolist())
print("compiled row0 :", compiled[0].tolist())
print("column sums   :", x.sum(0).tolist())
