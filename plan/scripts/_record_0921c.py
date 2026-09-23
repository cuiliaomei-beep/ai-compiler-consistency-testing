"""One-off bookkeeping (2026-09-21 night): layout/alias sweep results, drafts 13-14, Linux/CUDA re-check of 12-13."""
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(path, old, new, must=True):
    s = open(path, encoding="utf-8").read()
    if new in s:
        return
    if old not in s:
        assert not must, (path, old[:60])
        return
    open(path, "w", encoding="utf-8").write(s.replace(old, new, 1))


L = "Linux 复核（Kaggle `tcc-sidelinux` / `tcc-sidegpu`，`plan/kaggle_out/sidelinux.log`、`sidegpu.log`）"
edit(os.path.join(ISSUES, "12-dynamo-closure-mutation-lost-in-method-of-object-created-in-graph.md"),
     "`backend=\"eager\"` 即可复现 → Dynamo 层，与 AOTAutograd / Inductor 无关 |",
     "`backend=\"eager\"` 即可复现 → Dynamo 层，与 AOTAutograd / Inductor 无关；" + L + "：Linux 上 2.14.0 与 nightly 2.15.0.dev20260920（Python 3.12）输出逐字相同 |")
edit(os.path.join(ISSUES, "12-dynamo-closure-mutation-lost-in-method-of-object-created-in-graph.md"),
     "Same output on nightly 2.15.0.dev20260911+cpu.",
     "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux) and on Linux with 2.14.0 (Python 3.12), so it does not depend on the Python version or the platform.")
edit(os.path.join(ISSUES, "13-inductor-max-pool-large-window-noncontiguous-wrong-indices-and-grad.md"),
     "Linux / CUDA 复核任务见 README（结果出来后补一句） |",
     L + "：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 输出逐字相同；**Tesla T4 CUDA（2.14.0+cu130，Triton）同样错**（k=6 / k=3 两行 indices 与梯度都不同）→ 与设备无关 |")
edit(os.path.join(ISSUES, "13-inductor-max-pool-large-window-noncontiguous-wrong-indices-and-grad.md"),
     "scatters the gradient to those wrong positions (torch 2.14.0 and nightly, CPU).",
     "scatters the gradient to those wrong positions (torch 2.14.0 and nightly; CPU on Windows and Linux, and CUDA).")
edit(os.path.join(ISSUES, "13-inductor-max-pool-large-window-noncontiguous-wrong-indices-and-grad.md"),
     "Same output on nightly 2.15.0.dev20260911+cpu.",
     "Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), on Linux CPU with 2.14.0, and on CUDA (Tesla T4, 2.14.0+cu130): the two large-window rows have wrong indices and a wrong gradient there as well, so the defect is in the shared lowering rather than in the C++ backend.")

edit(os.path.join(ISSUES, "README.md"),
     "\n建议提交顺序：01 → 04（评论）→ 08 → 12 → 06 → 05 → 09 → 07（评论）→ 02 → 03 → 11 → 10（评论）。",
     "| 13 | pytorch/pytorch | 新 issue | **大窗口 max_pool（核体积 >25：2D 核≥6×6、3D 核≥3×3×3）+ 空间维转置的输入 → indices 错、梯度错**（前向值正确）；`nn.MaxPool3d(3, 2)` 接在 `permute` 后面就中招；CPU 与 CUDA、Win 与 Linux、2.14 与 nightly 都复现；根因：窗口内 argmax 的编号按 Inductor 依步长重排后的循环顺序，而偏移→下标换算假定行优先（与已修的 #193751 同类） | **高**（静默错梯度） | 待提交 |\n"
     "| 14 | pytorch/pytorch | 新 issue | **`adaptive_max_pool3d` 对 channels_last_3d 输入在 Inductor 下梯度错**；根因在 eager 的 C++ 内核：`adaptive_max_pool3d_backward`、`fractional_max_pool{2,3}d_backward` 把非连续的 `indices` 当连续内存读（不需要编译器也能复现）；Inductor 把存给反向的 indices 排成 channels_last 才触发 | **高**（静默错梯度；修法一行 `.contiguous()`） | 待提交 |\n"
     "\n建议提交顺序：01 → 13 → 14 → 04（评论）→ 08 → 12 → 06 → 05 → 09 → 07（评论）→ 02 → 03 → 11 → 10（评论）。")

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "副作用差分其余结果（75 例，71 一致）",
     "| 43 | **大窗口 max_pool2d/3d（核体积 >25）+ 空间维转置的输入：indices 错、梯度错**，前向值对；`return_indices=False` 梯度同样错；`nn.MaxPool3d(3,2)` 接 `permute` 即触发 | **待提交（高：静默错梯度）**（7.1 布局/别名扫描 `layout_alias_sweep.py`） | `0920issues/13-*.md`；`reports_layout/max_pool_indices_noncontiguous.py`、`max_pool_fallback_strides.py` | 无同报告；同类已修 #193751（argmax/argmin 对 channels_last 错位） | `should_fallback_max_pool_with_indices`（>25）走归约式路径：窗口内 argmax 用的是按输入步长重排后的循环序号（kw*6+kh），`_pool_offsets_to_indices` 按 kh*6+kw 解码。Win/Linux、CPU/CUDA、2.14/nightly 全复现 |\n"
     "| 44 | **`adaptive_max_pool3d` + channels_last_3d 输入：Inductor 下梯度错**（前向值与 indices 都对） | **待提交（高：静默错梯度；根因在 eager C++ 内核）**（同上扫描） | `0920issues/14-*.md`；`reports_layout/pool_backward_noncontiguous_indices.py`、`compiled_pool_grad_channels_last.py` | 无同报告；属 ☂️ #195547 一类 | `adaptive_max_pool3d_backward`、`fractional_max_pool2d_backward`、`fractional_max_pool3d_backward` 对 grad_output 做了 `.contiguous()` 而对 indices 没做；eager 里 indices 总连续所以撞不到，Inductor 把保存的 indices 排成 channels_last 才触发。2.14 + nightly |\n\n"
     "7.1 布局/别名扫描其余结果（534 个算子 × 7 种布局 × 前向+反向，4 路分片约 70 分钟）：527 个完全一致；`view_copy` 对不可 view 的布局 Inductor 编译失败而 eager 正常（低，未写稿）；4 个算子输出步长与 eager 不同（信息性，未报）。→ 布局这根轴除池化外是干净的（负结果）。\n\n"
     "副作用差分其余结果（75 例，71 一致）")

edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-21 晚）**：",
     "**当前断点（2026-09-21 深夜）**：7.1 布局/别名扫描跑完（534 算子，527 一致）→ **两条高优先级静默错梯度：台账 43 / 草稿 13（大窗口 max_pool + 转置输入，CPU 与 CUDA 都错）、台账 44 / 草稿 14（adaptive_max_pool3d + channels_last_3d，根因是 eager 内核读非连续 indices）**；12、13 已在 Linux（2.14 + nightly 0920）复核，13 在 T4 CUDA 上同样复现，均已写回草稿。`0920issues/` 现有 14 份（README 有提交顺序：01 → 13 → 14 → 04 → 08 → 12 → …）。下一步：`python scripts/prefix_consistency_sweep.py --isolate`（10.2，已启动则看 `results/prefix/`）；然后 10.1 改写前提、10.3 模型手术/超参数。\n\n"
     "**历史断点（2026-09-21 晚）**：")

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
s = open(mem, encoding="utf-8").read()
line = ("- 2026-09-21 night: layout/alias sweep (scripts/layout_alias_sweep.py, 534 ops, 4 shards ~70 min) done -> two HIGH silent-wrong-gradient drafts: "
        "0920issues/13 (max_pool2d/3d with kernel volume > 25 on input with transposed spatial dims: wrong indices + wrong grad; CPU and CUDA; root cause = in-window argmax numbered in "
        "stride-reordered loop order, same class as fixed #193751) and 0920issues/14 (adaptive_max_pool3d + channels_last_3d under Inductor; root cause is the EAGER kernels "
        "adaptive_max_pool3d_backward / fractional_max_pool{2,3}d_backward reading non-contiguous `indices` as contiguous). Drafts 12-13 re-verified on Linux (2.14 + nightly 0920), 13 also on T4. "
        "Ledger rows 43-44; 14 drafts total; suggested order in 0920issues/README.md starts 01 -> 13 -> 14 -> 04. Next: prefix_consistency_sweep (10.2), then 10.1 / 10.3. Nothing filed by me.\n")
if line not in s:
    open(mem, "w", encoding="utf-8").write(s + line)
print("recorded")
