# source: https://github.com/pytorch/pytorch/issues/188074
# title: torch.compile produces inconsistent outputs for stateful SNN model with custom LIF neurons
# state: closed  created: 2026-06-24
# mined automatically; the harness records the torch.compile target and its first call

import os
import copy
import torch
import torch.nn as nn
import torch.nn.functional as F

class LIFNeuron(nn.Module):

    def __init__(self, threshold=1.0, decay=0.9):
        super().__init__()
        self.threshold = threshold
        self.decay = nn.Parameter(torch.tensor(decay), requires_grad=True)
        self.register_buffer('mem_potential', None)

    def reset(self):
        self.mem_potential = None

    def forward(self, x):
        if self.mem_potential is None:
            self.mem_potential = torch.zeros_like(x)
        self.mem_potential = self.decay * self.mem_potential + x
        spike = torch.sigmoid(10 * (self.mem_potential - self.threshold))
        self.mem_potential = self.mem_potential * (1 - spike)
        return spike

class SNN(nn.Module):

    def __init__(self, input_dim=784, hidden_dim=128, output_dim=10, time_steps=10):
        super().__init__()
        self.time_steps = time_steps
        self.fc1 = nn.Linear(input_dim, hidden_dim)
        self.lif1 = LIFNeuron(threshold=0.5, decay=0.8)
        self.fc2 = nn.Linear(hidden_dim, output_dim)
        self.lif2 = LIFNeuron(threshold=0.5, decay=0.8)

    def forward(self, x):
        batch_size = x.size(0)
        self.lif1.reset()
        self.lif2.reset()
        total_output = torch.zeros(batch_size, self.fc2.out_features, device=x.device)
        for _ in range(self.time_steps):
            spike_input = torch.bernoulli(x).detach() + x - x.detach()
            h = F.relu(self.fc1(spike_input))
            h = self.lif1(h)
            out = getattr(self, 'fc2')(h)
            spikes = self.lif2(out)
            total_output += spikes
        return total_output / self.time_steps

def get_default_model():
    input_dim = 784
    hidden_dim = 128
    output_dim = 10
    time_steps = 10
    model = SNN(input_dim=input_dim, hidden_dim=hidden_dim, output_dim=output_dim, time_steps=time_steps)
    return model

def get_sample_inputs():
    batch_size = 2
    input_dim = 784
    x = torch.rand(batch_size, input_dim)
    return (x,)


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
