# source: https://github.com/pytorch/pytorch/issues/194103
# title: torch.compile(dynamic=True) fails for scatter out variants with symbolic shapes
# state: open  created: 2026-08-19
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x, index, src, out):
    return torch.scatter(x, 1, index, src, out=out)

compiled = torch.compile(
    f,
    backend="eager",
    fullgraph=True,
    dynamic=True,
)

for width in (2, 3, 5):
    x = torch.zeros(1, width)
    index = torch.arange(width).unsqueeze(0)
    src = torch.ones(1, width)
    out = torch.empty_like(x)

    # Eager succeeds
    f(x, index, src, out)

    # Compiled call fails
    compiled(x, index, src, out)
