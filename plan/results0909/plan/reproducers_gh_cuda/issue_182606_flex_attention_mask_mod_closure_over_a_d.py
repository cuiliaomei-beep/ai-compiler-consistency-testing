# source: https://github.com/pytorch/pytorch/issues/182606
# title: `flex_attention` + `mask_mod` closure over a derived sym-int
# state: closed  created: 2026-05-06
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn.attention.flex_attention import flex_attention, create_block_mask

def fn(q, k, v, current_pos: int):
    P_plus = current_pos + 1                  # derived sym-int OUTSIDE the closure
    def mask_mod(b, h, q_idx, kv_idx):
        return (kv_idx >= 0) & (kv_idx <= P_plus)
    bm = create_block_mask(mask_mod, B=None, H=None,
                            Q_LEN=q.shape[2], KV_LEN=k.shape[2],
                            device=q.device)
    return flex_attention(q, k, v, block_mask=bm)

B, H, M, KV_LEN, D = 1, 4, 1, 13, 64          # decode shapes; prefill also fails
q = torch.randn(B, H, M, D, device='cuda', dtype=torch.bfloat16)
k = torch.randn(B, H, KV_LEN, D, device='cuda', dtype=torch.bfloat16)
v = torch.randn(B, H, KV_LEN, D, device='cuda', dtype=torch.bfloat16)

compiled = torch.compile(fn, fullgraph=False)
compiled(q, k, v, current_pos=0)              # PASS — dynamo specializes on value
compiled(q, k, v, current_pos=5)              # FAIL — recompile with sym-int
