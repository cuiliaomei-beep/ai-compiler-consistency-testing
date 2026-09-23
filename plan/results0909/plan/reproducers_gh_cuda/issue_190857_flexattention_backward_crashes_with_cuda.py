# source: https://github.com/pytorch/pytorch/issues/190857
# title: FlexAttention backward crashes with CUDA illegal memory access when flattened K/V address exceeds INT32_MAX
# state: closed  created: 2026-07-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.nn.attention.flex_attention import flex_attention

KV_LEN = 24000
HEAD_DIM = 128
Q_LEN = 256
DTYPE = torch.bfloat16
INT32_MAX = torch.iinfo(torch.int32).max


@torch.compile(fullgraph=True)
def run(q, k, v):
    return flex_attention(q, k, v)


def make_inputs(batch, device):
    # K/V stored seq-major as [KV_LEN, B, HEAD_DIM], viewed as [B, 1, KV_LEN, HEAD_DIM].
    # stride_kn = B * HEAD_DIM, so offs_n_load * stride_kn overflows int32.
    k_storage = torch.randn(KV_LEN, batch, HEAD_DIM, device=device, dtype=DTYPE)
    v_storage = torch.randn(KV_LEN, batch, HEAD_DIM, device=device, dtype=DTYPE)
    k = k_storage.permute(1, 0, 2).unsqueeze(1).requires_grad_()
    v = v_storage.permute(1, 0, 2).unsqueeze(1).requires_grad_()
    q = torch.randn(batch, 1, Q_LEN, HEAD_DIM, device=device, dtype=DTYPE, requires_grad=True)
    return q, k, v


def fwd_bwd(batch, device="cuda"):
    q, k, v = make_inputs(batch, device)
    out = run(q, k, v)
    out.backward(torch.randn_like(out))
    torch.cuda.synchronize()


print(f"INT32_MAX = {INT32_MAX:,}")
print()

# batch=699: 24000 * 699 * 128 = 2,147,328,000 < INT32_MAX -> passes
addr = KV_LEN * 699 * HEAD_DIM
print(f"batch=699: KV addr = {addr:,} < INT32_MAX -> expecting pass")
fwd_bwd(699)
print("batch=699: fwd+bwd OK")
print()

# batch=700: 24000 * 700 * 128 = 2,150,400,000 > INT32_MAX -> illegal memory access
addr = KV_LEN * 700 * HEAD_DIM
print(f"batch=700: KV addr = {addr:,} > INT32_MAX -> expecting CUDA illegal memory access")
fwd_bwd(700)  # raises: CUDA error: an illegal memory access was encountered
