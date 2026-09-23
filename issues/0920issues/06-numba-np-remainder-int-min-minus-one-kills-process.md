<!-- 提交信息（不要复制到 issue 里） -->
# numba/numba — 0920 issue 06（高：进程被硬件异常杀死）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/numba/numba |
| 验证版本 | numba 0.67.0 / llvmlite 0.49.0 / numpy 2.5.3，Python 3.14.7，Windows 11 x64；每个 (表达式, dtype, 模式) 一个独立进程（`plan/reports_xtarget/numba_intmin_remainder_crash.py`）。**Linux 已复核**（Kaggle，Linux x86-64，numba 0.67.0，Python 3.12：同一张表，崩溃处子进程退出码 -8 = SIGFPE，`plan/kaggle_out/xtargetlinux.log`） |
| **提交 issue 链接** | https://github.com/numba/numba/issues/new?template=Bug_report.md （模板文件名首字母大写；打不开就用 https://github.com/numba/numba/issues/new/choose 选 “Bug report”） |
| 使用的模板 | Numba 的 "Bug report" 模板（勾选两项 checklist + 复现） |
| 提交前查重 | 2026-09-20：numba/numba 搜 `remainder crash`、`INT_MIN`、`integer overflow division crash`、`remainder -1`、`np.remainder integer`、`np.mod minimum integer`：无同报告。相关但不同：#8742（open，浮点 floor_divide/remainder/divmod 不一致）、#8574（open，`np.fmod` 对负数/整数结果错——我们也撞到了，**是重复，不报**） |
| 证据包 | `plan/reports_xtarget/numba_intmin_remainder_crash.py`；发现来源 `plan/scripts/xtarget_numpy_diff.py --target numba`（`ii_remainder`、`ii_mod`、`ii_divmod0`、`ii_remainder_zero` 四项子进程退出码 0xC0000095） |
| 根因 | `numba/np/npyfuncs.py::np_int_srem_impl` 只防了除数为 0，没有防 `(MIN_INT, -1)`；同文件的 `np_int_sdiv_impl` 防了（`could_cause_sigfpe`），但返回 0 而 NumPy 返回 `MIN_INT` |
| 同一次扫描里**不报**的 Numba 差异 | 已有 issue：`np.fmod` 整数结果错 #8574、`np.median` 含 NaN #10095、`np.clip` NaN 边界 #9995；文档化的偏离：标量整数提升为 int64、无越界检查、`error_model='python'` 的除零异常、float16 不支持、NEP 50 标量提升 |

---

## Title

`np.remainder` / `np.mod` / `np.divmod` on signed integer arrays kill the process for `MIN_INT % -1` in nopython mode (NumPy returns 0); `np.floor_divide(MIN_INT, -1)` returns 0 instead of `MIN_INT`

## Body

- [x] I have tried using the latest released version of Numba (most recent is visible in the release notes).
- [x] I have included a self contained code sample to reproduce the problem.

### Reporting a bug

**Summary.** For signed integer arrays that contain the pair `(iinfo(dtype).min, -1)`, NumPy's `np.remainder`, `np.mod`, and `np.divmod` return `0`, while the same ufuncs inside an `@njit` function terminate the interpreter: there is no Python exception, the process exits with status `0xC0000095` (integer overflow) on Windows and is killed by `SIGFPE`, the hardware trap of `idiv`, on Linux (Numba 0.67.0). A single such element in the data takes down the whole process, a server or a notebook kernel included, and `try/except` cannot catch it. Because the Python operator `%` and `np.floor_divide` inside the same jitted function return `0`, only the ufunc remainder path lacks the guard for this operand pair, and all four signed dtypes, int8 and int16 included, are affected.

```python
import numpy as np, numba

@numba.njit
def rem(a, b):
    return np.remainder(a, b)

a = np.array([np.iinfo(np.int32).min, 7], dtype=np.int32)
b = np.array([-1, -1], dtype=np.int32)
print(np.remainder(a, b))     # [0 0]
print(rem(a, b))              # process dies here, exit status 0xC0000095 on Windows
```

One process per cell (`a = [iinfo.min, 7]`, `b = [-1, -1]`):

| expression in the jitted function | NumPy | `@njit`, int8 / int16 / int32 / int64 |
|---|---|---|
| `np.remainder(a, b)` | `[0, 0]` | **process killed (0xC0000095)** for all four dtypes |
| `np.mod(a, b)` | `[0, 0]` | **process killed** for all four dtypes |
| `np.divmod(a, b)[1]` | `[0, 0]` | **process killed** for all four dtypes |
| `a % b` | `[0, 0]` | `[0, 0]` |
| `np.floor_divide(a, b)` | `[MIN_INT, -7]` | `[0, -7]` |
| `a // b` | `[MIN_INT, -7]` | `[MIN_INT, -7]` for int8/16/32, `[0, -7]` for int64 |

**Cause.** `numba/np/npyfuncs.py::np_int_srem_impl` guards only against a zero denominator:

```python
den_not_zero = builder.icmp_unsigned('!=', ZERO, den)
with cgutils.if_unlikely(builder, den_not_zero):
    mod = builder.srem(num, den)          # traps for (MIN_INT, -1)
```

`np_int_sdiv_impl`, a few lines above, already contains the missing test (`could_cause_sigfpe = den == -1 and num == MIN_INT`) but maps that case to `0`, whereas NumPy's integer division wraps to `MIN_INT`.

**Possible fix.** Reuse the `could_cause_sigfpe` predicate in `np_int_srem_impl` and return `0` for it (what NumPy and the `%` operator return); in `np_int_sdiv_impl`, return `MIN_INT` for that case and keep `0` only for a zero denominator. `a // b` for int64 (`numba/cpython/numbers.py::int_divmod_signed`) returns `0` as well and could follow the same rule.

Found with a differential sweep that compares 268 small NumPy programs on integer edge values between CPython + NumPy and `@njit`; each program runs in its own process, which is how the crash became visible.

Environment: numba 0.67.0, llvmlite 0.49.0, numpy 2.5.3, Python 3.14.7, Windows 11 (10.0.26200) x64, Intel Core i9-11900T. The table is identical on Linux x86-64 (numba 0.67.0, numpy 2.5.3, Python 3.12), where the three failing rows die with SIGFPE.
