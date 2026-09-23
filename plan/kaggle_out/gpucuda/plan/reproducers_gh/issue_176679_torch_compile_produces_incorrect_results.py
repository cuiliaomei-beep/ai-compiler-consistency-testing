# source: https://github.com/pytorch/pytorch/issues/176679
# title: torch.compile produces incorrect results with Tensor subclass using __torch_function__
# state: closed  created: 2026-03-06
# mined automatically; the harness records the torch.compile target and its first call

import torch

class ScaledTensor(torch.Tensor):
    @staticmethod
    def __new__(cls, data):
        return torch.Tensor._make_subclass(cls, data)

    @classmethod
    def __torch_function__(cls, func, types, args=(), kwargs=None):
        kwargs = kwargs or {}
        raw = super().__torch_function__(func, types, args, kwargs)
        # Only scale the output of torch.add — a single, deliberate side-effect.
        if isinstance(raw, torch.Tensor) and func is torch.add:
            return raw * 2.0   # <-- internally becomes torch.mul under compile,
                               #     which re-triggers __torch_function__ a second time
        return raw

a = ScaledTensor(torch.tensor([1.0, 2.0]))
b = ScaledTensor(torch.tensor([3.0, 4.0]))

# Eager
eager = torch.add(a, b)
# Compiled
torch._dynamo.reset()
compiled = torch.compile(torch.add, backend="eager", fullgraph=False)(a, b)

print(f"eager   : {eager}")    # [8., 12.]
print(f"compiled: {compiled}") # [16., 24.]
print(f"match   : {torch.allclose(eager, compiled)}")  # False
