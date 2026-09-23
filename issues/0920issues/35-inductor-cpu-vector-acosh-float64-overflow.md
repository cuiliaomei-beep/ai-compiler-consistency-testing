<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 35（中–低：Inductor CPU 向量路径的 float64 `acosh` 在 x > 1.34e154 时溢出为 inf；标量尾部与 eager 有限）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，AVX2）；Linux gcc 上 11.4 扫描同样命中；阈值 √DBL_MAX ≈ 1.34e154（1.34e154 有限，1.35e154 起 inf）；n ≥ 8 走向量路径出错，n = 3 标量尾部正确；float32 正确（SLEEF float 路径已在 #184359 一类里处理）；Tesla T4 CUDA 正确（Kaggle `tcc-erfinvgpu`）——CPU 向量后端专属 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22：`acosh inductor inf large double vectorized`、`acosh overflow vectorized`、`asinh vectorized overflow sleef`：无 float64 报告。相关：#183763/#183765/#183768（float32 `cosh/sinh/acosh` 经 SLEEF 溢出，含 eager）、#152299 + PR #184105（Inductor 向量 `asinh` float32 溢出，用稳定公式修）——本条是同一机制的 float64 `acosh` |
| 证据包 | `plan/reports_pairs/vector_acosh_erfinv.py`；发现来源 `scripts/opinfo_edge_sweep.py` int64/float64/complex64 组（Linux）`acosh float64` 一行 + `reports_pairs/large_arg_special_functions.py` |
| 根因 | `torch/_inductor/codegen/cpp.py`：`CppVecOverrides.acosh` → `{x}.acosh()` → `Vectorized<double>::acosh()` = `Sleef_acoshd4_u10`，它按 `log(x + sqrt(x·x − 1))` 计算，x² 在 x > √DBL_MAX 时溢出；标量后端 `std::acosh` 与 eager 内核用稳定公式（对大 x 为 `log(x) + log(2)`） |
| 建议标签 | oncall: pt2, module: inductor, module: cpu, module: vectorization, module: NaNs and Infs |

---

## Title

[inductor][cpu] Vectorized float64 `torch.acosh` returns `inf` for inputs above 1.34e154 under `torch.compile` (eager and the scalar tail are finite): `Vectorized<double>::acosh` squares its argument

## Body

### 🐛 Describe the bug

**Summary.** `torch.acosh` on a float64 tensor of 1e200 returns `461.21` in eager and in the compiled function when the tensor has 3 elements, while the compiled function returns `inf` as soon as the tensor has 8 or more elements (torch 2.14.0 and nightly, Windows/MSVC and Linux/gcc); float32 is unaffected. A user sees the same element come out finite or infinite depending only on how long the tensor is, with no error. Because the vectorized C++ backend lowers `acosh` to `Vectorized<double>::acosh()`, which is SLEEF's `log(x + sqrt(x*x - 1))` and overflows in `x*x` above `sqrt(DBL_MAX) ≈ 1.34e154`, rather than the stable form `std::acosh` uses in the scalar tail and in the eager kernel, only the vector body of the loop is wrong.

```python
import torch

compiled = torch.compile(torch.acosh)
for n in (3, 8, 64):
    x = torch.full((n,), 1e200, dtype=torch.float64)
    print(f"n={n:2d}  eager {torch.acosh(x)[0].item():.6g}   compiled {compiled(x)[0].item():.6g}")
for v in (1.34e154, 1.35e154, 1e308):
    x = torch.full((16,), v, dtype=torch.float64)
    print(f"x={v:.3g}  eager {torch.acosh(x)[0].item():.6g}   compiled {compiled(x)[0].item():.6g}")
```

```
n= 3  eager 461.21   compiled 461.21
n= 8  eager 461.21   compiled inf
n=64  eager 461.21   compiled inf
x=1.34e+154  eager 355.584   compiled 355.584
x=1.35e+154  eager 355.591   compiled inf
x=1e+308  eager 709.889   compiled inf
```

**Root cause and possible fix.** `CppVecOverrides.acosh` in `torch/_inductor/codegen/cpp.py` emits `x.acosh()`, i.e. `Vectorized<double>::acosh()`, which calls `Sleef_acoshd*_u10`; SLEEF computes `log(x + sqrt((x - 1) * (x + 1)))` and the product overflows for `x > sqrt(DBL_MAX)`. The scalar backend emits `std::acosh(x)`, which handles the whole range. This is the float64 counterpart of the float32 `asinh` overflow fixed for the vector backend by using a stable formula (#152299); the same treatment works here: for large `|x|` use `log(x) + log(2)`, or in general `log1p((x - 1) + sqrt((x - 1) * (x + 1)))` computed with `x - 1` factored so nothing is squared.

### Error logs

No error is raised; the compiled result is `inf` where eager is finite, as shown above.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz (AVX2)
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu and on Linux (gcc, torch 2.14.0+cpu and nightly 2.15.0.dev20260921+cpu). On a Tesla T4 the compiled CUDA result is finite and matches eager, so this is specific to the CPU vector backend.
