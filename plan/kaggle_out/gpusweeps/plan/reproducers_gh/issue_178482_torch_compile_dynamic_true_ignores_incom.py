# source: https://github.com/pytorch/pytorch/issues/178482
# title: torch.compile(dynamic=True) ignores incompatible `out` tensor for `torch.empty` and returns wrong shape
# state: open  created: 2026-03-26
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(size, out):
    return torch.empty(size, out=out, dtype=torch.float32)

size = [2, 3]
out = torch.empty([1])

# Eager: expected to fail
try:
    print(f(size, out))
except Exception as e:
    print('eager error:', e)

# Compiled: unexpectedly succeeds
cf = torch.compile(f, dynamic=True)
print('compiled result shape:', cf(size, out).shape)
