# source: https://github.com/pytorch/pytorch/issues/183677
# title: [HOP] Alias/mutation fake traces should ignore discarded unbacked symbols
# state: closed  created: 2026-05-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn.attention.flex_attention import create_block_mask, flex_attention


if not torch.cuda.is_available():
    raise RuntimeError("This repro needs CUDA because FlexAttention backward is CUDA-only.")


device = "cuda"
dtype = torch.float16


def score_mod(score, batch, head, q_idx, kv_idx):
    return score


compiled_create_block_mask = torch.compile(
    create_block_mask,
    dynamic=True,
    fullgraph=True,
)


def create_dynamic_block_mask(q_batch, kv_batch):
    q_len = q_batch.size(0)
    kv_len = kv_batch.size(0)

    def mask_mod(batch, head, q_idx, kv_idx):
        q_group = q_batch[q_idx]
        kv_group = kv_batch[kv_idx]
        return (q_group == kv_group) & (q_group != -1) & (kv_group != -1)

    return compiled_create_block_mask(
        mask_mod,
        B=None,
        H=None,
        Q_LEN=q_len,
        KV_LEN=kv_len,
        device=device,
        BLOCK_SIZE=128,
    )


groups = torch.zeros(128, dtype=torch.int64, device=device)
block_mask = create_dynamic_block_mask(groups, groups)

q = torch.randn(1, 1, 128, 64, device=device, dtype=dtype, requires_grad=True)
k = torch.randn(1, 1, 128, 64, device=device, dtype=dtype, requires_grad=True)
v = torch.randn(1, 1, 128, 64, device=device, dtype=dtype, requires_grad=True)

compiled_flex_attention = torch.compile(
    flex_attention,
    fullgraph=True,
    dynamic=True,
    backend="aot_eager",
)

out = compiled_flex_attention(q, k, v, score_mod=score_mod, block_mask=block_mask)
out.sum().backward()
torch.cuda.synchronize()
print("ok", out.shape)
