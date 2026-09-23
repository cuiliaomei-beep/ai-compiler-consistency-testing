<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 12（中–高：编译 NumPy 代码得到错误数值）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（numpy 2.5.2）与 nightly 2.15.0.dev20260911+cpu（numpy 2.5.3），Windows；`backend="eager"` 即可复现（问题在 Dynamo 把 numpy 调用翻译成 `torch._numpy` 这一层，与 Inductor 无关） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-20：`torch._numpy`（open：#195978 geomspace、#194866 arange、#139281 astype、#141258 numpy 标量——都不是这几条）、`np.fix compile`、`np.cbrt compile`、`np.clip torch.compile`：无同报告。维护者接受这类报告（#195978 / #194866 同类） |
| 证据包 | `plan/reports_xtarget/dynamo_numpy_semantics.py`（独立脚本，21 个用例）；发现来源 `plan/scripts/xtarget_numpy_diff.py --target dynamo`（268 个 NumPy 风格程序，参照 = 真 NumPy） |
| 建议标签 | oncall: pt2, module: dynamo, module: numpy, module: correctness (silent) |
| 根因 | `torch/_numpy/_unary_ufuncs_impl.py`: `round as fix`（第 40 行）；`cbrt = torch.pow(x, 1/3)`（第 55 行）。`torch/_numpy/_funcs_impl.py` 第 984 行 `clip` 直接 `torch.clamp(a, min, max)` |

---

## Title

[dynamo][numpy] NumPy code under `torch.compile` returns wrong values: `np.fix` rounds instead of truncating, `np.cbrt` is NaN for negatives, `np.clip` with out-of-range Python bounds wraps, `np.sign` / `np.heaviside` drop NaN

## Body

### 🐛 Describe the bug

**Summary.** Five NumPy functions do not agree between CPython + NumPy and the same code under `torch.compile`, where Dynamo translates them to `torch._numpy`: `np.fix(1.5)` returns `2.0` instead of `1.0`, `np.cbrt(-8.0)` returns `nan` instead of `-2.0`, `np.clip(int8_array, -1000, 1000)` returns `-24` for every element, `np.clip(uint8_array, -2, 5)` returns `5` for every element, and `np.sign(nan)` / `np.heaviside(nan, h)` return `0.0` instead of `nan` (torch 2.14.0 and nightly; `backend="eager"` is enough). A user who decorates a working NumPy function with `torch.compile` gets different numbers with no warning and no graph break. Because the divergence is decided inside `torch._numpy` (`fix` is an alias of `torch.round`, `cbrt` is `torch.pow(x, 1/3)`, `clip` forwards out-of-range Python integers to `torch.clamp`) rather than by the backend, every compiled NumPy program that calls these functions is affected.

```python
import numpy as np, torch

f4 = np.array([1.5, -1.5, 2.5, -0.5, 8.0, -8.0, np.nan], dtype=np.float32)
i8 = np.array([-128, -100, -3, 0, 5, 100, 127], dtype=np.int8)
u8 = np.array([0, 1, 3, 200, 255], dtype=np.uint8)

cases = {
    "np.fix":        (lambda x: np.fix(x), f4),
    "np.cbrt":       (lambda x: np.cbrt(x), f4),
    "np.sign":       (lambda x: np.sign(x), f4),
    "np.heaviside":  (lambda x: np.heaviside(x, np.float32(0.5)), f4),
    "np.clip int8":  (lambda x: np.clip(x, -1000, 1000), i8),
    "np.clip uint8": (lambda x: np.clip(x, -2, 5), u8),
}
for name, (fn, arg) in cases.items():
    torch._dynamo.reset()
    print(name, "\n  numpy   :", fn(arg.copy()).tolist(), "\n  compiled:", torch.compile(fn, backend="eager")(arg.copy()).tolist())
```

```
np.fix
  numpy   : [1.0, -1.0, 2.0, -0.0, 8.0, -8.0, nan]
  compiled: [2.0, -2.0, 2.0, -0.0, 8.0, -8.0, nan]
np.cbrt
  numpy   : [1.1447142362594604, -1.1447142362594604, 1.3572087287902832, -0.7937005162239075, 2.0, -2.0, nan]
  compiled: [1.1447142362594604, nan, 1.3572088479995728, nan, 2.0, nan, nan]
np.sign
  numpy   : [1.0, -1.0, 1.0, -1.0, 1.0, -1.0, nan]
  compiled: [1.0, -1.0, 1.0, -1.0, 1.0, -1.0, 0.0]
np.heaviside
  numpy   : [1.0, 0.0, 1.0, 0.0, 1.0, 0.0, nan]
  compiled: [1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0]
np.clip int8
  numpy   : [-128, -100, -3, 0, 5, 100, 127]
  compiled: [-24, -24, -24, -24, -24, -24, -24]
np.clip uint8
  numpy   : [0, 1, 3, 5, 5]
  compiled: [5, 5, 5, 5, 5]
```

**Root cause and possible fixes** (all in `torch/_numpy`):

| function | current implementation | fix |
|---|---|---|
| `fix` | `_unary_ufuncs_impl.py`: `from torch import ... round as fix` | `fix = torch.trunc` (NumPy: round towards zero) |
| `cbrt` | `torch.pow(x, 1 / 3)` | `torch.copysign(torch.pow(x.abs(), 1 / 3), x)` |
| `clip` | `torch.clamp(a, min, max)` — a Python bound outside the dtype's range is converted to the array dtype first (`1000 -> int8 -24`, `-2 -> uint8 254`) | clamp Python-scalar bounds to `iinfo(a.dtype)` before calling `torch.clamp` (NumPy 2 treats an out-of-range Python integer bound as "no bound on that side") |
| `sign`, `heaviside` | `torch.sign` / `torch.heaviside`, which map NaN to 0 | `torch.where(x.isnan(), x, torch.sign(x))`, same for `heaviside` |

Found with a cross-target differential that runs 268 small NumPy-style programs on edge-value inputs in CPython + NumPy and under `torch.compile`, and compares dtype, shape, values, NaN pattern, and exceptions. A companion issue lists the dtype and shape divergences found by the same sweep.

### Error logs

No error is raised; the values differ as shown above.

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

Same output on nightly 2.15.0.dev20260911+cpu with numpy 2.5.3.
