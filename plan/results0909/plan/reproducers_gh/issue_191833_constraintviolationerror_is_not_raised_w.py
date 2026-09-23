# source: https://github.com/pytorch/pytorch/issues/191833
# title: ConstraintViolationError is not raised when multiple shape guards specialize dynamic dimensions to a single shape
# state: open  created: 2026-08-01
# mined automatically; the harness records the torch.compile target and its first call

import torch


def f(x):
    a, b = x.shape

    if a > b:
        return x + 1
    if a < b:
        return x - 1
    if a + b != 10:
        return x + 2

    return x + 3


x = torch.randn(5, 5)
torch._dynamo.mark_dynamic(x, 0)
torch._dynamo.mark_dynamic(x, 1)

compiled_f = torch.compile(f, backend="eager", fullgraph=True)
compiled_f(x)
