<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 34（中：Inductor CPU 的 `erfinv` 在 ±1 附近精度只有 3～4 位——用的是 ATen 旧的 `calc_erfinv`（有理逼近 + 两步牛顿），eager 内核精确）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；标量尾部与向量主体（n=3 与 n=64）同样错；Linux gcc（Kaggle `tcc-sleeflinux`）：同样错但幅度小（f32 7.8e-6、f64 6.2e-5）；Tesla T4（Kaggle `tcc-erfinvgpu`，2.14.0+cu130 与 nightly）：CUDA 编译结果与参照一致——CPU 后端专属 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22：`erfinv inductor accuracy`、`erfinv torch.compile precision near 1`、`erfinv compiled wrong tail`、`calc_erfinv inductor`：无同报告（#129090、#136776 是 erfinv 的代码生成/头文件搬家，不涉及精度） |
| 证据包 | `plan/reports_pairs/vector_acosh_erfinv.py`（mpmath 30 位参照）；发现来源 `plan/reports_pairs/large_arg_special_functions.py`（11.4 延伸：特殊函数 × 大参数/近奇点 × 向量/标量路径） |
| 根因 | `torch/_inductor/codegen/cpp.py`：标量 `erfinv(x)` → `calc_erfinv({x})`，向量 `{x}.erfinv()` → `Vectorized::erfinv` = `map(calc_erfinv)`；`calc_erfinv`（`ATen/native/Math.h`，Pavlis 1996）是有理逼近初值 + 两步牛顿 `x -= (erf(x) - y) / (2/√π · e^{-x²})`，在 y → ±1 时 `erf(x) - y` 灾难性相消，两步牛顿收敛不到位。eager 的 CPU 内核结果与 mpmath 一致到浮点精度，走的不是这条路 |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent), module: numerical-stability |

---

## Title

[inductor][cpu] `torch.erfinv` loses accuracy near ±1 under `torch.compile`: relative error up to 7.5e-3 in float32 and 3.6e-3 in float64 where eager matches a 30-digit reference

## Body

### 🐛 Describe the bug

**Summary.** `torch.erfinv` on CPU returns `3.8325069` in eager for float32 `x = 0.99999994` and `5.8635847` for float64 `x = 1 - 1e-16`, both matching a 30-digit reference, while the Inductor-compiled function returns `3.8035836` and `5.8426883` (relative error 7.5e-3 and 3.6e-3 with MSVC, 7.8e-6 and 6.2e-5 with glibc; torch 2.14.0 and nightly, scalar and vector paths). A user computing normal quantiles from probabilities close to 1 (`sqrt(2) * erfinv(2p - 1)`) gets tail values off in the third digit with no error, and the error grows smoothly toward ±1. Because the C++ backend emits `calc_erfinv` from `ATen/native/Math.h` (a rational guess plus two Newton steps whose correction `erf(x) - y` cancels near ±1) rather than the eager kernel's algorithm, every input with `|x| > 0.999` is affected, float64 included.

```python
import torch
from mpmath import mp, erfinv as mp_erfinv

mp.dps = 30
cases = ((torch.float32, [0.99, 0.9999, 0.999999, 0.9999999, 0.99999994]), (torch.float64, [0.999, 0.999999999, 1 - 1e-12, 1 - 1e-14, 1 - 1e-16]))
torch._dynamo.reset()
compiled = torch.compile(torch.erfinv)
for dtype, values in cases:
    for v in values:
        x = torch.full((16,), v, dtype=dtype)
        ref = float(mp_erfinv(mp.mpf(x[0].item())))
        e, c = torch.erfinv(x)[0].item(), compiled(x)[0].item()
        print(f"{str(dtype):14s} x={x[0].item()!r:22s} eager rel err {abs(e - ref) / ref:.1e}   compiled rel err {abs(c - ref) / ref:.1e}   (eager {e:.8g}, compiled {c:.8g}, reference {ref:.8g})")
```

```
torch.float32  x=0.9900000095367432     eager rel err 1.4e-08   compiled rel err 1.8e-07   (eager 1.8213866, compiled 1.8213869, reference 1.8213866)
torch.float32  x=0.9998999834060669     eager rel err 5.1e-09   compiled rel err 3.5e-07   (eager 2.7510355, compiled 2.7510364, reference 2.7510354)
torch.float32  x=0.9999989867210388     eager rel err 2.4e-08   compiled rel err 4.0e-06   (eager 3.4570746, compiled 3.4570887, reference 3.4570747)
torch.float32  x=0.9999998807907104     eager rel err 3.1e-08   compiled rel err 6.8e-06   (eager 3.7439213, compiled 3.7439468, reference 3.7439212)
torch.float32  x=0.9999999403953552     eager rel err 1.0e-08   compiled rel err 7.5e-03   (eager 3.8325069, compiled 3.8035836, reference 3.8325069)
torch.float64  x=0.999                  eager rel err 0.0e+00   compiled rel err 4.0e-15   (eager 2.3267538, compiled 2.3267538, reference 2.3267538)
torch.float64  x=0.999999999            eager rel err 0.0e+00   compiled rel err 1.0e-09   (eager 4.3200054, compiled 4.3200054, reference 4.3200054)
torch.float64  x=0.999999999999         eager rel err 0.0e+00   compiled rel err 5.5e-07   (eager 5.0420319, compiled 5.0420291, reference 5.0420319)
torch.float64  x=0.99999999999999       eager rel err 0.0e+00   compiled rel err 4.8e-05   (eager 5.4725525, compiled 5.4728131, reference 5.4725525)
torch.float64  x=0.9999999999999999     eager rel err 0.0e+00   compiled rel err 3.6e-03   (eager 5.8635847, compiled 5.8426883, reference 5.8635847)
```

The compiled result is the same for a 3-element tensor (scalar C++ path) and a 64-element one (vectorized path), so both code paths share the cause. `backend="aot_eager"` matches eager. On Linux (gcc, glibc) the same program gives smaller but still large errors — float32 `erfinv(0.99999994)` = `3.8325369` (relative error 7.8e-6 against 1.0e-8 for eager) and float64 `erfinv(1 - 1e-16)` = `5.8639485` (6.2e-5 against 0) — so the size of the error depends on the C library's `erf` and `exp`, while the loss of digits itself does not.

**Root cause and possible fix.** `torch/_inductor/codegen/cpp.py` lowers `erfinv` to `calc_erfinv(x)` in the scalar backend and to `x.erfinv()` in the vector backend, which is `Vectorized<T>::erfinv() = map(calc_erfinv)`. `calc_erfinv` in `ATen/native/Math.h` (Pavlis, 1996) forms a rational initial approximation and then applies two Newton steps `x -= (erf(x) - y) / (2/√π · exp(-x²))`; for `y` near ±1 the numerator `erf(x) - y` is the difference of two numbers that agree to almost all their digits, so the correction carries only a few significant digits and two steps do not converge. The eager CPU kernel reaches full precision on the same inputs, so the C++ backend should call the same routine the eager kernel uses, or compute the tail via `erfcinv` (`sqrt(-log(...))` on `1 - |y|`, which is exact for these inputs) with the Newton steps expressed through `erfc` instead of `erf`.

### Error logs

No error is raised; the compiled values differ from eager as shown above.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] mpmath==1.3.0
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu. On Linux (gcc/glibc) the compiled errors are smaller but still far above eager's (see above). On a Tesla T4 (2.14.0+cu130 and nightly) the compiled CUDA kernel matches the reference, so this is specific to the CPU C++ backend.
