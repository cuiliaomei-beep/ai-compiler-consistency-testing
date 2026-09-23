# tcd — 一致性检测 harness（M1 最小闭环）

对应研究计划 v2.1 的 M1 里程碑：**在方法层的静态别名分析做出来之前，先把能产候选、能分诊、能出报告的闭环跑起来。**
方法可以边跑边加，但持续 fuzzing 必须最早启动——它是通往「20–30 个开发者确认」最长的关键路径。

```
eager / cold-compile / warm-cache 三路执行
  → 五个一致性 oracle（数值以 fp64 为基准判定）
  → 分层二分做阶段归因与分诊
  → failure signature 去重
  → 开发者可读的 issue 草稿
```

---

## 第一件事：两级自检

**这个 harness 没通过自检之前，它输出的任何东西都不算证据。**

```bash
cd harness
python run.py selfcheck             # 一级：oracle 本身对不对
python run.py validate              # 二级：整条上报链路通不通
python run.py selfcheck --offline   # 不依赖 torch 的部分
python tests/test_offline.py        # 报告与去重链路的离线测试
```

两级缺一不可，因为它们回答的是不同的问题：

- `selfcheck` 单独验证 oracle——注入一个**故意返回错误结果的 backend**，value oracle 必须报警；
  换成正确 backend 必须零发现。
- `validate` 验证 oracle **之后**的一切——runner、分诊、去重、record、issue 草稿。
  它把 D1 阶梯的顶层换成那个错误 backend，健康的流水线**必须**产出记录。

**没有第二级，「0 candidates」是有歧义的**：可能代码确实干净，也可能候选在某一环被静默丢弃了。
跑完 `validate` 之后，「0」才是一个有意义的结论。

自检不是走过场，它用**已知答案的情形**验证每一个结论所依赖的机制：

| 检查 | 验证的是什么 |
|---|---|
| `compile counter: cold compiles once` / `repeat is a cache hit` | 编译计数准确——**整个 cold/warm 判定（D2）都建立在这上面** |
| `compile counter: dtype switch recompiles` | 能区分「guard 正确触发重编译」与「静默复用」 |
| `value oracle fires on a wrong backend` | 故意注入一个**返回错误结果的 backend**；oracle 必须报警，否则真的误编译也检不出来 |
| `no false positive on a correct backend` | 正确 backend 下必须零发现，否则每晚的输出都是噪声 |
| `alias relation detects storage sharing` | 别名关系可比且与指针无关 |
| `fp64 reference builds` | 数值判定能用项目自身的精度政策 |

---

## 跑一次

```bash
python run.py list                        # 看已注册的用例
python run.py run --tag alias             # 只跑别名/原地写相关的
python run.py run --cases view_inplace --backend inductor --reruns 3
python run.py run --disk-cache            # 保留磁盘缓存，探测跨进程复用
```

`--backend` 只作用于 **D2（cold vs warm）** 探针。D1 阶梯固定是
`eager → eager → aot_eager → inductor`，因为正是这个固定顺序让阶段归因成为可能。

### 当前这台机器

`torch 2.14.0+cpu` · Python 3.14 · **无 CUDA** · MSVC 14.44 (VS 2022 Build Tools) + Windows SDK 10.0.26100。

- **E0 / E1 / E2 / E3 全部可用**，`selfcheck` 17/17。
- 首次冷编译约 15s（Inductor 在真的生成并编译 C++），所以完整 `run` 要按十分钟计。
- **没有 GPU**，因此跑不到 Triton 后端、CUDA kernel、vLLM / TileLang 那些目标。
  CPU 上能覆盖的是 Dynamo 捕获、functionalization、Inductor 的 C++ codegen 这三层。

#### MSVC 环境是自动导入的

Inductor 的 Windows CPU 后端要调 `cl`，而 `cl` 光有 PATH 不够——还需要 `INCLUDE` / `LIB`。
正常做法是从「x64 Native Tools 命令提示符」里启动，容易忘也容易搞错。
`run.py` 启动时会调 `ensure_msvc_env()`：用 `vswhere` 定位工具链，在临时 shell 里跑 `vcvars64.bat`，
把它设置的变量导进本进程。**所以在普通 PowerShell 里直接跑就行。**

如果哪天 E3 又开始报 `InvalidCxxCompiler`，先单独确认这一步：

```bash
python -c "import sys; sys.path.insert(0,'.'); from tcd.torchcompat import ensure_msvc_env; print(ensure_msvc_env(verbose=True))"
```

输出在 `reports/`：

```
reports/
  SUMMARY.md              按优先级分组的候选总表（每天先看这个）
  _dedup.json             signature → 首次出现，跨运行持久化
  <signature>/
    issue.md              开发者可读的 issue 草稿（提交前必须人工逐条核对）
    record.json           完整证据：三路观测、五个 oracle 的发现、分诊依据
    repro.py              用例源码 + 上下文
    environment.txt
```

---

## 两个探针

### D1 分层（eager vs 编译）

跑 `E0 eager` / `E1 backend="eager"` / `E2 aot_eager` / `E3 inductor`，用差异首次出现的层做归因。
**这同时是最省力的分诊过滤器**，不只是定位手段：

| 首次出现差异的层 | 归因 | 优先级 |
|---|---|---|
| E1 | Dynamo 图捕获语义 | **低**——多为 documented unsupported，提上去大概率 won't fix |
| E2 | AOTAutograd / functionalization | **高**——别名与原地写就住在这一层 |
| E3 | Inductor lowering / codegen | **高**——维护者最愿意处理的一类 |

### D2 warm（cold vs warm）

在上下文 A 下编译，**不 reset** 直接在上下文 B 下执行，与 B 的冷编译结果比。
两边都是编译产物，**不含 eager，因此没有浮点容差争议**——差异即缺陷。

结果按是否重编译分成三类：

| 有差异 | 重编译了 | 结论 |
|---|---|---|
| 是 | 否 | `specialization_cache` · **高**——guard 缺失，陈旧产物被复用 |
| 是 | 是 | `compile_nondeterminism` · 中——不是陈旧复用，是编译间状态泄漏 |
| 否 | 否 | `guard_suspicious` · info——guard 可能欠定但暂无可观察后果，用于指导后续变异（`--keep-info` 才记录） |

---

## 关键设计（都是容易做错的地方）

**浮点判定用 fp64 基准，不用固定阈值。**
`torch.compile` **合法地**改变数值（融合改变归约顺序、TF32、不同 epilogue），所以
`|compiled − eager| > eps` 会淹没在假阳性里。这里问的是 PyTorch 自己的精度套件问的问题：
*编译结果是否比 eager 更远离 float64 真值？* 只有这样才说明编译路径确实更不正确。
用项目自身的判据，报告就无法被「容差设太紧」驳回。

**别名比的是关系，不是指针。**
eager 与编译执行分配的是不同内存，`data_ptr()` 永远不同，比了没有意义。
可比的是 *关系*：在 `[inputs..., outputs...]` 这个索引列表里，哪些张量彼此共享 storage。
这才是编译器必须保持的东西。

**缓存有两层。**
`torch._dynamo.reset()` 只清进程内缓存，**清不掉**磁盘上的 FX graph / Inductor / Triton 缓存——
它们能活过 reset 甚至活过进程。冷跑时若静默命中磁盘缓存，D2 的判定就全是错的。
`cache_scope()` 把这个选择显式化；`--disk-cache` 则反过来用它探测跨进程复用（现有工具没测过这一面）。

**重编译要数，不能猜。**
改 dtype 通常会让 guard 失败并触发重编译——那是正确行为，不是缺陷。
有价值的事件是「切了上下文却**没有**重编译，而语义变了」。
我们统计 backend 的真实调用次数，所以这个过滤是精确的。

**同一上下文的多次执行必须拿到完全相同的输入。**
`make_inputs` 通常调 `torch.randn`，调两次就是两组不同的张量——于是 value 和 mutation oracle
比的是**互不相关的数据**，每个用例都会报差异。`build_inputs()` 在每次构造前重新播种，
这是比较成立的前提。（这个 bug 就是被上面的自检抓出来的：poison 与 identity 两个 backend
报出了同一条 mutation 发现，一眼可知是 harness 自己错了。）

**工具链失败 ≠ 语义分歧。**
后端根本编译不出来——缺 C++ 编译器、缺 triton、OOM、后端崩溃——它没有告诉我们任何关于语义的信息。
把这类失败当作「编译执行抛异常而 eager 正常」上报，会给**每一个**用例都造出一条假候选。
`is_infra_failure()` 识别这类情况，把该层整个排除出比较，并在 `layers_unavailable` 里记录，
这样覆盖面的损失是显式的。

---

## 加自己的用例

```python
from tcd.case import Case, Context, register

def my_fn(x):
    y = x.view(-1)
    y[0] += 1.0
    return x

def my_inputs(ctx):
    import torch
    return (torch.randn(8, 8, dtype=getattr(torch, ctx.get("dtype"))),)

register(Case(
    name="my_case",
    fn=my_fn,
    make_inputs=my_inputs,
    contexts=[Context("fp32", {"dtype": "float32"}),
              Context("fp16", {"dtype": "float16"})],
    tags=["alias", "mutation"],
))
```

**必须遵守的一条约定：`make_inputs` 每次调用都要返回新分配的张量。**
mutation oracle 比较的是调用后调用方的输入状态；复用同一个张量会让第二次执行看到第一次的原地写，
报出一个根本不存在的分歧。

上下文的构造原则：**任意两个上下文之间只差一个因子**。`context_pairs()` 只生成单因子对，
这正是分歧可归因的前提。

---

## 静态分析（Phase 1）

```bash
python run.py analyze --tag alias
python run.py analyze --cases overlapping_views --json analysis/
```

纯 AST，不依赖 torch，不做符号执行。它**不判定缺陷**，只导出「编译器必须保持的结构性事实」，
每条 FACT 对应一个测试义务和一条 oracle 断言：

| FACT 种类 | 含义 | 交给哪个 oracle |
|---|---|---|
| `mutation_visible` | 写穿别名，调用方的参数必须改变 | O2 mutation |
| `partial_write` | 只写了一部分，其余元素必须逐位保留 | O2 mutation |
| `write_order` | 两次写同一 storage，顺序必须保持 | O2 mutation |
| `alias_returned` | 返回值与参数共享 storage，编译版必须返回别名而非拷贝 | O3 alias |

同时导出语义因子（`x.shape` / `x.dtype` / `x.stride()` …，并标出哪些出现在分支条件里）
与边界取值（`x.shape[0] >= 32` → `[31,32,33]`；`n % 16 == 0` → `[15,16,17,31,32,33]`），
以及**这个函数适用哪些结构变异算子**。

这就是方法相对现有工作的差异点所在：结构不是猜出来的，是从程序里读出来的。

## 还没做的

- **结构变异算子尚未实现**：`analyze` 目前只报告哪些算子*适用*，还不会真的生成结构变体。这是下一步。
- 最小化未接官方 minifier（`TORCHDYNAMO_REPRO_AFTER=dynamo|aot`），目前只输出用例源码。
- LLM 分诊未接入；当前排序完全靠分层二分的优先级。
- 未接 GitHub issue 检索查重，`_dedup.json` 只在本地失败库内去重。
- 无 GPU，Triton / CUDA / vLLM / TileLang 路径未覆盖。
