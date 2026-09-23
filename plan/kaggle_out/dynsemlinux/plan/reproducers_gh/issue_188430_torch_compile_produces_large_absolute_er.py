# source: https://github.com/pytorch/pytorch/issues/188430
# title: torch.compile produces large absolute errors for model with LSTM, MultiheadAttention, and torch.reciprocal
# state: closed  created: 2026-06-29
# mined automatically; the harness records the torch.compile target and its first call

import os
import torch
import copy
import torch.nn as nn
import torch.nn.functional as F

class AttentionModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.lstm = nn.LSTM(input_size=5, hidden_size=20, num_layers=1, batch_first=False)
        self.linear1 = nn.Linear(20, 20)
        self.attention1 = nn.MultiheadAttention(embed_dim=20, num_heads=2, batch_first=torch.tensor(False, device='cpu'))
        self.relu = nn.ReLU()
        self.linear2 = nn.Linear(20, 15)
        self.attention2 = nn.MultiheadAttention(embed_dim=15, num_heads=5, batch_first=False)
        self.linear3 = nn.Linear(15, 10)
        self.attention3 = nn.MultiheadAttention(embed_dim=10, num_heads=2, batch_first=False)

    def forward(self, x):
        lstm_out, _ = self.lstm(x)
        linear1_out = self.relu(self.linear1(lstm_out))
        attn1_out, _ = self.attention1(linear1_out, linear1_out, linear1_out)
        reciprocal1 = torch.reciprocal(attn1_out)
        linear2_out = self.relu(self.linear2(reciprocal1))
        attn2_out, _ = self.attention2(linear2_out, linear2_out, linear2_out)
        reciprocal2 = attn2_out.reciprocal()
        linear3_out = self.relu(self.linear3(reciprocal2))
        attn3_out, _ = self.attention3(linear3_out, linear3_out, linear3_out)
        reciprocal3 = torch.reciprocal(attn3_out)
        return reciprocal3

def get_default_model():
    return AttentionModel()

def get_sample_inputs():
    return (torch.randn(10, 2, 5, dtype=torch.float64),)

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
