"""One-off bookkeeping for 2026-09-21 (second half): draft 12, side-effect sweep result, round-6 angles."""
import os

PLAN = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")


def edit(path, old, new):
    s = open(path, encoding="utf-8").read()
    if new in s:
        return
    assert old in s, (path, old[:60])
    open(path, "w", encoding="utf-8").write(s.replace(old, new, 1))


edit(os.path.join(ISSUES, "README.md"),
     "\n建议提交顺序：01 → 04（评论）→ 08 → 06 → 05 → 09 → 07（评论）→ 02 → 03 → 11 → 10（评论）。",
     "| 12 | pytorch/pytorch | 新 issue | **Dynamo 静默丢副作用**：在被编译函数里新建一个\"定义在外层函数里的类\"的对象并调用方法，方法对闭包 list/dict 的修改（append / extend / `d[k]=v` / `d[k]+=1`）全部丢失；`fullgraph=True` 不报错、无 graph break；本地定义的上下文管理器的 `__enter__/__exit__` 记账也因此丢失 | 中–高（静默；2.14 + nightly；触发条件已隔离成三条） | 待提交 |\n"
     "\n建议提交顺序：01 → 04（评论）→ 08 → 12 → 06 → 05 → 09 → 07（评论）→ 02 → 03 → 11 → 10（评论）。")

edit(os.path.join(PLAN, "TO_SUBMIT.md"),
     "不报：`atanh(次正规数)`→0",
     "| 42 | **Dynamo 丢副作用**：类定义在外层函数里 + 对象在被编译函数内创建 + 方法里改闭包捕获的 list/dict → 修改静默丢失（`fullgraph=True` 无报错）；对象在外面创建 / 换成嵌套函数 / 类与状态在模块级 都正常 | **待提交（中–高）**（7.2–7.6 副作用差分 `side_effect_diff.py`，用例 `context_manager_exit_runs`） | `0920issues/12-*.md`；`reports_sideeffects/closure_mutation_min2.py` | 无同报告（7 组关键词）；#196864/#171590 是同区域的崩溃，已关 | 怀疑：追踪期创建的对象无 source，其方法闭包单元被当成新的本地对象，修改没登记到 SideEffects |\n\n"
     "副作用差分其余结果（75 例，71 一致）：编译后才注册的 forward hook 不被调用 = 文档化限制（`skip_nnmodule_hook_guards`），不报；`x.add_(1)` 之后图里出形状错误——eager 已改了 x、compile 在追踪期就报错所以 x 未改 = 追踪式编译的固有差异，不报；**对\"既被返回又参与 loss 的中间量\"注册 tensor hook：eager 的 hook 收到梯度并可改写（x.grad 变 0），compile 下 hook 收到 `None`、改写不生效（x.grad=2）**——AOTAutograd 把整段当一个 autograd 节点的固有限制，但\"hook 收到 None\"值得查重后再定（`reports_sideeffects/ctx_manager_and_output_hook.py`）。\n\n"
     "不报：`atanh(次正规数)`→0")

edit(os.path.join(PLAN, "EXECUTION_REPORT.md"),
     "**当前断点（2026-09-21）——8.2 整数/IEEE 扫描跑完并分诊**",
     "**当前断点（2026-09-21 晚）**：(1) 07–11 已在 Linux CPU（2.14.0 + nightly dev20260920）与 T4 CUDA 复核并写回草稿：08/10/11 三处逐字相同（10 在 CUDA 上同样被消掉）；07/09 CPU 专属且不同 CPU 错法不同（07 在一台机器上 `argmin` 返回未初始化的大负数；09 在一台机器上 3 个元素也得 nan）。(2) **副作用/状态差分 `scripts/side_effect_diff.py`（75 例）跑完：71 一致；新缺陷 1 条 = 台账 42 / 草稿 12（Dynamo 丢闭包修改）**，其余 3 条差异为文档化限制或固有差异（见台账 42 下方说明）。(3) 7.1 布局/别名扫描改成 4 路分片在跑（`results/layout_alias/cases_s{0..3}.jsonl`，`python scripts/layout_alias_sweep.py --report` 汇总全部分片；单路时约 2 分钟/算子）。(4) 用户再次要新角度 → `NEXT_DIRECTIONS.md` **§10 第六轮**（按\"什么最出货\"反推：改写前提、前缀一致性、模型手术/超参数、保护机制、标量算术、全 lowering 表、32 位索引、随机分布、环境×缓存键、历史无关性、ONNX/Numba 并行/CPython JIT、全局模式）；已写 `scripts/prefix_consistency_sweep.py`（10.2），因机器被布局扫描占满，冒烟超时，**等布局扫描结束后再跑**：`python scripts/prefix_consistency_sweep.py --isolate`。\n\n"
     "**历史断点（2026-09-21）——8.2 整数/IEEE 扫描跑完并分诊**")

mem = os.path.expandvars(r"C:\Users\clm\.claude\projects\d--wsl-personal-dr-paper\memory\tcc-plan-status.md")
s = open(mem, encoding="utf-8").read()
line = ("- 2026-09-21 evening: drafts 07-11 re-verified on Linux CPU (2.14 + nightly dev20260920) and T4 CUDA and updated (08/10/11 identical incl. CUDA; 07/09 CPU-only, "
        "wrong in different ways per CPU). side_effect_diff.py (75 cases) done: 1 new defect -> ledger 42 / draft 0920issues/12 (Dynamo silently drops closure list/dict mutations "
        "made in a method of a locally defined class instantiated inside the compiled fn; fullgraph ok). NEXT_DIRECTIONS §10 = round-6 angles (rewrite preconditions, prefix consistency, "
        "post-compile model surgery / hyperparameter change, lost safety mechanisms, SymInt scalar arithmetic, all-lowerings x edge values, int32 indexing, RNG distribution, env vars x cache key, "
        "compile-history independence, ONNX/Numba parallel/CPython JIT, global modes). scripts/prefix_consistency_sweep.py written, not yet run (machine busy with 4-shard layout sweep in results/layout_alias). "
        "Total: 42 ledger rows, 12 drafts in 0920issues, nothing filed by me.\n")
if line not in s:
    open(mem, "w", encoding="utf-8").write(s + line)
print("recorded")
