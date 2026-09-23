<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 20: `torch.lerp(bool, bool, 0-d 浮点 weight)` eager 正常、Inductor 编译失败

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows）；nightly 2.15.0.dev20260911（Windows）；2.14.0+cu130（T4）与 Linux CPU（`kaggle_out/dtypesgpu`，`lerp_w` 行） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20lerp%20bool%20inductor · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20lerp%20BackendCompilerFailed（2026-09-12 无同报告） |
| 证据包 | `plan/scripts/diag_dtype_leads.py` |
| 建议标签 | oncall: pt2, module: inductor |
| 备注 | 低优先级：bool 输入的 lerp 很少见；但 eager 接受而 compile 崩溃，且 aot_eager 正常，是分解层对 bool 的 `end - start` 没先提升 |

---

## 标题

[inductor] `torch.lerp(bool_tensor, bool_tensor, scalar_tensor_weight)` works in eager but fails to compile: "Subtraction, the `-` operator, with two bool tensors is not supported"

## 🐛 Describe the bug

```python
import torch

a = torch.randint(0, 2, (3, 4)).bool()
w = torch.tensor(0.3)                      # 0-d weight; float16 0-d behaves the same

def f(a, w):
    return torch.lerp(a, a, w)

print(f(a, w).dtype)                                   # torch.float32
print(torch.compile(f, backend="aot_eager")(a, w).dtype)   # torch.float32
print(torch.compile(f)(a, w).dtype)                    # BackendCompilerFailed
```

```
torch._dynamo.exc.BackendCompilerFailed: backend='inductor' raised:
NotImplementedError: Subtraction, the `-` operator, with two bool tensors is not supported. Use the `^` or `logical_xor()` operator instead.
```

Eager returns a tensor of the weight's dtype (float32 here, float16 for a float16 weight) — `lerp` with a 0-d tensor weight promotes like `start + weight * (end - start)` after promotion. Inductor's lowering/decomposition computes `end - start` on the bool tensors before promoting. With integer tensors (`int64` start/end) the compiled result matches eager, and with a same-shape float16 weight both eager and compile raise the same "expected dtype bool for `weight`" error, so only the 0-d-weight-on-bool path is broken.

Expected: same float result as eager (or the same error as eager if this input combination is meant to be rejected — but eager accepts it).

### Error logs

```
torch._dynamo.exc.BackendCompilerFailed: backend='inductor' raised:
NotImplementedError: Subtraction, the `-` operator, with two bool tensors is not supported. Use the `^` or `logical_xor()` operator instead.
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

Also reproduced on torch 2.14.0+cu130 (Kaggle, Tesla T4) and Linux CPU.
