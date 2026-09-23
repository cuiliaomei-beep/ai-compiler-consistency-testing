# Deduplication — std / var / var_mean / std_mean give NaN under Inductor for ~1e30 inputs

Found 2026-09-09 by the decomposition differential (`run.py decomp`, variant `huge`), confirmed with
`torch.compile(backend="inductor")` on 2.14.0+cpu (`minimal_verified.py`). eager and aot_eager agree with
the float64 truth for `std` (9.56e29); Inductor returns NaN for all four ops. Mechanism: Inductor's
variance lowering evaluates E[x²] − E[x]² in float32, x² overflows to inf, inf − inf = NaN; eager's
Welford / two-pass kernel does not overflow.

Tracker:
- #173793 (open, 2026-01-29) "Numerical stability discrepancy in torch.compile: LayerNorm produces NaN for
  large inputs (~1e37) while Eager mode is stable" — same root cause on CUDA LayerNorm.
- #173989 (merged PR, 2026-01-31) "[Inductor] Fix NaN output in LayerNorm CPU by guarding Welford variance" —
  a fix for the LayerNorm CPU path only; plain `var`/`std` reductions are still affected on 2.14.0.

Decision: **new instance of an open issue** (different operator, CPU, lower magnitude 1e30 where eager
is fully finite). Recommended action: comment on #173793 with this reproducer, or file a new issue
referencing it ("torch.std/var return NaN under Inductor for large-magnitude float32 inputs").
Listed in TO_SUBMIT.md for the user's decision.
