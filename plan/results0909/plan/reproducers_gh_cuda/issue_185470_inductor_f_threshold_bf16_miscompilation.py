# source: https://github.com/pytorch/pytorch/issues/185470
# title: [Inductor] `F.threshold` bf16 miscompilation: scalar threshold not cast to tensor dtype
# state: open  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

x = torch.tensor([0.10009765625], dtype=torch.bfloat16, device='cuda')
# 0.10009765625 is the bf16 representation of 0.1

eager = F.threshold(x, 0.1, 0.0)
print(f"eager:    {eager}")    # tensor([0.], device='cuda:0', dtype=torch.bfloat16)  ← correct

torch._dynamo.reset()
compiled = torch.compile(F.threshold)(x, 0.1, 0.0)
print(f"compiled: {compiled}")  # tensor([0.1001], device='cuda:0', dtype=torch.bfloat16)  ← WRONG
