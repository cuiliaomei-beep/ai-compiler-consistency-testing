# Deduplication (plan 18.5) — 2026-09-08

Finding: the OpInfo helper `max_pool2d_backward` (torch/testing/_internal/common_methods_invocations.py)
calls `aten.max_pool2d_with_indices_backward.default(grad, x, kernel_size, ...)` with `kernel_size=3`
(an int). Under `torch.compile(dynamic=True)` the int, which reaches the call as a function argument,
is a SymInt, and the schema `int[2] kernel_size` rejects a SymInt scalar (eager broadcasts 3 -> [3, 3]).
`dynamic=False`, a list `[3, 3]`, or the Python-level `F.max_pool2d` all work. Verified
(`minimal_verified.py`). Isolated from the OpInfo program in three steps: literal kwargs OK, global dict
OK, ints reachable from function arguments FAIL.

Tracker:

- #122129 (open, 2024-03) "Obscure error: Expected a value of type 'List[int]' for argument 'sizes' but
  instead found type SymInt" — same limitation (SymInt scalar where an int list is declared) on a different
  argument.
- #125638 (closed 2024-05) same error text for `stride` with nn-module inlining; fixed for that path.
- #186897 (closed PR, 2026-06) "Warn when custom op int schema specializes SymInts" — related handling of
  SymInt vs int schemas.

Decision: **Duplicate / related to #122129** — the error class is known and open; the trigger is a direct
aten call from test infrastructure, not user-facing API. Not filed; recorded as a data point.
