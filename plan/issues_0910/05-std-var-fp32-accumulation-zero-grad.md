<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 05: std/var 在 Inductor 下 fp32 累加：1e30 → inf/NaN，1e-30 → 0 且梯度全 0

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20std%20inductor%20nan%20large%20values · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20inductor%20var_mean%20float32%20accumulation · 2026-09-10：相关 open #173793（LayerNorm、CUDA、1e37 → NaN，同根因），#173989（只修 LayerNorm CPU），#184383 / #183661（CUDA 两遍方差，未合并）；`std`/`var` 本身与梯度归零未被报告 |
| 证据包 | `plan/reports_decomp/std_var_large_values/`（`minimal_verified.py`、`minimal_verified_tiny_grad.py`、`DEDUP.md`、`ISSUE_FINAL.md`），`plan/scripts/confirm_std_tiny_grad.py`、`verify_issue_claims.py` |
| 建议标签 | oncall: pt2, module: inductor, module: cpu inductor, module: numerical-stability |

---

## Title

[inductor][cpu] `torch.std`/`var` accumulate in float32: inf/NaN for 1e30-scale inputs, and **zero output with an all-zero gradient** for 1e-30-scale inputs (eager and float64 are correct)

## Body

### 🐛 Describe the bug

On CPU, eager `torch.std` / `torch.var` / `var_mean` / `std_mean` accumulate float32 inputs in double, so they are correct over the whole float32 range. Under `torch.compile(backend="inductor")` the variance is accumulated in float32:

- inputs of magnitude ~1e30 → `std` / `std_mean` return **inf or NaN** (eager: 1.02e30, equal to the float64 truth). (`var` overflows to inf in eager as well because 1e60 does not fit in float32, so only `std`/`std_mean` disagree there.)
- inputs of magnitude ~1e-30 → `std` returns **0** (eager: 8.2e-31) and, more importantly, the **gradient is all zeros** while eager and float64 give the correct O(1) gradient `(x - mean) / ((N-1)·std)`. A model whose activations are tiny therefore trains in eager and silently stops learning under compile.

`backend="aot_eager"` matches eager in both cases; the deviation enters at Inductor.

```python
import torch

torch.manual_seed(0)

# 1. large values -> inf / nan
x = torch.randn(4, 8) * 1e30
print("eager   :", torch.std(x))                              # tensor(1.0223e+30)  (float64: 1.0223e+30)
torch._dynamo.reset()
print("inductor:", torch.compile(torch.std)(x))               # tensor(inf)   (nan for other inputs, e.g. 5 values ~1e30)

# 2. small values -> zero output and zero gradient
def grads(fn, x):
    xx = x.clone().requires_grad_(True)
    y = fn(xx)
    (g,) = torch.autograd.grad(y, xx)
    return y.item(), g

x = torch.randn(5) * 1e-30
print("eager   :", grads(torch.std, x))            # (8.19e-31, tensor([-0.0371,  0.2498, -0.1366, -0.3250,  0.2489]))
print("fp64    :", grads(torch.std, x.double()))   # same values
torch._dynamo.reset()
print("inductor:", grads(torch.compile(torch.std), x))   # (0.0, tensor([-0., 0., -0., -0., 0.]))
```

Also reproduces for `std_mean`, `correction=0`, and dim-wise `std(dim=1)`.

| | eager | float64 | inductor |
|---|---|---|---|
| `std` of `(4,8) * 1e30` | 1.0223e30 | 1.0223e30 | **inf** |
| `std_mean` of the same | (1.0223e30, 6.592e27) | same | (**inf**, 6.592e27) |
| `std` of 5 values `* 1e30` | 8.19e29 | 8.19e29 | **nan** |
| `var` of `(4,8) * 1e30` | inf (1e60 overflows fp32 output) | 1.045e60 | inf (same as eager) |
| `std` of `(5,) * 1e-30` | 8.19e-31 | 8.19e-31 | **0.0** |
| grad of `std` w.r.t. `(5,) * 1e-30` | `[-0.037, 0.250, -0.137, -0.325, 0.249]` | same | **all zeros** |

`backend="aot_eager"` gives the eager column in every row.

Also on Linux CPU (Kaggle, torch 2.10.0+cu128): `std` of 1e-30 values eager 1.16e-30 / inductor 0.0, gradient eager `[0.139, 0.215, -0.382, 0.153, -0.125]` / inductor all zeros; `std` of `(4,8)*1e30` eager 9.15e29 / inductor inf. On CUDA (T4) eager itself accumulates in float32 and returns 0 / inf as well, so this is a CPU-eager-vs-Inductor discrepancy — which is exactly where users move models between.

A third, more everyday instance of the same accumulation difference: `x = torch.randn(4, 100003) + 1e5` (values ~N(1e5, 1)). `x.var(-1)` in eager has relative error 5.6e-8 against a float64 reference, the compiled version 3.0e-3 (e.g. eager 1.000474 vs compiled 1.002948, truth 1.000474); `std`, `var_mean` and `std(correction=0)` behave the same, and `F.group_norm` on the same data is 10x less accurate compiled (2.7e-3 vs 2.7e-4). With `x = 1 + 1e-4 * randn` (`var` ~ 1e-8) the compiled error is 1000x eager's. Sweep: `scripts/large_reduce_sweep.py` (837 op x value x dtype cases; every flagged case is a variance-family op or an fp16 `prod`). The same sweep on the 2026-09-11 nightly flags exactly the same 26 cases, so the recent reduction-codegen change (#196371) did not affect this.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU), Linux CPU: `std` of 1e-30 values eager 1.16e-30 / inductor 0.0, gradient eager O(0.1) / inductor all zeros; `std` of `(4,8)*1e30` eager 9.15e29 / inductor inf.

Expected: finite `std` for 1e30 inputs; non-zero `std` and the correct gradient for 1e-30 inputs — as eager and float64 give. If float32 accumulation is the intended trade-off, the CPU eager kernel and Inductor should at least agree; a silent all-zero gradient is the worst possible failure mode for training.

Related: #173793 (open) reports the same overflow for `LayerNorm` on CUDA with 1e37 inputs; #173989 fixed the LayerNorm CPU path only. `std`/`var` themselves, and the gradient consequence, are not covered there.

### Error logs

No error is raised; the values differ as shown above.

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
