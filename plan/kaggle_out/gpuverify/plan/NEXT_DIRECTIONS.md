# 调整思路：为什么现在找不到新 issue，下一步往哪走

日期：2026-09-09。依据：本目录七轮 CPU campaign + Kaggle 三轮 GPU campaign 的结果，`harness/` 的 14 轮结果与消融，以及从 GitHub 挖到的 533 个 issue reproducer（335 个不重复标题）。

## 1. 两套实现得到的是同一个结论

| 语料 | harness/（tcd） | plan/（tcc） |
|---|---|---|
| 单算子 OpInfo（约 700 算子） | 4 轮，唯一真实发现 var_mean/std_mean（其余 softmax_backward、acos/asin/atanh 是 2e-16～3e-8 的浮点噪声，其 oracle 没有噪声底） | 4 轮 1 700 余程序，唯一非重复发现 **var_mean/std_mean 空张量 mean=0** |
| 结构变异（9 个算子：IntroduceView/AliasWrite/DeepenView/…，深度 1–2） | `reports_mut/deep/free/rule`：候选全是上述噪声或 `unsafe_chunk` 非契约别名 | 未实现（本目录用义务→上下文；别名结构靠语料自带） |
| 多算子链（10 个逐元素 link + 7 个结构元素 + 分支/索引） | RQ3 消融：A0–A6 **全部 0 候选**（`ablation/rq3_chains.json`、`rq3_structured.json`） | 未实现 |
| module_db（nn.Module，training 模式）| `reports_model`：0 候选 | 未实现 |
| NNSmith Setting B | 20 个模型 0 候选 | 8 + 20 个模型 0 候选 |
| issue reproducer | 9 个（数据集导入） | 533 个（GitHub 挖掘）：2.14.0 上 open 23/63 复现，2.10.0 上 open 61/170 复现 |

结论：**在 2.14.0 CPU 上，"单算子 + 轻量别名结构 + 逐元素链"这一层已经被 PyTorch 自己的 CI 覆盖，再挖不出东西**；harness 的 `cases_model.py` 注释里也写了同样的判断。真正有产出的是 issue reproducer 语料——但那是复现已知缺陷，不是发现新缺陷。

## 2. 真实缺陷长什么样（335 个 issue 标题的分布）

| 类别 | 数量 | 我们的生成器覆盖了吗 |
|---|---:|---|
| index / scatter / gather / cumsum / take / put | 102 | **几乎没有**：语料里只有 index_select、mask；链里没有索引类算子 |
| 崩溃 / 内部错误（compile 抛、eager 正常） | 100 | O3 能判，但生成器没有专门制造触发条件 |
| "silently accepts / ignores"（eager 拒绝、compile 静默接受：dtype/device/shape 校验被分解绕过） | 56 | 没有：我们的上下文都是"合法输入"，从不故意给非法输入 |
| in-place / view / alias / stride / expand / channels_last | 54 | 部分：有 noncontig/transposed，没有 expand（stride 0）、channels_last、storage_offset≠0、重叠 as_strided |
| reduction / softmax / norm / argmax | 53 | 部分：语料里几个 sum；var_mean 就是这类 |
| dtype cast / promotion / fp16 / bf16 / uint8 / int32 | 49 | 部分：只有浮点阶梯；**没有整数/uint8/bool**，没有"算子之间的 cast"（matmul→bf16→fp32 那种） |
| dynamic shapes / SymInt / unbacked / guard | 48 | 只有 `dynamic=True` 开关；没有 `mark_dynamic`、数据依赖形状（nonzero/unique/masked_select 后续再用）、0/1 特化 |
| autograd / backward / jvp / double backward | 44 | O6 只比一阶输入梯度；没有 autograd.Function、二阶、参数梯度 |
| conv / pool / interpolate | 34 | 无（都是 4D + kernel/stride/padding/ceil_mode 的组合） |
| sdpa / attention / flex | 25 | 无 |
| 特殊值：complex / nan / inf / 空张量 / 零维 | 21 | **只碰巧**：var_mean 的发现来自 OpInfo 的一个空张量样本 |
| graph break / fullgraph / 嵌套 compile / 重编译 | 20 | 部分（cache 序列） |
| rng / dropout / 确定性 | 18 | 故意排除 |
| autocast / amp | 10 | 无 |

也就是说，缺陷密度最高的三块——**索引类算子、非法输入的静默接受、算子间 dtype 转换**——正好是我们生成器的空白；而我们花最多预算的三块——浮点 dtype 阶梯、requires_grad、compile flag——在真实 issue 里占比很低。

## 3. 下一步：三条互补的路线（按性价比排序）

### 路线 A：issue 驱动的多算子程序合成（核心）

把"多算子 + 结构"做对，而不是像 harness 那样只串逐元素算子。要点：

1. **算子词表按 issue 分布加权**。从 335 个标题 + 533 个 reproducer 正文统计算子/API 出现频次，作为链合成时的采样权重（`index_add_`、`scatter_reduce`、`cumsum`、`where`+广播、`var_mean`、`softmax`、`interpolate`、`conv2d`、`.to(bfloat16)`、`masked_fill`、`nonzero`……优先）。这是"issue-informed generation"，本身就是一个可评估的 RQ：加权 vs 均匀采样，同预算下的检出。
2. **词表按语义类别分组，每条链跨类别组合**：`view/alias` × `in-place` × `reduction` × `index/scatter` × `cast` × `broadcast` × `constant`（`torch.full/arange/empty_like` 在图内创建常量——"constant folds sum(softmax) to e" 就是这类）× `control flow`。链长 3–6，每步带形状约束（reduction 后 keepdim、index 后长度变化），保证程序合法。
3. **生成的是源码**（不是 nn.Module），这样 Phase 1 的静态分析（别名并查集、shape→index 链、谓词边界）能读到结构，SCS 与义务照常派生——这正是本方法相对 NNSmith 的差异点，链要让这个差异点有用武之地。
4. **两种有效性门**：eager 可运行 + eager 两次一致（已有）；并保留"非法输入"作为一个显式上下文族（见路线 B）。

### 路线 B：把 issue 高频因子补进语义因子词表（§3.1 的扩展）

| 新因子 | 上下文 | 对应 issue 类别 |
|---|---|---|
| 边角形状 | 每个张量参数：某维=0、=1、素数（7/13）、非 2 的幂；零维标量 | 空张量/广播/0-1 特化（var_mean 就是） |
| 整数/布尔 dtype | int32/int64/uint8/bool（合法性由 eager 门决定） | uint8 abs 静默误编译、int32 输入被接受 |
| 算子间 cast | 在链的两步之间插入 `.to(bfloat16).to(float32)` / `.half().float()` | matmul→bf16、fp16 cast 前后不一致、`TORCHINDUCTOR_EMULATE_PRECISION_CASTS` |
| 布局 | `expand`（stride 0）、`channels_last`（4D）、`storage_offset≠0` 的切片、重叠 `as_strided` | stride/layout 类 54 个 |
| **非法输入**（新的上下文族） | 越界 index、形状不匹配的广播、超出定义域的值、dtype 不匹配的 target | "silently accepts" 56 个：oracle 期望 **两边都抛同类异常**，compile 不抛就是缺陷（O3 已支持，缺的是生成器） |
| 编译配置 | `torch._inductor.config` 开关（`emulate_precision_casts`、`freezing`、`cpp_wrapper`、`triton.cudagraphs`）、`mode="reduce-overhead"/"max-autotune"`、`fullgraph=True`、`torch.use_deterministic_algorithms(True)`、`autocast` 上下文 | 各 10–20 个；成本几乎为零（只是 compile 时的参数） |
| 数据依赖形状 | 链里插入 `nonzero`/`unique`/`masked_select`，后续算子消费其结果；`mark_dynamic`/`mark_unbacked` | dynamic/unbacked 48 个 |
| 自定义 autograd | `autograd.Function`（含自定义 backward/jvp）、二阶梯度、参数梯度（module） | autograd 44 个 |

### 路线 C：版本差分（把 §21 的 buggy/fixed 对照做实）

已经有的数据：同一批 reproducer 在 2.10.0（Kaggle）和 2.14.0（本机）上的检出集合。差集就是"2.10→2.14 之间修掉的/引入的"。扩展：
- 在 Kaggle 上再装一个 nightly（`pip install --pre torch --index-url .../nightly/cu128`）跑同一批 → 三版本对照；
- nightly 上跑路线 A/B 生成的新程序：**新缺陷最可能在 nightly 而不是发布版**（发布前 CI 已扫过一轮），这是 RQ5 真正该用的目标版本；
- 本机 CPU 也可以装 nightly 到一个 venv 里。

## 5. 换角度：不只是"生成更多程序"

上面三条都是在生成器一侧加东西。下面这些角度改的是 **oracle、执行方式、目标层**，其中几条不需要编译、成本极低，且直指 var_mean 那类缺陷所在的位置。

### 5.1 分解-核函数差分（不用编译，秒级几千个输入）

Inductor 不直接执行 aten 算子，而是执行 `torch._decomp` 里的 Python 分解；var_mean 空张量给 0 就是分解在 N=0 时的行为。分解函数可以**直接用真实张量调用**（`torch._decomp.get_decompositions([aten.var_mean])[...]`），不经 Dynamo/Inductor，与 eager 核函数比对：
- 一秒可测上千个输入，能把边角输入（空、size-1、零维、int/bool、非连续、负步长、NaN/Inf、极值）穷举一遍；
- 分解表约 400 个算子，全部扫一遍是小时级；
- 命中的就是"编译后必错"的语义偏差，再用 torch.compile 确认一次即可。
对应 issue 类别：reduction、index/scatter、dtype promotion、conv/pool/interpolate 的分解版。

### 5.2 meta/FakeTensor 元数据差分（不用编译）

编译路径在 FakeTensor 上推导 shape/dtype/stride，推导错了就是 compile 崩溃或错 stride（挖到的 issue 里有 5 个"incorrect strides"、多个"meta implementation"）。测法：同一算子在 meta 设备/FakeTensorMode 下跑一次，与 eager 真实输出的 shape/dtype/stride/storage_offset 比。再加符号形状（`ShapeEnv` 造 SymInt 尺寸）跑一遍，直接暴露 `numel()`/`int[2]` 那类 SymInt 不支持——cov 和 max_pool2d 两条都属于这一类。

### 5.3 变形关系（metamorphic）代替 eager 参考

两边都是编译产物，不存在"编译合法地改变数值"的争议（和 cold/warm 一个道理）：
- **批切分**：`f(cat(a,b))` 与 `cat(f(a), f(b))` 逐行一致——直接打 Inductor 按尺寸生成的 tiling/vectorization 尾部处理（"non power of 2 size" 那类 issue），而且不要求程序读 shape；
- **布局不变**：`f(x)` 与 `f(x.contiguous())`、`f(x.clone())`、`f(x.T).T`（对可换维算子）；
- **配置差分**：同一函数在 `dynamic` 开/关、`cpp_wrapper` 开/关、`freezing`、`mode=reduce-overhead/max-autotune`、`emulate_precision_casts` 下的两次编译结果互比；
- **幂等/复用**：同一编译产物用**同一个输入对象**连续调两次（不是每次 clone）——原地写回、copy-back、stale read 那类缺陷只在复用对象时出现。

### 5.4 "值怎么到达算子"作为语义因子（binding form）

max_pool2d 那条的触发条件不是值，而是**值以函数参数（默认 dict）传入**导致成为 SymInt。同一个标量可以通过字面量 / 位置参数 / 关键字参数 / 默认参数 / 闭包 / 全局 / 对象属性 / `**kwargs` 展开 / 列表元素 到达算子，Dynamo 对每种来源的特化策略不同（常量、SymInt、guard）。对每个标量参数系统生成这 9 种绑定形式，是现有计划"Python 语义因子"的自然延伸，实现只是 AST 改写，成本很低，而且是现有工具都没做的维度。

### 5.5 反向路径

issue 里 44 个是 backward/jvp/double-backward，而我们只比一阶输入梯度。AOTAutograd 的 functionalization 和 partitioner 主要作用在反向图：把别名/原地写结构（计划 §8 的核心）放到**需要梯度的输入**上再比 backward；参数梯度（module）；二阶梯度；`autograd.Function` 自定义 backward/jvp；`retain_graph` 后第二次 backward。

### 5.6 跨进程磁盘缓存

计划 §14 提过但一直没测：FX graph cache / AOTAutograd cache 的 key 是否覆盖"图里烘焙进去的常量"——闭包常量、对象属性、`torch.tensor(py_float)` 生成的常量、inductor config。序列：开磁盘缓存，编译一次，改一个被烘焙的常量，`dynamo.reset()` 后再编译（模拟另一个进程）——命中缓存但结果错就是缺陷。现有 `--disk-cache` 开关已经能做这件事，只缺"改常量"的上下文。

### 5.7 真实模型（Kaggle 上现成）

Kaggle 镜像预装了 torchvision / timm / transformers。34 个 conv/pool/interpolate、mkldnn 布局类 issue 都来自真实模型。用小模型（resnet18、mobilenet、bert-tiny）配 `channels_last`、bf16 autocast、`dynamic` 批维、eval/train 切换，走我们的分层 + cold/warm 流程。这是计划 §11 第 3/4 类种子（官方 example、真实项目）在 GPU 上的落地。

### 5.8 另一条编译路径：export + AOTInductor

`torch.export` → `aoti_compile_and_package` 走的是 C++ wrapper 和另一套运行时，和 `torch.compile` 共用分解但不共用调度/缓存。同一程序在 compile 与 AOTI 两条路径上互比，是又一个"两边都是编译产物"的干净 oracle。

### 5.9 优先级（按"每小时机器时间的预期产出"）

1. **5.1 分解差分** + **5.2 meta 差分**：不编译，一天能扫完整个分解表和 OpInfo 边角输入，直指 var_mean 所在层。
2. **5.3 批切分 + 配置差分**：改 runner 就能加，复用现有语料。
3. **5.4 绑定形式因子**：AST 改写，小；论文上是新维度。
4. **5.7 真实模型上 Kaggle**：现成库，直接用 `--from-dir` 的录制模式。
5. 5.5 / 5.6 / 5.8 视前四步的产出再定。

## 4. 建议的执行顺序

1. 路线 B 中零成本的部分（配置开关、边角形状、整数 dtype、算子间 cast、非法输入上下文族）——都是给现有义务/上下文体系加条目，一天内能做完，然后在 OpInfo + issue 语料上重跑一轮。
2. 路线 A 的链合成器 + issue 加权词表，先在 CPU 2.14 上验证生成程序的有效率和静态分析的义务产出，再上 Kaggle。
3. 路线 C：Kaggle 装 nightly，跑路线 A/B 的产物；同时用 2.10/2.14/nightly 三版本差集补 §21 的历史基准。

评估上这三条各自对应一个可写进论文的对比：A（加权 vs 均匀）、B（因子扩展前后的检出/无效率）、C（发布版 vs nightly 的新缺陷数）。
