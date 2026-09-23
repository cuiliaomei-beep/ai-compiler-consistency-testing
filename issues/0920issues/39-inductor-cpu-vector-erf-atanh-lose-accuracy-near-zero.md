<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 39（中：Inductor CPU 向量路径的 float32 `erf` 在 0 附近失去全部相对精度——|x| ≤ 1e-7 直接得 0、1e-5 处相对误差 1.7e-2；向量 `atanh` 对 |x| < eps 也得 0；标量尾部与 eager 正确）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，eager capability AVX512）；n=3（标量尾部）正确、n ≥ 8（向量主体）错；float64 `erf` 正确（float64 向量 erf 走别的实现）；Linux（Kaggle `tcc-erflinux`，2.14.0+cpu 与 nightly 2.15.0.dev20260922+cpu，capability AVX2）同错：n=64 曲线逐点一致（1e-7→0，1e-5 相对误差 1.7e-2），且 n=3 也错（gcc 下尾循环用带掩码的向量，没有标量尾部） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22（约 18:30）：`erf inductor accuracy small input vectorized`、`Vectorized erf polynomial accuracy near zero`、`erf torch.compile returns 0 small x`、`erf float32 relative error inductor cpu`、`vec256 erf approximation 1.5e-7`：无同报告。相关但不同：#189234（`1 + erf(x)` 在 gelu / ndtr 里的相消，x 为大负数）；#198133（自己的 erfinv） |
| 证据包 | `plan/scripts/special_vs_mpmath.py`（8.3：44 个一元数学函数 × 近奇点/大参数 × n=64 × f32/f64 vs mpmath 30 位；命中 erf、atanh、erfinv、acosh）、`$TEMP/erfcurve.py` / `erf2.py` 逻辑并入稿内代码 |
| 根因 | `CppVecOverrides.erf` → `{x}.erf()` → `Vectorized<float>::erf()`（`vec256_float.h` / `vec512_float.h`）= Abramowitz–Stegun 7.1.26：`erf(x) = 1 − (p1 t + … + p5 t⁵)·e^{−x²}`，`t = 1/(1 + 0.3275911|x|)`，最大**绝对**误差 1.5e-7——对小 x 结果是 `1 − (1 − 小量)`，相对精度全丢：|x| ≤ 1e-7 得 0，2e-7～5e-7 得同一个 4.17e-7。标量后端 `std::erf` 与 eager 内核精确。`atanh` 向量公式 `0.5·log((1+x)/(1−x))`：|x| < eps/2 时 `1+x` 舍成 1 → 0 |
| 建议标签 | oncall: pt2, module: inductor, module: cpu, module: vectorization, module: correctness (silent), module: numerical-stability |

---

## Title

[inductor][cpu] Vectorized float32 `torch.erf` loses all relative accuracy near 0 under `torch.compile` (returns 0 for |x| ≤ 1e-7, 1.7e-2 relative error at 1e-5); vector `atanh` returns 0 for |x| below eps

## Body

### 🐛 Describe the bug

**Summary.** Under `torch.compile` on CPU, float32 `torch.erf` of a tensor with 8 or more elements returns `0.0` for `x = 1e-7` and `1.1086e-5` for `x = 1e-5`, while eager returns `1.128e-7` and `1.1284e-5` (torch 2.14.0 and nightly; Windows AVX-512 and Linux AVX2). A user computing `erf` of small arguments, or `atanh`, whose vectorized form returns `0` for every |x| below the float epsilon, gets values with no correct digit, no error, and on Windows a result that changes with the tensor length. Because the vector backend emits `Vectorized<float>::erf()`, the Abramowitz–Stegun 7.1.26 approximation `1 - p(t)·exp(-x²)` whose 1.5e-7 error bound is absolute rather than relative, instead of the `std::erf` the eager kernel uses, every float32 `erf` below about 1e-3 loses digits and below 1e-7 loses everything.

```python
import torch

vals = [1e-8, 1e-7, 2e-7, 5e-7, 1e-6, 1e-5, 1e-4, 1e-3]
for n in (3, 8, 64):
    x = torch.tensor((vals * 8)[:n], dtype=torch.float32)
    torch._dynamo.reset()
    e, c = torch.erf(x), torch.compile(torch.erf)(x)
    print(f"n={n:2d}  " + "  ".join(f"erf({vals[i]:.0e}): eager {e[i].item():.4e} compiled {c[i].item():.4e}" for i in range(min(n, 4))))
x = torch.tensor(vals * 8, dtype=torch.float32)
torch._dynamo.reset()
c = torch.compile(torch.erf)(x)
print("relative error of the compiled erf vs eager (n=64):", " ".join(f"{vals[i]:.0e}:{abs(c[i].item() - torch.erf(x)[i].item()) / torch.erf(x)[i].item():.1e}" for i in range(len(vals))))
for dtype in (torch.float32, torch.float64):
    eps = torch.finfo(dtype).eps
    x = torch.tensor([eps / 4, eps / 2, eps, 1e-3] * 16, dtype=dtype)
    torch._dynamo.reset()
    print(f"atanh {dtype}: eager {torch.atanh(x)[:3].tolist()}  compiled {torch.compile(torch.atanh)(x)[:3].tolist()}")
```

```
n= 3  erf(1e-08): eager 1.1284e-08 compiled 1.1284e-08  erf(1e-07): eager 1.1284e-07 compiled 1.1284e-07  erf(2e-07): eager 2.2568e-07 compiled 2.2568e-07
n= 8  erf(1e-08): eager 1.1284e-08 compiled 0.0000e+00  erf(1e-07): eager 1.1284e-07 compiled 0.0000e+00  erf(2e-07): eager 2.2568e-07 compiled 4.1723e-07  erf(5e-07): eager 5.6419e-07 compiled 4.1723e-07
n=64  erf(1e-08): eager 1.1284e-08 compiled 0.0000e+00  erf(1e-07): eager 1.1284e-07 compiled 0.0000e+00  erf(2e-07): eager 2.2568e-07 compiled 4.1723e-07  erf(5e-07): eager 5.6419e-07 compiled 4.1723e-07
relative error of the compiled erf vs eager (n=64): 1e-08:1.0e+00 1e-07:1.0e+00 2e-07:8.5e-01 5e-07:2.6e-01 1e-06:5.6e-02 1e-05:1.7e-02 1e-04:4.5e-04 1e-03:2.8e-05
atanh torch.float32: eager [2.9802322387695312e-08, 5.960464477539063e-08, 1.1920928955078125e-07]  compiled [0.0, 5.9604641222676946e-08, 1.1920927533992653e-07]
atanh torch.float64: eager [5.551115123125783e-17, 1.1102230246251565e-16, 2.220446049250313e-16]  compiled [0.0, 1.1102230246251564e-16, 2.2204460492503126e-16]
```

On Windows (MSVC) the scalar tail (`n=3`, generated as `std::erf`) is right, so the same element comes out as `0` or `1.13e-7` depending only on how long the tensor is; on Linux (gcc, AVX2, torch 2.14.0 and nightly 2.15.0.dev20260922) the tail loop is vectorized with a mask, so `n=3` is wrong as well and the relative-error curve is identical point for point (`1e-7 → 0`, `1e-5 → 1.7e-2`, `1e-3 → 2.8e-5`). float64 `erf` is right on both paths. `torch.nn.functional.gelu` is not measurably affected (its `0.5·x` term dominates), but any direct use of `erf` for small arguments — error functions in statistics, `erf(x)/x` style kernels, Faddeeva-type formulas — is.

**Root cause and possible fix.** `torch/_inductor/codegen/cpp.py` lowers `erf` to `x.erf()` in the vector backend, which is `Vectorized<float>::erf()` in `ATen/cpu/vec/vec256/vec256_float.h` and `vec512/vec512_float.h`: the Abramowitz–Stegun 7.1.26 polynomial `erf(x) ≈ 1 - (p1·t + … + p5·t⁵)·exp(-x²)`, `t = 1/(1 + 0.3275911·|x|)`. Its stated accuracy is 1.5e-7 *absolute*, which is fine for |x| ≳ 0.1 and meaningless below it: for |x| ≤ 1e-7 the subtraction `1 - (…)` yields exactly 0, for 2e-7 ≤ |x| ≤ 5e-7 it yields the same `4.17e-7`, and at 1e-5 the relative error is 1.7e-2. The scalar backend emits `std::erf`. A fix that keeps the vector path is to use the small-|x| Taylor form `(2/√π)·x·(1 - x²/3 + x⁴/10)` below about 0.1 (or SLEEF's `erf` which is accurate to 1 ulp everywhere), selected with a mask; the eager CPU kernel already reaches full precision on these inputs. `atanh` has the analogous problem in `0.5·log((1 + x) / (1 - x))`: for |x| < eps/2 both `1 ± x` round to 1; `0.5·log1p(2x / (1 - x))` is exact there.

### Error logs

No error is raised; the compiled values differ from eager as shown above.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz (AVX-512)
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu, and (erf part) on Linux x86-64 with torch 2.14.0+cpu and nightly 2.15.0.dev20260922+cpu (Kaggle, CPU capability AVX2, gcc).
