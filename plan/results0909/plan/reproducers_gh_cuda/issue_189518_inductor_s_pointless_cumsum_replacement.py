# source: https://github.com/pytorch/pytorch/issues/189518
# title: Inductor's pointless_cumsum_replacement drops cumsum's explicit dtype argument
# state: closed  created: 2026-07-10
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f():
    ones = torch.ones((2, 4, 4), dtype=torch.bool)
    return ones.cumsum(1, dtype=torch.bfloat16)

eager = f()
compiled = torch.compile(f)()
print(eager.dtype)     # torch.bfloat16
print(compiled.dtype)  # torch.int64  <- wrong
