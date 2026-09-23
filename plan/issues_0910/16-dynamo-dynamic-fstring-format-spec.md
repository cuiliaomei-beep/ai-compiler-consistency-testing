<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 16: `dynamic=True` 下 f-string 对符号整数/浮点用格式说明符 → InternalTorchDynamoError

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows）；nightly 2.15.0.dev20260911（Windows）；Linux（`tcc-leadslinux`，见 `kaggle_out/leadslinux.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20%22Unknown%20format%20code%22%20dynamo · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20f-string%20symint%20format（2026-09-12 无同报告） |
| 证据包 | `plan/scripts/diag_dynamic_fstring_namedtuple.py`，`plan/results/dynsem_dynamic/DYNSEM.md`（6.6 扫描 `item_and_python_math` / `exception_message_with_value` 命中） |
| 建议标签 | oncall: pt2, module: dynamo, module: dynamic shapes |
| 备注 | 只在 `dynamic=True`（或自动动态形状被触发后）出现；错误类型是 InternalTorchDynamoError 而不是 graph break，所以用户看到的是编译崩溃 |

---

## 标题

[dynamo] `dynamic=True`: f-string with a format spec on a SymInt/SymFloat (`f"{x.shape[0]:d}"`) raises InternalTorchDynamoError "Unknown format code 'd' for object of type 'str'"

## 🐛 Describe the bug

With `dynamic=True`, formatting a shape-derived value with a format specifier inside the compiled function crashes Dynamo. Without a format spec (`f"{x.shape[0]}"`) and with `dynamic=False` it works; eager obviously works.

```python
import torch


def f(x):
    return f"{x.shape[0]:d}"            # also: f"{x.shape[0] / 2:.3f}"


x = torch.randn(3, 4)
print(f(x))                                                       # '3'
print(torch.compile(f, backend="eager", dynamic=False)(x))        # '3'
print(torch.compile(f, backend="eager", dynamic=True)(x))         # InternalTorchDynamoError
```

```
torch._dynamo.exc.InternalTorchDynamoError: ValueError: Unknown format code 'd' for object of type 'str'

from user code:
   File "...", line 5, in f
    return f"{x.shape[0]:d}"
```

`f"{x.shape[0] / 2:.3f}"` fails the same way with `Unknown format code 'f' for object of type 'str'`. The symbolic value is apparently converted to its string form (`"s0"`) before the format spec is applied. Variants that work: `f"{x.shape[0]}"`, `f"{int(x.sum().item()):d}"`, `"{:.2f}".format(x.sum().item())`, `str(x.shape[0])`.

Expected: either the formatted string (Dynamo already specializes / guards on the value for the plain f-string case) or a graph break — not an internal error.

Found by a differential run of small Python programs eager vs `torch.compile(backend="eager")`; the original hit was a log message `f"unexpected {v:.2f}"` inside a `raise ValueError(...)`, which turned the user's ValueError into an InternalTorchDynamoError.

### Error logs

```
torch._dynamo.exc.InternalTorchDynamoError: ValueError: Unknown format code 'd' for object of type 'str'
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
