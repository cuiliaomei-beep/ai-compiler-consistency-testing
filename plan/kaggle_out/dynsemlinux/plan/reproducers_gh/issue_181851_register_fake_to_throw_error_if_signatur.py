# source: https://github.com/pytorch/pytorch/issues/181851
# title: register_fake to throw error if signature doesn't match op's schema
# state: open  created: 2026-04-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.library import custom_op

# Define a custom op with a real kernel that takes (Tensor, int) -> Tensor
@custom_op("mylib::foo", mutates_args=())
def foo(x: torch.Tensor, n: int) -> torch.Tensor:
    return x.clone().repeat(n)

# Register a fake kernel with a DIFFERENT signature (missing the int arg)
@foo.register_fake
def foo_fake(x: torch.Tensor) -> torch.Tensor:
    return x.clone()

result = foo(torch.randn(3), 2)

@torch.compile(fullgraph=True)
def compiled_fn(x):
    return foo(x, 2)

result2 = compiled_fn(torch.randn(3))
