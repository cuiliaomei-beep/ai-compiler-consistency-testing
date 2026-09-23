# Deduplication — interpolate on a zero-size spatial dim: eager raises, Inductor returns garbage (OOB read)

Found 2026-09-09 by the decomposition/meta differential (`run.py decomp`, variants `empty_last` and
`size1_last`), confirmed with `minimal_verified.py` on 2.14.0+cpu:
`F.interpolate(torch.empty(2, 3, 0), size=3, mode="nearest")` — eager `RuntimeError: Input and output sizes
should be greater than 0`; aot_eager `IndexError` from the decomposition's gather; **inductor returns (2, 3, 3)
filled with NaN**, i.e. the generated C++ kernel reads past a 0-element buffer. Same for `linear` and 2-D
`bilinear` with an empty H. On CUDA an unchecked load of this kind is an illegal memory access. The reverse case
(output size 0 from `scale_factor=0.6` on W=1) is also accepted silently by compile.

Tracker (search API, 2026-09-09):
- #184848 (closed) "Fix nearest upsample scale shortcuts in compile" — scale handling, not size validation.
- #191850 (open) "[CUDA] illegal memory read on upsample_bilinear2d_out_frame" — eager CUDA kernel, unrelated.
- #195550 (open) "Use TORCH_CHECK_VALUE for adaptive_avg_pool2d input validation" — the same *family* (input
  validation missing on the compile path) for a different op.
- Nothing found for "interpolate empty tensor inductor" / "upsample empty input compile out of bounds".

Decision: **candidate** — belongs to the "compile silently accepts invalid input" family (#144362-style), but this
instance produces uninitialised output via an out-of-bounds read rather than merely skipping a check, so it is
worth its own report. Pending user review.
