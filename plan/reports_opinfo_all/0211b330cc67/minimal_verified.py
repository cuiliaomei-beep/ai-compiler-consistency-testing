# Verified by hand on torch 2.14.0+cpu (Windows, Inductor C++ backend via MSVC).
# torch.var_mean on an EMPTY tensor: eager returns (nan, nan); Inductor returns (nan, 0.).
# The mean component is wrong (0 instead of nan). backend="eager" and "aot_eager" agree with
# eager, so the deviation enters at Inductor lowering/codegen. dynamic=True reproduces too.
# torch.mean / torch.var / torch.std on the same input are correct under Inductor; only the
# fused var_mean is affected. A (3, 0) input with dim=1 is also correct.
import torch
import warnings

warnings.filterwarnings("ignore")  # "degrees of freedom is <= 0" is expected here

x = torch.randn(0)


def f(a):
    return torch.var_mean(a)


print("eager    :", f(x))                                               # (tensor(nan), tensor(nan))
torch._dynamo.reset()
print("aot_eager:", torch.compile(f, backend="aot_eager")(x))          # (tensor(nan), tensor(nan))
torch._dynamo.reset()
print("inductor :", torch.compile(f, backend="inductor")(x))           # (tensor(nan), tensor(0.))  <-- mean differs
torch._dynamo.reset()
print("mean only:", torch.compile(lambda a: a.mean(), backend="inductor")(x))   # tensor(nan)  (correct)
