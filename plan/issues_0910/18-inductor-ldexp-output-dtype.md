<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 18: Inductor 的 `torch.ldexp` 输出 dtype 与 eager 双向不一致

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows）；nightly 2.15.0.dev20260911（Windows）；2.14.0+cu130（Kaggle T4）与 Linux CPU（`kaggle_out/dtypesgpu/plan/gpu_dtypes_{cuda,cpu}/DTYPE_MATRIX.md`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20ldexp%20inductor · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20ldexp%20dtype%20compile（2026-09-12 无同报告）。相关 PR：#171721（2026-01-07 合并，"Add native ldexp lowering with libdevice/std::ldexp codegen"，注册了单独的 dtype 传播规则——本问题的来源）、#185540（自定义后端回退到分解）、#186566（负整数指数的梯度） |
| 证据包 | `plan/scripts/diag_dtype_leads.py`（三路对照），`plan/tcc/dtype_matrix.py`（6.2 dtype 矩阵扫描，`results/dtypes_aot`、`kaggle_out/dtypesgpu`） |
| 建议标签 | oncall: pt2, module: inductor |
| 备注 | aot_eager 与 eager 一致，所以是 Inductor lowering 的 dtype 规则，不是分解/meta；CPU 与 CUDA 都复现 |

---

## 标题

[inductor] `torch.ldexp` output dtype differs from eager in both directions (int/bool × half → float32; half × float32 → half)

## 🐛 Describe the bug

Inductor's native `ldexp` lowering decides the output dtype differently from eager (and from `aot_eager`, which agrees with eager):

```python
import torch

cases = {
    "bool  x fp16": (torch.ones(3, 4, dtype=torch.bool), torch.randn(3, 4).half()),
    "int64 x bf16": (torch.randint(1, 4, (3, 4)), torch.randn(3, 4).bfloat16()),
    "fp16  x fp32": (torch.randn(3, 4).half(), torch.randn(3, 4)),
    "fp16  x bf16": (torch.randn(3, 4).half(), torch.randn(3, 4).bfloat16()),
    "bf16  x fp64": (torch.randn(3, 4).bfloat16(), torch.randn(3, 4).double()),
}
for name, (a, b) in cases.items():
    torch._dynamo.reset()
    e = torch.ldexp(a, b).dtype
    i = torch.compile(torch.ldexp)(a, b).dtype
    print(f"{name}: eager {e} | inductor {i}")
```

Output (torch 2.14.0+cpu, same on 2.14.0+cu130 / Tesla T4 and on the 2026-09-11 nightly):

```
bool  x fp16: eager torch.float16  | inductor torch.float32
int64 x bf16: eager torch.bfloat16 | inductor torch.float32
fp16  x fp32: eager torch.float32  | inductor torch.float16
fp16  x bf16: eager torch.float32  | inductor torch.float16
bf16  x fp64: eager torch.float64  | inductor torch.bfloat16
```

Eager follows ordinary type promotion of the two operands (`ldexp(x, e) == x * 2**e`): an integer/bool mantissa with a half exponent gives half, and a half mantissa with a float32 exponent gives float32. Inductor instead keeps the mantissa's dtype when it is floating point and uses float32 when it is not — the exponent's dtype never takes part. `fp16 x fp16`, `fp32 x int64` etc. agree.

Both directions are user-visible: a model that keeps activations in bf16 and passes a float32 exponent gets a bf16 result after compile (precision loss), an integer mantissa with a half exponent gets float32 (memory / dtype mismatch further down).

Where: `torch/_inductor/lowering.py`, the `aten.ldexp` lowering added in #171721 and its `register_op_dtype_propagation_rules` entry; `aot_eager` (which uses the decomposition `input * pow(2, other)`) matches eager, so the decomposition's promotion is right and only the native lowering's rule is off.

Expected: `torch.compile(torch.ldexp)(a, b).dtype == torch.ldexp(a, b).dtype` for every dtype pair (i.e. `torch.result_type(a, b)` promoted to floating point).

### Error logs

No error; dtype mismatch only (values are numerically the same after casting).

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

Also reproduced on torch 2.14.0+cu130 (Kaggle, Tesla T4: `bool x fp16` → float32) and Linux CPU.
