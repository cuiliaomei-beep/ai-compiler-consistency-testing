# source: https://github.com/pytorch/pytorch/issues/178040
# title: `torch.compile` raises RuntimeError on valid `torch.addmm` with shape mismatch where eager succeeds
# state: closed  created: 2026-03-21
# mined automatically; the harness records the torch.compile target and its first call

import torch

d_model = 512
vocab_size = 10000
batch_size = 4

x = torch.randn(batch_size, d_model, device="cuda")
weight = torch.randn(vocab_size, d_model, device="cuda")
bias = torch.zeros(d_model, device="cuda")  # shape [512], not [10000]

# Eager: succeeds because beta=0.0 zeros out the bias term
try:
    out = torch.addmm(bias, x, weight.t(), beta=0.0, alpha=0.1)
    print(f"eager: OK shape={out.shape}")
except RuntimeError as e:
    print(f"eager: ERROR — {e}")

# Compiled: raises shape mismatch error
torch._dynamo.reset()

@torch.compile(fullgraph=True)
def compiled_addmm(bias, x, weight):
    return torch.addmm(bias, x, weight.t(), beta=0.0, alpha=0.1)

try:
    out = compiled_addmm(bias, x, weight)
    print(f"compile: OK shape={out.shape}")
except RuntimeError as e:
    print(f"compile: ERROR — {e}")
