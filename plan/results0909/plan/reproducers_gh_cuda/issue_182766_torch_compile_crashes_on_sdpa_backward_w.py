# source: https://github.com/pytorch/pytorch/issues/182766
# title: `torch.compile` crashes on SDPA backward when head_dim is not a multiple of 16
# state: closed  created: 2026-05-07
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

# Crashes for any head_dim that is not a multiple of 16
q = torch.randn(2, 4, 8, 33, device='cuda', requires_grad=True)
k = torch.randn(2, 4, 8, 33, device='cuda', requires_grad=True)
v = torch.randn(2, 4, 8, 33, device='cuda', requires_grad=True)

@torch.compile
def fn(q, k, v):
    return F.scaled_dot_product_attention(q, k, v).sum()

fn(q, k, v).backward()  # LoweringException: IndexError: list index out of range
