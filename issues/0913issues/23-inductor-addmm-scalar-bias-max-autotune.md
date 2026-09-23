<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 23

| 项 | 值 |
|---|---|
| 提交优先级 | 23 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 10 条；草稿 `plan/issues_0910/10-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20addmm%20max_autotune%20scalar%20bias · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20tuned_addmm%20get_stride%20IndexError · 2026-09-10 四组关键词无同报告；同一行代码有 **open PR #185578 / issue #185533**（SliceView 触发，`maybe_get_stride()` 守卫不覆盖 0-d） |
| 证据包 | `plan/reports_metamorphic/addmm_scalar_bias_autotune/`（`minimal_verified.py`、`DEDUP.md`），`plan/scripts/diag_autotune_tb.py` |
| 建议标签 | oncall: pt2, module: inductor, module: max-autotune |

---

## Title

[inductor] `max_autotune`: `torch.addmm` with a 0-d (scalar) bias fails in `tuned_addmm` with `IndexError: list index out of range` (`inp.get_stride()[0]` evaluated before the rank check)

## Body

### 🐛 Describe the bug

**Summary.** `torch.addmm(bias, x, y)` with a 0-d `bias` does not compile under `max_autotune`: eager and the default configuration return the result, while the autotuned lowering raises `IndexError: list index out of range` in `tuned_addmm` (CPU and CUDA, torch 2.14.0 and nightly). A user enabling `max_autotune` for a model with a scalar bias gets a lowering error that names no user-visible cause. Because `kernel/mm.py` reads `get_stride()[0]` before checking the bias rank, the failure is decided by the autotune path rather than by the operator, and the open PR #185578 for the neighbouring SliceView case does not cover the 0-d rank.

With `max_autotune=True` (or `mode="max-autotune-no-cudagraphs"`), compiling `torch.addmm(bias, x, y)` where `bias` is a 0-d tensor raises `LoweringException: IndexError: list index out of range`. The default configuration and eager work, and 1-d / 2-d biases work under max_autotune.

```python
import torch
from torch._inductor import config as IC

torch.manual_seed(0)
x, y = torch.randn(2, 2), torch.randn(2, 3)
for name, bias in (("0-d bias", torch.tensor(0.5)), ("1-d bias", torch.randn(3)), ("2-d bias", torch.randn(2, 3))):
    torch._dynamo.reset()
    try:
        with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
            out = torch.compile(lambda b, x, y: torch.addmm(b, x, y))(bias, x, y)
        print(name, "ok", torch.allclose(out, torch.addmm(bias, x, y), atol=1e-5))
    except Exception as e:
        print(name, type(e).__name__, str(e)[:80])
```

Output on 2.14.0+cpu:

```
0-d bias InductorError: LoweringException: IndexError: list index out of range
1-d bias ok True
2-d bias ok True
```

Not CPU- or Windows-specific: the same `IndexError: list index out of range` in `tuned_addmm` occurs on Linux CPU and on a Tesla T4 (Kaggle, torch 2.14.0+cu130).

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): `LoweringException: IndexError: list index out of range` for `aten.addmm.default` on both CPU and CUDA.

Cause (`torch/_inductor/kernel/mm.py`, `tuned_addmm`, line 714 in 2.14.0):

```python
if (
    inp.get_stride()[0] == 0
    and len(inp.get_size()) == 2
    and inductor_config.triton.autotune_cublasLt
    and not V.graph.cpp_wrapper
):
    aten_templates.append(aten_bias_addmm)
```

For a 0-d bias `get_stride()` is `()` and the first operand raises before the rank check runs. Swapping the two conditions (or checking `len(inp.get_size()) == 2` first) fixes it. Open PR #185578 (issue #185533) guards the same expression for lazy `SliceView` inputs with `maybe_get_stride()`, but a 0-d bias would still index into an empty tuple after that change.

Expected: same result as eager / default config (max_autotune should simply not add the `bias_addmm` candidate for a 0-d bias).

### Error logs

```
  File "...\torch\_inductor\graph.py", line 1567, in call_function
    raise LoweringException(
  File "...\torch\_inductor\graph.py", line 1544, in call_function
  File "...\torch\_inductor\lowering.py", line 525, in wrapped
  File "...\torch\_inductor\kernel\mm.py", line 714, in tuned_addmm
    inp.get_stride()[0] == 0
IndexError: list index out of range
torch._inductor.exc.InductorError: LoweringException: IndexError: list index out of range
  target: aten.addmm.default
  args[0]: TensorBox(StorageBox(InputBuffer(name='arg0_1', layout=FixedLayout('cpu', torch.float32, size=[], stride=[]))))
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
