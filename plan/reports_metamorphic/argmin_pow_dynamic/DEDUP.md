# Deduplication — CPU Inductor, dynamic=True: argmin/argmax index expression printed with Python `**` -> C++ compile error

Found 2026-09-10 by the metamorphic config differential (`run.py metamorphic`, relation `config`, variant
`dynamic`) on OpInfo `masked.argmin`; reduced to plain ops in `minimal_verified.py` (2.14.0+cpu, MSVC):

```python
x, m = torch.randn(3, 4, 4), torch.randn(1, 4, 4)
torch.compile(lambda x, m: (x + m).argmin(), dynamic=True)(x, m)   # InductorError: CppCompileError
```
Generated kernel: `argmin_combine_vec<float, 1, 2, true>(tmp_acc0_vec, tmp4, ks1**2*x0 + x1)`. `**` is not
C++ (MSVC C2100 "illegal indirection"; any compiler rejects it). Static shapes, aot_eager, dim-wise argmin,
amin/amax (no index), and distinct inner sizes ((3,2,3)+(1,2,3)) are fine.

Root cause (read from source): `torch/_inductor/codegen/cpp.py`
- `CppVecKernel.reduction_combine_vec`, line 3749: `arg_extra = f", {self._adjust_argreduce_index(index)}"` —
  the sympy index is formatted with `str()` (Python printer) instead of `cexpr_index(...)`;
- scalar `reduction_combine`, line 256: `f"{reduction_type}_combine({var}, {next_value}, {index})"` — same.
Every other place in the file goes through `cexpr_index`. The bug is only visible when the index contains a
`Pow`, i.e. when dynamic shapes unify two equal-sized dims into one symbol (duck sizing: `ks1*ks1 -> ks1**2`)
and the reduction is split by a broadcast operand into outer × inner loops. Products of distinct symbols print
identically in Python and C++, which is why it stayed hidden.

Tracker (search API + reads, 2026-09-10):
- #171870 (open) s390x argmax/argmin C++ failure — missing vector comparison operators on ZVECTOR; different.
- #193680 (open PR) "Preserve logical indices for fused arg reductions" — wrong index *value* when fused with
  another reduction (#193661); touches the same code path but not the printer; would not fix this.
- #186373 (draft, not merged) "Disable duck sizing by default" — would make the trigger rarer (equal dims stay
  separate symbols) but `x.view(n, n)`-style square shapes still produce a Pow.
- #178244 (closed) CPU C++ codegen failure with SDPA closures — undeclared variable, different.
- No hit for "argmin dynamic C++ compile error", "ks**2 inductor", "Pow cpp printer".

Decision: **candidate, not a duplicate as far as the search shows.** Two-line fix (`cexpr_index(index)` at both
sites). Pending user review.
