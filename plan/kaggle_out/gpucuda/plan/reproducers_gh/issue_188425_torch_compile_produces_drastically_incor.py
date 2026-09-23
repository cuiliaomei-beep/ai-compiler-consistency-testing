# source: https://github.com/pytorch/pytorch/issues/188425
# title: torch.compile produces drastically incorrect outputs for model with symbolic dimensions and random operations
# state: closed  created: 2026-06-29
# mined automatically; the harness records the torch.compile target and its first call

import os
import torch
import copy
import torch.nn as nn
import torch.nn.functional as F

class TestModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(3, 10, kernel_size=3, padding=1)
        self.lstm = nn.LSTM(10, 20, 2)
        self.fc = nn.Linear(20, 10)
        self.relu = nn.ReLU()
        self.sigmoid = nn.Sigmoid()
        self.composite_op = self._composite_op

    def _composite_op(self, x):
        return x + F.relu(x) * 2

    def forward(self, x):
        x = self.conv(x)
        x = self.relu(x)
        x = x.view(x.size(0), -1, x.size(1))
        x = x.permute(1, 0, 2)
        lstm_out, _ = self.lstm(x)
        x = lstm_out[-1, :, :]
        x = self.fc(x)
        x = self.sigmoid(x)
        x = torch.arange(_get_symbolic_dim('hidden_size'))
        x = self.composite_op(x)
        x = x * torch.normal(mean=0, std=1.0, size=x.shape)
        return x

def get_default_model():
    return TestModel()

def get_sample_inputs():
    return (torch.randn(8, 3, 32, 32, requires_grad=True),)

def _get_symbolic_dim(dim_name):
    defaults = {'batch_size': 32, 'seq_len': 128, 'hidden_size': 768, 
                'num_heads': 12, 'dim': 64, 'size': 100, 'length': 50}
    return defaults.get(dim_name, 64)

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
