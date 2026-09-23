# source: https://github.com/pytorch/pytorch/issues/188878
# title: [FlexAttention] FLASH backend silently wrong: wrapped gather index misclassified as lane-uniform in vectorized score_mod groups
# state: closed  created: 2026-07-03
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn.attention.flex_attention import create_block_mask, flex_attention

device, dtype = "cuda", torch.bfloat16
B, H, S, D = 2, 8, 1024, 64
rel_bias = torch.randn(2 * S, device=device)
head_scale = torch.randn(H, device=device)
offset = S - 1

def score_mod(score, b, h, q_idx, kv_idx):
    return score + rel_bias[q_idx - kv_idx + offset] * head_scale[h]

bm = create_block_mask(lambda b, h, q, kv: q >= kv, None, None, S, S,
                       device=device, BLOCK_SIZE=(256, 128))
q, k, v = (torch.randn(B, H, S, D, device=device, dtype=dtype) for _ in range(3))
out = torch.compile(flex_attention)(
    q, k, v, score_mod=score_mod, block_mask=bm, kernel_options={"BACKEND": "FLASH"}
)
# ~92% of elements mismatch vs TRITON backend / eager reference
