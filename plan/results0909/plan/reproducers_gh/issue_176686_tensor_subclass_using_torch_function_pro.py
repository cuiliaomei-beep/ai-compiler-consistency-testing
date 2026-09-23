# source: https://github.com/pytorch/pytorch/issues/176686
# title: Tensor subclass using __torch_function__ produce wrong results with torch.compile
# state: closed  created: 2026-03-06
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class ScaledTensor(torch.Tensor):
    """Subclass that scales results via __torch_function__."""
    @staticmethod
    def __new__(cls, data, scale=2.0):
        obj = torch.Tensor._make_subclass(cls, data)
        obj.scale = scale
        return obj

    @classmethod
    def __torch_function__(cls, func, types, args=(), kwargs=None):
        kwargs = kwargs or {}
        raw = super().__torch_function__(func, types, args, kwargs)
        if isinstance(raw, torch.Tensor) and func in (torch.add, torch.mul, torch.sub, torch.div):
            return raw * 2.0  # custom side-effect
        return raw

a = ScaledTensor(torch.tensor([1.0, 2.0]))
b = ScaledTensor(torch.tensor([3.0, 4.0]))

# Eager
eager = torch.mul(a, b)
# Compiled
torch._dynamo.reset()
compiled = torch.compile(torch.mul, backend="eager", fullgraph=False)(a, b)

print(f"eager   : {eager}") # ScaledTensor([ 6., 16.])
print(f"compiled: {compiled}") #  ScaledTensor([12., 32.])
print(f"match   : {torch.allclose(eager, compiled)}")  # False
