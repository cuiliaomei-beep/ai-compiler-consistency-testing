# source: https://github.com/pytorch/pytorch/issues/188420
# title: torch.compile produces inconsistent outputs for MultiHeadAttentionModel with scaled_dot_product_attention
# state: closed  created: 2026-06-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import copy
import torch.nn as nn
import torch.nn.functional as F
import os

class MultiHeadAttentionModel(nn.Module):
    def __init__(self, d_model=512, n_heads=8, seq_len=64):
        super().__init__()
        self.d_model = d_model
        self.n_heads = n_heads
        self.head_dim = d_model // n_heads
        self.query_proj = nn.Linear(d_model, d_model)
        self.key_proj = nn.Linear(d_model, d_model)
        self.value_proj = nn.Linear(d_model, d_model)
        self.out_proj = nn.Linear(d_model, d_model)
        self.seq_len = seq_len

    def forward(self, x):
        batch_size = x.size(0)
        query = self.query_proj(x)
        key = self.key_proj(x)
        value = self.value_proj(x)
        query = query.view(batch_size, self.seq_len, self.n_heads, self.head_dim).transpose(1, 2)
        key = key.view(batch_size, self.seq_len, self.n_heads, self.head_dim).transpose(1, 2)
        value = value.view(batch_size, self.seq_len, self.n_heads, self.head_dim).transpose(1, 2)
        attn_output = F.scaled_dot_product_attention(query, key, value, attn_mask=None, dropout_p=0.1, is_causal=False)
        attn_output = attn_output.transpose(1, 2).contiguous().view(batch_size, self.seq_len, self.d_model)
        output = self.out_proj(attn_output)
        return output

def get_default_model():
    return MultiHeadAttentionModel(d_model=512, n_heads=8, seq_len=64)

def get_sample_inputs():
    return (torch.randn(4, 64, 512),)

def main():
    torch.use_deterministic_algorithms(True)
    torch.set_float32_matmul_precision('highest')
    os.environ['CUBLAS_WORKSPACE_CONFIG'] = ':4096:8'
    torch._inductor.config.fallback_random = True

    torch.manual_seed(42)
    model = get_default_model()
    model = model.double()
    model.eval()

    inputs = get_sample_inputs()
    inputs = tuple(t.double() if isinstance(t, torch.Tensor) and t.is_floating_point() else t for t in inputs)

    with torch.no_grad():
        eager_output = model(*inputs)
    print(f'eager float64 output: {eager_output}')

    torch.manual_seed(42)
    model_fp32 = copy.deepcopy(model)
    model_fp32 = model_fp32.float()
    model_fp32.eval()

    inputs_fp32 = tuple(t.float() if isinstance(t, torch.Tensor) and t.is_floating_point() else t for t in inputs)
    compiled_model = torch.compile(model_fp32, mode="reduce-overhead")

    with torch.no_grad():
        compiled_output = compiled_model(*inputs_fp32)
    print(f'compile float32 output: {compiled_output}')

    abs_diff = (eager_output - compiled_output.double()).abs()
    rel_diff = abs_diff / (eager_output.abs() + 1e-8)
    is_inconsistent = (abs_diff > 0.01) | (rel_diff > 0.001)

    print(f'Abs diff max: {abs_diff.max().item():.6e}, mean: {abs_diff.mean().item():.6e}')
    print(f'Rel diff max: {rel_diff.max().item():.6e}, mean: {rel_diff.mean().item():.6e}')
    print(f'Inconsistent: {is_inconsistent.sum().item()} / {eager_output.numel()}')

if __name__ == '__main__':
    main()
