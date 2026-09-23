"""Windows CPU, max_autotune: torch.bmm (and batched matmul) always fails - the C++ bmm template kernel is not exported.

Verified on torch 2.14.0+cpu (Windows 11, MSVC):
    torch.compile(torch.bmm)(a, b) with torch._inductor.config.max_autotune=True
    -> InductorError: LoweringException: AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found
torch.mm / addmm / F.linear under the same setting work (their template exports the symbol).
Cause: torch/_inductor/codegen/cpp_bmm_template.py, BMM_TEMPLATE line 44 emits
    extern "C"
    {{kernel.def_kernel(...)}}
without `{{export_declaration}}`, whereas cpp_gemm_template.py (line 190) and cpp_grouped_gemm_template.py
(line 41) emit `extern "C" {{export_declaration}}` where get_export_declaration() is `__declspec(dllexport)` on
Windows. The autotuner then loads the benchmark DLL and `getattr(DLL, kernel_name)` fails
(autotune_process.py CppBenchmarkRequest.make_run_fn, line 1277).
Found by the configuration differential (plan/tcc/metamorphic.py, config set `max_autotune`) on OpInfo bmm/matmul.
"""
import torch
from torch._inductor import config as IC

torch.manual_seed(0)
a, b = torch.randn(4, 8, 8), torch.randn(4, 8, 8)
print(torch.__version__)
for name, fn, args in (("mm", torch.mm, (a[0], b[0])), ("bmm", torch.bmm, (a, b)),
                       ("matmul 3d", torch.matmul, (a, b))):
    torch._dynamo.reset()
    try:
        with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
            out = torch.compile(fn)(*args)
        print(f"{name:<9}: ok, matches eager = {torch.allclose(out, fn(*args), atol=1e-5)}")
    except Exception as e:  # noqa: BLE001
        inner = e
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"{name:<9}: {type(inner).__name__}: {str(inner)[:90]}")
