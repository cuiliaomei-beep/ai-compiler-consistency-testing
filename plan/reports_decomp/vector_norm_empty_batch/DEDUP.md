# Deduplication — vector_norm(ord=inf / -inf / negative, dim=-1) on an empty batch fails under torch.compile

Found 2026-09-09 by the decomposition/meta differential (`run.py decomp`, variant `empty_dim0`), confirmed with
`minimal_verified.py` on 2.14.0+cpu: `torch.linalg.vector_norm(torch.empty(0, 5), ord=inf, dim=-1)` returns
`tensor([])` in eager; every torch.compile backend (eager / aot_eager / inductor) fails at Dynamo's fake-tensor
tracing with "cannot compute the inf norm on the dimension -1 because this dimension is empty".

Root cause (corrected 2026-09-10 from the actual traceback): `_check_vector_norm_args` in
`torch/_refs/linalg/__init__.py` lines 119–126 checks `sym_or(x.numel() != 0, d < len(shape) and d >= 0 and
shape[d] != 0)` with the **raw** dim value; for `d = -1` the predicate is false, and with an empty batch
`numel() == 0`, so the check fails. `dim=1` / `dim=(1,)` compile fine; `dim=-1` / `dim=(-1,)` fail. Eager's C++
check canonicalizes the dim. (The earlier note "integer dim never looks at shape[dim]" was wrong: the integer is
wrapped into a list and reaches the same loop.)

Tracker (search API, 2026-09-09 and 2026-09-10, 5 queries): no report. #148809 (merged 2025-04) inlined the
size-oblivious guards of the same check but kept the un-normalized index; #194326 (open) is numeric overflow,
unrelated.

Decision: **candidate, not a duplicate as far as the search shows.** Draft: `plan/issues_0910/04-vector-norm-empty-batch.md`.
