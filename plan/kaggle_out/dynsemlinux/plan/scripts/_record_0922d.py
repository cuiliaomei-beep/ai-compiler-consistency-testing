"""One-off bookkeeping (2026-09-22 evening): 10.3/10.4 surgery+safety sweep, 10.5 SymInt sweep, gcc/clang results -> drafts 19-23."""
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
if "| 19 |" not in s:
    row18 = re.search(r"^\| 18 \|.*$", s, re.M).group(0)
    rows = [
        "| 19 | pytorch/pytorch | **评论**（#143649） | **整数 `torch.div(a, b, rounding_mode=\"trunc\")` 除零让进程直接崩溃**（Windows `0xC0000094`，Linux SIGFPE），`try/except` 接不住；原 issue 点名的 floor_divide / remainder / fmod 在 2.14 已有保护，漏了 truncdiv；根因 `CppOverrides.truncdiv` / `CppVecOverrides.truncdiv` 仍是裸 `a / b`；所有整数 dtype、向量主体与尾部都中；2.14 + nightly，Win + Linux | **高**（进程崩溃） | 待提交 |",
        "| 20 | pytorch/pytorch | **评论**（#197554，第二条） | Inductor 下丢失的三种“模式类保护”：① InferenceMode 外对 inference tensor 做原地修改不再报错（真的改了调用方张量）；② 确定性模式下 `put_`（重复下标）不再报错；③ 确定性模式的 `fill_uninitialized_memory` 对 `empty*` 不生效。`aot_eager` 都与 eager 一致；CPU + CUDA | 中–低 | 待提交（04 之后） |",
        "| 21 | pytorch/pytorch | 新 issue | **torch.fx 代码生成的优先级错误：`operator.pow(-2, x)` 生成 `-2 ** x`（= `-(2**x)`）**，`GraphModule.forward` 符号错而 `Interpreter` 对；`torch.compile(dynamic=True)` 下 `x * (-1) ** x.shape[0]` 在 eager/aot_eager 后端对所有长度都返回 `-x`；`symbolic_trace` 同错；根因 `fx/graph.py` 用 `\"{} ** {}\".format(repr(...))` | **中–高**（静默错值；修法一行） | 待提交 |",
        "| 22 | pytorch/pytorch | 新 issue | **`round(x.shape[0], -1)` 在 SymInt 上是恒等**（`SymInt.__round__` 直接 `return self`，忽略负的 ndigits）；round 从图里消失，三个后端一致地错（`round(25,-1)` 得 25 而不是 20） | 中（静默错值） | 待提交 |",
        "| 23 | pytorch/pytorch | 新 issue | **`capture_scalar_outputs=True` 下 `v = loss.item()` 的 NaN 自比较在追踪期被折成常量**：`if v != v:`（跳过 NaN 步）在三个后端都走错分支；`v - v`、`v * 0` 对 NaN/inf 得 0；`max(v, 0.0)` 对 NaN 得 0；`math.isnan(v)` 正确。与 #158087 不同（那条是异常对等） | 中（非默认开关，但 #157499 想把它改成默认） | 待提交 |",
    ]
    s = s.replace(row18, row18 + "\n" + "\n".join(rows))
s = s.replace("建议提交顺序：01 → 14 → 15 → 16（微软；17、18 随后各开一张单）→", "建议提交顺序：01 → 14 → 15 → 21 → 19（评论）→ 22 → 23 → 16（微软；17、18 随后各开一张单）→")
if "20（评论，04 之后）" not in s:
    s = s.replace("→ 13（评论，可选）。", "→ 20（评论，04 之后）→ 13（评论，可选）。", 1)
if "#194976" not in s:
    notes = [
        "| **2.14.0 上 `torch.add(e*d, p, alpha=1-d)`（EMA 更新）在 d 变化后用陈旧的 alpha，静默算错**（默认配置：FX 图缓存 + AOTAutograd 缓存都开才触发；Win/Linux/CUDA） | **已知且已在 nightly 修复**：#194976（2026-08-27 关闭）/ 修复 #195040 “Fix stale float specialization in tensorify_python_scalars”；2.14.0 发布版没带上这个修复。nightly 0911/0921 复核正确 → 不报（证据 `plan/reports_surgery/float_arg_cache_matrix.py`，可作论文里“工具重新发现已知缺陷”的例子） |",
        "| 编译的 Adam/AdamW `step` 与 eager 每步差 ~1e-6（不改超参数也有） | 偏差修正项在编译路径里用 float32 张量算；精度级，不报。lr/betas/eps/wd 的步间修改都被正确感知（10.3 负结果：76 例中 69 例一致） |",
        "| CUDA 确定性模式下 `avg_pool3d` / `reflection_pad1d` / `nll_loss2d` / `interpolate(bicubic, linear)` 的反向 eager 报错、编译后不报 | 编译后的实现本身是确定性的（gather 式 / 排序式），不报错合理，不算缺陷 |",
        "| `std()` 单元素的 “degrees of freedom” 警告在编译后丢失 | 警告对等，价值低，不报 |",
        "| SymInt/SymFloat 其它差异：`min(n, 2.5)` 返回 float 而不是 int；`round(v, 1)`、`v // 1` 丢 `-0.0` 的符号；`round(n/8, 1)` 得 0.6000000000000001；超过 int64 的大整数编译后 OverflowError；`v % 1` 对 inf 编译失败 | 类型/有符号零/大整数属已知限制或响亮失败，价值低，未写稿（记录在 `results/symint/cases.jsonl`） |",
        "| g++ 11.4 / clang++ 14（Kaggle，104,332 个内建函数组合，-O0 对 -O1/2/3） | **0 个真实差异**：全部“值差异”来自 `x * -1.0 → -x` 改变 NaN 符号位后经按位运算 / 比较选择显形，IEEE 与两家编译器文档都允许（负结果；说明 16–18 是 MSVC 特有） |",
    ]
    s = s.replace("\n## 工具（都在 `plan/` 下）", "\n".join(notes) + "\n\n## 工具（都在 `plan/` 下）", 1)
if "symint_arith_diff.py" not in s:
    s = s.rstrip("\n") + "\n" + (
        "| `scripts/symint_arith_diff.py` | 10.5：138 个 Python 标量表达式（SymInt 来自 shape、SymFloat/SymInt 来自 `.item()`）× 取值网格 × {eager, inductor} 后端，对照纯 Python 语义（类型+值+异常）；21、22、23 的来源 |\n"
        "| `reports_surgery/*.py`、`reports_symint/*.py` | 19–23 的独立复现与隔离脚本（逐用例独立进程；含“哪一个缓存导致陈旧 alpha”的 2×2 矩阵） |\n")
open(readme, "w", encoding="utf-8").write(s)

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**台账 43 更正（2026-09-21 深夜）**",
     "| 49 | **整数 `div(rounding_mode=\"trunc\")` 除零 → 进程崩溃**（Inductor CPU；floor/remainder/fmod 已有保护） | **待提交（高；评论 #143649）**（10.4 `model_surgery_diff.py`，CRASH 记录） | `0920issues/19-*.md`；`reports_surgery/int_div_zero_crash.py` | #143649 open；PR #178591 open、#186021 未合入 | `CppOverrides.truncdiv` / `CppVecOverrides.truncdiv` 裸 `a / b`。Win `0xC0000094`、Linux SIGFPE；2.14 + nightly 0921 |\n"
     "| 50 | Inductor 下丢失：inference tensor 原地修改检查、确定性模式 `put_` 报错、`fill_uninitialized_memory` | **待提交（中–低；#197554 第二条评论）**（同上） | `0920issues/20-*.md`；`reports_surgery/safety_mechanisms_lost.py`、`deterministic_mode_parity.py` | 无同报告 | aot_eager 与 eager 一致；CPU + CUDA |\n"
     "| 51 | **torch.fx codegen：`operator.pow(-2, x)` → `-2 ** x`**，GraphModule 符号错；Dynamo dynamic 下 `(-1) ** x.shape[0]` 在 eager/aot_eager 后端恒为 -1 | **待提交（中–高）**（10.5 `symint_arith_diff.py`） | `0920issues/21-*.md`；`reports_symint/fx_codegen_negative_pow.py`、`negative_base_pow.py` | 无同报告 | `fx/graph.py` magic_methods 模板 + repr；只有 `**` 比一元负号优先级高 |\n"
     "| 52 | **`SymInt.__round__` 忽略负 ndigits**（`return self`） | **待提交（中）**（同上） | `0920issues/22-*.md` | 无同报告 | 三后端一致地错；2.14 + nightly |\n"
     "| 53 | **unbacked SymFloat 的 NaN 自比较被 SymPy 折叠**（`v != v` → False；`v - v` → 0） | **待提交（中）**（同上） | `0920issues/23-*.md`；`reports_symint/nan_self_compare.py` | 相关 #158087（不同症状） | 需 `capture_scalar_outputs=True`；`math.isnan` 正确 |\n\n"
     "未报（2026-09-22）：2.14.0 的陈旧 alpha（EMA）= 已修 #194976/#195040；Adam 1e-6 漂移；CUDA 确定性模式下若干反向不报错（实现本身确定）；SymInt 次要差异（类型、-0.0、大整数）。gcc 11.4 / clang 14 的内建函数差分：0 个真实差异。\n\n"
     "**台账 43 更正（2026-09-21 深夜）**")

edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-22 中午）**：",
     "**当前断点（2026-09-22 晚）**：10.3/10.4（`model_surgery_diff.py`，76 例）与 10.5（`symint_arith_diff.py`，138 例）跑完并分诊 → **草稿 19（trunc 除零崩进程，评论 #143649）、20（#197554 第二条评论：inference tensor / 确定性模式）、21（torch.fx `-2 ** x` 优先级错，静默错值）、22（SymInt round 负 ndigits 恒等）、23（SymFloat NaN 自比较被折叠）**，全部在 2.14 + nightly 上逐字验证；19、20 已在 Linux/T4 复核，21–23 的 Linux 复核在 Kaggle `tcc-symintlinux`（日志 `kaggle_out/symintlinux.log`，出来后把“结果出来后补一句”替换掉）。g++ 11.4 / clang++ 14 内建函数差分：干净（负结果）。2.14.0 的“陈旧 alpha”是已修的 #194976（不报）。后台仍在跑：`host_opt_diff.py` 3 分片（`results/host_opt/`）、10.2 前缀扫描收尾。`0920issues/` 现 23 份（README 有顺序）。下一步：读 host_opt 报告；10.6 全 lowering 表 × 边界值；10.7 int32 索引；10.9 环境变量 × 缓存键（陈旧 alpha 这类“缓存键漏了某个特化值”的缺陷值得系统化：同一程序换标量/换全局开关后命中缓存是否仍正确）。\n\n"
     "**历史断点（2026-09-22 中午）**：")

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
t = open(mem, encoding="utf-8").read()
line = ("- 2026-09-22 evening: two more sweeps done. scripts/model_surgery_diff.py (76 post-compile surgery / hyper-parameter / safety cases) -> draft 19 (comment on #143649: integer div trunc by zero kills the process; truncdiv codegen is raw a / b) "
        "and draft 20 (2nd comment on #197554: inference-tensor in-place check, deterministic-mode put_ error and fill_uninitialized_memory lost under Inductor). scripts/symint_arith_diff.py (138 Python scalar expressions on SymInt/SymFloat) -> "
        "draft 21 (torch.fx codegen prints operator.pow(-2, x) as -2 ** x: wrong sign; hits Dynamo eager/aot_eager with (-1) ** x.shape[0]), draft 22 (SymInt.__round__ ignores negative ndigits), draft 23 (capture_scalar_outputs: v != v on loss.item() folded to False). "
        "Not reported: 2.14.0 stale alpha in torch.add(e*d, p, alpha=1-d) = already fixed #194976/#195040 (nightly ok); Adam 1e-6 drift; g++ 11.4 / clang++ 14 intrinsic differential clean. 23 drafts; ledger rows 49-53. Nothing filed by me.\n")
if line not in t:
    open(mem, "w", encoding="utf-8").write(t + line)

idx = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\MEMORY.md"
m = open(idx, encoding="utf-8").read()
old = re.search(r"^- \[plan/ 续跑点\].*$", m, re.M).group(0)
new = ("- [plan/ 续跑点](tcc-plan-status.md) — plan/tcc: 23 drafts in 0920issues/ (Inductor wrong grads/aliasing/crash, torch.fx pow sign, SymInt/SymFloat semantics, torch._numpy, JAX, Numba, "
       "three MSVC miscompiles for MS Developer Community); cross-target + C++-toolchain-layer tools; user files by hand; resume via EXECUTION_REPORT.md §1.")
open(idx, "w", encoding="utf-8").write(m.replace(old, new))
print("recorded")
