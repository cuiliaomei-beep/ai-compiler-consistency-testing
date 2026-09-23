# source: https://github.com/pytorch/pytorch/issues/193938
# title: [inductor][cuda] `align_random_eager=True` makes compiled `torch.randn` / `randn_like` return uniform(0,1) values instead of standard normal
# state: closed  created: 2026-08-18
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._inductor.config as ic
ic.align_random_eager = True

def fn():
    return torch.randn(4, 5000, device="cuda")

torch.manual_seed(1234)
x = torch.compile(fn)()
torch.cuda.synchronize()
print(x.min().item(), x.max().item(), x.mean().item(), x.std().item())
# (~0.0, ~1.0, ~0.5, ~0.29) -> uniform(0,1); eager randn is N(0,1)
