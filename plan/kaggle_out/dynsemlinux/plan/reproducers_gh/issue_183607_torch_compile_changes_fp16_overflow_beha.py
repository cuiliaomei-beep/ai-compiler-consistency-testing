# source: https://github.com/pytorch/pytorch/issues/183607
# title: torch.compile changes fp16 overflow behavior for cast-to-float16 multiplication
# state: open  created: 2026-05-13
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x):
    y = x.to(torch.float16)
    return (y * y).to(torch.float32)

x = torch.tensor([5000.0])

eager = fn(x).item()

torch._dynamo.reset()
compiled = torch.compile(fn, backend="inductor")(x).item()

print("eager:", eager, "compile:", compiled)
