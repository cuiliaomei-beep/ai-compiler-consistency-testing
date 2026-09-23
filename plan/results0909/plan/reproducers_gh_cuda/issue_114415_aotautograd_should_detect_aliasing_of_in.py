# source: https://github.com/pytorch/pytorch/issues/114415
# title: AOTAutograd should detect aliasing of inputs that happens *below* subclasses
# state: open  created: 2023-11-22
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.utils._pytree as pytree
from torch.utils._python_dispatch import return_and_correct_aliasing

class SubclassTensor(torch.Tensor):
    @staticmethod
    def __new__(cls, a):
        shape = a.shape
        kwargs = {}
        kwargs["strides"] = a.stride()
        kwargs["storage_offset"] = a.storage_offset()
        kwargs["device"] = a.device
        kwargs["layout"] = a.layout
        kwargs["requires_grad"] = a.requires_grad
        kwargs["dtype"] = a.dtype
        out = torch.Tensor._make_wrapper_subclass(cls, shape, **kwargs)
        return out

    __torch_function__ = torch._C._disabled_torch_function_impl

    def __init__(self, a):
        self.a = a

    def __repr__(self):
        a_repr = repr(self.a)
        return f"SubclassTensor({a_repr})"

    def __tensor_flatten__(self):
        return ["a"], None

    @staticmethod
    def __tensor_unflatten__(inner_tensors, meta):
        a = inner_tensors["a"]
        return SubclassTensor(a)

    @classmethod
    def __torch_dispatch__(cls, func, types, args, kwargs):
        if kwargs is None:
            kwargs = {}
        args_a = pytree.tree_map(lambda x: x.a if isinstance(x, SubclassTensor) else x, args)
        kwargs_a = pytree.tree_map(lambda x: x.a if isinstance(x, SubclassTensor) else x, kwargs)
        out_a = func(*args_a, **kwargs_a)
        out = pytree.tree_map(lambda x: SubclassTensor(x) if isinstance(x, torch.Tensor) else x, out_a)
        return return_and_correct_aliasing(func, args, kwargs, out)



@torch.compile
def f(x1, x2):
    x1.mul_(2)
    return x1 + x2


x = torch.ones(2)
subclass1 = SubclassTensor(x)
subclass2 = SubclassTensor(x)

out = f(subclass1, subclass2)
# WRONG
# prints:                 SubclassTensor(tensor([3., 3.]))
# correct answer: SubclassTensor(tensor([4., 4.]))
print(out)
