# source: https://github.com/pytorch/pytorch/issues/194547
# title: torch.compile silently promotes dtype for torch.distributions.Normal.sample() where eager preserves it
# state: open  created: 2026-08-23
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch.manual_seed(1367)

def fn(loc, scale):
    d = torch.distributions.Normal(loc, scale)
    return d.sample()

loc = torch.zeros(8).to(torch.float16)
scale = torch.ones(8)  # float32

# eager
out = fn(loc, scale)
print(out.dtype)  # torch.float16

# compiled
out = torch.compile(fn)(loc, scale)
print(out.dtype)  # torch.float32
