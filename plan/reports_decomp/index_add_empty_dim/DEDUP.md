# Deduplication — index_add into an empty dimension: Inductor kernel asserts, eager returns

Found 2026-09-09 by the decomposition differential (`run.py decomp`, variant `empty_last`), confirmed on
2.14.0+cpu: `index_add(x[5,0], dim=-1, index[5], source[5,5], alpha=-1)` — eager and aot_eager return a
(5, 0) tensor; Inductor's generated C++ kernel fails at run time with `index out of bounds: 0 <= tmp10 < 0`.

Tracker:
- #186532 (PR, merged 2026-08-18, i.e. after the 2.14 branch cut) "Fix index_add decomposition bounds
  checks": the decomposition lowered through index_put and "invalid indices could compile through
  Dynamo/Inductor and fail later in generated backend code instead of producing the user-visible
  RuntimeError". Fixes #108798.
- #184373 (merged 2026-05-19) "Fix index_add decomposition source shape checks".

Decision: **Duplicate / known** — exactly the failure mode #186532 describes; on main the compiled path
now raises a RuntimeError up front. (Eager returning normally for out-of-range indices into an empty
dimension is eager's own missing check, not a compiler defect.) Not filed.
