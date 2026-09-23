"""The small-value twin of the 1e30 case: torch.std on 1e-30-scale float32 inputs under torch.compile
returns 0 and an all-zero gradient; eager (CPU, double accumulation) and float64 give 1.44e-30 and O(1) grads.

Verified on torch 2.14.0+cpu:
    eager     out=1.439e-30  grad=[0.3179, -0.0006888, -0.3281, 0.149, -0.1381]
    fp64      out=1.439e-30  grad=[0.3179, -0.0006888, -0.3281, 0.149, -0.1381]
    compiled  out=0          grad=[0, -0, -0, 0, -0]
Same for correction=0 and dim-wise std. Found by the gradient decomposition differential
(plan/tcc/decomp_diff.py --grad, variant `tiny`); the forward-only sweep could not see it because the
absolute error |0 - 1.4e-30| is below any tolerance, while the gradient error is 0.33 on O(1) values.
Root cause shared with the 1e30 -> NaN case (minimal_verified.py): Inductor accumulates the variance in
float32 (sum of squared deviations ~1e-60 underflows to 0), CPU eager accumulates in double.
"""
import torch

torch.manual_seed(0)
x = torch.randn(5) * 1e-30


def grads(fn, x):
    xx = x.clone().requires_grad_(True)
    y = fn(xx)
    g, = torch.autograd.grad(y, xx)
    return y.item(), g


print(torch.__version__)
print("eager   :", grads(torch.std, x))
print("fp64    :", grads(torch.std, x.double()))
torch._dynamo.reset()
print("compiled:", grads(torch.compile(torch.std), x))
