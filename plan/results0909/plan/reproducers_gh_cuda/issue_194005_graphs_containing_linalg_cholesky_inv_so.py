# source: https://github.com/pytorch/pytorch/issues/194005
# title: Graphs containing `linalg.cholesky` / `inv` / `solve` / `lu_factor` are never cached
# state: open  created: 2026-08-18
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._dynamo.utils import counters

def f(x):
    return torch.linalg.cholesky(x)

for _ in range(2):
    torch._dynamo.reset()
    torch.compile(f)(torch.eye(4))

print(dict(counters["inductor"]))
print(dict(counters["aot_autograd"]))
