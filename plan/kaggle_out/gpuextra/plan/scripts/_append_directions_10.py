"""One-off: append section 10 (round-6 angles, 2026-09-21) to NEXT_DIRECTIONS.md."""
import os

p = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "NEXT_DIRECTIONS.md")
s = open(p, encoding="utf-8").read()
MARK = "## 10. 第六轮角度（2026-09-21）"
TEXT = MARK + r"""——从"这两天什么最出货"反推

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
"""
if MARK not in s:
    open(p, "w", encoding="utf-8").write(s.rstrip("\n") + "\n\n" + TEXT)
    print("appended")
else:
    print("already there")
