# source: https://github.com/pytorch/pytorch/issues/183606
# title: torch.compile changes signed-zero behavior for torch.frac on -0.0
# state: closed  created: 2026-05-13
# mined automatically; the harness records the torch.compile target and its first call

import torch

x = torch.tensor([-0.0, -0.0, -0.0])

torch._dynamo.reset()
e1 = torch.frac(x)

torch._dynamo.reset()
c1 = torch.compile(torch.frac, backend="inductor")(x)

print("frac eager bits :", e1.view(torch.int32)[0].item())
print("frac compile bits:", c1.view(torch.int32)[0].item())

def fn(x):
    return 1.0 / torch.frac(x)

torch._dynamo.reset()
e2 = fn(x)

torch._dynamo.reset()
c2 = torch.compile(fn, backend="inductor")(x)

print("1/frac eager:", e2[0].item(), "compile:", c2[0].item())
