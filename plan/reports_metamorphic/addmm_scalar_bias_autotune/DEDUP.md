# Deduplication — max_autotune addmm with a 0-d bias: IndexError in tuned_addmm

Found 2026-09-10 by the configuration differential (`run.py metamorphic --relations config --configs max_autotune`)
on OpInfo `addmm` (sample with a scalar `input`); confirmed with `minimal_verified.py` on 2.14.0+cpu:
`LoweringException: IndexError: list index out of range` from `torch/_inductor/kernel/mm.py` `tuned_addmm`
(line 714: `inp.get_stride()[0] == 0 and len(inp.get_size()) == 2 ...` — stride indexed before the rank check).
1-d and 2-d biases work; the default configuration works (the branch is only taken under max_autotune).

Tracker: #185533 / PR #185578 (open) "Fix addmm max-autotune SliceView bias guard" — the same line, different
trigger (unrealised SliceView without concrete strides); its `maybe_get_stride()` guard does not cover an empty
stride tuple. No report for the 0-d bias case.

Decision: **candidate (low)** — best filed as a comment on #185533 / #185578 asking to put the rank check first,
or a tiny follow-up issue. Pending user review.
