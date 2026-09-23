# Verified by hand on torch 2.14.0+cpu. Direct aten call with an int that is a *function argument*
# (so it becomes a SymInt under dynamic=True) for an `int[2]` parameter: eager broadcasts 3 -> [3, 3],
# Dynamo fails schema matching. Passing a list [3, 3], or going through F.max_pool2d, works.
import torch
F = torch.nn.functional
x = torch.randn(2, 2, 6, 6)


def f(x, k=3):
    out, ind = F.max_pool2d_with_indices(x, kernel_size=k, return_indices=True)
    return torch.ops.aten.max_pool2d_with_indices_backward.default(
        torch.ones_like(out), x, k, [], 0, 1, False, ind)


def f_list(x, kw={"kernel_size": [3, 3]}):
    out, ind = F.max_pool2d_with_indices(x, kernel_size=kw["kernel_size"], return_indices=True)
    return torch.ops.aten.max_pool2d_with_indices_backward.default(
        torch.ones_like(out), x, kw["kernel_size"], [], 0, 1, False, ind)


print("eager          :", f(x).shape)
torch._dynamo.reset()
print("dynamic=False  :", torch.compile(f, backend="eager", dynamic=False)(x).shape)
torch._dynamo.reset()
print("list, dynamic  :", torch.compile(f_list, backend="eager", dynamic=True)(x).shape)
torch._dynamo.reset()
print("int, dynamic   :", torch.compile(f, backend="eager", dynamic=True)(x).shape)
# -> TorchRuntimeError: ... aten::max_pool2d_with_indices_backward() Expected a value of type 'List[int]'
#    for argument 'kernel_size' but instead found type 'SymInt'.
