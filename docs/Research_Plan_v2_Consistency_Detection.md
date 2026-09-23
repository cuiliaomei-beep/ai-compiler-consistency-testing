# 研究计划 v2：torch.compile 语义一致性缺陷的自动检测
## 基于 Python 层别名/状态依赖分析的测试义务导出

> 本版是对 `Toxic_Compilation_Consistency_Detection_Research_Plan_Updated.md`（下称 v1）的修订。
> 修订触发因素：2026-04 出现的 arXiv:2604.08720（下称 **AlignGuard 论文**）与 v1 的核心创新点重叠，
> 但同时公开了一组数据，指出了一个比 v1 原定方向更大、更明确的空白区。
> 修订日期：2026-09-06。

---

## 0. 本版相对 v1 的变更摘要

| 项目 | v1 | v2 | 原因 |
|---|---|---|---|
| 首要创新点 | cold/warm cache 一致性差分（§14） | **alias/view/mutation 结构模式合成 + guard 完备性** | cache 重复执行思路已被 AlignGuard 论文发表，必须引用；而 memory 类缺陷是更大且同样未解的空白 |
| 历史 benchmark | 自建（v1 §21） | **复用 AlignGuard 的 77-bug benchmark**；自有数据集降级为种子来源 | 实测显示自有数据集不具备 ground truth（见 §7） |
| 自有数据集角色 | ground-truth benchmark | **seed corpus（295 条真实 issue reproducer）** | 同上 |
| 基线 | FreeFuzz / NNSmith / TorchProbe / TitanFuzz / DeepREL | **NNSmith / NeuRI / WhiteFox / DeepConstr / AlignGuard** | v1 基线集已过时，缺 3 个更强的近期工作 |
| Phase 4（issue 自动生成） | 独立贡献 | **删除**，改为复用官方 minifier + 人工整理 | 属工程不属研究；PyTorch 已自带 accuracy minifier |
| Oracle 数量 | 7 个（O1–O7） | **3 个主 oracle**（value/fp64、mutation、alias）+ 2 个辅助 | 收敛范围，保证第一篇能做完 |
| 目标系统 | PyTorch + Triton + TileLang 并列 | **PyTorch 为唯一主目标**，Triton/TileLang 作泛化性小节 | 同上 |
| RQ 数量 | 5 个 RQ + 5 个实验 | **4 个 RQ** | 同上 |
| 浮点 oracle | "dtype-aware tolerance"（未定义） | **`torch._dynamo.utils.same()` + fp64 参考基准** | 用项目自身判据，控假阳性且报告不可被容差理由驳回 |

---

## 1. 核心论点

> **现有 DL 编译器测试工具已经覆盖了足够多的算子，但无法合成算子所处的"结构性上下文"——
> 别名/视图关系、原地写序列、以及触发 guard 重判的上下文切换。
> 这些结构是程序特定的、无法枚举的，只能从 Python 层的语义依赖关系中推导。
> 本研究用轻量静态分析导出这些结构，并将其转化为可执行的一致性测试义务。**

这一论点不是猜测，而是由 AlignGuard 论文的实测数据直接支撑的（见 §2）。

与最接近工作的区别一句话：

```
AlignGuard : 从 issue 报告中用 LLM 抽取 bug 模式 → 变异已有测试用例   （采样式、启发式）
本研究     : 从被测程序自身的依赖关系推导必须被保持的语义关系 → 导出测试义务  （推导式、系统性）
```

AlignGuard 论文自己的 future work 明确点名了两项需求，恰好是本研究的方法内容：
「为 graph-structure bug 开发**超出标准差分测试**的定制 oracle」，以及
「**系统性地**支持复杂 tensor alias/view 模式与内存布局变异」。

---

## 2. 竞争格局与空白区（决定选题的实测数据）

AlignGuard 论文构建了 116 个 torch.compile correctness bug 的数据集，筛出 77 个可复现的作为 benchmark，
并在其上评测了 5 个 SOTA 工具（NNSmith、NeuRI、Opera、WhiteFox、DeepConstr）。结果：

| 缺陷族 | benchmark 中数量 | 5 个工具合计检出 | **漏检** |
|---|---:|---:|---:|
| Graph-related（语义捕获 + 图缓存） | 15 | **0** | **15 (100%)** |
| Memory-related（别名/原地写 + 内存布局） | 22 | 6 | **16 (73%)** |
| Operator-related（算子变换 + 底层代码生成） | 33 | 17 | 16 (48%) |
| 其他（精度/配置/外部库） | 7 | 3 | 4 |
| **合计** | **77** | **26 (33.8%)** | **51** |

**关键在于论文给出的漏检原因，两条都直接指向本研究的方法：**

1. Graph 类漏检原因之一：「多数技术依赖差分测试作为 oracle，只**执行编译模型一次**并比较编译前后输出；
   而某些 graph 相关缺陷只能由**专门的测试流水线（即重复执行）**检出。」
   → 对应本研究的上下文序列执行（§4.2.3）。
   漏检原因之二：「不覆盖非计算类 API（如控制流 API）与上下文类 API（如 `TorchDispatchMode`）。」
   → 对应本研究把 Python 控制流与状态读写纳入语义因子（§4.1）。

2. Memory 类漏检原因（**这是本计划最重要的一条依据**）：
   「这些缺陷**并非**因为原地算子覆盖不足而漏检，而是因为这些技术**无法合成这些算子的复杂的、触发缺陷的使用模式**。」
   并进一步指出：「除一个自定义 Triton 算子外，**所有原地操作都已被现有技术覆盖**，但相应缺陷仍未被检出，
   因为 IPO 缺陷要求原地操作被施加在**通过未充分探索的模式构造出的复杂 tensor 别名或视图**之上。」

**第 2 条是本研究成立的核心理由。** 它说明问题不在"用哪些算子"（枚举即可，已被解决），
而在"算子作用在什么样的别名/视图结构上"（无法枚举，必须从程序推导）。
这正是语法生成器与 LLM 变异都做不到、而静态别名依赖分析天然擅长的事。

**空白区总计：77 个中的 31 个（graph 15 + memory 16）被全部 5 个 SOTA 工具漏检，占 benchmark 的 40%。**

### 2.1 相关工作定位

| 工作 | venue | 测试空间 | 别名/视图结构 | 重复执行/cache | 与本研究关系 |
|---|---|---|---|---|---|
| NNSmith | ASPLOS 2023 | DNN 计算图（SMT 约束） | 否 | 否 | 基线 |
| NeuRI | ESEC/FSE 2023 | 归纳规则推断的算子组合 | 否 | 否 | 基线（原文最强之一，12/77） |
| WhiteFox | OOPSLA 2024 | LLM 读优化源码生成触发程序 | 否 | 否 | 基线（原文最强之一，12/77） |
| DeepConstr | ISSTA 2024 | 约束精化的 API 测试 | 否 | 否 | 基线 |
| Opera | 见 arXiv 2407.16626 | 从库测试迁移到编译器 | 否 | 否 | 基线（可选） |
| **AlignGuard** | arXiv 2604.08720 (2026) | LLM 按 issue 模式变异测试用例 | 部分（模式驱动） | **是**（重复执行流水线） | **最近对比对象，必须比** |
| TorchProbe | APLAS 2023 | 保语义程序变换 | 部分 | 非核心 | 降级为补充基线 |
| FreeFuzz / TitanFuzz / DeepREL | ICSE'22 / ISSTA'23 / FSE'22 | DL 库 API | 否 | 否 | **不再作为主基线**（目标是库不是编译器） |
| **本研究** | — | **静态推导的别名/状态结构 + 上下文序列** | **是（核心）** | **是** | — |

---

## 3. 问题定义

沿用 v1 的形式化，收紧到可判定的范围。

给定 Python 函数 `f`、输入 `x`、执行上下文 `c`：

- `E(f,x,c)`：eager 执行
- `C(f,x,c)`：`torch.compile` 后执行

可观察语义（v2 收敛为 5 项，去掉 v1 的 gradient 与部分 metadata 作为可选）：

```
Obs(r) = <value, exception, input_mutation, alias_relation, output_metadata>
```

三类判定：

| 判定 | 条件 | 结论 |
|---|---|---|
| **D1 编译一致性** | `Obs(E(f,x,c)) ≉ Obs(C_cold(f,x,c))` | 编译产物与源语义不一致 |
| **D2 特化一致性** | `Obs(C_cold(f,x,c2)) ≉ Obs(C_warm(f,x,c1→c2))` | guard/特化缺陷（强信号，无需 eager 参与） |
| **D3 结构一致性** | 别名/原地写关系在编译前后不同 | functionalization / alias 追踪缺陷 |

**D2 是最干净的 oracle**：它不涉及 eager 与 compiled 的合法数值差异，两边都是编译产物，
只要 cold 与 warm 结果不同就一定是缺陷。应作为优先报告的一类。

---

## 4. 方法

```
Python Program
      │
      ▼
┌──────────────────────────────────────────────┐
│ Phase 1  Python 层语义依赖分析                │
│  · 编译边界识别 (CompilationSite)             │
│  · 别名 / 视图 / 原地写依赖图  ← 本研究重心    │
│  · shape/index 关系、控制依赖、状态读写        │
│  · Semantic Context Signature (SCS)          │
└──────────────────┬───────────────────────────┘
                   │  Consistency Test Obligations
                   ▼
┌──────────────────────────────────────────────┐
│ Phase 2  义务导向的测试合成                    │
│  · 结构模式合成（别名/视图/原地写序列）← 重心   │
│  · 边界取值生成                                │
│  · 上下文序列生成（A→B, B→A, A→B→A）          │
└──────────────────┬───────────────────────────┘
                   ▼
        eager │ cold-compile │ warm-cache
                   │
                   ▼
┌──────────────────────────────────────────────┐
│ Phase 3  一致性判定、过滤与定位                │
│  · fp64 参考 oracle（同 PyTorch 官方判据）     │
│  · recompile 计数预过滤                        │
│  · 后端分层二分定位                            │
│  · 复用官方 accuracy minifier                  │
└──────────────────────────────────────────────┘
```

### 4.1 Phase 1：静态语义依赖分析

保留 v1 的 §5–§9，但**把别名/视图/原地写分析从 v1 的 §8（第八节，配角）提升为核心**。

#### 4.1.1 别名/视图依赖图（本研究的技术核心）

对 CompilationSite 可达的 Python 代码，构建：

```
AliasGraph:
    node   : tensor-valued SSA name
    edge   : view / reshape / slice / permute / expand / as_strided / select
             / cat-into / index_put / copy_ into
    attr   : storage_offset 关系、stride 关系、是否 contiguous、是否共享 storage
MutationSet:
    每个 in-place 写点 (op, target_node, 触发条件)
Reachability:
    对每个 in-place 写点，计算它能通过 AliasGraph 影响到的
    (a) 返回值 (b) 输入参数 (c) module 状态
```

**产出的不是 bug，而是"必须被编译保持的结构性事实"**，例如：

```
FACT-1  y = x.view(-1) 之后 y[0] += 1  ⇒  x 的可观察状态必须改变
FACT-2  z = x[:, ::2] 之后 z.copy_(w)  ⇒  x 的非连续子集必须被写入，且 x 其余元素不变
FACT-3  a, b 共享 storage 且写序为 a→b  ⇒  编译后写序不得交换
```

每条 FACT 直接对应一条测试义务与一个 alias/mutation oracle 断言。
**这就是 AlignGuard 论文说的"无法合成的复杂使用模式"——我们不合成，我们从程序中读出来，再系统性地扰动它。**

#### 4.1.2 结构变异算子（补 §4.1.1 的另一半）

只读出现有结构还不够，还要**系统性地枚举结构变体**。定义结构变异算子，作用于 AliasGraph：

| 算子 | 变换 | 目标缺陷 |
|---|---|---|
| `DeepenView` | `x.view()` → `x.view().permute().view()` | 多层视图下的 stride 推导 |
| `AliasBranch` | 让两个视图共享 storage 的重叠子集 | 别名追踪不完整 |
| `ReorderMutation` | 交换两个不相交原地写的顺序 | 写序保持（应等价） |
| `AliasMutation` | 把原地写目标从非别名换成别名 | functionalization 正确性 |
| `NonContiguous` | 在输入上插入 `[::2]` / `.t()` 使其非连续 | 内存布局冲突（MLC 类） |
| `EscapeAlias` | 让别名逃逸到 module 属性或全局 | 状态依赖漏判 |

这组算子是从 AlignGuard 论文的 memory-related 子类（别名追踪错误 17 个、布局元数据追踪错误 6 个、
缺失兼容性检查 8 个）反向设计的，可直接支撑 RQ1 的分类召回率论证。

#### 4.1.3 Semantic Context Signature (SCS)

沿用 v1 §9。SCS 用于导出上下文序列，**不假装等价于编译器真实 cache key**：

```
SCS(site) = { shape 关键维, dtype, stride/contiguous, device,
              requires_grad, python scalar/flag, backend, compile flag }
```

### 4.2 Phase 2：义务导向的测试合成

#### 4.2.1 种子

来源见 §7.2（自有数据集的 295 条真实 issue reproducer + 官方测试 + 官方 example）。

#### 4.2.2 结构模式合成（第一优先级）

对每个种子，用 §4.1.2 的算子生成结构变体，**每次只施加一个算子**，保持计算语义不变，
使得任何 eager/compiled 差异都可归因到结构本身。

#### 4.2.3 上下文序列生成（第二优先级）

沿用 v1 §14/§15 的执行矩阵，但**必须加上 recompile 预过滤**（见 §5.1）：

```
E2      = eager(x2)
C2cold  = compiled(x2)                    # torch._dynamo.reset() 之后
C2warm  = compiled(x1) 然后 compiled(x2)   # 不 reset

判定 D2 : C2cold ≉ C2warm            → 强信号，直接进候选
判定 D1 : E2 ≉ C2cold                → 需经 fp64 oracle 过滤
```

序列模式：`A→B`、`B→A`、`A→B→A`。

**必须区分两层缓存**（v1 未区分，是一个实质缺口）：

| 层 | 复位方式 | 说明 |
|---|---|---|
| 进程内 Dynamo/Inductor 缓存 | `torch._dynamo.reset()` | v1 §14 隐含的就是这一层 |
| **磁盘缓存**（FX graph cache、Inductor cache、Triton JIT cache） | 清空 `TORCHINDUCTOR_CACHE_DIR` / Triton cache dir；或**跨进程**执行 | **未被现有工作测试**，是额外的可挖掘面 |

跨进程复用尤其值得测：进程 A 编译 `x1`，进程 B 在同一 cache dir 下执行 `x2`。

### 4.3 Phase 3：判定、过滤与定位

#### 4.3.1 Oracle

| Oracle | 实现 | 优先级 |
|---|---|---|
| **O1 value** | `torch._dynamo.utils.same(ref, res, fp64_ref=..., tol=..., equal_nan=...)` | 主 |
| **O2 mutation** | 执行前后对所有输入 tensor / module buffer 做快照比对 | 主 |
| **O3 alias** | 比对 `data_ptr()` / `storage().data_ptr()` / `_base` / stride，验证 §4.1.1 的 FACT | 主 |
| O4 exception | 类型与是否抛出 | 辅 |
| O5 metadata | shape / dtype / device / stride / contiguous | 辅 |

gradient oracle 从 v1 的 O6 降级为可选（该方向已有 NablaFuzz 类工作，非本文重点）。

#### 4.3.2 定位

沿用 v1 §16 的后端分层：

```
E0 eager
E1 torch.compile(backend="eager")        → 差异出现在此层 ⇒ Dynamo 图捕获
E2 torch.compile(backend="aot_eager")    → 差异出现在此层 ⇒ AOTAutograd/functionalization
E3 torch.compile(backend="inductor")     → 差异出现在此层 ⇒ Inductor lowering/codegen
```

对 alias/mutation 类缺陷，E1→E2 这一跳信息量最大（functionalization 正是在 AOTAutograd 层）。

#### 4.3.3 最小化：不要自建

**删除 v1 §17.2 的自建最小化器。** 直接使用 PyTorch 官方 accuracy minifier：

```
TORCHDYNAMO_REPRO_AFTER="dynamo"   # 或 "aot"
# 失败时自动产出 minifier_launcher.py
```

自建最小化不构成研究贡献，且官方 minifier 产出的复现脚本是维护者熟悉的格式，更易被接收。
静态 slice 最小化（v1 §17.2 的 Python 程序最小化）可作为官方 minifier 之前的一道预处理保留。

---

## 5. 三个决定成败的工程要点

### 5.1 recompile 计数预过滤（决定 warm-cache 实验能否跑通）

改变 dtype 通常会使 guard 失败并**触发重编译**——这时没有缺陷，只有开销。
真正的缺陷是「切换了上下文但**没有**重编译，而语义变了」。因此：

```python
from torch._dynamo.utils import counters
counters.clear()
run(x2)                       # warm 执行
recompiled = counters["frames"]["total"] > baseline   # 或用 TORCH_LOGS="recompiles,guards"
```

**只有 `recompiled == False` 的上下文切换才进入 oracle 判定。**
没有这一步，D2 的信噪比会低到实验跑不动——这是 v1 最大的可执行性缺口。

反过来，「本应重编译却没有重编译」本身就是 guard 不完备的直接证据，
即使输出恰好相同也应记录为可疑事件（弱信号，用于指导后续变异）。

### 5.2 fp64 参考基准（决定假阳性率）

`torch.compile` **合法地**改变数值（融合改变归约顺序、TF32、不同的 epilogue）。
自定 tolerance 必然导致大量假阳性，这是这类研究最常见的失败原因。

采用 PyTorch 自身的判据：

```
ref_fp64 = f(x.double())                       # fp64 参考
err_eager    = |eager(x)    - ref_fp64|
err_compiled = |compiled(x) - ref_fp64|
报告条件： err_compiled 显著大于 err_eager      # 而非 |compiled - eager| > 固定阈值
```

即 `torch._dynamo.utils.same(..., fp64_ref=ref_fp64, ...)` 的语义。

三重收益：假阳性可控；用的是项目自身认可的精度政策，维护者无法以"容差设太紧"驳回；
AlignGuard 论文的 oracle 容差**未作说明**，这可作为本研究的一个次级贡献点。

### 5.3 RQ2 的 A0 基线必须是"穷举枚举"而非"随机"

对 `torch.compile` 而言，语义因子的**集合**是小而可枚举的
（shape / dtype / device / stride / requires_grad / scalar / flag）。
如果消融的 A0 设成 random，审稿人会立刻问：全枚举一遍不就行了，静态分析的价值在哪？

**A0 必须设成「穷举因子枚举 + 随机取值 + 随机结构变异」这个强基线。**
静态分析真正应当赢的是三处，实验必须对准：

1. **边界取值**：从 `x.shape[0] >= 32` 推出 31/32/33，从 `n % 16 == 0` 推出 15/16/17
2. **别名/原地写结构**：程序特定，**无法枚举**（← 主战场）
3. **组合与序列剪枝**：因子组合爆炸时选哪些

如果实验显示 A0 ≈ FULL，说明主要贡献不成立，应及早（Month 4 前）发现并转向。

---

## 6. 评估设计

### RQ1 — 能否检出现有工具漏检的缺陷？（主结果）

- **对象**：AlignGuard 的 77-bug benchmark
- **指标**：总检出数；**按缺陷族分列**（graph 15 / memory 22 / operator 33 / other 7）
- **成败线**：现有 5 工具在 graph 上 **0/15**、memory 上 **6/22**。
  本方法若能在 graph + memory 的 37 个中检出 **≥12 个**（现有为 6），即构成明确贡献。
- 另需报告在 fixed 版本上的假阳性数。

### RQ2 — 静态分析是否真的减少了动态搜索空间？（消融）

```
A0  穷举因子枚举 + 随机取值 + 随机结构变异     ← 强基线，不可用 random 代替
A1  + 边界取值推导
A2  + 别名/视图依赖图（FACT 导出）
A3  + 结构变异算子（§4.1.2）
A4  + SCS 上下文序列 + recompile 过滤
FULL
```

指标：检出数、达到同等检出所需测试数、TTF、无效测试率、静态分析开销。

### RQ3 — 能否在最新版本中发现新缺陷？（最高价值，最长周期）

- 对象：PyTorch 最新 nightly（主）；Triton、TileLang（泛化性）
- 流程：确定性重跑 → cold/warm 双验证 → fp64 oracle → 官方 minifier → 查重 → 人工审核 → 提交
- 记录：Generated / Submitted / Confirmed / Fixed / Duplicate / Invalid / Pending
- **参照线**：AlignGuard 拿到 23 个新 bug、14 个 high-priority、全部被确认或修复。
  当前门槛约为「**≥20 个新缺陷，多数被官方确认**」。
- 选 3–5 个做 mechanism-level case study，优先选 alias/mutation 与 warm-only 两类。

### RQ4 — 开销与可扩展性

Python LOC、compilation site 数、AliasGraph 规模、导出义务数、
静态分析时间、生成时间、执行时间、编译次数、峰值内存。

---

## 7. Benchmark 与种子的分工（基于实测）

### 7.1 自有数据集不能作为 ground-truth benchmark（实测结论）

对自有 `toxic-compilation-dataset` 中 codegen/cache 相关的 594 条事件，按 v1 §21 的六条标准实测：

```
有 fix 指针（fixed_commit 或 fixed_version）    66 / 594  = 11.1%
  fixed_commit 单项                             44 / 594  =  7.4%
  trigger_condition 单项                         4 / 594  =  0.7%
  └ 同时有代码的                                64
      └ 快照来源：advisory_excerpt 28 / llm_reconstructed 36
                  真实可运行 reproducer：       0 条
```

**结论：v1 §21 计划自建的 ground-truth benchmark，用现有数据建不起来。**
应直接复用 AlignGuard 的 77-bug benchmark，以及 NeuRI / WhiteFox 论文附带的历史缺陷集。

> **待办（阻塞项）**：AlignGuard 论文 v1 未声明 artifact / 复现包地址。
> 需要（a）检查是否有更新版本或正式发表版本附带 artifact；（b）若无，直接联系作者索取 benchmark；
> （c）最坏情况按论文附录的 issue 编号自行重建 77 个 bug 的可复现环境。
> **这是 Month 1 必须解决的第一个风险点。**

### 7.2 自有数据集的正确角色：种子语料

同一批数据中，**带真实 issue 片段且属于核心项目**的条目有 **295 条**：

| 项目 | 条数 |
|---|---:|
| pytorch/pytorch | 108 |
| vllm-project/vllm | 57 |
| llvm/llvm-project | 45 |
| triton-lang/triton | 43 |
| tile-ai/tilelang | 37 |
| apache/tvm | 4 |
| openxla/xla | 1 |

这正是 §4.2.1 需要的 base input seed，并且构成一个可辩护的差异化优势：

> AlignGuard 的种子来自**已有测试用例**；本研究的种子来自**真实缺陷报告的复现代码**。
> 两者的程序分布不同，可作为 RQ2 的一个受控变量单独评估。

---

## 8. 里程碑与风险

| 月份 | 里程碑 | 备注 |
|---|---|---|
| M1 | 取得 77-bug benchmark；搭好 eager/cold/warm 执行框架 + fp64 oracle + recompile 计数 | 框架先行；benchmark 是阻塞项 |
| M1 | **RQ3 的持续 fuzzing 开始跑，之后一直不停** | ← 最长关键路径，必须最早启动 |
| M2–M3 | Phase 1 别名/视图依赖图 + FACT 导出；结构变异算子 | 技术核心 |
| M4 | **中期检查点：A0 vs A2/A3 的初步消融** | 若 A0 ≈ FULL，及早转向 |
| M4–M5 | 上下文序列 + 跨进程磁盘缓存测试 | 第二贡献 |
| M6 | RQ1 完整 benchmark 评测 + RQ2 完整消融 | |
| M7 | RQ4；Triton/TileLang 泛化性；论文写作 | |
| 全程 | 跟踪 RQ3 的 issue 确认状态 | 维护者响应以周计 |

### 主要风险

| 风险 | 概率 | 影响 | 缓解 |
|---|---|---|---|
| 拿不到 77-bug benchmark | 中 | 高 | M1 即联系作者；备选按 issue 号重建 |
| A0 强基线追平 FULL（静态分析不增值） | 中 | **致命** | M4 检查点；主战场压在无法枚举的别名结构上 |
| fp64 oracle 仍有大量假阳性 | 中 | 高 | 优先报告 D2（cold vs warm），该判定不涉及 eager 数值差异 |
| warm-cache 切换几乎总是触发重编译，无信号 | 中 | 中 | recompile 预过滤；转向跨进程磁盘缓存 |
| RQ3 新缺陷数不达 20 | 中 | 高 | M1 就开跑；扩到 Triton/vLLM 增加面 |
| AlignGuard 团队跟进发表更完整版本 | 中 | 中 | 差异化压在"推导式 vs 采样式"，而非"是否测 cache" |

---

## 9. 从 v1 删除的内容及原因

| 删除项 | 原因 |
|---|---|
| Phase 4 全部（§18，issue 自动生成、去重、模板、提交流程） | 工程非研究；审稿人不计入贡献；官方 minifier 已覆盖大部分 |
| 自建 failure minimization（§17.2 输入最小化部分） | 复用 `TORCHDYNAMO_REPRO_AFTER` |
| O6 gradient oracle | 已有 NablaFuzz 类工作，非本文重点；可作 future work |
| TileLang / TVM / TensorRT 作为主实验对象（§19） | 收敛到 PyTorch；其余作泛化性小节 |
| FreeFuzz / TitanFuzz / DeepREL 作为主基线（§22） | 目标是 DL 库而非编译器，且已过时 |
| v1 §21 自建历史 benchmark | 实测不可行（§7.1） |
| v1 §25 的 RQ4（cache 单列 RQ）、§26 的五个独立实验 A–E | 折叠进 RQ1 的分族结果与 RQ2 消融 |

---

## 10. 需要写进论文的贡献陈述（草稿）

1. **一个 Python 层的别名/视图/原地写依赖分析**，能从被测程序中导出编译系统必须保持的结构性语义事实，
   并将其转化为可执行的一致性测试义务与断言。
2. **一组结构变异算子**，系统性地枚举别名/视图/布局结构的变体——
   这是现有语法生成与 LLM 变异方法被实测证明无法合成的部分。
3. **一个带 recompile 过滤的上下文序列执行框架**，将 cold/warm 与跨进程磁盘缓存一致性
   从人工设计的重复执行提升为由 SCS 自动导出，并首次覆盖跨进程编译缓存。
4. **一个基于 fp64 参考基准的多维一致性 oracle**（value / mutation / alias），
   采用 PyTorch 自身的精度判据以控制假阳性并提升缺陷报告的可接受性。
5. **实证结果**：在现有 5 个 SOTA 工具漏检的 31 个缺陷上的检出率，以及在最新版本上发现的新缺陷。

---

## 11. 参考文献（需补入的关键条目）

- Demystifying the Silence of Correctness Bugs in PyTorch Compiler. arXiv:2604.08720, 2026.（**最近对比对象**）
- WhiteFox: White-Box Compiler Fuzzing Empowered by Large Language Models. OOPSLA 2024. DOI 10.1145/3689736
- NeuRI: Diversifying DNN Generation via Inductive Rule Inference. ESEC/FSE 2023. arXiv:2302.02261
- NNSmith: Generating Diverse and Valid Test Cases for Deep Learning Compilers. ASPLOS 2023.
- Towards More Complete Constraints for Deep Learning Library Testing via Complementary Set Guided Refinement (DeepConstr). ISSTA 2024. DOI 10.1145/3650212.3680364
- A Tale of Two DL Cities: When Library Tests Meet Compiler (Opera). arXiv:2407.16626
- TorchProbe: Fuzzing Dynamic Deep Learning Compilers. arXiv:2310.20078, APLAS 2023.
- Tzer: Coverage-Guided Tensor Compiler Fuzzing with Joint IR-Pass Mutation. OOPSLA 2022.
