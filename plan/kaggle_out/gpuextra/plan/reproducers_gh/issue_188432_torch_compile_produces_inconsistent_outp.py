# source: https://github.com/pytorch/pytorch/issues/188432
# title: torch.compile produces inconsistent outputs for Multi-Query Attention model with manually implemented attention
# state: closed  created: 2026-06-29
# mined automatically; the harness records the torch.compile target and its first call

import os
import copy
import torch
import torch.nn as nn
import torch.nn.functional as F

class MultiQueryAttention(nn.Module):
    def __init__(self, embed_dim, num_heads, dropout=0.1):
        super().__init__()
        self.embed_dim = embed_dim
        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads
        assert self.head_dim * num_heads == embed_dim
        self.q_proj = nn.Linear(embed_dim, embed_dim)
        self.k_proj = nn.Linear(embed_dim, self.head_dim)
        self.v_proj = nn.Linear(embed_dim, self.head_dim)
        self.out_proj = nn.Linear(embed_dim, embed_dim)
        self.dropout = nn.Dropout(dropout)

    def forward(self, x, mask=None):
        batch_size, seq_len, _ = x.shape
        q = self.q_proj(x)
        k = self.k_proj(x)
        v = self.v_proj(x)
        q = q.view(batch_size, seq_len, self.num_heads, self.head_dim).transpose(1, 2)
        k = k.unsqueeze(1).expand(-1, self.num_heads, -1, -1)
        v = v.unsqueeze(1).expand(-1, self.num_heads, -1, -1)
        attn_scores = self.head_dim ** 0.5 / (q @ k.transpose(-2, -1))
        if mask is not None:
            attn_scores = attn_scores.masked_fill(mask == 0, float('-inf'))
        attn_weights = F.softmax(attn_scores, dim=-1)
        attn_weights = self.dropout(attn_weights)
        output = attn_weights @ v
        output = output.transpose(1, 2).contiguous().view(batch_size, seq_len, self.embed_dim)
        output = self.out_proj(output)
        return output

class MQA_DNN(nn.Module):
    def __init__(self, embed_dim, num_heads, hidden_dim, num_layers, dropout=0.1):
        super().__init__()
        self.layers = nn.ModuleList([
            nn.ModuleDict({
                'mqa': MultiQueryAttention(embed_dim, num_heads, dropout),
                'ffn': nn.Sequential(
                    nn.Linear(embed_dim, hidden_dim),
                    nn.ReLU(),
                    nn.Dropout(dropout),
                    nn.Linear(hidden_dim, embed_dim),
                    nn.Dropout(dropout)
                ),
                'norm1': nn.LayerNorm(embed_dim),
                'norm2': nn.LayerNorm(embed_dim)
            }) for _ in range(num_layers)
        ])

    def forward(self, x, mask=None):
        for layer in self.layers:
            attn_output = layer['mqa'](layer['norm1'](x), mask)
            x = x + attn_output
            ffn_output = layer['ffn'](layer['norm2'](x))
            x = x + ffn_output
        return x

def get_default_model():
    return MQA_DNN(embed_dim=512, num_heads=8, hidden_dim=2048, num_layers=6, dropout=0.1)

def get_sample_inputs():
    return (torch.randn(2, 20, 512), None)

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
