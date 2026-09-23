# source: https://github.com/pytorch/pytorch/issues/195579
# title: [meta / decomps] torch.compile skips addmm's broadcast check: eager raises, compiled returns the broadcast result
# state: open  created: 2026-09-01
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(inp, m1, m2):
    return torch.addmm(inp, m1, m2)

torch.manual_seed(0)
inp = torch.randn(500, 1)      # mat1 @ mat2 is (1, 1)
m1  = torch.randn(1, 1)
m2  = torch.randn(1, 1)

try:
    f(inp, m1, m2)
    print("eager: returned")
except Exception as e:
    print("eager:", type(e).__name__, str(e).splitlines()[0])

out = torch.compile(f, backend="inductor")(inp, m1, m2)
print("compiled: returned", tuple(out.shape))
