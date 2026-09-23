# Verified by hand on torch 2.14.0+cpu (Windows, CPU): eager and dynamic=False agree,
# torch.compile(dynamic=True) raises during Dynamo tracing.
import torch

x = torch.randn(2)
w = torch.tensor([0.2598, 0.3666])


def f(a):
    return torch.cov(a, correction=0, aweights=w)


print("eager        :", f(x))                                            # tensor(...)
torch._dynamo.reset()
print("dynamic=False:", torch.compile(f, backend="eager", dynamic=False)(x))  # same value
torch._dynamo.reset()
print("dynamic=True :", torch.compile(f, backend="eager", dynamic=True)(x))
# -> TorchRuntimeError: ... got RuntimeError('Cannot call numel() on tensor with symbolic sizes/strides')
#    (the cov decomposition reads aweights.numel() while aweights has symbolic shape)
