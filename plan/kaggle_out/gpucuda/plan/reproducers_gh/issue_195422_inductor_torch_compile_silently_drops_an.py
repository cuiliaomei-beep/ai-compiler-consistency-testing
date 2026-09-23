# source: https://github.com/pytorch/pytorch/issues/195422
# title: [inductor] torch.compile silently drops an in-place mutation of an input made through F.dropout's identity return
# state: closed  created: 2026-08-31
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    y = torch.nn.functional.dropout(x, 0.5, False)   # training=False -> y IS x
    y += y                                            # in-place mutation of the input
    return y

x = torch.ones(2, 2)
f(x)
print("eager    input after call:", x.flatten()[0].item())      # 2.0  (mutated)

x = torch.ones(2, 2)
torch.compile(f, backend="inductor")(x)
print("compiled input after call:", x.flatten()[0].item())      # 1.0  (mutation lost)
