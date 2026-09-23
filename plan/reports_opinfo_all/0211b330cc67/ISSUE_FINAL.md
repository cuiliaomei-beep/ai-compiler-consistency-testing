# [inductor] `torch.var_mean` / `torch.std_mean` on an empty tensor return mean `0.` instead of `nan` under `torch.compile`

## Summary

For a zero-element input, eager `torch.var_mean` / `torch.std_mean` return `(nan, nan)` (with the usual "degrees of
freedom is <= 0" warning). Under `torch.compile(backend="inductor")` the result is `(nan, 0.)`: the **mean**
component is `0.` instead of `nan`. `backend="eager"` and `backend="aot_eager"` match eager, so the deviation enters
at Inductor lowering/codegen. `torch.mean`, `torch.var` and `torch.std` on the same input are correct under Inductor;
only the fused `var_mean` / `std_mean` are affected.

Reproduces for: `var_mean` and `std_mean`; `correction=1` (default) and `correction=0` / `unbiased=False`; float32
and float16; shapes `(0,)` and `(0, 1)`; `dynamic=True` and `False`. Reducing an empty dimension with `dim=` on a
`(0, 3)` input gives `nan` correctly in both — only the full reduction to a scalar is affected.

## Environment

- PyTorch 2.14.0+cpu (git 08187d9e0fba026dc8217405802ab5381dc88d90), Python 3.14.7
- Windows 11, CPU only, Inductor C++ backend (MSVC)
- Also reproduces with `dynamic=True`

## Minimal reproducer

```python
import torch

x = torch.randn(0)

def f(a):
    return torch.var_mean(a)

print("eager    :", f(x))                                        # (tensor(nan), tensor(nan))
torch._dynamo.reset()
print("aot_eager:", torch.compile(f, backend="aot_eager")(x))   # (tensor(nan), tensor(nan))
torch._dynamo.reset()
print("inductor :", torch.compile(f, backend="inductor")(x))    # (tensor(nan), tensor(0.))   <-- mean differs
torch._dynamo.reset()
print("mean only:", torch.compile(lambda a: a.mean(), backend="inductor")(x))   # tensor(nan)  (correct)
torch._dynamo.reset()
print("std_mean :", torch.compile(lambda a: torch.std_mean(a), backend="inductor")(x))   # (tensor(nan), tensor(0.))
```

## Expected behavior

`(tensor(nan), tensor(nan))` — the mean of zero elements has no value (same as eager and as `torch.mean` under
Inductor).

## Actual behavior

`(tensor(nan), tensor(0.))`

## Notes

- Not the case of #113167 (scalar input with an invalid `correction`; closed 2023-11): here the input has zero
  elements, `correction` is the default, and the wrong component is the mean.
- Eager's NaN over an empty dimension is the intended semantics for reductions without an identity (#61901; see
  also #191229 for `median`).
- Found by a differential harness that compares eager / `backend="eager"` / `aot_eager` / `inductor` and flags a
  result only when it disagrees with a float64 reference; reproduced 2/2 with a fixed seed, and under four
  independent contexts (fp32 / fp16 / requires_grad / dynamic=True).
