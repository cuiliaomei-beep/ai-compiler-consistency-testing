<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 06: var_mean / std_mean 空张量在 Inductor 下 mean 为 0

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20var_mean%20empty%20tensor%20compile · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20std_mean%20empty%20inductor%20mean%200 · 2026-09-08 与 2026-09-10 两轮均无同报告；#113167（closed，标量输入 + 非法 correction）不是同一情形；#61901 / #191229 说明空维归约返回 NaN 是既定语义 |
| 证据包 | `plan/reports_opinfo_all/0211b330cc67/`（`ISSUE_FINAL.md`、`minimal_verified.py`），第 4 轮四个上下文 2/2、第 6 轮 5 个程序再次命中 |
| 建议标签 | oncall: pt2, module: inductor, module: cpu inductor |

---

## Title

[inductor] `torch.var_mean` / `torch.std_mean` on an empty tensor return mean `0.` instead of `nan` under `torch.compile`

## Body

### 🐛 Describe the bug

For a zero-element input, eager `torch.var_mean` / `torch.std_mean` return `(nan, nan)` (with the usual "degrees of freedom is <= 0" warning). Under `torch.compile(backend="inductor")` the result is `(nan, 0.)`: the **mean** component is `0.` instead of `nan`. `backend="eager"` and `backend="aot_eager"` match eager, so the deviation enters at Inductor lowering/codegen. `torch.mean`, `torch.var` and `torch.std` on the same input are correct under Inductor; only the fused `var_mean` / `std_mean` are affected.

Reproduces for: `var_mean` and `std_mean`; `correction=1` (default) and `correction=0` / `unbiased=False`; float32 and float16; shapes `(0,)` and `(0, 1)`; `dynamic=True` and `False`. Reducing an empty dimension with `dim=` on a `(0, 3)` input gives `nan` correctly in both — only the full reduction to a scalar is affected.

```python
import torch

x = torch.randn(0)

def f(a):
    return torch.var_mean(a)

print("eager    :", f(x))                                        # (tensor(nan), tensor(nan))
torch._dynamo.reset()
print("aot_eager:", torch.compile(f, backend="aot_eager")(x))   # (tensor(nan), tensor(nan))
torch._dynamo.reset()
print("inductor :", torch.compile(f, backend="inductor")(x))    # (tensor(nan), tensor(0.))   <-- mean differs
torch._dynamo.reset()
print("mean only:", torch.compile(lambda a: a.mean(), backend="inductor")(x))   # tensor(nan)  (correct)
torch._dynamo.reset()
print("std_mean :", torch.compile(lambda a: torch.std_mean(a), backend="inductor")(x))   # (tensor(nan), tensor(0.))
```

Expected: `(tensor(nan), tensor(nan))` — the mean of zero elements has no value (same as eager and as `torch.mean` under Inductor).

Actual: `(tensor(nan), tensor(0.))`.

Not CPU- or Windows-specific: on Linux (Kaggle, torch 2.10.0+cu128) both the CPU and the **Tesla T4** Inductor paths return `(nan, 0.)` for `var_mean` and `std_mean` on an empty input while eager and aot_eager return `(nan, nan)`.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): inductor `(nan, 0.)` vs eager/aot_eager `(nan, nan)` for both `var_mean` and `std_mean`, CPU and CUDA.

The same wrong mean is produced through the second compilation front end: `torch.export(...)` +
`torch._inductor.aoti_compile_and_package` + `aoti_load_package` returns `(nan, 0.)` for `var_mean` and `std_mean` on an
empty input as well (2.14.0+cpu), so the defect is in the shared Inductor lowering, not in Dynamo/AOTAutograd.

Notes:
- Not the case of #113167 (scalar input with an invalid `correction`; closed 2023-11): here the input has zero elements, `correction` is the default, and the wrong component is the mean.
- Eager's NaN over an empty dimension is the intended semantics for reductions without an identity (#61901; see also #191229 for `median`).
- Found by a differential harness that compares eager / `backend="eager"` / `aot_eager` / `inductor` and flags a result only when it disagrees with a float64 reference; reproduced 2/2 with a fixed seed and under four independent contexts (fp32 / fp16 / requires_grad / dynamic=True).

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
