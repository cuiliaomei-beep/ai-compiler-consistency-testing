# source: https://github.com/pytorch/pytorch/issues/182317
# title: Dynamo leaks TorchFunctionMode onto stack across graph breaks
# state: closed  created: 2026-05-04
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.overrides import TorchFunctionMode

@torch.compile(backend="eager")
def repro():
    class A(TorchFunctionMode):
        def __torch_function__(self, *args, **kwargs):
            return -1

    with A():
        torch.tensor([1])

repro()
print(torch._C._len_torch_function_stack())  # prints 1, should be 0
