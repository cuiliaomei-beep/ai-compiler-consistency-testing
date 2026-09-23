"""One-off bookkeeping (2026-09-23): draft 13 deleted on the user's instruction (already reported by someone else as #197434, fix PR #197596)."""
import glob
import os
import re

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")

for f in glob.glob(os.path.join(ISSUES, "13-*.md")):
    os.remove(f)
    print("deleted", os.path.basename(f))

readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
row13 = re.search(r"^\| 13 \|.*\n", s, re.M)
if row13:
    s = s.replace(row13.group(0), "")
s = s.replace("→ 13（评论，可选）。", "。").replace(" → 。", "。")
note = "| 大窗口 max_pool（核体积 >25）+ 空间维转置输入 → indices 错、梯度错（原 13 号稿） | **已被他人报告**：#197434（2026-09-17）+ 修复 PR #197596；用户 2026-09-23 指示删除该稿。复现脚本仍在 `plan/reports_layout/max_pool_indices_noncontiguous.py` |\n"
if "原 13 号稿" not in s:
    s = s.replace("\n## 工具（都在 `plan/` 下）", note + "\n## 工具（都在 `plan/` 下）", 1)
    s = s.replace("|\n\n| 大窗口 max_pool", "|\n| 大窗口 max_pool")
open(readme, "w", encoding="utf-8").write(s)

ledger = os.path.join(PLAN, "TO_SUBMIT.md")
t = open(ledger, encoding="utf-8").read()
add = "**台账 43 终态（2026-09-23）**：用户确认已被他人提交（#197434），草稿 13 已删除，不提交。\n\n"
if add not in t:
    t = t.replace("**台账 43 更正（2026-09-21 深夜）**", add + "**台账 43 更正（2026-09-21 深夜）**", 1)
    open(ledger, "w", encoding="utf-8").write(t)

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
m = open(mem, encoding="utf-8").read()
line = "- 2026-09-23: user had draft 13 deleted (max_pool transposed indices; already filed by someone else as #197434 with fix PR #197596). 0920issues/ now holds 22 drafts (01-12, 14-23).\n"
if line not in m:
    open(mem, "w", encoding="utf-8").write(m + line)
idx = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\MEMORY.md"
x = open(idx, encoding="utf-8").read()
open(idx, "w", encoding="utf-8").write(x.replace("plan/tcc: 23 drafts in 0920issues/", "plan/tcc: 22 drafts in 0920issues/ (13 deleted: dup of #197434)"))
print("recorded")
