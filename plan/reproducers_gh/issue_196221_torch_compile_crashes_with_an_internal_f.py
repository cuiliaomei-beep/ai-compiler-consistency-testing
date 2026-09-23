# source: https://github.com/pytorch/pytorch/issues/196221
# title: torch.compile crashes with an internal FakeTensor assertion for torch.func.grad with masked_select
# state: open  created: 2026-09-07
# mined automatically; the harness records the torch.compile target and its first call

import torch


def loss(x):
    selected = torch.masked_select(x, x > 0)
    return selected.square().sum()


def model(x):
    return torch.func.grad(loss)(x)


compiled_model = torch.compile(
    model,
    backend="eager",
    fullgraph=True,
    dynamic=True,
)

inputs = (
    torch.tensor([-2.0, 1.0, 3.0, -4.0]),
    torch.tensor([2.0, 1.0, -3.0, 4.0]),
)

for x in inputs:
    eager = model(x)
    compiled = compiled_model(x)
    torch.testing.assert_close(compiled, eager)
