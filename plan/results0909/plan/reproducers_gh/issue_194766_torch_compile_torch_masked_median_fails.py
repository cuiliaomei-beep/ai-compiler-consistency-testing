# source: https://github.com/pytorch/pytorch/issues/194766
# title: [torch.compile] torch.masked.median fails on integer inputs under fullgraph=True
# state: open  created: 2026-08-25
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.masked as masked

def fn(input, mask):
    return masked.median(input, dim=0, mask=mask)

input = torch.tensor([1, 9, 3])
mask = torch.tensor([True, False, True])

print("eager:", fn(input, mask))
compiled = torch.compile(fn, backend="inductor", fullgraph=True)
print("compiled:", compiled(input, mask))
