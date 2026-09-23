# source: https://github.com/pytorch/pytorch/issues/189895
# title: [inductor] Silent wrong results: constant_pad_nd fused into a split reduction drops the pad's boundary select (corrupts flash-attn cu_seqlens)
# state: closed  created: 2026-07-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def cu_seqlens(mask):
    lengths = mask.sum(dim=-1, dtype=torch.int32)
    return F.pad(torch.cumsum(lengths, dim=0, dtype=torch.int32), (1, 0))

mask = torch.ones(1, 16384, device="cuda", dtype=torch.bool)

print("eager   :", cu_seqlens(mask).tolist())
print("compiled:", torch.compile(cu_seqlens, fullgraph=True)(mask).tolist())
