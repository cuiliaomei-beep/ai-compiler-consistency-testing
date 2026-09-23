<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 04

| 项 | 值 |
|---|---|
| 提交优先级 | 04 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 1 条；草稿 `plan/issues_0910/01-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`），Windows 11 / MSVC 19.44 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20argmin%20dynamic%20shapes%20C%2B%2B%20compile%20error · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20argmin_combine_vec · 2026-09-10 五组关键词均无同报告；最近的 #171870（s390x 向量算子缺失）、#193680（融合 arg-reduction 索引值错）都不是 |
| 证据包 | `plan/reports_metamorphic/argmin_pow_dynamic/`（`minimal_verified.py`、`DEDUP.md`），`plan/scripts/diag_argmin_dynamic.py`（打印生成的 C++ 出错行） |
| 建议标签 | oncall: pt2, module: inductor, module: cpu inductor, module: dynamic shapes |

---

## Title

[inductor][cpu] argmin/argmax under `dynamic=True` emits the index expression with Python `**` into C++ → CppCompileError

## Body

### 🐛 Describe the bug

**Summary.** For `argmin`/`argmax` on a broadcast sum under `dynamic=True`, eager and the CPU Inductor backend do not agree on whether the program runs: eager and `aot_eager` return the index, while Inductor emits `ks1**2*x0 + x1` into the generated C++ and the kernel fails to compile with MSVC and GCC alike (torch 2.14.0 and nightly). A user hits `InductorError: CppCompileError` only for the shape pattern where two equal-sized dimensions are unified into one symbol, so static compilation and slightly different shapes work and the failure looks random. Because the index expression is printed with Python's `str()` instead of the C++ expression printer in two places of `cpp.py`, any arg-reduction whose index contains a power is affected.

With dynamic shapes, when two dimensions of equal size are unified into one symbol (`ks1 * ks1` → `ks1**2`) and an arg-reduction (`argmin` / `argmax`) is split by a broadcast operand into an outer × inner loop, the CPU C++ backend prints the reduction's *index expression* with the Python printer:

```cpp
tmp_acc0_vec = argmin_combine_vec<float, 1, 2, true>(tmp_acc0_vec, tmp4, ks1**2*x0 + x1);
```

`**` is not C++, so the kernel does not compile and `torch.compile` raises `InductorError: CppCompileError`. Verified with two compilers: MSVC on Windows (`error C2100: illegal indirection`) and GCC on Linux (Kaggle, torch 2.14.0+cu130, CPU: `main.cpp:25:106: error: invalid type argument of unary '*' (have 'int')`). The CUDA/Triton backend is not affected (same call with CUDA tensors compiles and matches eager). Static shapes, `backend="aot_eager"`, dim-wise `argmin(dim=...)`, `amin`/`amax` (no index), and distinct inner sizes (e.g. `(3, 2, 3) + (1, 2, 3)`) all work.

Minimal reproducer:

```python
import torch

x = torch.randn(3, 4, 4)
m = torch.randn(1, 4, 4)        # broadcast over dim 0; the two inner dims have equal size

def f(x, m):
    return (x + m).argmin()

print(f(x, m))                                                    # e.g. tensor(24)
print(torch.compile(f)(x, m))                                     # same (static shapes: fine)
torch._dynamo.reset()
print(torch.compile(f, backend="aot_eager", dynamic=True)(x, m))  # same
torch._dynamo.reset()
print(torch.compile(f, dynamic=True)(x, m))                       # InductorError: CppCompileError: C++ compile error
```

`(x + m).argmax()` and `torch.where(m, x, torch.tensor(float("inf"))).argmin()` fail the same way; the case was originally hit through `torch.masked.argmin(x, mask=mask)` with a broadcastable mask.

Ablations (all on 2.14.0+cpu):

| variant | result |
|---|---|
| static compile | ok |
| `dynamic=True`, `backend="aot_eager"` | ok |
| `dynamic=True`, inductor, `(3,4,4)+(1,4,4)` | **CppCompileError** |
| `dynamic=True`, inductor, `(3,2,3)+(1,2,3)` (distinct inner sizes, no `Pow`) | ok |
| `dynamic=True`, inductor, `argmin(dim=0)` | ok |
| `dynamic=True`, inductor, `amin()` (no index) | ok |
| `dynamic=True`, inductor, 2-D `(4,4)+(1,4)` | ok |

Where it comes from (2.14.0 sources, `torch/_inductor/codegen/cpp.py`):

- `CppVecKernel.reduction_combine_vec`, line 3749: `arg_extra = f", {self._adjust_argreduce_index(index)}"` — the sympy index is formatted with `str()` (Python printer) instead of `cexpr_index(...)`;
- scalar `reduction_combine`, line 256: `f"{reduction_type}_combine({var}, {next_value}, {index})"` — same.

Every other index in that file goes through `cexpr_index`, which prints `Pow` as valid C++. Products of *distinct* symbols print identically in both printers, which is why the bug only surfaces when a symbol is squared (duck sizing of equal dims, or `x.view(n, n)`-style shapes).

Expected: the same result as eager / static compile.

### Error logs

Windows / MSVC:

```
torch._inductor.exc.InductorError: CppCompileError: C++ compile error

Command: cl /I ... /O2 /std:c++20 ... c...main.cpp /LD /Fe...
Output:
c...main.cpp(28): error C2100: illegal indirection
```

Linux / GCC (torch 2.14.0+cu130, same reproducer on CPU tensors):

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1) (Kaggle, Linux CPU / GCC): `main.cpp:28:106: error: invalid type argument of unary '*' (have 'int')`; CUDA/Triton still fine.

```
torch._inductor.exc.InductorError: CppCompileError: C++ compile error

Command: g++ /tmp/torchinductor_root/ra/crarvwr7an7ouhzjplo7erjzykbrlakfmlqanumt77qj7sbw7wqh.main.cpp -D ...
/tmp/torchinductor_root/ra/crarvwr7an7ouhzjplo7erjzykbrlakfmlqanumt77qj7sbw7wqh.main.cpp:25:106: error: invalid type argument of unary '*' (have 'int')
/tmp/torchinductor_root/ra/crarvwr7an7ouhzjplo7erjzykbrlakfmlqanumt77qj7sbw7wqh.main.cpp:32:106: error: invalid type argument of unary '*' (have 'int')
```

Generated code around the failing line (from `TORCH_LOGS=output_code`):

```cpp
    23|   auto tmp0 = at::vec::VecMask<float,1>::from(in_ptr0 + static_cast<int64_t>(x1), static_cast<int64_t>(16));
    24|   auto tmp1 = at::vec::Vectorized<float>::loadu(in_ptr1 + static_cast<int64_t>(x1 + x0*static_cast<int64_t>(ks1*ks1)), static_cast<int64_t>(16));
    ...
    28|   tmp_acc0_vec = argmin_combine_vec<float, 1, 2, true>(tmp_acc0_vec, tmp4, ks1**2*x0 + x1);
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
