# Deduplication — binary_cross_entropy with a float32 weight on bf16/fp16 inputs returns float32 under Inductor

Found 2026-09-09 by the decomposition/meta differential (`run.py decomp`, variants `dtype_bfloat16` /
`dtype_float16`), confirmed with `minimal_verified.py` on 2.14.0+cpu: eager and aot_eager return bfloat16,
inductor returns float32 (values agree within bf16 rounding). Trigger: `weight` is float32 while input/target are
bf16/fp16 — the decomposition multiplies `loss * weight` and promotes; eager keeps the input dtype.

Tracker (search API + issue read, 2026-09-09):
- #171282 (closed 2026-03-19) "[Inconsistency][Inductor] binary_cross_entropy_with_logits returns different
  dtypes between Eager and Inductor" — identical symptom for the **with_logits** variant (bf16 inputs, fp32
  weight, CUDA). On 2.14 with_logits is consistent, so the fix did not reach plain `binary_cross_entropy`.
- #76670 (closed, 2022) added the binary_cross_entropy decomposition.

Decision: **candidate — same class as the fixed #171282, different op.** Low severity (a dtype, values right),
but a one-line report with a clear pointer to the sibling fix. Pending user review. Secondary observation for the
same op: a float32 *target* is rejected by eager and accepted by inductor (missing-check family, #144362).
