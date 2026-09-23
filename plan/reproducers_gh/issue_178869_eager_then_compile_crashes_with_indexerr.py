# source: https://github.com/pytorch/pytorch/issues/178869
# title: eager_then_compile crashes with IndexError when number of dims changes
# state: closed  created: 2026-03-31
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile(dynamic=True)
def f(x):
    return x + 1

with torch.compiler.set_stance("eager_then_compile"):
    f(torch.randn(10))     # Eager phase: tracks 1D tensor
    f(torch.randn(10))     # Eager phase: tracks 1D tensor
    
    # Change the input shape before compilation
    f(torch.randn(10, 10)) # Compilation phase: 2D tensor causes IndexError
