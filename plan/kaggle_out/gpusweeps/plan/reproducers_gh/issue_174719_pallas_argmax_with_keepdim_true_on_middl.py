# source: https://github.com/pytorch/pytorch/issues/174719
# title: [Pallas] argmax with keepdim=True on middle dimension produces incorrect reshape in generated kernel
# state: closed  created: 2026-02-10
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._inductor.config as config

x = torch.randint(0, 3, (4, 8, 64))

def fn(x):
    mask = x == 1
    return mask.max(dim=1, keepdim=True)

with config.patch({"cpu_backend": "pallas"}):
    compiled = torch.compile(fn, backend="inductor")
    compiled(x)  # TypeError: cannot reshape array of shape (8, 64) into shape (4, 1, 64)
