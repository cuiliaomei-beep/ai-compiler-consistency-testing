"""One-off bookkeeping (2026-09-22 night): host_opt_diff and prefix_consistency_sweep finished (negative results); symbolic-modulo crash path."""
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(path, old, new):
    t = open(path, encoding="utf-8").read()
    if new in t:
        return
    assert old in t, (path, old[:50])
    open(path, "w", encoding="utf-8").write(t.replace(old, new, 1))


edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**台账 43 更正（2026-09-21 深夜）**",
     "负结果三条（2026-09-22 夜，可直接写进论文的“干净的轴”）：\n"
     "- **宿主编译器优化档差分 `host_opt_diff.py`**（同一批 Inductor 内核 `/Od` 对 `/O2`，178 个批次 ≈ 94 个一元 + 41 个二元程序 × 10 种 dtype，外加 22×22 个一元复合 × 4 种 dtype）：**只有 `abs(abs(x))`（int8 / int32）逐位不同**，即草稿 16；其余 176 个批次逐位相同。注意灵敏度陷阱：把 33 个程序并进一个编译函数时连 abs(abs) 都测不出来（MSVC 在大函数里不做这个折叠），所以每个编译函数只放 4 个程序。\n"
     "- **前缀一致性 `prefix_consistency_sweep.py`**（135 个逐点程序 × 10 dtype × 动态/静态长度 × 对齐 × 线程数）：21 个程序有差异，全部是超越函数的向量主体与标量尾部用了不同的数学实现，最大 7.6 ε（gelu float32），典型 ≤ 1 ε；没有对齐或线程数造成的差异 → 不报。\n"
     "- **符号尺寸 `%` 的除零**：`torch.full((2,), x.shape[0] % (y.shape[0] - 20))` 在 y 长度为 20 时 Inductor 进程崩溃（Python/`backend=\"eager\"` 抛 ZeroDivisionError）→ 已并入草稿 19 作为第二条未保护路径（`reports_symint/symint_mod_zero_crash.py`）。\n\n"
     "**台账 43 更正（2026-09-21 深夜）**")
edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-22 晚）**：",
     "**当前断点（2026-09-22 夜）**：`host_opt_diff.py`（178 批）与 10.2 前缀扫描（135 程序）都跑完：前者只重新发现 abs(abs)（草稿 16），后者最大 7.6 ε，均记为负结果（`TO_SUBMIT.md`）。草稿 19 追加了“符号尺寸 `%` 除零崩进程”的第二条路径；19、21–23 的 Linux 复核已写回。后台在跑 10.5b `scripts/symshape_index_diff.py --isolate`（112 个“符号整数流进切片/形状算子”的程序 × 12 个长度 × 3 后端；`results/symshape/cases.jsonl`，`--report` 看结果）。下一步：分诊 symshape；10.6 全 lowering 表；10.7 int32 索引；10.9 缓存键完备性。\n\n"
     "**历史断点（2026-09-22 晚）**：")
mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
t = open(mem, encoding="utf-8").read()
line = ("- 2026-09-22 night: negative results recorded in TO_SUBMIT.md: host_opt_diff (178 batches of real Inductor kernels, /Od vs /O2) differs only for abs(abs(x)) int8/int32 (= draft 16); "
        "prefix_consistency_sweep (135 programs) max 7.6 eps, transcendental vector-vs-tail only. Draft 19 gained a second path (symbolic size `%` by zero kills the process under Inductor). "
        "Drafts 19, 21-23 re-verified on Linux (2.14 + nightly 0921). Running: scripts/symshape_index_diff.py --isolate (results/symshape/).\n")
if line not in t:
    open(mem, "w", encoding="utf-8").write(t + line)
print("recorded")
