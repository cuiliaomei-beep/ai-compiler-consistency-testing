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

## 6. 第二轮换角度（2026-09-12，基于 13 条候选的"产出地图"）

先看哪些角度出了真缺陷、哪些没出：

| 角度 | 真缺陷 | 说明 |
|---|---|---|
| 5.1 分解 vs 核函数（边界输入变体） | 03 04 05 06 08 09 + nll_loss | **最高产**：空维、负 dim、1e±30、dtype 提升、channels_last 步长 |
| 5.3 配置差分（dynamic / max_autotune / cudagraphs） | 01 02 10 13 | 少走的 codegen 路径每条都有洞 |
| 5.8 export + AOTI | 11 12 | 序列化/functionalization 边界 |
| 5.5 反向 | 05(梯度归零) 07(崩溃) | 反向核函数比前向少测 |
| 5.6 磁盘缓存、5.4 绑定形式、5.7 真实模型、多算子程序 | 0 | 主流路径被大量用户覆盖，差分白跑 |

规律：缺陷出现在 **"合法但冷门"的输入类 × "合法但冷门"的编译路径**，而不是"更多随机程序"。下面的角度都按这个规律选，并且都能复用现有 `decomp_diff` / `metamorphic` 基础设施。

### 6.1 Inductor 配置开关扫描（最便宜，直接复用 metamorphic）
目前只开过 dynamic / max_autotune / cudagraphs / freezing。还有一批改 codegen 路径的开关，每个都是一条独立的代码路径：
`cpp_wrapper=True`（C++ wrapper 是另一套 codegen）、`pattern_matcher=False`（对比能暴露 pattern 重写引入的错：split_cat、mm_plus_mm、addmm 融合、fuse_attention）、`coordinate_descent_tuning`、`epilogue_fusion=False`、`cpp.simdlen=0/8/16`、`emulate_precision_casts`、`comprehensive_padding / shape_padding`、`layout_optimization=False`、`decompose_mem_bound_mm`、`force_disable_caches`、`triton.cudagraph_trees=False`。
做法：`metamorphic.config_sets()` 加 10 个配置，OpInfo 单算子 + 语料程序各跑一遍；与默认配置输出不一致即候选（同一编译器、同一输入，参考是默认配置而不是 eager）。预期：1–3 条（每条冷门路径历史上都出过）。

### 6.2 dtype 提升矩阵（08 的泛化，秒级）
08 是"带 weight 的损失函数 bf16×fp32 提升不一致"。系统化：对所有二元/三元 OpInfo 算子（binary_ufuncs、`where/lerp/addcmul/addcdiv/clamp(min=tensor)`、带 weight/pos_weight 的损失、`masked_fill(value=tensor)`）枚举 dtype 对（bf16/fp16/fp32/fp64/int64/bool/complex64，含 0-d 张量与 Python 标量），只比较 **输出 dtype** 与是否报错。eager/aot_eager/inductor 三路 + autocast(cpu, bf16) 下再做一遍。不需要数值比较，无误报；实现 ~150 行。预期：2–4 条。

### 6.3 复数与大规模归约两个新变体（5.1 里加两行）
`_variants` 目前没有 `dtype_complex64`（复数在 Inductor 多数走 fallback/view_as_real 分解，冷门）和 `large_reduce`（归约维 1e6 元素、bf16/fp16；eager CPU 用 double 累加，Inductor 用 fp32——05 的根因在更多算子上应当重现：`mean/norm/logsumexp/softmax/cumsum/prod`）。加上后全量重跑一次 5.1（本机 15 分钟）。预期：05 同族 2–3 条，复数 1–2 条。

### 6.4 反向路径加深（05/07 的泛化）
- **compiled_autograd**（`torch._dynamo.config.compiled_autograd=True`）：把反向图也编译，是 2.5+ 新路径，用户少、测试少。现有 `--grad` 扫描加一个开关即可对比。
- **双重反向** `autograd.grad(create_graph=True)` + 编译：二阶导的分解（`*_backward` 的反向）几乎无人差分。
- **编译的 optimizer.step**：`torch.compile(opt.step)` × {SGD/Adam/AdamW/RMSprop/Adagrad} × {foreach, fused, capturable, maximize, weight_decay, amsgrad} × {bf16 参数、复数参数、grad=None、稀疏 grad}，与 eager 参数更新逐位比较。CPU 可跑，实现 ~100 行。预期：1–2 条。

### 6.5 0/1 特化与运行时环境变化（01/13 与已知 #184405 的泛化）
- 用 batch=3 编译后分别喂 batch=0 / batch=1（Dynamo 对 0/1 特化，`mark_dynamic` + 0/1 是经典错区）、`mark_unbacked`、`nonzero/item` 产生的 unbacked SymInt 配 `torch._check`。
- **环境标志变化后复用编译产物**：autocast 进出、`torch.set_default_dtype`、`use_deterministic_algorithms`、`torch.set_grad_enabled`、`set_flush_denormal`、`torch.backends.mkldnn.enabled`、线程数。已知 #184405/#174386 就是这类"guard 漏掉环境"的缺陷。复用 metamorphic 的 reuse 关系，每个标志一个包装。预期：1–2 条。

### 6.6 Dynamo 的 Python 语义差分（新的缺陷类别，不是 Inductor）
到目前为止全部候选都在 Inductor/分解层。Dynamo 本身（字节码层）是 issue 最多的组件（§2 的 335 个标题里 Dynamo 占比最高）。做法：生成小的 Python 程序，覆盖 生成器、try/except/finally、上下文管理器、闭包修改 nonlocal、dict/set 顺序与原地修改、列表切片赋值、`functools.partial`、`*args/**kwargs` 转发、dataclass/NamedTuple、`isinstance` 分派、字符串格式化、`torch._dynamo.graph_break()` 插在中间（resume function 正确性）、在编译区内抛异常。参考 = 同一程序不编译；backend="eager" 即可（不碰 Inductor，秒级）。这是 nnsmith 类工具完全不覆盖的面。预期：3–5 条（Dynamo 缺陷多且修得快）。

### 6.7 PR 驱动的差分（把路线 C 从"版本对"变成"提交对"）
quantile 的 nightly 独有分歧指向 PR #188394（CPU quantile 改 nth_element，只改 eager 内核不改分解）。一般化：每天取 main 上改 `aten/src/ATen/native/*.cpp|cu` 的合并 PR，提取它们碰的算子，在 nightly 上只对这些算子跑 5.1/5.5 的全变体（几分钟），eager 内核变了而分解没变 → 分歧。这是"别人刚引入、还没人发现"的缺陷，报上去最受欢迎，也是论文里"持续差分"的卖点。实现：`gh`/GitHub API 取提交列表 → 正则取算子名 → `run.py decomp --only`。预期：每周 0–1 条，但都是新鲜的。

### 6.8 跨设备/随机性（需要 Kaggle）
- 13 的泛化：CUDA 张量与 CPU 0-d 张量混用（eager 允许 CPU 标量张量）、`device='cpu'` 工厂 kwargs、`.cpu()/.to()` 在编译区内，默认配置 + cudagraphs 各一遍。
- 随机算子：`fallback_random=True` 下 `rand/randn/dropout/bernoulli/multinomial/randperm/rand_like` 编译结果应与 eager **逐位相同**；配 dynamic shapes、cudagraphs 再跑。已知 cudagraphs 下 RNG 状态多次出问题。

### 6.9 优先级（按预期产出 / 实现成本）
1. **6.2 dtype 矩阵** 与 **6.3 两个新变体**：各半天，复用 5.1，最可能立刻出 3–5 条。
2. **6.1 配置开关**：半天，复用 5.3。
3. **6.6 Dynamo 语义差分**：1–2 天，打开一个全新的缺陷类别，对论文贡献最大（"编译一致性"不只是数值）。
4. **6.4 反向加深**（compiled_autograd + optimizer）：1 天。
5. **6.5 0/1 特化与环境标志**：半天。
6. **6.7 PR 驱动差分**：半天搭起来后每天自动跑。
7. **6.8 跨设备/随机**：需 GPU，放 Kaggle 批量跑。

### 6.10 第二轮执行结果（2026-09-12/13，见 EXECUTION_REPORT §3.O）

| 角度 | 产出 | 结论 |
|---|---|---|
| 6.2 dtype 提升矩阵 | 18 ldexp 双向 dtype 错、19 huber_loss（并入 08）、20 lerp(bool) 编译失败、21 sum/prod(dtype=bool) 编译失败 | **高产**，aot_eager 全对、Inductor 出错 → 都是 lowering 层 |
| 6.3 新变体 | 复数变体 grad 扫描 → **24 pinv/matrix_sqrth 复数梯度错**（AOTAutograd）；large_reduce 脚本 → 第 5 条的均值 1e5 例子 | 复数反向是新矿脉，用 `complex_grad_sweep.py` 系统化后只剩这两算子 |
| 6.6 Dynamo 语义差分 | 14 shuffle/sample 冻结、15 seed 首调用、16 f-string 格式码、17 namedtuple RecursionError（Py3.14）、22 str(KeyError) | **最高产**（151 个程序、30 秒、5 条），Dynamo 缺陷密度远高于 Inductor |
| 6.4 优化器差分 | 23 SGD foreach 复数编译失败 | 1584 个配置只 1 条：优化器主路径测得很好 |
| 6.1 配置开关 | 0 | 593 算子 × 20 配置 0 违例：冷门开关不改变单算子输出 |
| 6.5 0/1 特化 + 环境翻转 | 0 | 260 项全一致（除已知 RNG 行为） |
| 6.7 PR 驱动 | 脚本可用；本周相关提交在 nightly 上未引入新分歧 | 每周跑一次即可 |

下一批值得做的（按同样的"冷门 × 冷门"规律）：Dynamo 语义第三批（异步/生成器协议、`__torch_function__` 子类、`torch.Tensor` 子类、weakref、`sys.settrace`、多线程 `threading.local`、`copy.deepcopy(module)`、pickle 往返）；dtype 矩阵扩到一元算子 × autocast 与 `out=` 参数；复数反向扩到 fft 与 `torch.func.jvp`（前向模式）；6.4 加 `torch.compile(loss.backward)` / compiled_autograd。

### 6.11 第三轮执行结果（2026-09-13，§6.10 末尾的角度）

| 角度 | 产出 | 结论 |
|---|---|---|
| 一元算子 × dtype × autocast × out= | 26 bitwise 对 float 垃圾值（#144247 部分重复）、29 nan_to_num(complex) 编译失败、30 abs out= dtype | dtype 提升本身 0 分歧（含 autocast）；产出都在"eager 接受/拒绝 vs compile 相反"一类 |
| 二阶导 | — | 框架明确不支持（RuntimeError 有说明），不适用 |
| 前向模式 AD（compile(jvp(f))） | **27 ldexp 进程崩溃**、**28 quantile/addr/nanquantile `_make_dual` 断言**（Linux 三后端全断言） | 507 算子数值 0 分歧，但崩溃/断言两条都是新的；注意 `jvp(compile(f))` 不触发编译，必须编译包装 |
| Dynamo 语义第三批 | 0 | 饱和 |
| vmap 经编译（compile(vmap(f))） | 0 | 678 算子 0 分歧：批处理规则与 Dynamo 追踪一致 |
| 复数前向 AD | 0 新 | 只有 addr 的同一断言（28） |

再往下值得试的：`torch.func.vmap` 经编译（batching rule vs 分解）；`torch.func.hessian/jacrev` 经编译；复数 + 前向 AD（`forward_ad_sweep.py --dtype complex64`）；`out=` 参数扩到二元算子；CUDA 上重跑 6.4d/6.2b（Kaggle）。

## 7. 第四轮候选角度（2026-09-20 提出）

前三轮的规律仍然成立：缺陷在"合法但冷门的输入"×"合法但冷门的编译路径"。前三轮已经把**输入的数值/类型/形状**这一轴挖得比较透（分解差分、dtype 矩阵、大归约），把**编译选项**这一轴挖完（0 违例）。下面七个角度换的是**另外两根轴：张量的内存布局与别名关系、程序的副作用与状态**，都是前三轮没有系统覆盖的。

### 7.1 布局 / 视图 / 别名矩阵（推荐先做）
同一个算子，输入换成：转置、`expand` 出来的 0 步长张量、带 `storage_offset` 的切片、`[::2]` 这类跨步视图、`as_strided` 造出的自重叠张量、以及两个参数共享同一块内存的情形；前向与反向都比。判据：数值 + 输出步长 + 是否报错，三者与 eager 一致。
理由：Inductor 历史上大量缺陷是步长/布局相关（已知 open #184101 就是"转置的复数张量做 abs 的反向崩溃"）；我们只测过 `noncontig` 与 `channels_last` 两种，且只在前向。
成本：半天，复用 `decomp_diff` 的算子遍历。预期：2–4 条。

### 7.2 原地修改与 functionalization
带 `_` 后缀的原地算子、`copy_` / `index_put_` / `masked_fill_` / `scatter_`、对输入和对视图的修改、以及"多次修改的先后顺序"。判据：函数返回值一致 **且** 调用者手里的张量内容一致（这一点我们从来没查过）。
另一个子项很可能出静默缺陷：**改动了反向需要用的张量**——eager 会抛"variable needed for gradient computation has been modified"，如果编译后不报错而给出别的梯度，就是高价值缺陷。
成本：半天。预期：1–3 条，且容易是高优先级。

### 7.3 钩子（hooks）
`module.register_forward_hook` / `register_full_backward_hook` / `register_forward_pre_hook`、张量的 `register_hook`。判据：是否被调用、调用次数与顺序、拿到的值是否与 eager 相同、在 hook 里修改梯度是否生效。
理由：钩子是用户代码里极常见的东西（打印、梯度裁剪、特征提取），而它属于"图之外的副作用"，正是 Dynamo 容易处理不全的地方；我们一条都没测过。
成本：半天。预期：1–3 条。

### 7.4 自定义算子与自定义反向
用 `torch.autograd.Function` 写一个**故意与自动求导不同**的反向（例如返回 2 倍梯度），再用 `torch.library.custom_op` 注册一个自定义算子。判据：编译后是否真的用了用户的反向（比数值，不只是"没报错"）、`mark_dirty`/`once_differentiable`/`setup_context` 是否被尊重、自定义算子的 fake 实现与真实实现是否一致。
理由：PyTorch 自己有一条 open issue（#193277）就是"Dynamo 悄悄丢掉了用户自定义的 jvp"，说明这条路径薄弱；训练框架（PEFT、量化库）大量使用自定义 Function。
成本：半天。预期：1–2 条，可能是静默错梯度。

### 7.5 守卫与重编译序列
同一个编译产物，连续喂入属性逐步变化的输入：dtype 变化、连续 vs channels_last、`requires_grad` 从 False 变 True、可选参数从 `None` 变成张量、模块 `train()`/`eval()` 切换、被特化过的标量参数取 0/1/2。判据：每一次调用都与 eager 相同。
理由：守卫判断"能否复用已编译代码"，判错就是静默错结果。我们测过"环境翻转"（0 发现），但没测过"输入属性序列"，二者机制不同。
成本：半天。预期：1–2 条。

### 7.6 插入 graph break 作为变形关系
对语料里的程序，用 AST 改写在每个语句位置插入一次 `torch._dynamo.graph_break()`，结果必须与不插入时完全一致。复用第 5.4 节已有的 AST 改写设施。
理由：graph break 把一个图拆成两半并生成"恢复函数"，跨越 break 的局部变量、副作用、异常状态都要正确搬运——这是 Dynamo 最复杂的一段代码。我们只在手写的几个程序里碰过。
成本：半天。预期：1–2 条。

### 7.7 export / AOTI 的"取回后再算"
目前只检查了 export、分解、打包这三步会不会报错；从没有把打包后的产物**加载回来运行并比数值**。加上：`torch.export.save/load` 往返、AOTI 包加载后推理，与 eager 比数值与 dtype。
成本：半天（Windows 上 AOTI 加载曾有临时目录问题，可放 Kaggle Linux 跑）。预期：1–2 条。

### 优先级
1. 7.1 布局/别名（最可能高产，且与已知缺陷族同源）
2. 7.3 钩子、7.2 原地修改（都指向"副作用"这根新轴，且容易出静默缺陷）
3. 7.4 自定义反向
4. 7.5 守卫序列、7.6 graph break、7.7 AOTI 取回
另外维持每周一次 6.7 的 PR 驱动复核（几分钟，抓新引入的回归）。

## 8. 第五轮候选角度（2026-09-20 第二次提出）——换"判据"而不只是换"输入"

§7 换的是输入轴（布局、副作用）。下面这批换的是**判据/参照物**：不再只问"编译结果 == eager 结果"，而是问"该报错时报错了吗""比真值差多远""和 NumPy 一致吗""换个 Python 版本还一样吗"。每条都配一个脚本、逐算子独立子进程、jsonl 逐条落盘可续跑；确认的缺陷要在草稿里附**建议修复**（定位到 lowering / decomposition / Dynamo VariableTracker 的具体文件）。

### 8.1 错误一致性（OpInfo `error_inputs` 差分）——`scripts/error_parity_sweep.py`
OpInfo 自带 `error_inputs`：每个算子一批**非法输入**及 eager 应抛的异常类型与消息。把它们喂给三个后端：eager 抛而编译**不抛**（越界索引静默读到垃圾）是高优先级静默缺陷；抛的类型/消息不同是低优先级。理由：Inductor 的 C++/Triton 代码里边界检查是可选的（`assert_indirect_indexing`），decomposition 也常省掉 `TORCH_CHECK`。从没测过。成本：脚本 1 小时，跑 1 小时。预期：2–4 条。

### 8.2 整数与类型转换的 C++ 未定义行为边界——`scripts/int_ub_sweep.py`
float→int 越界转换（1e20、inf、nan、2^31、2^63）、`INT_MIN` 的 neg/abs/div(-1)、有符号溢出、移位 ≥ 位宽与负移位、`%`/`//` 的符号、int pow 溢出、bool 算术、int8 求和/累乘/`cumsum` 的累加类型、2^53 附近 int64 与 float 比较、`round` 半偶数在 2^23 边界。eager 由 ATen 的实现定义语义；Inductor 生成的 C++ 遇到 UB 时由编译器决定，二者不一致就是 issue。再叠一层**长度扫描 1..65**命中向量化主体与标量尾部两条路径。成本：半天。预期：2–3 条，整数可精确比较，零误报。

### 8.3 特殊函数精度 vs 高精度真值（mpmath）+ 尾部长度扫描
`torch.special.*`、`lgamma/digamma/polygamma/erfinv/erfcx/i0e/i1e/ndtri/log_ndtr/zeta/gammainc`、`expm1/log1p/atan2/pow/fmod/hypot/sinc`，在对数间隔的参数区间上，以 mpmath 为真值分别算 eager 和 Inductor 的 ULP 误差。判据：Inductor 误差比 eager 大 ≥ 100 倍的区间（或 inf/nan 出现位置不同）。理由：Inductor 有一套自己的特殊函数实现（`torch/_inductor/codegen/cpp_prefix.h`、Triton `libdevice`），与 ATen 不是同一份代码。成本：半天。预期：1–3 条。

### 8.4 NumPy-in-Dynamo 差分（`torch._numpy` vs 真 NumPy）
Dynamo 会把编译区域里的 numpy 调用翻译成 `torch._numpy`——这是对 NumPy 语义的一次**重实现**。判据是真 NumPy：对每个 ufunc × dtype（含 uint、bool、float16、object 之外的全部）× 标量/0 维/广播用例，比 dtype、shape、值。理由：dtype 提升规则（NumPy 用值相关提升 / NEP50，torch 不是）、整数除法、越界转换、`np.sum(bool)` 的返回类型——这类差异官方文档只列了一部分。成本：半天。预期：3–5 条（其中部分会被标为"已知限制"，需先对照 `torch/_numpy` 的文档与已开 issue）。

### 8.5 控制流高阶算子（`torch.cond` / `while_loop` / `scan` / `associative_scan` / `torch.utils.checkpoint`）
两条分支返回不同 dtype/步长、循环携带量形状变化、`associative_scan` 与顺序累积的数值、`checkpoint` + dropout 重算时的 RNG 一致性（`preserve_rng_state`）；前向与反向都比。理由：高阶算子是活跃开发区，eager 语义与编译语义分别实现。成本：半天。预期：1–3 条。

### 8.6 数据依赖形状与形状整数算术
`nonzero/unique/masked_select/repeat_interleave(tensor)/bincount/item()` 在 `capture_dynamic_output_shape_ops` / `capture_scalar_outputs` 下与 eager 比；再单独造一批"输出尺寸由形状整数表达式决定"的程序（`n//3*3 - n%5`、`math.ceil(n/7)`、负偏移切片），在 `dynamic=True` 下扫具体尺寸 0..40。理由：unbacked SymInt 与 SymPy `FloorDiv/Mod` 化简是历史缺陷高发区。成本：半天。预期：1–3 条。

### 8.7 Python 版本差分与平台差分
同一份 Dynamo 语义语料（185 个程序 + dynsem 新增）分别在 Python 3.11/3.12/3.13/3.14 上跑：只在某个版本出错的就是 Dynamo 对该版本字节码的翻译缺陷（3.14 支持很新）。平台差分：Windows/MSVC 与 Linux/GCC 的 Inductor 结果对比（`long` 在 MSVC 上是 32 位、OpenMP 2.0 只允许有符号循环变量）。成本：装解释器 1 小时（uv），跑 1 小时。预期：1–2 条。

### 8.8 编译组合律
`compile(compile(f))`、编译函数调用另一编译函数、调用 `torch._dynamo.disable` / `allow_in_graph` 包裹的函数、`compile(mod)` vs `mod.compile()` vs `compile(mod.forward)`、同一函数被 `compile` 两次（不同 backend）、`fullgraph=True` 与否；判据全部一致。成本：2 小时。预期：1 条。

### 8.9 异常前的副作用与 graph break 恢复重放
`x.add_(1); raise ValueError` 这种程序，eager 里 x 已被改；编译后若回滚、或因 Dynamo 重启分析而**重放两次**，都是缺陷。与 7.6 共用 AST 设施：在每个语句后插 graph break，同时在函数里放副作用（原地改、列表 append、全局计数器、print 计数），比副作用次数。成本：2 小时。预期：1–2 条。

### 8.10 CI 跳过/容差清单挖掘
`test/inductor/test_torchinductor_opinfo.py` 的 `inductor_skips` / `inductor_expected_failures_*` / `inductor_override_kwargs`，`test/test_decomp.py` 的 `CROSS_REF_EXCLUDE_SET` 与容差覆盖，`test/dynamo/` 的 `expectedFailure`：凡**没有链接 issue** 的条目，复现并查重，能复现且无 issue 的就是"CI 知道但没人报"的缺陷。成本：半天。预期：2–4 条（部分会被回复"已知"）。

### 8.11（小）autocast 全算子扫描；8.12（GPU）`reduce-overhead` 输出陈旧检测
6.2b 只扫了一元算子；扩到全部 OpInfo 算子（输出 dtype + 数值）成本很低。cudagraphs 下跨调用保留输出应报错而非静默读到被覆盖的值——Kaggle T4。

### 优先级（合并 §7 与 §8）
1. **8.1 错误一致性**、**8.2 整数 UB**（最便宜、判据最硬、零误报）
2. **7.1 布局/别名**（与已知缺陷族同源）
3. 8.4 NumPy 差分、8.7 Python 版本差分（参照物现成、可能高产）
4. 7.3 钩子、7.2 原地修改、8.9 副作用重放
5. 8.3 特殊函数精度、8.5 高阶算子、8.6 数据依赖形状
6. 7.4、7.5、7.7、8.8、8.10、8.11、8.12

## 9. 跨目标：把工具从 PyTorch 扩到其它 Python 驱动的编译栈（2026-09-20，用户提出"工具还不能测 PyTorch 以外的"）

现状：27 条 issue 全在 pytorch/pytorch。PyTorch 是入口，但它下面和旁边还有独立的编译栈；论文的外部效度也需要第二、第三个对象。方法本身只依赖两件事——**有一个不编译的参照执行**、**能只改一个因子**——所以可以按"目标适配器"扩展：

| 目标 | 编译入口 | 参照 | 本机可跑？ | 状态 |
|---|---|---|---|---|
| NumPy-in-Dynamo（`torch._numpy`） | `torch.compile` 包 numpy 函数 | CPython + NumPy | 是（主环境） | **已接**：`scripts/xtarget_numpy_diff.py --target dynamo` |
| Numba | `numba.njit` | CPython + NumPy（同一函数的 `py_func` 语义） | 是（`..\venv_xtarget`，numba 0.67 / numpy 2.5 / Py3.14） | **已接**：`--target numba` |
| JAX / XLA | `jax.jit` | 同一函数在 `jax.disable_jit()` 下逐算子执行 | 是（`..\venv_xtarget`，jax 0.11 CPU） | **已接**：`--target jax` |
| ONNX Runtime（torch → onnx → ORT） | `torch.onnx.export` + ORT | PyTorch eager | 是（onnxruntime 1.30 已装） | 待接：复用 AOTI 分析器的骨架（OpInfo 样本包成 Module） |
| Triton（`@triton.jit` 内核） | Triton JIT + 缓存 | 同一内核的 NumPy/torch 参照实现 | 否（需 GPU）→ Kaggle T4 | 待接：dtype/constexpr/块大小/`num_warmups` 单因子 + 缓存序列 |
| TileLang / TVM | 各自的 JIT | Python 参照 | 否 → Kaggle | 计划 §19 的原定对象，排在 Triton 之后 |
| TensorFlow XLA（`tf.function(jit_compile=True)`） | XLA | TF eager | 否（Windows 无 XLA）→ Kaggle | 备选 |

设计：一份 NumPy 风格语料（`xtarget_numpy_diff.py` 里 268 个小程序：整数极值对、移位越位、有符号零/NaN/inf/次正规数、半偶舍入、混合 dtype 提升、归约、索引/切片、线代），每个目标一个适配器（怎么编译、参照是什么、哪些异常算"不支持"），比 dtype / 形状 / 值 / 异常。每个程序一个子进程（崩溃即发现）。结果在 `results/xtarget/<target>.jsonl`，`--report` 出摘要。

判定口径要比 PyTorch 严：Numba 与 JAX 都有**文档化的语义偏离**（Numba：不做越界检查、整数除零的 error model、部分提升规则；JAX：越界索引钳位、默认 32 位），这些不算缺陷；报告前逐条对照官方"deviations"文档。JAX 的参照取 jit 关闭的 JAX 自己而不是 NumPy，就是为了把"JAX 与 NumPy 的设计差异"排除在外，只留"编译改变了行为"。

## 10. 第六轮角度（2026-09-21）——从"这两天什么最出货"反推

回看第四/五轮的 11 份草稿，出货的不是"更多输入"，而是四种**结构性位置**：
(a) **同一语义的第二份实现**（Inductor 的 lowering / 向量化内核 vs eager 内核；`torch._numpy` vs NumPy）——08、09、02、03、11；
(b) **eager 的保护机制在编译路径上丢失**（校验、版本计数器）——01、04；
(c) **向量主体 vs 标量尾部 / 不同指令集**——07、09；
(d) **"无害"的图改写其实有前提**（成对 cast 被消掉）——10。
下面的角度都是把这四个位置系统化，外加几个还没碰过的轴。每条仍然是：一个脚本、逐项子进程、jsonl 续跑、确认后定位源码给修法。

### 10.1 图改写的前提（noop 消除 / 代数化简 / 模式匹配）——对应 (d)，最优先
Inductor/AOT 有一批"显然等价"的改写：`x.to(a).to(b)`、`x + 0`、`x * 1`、`x / 1`、`x - x`、`x ** 1`、`cat([x])`、`view→view`、`clone` 消除、`expand` 成自身、`slice(0, None)`、`permute` 两次、`sum(softmax)`→1（已有 #189787）、pad_mm / addmm 融合、split_cat、`randperm_index_add`（#121135）。每条改写都有隐含前提：NaN/inf/-0.0（`x + 0` 把 -0.0 变 0.0，`x - x` 对 NaN/inf 不是 0）、溢出与中间 dtype（10 号就是这一类）、别名（消掉 `clone` 后再原地改）、步长/内存格式、requires_grad。做法：枚举 `torch/_inductor/fx_passes/*.py` 与 `pattern_matcher` 注册的模式，为每条改写写"前提恰好被破坏"的小程序。预期 3–5 条，其中别名类可能是静默错值。

### 10.2 前缀一致性：逐点算子的结果不应取决于张量长度 / 对齐 / 线程数——对应 (c)
09 号是手工碰到的；把它变成通用变形关系：对**每个逐点 lowering**，`compiled(f)(x[:n])` 对 n=1..70 必须等于 `compiled(f)(x)[:n]`（同一元素，换长度就换了"向量主体/尾部/掩码加载"路径），再叠加 `storage_offset=1`（不对齐指针）和 `torch.set_num_threads(1/4)`。两侧都是编译结果，不需要浮点容差（要求逐位相等），零误报。覆盖 float16/bfloat16/int8/uint8/bool 这些有专用向量类的 dtype。预期 2–4 条。

### 10.3 编译后的"模型手术"与超参数变化——守卫的真实使用场景
用户最常做而我们没测的序列：编译后 `requires_grad_(False)` 冻结/解冻层（梯度应为 None 而不是 0 或陈旧值）、`module.half()/to(dtype)`、替换子模块、`load_state_dict`、参数共享（tied weights 的梯度要相加）、`parametrize`/`weight_norm`；编译的 `optimizer.step` 在步间改 `param_group['lr'|'weight_decay'|'betas']`（Python float 被特化→要么重编译要么**用旧 lr**）、LR scheduler、`GradScaler` 遇 inf 跳步、`clip_grad_norm_`。判据：每一步的参数/状态与 eager 逐步相同。预期 1–3 条，且一旦有就是静默训练错误。

### 10.4 eager 的其它保护/诊断机制是否还在——对应 (b)
版本计数器已经出了 01。同类机制还有：`torch.autograd.set_detect_anomaly`（反向出 NaN 应报错）、`torch.use_deterministic_algorithms(True)`（非确定性算子应报错；`fill_uninitialized_memory`）、inference tensor 的限制（"Inplace update to inference tensor outside InferenceMode"）、`torch.autograd.forward_ad` 的不支持报错、`check_nan`、`set_warn_always` 下的警告（如 std 自由度≤0、`lr_scheduler.step` 顺序）、整数除零的 `ZeroDivisionError`（CPU eager 抛，Inductor 已有 `inductor_cpu_integer_div_error` 标志——测它在各形态下是否都触发）。预期 2–3 条，可并入 #197554 或单独报。

### 10.5 进图的 Python 标量算术（SymInt/SymFloat vs Python 语义）
`dynamic=True` 或 `capture_scalar_outputs` 下，`x.shape[0]`、`.item()` 流进 Python 算术后由 SymPy 求值：`//` 与 `%` 对负数、`round()` 的银行家舍入、`int()` 截断、`divmod`、`**`（负指数、大指数）、`<<`、`math.floor/ceil/trunc`、`min/max` 混合类型、bool 算术、**超过 2^63 的大整数**（Python 任意精度 vs int64 符号整数）、float 转 int 的边界。随机生成整数/浮点表达式程序，扫具体取值，与纯 Python 比。§8.6 提过但没做。预期 2–3 条。

### 10.6 全 lowering 表 × 边界值（自动枚举，代替手写 260 例）
8.2 是手写清单；`torch._inductor.lowering.lowerings` 有上千个条目。自动对每个逐点/归约 lowering 套 8.2 的边界值向量，dtype 扩到 float16/bfloat16/int16/uint8/bool 与混合 dtype，参照 eager。08、09、11 都属于这一类，说明手写清单只碰到冰山一角。预期 3–5 条。

### 10.7 32 位索引边界
Inductor 在"看起来不大"时用 int32 索引。测：元素数跨 2^31（uint8 张量 2.2 GB，本机内存够）、先用小形状编译再用 `dynamic=True` 喂大形状（索引类型在编译时定了，守卫是否重编译）、步长×尺寸乘积溢出但 numel 不大的 `as_strided/expand`。一旦有就是静默越界，优先级高；用例只有十来个。

### 10.8 随机数的分布正确性（统计判据）
之前只比了"是否推进状态"。Inductor 有自己的 Philox 实现：`rand` 是否取到 1.0 / 半精度下的取值格点、`randint` 上界与偏差、`bernoulli(p)` 的频率、`normal` 的均值方差与尾部、`multinomial`、`randperm` 的均匀性、`dropout` 的缩放与 p=0/p=1 精确性、同种子两次编译运行自洽。KS / 卡方检验，阈值取极保守。预期 0–2 条，但这是完全没碰过的判据。

### 10.9 环境变量 × 磁盘缓存键（回到"有毒编译"的缓存主题）
5.6 验证了"源码里的常量"都进了缓存键；没验证**环境**：`ATEN_CPU_CAPABILITY`/指令集、`OMP_NUM_THREADS`（生成代码里烘焙了线程数）、`CC/CXX` 编译器与版本、`TORCHINDUCTOR_*` 环境变量、`LD_PRELOAD`/数学库、Python 小版本。两进程共享缓存目录，第二个进程改一个环境因子：命中且行为不同 = 缓存键缺项（共享缓存目录的 CI / 容器 / NFS 场景下就是跨机器的陈旧制品）。与论文的 cache consistency 主线直接呼应。预期 1–2 条。

### 10.10 编译历史无关性
28 号（jvp 断言）暴露过"同进程里先跑什么会改变后面的结果"。把它变成变形关系：程序 B 单独跑的结果，必须等于"先编译并运行任意程序 A 再跑 B"的结果（不 reset / reset 两种）。语料两两抽样。预期 1–2 条。

### 10.11 更多跨目标（§9 续）
(1) **ONNX 导出路径**：`torch.onnx.export(dynamo=True)` → onnxruntime（已装）对 OpInfo 样本与边界值，参照 eager；这是 PyTorch 之下另一条独立的"源码→制品"链。(2) **Numba 的其它编译模式**：`parallel=True`/`prange` 归约（竞态、归约初值）、`fastmath=True`、`@vectorize`/`@guvectorize`、`cache=True` 的磁盘缓存（改全局常量后是否陈旧——Numba 文档承认全局量被冻结，但缓存是否跨进程陈旧是另一回事）。(3) **CPython 自己的 JIT**（3.13+ 的 copy-and-patch JIT，`PYTHON_JIT=1`）：用我们 185 个 Python 语义小程序做 JIT 开/关差分——这是整个栈最底下那层"Python 驱动的 JIT"。(4) Triton（Kaggle T4）。

### 10.12 全局模式 × OpInfo
在 `set_default_dtype(float64)`、`set_default_device`、`use_deterministic_algorithms`、`set_flush_denormal`、autocast(bf16) 这些全局模式**之下**重跑一遍编译差分（以前只测过"模式翻转后复用"）：图里烘焙的常量与工厂函数（`arange/full/tensor(1.5)/linspace`）的 dtype 是否跟随模式。成本低，预期 1–2 条。

### 优先级
1. **10.1 改写前提**、**10.2 前缀一致性**（便宜、零误报、与已出货的 10/09 同类）
2. **10.3 模型手术/超参数**、**10.4 保护机制**（一旦有就是静默训练错误或可并入维护者正在跟的伞形 issue）
3. 10.5 标量算术、10.6 全 lowering 表、10.7 32 位索引
4. 10.9 环境×缓存键、10.11 ONNX/Numba 并行/CPython JIT
5. 10.8 随机分布、10.10 历史无关性、10.12 全局模式

### 10.13 C++ 工具链层：内建函数组合的优化级别差分（2026-09-21 新增，**已落地**）

- 动机：草稿 16 表明"Inductor 生成的 C++ 是对的，错在宿主编译器"。Inductor CPU 后端的正确性依赖 MSVC/GCC/Clang 对 `Vectorized<T>`（即 x86 内建函数）代码的优化是保语义的，这一层此前没人替 PyTorch 测。
- 工具：`scripts/cxx_intrinsic_algebra_diff.py`。不经过 PyTorch，直接生成小函数（代数化简器会去匹配的形状：对合/幂等、常量重结合、select→min/max、洗牌合成、int↔float 往返），同一份源码用 `/Od` 与 `/O1`、`/O2`、`/arch:AVX2`、`/arch:AVX512` 各编一份，在每种 lane 宽度 16 个边界值的全部配对上比较（FNV 哈希；浮点另比一遍 NaN 规范化后的哈希）。编译 11 万个函数只要 30 秒。
- 结果（MSVC 19.44）：三个缺陷 → 草稿 16、17、18。整数域、洗牌、pack、int↔float 往返全部干净（负结果）。
- 后续：① g++/clang++（Kaggle，`--compiler gcc|clang`）；② 词表 v3：`fmadd` 家族、`mask_*`（AVX-512 掩码算子）、`cvt` 饱和/截断窄化、`maskload/maskstore`（Inductor 尾部处理就用它）；③ 三层组合与"公共子表达式"形状 `B(U(x), U(x))`；④ 同样的思路下沉到 Triton→LLVM（`tl.where`/`tl.abs`/`tl.minimum` 组合，`-O0` 对默认）；⑤ 直接拿 Inductor 真实生成的内核（`TORCH_COMPILE_DEBUG` 导出的 .cpp）做 `/Od` vs `/O2` 差分——把现有 sweep 的产物复用成编译器测试语料。

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

**进度（2026-09-22）**：11.1 完成（三族真缺陷：#197894、23 号稿、26 号稿；其余是工具假象）。11.2 完成（25 号评论稿；形状/分解/SymBool 全对）。11.3：`overrides_pair_audit.py` 无新不对称；Python wrapper vs C++ wrapper 差分 174 程序 + 138 表达式基本一致（台账 62，负结果），副产物：Python wrapper 用 `repr()` 打印复数 → `infj` NameError（台账 59，响亮）、`int(item())` 非有限值静默 INT64_MIN（台账 61，= #158087）。11.4：`scripts/opinfo_edge_sweep.py`（OpInfo 全算子 × 边界值 × f16/bf16/int8/uint8/int16/bool/f32/int32；本机 2 分片 + Kaggle 3 个 kernel）运行中；预探已给出 27 号评论稿（float16 融合链中间量，#183607）。11.5：本机只有 MSVC 14.44（票里那一版），无更新版本可复测。

## 12. 第八轮方向（2026-09-22 收工时整理）

§11 六个方向都已跑完（进度见 §11 末尾）。今天最省钱且命中的是 **11.4 的 OpInfo × 边界值全算子扫描**（`scripts/opinfo_edge_sweep.py`，一次跑遍 500+ 算子 × dtype，本机 + Kaggle CPU/T4 共约 6,000 对），命中 28 号稿；差分类工具（wrapper、ORT、Numba parallel/fastmath）全是负结果。经验：**"两条路径"要选成熟度差距大的一对**——wrapper 生成器、ORT 优化级别都是成熟且互相测试过的路径，差异为零；而"分解 vs 专门 lowering"（07、28）、"Interpreter vs 生成源码"（#197894、23、26）、"标量特化 vs 张量化"（02b、25）这种一边是主路径、一边是捷径的对子才出缺陷。

### 12.1 "专门 lowering 绕过分解里的特判" 静态审计（28 的推广）——最便宜，先做
- 枚举 `torch/_inductor/lowering.py` 里 `register_lowering` 的 aten 算子，取交集：同一算子在 `torch/_refs` / `torch/_decomp` 里的分解含有 dtype 特判（`if a.dtype is torch.uint8`、`is_boolean_dtype`、`int_to_float`、`exact_dtype`）、值特判（`if p == 0`、`beta == 0`）或校验（`torch._check`）。对每个交集算子生成小程序，比较 eager / aot_eager（走分解）/ inductor（走 lowering）的 dtype 与值。预期 2–4 条（28 一类）。
- 反向同理：有分解但 Inductor 又注册了 `fallback` 的算子，比较 fallback 内核与分解的边界行为。

### 12.2 OpInfo 边界值扫描的两档扩展
- `dynamic=True`（符号形状下 lowering 的分支不同，如 `use_two_step_variance` 依赖 `reduction_numel` 是否为常量）；`requires_grad=True` 跑反向（`gradcheck` 风格但只比 eager vs compiled 的梯度 NaN 模式 / inf / 值）。分片方式同 11.4，放 Kaggle。

### 12.3 评论补充（可选，低）
- numba #6976：0.67 上 `//`、`%`、`/` 在 parallel 下仍丢异常，Windows 上 `**` 负指数还给未初始化内存（`reports_xtarget/numba_parallel_lost_zero_division.py`）。
- pytorch #158087：`int(item())` 非有限值进张量时是静默 INT64_MIN（台账 61）。

### 12.5 计划表剩余项（2026-09-22 18:45 盘点）

已完成并记账：8.5 HOP（台账 84，负）、7.4 自定义算子（83，负）、8.3 特殊函数 vs mpmath（85 → 39 号稿）。未做：8.9 副作用 / graph-break 重放、7.6、8.8 编译组合（compile 嵌套 / 与 export、AOTI 组合）、8.7 / 8.10 / 8.12、Triton / TileLang 目标。8.3 的方法（对高精度参考而不是对 eager）值得推广到二元函数（`pow`、`atan2`、`hypot`、`xlogy`、`logaddexp`）和归约（`logsumexp`、`norm`）——目前的 `special_vs_mpmath.py` 只覆盖一元。

### 12.6 语料 × 蜕变关系（7.6 的推广；2026-09-22 19:30 记）

7.6 一轮就出两条新缺陷（台账 89 → 40/41 号稿），而同一语料的 6.6 差分三轮只有 19 处已知分歧——**换关系比换程序便宜且高产**。同一套 AST 改写设施上还能做的关系（每个半小时～两小时）：
1. **逐语句插 `print(...)`**（带副作用的 graph break，且副作用次数可数）：检查 print 次数与顺序——重放两次 / 漏掉一次都是 8.9 的缺陷；
2. **把每条语句包进一个内层函数再调用**（inline 边界）：Dynamo 的内联与直接追踪应等价；
3. **每条语句后插 `torch._dynamo.disable(lambda: None)()`**：disable 区域进出时的局部变量搬运；
4. **把函数体切成两半分别 `torch.compile`**（模拟用户手工拆分）：等价于 graph break 但走不同的恢复路径；
5. **在生成器 / 上下文管理器 / `try` 体内插 break**（deep 变体只多插 6 处——当前语料这些结构少，先给语料补 20 个含 with/try/生成器的程序再跑）；
6. 对 `side_effect_diff.py` 的 76 例也做 1–4（它们本来就是副作用程序）。
另一个方向是**重建（reconstruct）路径的系统检查**：41 号稿的机制是"追踪期对象 → 重建成别的 Python 对象"，凡 `VariableTracker.reconstruct` 有特殊实现的类型（生成器、迭代器、`range`、`functools.partial`、`itertools.*`、`enumerate`/`zip` 对象、`dict_keys` 视图、`namedtuple`、`Exception` 实例）都值得做"返回该对象 → `type()`、剩余行为、身份"三项比对——`torch/_dynamo/variables/*.py` 里 grep `def reconstruct` 共 60 余处。

### 12.4 论文口径
- `ISSUE_OUTCOMES.md` 现在覆盖两轮全部 54 项（第一轮 27、第二轮 27）；论文里 27/11/9 的口径仍待用户决定。

## 13. 收编计划：一个工具、一个方法（2026-09-22 22:33 记，用户要求）

### 13.1 方法的统一表述
所有 73 项都能写成同一个式子：**对同一程序 P 施加变换 T 后，沿两条执行路径 A、B 跑，用固定 oracle O 比较。**
- **输入源 I**（三种）：① OpInfo 样本 × 边界值替换（inf / nan / max / 近奇点 / 不支持的 dtype）；② 程序语料（Dynamo 语义 274 个、副作用 76 个、GitHub 复现程序 161 个）；③ 生成程序（NNSmith）。
- **变换 T**（蜕变关系，可为恒等）：逐语句插 graph break / 状态标记 / disable 调用 / print；dynamic=True；编译组合（compile∘compile、先 no_grad 后正常……）；执行上下文（TorchDispatchMode、autocast、reduce-overhead）；制品往返（export save/load、AOTI 打包加载、runner 销毁）。
- **路径 A/B**：eager（参照）↔ Dynamo-only（backend=eager）/ aot_eager / inductor / export / AOTI / cudagraphs / max-autotune；其它目标（Numba、JAX、MSVC 内建）只是换一对 A/B。
- **oracle O**（唯一实现）：数值（fp64 或 mpmath 参照、相对误差、NaN/inf 模式、零符号）、元数据（dtype / 形状 / stride / 别名与身份）、异常一致性（类型 + 是否被 handler 接住）、副作用与状态（STATE 快照、输入是否被改、print 次数）、进程级结果（崩溃、退出码）。
现有 35 个脚本的区别只在 (I, T, A/B) 的取值，O 已经基本共用（`opinfo_edge_sweep.diff` / `oracle.compare` / `dynamo_semantics._norm`）——所以统一是把参数化做出来，不是重写。

### 13.2 实现步骤（估 6–7 个工作日）
1. **接口**（1 天）：`tcc/probe.py` 定义 `InputSource`（产出 (program, inputs)）、`Relation`（program → program'）、`Path`（program → callable）、`Oracle`（统一 `compare()` 返回分类标签 VALUE / DTYPE / NAN / SIGNZERO / STRIDE / ALIAS / RAISES / SILENT / STATE / CRASH）；`run.py sweep --input … --relation … --paths … [--device] [--dynamic] [--shard]` 一个入口，复用 `sweep_common` 的隔离、续跑、崩溃标记与 Kaggle 分发。
2. **先迁高产的 6 个探针**（2 天，每个变成 ≤50 行配置）：`opinfo_edge_sweep`、`dispatch_mode_sweep(+grad)`、`graph_break_insertion_diff`（含四种关系）、`special_vs_mpmath(+binary)`、`error_parity_sweep`、`export_roundtrip_edge`。这 6 个覆盖第二轮 46 项里的约 35 项。
3. **迁其余探针或标记废弃**（2 天）：`layout_alias`、`scalar_arg_sequence`、`xtarget_numpy`（Numba / JAX 路径）、`cxx_intrinsic_algebra`（MSVC）、fx 三个、`compile_composition`、`reconstruct_diff`、`cudagraph_stale`、`autocast_sweep`、`side_effect_*`；一次性诊断脚本（`diag_*`、`$TEMP` 探针）归档不迁。
4. **统一报告与已知族过滤**（1 天）：`run.py triage` 读所有 jsonl，按 (op, class, 根因关键词) 聚类，对照 `TO_SUBMIT.md` / `ISSUE_OUTCOMES.md` 生成的已知族表自动打"已报 #N / 新"标签——这一步把目前手工分诊的最大成本自动化。
5. **回归验证**（1 天）：用统一入口重跑全部 (I,T,A/B) 组合，验证 73 项全部被重新命中（这就是论文里"检测器召回率"的直接证据），并记录每项由哪个 (I,T,A/B) 命中——同时得到"探针 → issue"表。
6. **与 `harness/` 合并**（待用户决定，0.5 天）：memory 记着 9 月 7 日的决定是"harness/ 继续、plan/tcc 最后合并"；现在实际产出都在 plan/tcc，建议以 plan/tcc 为基、把 harness/ 里独有的部分（若有）并入，而不是反过来。**这一条需要用户拍板。**

### 13.3 论文里的说法
"一个差分一致性检测框架：固定 oracle，三类输入源，一组蜕变关系，覆盖 PT2 栈的全部执行路径；73 项发现 = 该框架在不同 (I,T,A/B) 配置下的输出"。第 2 类（根因在 eager / fx / 运行时）和第 3 类（跨目标）按 §12 的归属字段分开统计。
