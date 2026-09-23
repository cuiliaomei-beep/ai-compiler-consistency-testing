<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 02: Windows + max_autotune 下 bmm 模板内核未导出

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`），Windows 11 / MSVC 19.44 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20bmm%20max_autotune%20windows · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20cpp_CppMicroGemm%20not%20found · 2026-09-10 五组关键词均无同报告 |
| 证据包 | `plan/reports_metamorphic/bmm_autotune_windows_export/`，`plan/scripts/diag_autotune.py`、`diag_autotune_tb.py`、`diag_autotune2.py` |
| 建议标签 | oncall: pt2, module: inductor, module: cpu inductor, module: windows |

---

## Title

[inductor][cpu][windows] `max_autotune`: bmm C++ template kernel is not exported (`extern "C"` without `__declspec(dllexport)`) → `AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found`

## Body

### 🐛 Describe the bug

On Windows, any `torch.bmm` (and therefore batched `matmul`, `linalg.matrix_power` with n ≥ 2, ...) compiled with `max_autotune=True` fails during autotuning: the C++ bmm template is compiled into a benchmark DLL, but its kernel symbol is not exported, so `getattr(DLL, kernel_name)` in `CppBenchmarkRequest.make_run_fn` raises `AttributeError`, which surfaces as `LoweringException`. `torch.mm`, `torch.addmm` and `F.linear` work under the same setting.

```python
import torch
from torch._inductor import config as IC

a, b = torch.randn(4, 8, 8), torch.randn(4, 8, 8)
for name, fn, args in (("mm", torch.mm, (a[0], b[0])), ("bmm", torch.bmm, (a, b)), ("matmul 3d", torch.matmul, (a, b))):
    torch._dynamo.reset()
    try:
        with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
            out = torch.compile(fn)(*args)
        print(name, "ok", torch.allclose(out, fn(*args), atol=1e-5))
    except Exception as e:
        print(name, type(e).__name__, str(e)[:120])
```

Output on 2.14.0+cpu / Windows:

```
mm        ok True
bmm       InductorError: LoweringException: AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found
matmul 3d InductorError: LoweringException: AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found
```

Also fails: `torch.bmm` on an empty batch `(0, 2, 2)`, `torch.linalg.matrix_power(x, 2)` for a `(3, 2, 2)` input (it lowers to bmm). (`torch.compile(fn, mode="max-autotune-no-cudagraphs")` sets the same `max_autotune` config, so it is expected to hit the same path.)

Cause (2.14.0 sources): `torch/_inductor/codegen/cpp_bmm_template.py`, `BMM_TEMPLATE` line 44 emits

```
extern "C"
{{kernel.def_kernel(inputs={"X": BX, "W": BW}, outputs={"Y": BY}, aliases=aliases)}}
```

whereas `cpp_gemm_template.py` (line 190) and `cpp_grouped_gemm_template.py` (line 41) emit `extern "C" {{export_declaration}}`, where `get_export_declaration()` (`codegen/cpp.py` line 92) returns `__declspec(dllexport)` on Windows and `""` elsewhere. Without it the symbol has no export entry in the DLL, and `autotune_process.py` line 1277 (`run_method = getattr(self.DLL, self.kernel_name)`) fails. Linux/macOS are unaffected because ELF/Mach-O symbols are visible by default.

Still present on nightly torch 2.15.0.dev20260911+cpu (Windows 11 / MSVC 19.44, same reproducer): `mm ok`, `bmm` and 3-d `matmul` fail with the same `AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found`; `cpp_bmm_template.py` on `main` still emits a bare `extern "C"` without `{{export_declaration}}`. (The Linux nightly run passes, as expected for a Windows-only symbol-export problem.)

Expected: bmm autotunes like mm (or, if the C++ template cannot be benchmarked, it is skipped and the ATen choice is used, instead of failing the whole compilation).

### Error logs

```
  File "...\torch\_inductor\select_algorithm.py", line 3666, in benchmark
  File "...\torch\_inductor\codegen\cpp_template_kernel.py", line 640, in benchmark
    return self.bmreq.benchmark(*args, out=out)
  File "...\torch\_inductor\autotune_process.py", line 585, in benchmark
  File "...\torch\_inductor\autotune_process.py", line 1277, in make_run_fn
    run_method = getattr(self.DLL, self.kernel_name)
AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found
torch._inductor.exc.InductorError: LoweringException: AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found
  target: aten.bmm.default
```

### Versions

```
PyTorch version: 2.14.0+cpu
Is debug build: False
CUDA used to build PyTorch: None
ROCM used to build PyTorch: N/A

OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
GCC version: Could not collect
Clang version: Could not collect
CMake version: Could not collect
Libc version: N/A
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64 (used by Inductor's C++ backend)

Python version: 3.14.7 (tags/v3.14.7:823f032, Aug  5 2026, 10:51:32) [MSC v.1944 64 bit (AMD64)] (64-bit runtime)
Python platform: Windows-11-10.0.26200-SP0
Is CUDA available: False
CUDA runtime version: No CUDA
GPU models and configuration: No CUDA
Is XPU available: False
Is XNNPACK available: False

CPU:
Name: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
Manufacturer: GenuineIntel
Architecture: 9

Versions of relevant libraries:
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
[pip3] torchvision==0.29.0+cpu
[conda] Could not collect
```
