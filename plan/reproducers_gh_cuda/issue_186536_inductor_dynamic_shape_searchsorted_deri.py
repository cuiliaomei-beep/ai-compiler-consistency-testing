# source: https://github.com/pytorch/pytorch/issues/186536
# title: [inductor] Dynamic-shape `searchsorted`-derived index trips a device-side bounds assert on in-bounds CUDA inputs
# state: closed  created: 2026-06-07
# mined automatically; the harness records the torch.compile target and its first call

import torch

dev = "cuda"
torch.manual_seed(0)
lengths = torch.randint(54, 226, (64,), device=dev)
offsets = torch.zeros(65, dtype=torch.long, device=dev)
offsets[1:] = lengths.cumsum(0)
values = torch.randn(int(offsets[-1]), 32, device=dev)   # values.size(0) == offsets[-1]: every index valid
torch._dynamo.mark_dynamic(values, 0)                    # size(0) a free symbol, != offsets[-1] (data)

def densify(values, offsets):
    flat = torch.arange(values.size(0), device=values.device)
    batch_idx = torch.searchsorted(offsets[1:], flat, right=True)   # eager: 0..63
    local_idx = flat - offsets[batch_idx]
    out = values.new_zeros(offsets.shape[0] - 1, int(lengths.max()), values.size(1))
    out[batch_idx, local_idx] = values
    return out

ref = densify(values, offsets)                                                 # eager: OK
out = torch.compile(densify, fullgraph=True, dynamic=True)(values, offsets)     # device-side assert
print((out - ref).abs().max().item())
