# source: https://github.com/pytorch/pytorch/issues/185472
# title: [Inductor] `F.hardtanh` compiled backward silently drops gradient at bf16 boundary values
# state: closed  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

# bf16(0.7) = 0.69921875 (bf16 rounds 0.7 down)
x = torch.tensor([0.69921875], dtype=torch.bfloat16, device='cuda', requires_grad=True)

# Eager: gradient passes through (value is within bounds)
F.hardtanh(x, min_val=-0.7, max_val=0.7).backward()
print(f"eager grad:    {x.grad}")  # tensor([1.], ...) ← correct

# Compiled: gradient is zeroed
x2 = torch.tensor([0.69921875], dtype=torch.bfloat16, device='cuda', requires_grad=True)
torch._dynamo.reset()
torch.compile(lambda y: F.hardtanh(y, min_val=-0.7, max_val=0.7))(x2).backward()
print(f"compiled grad: {x2.grad}")  # tensor([0.], ...) ← WRONG
