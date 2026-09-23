<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 19（中：编译 NumPy 代码的 dtype / 形状 / 溢出语义不同）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（numpy 2.5.2）与 nightly 2.15.0.dev20260911+cpu（numpy 2.5.3），Windows，`backend="eager"` |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 同 02；另查 `np.cumsum torch.compile dtype`、`torch._numpy median`、`numpy dynamo uint16`：无同报告。`torch._dynamo.config.numpy_default_float` 默认为 `"float64"`，所以 `int8 / int8 -> float32` 不是配置造成的 |
| 证据包 | `plan/reports_xtarget/dynamo_numpy_semantics.py`；`plan/results/xtarget/dynamo.jsonl` |
| 建议标签 | oncall: pt2, module: dynamo, module: numpy |
| 备注 | 与 02 分开报：02 是"值错"，这里是"dtype / 形状 / 提升规则不同"；其中 `cumsum` / `cumprod` 因为不提升会**静默溢出**，是本条里最重的 |

---

## Title

[dynamo][numpy] dtype and shape divergences of NumPy code under `torch.compile`: `np.cumsum(int8)` overflows in int8, `np.square(int8)` returns float64, `np.median` returns shape `(1,)`, `np.any` returns uint8, uint16/32/64 arithmetic raises

## Body

### 🐛 Describe the bug

**Summary.** NumPy code compiled with `torch.compile` does not follow NumPy's result-type and result-shape rules in several common functions: `np.cumsum` / `np.cumprod` of an int8 array stay int8 and overflow where NumPy accumulates in int64, `np.square` / `np.reciprocal` of an integer array return float64, `int8 / int8` returns float32, `np.sum(uint8)` returns int64, `np.any(uint8)` returns uint8 instead of bool, `np.median` / `np.percentile` / `np.quantile` return shape `(1,)` instead of a scalar, and arithmetic on uint16/uint32/uint64 arrays raises `NotImplementedError` (torch 2.14.0 and nightly, `backend="eager"`). A user sees a running total that silently wraps at 127, a downstream `if result:` that changes behavior, or a function that stops working once compiled. Because these rules are decided inside `torch._numpy` rather than by the backend, every compiled NumPy program that uses small integer dtypes is exposed.

```python
import numpy as np, torch

i8 = np.array([-128, -100, -3, 0, 5, 100, 127], dtype=np.int8)
u8 = np.array([0, 1, 3, 200, 255], dtype=np.uint8)
f4 = np.array([1.5, -1.5, 2.5, -0.5, 8.0], dtype=np.float32)

cases = {
    "np.cumsum(int8)":        (lambda x: np.cumsum(x), i8),
    "np.cumprod(int8)":       (lambda x: np.cumprod(x), i8),
    "np.square(int8)":        (lambda x: np.square(x), i8),
    "np.reciprocal(int8)":    (lambda x: np.reciprocal(x), i8),
    "int8 / int8":            (lambda x: np.true_divide(x, x + (x == 0)), i8),
    "np.sum(uint8)":          (lambda x: np.sum(x), u8),
    "np.any(uint8)":          (lambda x: np.any(x), u8),
    "np.median(float32)":     (lambda x: np.median(x), f4),
    "np.percentile(x, 50)":   (lambda x: np.percentile(x, 50), f4),
    "uint16 + 1":             (lambda x: x.astype(np.uint16) + np.uint16(1), u8),
}
def show(o):
    o = np.asarray(o); return f"{o.dtype}{list(o.shape)} {o.tolist()}"
for name, (fn, arg) in cases.items():
    torch._dynamo.reset()
    try:
        got = show(torch.compile(fn, backend="eager")(arg.copy()))
    except Exception as e:
        got = f"raised {type(e).__name__}: {str(e).splitlines()[0][:70]}"
    print(f"{name}\n  numpy   : {show(fn(arg.copy()))}\n  compiled: {got}")
```

```
np.cumsum(int8)
  numpy   : int64[7] [-128, -228, -231, -231, -226, -126, 1]
  compiled: int8[7] [-128, 28, 25, 25, 30, -126, 1]
np.cumprod(int8)
  numpy   : int64[7] [-128, 12800, -38400, 0, 0, 0, 0]
  compiled: int8[7] [-128, 0, 0, 0, 0, 0, 0]
np.square(int8)
  numpy   : int8[7] [0, 16, 9, 0, 25, 16, 1]
  compiled: float64[7] [16384.0, 10000.0, 9.0, 0.0, 25.0, 10000.0, 16129.0]
np.reciprocal(int8)
  numpy   : int8[7] [0, 0, 0, 0, 0, 0, 0]
  compiled: float64[7] [-0.0078125, -0.01, -0.3333333333333333, inf, 0.2, 0.01, 0.007874015748031496]
int8 / int8
  numpy   : float64[7] [1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0]
  compiled: float32[7] [1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0]
np.sum(uint8)
  numpy   : uint64[] 459
  compiled: int64[] 459
np.any(uint8)
  numpy   : bool[] True
  compiled: uint8[] 1
np.median(float32)
  numpy   : float32[] 1.5
  compiled: float32[1] [1.5]
np.percentile(x, 50)
  numpy   : float32[] 1.5
  compiled: float32[1] [1.5]
uint16 + 1
  numpy   : uint16[5] [1, 2, 4, 201, 256]
  compiled: raised NotImplementedError: "add_stub" not implemented for 'UInt16'
```

`torch._dynamo.config.numpy_default_float` is `"float64"` (the default) in these runs, so the float32 result of `int8 / int8` does not come from that switch.

**Where the rules are decided** (`torch/_numpy`):

- `_reductions_impl.py::cumsum` / `cumprod`: `if dtype is None: dtype = a.dtype`. NumPy applies the same promotion as `sum` / `prod` (small signed integers to the platform `int`, small unsigned to `uint`); reusing the helper that `sum` already uses fixes both.
- `square` and `reciprocal` are listed in `_fp_unary` in `_ufuncs.py` (the list of ufuncs whose integer inputs are cast to the default float, next to `sqrt` / `sin`); NumPy keeps the integer dtype for both, so they belong in the dtype-preserving `_unary` list.
- `median` calls `quantile(a, torch.as_tensor(0.5), ...)`; a 0-d `q` should give a 0-d result, the returned tensor has shape `(1,)`.
- `_reductions_impl.py::any` / `all` return `torch.any(a)`, which keeps uint8 for a uint8 input; NumPy always returns `bool` (`.to(torch.bool)` on the result).
- uint16/32/64: the ops have no CPU kernels; Dynamo could graph-break and run the NumPy call in CPython (as it does for unsupported NumPy functions) instead of raising.

Found by the same cross-target sweep as the companion "wrong values" issue.

### Error logs

Only the last case raises:

```
NotImplementedError: "add_stub" not implemented for 'UInt16'
```

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
