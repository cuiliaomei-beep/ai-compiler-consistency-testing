<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 03 条：在 #143649 下的**评论稿**（整数 `div(rounding_mode="trunc")` 除零仍然让进程崩溃）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/143649 （"Floating Point Exception (core dumped) when running floordiv/remainder/fmod under torch.compile"，2024-12-20，open） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/143649#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | issue 处于 open、未锁定（2026-09-21 核对），任何登录用户都能评论。① 登录 GitHub 后打开上面的提交网址（`#new_comment_field` 会直接跳到页面最底部的评论框；没跳的话手动滚到底，找 “Add a comment”）；② 评论框保持在 **Write** 页签，把本文件 `## Comment` 标题**下面**到文件末尾的全部内容原样粘贴进去（不要带 `## Comment` 这一行，也不要带上面这张表）；③ 点 **Preview** 看一眼：代码块、输出块、行内代码都应正常渲染；④ 点绿色的 **Comment** 按钮。评论没有标题、标签、模板字段，不需要填别的；⑤ 发出后点评论右上角的时间戳，复制地址栏里形如 `…/issues/NNNN#issuecomment-XXXXXXXX` 的链接，填到 `README.md` 对应行的“状态”列。 |
| 为什么是评论 | 同一类缺陷、同一个修复位置。原 issue 点名的 `floor_divide` / `remainder` / `fmod` 在 2.14.0 里已经有保护（`inductor_cpu_integer_div_error` 标志 + `floor_divide_integral` 等辅助函数），**漏了 `truncdiv`**；相关 PR #178591（open）、#186021（closed 未合入）都提到要一起改 truncdiv，但目前发布版与 nightly 都还没有 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，进程退出码 `0xC0000094` = STATUS_INTEGER_DIVIDE_BY_ZERO）；`aot_eager` 与 eager 一样抛 `RuntimeError: ZeroDivisionError`。Linux 复核（Kaggle `tcc-safetylinux`，`plan/kaggle_out/safetylinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921 上 `trunc` 一行同样是进程死亡（返回码 -8 = SIGFPE），另两行正常抛错 |
| 证据包 | `plan/reports_surgery/int_div_zero_crash.py`（14 种 算子×dtype × 长度 40/5 × 三个后端，逐用例独立进程）；发现来源 `plan/scripts/model_surgery_diff.py`（10.4 保护机制，用例 `int_div_trunc_by_zero`，隔离运行时子进程崩溃被记为 CRASH） |
| 触发条件（已隔离） | `torch.div(a, b, rounding_mode="trunc")`（含 `a.div_(b, rounding_mode="trunc")`）、整数 dtype（int8/16/32/64、uint8 全中）、除数张量里有 0；向量主体、标量尾部、长度 5 都崩。`//`、`%`、`fmod` 正常抛错 |
| 第二条路径 | 符号尺寸表达式：`torch.full((2,), x.shape[0] % (y.shape[0] - 20))`，`dynamic=True`，y 长度为 20 时 Inductor 进程崩溃（eager / `backend="eager"` 抛 ZeroDivisionError）；直接返回该整数则正常抛错。证据 `plan/reports_symint/symint_mod_zero_crash.py`（4 种写法 × mark_dynamic 与否 × 2 后端，逐用例独立进程） |
| 根因 | `torch/_inductor/codegen/cpp.py`：`CppOverrides.truncdiv` 返回 `f"{a} / {b}"`，`CppVecOverrides.truncdiv` 返回向量 `a / b`；而 `floordiv` 走的是带除零检查的 `floor_divide_integral(...)` |

---

## Comment

On 2.14.0 and nightly (2.15.0.dev20260911) the three ops named in this issue are handled: `floor_divide`, `remainder` and `fmod` with an integer zero divisor now raise `RuntimeError: ZeroDivisionError` from the compiled kernel, through `inductor_cpu_integer_div_error`. Integer **`torch.div(..., rounding_mode="trunc")`** was left out and still takes the whole process down (Windows: exit code `0xC0000094`, integer divide by zero; no Python exception, so `try/except` cannot catch it):

```python
import subprocess, sys

child = r'''
import torch
op = {"floor": lambda a, b: a // b, "trunc": lambda a, b: torch.div(a, b, rounding_mode="trunc"), "remainder": lambda a, b: a % b}[__import__("sys").argv[1]]
a = torch.arange(1, 9, dtype=torch.int32); b = torch.ones(8, dtype=torch.int32); b[3] = 0
try:
    torch.compile(op)(a, b)
except RuntimeError as e:
    print("raised RuntimeError, ZeroDivisionError in message:", "ZeroDivisionError" in str(e))
'''
for name in ("floor", "remainder", "trunc"):
    r = subprocess.run([sys.executable, "-c", child, name], capture_output=True, text=True)
    print(f"{name:10s}", r.stdout.strip() or f"process died, return code {r.returncode & 0xFFFFFFFF:#x}")
```

```
floor      raised RuntimeError, ZeroDivisionError in message: True
remainder  raised RuntimeError, ZeroDivisionError in message: True
trunc      process died, return code 0xc0000094
```

On Linux the child dies with SIGFPE (return code -8), on 2.14.0 and on nightly 2.15.0.dev20260921. Eager and `backend="aot_eager"` raise `RuntimeError: ZeroDivisionError` for all three. It happens for every integer dtype (int8/16/32/64, uint8), in the vectorized body and in the scalar tail.

The cause is in `torch/_inductor/codegen/cpp.py`: `CppOverrides.truncdiv` still returns the raw expression `f"{a} / {b}"` and `CppVecOverrides.truncdiv` the raw vector division, whereas `floordiv` goes through `floor_divide_integral(...)`, which checks the divisor and calls `inductor_cpu_note_integer_div_by_zero()`. A `trunc_divide_integral` helper next to `floor_divide_integral` in `cpp_prefix.h` (scalar and `Vectorized<T>` overloads, same placeholder-and-flag scheme), used by both `truncdiv` overrides, would close the gap; #178591 and #186021 both contain this change but neither has landed.

A second unguarded path, found with symbolic sizes: under `dynamic=True`, a Python-level `%` on sizes that reaches a kernel is printed as a raw C++ `%` as well. `torch.compile(lambda x, y: torch.full((2,), x.shape[0] % (y.shape[0] - 20)), dynamic=True)` returns the right values for `y` of length 25 and 22 and kills the process (`0xC0000094`) when `y` has length 20, where eager and `backend="eager"` raise Python's `ZeroDivisionError`; returning the integer itself instead of putting it into a tensor raises correctly.
