<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 18

| 项 | 值 |
|---|---|
| 提交优先级 | 18 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 17 条；草稿 `plan/issues_0910/17-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911 —— **Windows + Python 3.14**。Linux + Python 3.11（Kaggle，2.14.0 与 nightly dev20260912）**不复现**（与 eager 一致），见 `kaggle_out/leadslinux.txt` → 是 Python 3.14 专属（Dynamo 的 3.14 支持），提交时必须写明 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20namedtuple%20RecursionError%20dynamo · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20dynamo%20namedtuple%20equality（2026-09-12 无同报告；#191817 是 invoke_subgraph 对 namedtuple 参数的性能修复，无关） |
| 证据包 | `plan/scripts/diag_dynamic_fstring_namedtuple.py`，`plan/results/dynsem_dynamic/DYNSEM.md`（`dataclass_namedtuple` 命中） |
| 建议标签 | oncall: pt2, module: dynamo, module: dynamic shapes |
| 备注 | 单元素张量的情形 eager 返回 True、compile 栈溢出，是"静默正确 → 崩溃"；多元素张量 eager 也报错（bool 歧义），compile 应报同样的错而不是递归到栈溢出 |

---

## Title

[dynamo] Python 3.14 + `dynamic=True`: `==` between namedtuples that hold tensors overflows the stack (RecursionError) instead of comparing / raising like eager

## Body

### 🐛 Describe the bug

**Summary.** Under `dynamic=True` on Python 3.14, `==` between namedtuples that hold tensors does not behave as in eager: eager returns `True` for one-element tensors and raises the usual "Boolean value of Tensor ... is ambiguous" error otherwise, while the compiled function overflows the stack with `RecursionError` in both cases; plain tuples and lists with the same tensors, `dynamic=False`, and Python 3.11 on Linux behave like eager (torch 2.14.0 and nightly). A user comparing small result records gets a stack overflow instead of a value or the expected error. Because the recursion is decided by Dynamo's handling of namedtuple `__eq__` under symbolic shapes on this Python version rather than by the program, the same code runs on another interpreter.

```python
import collections
import torch

NT = collections.namedtuple("NT", "u v")


def f(x):
    return NT(x, x + 1) == NT(x, x + 1)


x = torch.randn(3, 4)
for dyn in (False, True):
    try:
        print(dyn, torch.compile(f, backend="eager", dynamic=dyn)(x))
    except Exception as e:
        print(dyn, type(e).__name__, str(e)[:60])
```

```
False RuntimeError Boolean value of Tensor with more than one value is ambiguous   <- same as eager
True  RecursionError Stack overflow (used 2912 kB)
```

With one-element tensors eager returns `True` and `dynamic=False` agrees; `dynamic=True` still hits the RecursionError:

```python
def g(x):
    return NT(x[0, 0], x[0, 1]) == NT(x[0, 0], x[0, 1])
# eager: True | dynamic=False: True | dynamic=True: RecursionError: Stack overflow
```

Environment matters: this reproduces with **Python 3.14** (Windows, torch 2.14.0+cpu and the 2026-09-11 nightly); with Python 3.11 on Linux (same torch versions) the compiled function behaves like eager. So it is probably in Dynamo's Python 3.14 bytecode/`__eq__` handling rather than in the namedtuple logic itself.

Plain `tuple`/`list` equality with the same tensors (`(x, x + 1) == (x, x + 1)`) behaves like eager under `dynamic=True`, and a namedtuple with scalar fields (`NT(1, 2) == NT(1, 2)`) is fine, so it is specifically namedtuple `__eq__` with tensor fields under symbolic shapes.

Expected: same result as eager (`True` / the "Boolean value of Tensor ... is ambiguous" RuntimeError), or a graph break.

### Error logs

```
RecursionError: Stack overflow (used 2912 kB)
```
(full trace is a repeating cycle inside torch/_dynamo/variables while evaluating the comparison)

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
