"""Bookkeeping 2026-09-22 morning: drafts 23 (new issue) and 24 (comment on #174386); draft 22 lost its item 3; draft 14 cites the open fix PR."""
import glob
import os
import re

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(path, old, new):
    t = open(path, encoding="utf-8").read()
    if new in t:
        return
    assert old in t, (path, old[:50])
    open(path, "w", encoding="utf-8").write(t.replace(old, new, 1))


readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
row22 = re.search(r"^\| 22 \|.*\n", s, re.M).group(0)
if "| 23 |" not in s:
    new22 = row22.replace("Inductor 下丢失的三种“模式类保护”", "Inductor 下丢失的保护（2026-09-22 调整为 3 项：原“确定性模式下 `empty*` 不填充”已有 #174386，拆到 24 号）")
    s = s.replace(row22, new22 +
        "| 23 | pytorch/pytorch | 新 issue | **torch.fx：名为 `nan` / `inf` 的 `forward` 形参遮蔽生成源码里同名的浮点常量**：`symbolic_trace` 后 `torch.where(nan, float(\"nan\"), x)` 得 `[1, 1, 3]` 而不是 `[1, nan, 3]`，`clamp(max=float(\"inf\"))` 的上限变成了名叫 `inf` 的张量；`Interpreter` 正确；与已提交的 #197894 同属“生成源码 ≠ Interpreter 语义”，根因不同（custom builtin 名字只对节点改名、不对形参） | 中–低（静默错值，触发面窄） | 待提交 |\n"
        "| 24 | pytorch/pytorch | **评论**（#174386，已关闭为 completed） | 确定性模式下 `empty` / `empty_like` / `new_empty` 在 Inductor **CPU** 上仍不按文档填充 NaN / 最大整数（原 issue 的复现程序原样失败，2.14.0 + nightly，Win + Linux；CUDA 上浮点已修、整数仍不填）；请求 reopen | 中–低 | 待评论（22 之后） |\n", 1)
howto = "| 22 | https://github.com/pytorch/pytorch/issues/197554 | 同 04 | 在 04 之后单独发一条，不要与 04 合并 |\n"
if howto in s and "| 24 | https://github.com/pytorch/pytorch/issues/174386" not in s:
    s = s.replace(howto, howto + "| 24 | https://github.com/pytorch/pytorch/issues/174386 | closed（completed），未锁定，仍可评论 | 没有 Reopen 按钮，稿子末尾已请维护者 reopen |\n", 1)
    s = s.replace("## 评论稿怎么提交（03、04、14、20、22）", "## 评论稿怎么提交（03、04、14、20、22、24）", 1)
open(readme, "w", encoding="utf-8").write(s)

p14 = glob.glob(os.path.join(ISSUES, "14-*.md"))[0]
t = open(p14, encoding="utf-8").read()
if "#191543" not in t:
    t = t.replace("| 发现来源 |", "| 相关 PR（2026-09-22 查重补充） | #191543（open，2026-07-29，“Fix int8/uint8 min/max vectorized reductions polluted by inactive lanes”，Fixes #191499）：修的是 `amin`/`amax` 的未屏蔽通道；我们评论里的 `argmin`/`argmax` 与 x86 上的表现是否被它覆盖**没有验证过**，所以评论仍有价值，可在评论末尾提醒 PR 作者顺带测 arg-归约 |\n| 发现来源 |", 1)
    open(p14, "w", encoding="utf-8").write(t)

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "| 55 | **torch.fx 代码生成：形参名 `nan` / `inf` 遮蔽同名浮点常量**",
     "**2026-09-22 早**：台账 55 已写成 `0920issues/23-*.md`（2.14 + nightly 逐字验证）。当天查重发现台账 50 的第 3 项（确定性模式下 `empty*` 不填充）= 已关闭的 #174386（2026-05-10 closed completed，PR #174718 仍 open），原复现程序在 2.14.0 与 nightly 的 CPU 上**原样失败** → 从 22 号稿拆出，单独写成 `0920issues/24-*.md`（评论 #174386，请求 reopen）；22 号稿改为 3 项并重新验证。14 号稿补记了 open 的修复 PR #191543。\n\n"
     "| 55 | **torch.fx 代码生成：形参名 `nan` / `inf` 遮蔽同名浮点常量**")
print("recorded")
