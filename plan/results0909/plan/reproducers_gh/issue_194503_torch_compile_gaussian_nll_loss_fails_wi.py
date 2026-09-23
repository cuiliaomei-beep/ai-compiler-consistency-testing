# source: https://github.com/pytorch/pytorch/issues/194503
# title: [torch.compile] gaussian_nll_loss fails with a data-dependent guard under fullgraph=True
# state: open  created: 2026-08-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def fn(input, target, var):
    return F.gaussian_nll_loss(input, target, var)

input = torch.zeros(2, 3)
target = torch.ones(2, 3)
var = torch.ones(2, 3)

print("eager:", fn(input, target, var))
compiled = torch.compile(fn, backend="inductor", fullgraph=True)
print("compiled:", compiled(input, target, var))
