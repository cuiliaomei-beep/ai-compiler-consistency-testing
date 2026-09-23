# source: https://github.com/pytorch/pytorch/issues/184101
# title: `torch.compile` backward crashes for `abs()`/`angle()` on transposed complex tensors
# state: open  created: 2026-05-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

x = torch.randn(4, 8, dtype=torch.complex64, device="cuda", requires_grad=True)

# Eager: works
(x.T.abs().sum()).backward()
print(x.grad.shape)  # torch.Size([4, 8])

# Compiled: crashes on backward
x.grad = None
torch.compile(lambda x: x.T.abs().sum(), backend="inductor")(x).backward()
