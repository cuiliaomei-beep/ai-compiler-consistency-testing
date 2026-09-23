# Deduplication (plan 18.5) — 2026-09-08

Finding: `torch.cov(x, correction=0, aweights=w)` raises
`Cannot call numel() on tensor with symbolic sizes/strides` under `torch.compile(dynamic=True)`;
eager and `dynamic=False` agree. Verified by hand on torch 2.14.0+cpu (`minimal_verified.py`).

Existing work found:

- **pytorch/pytorch PR #190669** "[decomp][bugfix] Add aten.cov decomposition for compilation"
  (opened 2026-07-21, state open, not merged, base main). Describes the same root cause:
  the C++ composite for `aten::cov` runs under FakeTensorMode, and its weight validation calls
  `.numel()` on symbolically-shaped `fweights`/`aweights`; without weights the dof check causes a
  graph break. Adds a Python `CompositeImplicitAutograd` decomposition; reports 305/360 enumerated
  cases compiling (previously 0/360).
- Same error class on other operators (tracked separately, informative for the paper's
  "specialization / symbolic-shape" category): #122171 one_hot, #122774 matmul out=, #122773 gather
  out=, #165210 _convolution meta, #179383 quantile/nanquantile, #186112/#182233 combinations,
  #186028/#187614 linalg.cond, #194103/#194611 scatter out=.

Decision: **Duplicate** — do not file. The reproducer is still valid on 2.14.0 and can be posted as a
confirming comment on #190669 if the PR stalls.

Search performed via the GitHub search API (queries: `cov numel symbolic`, `"torch.cov" compile`,
`"Cannot call numel() on tensor with symbolic sizes"`, `cov aweights`), 2026-09-08.
