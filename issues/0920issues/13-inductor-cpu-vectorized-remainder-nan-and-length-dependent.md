<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 13（中–高：静默错值；同一元素的结果取决于张量长度）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，AVX2）；Linux 复核（Kaggle，`plan/kaggle_out/intublinux.log`、`intubgpu.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 同样出错，且其中一台机器上**连 3 个元素的张量也得 nan**（尾部也走带掩码的向量路径），另一台与 Windows 一样是长度 3 正确、长度 8 错；CUDA（Triton）正确；`aot_eager` 与 eager 一致；`torch.fmod` 正常 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21：open #194345（CUDA 上 remainder/fmod 在 \|a/b\| 很大时错，正文写明 "compiled CPU 给出正确结果"——他们用的是单元素输入，走的是标量路径）；open #186875（bf16/fp16 + Python 标量）。本条是 **CPU 向量化路径**，float32/float64，且包含 ±inf 除数得 NaN，根因不同 → 新 issue，正文引用 #194345 |
| 证据包 | `plan/reports_intub/remainder_vector_vs_tail.py`；发现来源 `plan/scripts/int_ub_sweep.py`（`float_binary:remainder`：1600 对里 NaN 模式 125 处不同） |
| 根因 | `torch/_inductor/codegen/cpp.py::CppVecOverrides.remainder`：浮点走 `a - floordiv(a, b) * b`；标量路径 `CppOverrides` 用 `mod()`（fmod + 符号修正） |
| 建议标签 | oncall: pt2, oncall: cpu inductor, module: correctness (silent) |

---

## Title

[inductor][cpu] Vectorized `torch.remainder` / `%` returns NaN for an infinite divisor and 0 for large quotients; elements handled by the scalar tail are correct, so the result depends on the tensor length and on the CPU

## Body

### 🐛 Describe the bug

**Summary.** `torch.remainder` and `%` on float tensors do not agree between eager and CPU Inductor once the tensor is vectorized: with a divisor of `±inf` eager returns the dividend and Inductor returns `nan`, and `1e20 % 3.0` is `2.0` in eager and `0.0` under Inductor, while a 3-element tensor takes the scalar tail and is correct (torch 2.14.0 and nightly, Windows and Linux; `aot_eager`, `torch.fmod` and CUDA match eager). A user sees values change, even to NaN, once the batch reaches eight elements, which looks like a data issue. Because the vector path computes `a - floor_divide(a, b) * b` rather than the `fmod` with sign correction of the scalar path and eager, every vectorized float remainder with a large quotient or an infinite divisor is affected.

```python
import torch

INF = float("inf")
a = torch.tensor([5.5, -5.5, 0.0, 1e20, 2147483648.0, 7.0, 1.0, -0.0])
b = torch.tensor([INF, -INF, INF, 3.0, 3.0, 0.7, 0.1, 1.0])
f = lambda a, b: torch.remainder(a, b)

print("eager          ", f(a, b).tolist())
torch._dynamo.reset()
print("inductor, n=8  ", torch.compile(f)(a, b).tolist())
torch._dynamo.reset()
print("inductor, n=3  ", torch.compile(f)(a[:3].clone(), b[:3].clone()).tolist(), "  <- same first three elements, scalar path")
```

```
eager           [5.5, -5.5, 0.0, 2.0, 2.0, 1.1920928955078125e-07, 0.09999998658895493, -0.0]
inductor, n=8   [nan, nan, nan, 0.0, 0.0, 0.0, 0.09999996423721313, 0.0]
inductor, n=3   [5.5, -5.5, 0.0]   <- same first three elements, scalar path
```

**Root cause.** `torch/_inductor/codegen/cpp.py`, `CppVecOverrides.remainder`:

```python
return f"{a} - ({CppVecOverrides.floordiv(a, b)}) * {b}"
```

For `b = inf` this is `a - 0 * inf = nan`; for a large quotient the product `floor(a / b) * b` absorbs `a` and the difference is `0`; for ordinary inputs it is less accurate than eager (`0.09999996` vs `0.09999999`), and the sign of a zero result is lost (`-0.0 % 1.0` gives `0.0`). The scalar override emits `mod(a, b)`, which is `std::fmod` plus a sign correction and matches eager. `Vectorized<T>::fmod` already exists (it is what `torch.fmod` uses and it is correct in the run above), so the vector override can mirror the scalar one: `r = a.fmod(b); r = blendv(r, r + b, (r != 0) & ((r < 0) ^ (b < 0)))`.

The length dependence is specific to the instruction set: on one Linux x86-64 machine the 3-element call above also returns `[nan, nan, nan]`, because there the tail is vectorized with a masked load as well; on another Linux machine and on Windows (AVX2) the output is exactly the one shown.

Related: #194345 reports wrong `remainder` / `fmod` results for large `|a / b|` under Triton and states that compiled CPU is correct; that holds for its single-element inputs, which take the scalar path.

### Error logs

No error is raised; the values differ as shown above.

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

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux).
