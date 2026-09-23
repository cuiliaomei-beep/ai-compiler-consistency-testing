"""One-off bookkeeping (2026-09-22 night): Linux re-check written back to drafts 19, 21-23; symbolic-modulo crash added to draft 19."""
import glob
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(pattern, old, new):
    path = glob.glob(os.path.join(ISSUES, pattern))[0]
    s = open(path, encoding="utf-8").read()
    if new in s:
        return
    assert old in s, (pattern, old[:50])
    open(path, "w", encoding="utf-8").write(s.replace(old, new, 1))


L = "Linux 复核（Kaggle `tcc-symintlinux`，`plan/kaggle_out/symintlinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921（Python 3.12）输出逐字相同"
for pat in ("21-*.md", "22-*.md", "23-*.md"):
    edit(pat, "Linux 复核见 Kaggle `tcc-symintlinux`（结果出来后补一句）", L)
    edit(pat, "Same output on nightly 2.15.0.dev20260911+cpu.",
         "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux) and on Linux with 2.14.0 (Python 3.12).")

edit("19-*.md", "Linux 复核见 Kaggle `tcc-safetylinux`（结果出来后补一句；预期 SIGFPE）",
     "Linux 复核（Kaggle `tcc-safetylinux`，`plan/kaggle_out/safetylinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921 上 `trunc` 一行同样是进程死亡（返回码 -8 = SIGFPE），另两行正常抛错")
edit("19-*.md", "Eager and `backend=\"aot_eager\"` raise `RuntimeError: ZeroDivisionError` for all three.",
     "On Linux the child dies with SIGFPE (return code -8), on 2.14.0 and on nightly 2.15.0.dev20260921. Eager and `backend=\"aot_eager\"` raise `RuntimeError: ZeroDivisionError` for all three.")
edit("19-*.md", "would close the gap; #178591 and #186021 both contain this change but neither has landed.",
     "would close the gap; #178591 and #186021 both contain this change but neither has landed.\n\n"
     "A second unguarded path, found with symbolic sizes: under `dynamic=True`, a Python-level `%` on sizes that reaches a kernel is printed as a raw C++ `%` as well. "
     "`torch.compile(lambda x, y: torch.full((2,), x.shape[0] % (y.shape[0] - 20)), dynamic=True)` returns the right values for `y` of length 25 and 22 and kills the process "
     "(`0xC0000094`) when `y` has length 20, where eager and `backend=\"eager\"` raise Python's `ZeroDivisionError`; returning the integer itself instead of putting it into a tensor raises correctly.")
edit("19-*.md", "| 根因 |",
     "| 第二条路径 | 符号尺寸表达式：`torch.full((2,), x.shape[0] % (y.shape[0] - 20))`，`dynamic=True`，y 长度为 20 时 Inductor 进程崩溃（eager / `backend=\"eager\"` 抛 ZeroDivisionError）；直接返回该整数则正常抛错。证据 `plan/reports_symint/symint_mod_zero_crash.py`（4 种写法 × mark_dynamic 与否 × 2 后端，逐用例独立进程） |\n| 根因 |")
print("ok")
