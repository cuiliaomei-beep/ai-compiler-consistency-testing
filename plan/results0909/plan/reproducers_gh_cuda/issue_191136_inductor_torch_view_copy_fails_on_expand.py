# source: https://github.com/pytorch/pytorch/issues/191136
# title: [Inductor] torch.view_copy fails on expanded tensors
# state: open  created: 2026-07-26
# mined automatically; the harness records the torch.compile target and its first call

import torch


def f(x):
    return torch.view_copy(x, (8,))

x = torch.arange(2, dtype=torch.float32).expand(4, 2)


print("eager:", f(x))
compiled_f = torch.compile(f, backend="inductor", fullgraph=True)
print("compiled:", compiled_f(x))
