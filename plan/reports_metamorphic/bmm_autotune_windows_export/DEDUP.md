# Deduplication — Windows CPU max_autotune: bmm C++ template kernel not exported (`__declspec(dllexport)` missing)

Found 2026-09-10 by the configuration differential (`run.py metamorphic --relations config --configs max_autotune`)
on OpInfo `bmm` / `matmul` (batched); confirmed with `minimal_verified.py` on 2.14.0+cpu, Windows 11 / MSVC:
`torch.compile(torch.bmm)` with `max_autotune=True` → `LoweringException: AttributeError: function
'cpp_CppMicroGemmFP32Vec' not found`; `mm`, `addmm`, `F.linear` fine under the same setting.

Root cause (read from source): `torch/_inductor/codegen/cpp_bmm_template.py` line 44 emits `extern "C"` without
`{{export_declaration}}`; `cpp_gemm_template.py` (line 190) and `cpp_grouped_gemm_template.py` (line 41) emit
`extern "C" {{export_declaration}}` = `__declspec(dllexport)` on Windows (`cpp.py` `get_export_declaration`).
The autotuner's `CppBenchmarkRequest.make_run_fn` (`autotune_process.py` line 1277) does `getattr(DLL, name)`
on the benchmark DLL and cannot find the unexported symbol. Linux/macOS are unaffected (default visibility).

Tracker (search API, 2026-09-10): nothing for "cpp_CppMicroGemmFP32Vec not found", "CppMicroGemm windows bmm
max_autotune", "max_autotune cpu windows inductor" (only unrelated PRs #185578 / #185767).

Decision: **candidate** — Windows-only, one-line fix, deterministic. Pending user review.
