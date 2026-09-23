> Superseded 2026-09-10 by `plan/issues_0910/05-std-var-fp32-accumulation-zero-grad.md` (numbers re-measured: `var`
> overflows in eager too, only `std`/`std_mean` disagree at 1e30). Kept for history.

# [inductor][cpu] `torch.std` / `var` accumulate in float32: NaN for 1e30-scale inputs, zero output **and zero gradient** for 1e-30-scale inputs (eager is correct)

## Summary

On CPU, eager `torch.std` / `torch.var` / `var_mean` / `std_mean` accumulate float32 inputs in double, so they are
correct over the whole float32 range. Under `torch.compile(backend="inductor")` the variance is accumulated in
float32:

- inputs of magnitude ~1e30 → **inf or NaN** depending on the values (eager: 1.02e30, equal to the float64
  truth; `var_mean` / `std_mean` additionally return a wrong finite mean component);
- inputs of magnitude ~1e-30 → `std` returns **0** (eager: 1.44e-30) and, more importantly, the **gradient is
  all zeros** while eager and float64 give the correct O(1) gradient `(x - mean) / ((N-1)·std)`. A model whose
  activations are tiny therefore trains in eager and silently stops learning under compile.

`backend="aot_eager"` matches eager in both cases; the deviation enters at Inductor.

## Environment

- PyTorch 2.14.0+cpu (git 08187d9e0fba026dc8217405802ab5381dc88d90), Python 3.14.7
- Windows 11, CPU only, Inductor C++ backend (MSVC)

## Minimal reproducer

```python
import torch

torch.manual_seed(0)

# 1. large values -> inf / nan
x = torch.randn(4, 8) * 1e30
print("eager   :", torch.std(x))                              # tensor(1.0223e+30)  (float64: 1.0223e+30)
torch._dynamo.reset()
print("inductor:", torch.compile(torch.std)(x))               # tensor(inf)   (nan for other inputs, e.g. 5 values ~1e30)

# 2. small values -> zero output and zero gradient
def grads(fn, x):
    xx = x.clone().requires_grad_(True)
    y = fn(xx)
    (g,) = torch.autograd.grad(y, xx)
    return y.item(), g

x = torch.randn(5) * 1e-30
print("eager   :", grads(torch.std, x))            # (8.19e-31, tensor([-0.0371,  0.2498, -0.1366, -0.3250,  0.2489]))
print("fp64    :", grads(torch.std, x.double()))   # same values
torch._dynamo.reset()
print("inductor:", grads(torch.compile(torch.std), x))   # (0.0, tensor([-0., 0., -0., -0., 0.]))
```

## Expected behavior

Finite `std` for 1e30 inputs; non-zero `std` and the correct gradient for 1e-30 inputs — as eager and float64
give. If float32 accumulation is intended, the CPU eager kernel and Inductor should at least agree.

## Actual behavior

NaN (large) / zero output and zero gradient (small) under Inductor only.

## Notes

- Related: #173793 (open) reports the same overflow for `LayerNorm` on CUDA with 1e37 inputs; #173989 fixed the
  LayerNorm CPU path only. `std`/`var` themselves, and the gradient consequence, are not covered there.
- Found by a decomposition/kernel differential with extreme-magnitude input variants, forward and backward.
