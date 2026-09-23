"""One-off bookkeeping (2026-09-22 late night): symshape_index_diff finished; draft 20 gained a 4th member."""
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
row20 = re.search(r"^\| 20 \|.*$", s, re.M).group(0)
if "F.pad" not in row20:
    s = s.replace(row20, row20.replace("`aot_eager` 都与 eager 一致；CPU + CUDA",
                                       "④（后补）`F.pad` 负填充裁掉的比输入还多时 eager 报错、Inductor 静默返回全填充值。`aot_eager` 都与 eager 一致；前三项 CPU + CUDA"))
if "symshape_index_diff.py" not in s:
    s = s.rstrip("\n") + "\n| `scripts/symshape_index_diff.py` | 10.5b：112 个“符号整数流进切片 / 下标 / roll / pad / repeat / split / view / arange / 池化参数”的程序 × 12 个长度（让派生整数跨过 0、长度、两倍长度）× 3 后端；111 个一致（负结果），1 个并入 20 号 |\n"
open(readme, "w", encoding="utf-8").write(s)

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**台账 43 更正（2026-09-21 深夜）**",
     "- **符号形状语义 `symshape_index_diff.py`**（10.5b，112 个程序 × 12 个长度 × 3 后端）：111 个一致——负下标、越界切片、负步长报错、roll/repeat/split/chunk/unfold/view/arange/linspace/tril/topk/池化参数在符号尺寸下都与 eager 相同（负结果）；唯一差异 `F.pad(x, (k, -k))` 裁过头（eager 报错、Inductor 返回全填充值）→ 并入草稿 20 第 4 项（`reports_symshape/negative_pad_beyond_input.py`，2.14 + nightly，查重无同报告）。\n\n"
     "**台账 43 更正（2026-09-21 深夜）**")
edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-22 夜）**：",
     "**当前断点（2026-09-22 深夜）**：10.5b `symshape_index_diff.py` 跑完（112 程序，111 一致；`F.pad` 负填充裁过头的校验丢失并入草稿 20 第 4 项）。本轮（09-21 深夜 → 09-22 深夜）新增工具 7 个：`rewrite_precondition_diff`、`cxx_intrinsic_algebra_diff`（+`cxx_algebra_families`、`run_issue_cpp_snippet`）、`host_opt_diff`、`model_surgery_diff`、`symint_arith_diff`、`symshape_index_diff`；新增草稿 15–23（其中 16–18 报给微软），13 降级为评论。没有后台任务在跑。下一步候选：10.6 全 lowering 表 × 边界值、10.7 int32 索引、10.9 缓存键完备性（受“陈旧 alpha”启发）、10.13 后续（maskload/maskstore、真实内核语料扩到归约与 float16）、10.11 ONNX Runtime 适配；论文侧：把跨目标与工具链层的结果写进 RQ5/讨论（目前 paper_tcc 还没反映 0920issues 的任何内容）。\n\n"
     "**历史断点（2026-09-22 夜）**：")
mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
t = open(mem, encoding="utf-8").read()
line = ("- 2026-09-22 late night: scripts/symshape_index_diff.py (112 programs: symbolic ints into slicing / roll / pad / repeat / split / view / arange ...) finished: 111 consistent (negative result), "
        "1 lost validation (F.pad negative pad larger than the dim: eager raises, Inductor returns fill values) folded into draft 20 as item 4. No background jobs left. 23 drafts in 0920issues/ "
        "(15-23 new this round; 16-18 for Microsoft; 13 downgraded to optional comment on #197434). paper_tcc does not yet reflect any 0920issues result. Nothing filed by me.\n")
if line not in t:
    open(mem, "w", encoding="utf-8").write(t + line)
print("recorded")
