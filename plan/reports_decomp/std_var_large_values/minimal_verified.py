# Verified on torch 2.14.0+cpu (Inductor C++ backend). Found by the decomposition/kernel
# differential (NEXT_DIRECTIONS 5.1), confirmed with torch.compile.
#
# torch.std / var / var_mean / std_mean on float32 values of magnitude ~1e30:
#   eager      std = 9.5635e+29 (finite, equals the float64 truth), var = inf
#   aot_eager  same as eager
#   inductor   NaN for all four  (variance computed as E[x^2] - E[x]^2 -> inf - inf)
import torch

torch.manual_seed(0)
x = torch.randn(5, 5) * 1e30

for name, f in (("std", lambda a: torch.std(a)), ("var", lambda a: torch.var(a)),
                ("std_mean", lambda a: torch.std_mean(a)), ("var_mean", lambda a: torch.var_mean(a))):
    eager = f(x)
    torch._dynamo.reset()
    comp = torch.compile(f, backend="inductor")(x)
    print(f"{name:<9} eager={eager}  inductor={comp}")
print("float64 truth std:", torch.std(x.double()))
# expected: inductor should give the finite std (9.5635e+29); it gives nan
