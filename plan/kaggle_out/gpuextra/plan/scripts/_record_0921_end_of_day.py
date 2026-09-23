"""End-of-day record (2026-09-21): resume point, open leads, next angles.  Idempotent."""
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def edit(path, old, new):
    t = open(path, encoding="utf-8").read()
    if new in t:
        return
    assert old in t, (path, old[:50])
    open(path, "w", encoding="utf-8").write(t.replace(old, new, 1))


RESUME = """**当前断点（2026-09-21 收工）——明天从这里接着做**

1. **提交（用户手工，方案 A）**：今天已提交 14 条并登记在 `0920issues/FILED.md`（PyTorch issue #197887 #197888 #197889 #197893 #197894 #197895 #197896；评论 #143649、#197554 下各一条；微软 11155532 / 11155535 / 11155537；numba #10845；jax #40840）。**还剩 9 条**：12、13、15、16、19、21（PyTorch 新 issue）与 14、20、22（评论）。用户说明天继续；**开始前先按根因关键词对这 9 条重新查重**，用户贴链接后跑 `python scripts/mark_filed.py <稿号> <url>`。规则见 `D:\\wsl\\personal\\dr\\paper\\CLAUDE.md`，交稿前跑 `python scripts/check_issue_drafts.py`。
2. **两轮 issue 的结果记录**：`toxic_compile/ISSUE_OUTCOMES.md`（刷新：`python scripts/issue_status_report.py && python scripts/issue_outcomes.py`）。第一轮 27 条：2 已修复、5 维护者确认、8 他人复现/有修复 PR、1 有争议、11 无回应；第二轮 14 条均无回应。**论文里 “11 确认 / 9 修复” 与证据不符（实际 7 / 2），未改，等用户定口径**。注意 PyTorch 的 `triaged` 常由机器人打，不单独算确认。
3. **未写稿的新线索（明天第一件事）**：torch.fx 代码生成的**名字遮蔽**——被 `symbolic_trace` 的函数若有名为 `nan`（或 `inf`）的参数、图里又有浮点常量 `float("nan")` / `float("inf")`，生成的 `forward` 把常量写成裸名字 `nan` / `inf`，被同名形参遮蔽：`torch.where(mask, float("nan"), x)`（形参叫 `nan`）得到 `[1, 1, 3]` 而不是 `[1, nan, 3]`；`Interpreter` 正确；2.14 与 nightly 0911 都复现；参数名为 `torch` 时是响亮报错。根因：`fx/graph.py` 用 `_register_custom_builtin("inf"/"nan"/"torch"/"device"/…)` 把这些名字当全局使用，`_Namespace` 只给**节点名**改名（`nan_1`），但函数签名仍用占位符的原名 `nan`。查重 4 组关键词无同报告。证据：`plan/reports_fx/codegen_name_shadowing.py`、`codegen_param_shadows_inf_nan.py`（后者里 `clip_scores` 例子不敏感，写稿时把 scores 改成含大于上限的值，如 `[1, 50, 3]` 对上限 `[10, 20, 30]`）。与已提交的 #197894（`-2 ** x`）同属 “FX 生成的 Python 源码与 Interpreter 语义不一致”，根因不同，单独成稿，优先级中–低，编号接在 22 之后（`23`）。
4. **今天跑完的扫描（都已分诊、记账）**：10.1 改写前提、10.2 前缀一致性、10.3/10.4 模型手术与保护机制、10.5 SymInt/SymFloat 标量算术、10.5b 符号形状、10.7 32 位索引（T4）、10.9b 标量实参序列（release + nightly）、10.13 C++ 工具链层（MSVC / g++ / clang++）与 host_opt。没有后台任务在跑。
5. **下一步挖掘方向（按预期产出排序）**见 `NEXT_DIRECTIONS.md` §11。

"""

edit(os.path.join(PLAN, "EXECUTION_REPORT.md"), "**2026-09-21 晚**：", RESUME + "**2026-09-21 晚**：")

ND = """

## 11. 第七轮方向（2026-09-21 收工时整理；今天的经验：产出最高的是“同一语义的两条实现路径”与“被缓存键漏掉的特化”）

今天 8 个新工具共 9 份新稿 + 1 份待写，规律很清楚：**凡是系统里同一件事有两条实现路径、而只有一条被测试覆盖的地方，就有缺陷**（FX 的 Interpreter vs 生成源码 → #197894 与名字遮蔽；标量被张量化 vs 被特化 → 02b；`remove_noop_ops` 在 post_grad 有别名检查而 joint_graph 没有 → 07；floordiv 有除零保护而 truncdiv 没有 → 03；向量主体 vs 标量尾部 → 13）。下一轮按这个思路找“成对路径”：

### 11.1 FX：Interpreter 与生成源码的系统差分（把 #197894 / 名字遮蔽推广）——最便宜，先做
- 工具 `scripts/fx_codegen_vs_interpreter.py`：随机/枚举构造 FX 图（全部 `operator.*` 魔术方法 × 字面量实参取 {负数, inf, nan, -0.0, 大整数, 复数, bool, None, slice, Ellipsis, 嵌套 tuple/list/dict, dtype, device, memory_format, 字符串含引号/换行}；占位符名取 Python 关键字、内置名、`inf/nan/torch/device/math/self` 等；`*args/**kwargs` 占位符；默认实参），对每张图比较 `Interpreter.run` 与 `GraphModule.forward`，再比较 `gm.code` 经 `exec` 往返、`copy.deepcopy`、`pickle` 往返后的结果。纯 Python，不需要 C++ 编译，几分钟跑完。
- 预期 2–4 条（运算符优先级、名字遮蔽、特殊浮点字面量、关键字参数名）。

### 11.2 “特化值进了图、却不在缓存键里”家族（02b 的推广）
- 02b 的机制：fake-tensor 传播时把符号 float 特化 → ShapeEnv 守卫 → AOTAutogradCache 剪掉非占位符符号的守卫。**同一机制的其它入口**：① `.item()` 得到的 unbacked 值经 `torch._check` / `guard_size_oblivious` 被特化；② `int(s * k)` 决定形状（`torch.zeros(int(s*8))`、`x[: int(s*4)]`、`arange(0, s, 0.1)`、`F.pad(x, (int(s*4), 0))`、`repeat(int(s*4))`）；③ 分解时按值分支的算子（`pow` 指数 2/0.5/-1、`addmm` 的 `beta == 0`（NaN 传播语义不同）、`dropout` 的 p ∈ {0, 1}、`lerp` 权重 0/1、`clamp` 的 min > max）；④ SymBool（`s > 0.5` 进 `torch.where` 而不是 Python 分支）。
- 工具：在 `reports_scalar_seq/specialized_float_kwarg_census.py` 基础上做 v2（形状类 + 分解分支类），序列里放 0 / 1 / 2 / 0.5 / 负数等特殊值；release 与 nightly 各跑；再加“跨进程热缓存”一档（同一缓存目录，第二个进程用不同取值）。预期 1–3 条，且都是默认配置下的静默错值。

### 11.3 成对 pass / 成对 lowering 的“保护不对称”审计（07、03 的推广）——半静态
- 用脚本在 `torch/_inductor` 里找“同名或同功能的两处实现”，对比各自的前置条件：`joint_graph.py` vs `post_grad.py` 的同类改写；`CppOverrides` vs `CppVecOverrides` vs `TritonOverrides` 的同名方法（谁有除零/溢出/NaN 处理，谁没有）；`lowering.py` 里 `fallback` 条件与对应 `decomposition` 的校验；`_refs` 与 `_decomp` 里同一算子的两份实现。对每个不对称点生成一个针对性的小程序验证。
- 预期 3–5 条；成本主要是读代码，验证很快。

### 11.4 10.6 全 lowering 表 × 边界值（一直没做）
- `torch._inductor.lowering.lowerings` 自动枚举，对每个逐点/归约 lowering 套 `int_ub_sweep.py` 的边界值向量，dtype 扩到 float16/bfloat16/int16/uint8/bool 与混合 dtype；要分片跑（MSVC 编译是瓶颈），或放 Kaggle Linux 上跑 gcc（快 3–5 倍）。预期 3–5 条。

### 11.5 10.13 后续：C++ 工具链层
- 词表 v4：`maskload/maskstore`（Inductor 尾部处理用）、饱和/截断窄化 `cvt*`、`fmadd` 与常量、整数比较链、`testz`；三层组合与公共子表达式形状 `B(U(x), U(x))`。
- 拿 Inductor 真实内核语料扩到归约、float16/bfloat16、`cpp.simdlen=256`（本机默认 512）。
- 更新的 MSVC（VS 2026 / 17.14 最新补丁）上复测 05/17/18 三条，结果补到微软工单里。

### 11.6 其它目标（跨目标表 §9 里还没做的）
- ONNX Runtime（图优化级别 `ORT_DISABLE_ALL` vs `ORT_ENABLE_ALL` 的差分——与 host_opt 同思路，语料用 `xtarget_numpy_diff` 的 268 个程序导出 ONNX）；Numba `parallel=True` / `fastmath=False` 对普通 `njit`；`torch.export` + AOTInductor 对 `torch.compile`（同一程序两条部署路径）。

优先级：11.1 → 11.2 → 11.3 → 11.4 → 11.5 / 11.6。
"""
nd = os.path.join(PLAN, "NEXT_DIRECTIONS.md")
t = open(nd, encoding="utf-8").read()
if "## 11. 第七轮方向" not in t:
    open(nd, "w", encoding="utf-8").write(t.rstrip("\n") + ND)

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "**2026-09-21 重新编号**",
     "| 55 | **torch.fx 代码生成：形参名 `nan` / `inf` 遮蔽同名浮点常量**（`symbolic_trace` 后 `GraphModule.forward` 静默错值，`Interpreter` 正确；形参名 `torch` 时响亮报错） | **线索已确认、未写稿（中–低）**（2026-09-21 夜，顺着 #197894 查 FX codegen 时发现） | 待写 `0920issues/23-*.md`；`reports_fx/codegen_name_shadowing.py`、`codegen_param_shadows_inf_nan.py` | 4 组关键词无同报告 | `fx/graph.py`：`inf`/`nan`/`torch`/`device`/… 注册为 custom builtin 当全局用；`_Namespace` 只改节点名，函数签名仍用占位符原名。2.14 + nightly 0911 |\n\n"
     "**2026-09-21 重新编号**")

mem = r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md"
m = open(mem, encoding="utf-8").read()
line = ("- 2026-09-21 END OF DAY (resume here): EXECUTION_REPORT.md §1 has the resume block. (a) user files the remaining 9 drafts tomorrow (12, 13, 15, 16, 19, 21 issues; 14, 20, 22 comments): re-run dedup first, record with mark_filed.py. "
        "(b) unwritten lead = ledger row 55: torch.fx codegen lets a parameter named `nan`/`inf` shadow the float constant printed as bare `nan`/`inf` (symbolic_trace -> GraphModule.forward silently wrong, Interpreter right; 2.14 + nightly); "
        "evidence in plan/reports_fx/; write it as 0920issues/23. (c) next angles = NEXT_DIRECTIONS.md §11: 11.1 FX Interpreter-vs-generated-code differential (cheap, first), 11.2 'specialised value not in cache key' family (generalise 02b: shapes from floats, value-dependent decompositions, warm cache across processes), "
        "11.3 asymmetry audit of paired passes/lowerings (generalise drafts 07/03), 11.4 all-lowerings x edge values, 11.5 C++ toolchain v4, 11.6 ONNX Runtime / AOTI. Insight of the day: bugs sit where one semantics has two implementation paths and only one is tested. "
        "(d) paper counts (11 confirmed / 9 fixed) disagree with evidence (7 / 2): waiting for the user's decision. No background jobs running.\n")
if line not in m:
    open(mem, "w", encoding="utf-8").write(m + line)
print("recorded")
