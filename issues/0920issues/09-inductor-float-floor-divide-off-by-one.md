<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 09（中–高：静默错值，Python 教科书例子）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，CPU）；Linux 复核（Kaggle，`plan/kaggle_out/intublinux.log`、`intubgpu.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920、**Tesla T4 CUDA 2.14.0+cu130 输出逐字相同**；float32 与 float64 都复现；`aot_eager` 与 eager 一致 → Inductor lowering |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21：`floor_divide inductor float`、`floor division inductor wrong`：无同报告（当晚按根因关键词 `div_rn floor float floordiv inductor` 复查：closed #177740 / PR #177926 是**相反方向**的问题——Triton 近似除法让结果少 1，修法正是引入 `div_rn`；本条是引入 `div_rn` 之后商恰好舍入到整数时多 1）。**相关**：open #184408（CUDA 上 `rounding_mode='trunc'` 差 1，high priority；正文说 floor 路径"已用 div_rn 修好"）——本条说明 floor 路径用 div_rn 之后仍与 eager 不同，方向相反（多 1） |
| 证据包 | `plan/reports_intub/floor_divide_python_example.py`；发现来源 `plan/scripts/int_ub_sweep.py`（`float_binary:floor_divide`、`float_binary:div_floor`，1600 对边界值里 40 对不同） |
| 根因 | `torch/_inductor/lowering.py::_floor_div_floating`：`floor(div_rn(a, b))`。eager（`c10::div_floor_floating`）与 `_refs` 都是 fmod 算法 `(a - fmod(a, b)) / b`。当真商略小于整数、而四舍五入后的浮点商恰为该整数时，`floor(round(a/b))` 多 1 |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent) |

---

## Title

[inductor] Floating-point floor division is off by one: `torch.compile` makes `1.0 // 0.1` return `10.0` (eager and Python: `9.0`)

## Body

### 🐛 Describe the bug

**Summary.** `a // b`, `torch.floor_divide` and `torch.div(..., rounding_mode="floor")` on floating-point tensors do not agree between eager and Inductor when the exact quotient lies just below an integer: for `1.0 // 0.1` eager returns `9.0`, as Python does, and Inductor returns `10.0`; the same happens for `0.5 // 0.1` and `6.0 // 0.2` in float32 and float64 (torch 2.14.0 and nightly, CPU and CUDA, Windows and Linux; `aot_eager` matches eager). A user who bins values or computes indices with `//` gets a bucket that is one too high after adding `torch.compile`, with no warning. Because Inductor lowers floating floor division to `floor(div_rn(a, b))` rather than to eager's fmod-based algorithm, every quotient that rounds up to an integer in floating point is affected, on every device that shares this lowering.

```python
import torch

print("python   :", 1.0 // 0.1, 0.5 // 0.1, 6.0 // 0.2)
for dtype in (torch.float32, torch.float64):
    a = torch.tensor([1.0, 0.5, 6.0, 1.0], dtype=dtype)
    b = torch.tensor([0.1, 0.1, 0.2, 1 / 3], dtype=dtype)
    for name, fn in (("a // b", lambda a, b: a // b), ("div(floor)", lambda a, b: torch.div(a, b, rounding_mode="floor"))):
        torch._dynamo.reset()
        print(f"{str(dtype):14s} {name:11s} eager {fn(a, b).tolist()}  inductor {torch.compile(fn)(a, b).tolist()}")
```

```
python   : 9.0 4.0 29.0
torch.float32  a // b      eager [9.0, 4.0, 29.0, 2.0]  inductor [10.0, 5.0, 30.0, 3.0]
torch.float32  div(floor)  eager [9.0, 4.0, 29.0, 2.0]  inductor [10.0, 5.0, 30.0, 3.0]
torch.float64  a // b      eager [9.0, 4.0, 29.0, 3.0]  inductor [10.0, 5.0, 30.0, 3.0]
torch.float64  div(floor)  eager [9.0, 4.0, 29.0, 3.0]  inductor [10.0, 5.0, 30.0, 3.0]
```

`0.1` is stored as a value slightly larger than one tenth, so the exact quotient `1.0 / 0.1` is slightly below 10 and its floor is 9; the correctly rounded floating-point quotient is exactly `10.0`, and flooring that gives 10.

**Root cause.** `torch/_inductor/lowering.py`:

```python
def _floor_div_floating(a, b):
    ...
    def fn(a, b, nan, neg_one, zero):
        quotient = ops.div_rn(a, b)
        result = ops.floor(quotient)
```

Eager (`c10::div_floor_floating`) and `torch._refs` compute `mod = fmod(a, b); div = (a - mod) / b; ...; floor(div)`, which is exact for these inputs. `cpp_prefix.h` already contains a vector implementation of that algorithm (`div_floor_floating_vec`), so the C++ backend can call it (and the scalar `c10::div_floor_floating`) instead of `floor(div_rn(...))`; for Triton the same fmod-based sequence can be emitted. This is the mirror image of #184408 (truncating division off by one on CUDA): that report notes that the floor path was switched to `div_rn`; `div_rn` fixes quotients that were rounded *down* by an approximate reciprocal, but not quotients whose correctly rounded value is already past the integer.

### Error logs

No error is raised; the values differ as shown above.

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

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), on Linux CPU with 2.14.0, and on CUDA (Tesla T4, 2.14.0+cu130).
