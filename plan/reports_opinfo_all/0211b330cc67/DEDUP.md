# Deduplication (plan 18.5) — 2026-09-08

Finding: `torch.var_mean(torch.randn(0))` returns `(nan, 0.)` under `torch.compile(backend="inductor")`
while eager, `backend="eager"` and `backend="aot_eager"` return `(nan, nan)`. The **mean** component is
wrong. `mean()`, `var()`, `std()` alone are correct under Inductor; a `(3, 0)` input reduced over dim 1 is
correct; `dynamic=True` reproduces. Verified by hand (`minimal_verified.py`), torch 2.14.0+cpu.

Round 6 (3 OpInfo samples per op) confirmed the same defect for `std_mean`, for `unbiased=False`, for shape
`(0, 1)` and for float16 (hand-verified 2026-09-08); an empty-dimension reduction with `dim=` is correct.

Same defect seen by the pipeline under four contexts of the same program (base, dtype, requires_grad,
compile flag): signatures `0211b330cc67` (this one), `3c313d55c8e2`, `282f0b8cd0fa`, `3b6a5083ff89` —
clustered locally as one failure.

Tracker search (GitHub search API, queries: `var_mean inductor wrong result`, `var_mean torch.compile
incorrect`, `var empty tensor inductor nan 0`, `var_mean empty`, `degrees of freedom torch.compile nan 0`, ...):

- #113167 "Different behaviors on `torch.var_mean` with torch.compile(default mode)" — **closed 2023-11-13**
  (module: inductor). Scalar input with an invalid `correction=4.9`, eager NaN vs compiled other value.
  Related (same family: var_mean with dof <= 0 under Inductor) but not the same case: ours is a
  zero-element input with default correction, the *mean* component, and it reproduces on 2.14.0 —
  i.e. either a regression or an uncovered path of that fix.
- #145401 "torch.compile has different numerics for var_mean" — open, about float16 precision on a large
  CUDA tensor; not this.
- #61901 "Reducing over empty dimensions for reductions without identity" — eager semantics discussion
  (2021); establishes that eager's NaN is the intended answer.
- #191229 (open PR) "Return NaN from median over empty dimensions" — maintainers currently treat "NaN over
  empty dimension" as the required behaviour for reductions without identity.

Decision: **not a duplicate**. Ready for human review and submission (`ISSUE_FINAL.md`); reference
#113167 and #61901 in the report.
