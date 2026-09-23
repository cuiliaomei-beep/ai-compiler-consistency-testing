# Deduplication (plan 18.5) — 2026-09-08

Finding: `torch.nn.functional.multi_margin_loss` on float16 CPU inputs. Eager raises
`NotImplementedError: "multi_margin_loss_cpu_kernel" not implemented for 'Half'`; `backend="eager"`
raises the same; `aot_eager` and `inductor` **return normally** because the decomposition
(#104578, 2023) is expressed in primitives that do support Half. Stage: AOTAutograd / decomposition
(E1 agrees with eager, E2 differs). Reproduced 2/2.

Tracker:

- #144362 (open, 2025-01) "Some operators miss dtype check when using `torch.compile`" — the same
  class: compiled decompositions accept inputs that eager kernels reject.
- #193811 (open, 2026-08) "torch.compile silently accepts int32 input to upsample_bilinear2d that eager
  correctly rejects" — same class, different operator.
- #104578 / #104846 (closed PRs, 2023-07) added the `multi_margin_loss` decomposition used by compile.

Decision: **Duplicate / instance of #144362**. Recorded as a data point (operator + dtype) rather than filed;
worth adding to #144362 as a comment if the maintainers collect instances.
