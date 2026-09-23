# source: https://github.com/pytorch/pytorch/issues/178964
# title: [inductor] `max` returns incorrect indices when compiling a function includes `(a + b).max(dim=1)`
# state: closed  created: 2026-04-01
# mined automatically; the harness records the torch.compile target and its first call

import torch
def fn(a, b):
    return (a + b).max(dim=1)

torch.manual_seed(0)
a = torch.randn(8, 8).transpose(0, 1)  # the shape should be (8, 8) to trigger the error
b = torch.randn(8, 8)

res1 = fn(a, b)
print(res1.indices)  # tensor([5, 5, 6, 7, 0, 3, 7, 2])
res2 = torch.compile(fn, backend='inductor')(a, b)
print(res2.indices)  # tensor([0, 0, 0, 0, 0, 0, 0, 0])
torch.testing.assert_close(res1, res2, equal_nan=True)  # assertion error
