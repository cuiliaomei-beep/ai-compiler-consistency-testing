<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 15（中：`round(SymInt, 负 ndigits)` 被当成恒等，静默错值）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；`backend="eager"` 即可复现 → Dynamo / SymInt 层；三个后端结果相同；Linux 复核（Kaggle `tcc-symintlinux`，`plan/kaggle_out/symintlinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921（Python 3.12）输出逐字相同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 提交前查重 | 2026-09-21：`dynamo round ndigits symint`、`round negative ndigits torch.compile`、`SymInt __round__`：无同报告。相关但不同：#186069（closed，NumPy 标量上的 round） |
| 证据包 | `plan/reports_symint/scalar_semantics_leads.py`（`round(n * 5, -1)` 一行）；发现来源 `plan/scripts/symint_arith_diff.py`（用例 `i:round_int_neg_digits`） |
| 触发条件（已隔离） | `round(整数符号值, 负数)`，整数符号值来自 `x.shape[i]` / `x.numel()` / `len(x)`（`dynamic=True` 或第二次不同形状触发的自动动态）。`ndigits` 为 `None` 或 ≥ 0 时恒等是对的 |
| 根因 | `torch/__init__.py`：`SymInt.__round__(self, ndigits=None)` 直接 `return self` |
| 建议标签 | oncall: pt2, module: dynamic shapes, module: correctness (silent) |

---

## Title

[dynamic shapes] `round(x.shape[0], -1)` is a no-op on SymInt (`SymInt.__round__` ignores a negative `ndigits`): bucketed sizes computed with `round(n, -k)` silently differ from eager

## Body

### 🐛 Describe the bug

**Summary.** In Python, `round(25, -1)` is `20` and `round(1234, -2)` is `1200`; under `torch.compile(dynamic=True)` the same call on a symbolic size returns the size unchanged, because the `round` disappears from the trace, on every backend (torch 2.14.0 and nightly). Code that buckets a dynamic length with `round(n, -1)` to pick a padded size, a number of chunks, or a scaling constant therefore computes a different number after compilation, with no error and no graph break: `x * round(x.shape[0] * 5, -1)` multiplies by 15 where eager multiplies by 20. Because `torch.SymInt.__round__(self, ndigits=None)` is implemented as `return self`, which is only correct for `ndigits` that is `None` or non-negative, every negative `ndigits` is affected.

```python
import torch

def bucket(x):
    return round(x.shape[0], -1)

def scaled(x):
    return x * round(x.shape[0] * 5, -1)

f, g = (torch.compile(fn, backend="eager", dynamic=True) for fn in (bucket, scaled))
for n in (14, 15, 16, 25):
    x = torch.ones(n)
    print(f"n={n:2d}  round(n, -1): python {bucket(x):3d} compiled {f(x):3d}   x * round(5n, -1): eager {scaled(x)[0].item():5.0f} compiled {g(x)[0].item():5.0f}")
```

```
n=14  round(n, -1): python  10 compiled  14   x * round(5n, -1): eager    70 compiled    70
n=15  round(n, -1): python  20 compiled  15   x * round(5n, -1): eager    80 compiled    75
n=16  round(n, -1): python  20 compiled  16   x * round(5n, -1): eager    80 compiled    80
n=25  round(n, -1): python  20 compiled  25   x * round(5n, -1): eager   120 compiled   125
```

The traced graph for `scaled` is `mul = s77 * 5; mul_1 = l_x_ * mul`: the `round` call is gone.

**Root cause and fix.** `torch/__init__.py`:

```python
class SymInt:
    def __round__(self, ndigits: builtins.int | None = None) -> "SymInt":
        return self
```

For `ndigits < 0` Python rounds to a multiple of `10 ** -ndigits`, half to even. It can be expressed with the existing integer ops, e.g. with `m = 10 ** -ndigits`, `q, r = self // m, self % m` and the result `(q + (2 * r > m or (2 * r == m and q % 2 == 1))) * m`; or, as a smaller step, `__round__` can raise / graph-break for a negative `ndigits` instead of silently returning `self`.

### Error logs

No error and no graph break.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux) and on Linux with 2.14.0 (Python 3.12).
