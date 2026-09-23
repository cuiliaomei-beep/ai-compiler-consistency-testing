"""One-off bookkeeping (2026-09-21 late night): rewrite-precondition differential triage -> drafts 15, 16; draft 13 downgraded to a comment on #197434."""
import os, re

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


readme = os.path.join(ISSUES, "README.md")
s = open(readme, encoding="utf-8").read()
row13 = re.search(r"^\| 13 \|.*$", s, re.M).group(0)
new13 = ("| 13 | pytorch/pytorch | **评论**（#197434） | ~~大窗口 max_pool + 空间维转置输入 → indices 错、梯度错~~ **已被他人报告：#197434（09-17）+ 修复 PR #197596（09-18）**，"
         "09-21 查重时因标题写的是 `adaptive_max_pool2d` 而漏掉。降级为可选评论：补充\"`return_indices=False` 时梯度同样错\"（原 issue 说此时无问题）、直接 `max_pool2d/3d` 窗口>25 即触发、CUDA 同错，建议 PR 加反向测试 | 低（可选） | 待定 |")
if row13 != new13 and "#197434" not in row13:
    s = s.replace(row13, new13)
if "| 15 |" not in s:
    row14 = re.search(r"^\| 14 \|.*$", s, re.M).group(0)
    s = s.replace(row14, row14 + "\n"
        "| 15 | pytorch/pytorch | 新 issue | **`x / 1.0`、`buf * 1.0`、`x + 0` 作为图输出时，Inductor 直接把输入张量本身返回（`out is x`）**；调用方对结果做原地更新就会改坏输入；只在超参数取\"中性值\"时触发（`temperature=1.0`、`momentum=1.0`、`bias=0`），0.9 就正常；`requires_grad` 时不是同一对象但共享存储；根因：`joint_graph.remove_no_ops` 缺少 `post_grad.remove_noop_ops` 里那条\"不得在输入与输出之间引入新别名\"的检查 | 中–高（静默改坏输入；修法几行） | 待提交 |\n"
        "| 16 | **Microsoft Visual C++**（Developer Community，非 GitHub） | 新反馈 | **MSVC 19.44 `/O1`、`/O2` 把连续两次 `_mm*_abs_epi8/16/32` 整个消掉：`abs(abs(x))` 返回 `x`**（一次、三次都对，`/Od` 对）；128/256/512 位都中；独立 C++ 复现 + 汇编；是通过 Inductor 在 Windows 上 `x.abs().abs()`（int8/16/32）返回负数发现的——**PyTorch 之下一层（C++ 编译器）的缺陷** | 高（编译器误编译） | 待提交（需微软账号） |")
s = s.replace("建议提交顺序：01 → 13 → 14 → 04（评论）→ 08 → 12 →", "建议提交顺序：01 → 14 → 15 → 16（微软）→ 04（评论）→ 08 → 12 →")
if "13（评论，可选）" not in s:
    s = s.replace("→ 10（评论）。", "→ 10（评论）→ 13（评论，可选）。", 1)
if "`x ** -0.5`" not in s:
    s = s.replace("\n## 工具（都在 `plan/` 下）",
        "| eager `x ** -0.5` 对 `-0.0` 得 `-inf`、对 `-inf` 得 `nan`（编译后是 `inf` / `0`，与 C `pow` 和 NumPy 一致） | 偏离 IEEE `pow` 的是 **eager**（指数 -0.5 走 `rsqrt` 特化），编译结果反而对；价值低，未写稿 |\n"
        "| `x + 0` 编译后不再把 `-0.0` 规整成 `+0.0` | 有符号零一类（open #188680）；已作为 15 号稿的一句附注 |\n"
        "| `x.half().float()` 链、`cast_then_op` 被消掉 | 即 10 号评论稿（#185337），不重复报 |\n"
        "| 前缀一致性（10.2）：`exp/expm1/exp2/sin/cos/tan/gelu/elu/selu/celu/softplus/hypot/xlogy` 向量主体与标量尾部差 1 ULP（gelu float32 约 8 ULP） | 向量数学库与标量 `std::` 函数的舍入差；没有对齐 / 线程数造成的差异；PyTorch 不承诺逐位一致，不报（负结果） |\n"
        "\n## 工具（都在 `plan/` 下）", 1)
if "rewrite_precondition_diff.py" not in s:
    s = s.rstrip("\n") + "\n" + (
        "| `scripts/layout_alias_sweep.py` | 534 个算子 × 7 种布局/别名 × 前向+反向（`--shard i/n`）；13、14 的来源 |\n"
        "| `scripts/side_effect_diff.py` | 75 个副作用/状态小程序；12 的来源 |\n"
        "| `scripts/rewrite_precondition_diff.py` | 183 个\"代数改写前提\"用例（-0.0 / NaN / 别名敏感）；15、16 的来源 |\n"
        "| `scripts/prefix_consistency_sweep.py` | 同一输入的前缀、对齐、线程数下编译结果逐位一致性（负结果） |\n"
        "| `reports_rewrites/msvc_abs/` | 16 的独立 C++ 复现、四档优化级别构建脚本、汇编打印、草稿 C++ 块逐字验证（`verify_draft16.py`） |\n")
open(readme, "w", encoding="utf-8").write(s)

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "7.1 布局/别名扫描其余结果",
     "| 45 | **`x / 1.0`、`x * 1.0`、`x ± 0` 作为图输出时 Inductor 返回输入张量本身**（`out is x`），对结果原地更新会改坏输入；中性超参数才触发 | **待提交（中–高）**（10.1 改写前提差分 `rewrite_precondition_diff.py`，用例 `add_zero_is_copy` / `mul_one_is_copy`） | `0920issues/15-*.md`；`reports_rewrites/noop_returns_input_alias.py`、`noop_alias_realistic.py` | 无同报告；相关 #174187/#174938（同 pass，另一前提）、#197489（post_grad 同名 pass） | `joint_graph.remove_no_ops.replace_no_op` 缺\"输入↔输出不得新增别名\"检查（`post_grad.remove_noop_ops` 有）。2.14 + nightly；Linux/CUDA 复核 `tcc-rewritelinux/gpu` |\n"
     "| 46 | **MSVC 19.44 误编译：连续两次 `_mm*_abs_epi8/16/32` 被整个消掉（`abs(abs(x)) → x`）**；在 Inductor 上表现为 Windows CPU `x.abs().abs()`（int8/16/32）返回负数 | **待提交到 Visual Studio Developer Community（高：编译器误编译）**（同上工具，用例 `abs_abs`） | `0920issues/16-*.md`；`reports_rewrites/msvc_abs/` | Web 搜索无同报告（站内需人工再搜） | `/Od` 对，`/O1`、`/O2`（含 AVX2/AVX512）错；一次、三次 abs 都对 → 优化器把 pabs 当对合而非幂等。**第一条 PyTorch 之下（C++ 工具链）的缺陷** |\n\n"
     "**台账 43 更正（2026-09-21 深夜）**：已被他人报告为 #197434（09-17，标题是 adaptive_max_pool2d）并有修复 PR #197596；草稿 13 降级为可选评论（增量：`return_indices=False` 时梯度同样错）。\n\n"
     "10.1 改写前提差分其余结果（183 例，174 一致）：`x+0` 不规整 -0.0（#188680 一类）、`x ** -0.5`（偏离的是 eager）、cast 链（=草稿 10）。10.2 前缀一致性（进行中，70/135）：仅向量主体与标量尾部 1 ULP 级差异，无对齐/线程差异 → 负结果。\n\n"
     "7.1 布局/别名扫描其余结果")

edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-21 深夜）**：",
     "**当前断点（2026-09-22 凌晨）**：10.1 改写前提差分跑完并分诊（183 例，9 DIFF）→ **台账 45 / 草稿 15（Inductor `x*1`/`x+0` 返回输入本身）**、**台账 46 / 草稿 16（MSVC 误编译 `abs(abs(x))`，报给微软——第一条 PyTorch 之下的工具链缺陷）**；**草稿 13 被 #197434 + PR #197596 抢先，降级为可选评论**（教训：查重要按根因关键词而不是按我们触发的算子名，且提交前当天再查一次）。Kaggle `tcc-rewritelinux` / `tcc-rewritegpu` 复核 14、15 与 abs(abs)（结果在 `kaggle_out/`）。10.2 前缀扫描仍在跑（`results/prefix/`），目前只有 1 ULP 级差异。下一步：10.13（新）C++ 工具链层差分 `scripts/cxx_intrinsic_algebra_diff.py`（同一 Vectorized<T> 组合 `/Od` vs `/O2`）；然后 10.3 模型手术/超参数、10.4 安全机制。\n\n"
     "**历史断点（2026-09-21 深夜）**：")

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
s = open(mem, encoding="utf-8").read()
line = ("- 2026-09-22 early: rewrite-precondition differential (scripts/rewrite_precondition_diff.py, 183 cases) triaged -> 0920issues/15 (Inductor joint_graph.remove_no_ops returns the INPUT itself for x*1.0 / x/1.0 / x+0 outputs; "
        "in-place update of result corrupts input; fix = same input/output alias check as post_grad.remove_noop_ops) and 0920issues/16 (MSVC 19.44 /O1,/O2 folds two consecutive _mm*_abs_epi8/16/32 into a no-op; standalone C++ repro in "
        "plan/reports_rewrites/msvc_abs/; goes to Visual Studio Developer Community, first below-PyTorch toolchain bug). Draft 13 was pre-empted by #197434 + PR #197596 -> downgraded to optional comment (lesson: dedup by root-cause keywords, re-check on filing day). "
        "Ledger rows 45-46; 16 drafts. Prefix sweep (10.2): only 1-ULP vector-vs-tail differences, negative result. Next: C++ toolchain-level /Od-vs-/O2 differential over Vectorized<T> op compositions, then 10.3/10.4. Nothing filed by me.\n")
if line not in s:
    open(mem, "w", encoding="utf-8").write(s + line)
print("recorded")
