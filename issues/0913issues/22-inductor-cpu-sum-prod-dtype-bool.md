<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 22

| 项 | 值 |
|---|---|
| 提交优先级 | 22 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 21 条；草稿 `plan/issues_0910/21-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows/MSVC）；nightly 2.15.0.dev20260911（Windows）；Linux CPU 2.14.0 与 nightly dev20260912（g++，`kaggle_out/leadslinux.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20sum%20dtype%20bool%20inductor · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20prod%20dtype%20bool%20inductor（2026-09-12 无同报告） |
| 证据包 | `plan/scripts/diag_dtype_leads.py`，`plan/kaggle_out/dtypesgpu/plan/gpu_dtypes_cpu/DTYPE_MATRIX.md`（`sum_dtype` 行） |
| 建议标签 | oncall: pt2, module: inductor, module: cpu inductor |
| 备注 | 低优先级（`dtype=torch.bool` 归约少见），但两条都是 eager 接受、Inductor 崩溃；`prod` 的断言在通用代码里，CUDA 大概率也挂（未验） |

---

## Title

[inductor] `torch.sum(x_half, dtype=torch.bool)` fails with a C++ compile error and `torch.prod(x, dtype=torch.bool)` with "expected reduction_type in (min, max, any, sum)"; both work in eager

## Body

### 🐛 Describe the bug

**Summary.** `torch.sum(x, dtype=torch.bool)` on a float16 or bfloat16 input and `torch.prod(x, dtype=torch.bool)` on any float input do not compile on CPU: eager and `aot_eager` return a bool scalar, while Inductor fails with a C++ compile error (`sum_masked_reduce` has no bool overload) for `sum` and `AssertionError: expected reduction_type in ("min", "max", "any", "sum")` for `prod` (torch 2.14.0 and nightly, MSVC and GCC). A user who folds a mask with a reduction in bool sees float32 work and half precision fail. Because the CPU reduction codegen has no bool accumulator for these reduction types, the outcome is decided by the input dtype rather than by the program.

Two reductions with `dtype=torch.bool` that eager (and `aot_eager`) evaluate to a bool scalar fail to compile with Inductor on CPU:

```python
import torch

x16 = torch.randn(3, 4).half()
x32 = torch.randn(3, 4)

print(torch.sum(x16, dtype=torch.bool))                  # tensor(True)
torch.compile(lambda a: torch.sum(a, dtype=torch.bool))(x16)
# InductorError: CppCompileError: C++ compile error ... error C2672: 'sum_masked_reduce': no matching overloaded function found   (MSVC)
# g++: same kernel fails to compile on Linux

print(torch.prod(x32, dtype=torch.bool))                 # tensor(True)
torch.compile(lambda a: torch.prod(a, dtype=torch.bool))(x32)
# InductorError: AssertionError: expected reduction_type in ("min", "max", "any", "sum")
```

Details:

- `sum(..., dtype=torch.bool)` fails only for float16 / bfloat16 inputs (float32 input compiles and returns `tensor(True)`); with a `dim=` argument (`torch.sum(x16, 0, dtype=torch.bool)`) it also compiles. So it is the full reduction of a half-precision input into a bool accumulator: the generated C++ calls `sum_masked_reduce` with a bool accumulator type that has no overload.
- `prod(..., dtype=torch.bool)` fails for every float input; the assertion comes from the CPU reduction codegen, which only knows `min/max/any/sum` as bool reductions (`prod` on bool would be `all`).
- `aten.cumsum(..., dtype=torch.bool)` is rejected by eager itself ("not implemented for 'Bool'"), so that one is consistent.

Expected: same `tensor(True)` / `tensor(False)` as eager (the semantics are `any()` for sum and `all()` for prod after the cast), or at least a graceful fallback instead of a compile failure.

### Error logs

```
torch._inductor.exc.InductorError: CppCompileError: C++ compile error
...main.cpp(19): error C2672: 'sum_masked_reduce': no matching overloaded function found
```
```
torch._inductor.exc.InductorError: AssertionError: expected reduction_type in ("min", "max", "any", "sum")
  (Error in codegen for ComputedBuffer(... layout=FixedLayout('cpu', torch.bool, size=[], stride=[]), data=Reduction(... reduction_type=prod ...)))
```

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14, MSVC 19.44 — `python -m torch.utils.collect_env` output below; the same reproducer was also run on the 2026-09-11 nightly wheel.)

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

Also reproduced on Linux CPU (Kaggle, torch 2.14.0+cpu and 2.15.0.dev20260912+cpu, g++).
