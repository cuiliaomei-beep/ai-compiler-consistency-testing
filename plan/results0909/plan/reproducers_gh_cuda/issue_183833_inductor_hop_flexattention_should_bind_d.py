# source: https://github.com/pytorch/pytorch/issues/183833
# title: [Inductor][HOP] FlexAttention should bind derived unbacked tensor input extents from runtime metadata
# state: closed  created: 2026-05-15
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._dynamo.decorators import mark_unbacked
from torch.nn.attention.flex_attention import create_block_mask, flex_attention


if not torch.cuda.is_available():
    raise RuntimeError("This repro needs CUDA.")


device = "cuda"
B, H, S, D, MAX_S = 4, 2, 64, 64, 128
stride = (H * MAX_S * D, MAX_S * D, D, 1)


def make_tensor():
    tensor = torch.empty_strided(
        (B, H, S, D), stride, device=device, dtype=torch.float16
    )
    tensor.normal_()
    tensor.requires_grad_(True)
    mark_unbacked(tensor, 0, hint_override=B, shape_id="batch", min=2, max=B)
    mark_unbacked(tensor, 2, hint_override=S, shape_id="seq", min=1, max=MAX_S)
    return tensor


def causal_mask(_b, _h, q_idx, kv_idx):
    return q_idx >= kv_idx


block_mask = create_block_mask(
    causal_mask, B=None, H=None, Q_LEN=S, KV_LEN=S, device=device
)
q, k, v = make_tensor(), make_tensor(), make_tensor()


@torch.compile(dynamic=True, fullgraph=True)
def fn(q, k, v):
    mid = q.shape[0] // 2
    return (
        flex_attention(q[:mid], k[:mid], v[:mid], block_mask=block_mask).sum()
        + flex_attention(q[mid:], k[mid:], v[mid:], block_mask=block_mask).sum()
    )


fn(q, k, v).backward()
torch.cuda.synchronize()
print("ok")
