# source: https://github.com/pytorch/pytorch/issues/188871
# title: [FlexAttention] FLASH backend: cute.where Int64/Int32 dtype mismatch in captured-buffer negative-index wrap under dynamic shapes
# state: closed  created: 2026-07-03
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn.attention.flex_attention import create_block_mask, flex_attention

device, dtype = "cuda", torch.bfloat16
flex_c = torch.compile(flex_attention)

def run(S):
    tbl = torch.randn(2 * S, device=device)
    offset = S - 1

    def mod(score, b, h, q, kv):
        return score + tbl[q - kv + offset]

    bm = create_block_mask(lambda b, h, q, kv: q >= kv, None, None, S, S,
                           device=device, BLOCK_SIZE=(256, 128))
    q_, k_, v_ = (torch.randn(2, 8, S, 64, device=device, dtype=dtype) for _ in range(3))
    with torch.no_grad():
        return flex_c(q_, k_, v_, score_mod=mod, block_mask=bm,
                      kernel_options={"BACKEND": "FLASH"})

run(512)    # static: works
run(1024)   # dynamic recompile: ValueError in cute.where
