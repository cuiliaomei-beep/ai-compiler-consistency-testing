# source: https://github.com/pytorch/pytorch/issues/174923
# title: FlexAttention: CUDA error: an illegal memory access was encountered
# state: closed  created: 2026-02-12
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn.attention.flex_attention import create_block_mask, flex_attention

torch.set_default_device("cuda")
torch.manual_seed(0)

# ---- 1) Pure causal mask: no external tensor access ----
def causal_mask_mod(b, h, q_idx, kv_idx):
    return q_idx >= kv_idx

# ---- 2) Compile ----
create_block_mask_compiled = torch.compile(create_block_mask)
flex_attention_compiled = torch.compile(flex_attention)

KERNEL_OPTIONS = {
    "FORCE_USE_FLEX_ATTENTION": True,
    "BLOCK_M": 16,
    "BLOCK_N": 16,
}

def run_once(Q_LEN: int, KV_LEN: int, enable_gqa: bool = True):
    HEADS = 1
    DIM = 64

    q = torch.randn(1, HEADS, Q_LEN, DIM, device="cuda")
    k = torch.randn(1, HEADS, KV_LEN, DIM, device="cuda")
    v = torch.randn(1, HEADS, KV_LEN, DIM, device="cuda")

    bm = create_block_mask_compiled(
        causal_mask_mod,
        B=None,
        H=None,
        Q_LEN=Q_LEN,
        KV_LEN=KV_LEN,
        device="cuda",
        BLOCK_SIZE=(16, 16),
    )

    out = flex_attention_compiled(
        q, k, v,
        block_mask=bm,
        enable_gqa=enable_gqa,
        kernel_options=KERNEL_OPTIONS,
    )

    torch.cuda.synchronize()
    print("OK, out.shape =", out.shape)

if __name__ == "__main__":
    # Prefill-like
    run_once(Q_LEN=7896, KV_LEN=931920)

    # Decode-like (often crashes)
    run_once(Q_LEN=2, KV_LEN=931920)
