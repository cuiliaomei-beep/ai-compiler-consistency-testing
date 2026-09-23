# source: https://github.com/pytorch/pytorch/issues/135432
# title: torch.compile cannot handle torch.Tensor correctly
# state: closed  created: 2024-09-08
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile
def foo(x):
    return torch.Tensor(x)

print(foo([1, 2]))
print(foo([3, 4]))
