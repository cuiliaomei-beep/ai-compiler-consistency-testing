# 执行记录：研究计划（Updated 版）的实现与结果

- 记录时间：2026-09-07 晚首版；2026-09-08 上午更新为最终数字（§3 全部为最终代码、同一预算下的结果；最后一次整体重跑在 O3 异常规范化与"与 base 相同上下文剪枝"之后）
- 依据：`../Toxic_Compilation_Consistency_Detection_Research_Plan_Updated.md`（只以此文件为准）
- 位置：本目录 `plan/`（代码 `tcc/`，入口 `run.py`，结果 `results/`，报告 `reports*/`）
- 机器：torch 2.14.0+cpu · Python 3.14 · 无 CUDA/Triton · MSVC（`run.py` 自动导入 vcvars）

---

## 1. 怎么继续

```bash
cd D:\wsl\personal\dr\paper\toxic_compile\plan
python run.py selfcheck --offline      # 10/10 应通过
python run.py selfcheck                # 29/29 应通过（约 1 分钟，含一次 Inductor 冷编译）
python tests\test_offline.py           # 38/38 应通过
```

**当前断点（2026-09-10 下午）**：`TO_SUBMIT.md` 已有 10 条候选（用户决定全部暂不提交）。按用户要求做了第二轮系统查重（`results/dedup_0910.md`，每条 4–5 组关键词）并按 `0909ISSUEs` 的格式为 10 条各写了可直接粘贴的 issue 草稿：`issues_0910/`（README 是优先级与查重结论；01–06、08–10 用 `pt2-bug-report.yml` 模板，07 pdist 是 eager 崩溃用 `bug-report.yml`）。查重过程中修正了第 4 条的根因（`_refs/linalg` 对负 `dim` 未规范化，`dim=1` 正常、`dim=-1` 失败）。expand(-1) 0 维与 open #70398 同根、interpolate bilinear 是 #175154 的实例，README 里给了评论稿而非新 issue。本机 `collect_env` 在中文 Windows 上解码失败，用 `scripts/collect_env_safe.py`。已跑完并分诊：decomp 全量 ×2 种子、decomp --grad ×2 种子、metamorphic 全量、binding 全量、max_autotune（GEMM 子集）。仍在后台（中断则同一命令续跑，`--isolate` 的按 JSONL/progress.json 跳过已完成）：

```bash
python run.py metamorphic --isolate --samples 3 --seed 1 --relations config --configs dynamic --chunk-size 20 --out results\meta_dynamic_s1   # dynamic=True × 3 样本
python run.py metamorphic --isolate --samples 2 --seed 2 --relations config --configs max_autotune --chunk-size 20 --out results\meta_autotune_all
python run.py metamorphic --source both --models 30 --max-nodes 12 --relations config,reuse --configs dynamic,no_fusion,no_inplace,no_vec,cpp_wrapper --jsonl results\meta_graph\metamorphic.jsonl --out results\meta_graph   # 150 图 × 13 配置太慢（>10 h），改为 30 图 × 5 配置；JSONL 有进度
python run.py campaign --from-dir reproducers_models --backend inductor --reruns 1 --max-contexts 4 --test-budget 6 --time-budget 300 --isolate --child-timeout 900 --out reports_models   # densenet121 已移入 _skip/
```
跑完后：`results\<dir>\METAMORPHIC.md` 看 violations；`reports_models\SUMMARY.md` 看候选；分诊方法同 §3。

```bash
# 5.1/5.2 分解/meta 差分：已跑完（results\decomp_full\DECOMP_DIFF.md），结论已分诊进 TO_SUBMIT.md 第 2–5 条。换种子再扫一轮：
python run.py decomp --isolate --samples 2 --seed 1 --out results\decomp_full_s1
# 5.3 变形关系：后台运行中（results\meta_full\，日志 results\meta_full.log）；被中断则同一命令续跑（按 metamorphic.jsonl 的 done 标记跳过）：
python run.py metamorphic --isolate --samples 1 --chunk-size 15 --out results\meta_full
# 单条复核：
python scripts\confirm_decomp2.py <OpInfo 名> <变体名>      # 重跑该算子全部样本，打印 eager/compiled/fp64
```
跑完 `results\meta_full\METAMORPHIC.md` 后，对 `standard oracle differs = False` 的违背逐条用最小脚本复核（这类是变形关系独有的发现），再查重登记。

**第七轮已于 2026-09-09 跑完并分诊**（结果见 §3 RQ5 第七轮、`reports_gh/KNOWN_BUGS.md`、`TO_SUBMIT.md`）。下面的命令用于再跑一轮或续跑（自动跳过已完成的程序，先做约 10 分钟的隔离试载）：

```bash
python run.py campaign --from-dir reproducers_gh --backend inductor --reruns 2 --minimize --max-contexts 12 --test-budget 16 --time-budget 180 --search-duplicates --out reports_gh
python scripts\gh_summary.py reproducers_gh reports_gh      # 跑完后：按 issue 状态（open/closed）算已知缺陷召回表 -> reports_gh/KNOWN_BUGS.md
```

然后逐条分诊 `reports_gh/`：来源 issue 本身就是第一条查重候选（记录里 `duplicates.candidates[0]` 是 origin issue）；open issue 复现 = 已知缺陷检出（Duplicate/origin），closed issue 复现 = 回归候选或误报（需人工看）。用 `python run.py campaign --status <sig>=<Status> --out reports_gh` 记账。
如果续跑时某个脚本再次把进程带崩，把该文件移到 `reproducers_gh\_skip\`（已放了 3 个 flex_attention 脚本）再续跑。

全部实验已用最终代码跑完（2026-09-08）。要整体复现：

```powershell
powershell -ExecutionPolicy Bypass -File scripts\run_experiments.ps1 -Backend eager -Budget 16 -SmallBudget 12   # RQ1→RQ3→RQ4→RQ2→A–E→metrics，约 40 分钟
python run.py campaign --backend inductor --reruns 2 --minimize --max-contexts 12 --test-budget 24 --time-budget 300 --nnsmith 6 --out reports   # RQ5，约 15 分钟
```

`scripts\run_rest.ps1` 只重跑 RQ2、A–E、metrics。

---

## 2. 已实现的内容（按计划章节）

| 计划章节 | 模块 | 状态 |
|---|---|---|
| §5.1 编译边界识别 | `tcc/sites.py` | 完成；在 torch 自带代码上验证：`torch/_inductor/runtime` 51 个 `@triton.jit` 边界，`torch/_dynamo` 9 个 |
| §5.2 轻量 IR + data/control/alias/state 依赖 | `tcc/ir.py` | 完成；含 Param 入口节点、别名并查集、前后向切片 |
| §6 Tensor 抽象 / scalar-flag / 边界 | `tcc/factors.py` | 完成；边界取值顺序为 k、对侧邻值、另一侧（保证前两个值分居谓词两侧） |
| §7 shape→index 关联 | `tcc/factors.py` | 完成；支持常量偏移、经 `torch.arange` 等调用传播、index/slice/gather/index_select |
| §8 alias/mutation FACT | `tcc/factors.py` | 完成；mutation_visible / partial_write / write_order / alias_returned / conditional_mutation / state_write / exception_path |
| §9 SCS | `tcc/scs.py: derive_scs` | 完成 |
| §10 测试义务（YAML） | `tcc/scs.py` | 完成；`results/obligations/*.yaml` 29 个 |
| §11 种子 | `tcc/seeds.py` | 完成：签名/注解构造、记录调用、reproducer 文件目录、site 派生、OpInfo 官方测试样本 |
| §12 单因子变异 / §13 边界引导 | `tcc/scs.py`, `tcc/program.py` | 完成；按义务轮转取值，使小预算也先覆盖每个因子一次 |
| §14 执行矩阵 E1/C1/E2/C2cold/C2warm(+C1') | `tcc/execute.py` | 完成；编译次数精确计数；磁盘缓存显式关闭 |
| §15 A→B / B→A / A→B→A | `tcc/generate.py`, `tcc/runner.py` | 完成；只对义务要求 warm_sequence 的上下文做序列（shape/compile flag 只做 cold） |
| §16 多层定位 E0–E3（E4 需 GPU） | `tcc/execute.py`, `tcc/localize.py` | 完成 |
| §17.1 O1–O7 | `tcc/oracle.py` | 完成；O1 用 fp64 参考 + dtype 感知噪声底；O7 = CacheVerdict |
| §17.2 最小化 | `tcc/minimize.py` | 完成；输入（rank/shape/值/容器/flag/参数）+ 切片引导的语句删除；未在真实缺陷上验证效果 |
| §18 Issue 生成、目录、去重、脱敏 | `tcc/report.py`, `tcc/campaign.py` | 完成；`results/bench_reports/<sig>/issue.md` 有 40+ 个样例；§18.5 的 tracker 检索已接 GitHub search API（`run --search-duplicates`，查询词由复现脚本中的算子名 + 触发因子 + 异常文本自动拼出；只给候选，不下结论） |
| §21 历史基准 | `benchmark/historical_bugs.json` | 只有骨架（本机单一 torch 版本，无法验证 buggy/fixed）；用 `tcc/faults.py` 19 个注入缺陷作受控 ground truth |
| §22–24 基线 | `tcc/baselines.py` | B1 随机（穷举因子族 + 随机值）完成；**NNSmith 本机可用并已接入**（编程生成 SymbolNet 模型）；FreeFuzz/TorchProbe/TitanFuzz/DeepREL 只有适配接口（未安装） |
| §25 RQ1–RQ5 | `tcc/benchmark.py`, `tcc/ablation.py`, `tcc/experiments.py`, `tcc/campaign.py` | 全部有最终结果（§3） |
| §26 实验 A–E | `tcc/experiments.py` | 全部有最终结果（§3） |
| §27 效率 | `tcc/metrics.py` | 完成（`results/metrics_static.json`） |

自检：离线 10/10，torch 级 29/29，离线测试 34/34。每个 oracle 都验证过"注入缺陷会报警、真实 `aot_eager` 不误报"。

---

## 3. 结论（注入缺陷基准，backend=eager，每程序固定预算；最终代码）

### RQ1 检测有效性（`results/rq1_bench.log`，预算 16）

| 指标 | 值 |
|---|---:|
| 检出 / 注入缺陷 | **19 / 19** |
| fixed 版本（真实编译器）误报 | **0 / 19 程序** |
| 平均检出所需测试数 | 4.19 |
| 平均 TTF | 0.35 s |
| 总测试 / 无效测试 / 编译次数 | 249 / 16 / 679 |

按类别全部 100%：codegen 4/4、shape 4/4、dtype 1/1、control_flow 2/2、alias_mutation 2/2、specialization 4/4、cache 2/2；
按缺陷类：code-generation deviation 13/13、JIT specialization 4/4、cache consistency 2/2。

### RQ3 静态分析贡献（`results/rq3_ablation.log`，预算 12）

| 级别 | 检出 | 测试数 | 无效测试 | 平均检出测试数 | 分析开销 ms |
|---|---:|---:|---:|---:|---:|
| A0 动态随机 | 7/19 | 338 | 109 | 3.73 | 0 |
| A1 +Tensor metadata | 8/19 | 350 | 71 | 3.18 | 28 |
| A2 +流敏感依赖 | 8/19 | 358 | 71 | 3.18 | 27 |
| A3 +shape/index 关系 | 10/19 | 343 | 69 | 3.16 | 26 |
| A4 +alias/mutation | 13/19 | 262 | 69 | 2.43 | 26 |
| A5 +SCS 剪枝 | 13/19 | 244 | 16 | 2.52 | 24 |
| A6 +cache 序列 | **19/19** | 235 | 16 | 3.98 | 27 |
| FULL | **19/19** | 235 | 16 | 3.98 | 29 |

读法：每加一层静态分析，检出单调上升而测试数总体下降（338→235），无效测试从 109 降到 16（A5 的 SCS 剪枝去掉了对程序没读的因子的枚举）；
A3 补齐 shape 类（4/4）与控制流；A4 补齐 alias/mutation（0→2/2）和 codegen；A6 补齐 cache（0→2/2）与 specialization（0→4/4）。
静态分析 + 生成总开销约 30 ms/语料（毫秒级，与执行相比可忽略）。

### RQ4 cache / specialization（`results/RQ4.md`，6 个需要 warm 序列的缺陷）

| 设置 | 已知 cache 缺陷检出 | warm-only 失败数 | 平均触发测试数 | 测试数 |
|---|---:|---:|---:|---:|
| 普通 eager-vs-compiled | 0/6 | 0 | – | 148 |
| 随机序列 | 5/6 | 11 | 6.45 | 155 |
| SCS 引导序列 | **6/6** | 17 | 4.76 | 93 |

真实编译器的切换表（同文件）：dtype / requires_grad / layout / 语义不同的 flag 切换都触发重编译且 cold==warm、A→B→A 一致；
`compile.dynamic` 不能作为 warm 切换因子（编译选项在 compile() 时固定），已改为 cold-only 义务。

### RQ2 基线对比（`results/RQ2.md`，预算 12，同一 harness、同一 oracle、同一注入缺陷集）

| 生成器 | bugs found | unique failure clusters | tests | valid rate | TTF | FP(fixed) | BugDetectionRate | TestEfficiency |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| B1 随机（输出型 oracle，3 种子均值） | 11.33/19 | 11.7 | 465 | 0.81 | 0.38 s | 0 | 0.596 | 0.025 |
| B1 随机 + O1–O7 全部 oracle | 14/19 | 18.0 | 355 | 0.77 | 0.32 s | 0 | 0.737 | 0.051 |
| B3 NNSmith（8 个模型，原生单输入 + 全部 oracle） | 6/19 | 6.0 | 152 | 1.0 | 1.01 s | 0 | 0.316 | 0.040 |
| B3 NNSmith 模型（4 个）+ 本方法上下文/序列 | 9/19 | 9.0 | 496 | 1.0 | 2.53 s | 0 | 0.474 | 0.018 |
| B5 本方法 | **19/19** | **23.0** | 235 | 0.94 | 0.34 s | 0 | **1.0** | **0.098** |

读法：NNSmith 的强项是图结构多样性，它的程序上找不到 Python 语义因子（`SymbolNet.forward` 是通用解释器），
所以即使套上本方法的上下文（只剩默认的 dtype/requires_grad/compile flag 义务）也只到 9/19；本方法的检出来自"程序本身读了哪些因子"这一信息。
随机基线换成全部 oracle 后从 11.33 升到 14，说明约 1/3 的差距来自 oracle，其余来自生成器；本方法用最少的测试数（235）达到最高的 TestEfficiency（0.098，约为随机的 4 倍）。
FreeFuzz / TorchProbe / TitanFuzz / DeepREL 未安装：`baselines.py` 保留 Setting B 接口（把工具产出导出成 `f`+`args` 的 `.py` 后用 `--from-dir` 或 `--external` 载入）。

### 实验 A–E（`results/EXPERIMENTS.md`，预算 12，最终代码）

| 实验 | 结果 |
|---|---|
| A shape 边界 `x.shape[0] >= 32` | 缺陷在 31（k−1）：本方法第 9 个测试检出，随机 5 个种子 0/5；缺陷在 32（基准形状）：两者都在第 1 个测试检出；`%16` 尾部（17）：本方法检出 |
| B dtype 特化（`underspec_dtype`） | 只做 cold：漏；cold + warm：第 4 个测试检出（specialization_cache）；`cache_stale_on_return`：第 3 个测试经 A→B→A 检出 |
| C 控制流 `flag and x.shape[0] > 32` | T/T、T/F、F/T、F/F 四格全部被生成并执行（`complete: true`）；随机上下文没有覆盖全表 |
| D alias/mutation | 4 组（view_inplace / overlapping_views / alias_returned / noncontig_copy）：输出型 oracle 0/4，mutation+alias oracle 4/4，均第 1 个测试检出 |
| E A→B vs reset→B | 真实编译器：一致；`underspec_dtype`、`cache_result_memo`：A→B ≠ reset→B 且无重编译 → specialization_cache；`cache_stale_on_return`：A→B 一致但 A→B→A 不一致 → cache_invalidation |

### RQ5 真实编译器（`results/rq5_campaign.log`，`reports/CAMPAIGN.md`）

- torch 2.14.0+cpu Inductor（MSVC C++ codegen），29 个内置程序 + 6 个 NNSmith 模型，每程序 24 项测试（分层 + warm 矩阵），确认重跑 2 次，开启最小化。
- 838 项测试、约 4700 次编译、0 候选、0 报错、无 infra 失败。
- 结论：在本机版本上没有发现新缺陷，也没有误报（fp64 规则 + 精确重编译计数在真实编译器上是干净的）。
- 第二轮（`results/rq5_campaign2.log`，`reports_campaign2/`）：20 个 NNSmith 模型 + 29 个内置程序，1174 项测试，51 分钟，0 可提交候选。
  `--keep-info` 记录了 42 条非提交级记录：1 条 low（NNSmith 模型在 resize 后 eager 抛 `RuntimeError`、Dynamo 抛包装后的 `TorchRuntimeError`，已在 O3 中把包装类型规范化为被包装类型，此类不再上报）；41 条 info 级"切换后未重编译且结果相同"，其中 29 条 `requires_grad`、7 条 `substitute`、1 条 `device` 是上下文构造出的输入与 base 完全相同（例如基准已是 no-grad），已加过滤（输入指纹与 base 相同的上下文直接丢弃）；剩余 4 条（NNSmith 模型的 dtype/layout/requires_grad 切换、overlapping_views 的 layout 切换）是真正的 guard 弱信号，按计划 §15 记录用于指导后续变异，不构成缺陷。
- 第三轮：官方测试种子（§21 "官方 compiler tests"）。`--opinfo 120 --no-corpus`：PyTorch OpInfo 数据库的 120 个算子样本（别名声明算子优先），Inductor，每程序约 16 项测试，11 分钟（`results/rq5_opinfo.log`，`reports_opinfo/`）。
  **2 条 low 级候选，均为 `compile.dynamic=True` 上下文下"编译抛异常而 eager 正常"（O3，Dynamo 捕获阶段）：**
  1. `torch.cov(x, correction=0, aweights=w)`：`torch.compile(dynamic=True)` 抛 `Cannot call numel() on tensor with symbolic sizes/strides`（cov 的分解读取了符号形状的 `aweights.numel()`），eager 与 `dynamic=False` 正常。**已独立复现并人工确认**（`reports_opinfo/7972f93b54ff/minimal_verified.py`）。§18.5 查重（GitHub search API，2026-09-08）：**重复** —— PR pytorch/pytorch#190669（2026-07-21 开，未合并）正在给 `aten.cov` 加 Python 分解，根因描述完全一致（C++ 复合实现的权重校验对符号形状张量调 `.numel()`）；同一错误类在 one_hot/gather/scatter/quantile/combinations/linalg.cond 等算子上各有 issue。台账状态改为 Duplicate，不提交；细节见 `reports_opinfo/7972f93b54ff/DEDUP.md`。这仍是本方法在真实编译器上按 §18.1 全流程（检出→重跑确认→人工复现→查重）走完的第一条 source–artifact 不一致：触发因子是编译选项 `dynamic`，正是 §10 中 `compile_flag` 义务生成的上下文。
  2. `aten.max_pool2d_with_indices_backward` 的 OpInfo 样本在 `dynamic=True` 下追踪失败；用连续/非连续输入手工复现均通过，需要 OpInfo 原样本（含特定 padding/dilation 与布局）才能触发，暂列 Pending，待用记录中的 `execution_trace.json` 精确重建输入后再判定。
- 第四轮：全部 OpInfo（`--opinfo 703 --seed 2 --no-corpus`，545 个可运行样本，Inductor，97 分钟，`results/rq5_opinfo_all.log`，`reports_opinfo_all/`）。11 条候选，逐条走 §18.1：
  - **`torch.var_mean(torch.randn(0))`：eager `(nan, nan)`，Inductor `(nan, 0.)`，mean 分量错误**。E0=E1=E2、仅 E3 不同 → inductor_codegen（§16 归因）；`mean/var/std` 单独在 Inductor 下正确，`(3,0)` 沿 dim=1 正确，`dynamic=True` 同样复现；四个上下文 2/2 复现。手工验证 `reports_opinfo_all/0211b330cc67/minimal_verified.py`。查重（`DEDUP.md`）：#113167（2023 关闭，标量输入 + 非法 correction）相关但不同，#145401 是精度问题，#61901/#191229 说明"空维度归约返回 NaN"是维护者认可的语义 → **非重复**。可提交稿 `ISSUE_FINAL.md`，台账 Generated（提交与否由人决定）；另外三个上下文的记录本地聚类为 Duplicate。
  - `soft_margin_loss` fp16：eager 溢出为 `inf`，Inductor 内部升精度得到有限的正确值。这不是缺陷，是 O1 的 NaN/Inf 判据没有服从 fp64 参考 → 已修：有 fp64 参考时只有"编译结果的 NaN/Inf 模式与真值不同"才报。标 Invalid。
  - `new_empty` / `new_empty_strided` 5 条（cache_invalidation / compile_nondeterminism，复现 0/2–1/2）：返回未初始化内存，比较无意义 → 已加 §18.1 步骤 1 的确定性门控（eager 自身两次不一致的程序整体跳过）。标 Invalid。
  - `cov`（Duplicate，同第三轮）。
  - `max_pool2d_with_indices_backward`：已精确重建 OpInfo 样本并隔离触发条件——OpInfo 的 `max_pool2d_backward` 包装函数直接调 aten 算子，`kernel_size=3` 这个 int 经函数参数传入，`dynamic=True` 下成为 SymInt，`int[2]` 形参拒绝 SymInt 标量（eager 会广播成 `[3,3]`）；传 `[3,3]` 或走 `F.max_pool2d` 都正常。与 #122129（open）同一错误类 → Duplicate/相关，不提交（`reports_opinfo_all/6468272fac80/DEDUP.md`、`minimal_verified.py`）。
  - 台账：Pending 1（var_mean，用户决定暂不提交，见 `TO_SUBMIT.md`）、Duplicate 5、Invalid 5。
  - 顺带发现并修复：最小化器对空张量重复应用"simplify values"直到预算耗尽；OpInfo 程序的复现脚本现在会带上 OpInfo 包装函数的真实源码而不是 `torch.<name>` 的假象。
- 第五轮：OpInfo `--seed 3`（另一组样本，540 个可运行，99 分钟，`results/rq5_opinfo_s3.log`，`reports_opinfo_s3/`）。21 条候选，分诊结果：
  - **`F.multi_margin_loss` float16 CPU：eager 抛 `NotImplementedError`（Half 无 CPU kernel），`backend="eager"` 同样抛，aot_eager/inductor 经分解正常返回**——E1 与 eager 一致、E2 起不同 → AOTAutograd/分解阶段（§16）。查重：#144362（open，"compile 缺少 eager 有的 dtype 检查"）的一个实例，#193811 同类 → Duplicate（`reports_opinfo_s3/11ddea7fd13c/DEDUP.md`）。
  - 8 条 low：eager 抛 `ValueError`（形状/维度校验），Dynamo 抛 `TorchRuntimeError` 包装同一个 `ValueError`（`__cause__` 链末端）。之前的 O3 规范化按消息开头取到了包装层自带的 "RuntimeError" 字样而失效 → 已改为记录 `__cause__` 链最内层异常类型并以之比较，消息截断从 400 放宽到 1500 字符。标 Invalid。
  - 13 条 `new_empty`/`new_empty_strided`：eager 两次一致的确定性门控挡不住"两次分配碰巧相同"的未初始化内存 → 已在 OpInfo 种子加按名排除清单（`empty*`、`new_empty*`、`rand*`、`dropout`、分布采样等：前者无 oracle 可用，后者 compile 与 eager 随机流不同是文档化行为）。标 Invalid。
  - `max_pool2d_with_indices_backward` 再次命中，Duplicate。
  - 台账：Duplicate 2、Invalid 21 中的其余；无新的可提交发现。
- 第六轮：每算子 3 个不同样本（`--opinfo 3000 --opinfo-samples 3 --seed 4`，1393 个可运行程序，4.4 小时，`results/rq5_opinfo_s4x3.log`，`reports_opinfo_s4x3/`）。动机：`var_mean` 的发现来自 OpInfo 的一个边角样本（空张量），单样本抽取覆盖不到大部分边角。28 条候选：
  - 20 条 `var_mean` / `std_mean`（5 个程序 × 4 个上下文，2/2 复现）：**同一缺陷家族的扩展**——`std_mean`、`unbiased=False`、形状 (0,1)、fp16 均为 mean 分量返回 0；`dim=` 归约空维度则正确。已手工验证并并入待提交稿（`ISSUE_FINAL.md` 已更新为 `var_mean`/`std_mean`），台账归为该发现的 Duplicate。
  - 3 条 `hinge_embedding_loss`（reduction='sum'，margin≈8.4）：输出 −0.62，编译误差 1.1e-6 vs eager 1.8e-7，超过 4× 预算；但求和中间量约为 8，1e-6 只是中间量的 1 ULP，属于重结合的合法差异——本方法的 ULP 噪声底按输出幅度缩放，在"大项相消成小输出"时偏紧。按计划 §17.1"用项目自身判据"，已让 `torch._dynamo.utils.same(fp64_ref=…)` 对纯数值发现拥有否决权（NaN/Inf 模式差异除外，因为 `same` 对 NaN 宽松，会放过 `var_mean` 那条真缺陷）；被否决的发现保留在 `comparisons[*].suppressed` 里。标 Invalid。
  - 5 条已知重复（`cov` ×2、`max_pool2d_with_indices_backward` ×3）。
  - 台账：Duplicate 25、Invalid 3；无新的独立发现。
  本机没有安装任何带 `torch.compile` 站点的真实项目（只有 torch、nnsmith、numpy），§21 的"真实项目 compile 函数"种子源暂无法在本机使用。
- 第七轮（2026-09-08 晚启动）：§11 第 2 类种子——**issue reproducer**。新增 `tcc/mine.py`（`run.py mine`）：用 GitHub search API 在 pytorch/pytorch 中按 6 组查询词拉取含 `torch.compile` 代码块的 issue，抽出代码写成 `reproducers_gh/issue_<n>_<title>.py`（197 个；另 241 个因无 compile 调用、需 CUDA、依赖外部权重等被拒，`reproducers_gh/MANIFEST.json`）。载入器新增**录制模式**：脚本里的 `torch.compile(...)` 被替换为录制器，记录编译目标与第一次调用的实参作为种子（issue 脚本几乎不定义 `args`）；每个文件先在子进程里带超时试载，原生崩溃/死循环只损失该文件。146/197 载入成功（21 个是 nn.Module 目标，分析其 `forward`）；修正 `eval(` 误判（`model.eval()` 被当成内置 `eval`）后为 161 个。campaign 输出 `reports_gh/`，日志 `results/rq5_gh.log`，开启 `--search-duplicates`。
  进度（关机时）：110/161 完成；中途一次因 flex_attention 脚本在 `BlockMask.__repr__` 抛错把主进程带崩，已把 3 个 flex_attention 脚本移到 `_skip/` 并续跑（`observe()` 也已加固：异常消息不可打印时不再向上抛）。
  **2026-09-09 跑完（161 个程序，续跑后合并）**，`reports_gh/KNOWN_BUGS.md`：open 63 个中检出 12（0.19），closed 98 个中检出 12（0.12）。
  - open 未检出的 51 个：29 个跑了上下文但无分歧（多为 CUDA 专属、性能/graph break 类、或需 nightly），8 个只跑了 base，14 个"0 测试"——原因是这类 issue 是"eager 拒绝、compile 静默接受"，我们的 `valid_contexts` 把 eager 抛异常的基准上下文当无效丢掉了。**已修**：基准上下文即种子本身，eager 在其上抛异常属于程序语义，保留给 O3 比较。重跑这 14 个（`reproducers_gh_rerun/`, `reports_gh_rerun/`）后其中至少 6 个被检出（#185246、#185248、#185481、#193757、#193811、#194501，全部是 "compile silently accepts what eager rejects"）。
  - **closed 但仍检出的 12 个是本轮最重要的产出**。torch 2.14.0 发布于 2026-09-02（GitHub release），这 12 个 issue 都在此之前关闭为 completed。用 issue 自带脚本（不经 harness）原样重跑确认了 6 个：#181693 hardswish 误差 1.90、#181695 where 广播误差 3.93、#183601 InstanceNorm 误差 1.97、#177821 复数索引赋值精确不等、#181568 matmul→bf16 误差 3.1e-2（510/510 元素）、#193279 custom backward 被丢弃（梯度全 0）。修复提交与 `v2.14.0` 标签的 compare：#172711、#193279 的修复在分支切割之后（diverged → 不在 2.14.0，检出是预期的）；#174386、#182131、#184405 的修复**在** 2.14.0 中（behind）却仍复现 → 回归或修复不完整的候选（其中 #174386/#184405 复现 1/2 次，#182131 误差 3.9e-4，需人工判断）；其余 7 个关闭事件无提交，读关闭评论后分类：#160840（decomposition 使近似相等值不同、argmin 翻转，维护者判为预期）、#181568（用 `TORCHINDUCTOR_EMULATE_PRECISION_CASTS` 可缓解，agent 关闭）、#181693（`torch.randn` 在被编译函数内 + `F.normalize` 放大，判非缺陷）、#181695（instance_norm 均值≈0 后阈值化的舍入噪声，判非缺陷）、#183601（归约顺序差异被 `F.normalize(eps=1e-12)` 放大，判 INTENDED）→ 这 5 个标 Invalid，是 §18.6 "documented unsupported behavior" 一类，也说明我们的 fp64 规则会和 issue 报告者一样被"病态放大"骗到——值得在论文里作为 oracle 局限讨论；#177821 复数索引赋值精确不等，关闭时**无评论无 PR**，#176679 只留下"能复现"就关闭 → 这 2 个加上 3 个"修复在 2.14.0 内却仍复现"的（#174386、#182131、#184405）列入 `TO_SUBMIT.md` 待人工复核。
  台账（`reports_gh/CAMPAIGN.md`）：Pending 5 个 issue 的记录，Invalid 5 个 issue 的记录，其余全部 Duplicate（复现的是各自的 open 来源 issue）。
  已出现的候选（都是来源 issue 本身在 2.14.0 上仍复现，即"已知缺陷检出"）：#160840 interpolate+argmin、#174386 `use_deterministic_algorithms` 下 `empty_like`、#176679 tensor subclass `__torch_function__`、#177821 complex、#181693 hardswish、#181695 where 广播、#182131/#183601 inductor 数值、#183607 fp16 溢出行为、#184405、#172711、#189787 sum/softmax 常量折叠；#114415 subclass 别名（compile 抛 InternalTorchDynamoError）。这一轮的意义是 §21/§25 RQ1 的"历史缺陷"检出：在同一版本上，open issue 应能复现、closed issue 不应复现，`scripts/gh_summary.py` 会按 issue 状态汇总。

---

### GPU 结果（Kaggle T4，torch 2.10.0+cu128，2026-09-09；`results0909/` 为原始下载，已拷入 `gpu_reports_*`）

| campaign | 程序 | 测试 | 记录 | 已知缺陷检出（open / closed） |
|---|---:|---:|---:|---|
| `gpu_reports_gh`：336 个 CUDA 版 issue reproducer（`mine --allow-cuda`） | 336（58 个子进程被拒/崩溃） | 2371 | 234（high 145） | open 34/100，closed 75/236 |
| `gpu_reports_gh_cpu_set`：CPU 那批 193 个在 Triton 路径重跑 | 193 | 1371 | 137（high 85） | open 27/70，closed 37/123 |
| `gpu_reports_corpus`：内置语料 + 10 NNSmith | 39 | 570 | 0 | 无误报 |
| `gpu_reports_opinfo` | 0 | – | – | 环境缺 `expecttest`，未跑（已补进 bootstrap） |

按阶段：inductor_codegen 129 + 72、dynamo_capture 89 + 52、aot_functionalization 16 + 13。
closed 而检出的 112 条按 issue 创建/关闭时间对照 2.10.0 发布日（2026-01-21）：创建于发布之后的 92 个 → 缺陷本就在 2.10 中、修复在其后，检出是预期（Duplicate）；创建于发布前的 17 个再查关闭时间：11 个关闭于 2026-01-21 之后（修复不在 2.10，预期），#160840 维护者判为预期行为，#171258/#171366/#170642 关闭于分支切割前后（修复大概率未进 2.10），剩 2 个复核：#122381（2024-05 关闭，CUDA attention）读脚本后判为 Invalid——模型含 training 模式的 `nn.Dropout`，误差 1.11 是 dropout 随机流不同（与 CPU 第七轮 #181693 的 `randn` 同类），载入器已改为含 Dropout 的模块目标自动 `eval()`；#113641（2023-11 关闭，双重 inplace clamp）在 2.10 上 Dynamo 抛 `InternalTorchDynamoError` 而同一脚本在本机 2.14.0 三路一致 → 2.10 特有、后续已修的崩溃，列入 `TO_SUBMIT.md` 待 GPU 复核但预期不提交。
另：open issue 在 2.10 上的检出率（34%/39%）高于 2.14.0 上的（19%），符合"越旧的版本未修缺陷越多"的预期，也说明同一批 reproducer 在两个版本上的差集可以直接当 §21 的 buggy/fixed 对照使用。

### 新角度：分解/meta 差分（NEXT_DIRECTIONS §5.1/5.2，2026-09-09 起）

`tcc/decomp_diff.py`（`run.py decomp`）：用 `TorchDispatchMode` 把每个 aten 算子换成 `torch._inductor.decomposition` 里的分解直接执行（不经 Dynamo/Inductor），与 eager 核函数按 fp64 规则比对；同时在 FakeTensorMode 下比 shape/dtype/stride。每个 OpInfo 样本派生 12 个边角变体（空维、size-1、素数尺寸、非连续、NaN/Inf、1e30、1e-30、fp16、bf16）。8 个算子 348 个变体 4 秒。不一致再用 `torch.compile` 确认。
首批结果（`results/decomp_smoke/`，均已在 Inductor 上确认）：
- **`torch.std/var/var_mean/std_mean` 对 1e30 量级 float32 输入返回 NaN**，eager 的 `std` 为 9.56e29 且等于 fp64 真值（Inductor 方差按 E[x²]−E[x]² 溢出为 inf−inf）。查重：#173793（open，LayerNorm/CUDA/1e37）同根因，#173989 只修了 LayerNorm CPU → 新实例，入 `TO_SUBMIT.md` 第 2 条（`reports_decomp/std_var_large_values/`）。
- `index_add` 到空维：Inductor 内核越界断言而 eager 正常 → PR #186532（2.14 分支切割后合并）描述的正是这一失败模式，Duplicate。
全量扫描（`results/decomp_full/`，`run.py decomp --isolate --samples 2`，2026-09-09 晚）：576 个算子、1 110 个样本、11 911 个变体、5 506 个变体至少命中一个分解，约 15 分钟。分解不一致 100 条（Inductor 确认 ~40 条）、meta 不一致 7 条、1 个原生崩溃（`linalg.eigvals` 含 NaN 输入，MKL 直接中止进程，eager 问题，#93124 已关闭仍复现）。为此把扫描改成分块子进程（`--isolate`，每块 25 个算子，崩溃块逐算子重放并记 `crash`，JSONL 增量落盘可续跑）。修过的 harness 误报：复数输出按 (re, im) 浮点比较；克隆保持步长（`clone()` 会把切片变连续，导致 view 类算子 meta stride 假阳性）；size-1 维的 stride 不算显著；kwargs 里嵌套张量列表用 pytree 转 FakeTensor。
逐条确认（`scripts/confirm_decomp2.py OP VARIANT` 重跑该算子全部样本；`scripts/confirm_decomp_batch2.py` 手写最小复现）后的分类：
- **新候选 3 条**（入 `TO_SUBMIT.md` 第 3–5 条，各有 `reports_decomp/<name>/minimal_verified.py` + `DEDUP.md`）：
  - `F.interpolate` 空的空间维（(2,3,0) → size 3）：eager 抛错、aot_eager IndexError、**Inductor 返回全 NaN 的 (2,3,3)**（越界读 0 元素缓冲区）；输出尺寸为 0 的反向情形 compile 静默返回空张量。分解（`upsample_*.vec` 的 CompositeImplicit py_impl）先于 meta 检查执行且不校验尺寸。
  - `linalg.vector_norm(ord=inf/-inf/<0)` 空 batch（(0,5)，dim=-1）：eager 返回 (0,)，compile 在 fake-tensor 路径抛"cannot compute the inf norm on an empty tensor"。根因在 `_refs/linalg` 的 `_check_vector_norm_args` 用 `numel()` 而非 `shape[dim]`。
  - `F.binary_cross_entropy` bf16/fp16 输入 + fp32 weight：Inductor 输出 float32，eager/aot_eager 保持 bf16；#171282（with_logits 版）已修而 plain 版未修。
- 已知/同族不报（记入 `TO_SUBMIT.md` 不提交表）：`index_reduce` 越界 index（#186532/#185977 族）、`cross_entropy`/`linear_cross_entropy`/`multi_margin_loss`/`multilabel_margin_loss` 半精度缺检查（#144362 族）、`native_batch_norm` N=1 ZeroDivisionError（legacy 算子）、`multilabel_margin_loss` NaN（eager 端吞 NaN）、`max_pool2d` 全 padding 窗口索引（两侧都无意义）。
- harness 侧假阳性（`confirmed=False`，compile 与 eager 一致）：`pad/bmm/stft/pinv/pca_lowrank/svd_lowrank/softsign/gaussian_nll_loss/multilabel_soft_margin_loss` 等——直接调用分解时缺少 Inductor 前置校验或 Python 标量参数类型不同，不计。
产出率：一次 15 分钟无 GPU 扫描给出 3 条新候选 + 1 条已在 TO_SUBMIT 的（std/var 1e30），高于此前七轮约 4 000 程序的编译式 campaign（1 条）。

**扩展（2026-09-10）**：
- `--grad`：把前向+反向包成一个函数（输出 + 每个浮点输入的梯度，固定随机权重加权求和后 `autograd.grad`），整个在 DecompMode 下跑，反向算子也走 `*_backward` 分解；确认时编译前向再对编译产物求导（AOTAutograd 路径）。冒烟即命中：**`torch.std` 对 1e-30 量级输入编译后前向 0、梯度全 0**（eager/fp64 正确），前向扫描因绝对噪声底看不见——并入 TO_SUBMIT 第 2 条（`minimal_verified_tiny_grad.py`）。全量在后台：`results/decomp_grad/`。
- 新变体：`prime_all`（每维不同素数）、`zero_dim`、`channels_last`、`dtype_int64`、`dtype_bool`；`--variants` 可限定。换种子全量在后台：`results/decomp_full_s1/`。
- 复现脚本独立运行需要 MSVC 环境（VS 开发者命令行），或经 `tcc.compat.ensure_msvc_env()`。
- 换种子 + 新变体全量（`results/decomp_full_s1/`）：580 个算子、15 545 个变体、11 分钟；分解不一致 161、meta 34。分诊（`scripts/decomp_triage.py`，自动隐去已登记的族）：新增 **`channel_shuffle` 在 Inductor 下丢失 channels_last 布局**（TO_SUBMIT 第 7 条，同族 #187195/#179830/#179837 已修）；`pixel_unshuffle` 空 batch 是 eager 侧缺陷（open #192816，Inductor 反而正确）；`expand(-1, 5, 5)` 在 0 维张量上 eager 返回形状 (-1,5,5) 的张量（eager 侧缺陷，未见报告）；`dtype_int64/bool` 变体命中约 40 个算子的 #144362 族（eager 无整数 kernel 抛 NotImplementedError、compile 照算），已作为该 issue 的补充清单登记。
- 反向全量（`results/decomp_grad/`）：570 个算子、7 979 个变体、14 分钟；除已知族外新增 `hardswish` / `smooth_l1_loss` 含 NaN 输入时梯度 NaN 模式不同（语义争议，不报）。唯一的原生崩溃定位（`scripts/find_crash_variant.py nn.functional.pdist --grad`）为 **`F.pdist` 零行输入的 backward 让进程以整数除零退出**（eager 侧硬崩溃，TO_SUBMIT 第 10 条，`reports_decomp/pdist_empty_backward_crash/`）。meta 侧 200 条"Please convert all Tensors to FakeTensors"是 harness 的加权张量在 FakeTensorMode 下创建的问题，已改为 `arange` 构造（fake 兼容）。
- DecompMode 假阳性根因：部分 Inductor 分解对 Python 标量参数返回 `NotImplemented` 表示"回退默认实现"，模式未处理 → `Tensor + 1` 抛 TypeError；已加回退，softsign / gaussian_nll_loss / pca_lowrank / svd_lowrank / stft 等约 60 条假阳性消失。

### 新角度：编译产物间的变形关系（NEXT_DIRECTIONS §5.3，2026-09-09 晚起）

`tcc/metamorphic.py`（`run.py metamorphic`，支持 `--isolate`）：两侧都是编译结果，eager 只用来**验证关系在该算子/样本上成立**（不成立则计 not_applicable），不作参考值：
- `config`：同一函数在 9 组 Inductor 配置（`cpp.simdlen=1`、`split_reductions=False`、`unroll_reductions_threshold=1`、无融合、无 pattern_matcher、`inplace_buffers=False`、`cpp_wrapper`、`emulate_precision_casts`）+ `dynamic=True` 下分别编译，与默认配置互比；
- `split`：`f(x)` 与 `cat(f(x[:k]), f(x[k:]))`（k = 1、n/2、n−1）；
- `layout`：`f(x)` 与 `f(非连续副本)`；
- `reuse`：同一编译产物、同一输入对象连续调用两次。
每条违背同时记录"普通 eager-vs-compiled oracle 是否也已不同"，以区分变形关系独有的发现。冒烟：7 个样本 88 次编译 92 s、0 违背。
全量（`results/meta_full/METAMORPHIC.md`，2026-09-10 上午续跑完成）：572 个算子、7 360 次编译、7 212 次关系检查（448 次关系在 eager 上就不成立，跳过）、**3 条违背，全部来自 `dynamic=True` 这一配置**，9 组 Inductor CPU 配置与批切分/布局/复用四种关系在单算子程序上 0 违背（说明这些配置在单算子层面是一致的，配置差分要放到多算子融合图上才有意义，见待办）。三条中 cov（#190669）与 max_pool2d backward（#122129）是已知，`masked.argmin` 是新的：
- **CPU Inductor `dynamic=True` 下 arg-reduction 索引表达式把 Python 的 `**` 写进 C++**：`(x + m).argmin()`，x (3,4,4)、m (1,4,4) 广播且内维尺寸相等（duck sizing 合成同一符号 → `ks1**2`），生成 `argmin_combine_vec<...>(..., ks1**2*x0 + x1)`，C++ 编译失败；static / aot_eager / 逐维 / amin 都正常，内维尺寸不等也正常。根因在 `torch/_inductor/codegen/cpp.py` 3749 与 256 行（`str(index)` 而非 `cexpr_index`）。查重未见同报告 → `TO_SUBMIT.md` 第 6 条，`reports_metamorphic/argmin_pow_dynamic/`。诊断脚本 `scripts/diag_argmin_dynamic.py`（打印生成的 C++ 出错行）、`scripts/confirm_dynamic.py OP`（某算子全部样本过 dynamic=True）。

**配置集扩展（2026-09-10 午）**：加入可选配置 `max_autotune`（`max_autotune` + `max_autotune_gemm`，CPU 上启用 C++ GEMM 模板自动调优）与 `freezing`（默认不跑，慢）。只在 15 个 GEMM/conv 算子 × 3 样本上跑（78 次编译、63 s）就得到 4 条违背、两条新候选：
- **Windows CPU 上 `max_autotune` 的 `bmm` / 批量 `matmul` 必然失败**：`cpp_bmm_template.py` 第 44 行的 `extern "C"` 漏了 `{{export_declaration}}`（gemm / grouped_gemm 模板都有），基准 DLL 里找不到 `cpp_CppMicroGemmFP32Vec` → TO_SUBMIT 第 8 条。
- `max_autotune` + `addmm(标量 bias)`：`kernel/mm.py` 714 行先索引 `get_stride()[0]` 再查秩 → IndexError；同一行有 open PR #185578 但不覆盖 0-d → TO_SUBMIT 第 9 条。
这说明配置差分的产出在"非默认配置 × 边角输入"上。全算子 `max_autotune`（`results/meta_autotune_all/`，583 个算子 × 2 样本、2 237 次编译、25 分钟）：3 条违背（bmm ×2、`linalg.matrix_power` 空 batch），经 `scripts/diag_autotune2.py` 确认全部是第 8 条同一根因（任何走 bmm 的路径：批量 matmul、matrix_power n≥2）；`mm` 的空维输入正常。反向差分换种子（`results/decomp_grad_s1/`，562 个算子）在 kwargs 张量修复后 meta 误报从 190 降到 5，无新发现。`dynamic=True` × 3 样本换种子（`results/meta_dynamic_s1/`，583 个算子、3 264 次编译、52 分钟）：3 条违背全部已知（cov #190669、max_pool2d backward #122129、masked.argmax = 第 6 条）。

### 新角度：多算子图上的配置差分 / 真实模型（NEXT_DIRECTIONS §5.3 补充、§5.7，2026-09-10）

- `run.py metamorphic --source nnsmith|corpus|both`：同一套四种关系跑在 NNSmith 生成的多算子图（`--models N --max-nodes 15`）和语料程序上——融合、缓冲区复用、向量化这些配置只在多算子图上才有区别。冒烟 8 个程序 96 次编译 0 违背；全量（`results/meta_graph/`，30 个 NNSmith 图 + 28 个语料程序 × {dynamic, no_fusion, no_inplace, no_vec, cpp_wrapper} + reuse，348 次编译，32 分钟）**0 违背**。结论：2.14 CPU 上这五组配置在小型多算子图上一致，配置差分的产出集中在 `max_autotune` 与 `dynamic=True` × 边角输入。
- `scripts/make_model_reproducers.py` → `reproducers_models/`（73 个文件）：torchvision 14 个小模型（resnet18、mobilenet v2/v3、squeezenet、shufflenet、efficientnet_b0、regnet、mnasnet、convnext_tiny、densenet121、googlenet、小 ViT、小 Swin、FCN 式分割头）× {fp32、channels_last、bf16 autocast、train、dynamic=True} + 5 个 torchvision.ops（roi_align、nms、box_iou、deform_conv2d、StochasticDepth/FrozenBN），随机权重、固定种子、64×64 输入，走 `--from-dir` 录制模式（含 BN 的模块由 `Program.reset` 恢复状态）。本机装了 torchvision 0.29.0+cpu（`--no-deps`，未动 torch）。resnet18 一个程序 4 个上下文约 260 s，整批在后台：`reports_models/`（`--max-contexts 4 --test-budget 6 --time-budget 300`）。Kaggle 打包已包含该目录，`kaggle/campaign_gpu.sh` 新增第 0 步（decomp / metamorphic / binding 三个扫描在 GPU 上）和第 2 步（真实模型）。

### 新角度：跨进程磁盘缓存差分（NEXT_DIRECTIONS §5.6 / 计划 §14，2026-09-10 下午）

`tcc/cache_diff.py`（`run.py diskcache`）：每个案例是一段带 `{V}` 占位的脚本；进程 A 用 v1 在空缓存目录编译并运行，进程 B 用 v2 对同一目录编译运行（`TORCHINDUCTOR_CACHE_DIR` 共享，FX 图缓存与 AOTAutograd 缓存打开），两进程各报 eager/compiled 输出与缓存计数器。判定：B miss = 键覆盖了改动；B hit 且结果对 = 该值是运行时输入；**B hit 且结果错 = 键漏了烘焙值（缺陷）**。先跑对照（同源两次，B 必须命中）证明目录确实共享。
29 个案例（`results/diskcache/DISKCACHE.md` + `results/diskcache_extra/`，约 15 分钟）：闭包/全局浮点与整数（含 view 尺寸、切片）、图内 `torch.tensor` / `torch.full` / `arange` 常量（1、100、10 000 元素）、全局张量、闭包张量、对象属性、默认参数、`math.pi`、字符串 mode、bool 分支、元组 kernel_size、`set_default_dtype`、`set_float32_matmul_precision`、`use_deterministic_algorithms`、`set_grad_enabled`、`set_num_threads`、`requires_grad`、Inductor 配置（simdlen、epilogue_fusion、freezing 冻结参数）、Dynamo 配置（capture_scalar_outputs）、`dynamic=` 编译选项。结果：**0 例陈旧命中**，27 例 miss，2 例 hit-ok（全局张量与闭包张量作为图输入被 guard）。结论：2.14 的缓存键对烘焙常量与进程级状态是完备的，§14 的这一疑虑可以关闭；写论文时作为"消融/负结果"报告。

### 新角度：export + AOTInductor 路径（NEXT_DIRECTIONS §5.8，2026-09-10 下午）

`tcc/aoti_diff.py`（`run.py aoti --isolate`）：每个 OpInfo 样本包成 `nn.Module`，跑 eager / `torch.export(...).module()` / `aoti_compile_and_package` + `aoti_load_package` / `torch.compile(inductor)`，前两条编译路径与 eager 按 fp64 规则比对，并标注该分歧 torch.compile 是否也有（共享 = Inductor 缺陷经两个前端可见；仅 AOTI = export/AOTI 管线自身）。Windows CPU 上 export + AOTI 可用（MSVC 编 C++ wrapper，约 9 s/样本）。冒烟 14 个样本 0 分歧。全量（`results/aoti_full/AOTI.md`，509 个算子、约 1 小时）：export 成功 497 / 失败 7，AOTI 打包成功 464 / 失败 33，分歧 7 条——2 条与 torch.compile 共享（var_mean/std_mean 空张量）、dropout2d/3d（training=True 的随机流，无效）、`item` 返回结构（export 语义）、`hash_tensor`（AOTI 不支持该新算子）。三次子进程访问违例（slice_scatter、kron、repeat_interleave）逐样本单独跑全部正常，60 次连续加载也不崩，判为 Windows 上 AOTI 包加载器临时目录处理的偶发问题（日志里持续有"Failed to remove temporary directory"），未能稳定复现，不报。分类：
- `var_mean` / `std_mean` 空张量在 AOTI 路径上同样返回 mean 0 → 第 6 条 issue 补上"第二前端也复现"的证据；`x.item()` 类返回 Python 标量的算子 AOTI 返回张量（结构差异，export 的既定语义，不报）。
- **AOTI 打包失败 33 个算子**：33 个里 30 个是同一原因——返回 `torch.return_types.*` 命名元组（max/min/sort/topk/mode/kthvalue/nanmedian/cummax/cummin/aminmax/frexp/histogram/svd/geqrf/lu_unpack/triangular_solve 与 `linalg.*` 的 eig/eigh/qr/slogdet/lu/lu_factor/ldl_factor/cholesky_ex/inv_ex/polar…）打包时"No registered serialization name"（TO_SUBMIT 第 11 条）；3 个 `split*` 是 harness 传参形态（list/tuple）与导出输入 spec 不一致，不计；1 个 `instance_norm`：running stats 为闭包捕获张量时 export 静默接受对提升常量的原地更新、`run_decompositions` 正确报错、AOTI 抛 INTERNAL ASSERT（TO_SUBMIT 第 12 条，`scripts/diag_aoti_instance_norm2.py` 定位到步骤）。
- 子进程在 `slice_scatter` 处访问违例：9 个样本逐个单独跑全部正常（`scripts/find_aoti_crash.py`），判为同一进程连续加载几十个 AOTI 包的累积问题（`scripts/diag_aoti_many_loads.py` 验证中），与算子无关。

### 新角度：绑定形式因子（NEXT_DIRECTIONS §5.4，2026-09-10 起）

`tcc/binding.py`（`run.py binding`，支持 `--isolate`）：对 OpInfo 样本里的每个 Python 标量参数（int/float/bool/str/int 元组，优先 int），生成 11 种绑定形式的函数（字面量、位置参数、默认参数、`**kwargs`、闭包、模块全局、对象属性、列表元素、字典元素、`**opts` 展开、`tensor.item()`），每次只改一个标量的绑定方式；每个变体做三种检查：`static`（compile vs eager）、`dynamic`（`dynamic=True`，int 参数成 SymInt）、`rebind`（同一编译产物，经同一路径把值改成 v2——改全局/属性/列表/字典、换实参、重建闭包——再调用，与 v2 的 eager 比，缺 guard 会表现为陈旧结果；v2 先在 eager 上验证合法）。每条发现标注"字面量形式在同一模式下是否通过"，只有字面量通过而某形式不通过才是绑定形式独有的发现。冒烟：5 个算子 11 个样本 332 次编译 235 s、0 发现。
全量（`results/binding_full/BINDING.md`，2026-09-10）：386 个带标量参数的算子、4 090 个变体、10 651 次编译、约 41 分钟（隔离子进程）。106 条发现，分诊（`scripts/binding_summary.py`）：
- **绑定形式独有（字面量通过、参数形式不通过）**：`max_pool2d_with_indices_backward` `kernel_size=3` 在 `dynamic=True` 下，位置参数 / 默认参数 / `**kwargs` / 闭包 / `tensor.item()` 五种形式失败，字面量 / 全局 / 属性 / 列表 / 字典五种通过——正是 #122129 那类"int 变 SymInt 后 `int[2]` 形参拒绝"的缺陷，这次由机制自动给出了**哪些绑定形式会被 Dynamo 符号化**（参数与闭包会，容器与全局不会），是此前手工猜出来的那条的系统版本。已知，不再报。
- rebind 模式（同一编译产物、经同一路径改值再调用）：`F.interpolate` scale_factor 0.6→1.15 后所有形式偏差 15，独立验证为 2-D nearest/bilinear 在"输出尺寸等于输入尺寸"时 eager 走拷贝捷径、compile 按 scale 算索引 → **open issue #175154（scale 1.3、nearest）的实例**，bilinear 是它未提到的模式（`scripts/confirm_interp_scale.py`），归重复；`native_group_norm` 把 N 改成与输入不符的值（eager 不检查、compile 报错，非法输入）；`resize_` 未初始化内存；`var_mean/std_mean` 翻转 correction 命中的是 TO_SUBMIT 第 1 条（空张量 mean）。未发现"改值后缺 guard 返回陈旧结果"的情形——9 种可变绑定路径在 2.14 上 guard 都完整。
- harness 误报两处已修：`repr(inf)` 不是合法源码（`linalg.norm` 的 24 条）；rebind 模式下"字面量是否通过"不适用。
结论：绑定形式因子在 2.14 单算子上没有给出新缺陷，但把 #122129 族的触发条件从"值"精确到"绑定方式"，论文里可作为因子有效性的证据。
**接进 Phase 1（2026-09-10 下午）**：`tcc/binding_ast.py` 把绑定形式做成程序变换——解析程序源码，取函数体里的前 N 个标量字面量（int/float/bool/str，跳过文档串与过长字符串），用 AST 改写生成 8 种形式的变体（模块全局、闭包工厂、对象属性、列表元素、字典元素、仅关键字默认参数、位置参数（`make_inputs` 追加实参）、`**opts` 展开（仅关键字实参）），在原函数的 `__globals__`（含闭包自由变量）里 exec，得到同语义的新 `Program`（tag `binding`、`bind:<form>`），进入和其它程序完全相同的流水线（Phase 1 分析、上下文、cold/warm、全部 oracle）。`run.py run/campaign --binding-variants N [--binding-forms ...] [--binding-only]`。语料 29 个程序 → 197 个变体，完整流水线（4 个上下文、Inductor）8 分钟跑完：**0 候选**（`results/binding_phase1/`），与 OpInfo 上的绑定形式扫描一致——2.14 对 8 种绑定形式的处理在语料程序上是一致的。机制已就位，出结果要靠更多程序来源（issue reproducer、真实模型）和 GPU。

### GPU 路线（本机无 GPU）

`plan/kaggle/` 是上云套件：`pack.ps1` 打包 `plan_kaggle.zip`（0.3 MB，代码 + 语料 + 挖到的 reproducer）、`bootstrap.sh`（解压、装 nnsmith、自检）、`campaign_gpu.sh`（按价值排序的 4 个 GPU campaign：CUDA 专属 issue reproducer → CPU 那批在 Triton 路径重跑 → 语料+NNSmith → OpInfo）、`RUN_ON_KAGGLE.md`（操作步骤）。新增 `--device cuda`（种子张量搬到 GPU）和 `mine --allow-cuda`。
Kaggle（T4，torch 2.10.0+cu128）首跑暴露并修掉的问题：(1) CUDA 设备端断言是异步的，隔离子进程退出前未冒出、在主进程里毒化了 CUDA 上下文 → 子进程内开 `CUDA_LAUNCH_BLOCKING=1` 并在加载后做 `synchronize()` 探测；(2) `nn.Module` 目标的 forward 会改 running stats，"eager 两次一致"门控把它们全部误判为非确定性 → `Program.reset` 在每次执行前恢复加载时的 `state_dict`；(3) 参数 `repr` 失败（flex_attention `BlockMask`）不再中断；(4) 执行阶段我们自己生成的上下文也能触发设备端断言（例如把 loss 的 target 改到 [0,1] 之外），一旦发生整个进程的 CUDA 就废了 → `campaign --isolate`（CUDA 上默认开启）：父进程只调度，每个 reproducer 文件或每 `--chunk-size` 个生成程序在独立解释器里跑，共享输出目录与 `progress.json`，子进程崩溃只损失那一份。Kaggle 上的 torch 是 2.10.0，与本机 2.14.0 形成两个版本的对照。

## 4. 实现过程中修正过的关键问题（避免重蹈）

1. **预算分配**：分层探针先把预算吃光导致 warm 序列不跑 → 改为交错调度 layered(c)、matrix(base→c)、matrix(c→base)。
2. **义务取值顺序**：dtype 阶梯 3 个值挤掉其他因子 → 按义务轮转取值；shape 边界按 k、对侧邻值、另一侧排序。
3. **oracle 启用条件**：梯度 oracle 曾只在源码读 `requires_grad` 时启用 → A4 起 mutation/alias/gradient 始终启用（FACT 决定生成哪些上下文，不决定比较什么）。
4. **A→B→A 判定阈值**：同一产物同一上下文两次执行应严格一致 → 返回行程改用严格容差（ulp_slack 0.25）。
5. **`compile.dynamic` 不能做 warm 切换因子**（见 RQ4）。
6. `torch._dynamo.utils.same` 会把每次不一致打成 ERROR 日志 → 调用时临时静音。
7. 实验 A–E 曾用默认预算 8 而非命令行预算 → 已传入。
8. **不要用 PowerShell 的 `Get-Content -Raw | Set-Content` 改中文文件**（会按 ANSI 回写成乱码）；改文件用编辑器工具。

---

## 5. 结果文件索引

| 文件 | 内容 |
|---|---|
| `results/selfcheck_torch.log` | torch 级自检 29/29 |
| `results/rq1_bench.log`, `results/rq1_benchmark.json` | RQ1（最终，预算 16） |
| `results/rq3_ablation.log`, `results/rq3_ablation.json` | RQ3（最终，预算 12） |
| `results/rq4_cache.log`, `results/RQ4.md`, `results/rq4_cache.json` | RQ4（最终） |
| `results/rq2_baselines.log`, `results/RQ2.md`, `results/rq2_baselines.json` | RQ2（最终，含 NNSmith） |
| `results/experiments.log`, `results/EXPERIMENTS.md`, `results/experiments.json` | 实验 A–E（最终，预算 12） |
| `results/rq5_campaign.log`, `reports/` | RQ5 第一轮（35 程序，0 候选） |
| `results/rq5_campaign2.log`, `reports_campaign2/` | RQ5 第二轮（20 NNSmith + 语料，`--keep-info`） |
| `results/rq5_opinfo.log`, `reports_opinfo/` | RQ5 第三轮（120 个 OpInfo 官方测试样本；含 `torch.cov` dynamic=True 的已验证发现） |
| `results/metrics_static.json` | §27 静态指标：29 个函数、111 LOC、111 IR 节点、133 条依赖、14 条 FACT、114 条义务、分析 43 ms、生成 78 ms（整个语料） |
| `results/obligations/*.yaml` | §10 义务（29 个程序） |
| `results/sites_torch_inductor_runtime.json`, `results/sites_torch_dynamo.json` | §5.1 在 torch 源码上的边界识别 |
| `results/bench_reports/<sig>/` | 注入缺陷触发后自动生成的 issue.md / minimal.py / 证据文件样例 |
| `results/run_smoke.log`, `reports_smoke/` | Inductor 冒烟运行 |

---

## 6. 待办（按优先级）

0. **新角度（NEXT_DIRECTIONS §5）**：等 `results\meta_full\` 跑完并分诊（§1）；用户决定 `TO_SUBMIT.md` 第 2–5 条是否提交；然后按 §5.9 做 5.4 绑定形式因子（AST 改写，把标量以字面量/位置/关键字/默认参数/闭包/全局/属性/`**kwargs`/列表元素 9 种方式送进算子）与 5.7 Kaggle 真实模型；分解差分可扩展到 int/bool dtype、0-d、负步长变体和反向分解（`*_backward`）。
0'. 第七轮已跑完；closed issue 仍复现的 5 条待人工核实是否回归（`TO_SUBMIT.md`）。
1. RQ5：`var_mean` 空张量的发现按用户决定（2026-09-08）暂不提交，登记在 `TO_SUBMIT.md`（台账 Pending）；将来提交后 `python run.py campaign --status 0211b330cc67=Submitted --out reports_opinfo_all` 并跟踪 Confirmed/Fixed；`max_pool2d_with_indices_backward` 待精确重建样本；换 `--seed` 再跑一轮 OpInfo（每轮抽样不同）；`run.py run --search-duplicates` 已接 GitHub search API（无 token 时每分钟 10 次限额）；再加 issue reproducer 目录 `--from-dir`、项目 `torch.compile` 站点 `programs_from_sites`、nightly 版本、GPU（Triton 层）。
2. §21 历史基准：**2026-09-10 已用现有数据填了第一版**（`scripts/build_benchmark.py`）——同一批 `reproducers_gh/` 在 2.10.0+cu128（Kaggle）与 2.14.0+cpu 上的检出结果做交集：160 个两版本都跑过的程序里，26 条"closed、2.10 检出、2.14 未检出"作为 buggy/fixed 对（`Kind: fixed`），10 条 open 且两版都检出作阳性对照（`present`），17 条只在 2.10/CUDA 检出的 open issue 单列（`device?`）。`Verified` 全为 false：两次运行的设备不同（cuda vs cpu），严格的同设备版本对要在 Kaggle 上用 2.10 与 2.14 的 CPU 轮子各跑一次（`RUN_ON_KAGGLE.md`）。修复提交用 `fix_in_release.py` 查（`benchmark/fix_status_2.14.json`）：26 条中 8 条的关闭提交确认在 v2.14.0 内（最硬的 buggy/fixed 对），17 条 issue 是被 PR 引用/手工关闭、关闭事件上没有提交（需人工从 PR 找），1 条（#193661）关闭提交不在 2.14 内却在 2.14 上未检出——要么是 CUDA 专属、要么我们漏检，标为待查。
3. 最小化器在真实候选上验证（目前只在注入缺陷上跑过 `--minimize`）。
4. 有 GPU 时：E4（Inductor+Triton）层、Triton `@triton.jit`/TileLang 执行路径（现在只有边界识别）。
5. 外部基线：安装 TorchProbe/FreeFuzz/TitanFuzz 后用 Setting B 接口比较；或用它们的产出目录跑 `--external`。
6. 论文写作时把本文件 §3 的表按 §25 的指标名（BugDetectionRate / TestEfficiency / TTF）重排。

> 2026-09-08 上午另起一轮：`--opinfo 703 --seed 2` 全算子 OpInfo campaign 在后台运行，日志 `results/rq5_opinfo_all.log`，报告 `reports_opinfo_all/`（约 1 小时；用 `python run.py campaign --status <sig>=<Status> --out reports_opinfo_all` 维护台账）。
