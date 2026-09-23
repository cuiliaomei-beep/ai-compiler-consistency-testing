<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 12: export 静默接受对提升常量的原地更新，AOTI 打包抛内部断言

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20export%20constant%20tensor%20mutation%20instance_norm · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20mutating%20a%20non-functional%20tensor%20INTERNAL%20ASSERT%20export · 2026-09-10 无同报告；#150008（closed 2026-05）是同一断言类的另一触发（narrow 视图上的 `copy_`），#185130（closed）修的是 prim view 函数化 |
| 证据包 | `plan/reports_aoti/lifted_constant_mutation/`（`minimal_verified.py`、`DEDUP.md`），`plan/scripts/diag_aoti_instance_norm2.py` |
| 建议标签 | oncall: pt2, oncall: export, module: aotinductor, module: functionalization |

---

## Title

[export][aoti] In-place update of a captured (lifted-constant) tensor: `torch.export` succeeds and keeps the update (the exported module mutates the captured tensor in place), `run_decompositions` raises the intended error, `aoti_compile_and_package` raises an INTERNAL ASSERT ("please report a bug")

## Body

### 🐛 Describe the bug

When `F.instance_norm` (or `F.batch_norm(..., training=True)`) is called with `running_mean` / `running_var` that are plain tensors captured from the enclosing scope — not registered buffers — the three export-side steps disagree:

| step | result |
|---|---|
| eager | ok, `RM` / `RV` updated in place |
| `torch.compile` | ok |
| `torch.export(m, (x,))` | **ok** — the tensors are lifted as constants; the exported module still performs the in-place update (the lifted constant aliases the captured tensor) |
| `ep.module()(x)` | ok |
| `ep.run_decompositions()` | `RuntimeError: Constant lifted_tensor_0 is mutated in the forward method. Pls register it as buffer` (the intended diagnostic) |
| `aoti_compile_and_package(ep)` | `RuntimeError: false INTERNAL ASSERT FAILED at ".../ATen/RegisterFunctionalization_2.cpp":8058, please report a bug to PyTorch. mutating a non-functional tensor ...` |

With `register_buffer` every step works. Same three outcomes on Linux (Kaggle, torch 2.14.0+cu130, CPU and CUDA tensors; the assert is at `RegisterFunctionalization_2.cpp:8056` in that build). The pattern is not exotic: every OpInfo sample of `nn.functional.instance_norm` with running statistics passes them exactly this way, and user code that keeps running stats in module-level tensors does too.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): `run_decompositions` raises the clear "Constant lifted_tensor_0 is mutated" error, `aoti_compile_and_package` still hits the INTERNAL ASSERT (now at `RegisterFunctionalization_2.cpp:8064`), CPU and CUDA.

```python
import os, tempfile, torch
import torch.nn.functional as F
from torch.export import export
from torch._inductor import aoti_compile_and_package

RM, RV = torch.zeros(3), torch.ones(3)

class M(torch.nn.Module):
    def forward(self, x):
        return F.instance_norm(x, RM, RV, use_input_stats=True)   # updates RM / RV in place

x = torch.randn(2, 3, 4, 4)
m = M()
m(x); print("eager: RM updated ->", RM)
ep = export(m, (x,)); print("export ok")            # no error, no warning
try:
    ep.run_decompositions()
except Exception as e:
    print("run_decompositions:", type(e).__name__, e)   # Constant lifted_tensor_0 is mutated in the forward method. Pls register it as buffer
try:
    aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2"))
except Exception as e:
    print("aoti_compile_and_package:", type(e).__name__, str(e)[:160])
    # false INTERNAL ASSERT FAILED at "...\ATen\RegisterFunctionalization_2.cpp":8058, please report a bug to PyTorch. mutating a non-functional tensor ...
```

Expected: `torch.export` raises the same clear error as `run_decompositions` (a mutated lifted constant is not exportable), or exports it as a buffer mutation; `aoti_compile_and_package` never surfaces an internal assert for user code that `export` accepted.

### Error logs

```
RuntimeError: Constant lifted_tensor_0 is mutated in the forward method. Pls register it as buffer        # ep.run_decompositions()

RuntimeError: false INTERNAL ASSERT FAILED at "C:\actions-runner\_work\pytorch\pytorch\build\aten\src\ATen\RegisterFunctionalization_2.cpp":8058, please report a bug to PyTorch. mutating a non-functional tensor with a functional tensor is not allowed. Please ensure that all of your inputs are wrapped inside of a functionalize() call.   # aoti_compile_and_package(ep)
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
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64 (used by Inductor / AOTI C++ backend)

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
