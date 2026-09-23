# source: https://github.com/pytorch/pytorch/issues/193876
# title: [inductor] Compiling two `torch.full -> cumsum` graphs with different fill constants in one process raises InductorError (FakeTensor/Node in pointless_cumsum_replacement)
# state: closed  created: 2026-08-18
# mined automatically; the harness records the torch.compile target and its first call

import torch

def make(fill):
    def fn():
        return torch.full((2,), fill, dtype=torch.int64).cumsum(0).sum()
    return fn

print(torch.compile(make(1))())  # tensor(3), ok
print(torch.compile(make(2))())  # InductorError
