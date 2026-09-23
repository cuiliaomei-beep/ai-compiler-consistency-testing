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

### GPU 路线（本机无 GPU）

`plan/kaggle/` 是上云套件：`pack.ps1` 打包 `plan_kaggle.zip`（0.3 MB，代码 + 语料 + 挖到的 reproducer）、`bootstrap.sh`（解压、装 nnsmith、自检）、`campaign_gpu.sh`（按价值排序的 4 个 GPU campaign：CUDA 专属 issue reproducer → CPU 那批在 Triton 路径重跑 → 语料+NNSmith → OpInfo）、`RUN_ON_KAGGLE.md`（操作步骤）。新增 `--device cuda`（种子张量搬到 GPU）和 `mine --allow-cuda`。
Kaggle（T4，torch 2.10.0+cu128）首跑暴露并修掉的问题：(1) CUDA 设备端断言是异步的，隔离子进程退出前未冒出、在主进程里毒化了 CUDA 上下文 → 子进程内开 `CUDA_LAUNCH_BLOCKING=1` 并在加载后做 `synchronize()` 探测；(2) `nn.Module` 目标的 forward 会改 running stats，"eager 两次一致"门控把它们全部误判为非确定性 → `Program.reset` 在每次执行前恢复加载时的 `state_dict`；(3) 参数 `repr` 失败（flex_attention `BlockMask`）不再中断。Kaggle 上的 torch 是 2.10.0，与本机 2.14.0 形成两个版本的对照。

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

0. **先续跑第七轮**（见 §1 断点），跑完后 `scripts\gh_summary.py` 出已知缺陷召回表并逐条分诊；closed issue 仍复现的要人工核实是否回归。
1. RQ5：`var_mean` 空张量的发现按用户决定（2026-09-08）暂不提交，登记在 `TO_SUBMIT.md`（台账 Pending）；将来提交后 `python run.py campaign --status 0211b330cc67=Submitted --out reports_opinfo_all` 并跟踪 Confirmed/Fixed；`max_pool2d_with_indices_backward` 待精确重建样本；换 `--seed` 再跑一轮 OpInfo（每轮抽样不同）；`run.py run --search-duplicates` 已接 GitHub search API（无 token 时每分钟 10 次限额）；再加 issue reproducer 目录 `--from-dir`、项目 `torch.compile` 站点 `programs_from_sites`、nightly 版本、GPU（Triton 层）。
2. §21 历史基准：从 toxic-compilation 数据集筛选并人工验证后填入 `benchmark/historical_bugs.json`（需要能装第二个 torch 版本的环境）。
3. 最小化器在真实候选上验证（目前只在注入缺陷上跑过 `--minimize`）。
4. 有 GPU 时：E4（Inductor+Triton）层、Triton `@triton.jit`/TileLang 执行路径（现在只有边界识别）。
5. 外部基线：安装 TorchProbe/FreeFuzz/TitanFuzz 后用 Setting B 接口比较；或用它们的产出目录跑 `--external`。
6. 论文写作时把本文件 §3 的表按 §25 的指标名（BugDetectionRate / TestEfficiency / TTF）重排。

> 2026-09-08 上午另起一轮：`--opinfo 703 --seed 2` 全算子 OpInfo campaign 在后台运行，日志 `results/rq5_opinfo_all.log`，报告 `reports_opinfo_all/`（约 1 小时；用 `python run.py campaign --status <sig>=<Status> --out reports_opinfo_all` 维护台账）。
