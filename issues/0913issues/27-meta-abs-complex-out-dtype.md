<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 27

| 项 | 值 |
|---|---|
| 提交优先级 | 27 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 30 条（无早期草稿） |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows Py3.14 + Linux Py3.11）；nightly 2.15.0.dev20260911（Windows）/ dev20260912（Linux，`kaggle_out/unarylinux.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20abs%20complex%20out%20dtype · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20out%3D%20complex%20real%20meta（`results/dedup_0913e.txt`，无同报告；#125718 是复数支持总 issue） |
| 证据包 | `plan/scripts/diag_unary_out_complex.py`，`plan/results/unary_dtype/UNARY_DTYPE.md`（一元算子 × dtype × out= 扫描） |
| 建议标签 | oncall: pt2, module: fakeTensor, module: complex |
| 备注 | 低优先级：`out=` 到另一 real dtype 的用法少见；但 eager 接受、compile 拒绝，且 `angle` 同样场景两边一致 |

---

## Title

[fake tensor] `torch.abs(complex, out=real_tensor_of_other_dtype)` is accepted by eager but rejected under torch.compile (meta requires out dtype == real dtype)

## Body

### 🐛 Describe the bug

**Summary.** `torch.abs(z, out=o)` for a complex64 `z` and a real `out` of a different dtype does not agree between eager and compile: eager fills a float64 or bfloat16 `out`, while `aot_eager` and Inductor fail in fake-tensor propagation; `out=float32` and `torch.angle(z, out=float64_out)` work everywhere (torch 2.14.0 and nightly, Windows and Linux). A user with an existing `out` buffer sees compile reject a call eager accepts. Because the meta kernel requires the `out` dtype to equal the real dtype of the input while the eager kernel casts, the outcome is decided by the meta check rather than by the operator's documented behaviour.

```python
import torch

z = torch.complex(torch.rand(3, 4) + 0.5, torch.rand(3, 4))

def f(a):
    return torch.abs(a, out=torch.empty(0, dtype=torch.float64))

print(f(z).dtype)                                            # torch.float64 (eager casts the real result into out)
torch.compile(f, backend="aot_eager")(z)                     # TorchRuntimeError: RuntimeError when making fake tensor call
torch.compile(f)(z)                                          # same
```

Matrix (torch 2.14.0+cpu; identical on the 2026-09-11 nightly and on Linux):

| call | eager | aot_eager | inductor |
|---|---|---|---|
| `abs(complex64, out=float64)` | float64 | **raise** | **raise** |
| `abs(complex64, out=bfloat16)` | bfloat16 | **raise** | **raise** |
| `abs(complex64, out=float32)` | float32 | float32 | float32 |
| `abs(float32, out=float64)` | raise (eager rejects too) | raise | raise |
| `angle(complex64, out=float64)` | float64 | float64 | float64 |

So eager's `abs` kernel casts a complex→real result into any floating `out`, while the meta function insists the `out` dtype equals the real dtype of the input; `angle`, whose meta allows the cast, is consistent. Expected: either both accept (matching eager) or eager also rejects — the documented behaviour of `out=` is that the result is cast into the provided tensor when the cast is safe.

### Error logs

```
torch._dynamo.exc.TorchRuntimeError: RuntimeError when making fake tensor call
  Explanation: Dynamo failed to run FX node with fake tensors: call_function <built-in method abs of type object ...>(*(FakeTensor(..., size=(3, 4), dtype=torch.complex64),), **{'out': FakeTensor(..., size=(0,), dtype=torch.float64)}): got RuntimeError('Expected out tensor to have dtype torch.float32 but got torch.float64 instead')
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

Also reproduced on Linux / Python 3.11 with torch 2.14.0+cpu and 2.15.0.dev20260912+cpu.
