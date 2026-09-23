<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 16（中：`capture_scalar_outputs=True` 下，`loss.item()` 的 NaN 自比较在追踪期被折成常量）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；需要 `torch._dynamo.config.capture_scalar_outputs = True`（非默认；#157499 正在尝试把它改成默认，所以这条会变得更重要）；Linux 复核（Kaggle `tcc-symintlinux`，`plan/kaggle_out/symintlinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921（Python 3.12）输出逐字相同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 提交前查重 | 2026-09-21：`SymFloat nan`、`unbacked float nan item compile`、`capture_scalar_outputs nan`、`SymFloat nan equality self`、`symfloat x != x nan inductor`：无同报告。相关但不同：#158087（open，`int(torch.tensor(nan))` 编译后不抛 ValueError，被认为小众）——本条是**分支走错 / 值算错**，不是异常对等 |
| 证据包 | `plan/reports_symint/nan_self_compare.py`（11 种写法 × 3 后端 × {1.0, nan, inf}）；发现来源 `plan/scripts/symint_arith_diff.py`（用例 `f:self_eq`） |
| 触发条件（已隔离） | 标量来自 `tensor.item()`（unbacked SymFloat）；用它自己和自己比较 / 相减 / 乘 0。`math.isnan(v)` 是对的（可作为规避办法） |
| 分层 | `if v != v:` 分支：三个后端都错（追踪期由 SymPy 决定分支）；`v != v` 作为返回值、`max(v, 0.0)`：只有 Inductor 错；`v - v`、`v * 0`：aot_eager 与 Inductor 错 |
| 建议标签 | oncall: pt2, module: dynamic shapes, module: NaNs and Infs, module: correctness (silent) |

---

## Title

[dynamic shapes] With `capture_scalar_outputs=True`, the NaN check `v != v` on `v = loss.item()` is folded to `False` at trace time: a "skip this step if the loss is NaN" branch is never taken (all backends); `v - v` and `v * 0` fold to `0.0`

## Body

### 🐛 Describe the bug

**Summary.** With `torch._dynamo.config.capture_scalar_outputs = True`, `v = loss.item()` is an unbacked SymFloat and the self-comparison `v != v` is simplified to `False` while tracing, so for a NaN loss eager takes the `if v != v:` branch and the compiled function takes the other one on every backend (torch 2.14.0 and nightly). A training step that skips the update when the loss is NaN, written with the standard `x != x` idiom, applies the NaN update after compilation, with no error and no recompilation. Because the symbol is simplified as a finite real rather than as an IEEE float, `v != v` becomes false and `v - v` and `v * 0` become `0`, so every simplification that does not hold for NaN or infinity is affected, while `math.isnan(v)` stays correct.

```python
import math
import torch

torch._dynamo.config.capture_scalar_outputs = True

def step(loss, param):
    v = loss.item()
    if v != v:                      # standard NaN check: skip the update
        return param
    return param - 0.1 * v

def step_isnan(loss, param):
    v = loss.item()
    if math.isnan(v):
        return param
    return param - 0.1 * v

param, nan = torch.ones(2), torch.tensor(float("nan"))
for name, fn in (("v != v", step), ("math.isnan(v)", step_isnan)):
    print(f"{name:14s} eager {fn(nan, param).tolist()}", end="")
    for backend in ("eager", "aot_eager", "inductor"):
        torch._dynamo.reset()
        print(f"   {backend} {torch.compile(fn, backend=backend)(nan, param).tolist()}", end="")
    print()

sub = lambda t: t.item() - t.item()
torch._dynamo.reset()
print("v - v for v = inf:  eager", sub(torch.tensor(float("inf"))), "  inductor", torch.compile(sub)(torch.tensor(float("inf"))))
```

```
v != v         eager [1.0, 1.0]   eager [nan, nan]   aot_eager [nan, nan]   inductor [nan, nan]
math.isnan(v)  eager [1.0, 1.0]   eager [1.0, 1.0]   aot_eager [1.0, 1.0]   inductor [1.0, 1.0]
v - v for v = inf:  eager nan   inductor 0.0
```

Other forms from the same family (Inductor): `v != v` returned as a value is `False` for NaN, `v == v` is `True`, `torch.ones(2) * (v == v)` is `[1., 1.]` instead of `[0., 0.]`, `max(v, 0.0)` and `min(v, 0.0)` return `0.0` for NaN where Python returns `nan`, and `v * 0` is `0.0` for NaN and infinity.

**Possible fix.** The relational and arithmetic simplifications are valid for finite reals only. Options, from narrow to broad: special-case identical operands in `SymFloat.__eq__` / `__ne__` (and the `sym_node` handlers behind them) so that `v != v` is traced as `isnan(v)` rather than handed to SymPy; create unbacked float symbols without the `real=True` / finiteness assumptions so that `Ne(v, v)`, `v - v` and `0 * v` are not reduced; or, when a simplification of a float expression relies on finiteness, record a runtime assertion (`torch._check(math.isfinite(v))`) so that the NaN case fails loudly instead of taking the wrong branch.

### Error logs

No error, no graph break, no recompilation.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux) and on Linux with 2.14.0 (Python 3.12).
