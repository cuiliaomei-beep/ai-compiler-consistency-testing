# Deduplication — backward of F.pdist on an input with zero rows crashes the process (eager)

Found 2026-09-10 by the gradient decomposition differential (`run.py decomp --grad`, variant `empty_dim0`): the
child interpreter died with exit code 0xC0000094 (integer division by zero). `minimal_verified.py` runs each case
in a subprocess on 2.14.0+cpu: forward `F.pdist(torch.empty(0, d, requires_grad=True))` returns shape `(0,)`,
`.sum().backward()` kills the interpreter for `(0, 1)` and `(0, 4)`; `(1, 4)` (one row, zero pairs) and `(2, 4)`
are fine. So `pdist_backward` divides by the number of rows without guarding `n == 0`.

Tracker (search API, 2026-09-10): nothing for "pdist backward empty crash", "pdist zero rows segfault",
"pdist_backward division by zero", "pdist empty tensor".

Linux confirmation 2026-09-10 (Kaggle CPU notebook, torch 2.10.0+cpu, Python 3.12.13, Linux 6.12 / glibc 2.35,
`kaggle/verify/pdist_crash_linux.py`): `(0, 1)` and `(0, 4)` killed by SIGSEGV, `(1, 4)` / `(2, 4)` fine — same
failure point, different signal than Windows.

Decision: **eager-side candidate, high value (hard crash, no Python exception, two platforms / two versions)** — not a compile issue
(the compiled path dies the same way since it calls the same kernel). Pending user review; would be filed as
`module: autograd` / `module: crash`.
