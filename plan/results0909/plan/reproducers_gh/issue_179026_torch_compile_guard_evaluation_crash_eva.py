# source: https://github.com/pytorch/pytorch/issues/179026
# title: `torch.compile` guard evaluation crash: `eval_is_non_overlapping_and_dense()` calling convention mismatch with `IsNonOverlappingAndDenseIndicator`
# state: closed  created: 2026-04-01
# mined automatically; the harness records the torch.compile target and its first call

import torch

# repeat_kv pattern that triggers the bug under dynamic shapes
def repeat_kv(hidden_states: torch.Tensor, n_rep: int) -> torch.Tensor:
    batch, num_key_value_heads, slen, head_dim = hidden_states.shape
    if n_rep == 1:
        return hidden_states
    hidden_states = hidden_states[:, :, None, :, :].expand(
        batch, num_key_value_heads, n_rep, slen, head_dim
    )
    return hidden_states.reshape(batch, num_key_value_heads * n_rep, slen, head_dim)

compiled_fn = torch.compile(repeat_kv, dynamic=True)

x = torch.randn(2, 4, 128, 64)
# First call traces successfully
out1 = compiled_fn(x, 2)
# Subsequent call with different dynamic shape may trigger guard re-evaluation crash
x2 = torch.randn(3, 4, 256, 64)
out2 = compiled_fn(x2, 2)
