> Superseded 2026-09-10 by `plan/issues_0910/03-interpolate-zero-size-oob.md`. Kept for history.

# [inductor] `F.interpolate` on a zero-size spatial dim returns uninitialised (NaN) data instead of raising; output size 0 accepted silently

## Summary

Eager `torch.nn.functional.interpolate` validates the spatial sizes and raises
`RuntimeError: Input and output sizes should be greater than 0`. Under `torch.compile` the check never runs:
`backend="aot_eager"` raises an `IndexError` from the decomposition's gather, and `backend="inductor"` **returns a
tensor of the requested shape filled with NaN** — the generated kernel reads past a 0-element buffer (no bounds
check is emitted for that load). On CUDA an unchecked load of this kind is an illegal memory access. The reverse
case (input size 1, `scale_factor=0.6` → output size 0) is also accepted silently by compile.

Reproduces for `mode="nearest"` and `"linear"` (1-D) and `"bilinear"` (2-D with `H=0`).

## Environment

- PyTorch 2.14.0+cpu (git 08187d9e0fba026dc8217405802ab5381dc88d90), Python 3.14.7
- Windows 11, CPU only, Inductor C++ backend (MSVC)

## Minimal reproducer

```python
import torch
import torch.nn.functional as F

x = torch.empty(2, 3, 0)          # empty spatial dim

def f(x):
    return F.interpolate(x, size=3, mode="nearest")

print("eager    :", end=" ")
try:
    f(x)
except RuntimeError as e:
    print("RuntimeError:", e)      # Input and output sizes should be greater than 0, but got input (W: 0) and output (W: 3)

torch._dynamo.reset()
try:
    torch.compile(f, backend="aot_eager")(x)
except Exception as e:
    print("aot_eager: IndexError: index is out of bounds for dimension with size 0")

torch._dynamo.reset()
out = torch.compile(f, backend="inductor")(x)
print("inductor :", out.shape, torch.isnan(out).sum().item(), "NaNs")   # torch.Size([2, 3, 3]) 18 NaNs

# reverse case: output size 0
y = torch.randn(2, 3, 1)
g = lambda y: F.interpolate(y, scale_factor=0.6, mode="nearest", recompute_scale_factor=False)
# eager: RuntimeError (output (W: 0));  torch.compile(g)(y): tensor of shape (2, 3, 0), no error
```

## Expected behavior

The same `RuntimeError` as eager (or at least an error), never a tensor of garbage.

## Actual behavior

`inductor` returns `(2, 3, 3)` filled with NaN (uninitialised memory read out of bounds); `aot_eager` raises an
unrelated `IndexError`.

## Notes

- Cause: the eager check lives in the C++ kernels and in `upsample_common_check` of the meta registration, but
  `upsample_nearest1d.vec` / `upsample_linear1d.vec` (and the 2-D variants) are decomposed by their
  `CompositeImplicitAutograd` `py_impl` in `torch/_decomp/decompositions.py` before any meta check runs, and the
  decomposition validates nothing.
- Same family as the missing-validation reports for other ops (e.g. #195550 for `adaptive_avg_pool2d`), but this
  instance produces uninitialised output rather than a late error.
- Found by a decomposition-vs-kernel differential (each OpInfo sample run once eagerly and once with every aten op
  replaced by its Inductor decomposition), confirmed with `torch.compile`.
