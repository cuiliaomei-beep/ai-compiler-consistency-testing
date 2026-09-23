> Superseded 2026-09-10 by `plan/issues_0910/01-argmin-pow-dynamic-cpp.md`. Kept for history.

# [inductor][cpu] argmin/argmax with `dynamic=True` emits the index expression with Python `**` into C++ → compile error

## Summary

With dynamic shapes, when two dimensions of equal size are unified into one symbol (`ks1 * ks1 → ks1**2`) and an
arg-reduction (`argmin` / `argmax`) is split by a broadcast operand into outer × inner loops, the CPU C++ backend
prints the reduction's index expression with the *Python* printer:

```cpp
tmp_acc0_vec = argmin_combine_vec<float, 1, 2, true>(tmp_acc0_vec, tmp4, ks1**2*x0 + x1);
```

`**` is not C++ (MSVC: `error C2100: illegal indirection`; GCC/Clang reject it as well), so the kernel fails to
compile → `InductorError: CppCompileError`. Static shapes, `backend="aot_eager"`, dim-wise `argmin(dim=…)`,
`amin`/`amax` (no index), and distinct inner sizes (`(3, 2, 3) + (1, 2, 3)`) all work.

## Environment

- PyTorch 2.14.0+cpu (git 08187d9e0fba026dc8217405802ab5381dc88d90), Python 3.14.7
- Windows 11, Inductor C++ backend (MSVC). The emitted `**` is compiler-independent.

## Minimal reproducer

```python
import torch

x = torch.randn(3, 4, 4)
m = torch.randn(1, 4, 4)        # broadcast over dim 0; the two inner dims have equal size

def f(x, m):
    return (x + m).argmin()

print(f(x, m))                                                  # e.g. tensor(24)
print(torch.compile(f)(x, m))                                   # same (static: fine)
torch._dynamo.reset()
print(torch.compile(f, backend="aot_eager", dynamic=True)(x, m))  # same
torch._dynamo.reset()
print(torch.compile(f, dynamic=True)(x, m))                     # InductorError: CppCompileError: C++ compile error
```

Originally hit through `torch.masked.argmin(x, mask=mask)` with a broadcastable mask; the plain ops above are the
reduced form. `(x + m).argmax()` and `torch.where(m, x, inf).argmin()` fail the same way.

## Expected behavior

Same result as eager / static compile.

## Actual behavior

C++ compilation of the generated kernel fails; the error text (MSVC) is `error C2100` at the
`argmin_combine_vec(...)` line whose last argument is `ks1**2*x0 + x1`.

## Notes

- Cause (`torch/_inductor/codegen/cpp.py`): in `CppVecKernel.reduction_combine_vec` the arg-reduction index is
  interpolated as `f", {self._adjust_argreduce_index(index)}"` (line 3749 in 2.14.0), and in the scalar
  `reduction_combine` as `f"{reduction_type}_combine({var}, {next_value}, {index})"` (line 256) — i.e. `str()`
  of a sympy expression. Every other index in the file goes through `cexpr_index(...)`, which prints `Pow` as C++.
  Products of distinct symbols print identically in both printers, which is why the bug only surfaces when a
  symbol is squared.
- Not #171870 (s390x vector operators) and not #193680 (wrong index *value* for fused arg reductions).
- Found by a configuration differential (the same OpInfo sample compiled under several Inductor configurations and
  `dynamic=True`, results compared against each other).
