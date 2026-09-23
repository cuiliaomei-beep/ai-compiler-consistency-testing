<!-- 提交信息（不要复制到 issue 里） -->
# jax-ml/jax — 0920 issue 11（中–高：死循环 / 拒绝服务型；第一个非 PyTorch 目标的发现）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/jax-ml/jax |
| 验证版本 | jax 0.11.2 / jaxlib 0.11.2，CPU，Windows 11，Python 3.14.7，numpy 2.5.3（`jax_enable_x64=True`）；每个输入一个独立进程、60 秒超时（`plan/reports_xtarget/jax_gcd_intmin_hang.py`）。**Linux 已复核**（Kaggle，Linux x86-64，jax 0.11.2，Python 3.12：同一张表，逐行相同，`plan/kaggle_out/xtargetlinux.log`） |
| **提交 issue 链接** | https://github.com/jax-ml/jax/issues/new?template=bug-report.yml |
| 使用的模板 | JAX 的 Bug report 模板（Description / System info） |
| 提交前查重 | 2026-09-20：jax-ml/jax 搜 `gcd`、`gcd hang`、`lcm infinite loop`、`gcd min int`：只有 #11378（closed，gcd 除零保护）与 #12728（closed，lcm int8 溢出与 NumPy 不同），无"不终止"的报告 |
| 证据包 | `plan/reports_xtarget/jax_gcd_intmin_hang.py`；发现来源 `plan/scripts/xtarget_numpy_diff.py --target jax`（扫描在 `ii_gcd`、`ii_lcm` 两项上 1200 秒超时，其余 266 项 jit 与非 jit 一致） |
| 说明 | 这条不是"jit 与 eager 不一致"（两者都挂），而是 JAX 对 NumPy 语义的实现缺陷；它是跨目标扫描的副产品。JAX 的 jit-vs-eager 一致性在 268 个程序上除这条外是干净的（论文里可作为外部效度 + 负结果） |
| 根因 | `jax/_src/numpy/lax_numpy.py`：`gcd` 对 `abs(x1), abs(x2)` 跑 `while_loop`；`abs(INT_MIN)` 仍是负数，循环体末尾的 `where(x1 < x2, x2, x1)` 交换假定两数非负 |

---

## Title

`jnp.gcd` / `jnp.lcm` never terminate when an argument is the minimum integer of its dtype (eager and jit)

## Body

### Description

**Summary.** When one argument is the most negative value of a signed integer dtype and the other is non-zero, `np.gcd` and `np.lcm` return immediately, while `jnp.gcd(x1, x2)` and `jnp.lcm(x1, x2)` never return, both op-by-op and under `jax.jit` (jax 0.11.2, CPU, Windows and Linux). The call cannot be interrupted from Python, so a single such element in an array hangs the whole process. Because `abs(INT_MIN)` is still negative, the Euclidean `while_loop` starts from a negative value and its final ordering step keeps swapping the same two numbers, so every signed dtype is affected for every non-zero partner, in either argument position.

```python
import jax
jax.config.update("jax_enable_x64", True)
import jax.numpy as jnp, numpy as np

x, y = np.array([-128], dtype=np.int8), np.array([6], dtype=np.int8)
print(np.gcd(x, y))                              # [2]
print(jnp.gcd(jnp.asarray(x), jnp.asarray(y)))   # never returns
```

Each line below ran in its own process with a 60 s timeout:

```
jnp.gcd(int8 -128, 6):                 NUMPY [2]                     -> jax: no result after 60 s (killed)
jnp.gcd(int8 6, -128):                 NUMPY [2]                     -> jax: no result after 60 s (killed)
jnp.gcd(int8 -128, 0):                 NUMPY [-128]                  RESULT [-128]
jnp.gcd(int8 -127, 6):                 NUMPY [1]                     RESULT [1]
jnp.gcd(int32 -2147483648, 6):         NUMPY [2]                     -> jax: no result after 60 s (killed)
jnp.gcd(int64 -9223372036854775808, 6): NUMPY [2]                    -> jax: no result after 60 s (killed)
jnp.gcd(int64 6, -9223372036854775808): NUMPY [2]                    -> jax: no result after 60 s (killed)
jnp.lcm(int32 -2147483648, 6):         NUMPY [-2147483648]           -> jax: no result after 60 s (killed)
jnp.lcm(int64 6, -9223372036854775808): NUMPY [-9223372036854775808] -> jax: no result after 60 s (killed)
jnp.gcd(int32 12, 18):                 NUMPY [6]                     RESULT [6]
```

**Cause.** In `jax/_src/numpy/lax_numpy.py`, `gcd` runs

```python
gcd, _ = control_flow.while_loop(_gcd_cond_fn, _gcd_body_fn, (ufuncs.abs(x1), ufuncs.abs(x2)))

def _gcd_body_fn(xs):
  x1, x2 = xs
  x1, x2 = (where(x2 != 0, x2, x1), where(x2 != 0, lax.rem(x1, x2), lax._const(x2, 0)))
  return (where(x1 < x2, x2, x1), where(x1 < x2, x1, x2))
```

`abs(INT_MIN)` is `INT_MIN`, so a negative value enters the loop. For `(-128, 6)`: `rem(-128, 6) = -2`, then `rem(6, -2) = 0` gives the state `(-2, 0)`; the final ordering step sees `-2 < 0` and swaps it to `(0, -2)`; `x2 != 0` again, the body produces `(-2, 0)`, and the two states alternate forever. `lcm` calls `gcd`.

**Possible fix.** Run the loop on unsigned magnitudes (`abs(x).astype(unsigned dtype)`, which represents `|INT_MIN|` exactly) and convert back at the end, or skip the ordering swap when the new `x2` is zero. With the first option `jnp.gcd(-128, 6)` returns `2` like NumPy.

Found with a differential sweep that runs 268 NumPy-style programs on integer and floating-point edge values under `jax.jit` and with `jax.disable_jit()`; every other program agreed between the two modes.

### System info (python version, jaxlib version, accelerator, etc.)

```
jax:    0.11.2
jaxlib: 0.11.2
numpy:  2.5.3
python: 3.14.7 (tags/v3.14.7:823f032, Aug  5 2026, 10:51:32) [MSC v.1944 64 bit (AMD64)]
device info: cpu-1, 1 local devices
process_count: 1
platform: Windows 11 (10.0.26200), AMD64
```

The same ten probes give the same result on Linux x86-64 (jax 0.11.2, Python 3.12, CPU).
