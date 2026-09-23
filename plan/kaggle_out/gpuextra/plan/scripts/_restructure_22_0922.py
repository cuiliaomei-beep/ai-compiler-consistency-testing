"""2026-09-22: item 3 of draft 22 (fill_uninitialized_memory under Inductor) is already tracked as pytorch #174386
(closed as completed 2026-05-10, still reproduces on CPU).  Take it out of the #197554 comment and point to the new
comment draft for #174386 instead."""
import glob
import os

ISSUES = os.path.join(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))), "0920issues")
p = glob.glob(os.path.join(ISSUES, "22-*.md"))[0]
s = open(p, encoding="utf-8").read()


def rep(old, new):
    global s
    if old not in s and new in s:
        return
    assert old in s, old[:70]
    s = s.replace(old, new, 1)


rep('    "deterministic mode: empty_like is filled with NaN": (lambda x: torch.empty_like(x), lambda y: bool(y.isnan().all()), lambda: (torch.ones(6),), True),\n'
    '    "deterministic mode: int32 empty is filled with INT_MAX": (lambda x: x.new_empty(4, dtype=torch.int32), lambda y: bool((y == 2**31 - 1).all()), lambda: (torch.ones(6),), True),\n', "")
rep("deterministic mode: empty_like is filled with NaN\n    None       returns True\n    aot_eager  returns True\n    inductor   returns False\n"
    "deterministic mode: int32 empty is filled with INT_MAX\n    None       returns True\n    aot_eager  returns True\n    inductor   returns False\n", "")
rep("Four more members. The first three are of a slightly different kind:", "Three more members. The first two are of a slightly different kind:")
rep("All four behave like eager", "All three behave like eager")
i = s.index("3. **`torch.utils.deterministic.fill_uninitialized_memory`.**")
j = s.index("4. **`F.pad` with a negative pad larger than the dimension.**")
s = s[:i] + "3. " + s[j + 3:]
i = s.index("; (3) when deterministic mode with `fill_uninitialized_memory`")
j = s.index("; (4) check `-pad <= size`")
s = s[:i] + "; (3) check `-pad <= size`" + s[j + len("; (4) check `-pad <= size`"):]
s = s.rstrip("\n") + ("\n\nA fourth loss of the same kind, deterministic mode's `fill_uninitialized_memory` not being honoured for `empty` / `empty_like` / `new_empty` "
                      "under Inductor on CPU, is already tracked as #174386; it still reproduces there, details in my comment on that issue.\n")
rep("| 严重度 |", "| 2026-09-22 调整 | 原第 3 项（确定性模式下 `empty*` 不填充）查重发现已有 #174386（closed completed，但 CPU 上仍复现）→ 从本评论拆出，单独成 24 号评论稿发到 #174386 下；本稿现在是 3 项：inference tensor、`put_`、`F.pad` |\n| 严重度 |")
open(p, "w", encoding="utf-8").write(s)
print("draft 22 restructured")
