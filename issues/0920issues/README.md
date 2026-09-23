# 0920issues —— 第四/五轮（2026-09-20）新发现的提交稿

格式与 `0913issues/` 相同：每个文件顶部的表格是提交信息（**不要复制到 issue 里**），`## Title` 是标题，`## Body` / `## Comment` 以下原样粘贴。
**未经你明确指示我不会提交任何一条**；都由你在网页上手工提交。

| # | 仓库 | 类型 | 一句话 | 优先级 | 状态 |
|---|---|---|---|---|---|
| 01 | pytorch/pytorch | 新 issue | Inductor 下 autograd 的"反向需要的张量被原地修改"检查丢失：`x @ w`、`bmm`、`einsum`、3 维 `F.linear` 等在前向后改了输入，`backward()` **静默返回错误梯度**（eager / aot_eager 报错） | **高**（静默错梯度；Win/Linux、CPU/CUDA、2.14/nightly 全部复现；根因已用 `_version` 实测证实） | **已提交 #197887**（2026-09-21）https://github.com/pytorch/pytorch/issues/197887 |
| 02 | pytorch/pytorch | 新 issue | **`adaptive_max_pool3d` 对 channels_last_3d 输入在 Inductor 下梯度错**；根因在 eager 的 C++ 内核：`adaptive_max_pool3d_backward`、`fractional_max_pool{2,3}d_backward` 把非连续的 `indices` 当连续内存读（不需要编译器也能复现）；Inductor 把存给反向的 indices 排成 channels_last 才触发 | **高**（静默错梯度；修法一行 `.contiguous()`） | **已提交 #197888**（2026-09-21）https://github.com/pytorch/pytorch/issues/197888 |
| 02b | pytorch/pytorch | 新 issue | **变化的 Python float 实参被烤进缓存图（#194976 的残留）**：`f(x, s)` 里 `s` 既有 `x * s` 这样的用法、它的表达式又传给算子的浮点形参时，默认配置的 torch.compile 从第三个取值起一直沿用第二个取值算出的参数；nightly 上 51 个算子里 18 个中招：rms/layer/group/batch/instance_norm 的 eps、batch_norm momentum、huber delta、smooth_l1 beta、label_smoothing、triplet margin、cdist/pairwise p、quantile q、SDPA scale、**`interpolate(scale_factor=…)` 连输出形状都是旧的**；2.14.0 与 nightly 0921、Win/Linux、CPU/CUDA 全复现；关掉 FX 图缓存或 AOTAutograd 缓存任一个即正确；根因已用日志钉死（fake-tensor 传播时特化 → ShapeEnv 守卫被缓存键丢弃） | **高**（默认配置静默错值/错形状） | **已提交 #197889**（2026-09-21）https://github.com/pytorch/pytorch/issues/197889 |
| 03 | pytorch/pytorch | **评论**（#143649） | **整数 `torch.div(a, b, rounding_mode="trunc")` 除零让进程直接崩溃**（Windows `0xC0000094`，Linux SIGFPE），`try/except` 接不住；原 issue 点名的 floor_divide / remainder / fmod 在 2.14 已有保护，漏了 truncdiv；根因 `CppOverrides.truncdiv` / `CppVecOverrides.truncdiv` 仍是裸 `a / b`；所有整数 dtype、向量主体与尾部都中；2.14 + nightly，Win + Linux | **高**（进程崩溃） | **已评论 #143649**（2026-09-21）https://github.com/pytorch/pytorch/issues/143649#issuecomment-5761796627 |
| 04 | pytorch/pytorch | **评论**（在 #197554 下） | 维护者 9 月 18 日开的总括 issue "[PT2] Validation lost" 点名要"把 OpInfo error_inputs 过编译路径的系统扫描"——我们的工具就是；评论里给方法 + 10 个新成员 | 高（命中维护者正在找的东西；成员表里已有你的 #197095） | **已评论 #197554**（2026-09-21）https://github.com/pytorch/pytorch/issues/197554#issuecomment-5761854781 |
| 05 | **Microsoft Visual C++**（Developer Community，非 GitHub） | 新反馈 | **MSVC 19.44 `/O1`、`/O2` 把连续两次 `_mm*_abs_epi8/16/32` 整个消掉：`abs(abs(x))` 返回 `x`**（一次、三次都对，`/Od` 对）；128/256/512 位都中；独立 C++ 复现 + 汇编；是通过 Inductor 在 Windows 上 `x.abs().abs()`（int8/16/32）返回负数发现的——**PyTorch 之下一层（C++ 编译器）的缺陷** | 高（编译器误编译） | **已提交**（2026-09-21）https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-folds-two-consecutive/11155532 |
| 06 | numba/numba | 新 issue | `np.remainder` / `np.mod` / `np.divmod` 在 `MIN_INT % -1` 上**杀死进程**（NumPy 返回 0）；`np.floor_divide(MIN_INT, -1)` 得 0；根因在 `np_int_srem_impl` 少一个判断 | 高（硬崩溃） | **已提交 #10845**（2026-09-21）https://github.com/numba/numba/issues/10845 |
| 07 | pytorch/pytorch | 新 issue | **`x / 1.0`、`buf * 1.0`、`x + 0` 作为图输出时，Inductor 直接把输入张量本身返回（`out is x`）**；调用方对结果做原地更新就会改坏输入；只在超参数取"中性值"时触发（`temperature=1.0`、`momentum=1.0`、`bias=0`），0.9 就正常；`requires_grad` 时不是同一对象但共享存储；根因：`joint_graph.remove_no_ops` 缺少 `post_grad.remove_noop_ops` 里那条"不得在输入与输出之间引入新别名"的检查 | 中–高（静默改坏输入；修法几行） | **已提交 #197893**（2026-09-21）https://github.com/pytorch/pytorch/issues/197893 |
| 08 | pytorch/pytorch | 新 issue | **torch.fx 代码生成的优先级错误：`operator.pow(-2, x)` 生成 `-2 ** x`（= `-(2**x)`）**，`GraphModule.forward` 符号错而 `Interpreter` 对；`torch.compile(dynamic=True)` 下 `x * (-1) ** x.shape[0]` 在 eager/aot_eager 后端对所有长度都返回 `-x`；`symbolic_trace` 同错；根因 `fx/graph.py` 用 `"{} ** {}".format(repr(...))` | **中–高**（静默错值；修法一行） | **已提交 #197894**（2026-09-21）https://github.com/pytorch/pytorch/issues/197894 |
| 09 | pytorch/pytorch | 新 issue | 浮点 `//`：`torch.compile` 让 `1.0 // 0.1` 得 **10**（eager 与 Python 得 9）；float32/float64 都是；根因 `_floor_div_floating = floor(div_rn(a,b))` | 中–高（静默错值，教科书例子，标题很醒目） | **已提交 #197895**（2026-09-21）https://github.com/pytorch/pytorch/issues/197895 |
| 10 | pytorch/pytorch | 新 issue | **Dynamo 静默丢副作用**：在被编译函数里新建一个"定义在外层函数里的类"的对象并调用方法，方法对闭包 list/dict 的修改（append / extend / `d[k]=v` / `d[k]+=1`）全部丢失；`fullgraph=True` 不报错、无 graph break；本地定义的上下文管理器的 `__enter__/__exit__` 记账也因此丢失 | 中–高（静默；2.14 + nightly；触发条件已隔离成三条） | **已提交 #197896**（2026-09-21）https://github.com/pytorch/pytorch/issues/197896 |
| 11 | jax-ml/jax | 新 issue | `jnp.gcd` / `jnp.lcm` 遇到整型最小值**永不返回**（eager 与 jit 都是）；根因与修复已给 | 中–高 | **已提交 #40840**（2026-09-21）https://github.com/jax-ml/jax/issues/40840 |
| 12 | pytorch/pytorch | 新 issue | 编译 NumPy 代码得到错误数值：`np.fix(1.5)=2.0`、`np.cbrt(-8)=nan`、`np.clip(int8, -1000, 1000)` 全为 -24、`np.sign(nan)=0` | 中–高（静默错值；根因都是一行） | **已提交 #198052**（2026-09-22）https://github.com/pytorch/pytorch/issues/198052 |
| 13 | pytorch/pytorch | 新 issue | CPU 向量化 `remainder` / `%`：除数 ±inf 得 nan、`1e20 % 3` 得 0；长度 3 正确、长度 ≥8 错（同一元素的结果取决于张量长度）；根因 `CppVecOverrides.remainder` | 中–高 | **已提交 #198057**（2026-09-22）https://github.com/pytorch/pytorch/issues/198057 |
| 14 | pytorch/pytorch | **评论**（在 #191499 下） | int8/uint8 的 `min/max/argmin/argmax` 在 ≥16 个元素时错（补 0 的向量通道参与归约）：原 issue 只报了 Apple Silicon 的 `amin` 得 0；我们补 x86-64 同样、全负 int8 的 `max` 得 0、**`argmin/argmax` 返回 -1** | 中–高 | **已评论 #191499**（2026-09-22）https://github.com/pytorch/pytorch/issues/191499#issuecomment-5769459765 |
| 15 | pytorch/pytorch | 新 issue | **`round(x.shape[0], -1)` 在 SymInt 上是恒等**（`SymInt.__round__` 直接 `return self`，忽略负的 ndigits）；round 从图里消失，三个后端一致地错（`round(25,-1)` 得 25 而不是 20） | 中（静默错值） | **已提交 #198064**（2026-09-22）https://github.com/pytorch/pytorch/issues/198064 |
| 16 | pytorch/pytorch | 新 issue | **`capture_scalar_outputs=True` 下 `v = loss.item()` 的 NaN 自比较在追踪期被折成常量**：`if v != v:`（跳过 NaN 步）在三个后端都走错分支；`v - v`、`v * 0` 对 NaN/inf 得 0；`max(v, 0.0)` 对 NaN 得 0；`math.isnan(v)` 正确。与 #158087 不同（那条是异常对等） | 中（非默认开关，但 #157499 想把它改成默认） | **已提交 #198070**（2026-09-22）https://github.com/pytorch/pytorch/issues/198070 |
| 17 | **Microsoft Visual C++** | 新反馈 | **MSVC 把向量 `_mm*_add_p{s,d}(x, 0.0)` 整个消掉，`-0.0 + 0.0` 得 `-0.0`（应为 `+0.0`）；`/fp:strict` 下也一样**，而标量 `x + 0.0f` 是对的（保留 `addss`）；128/256/512 位、ps/pd、零在左或右、`setzero` 或 `set1(0)` 都中 | 中（违反 /fp:strict；只影响零的符号） | **已提交**（2026-09-21）https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-removes-_mm_add_psx/11155535 |
| 18 | **Microsoft Visual C++** | 新反馈 | **MSVC 把"谓词带等号"的比较+混合选择（`blendv(x, y, cmp(x, y, LE_OS / GE_OS / NLE_US))`，以及 AVX-512 的 `mask_blend(cmp_mask(...))`）折叠成 `maxps`/`minps`，±0 平局时选错操作数**；`<`/`>`/`EQ`/`NEQ`/`UNORD` 形式与全部整数选择是对的；`LE`/`GE` 需 `/arch:AVX2`（VEX 编码）才触发，`NLE_US` 在普通 `/O2` 下就错，256/512 位只要开优化就错；`/fp:strict` 下也一样；差分里约 2,500 个函数全部归到这一条；已确认在 Inductor 上不表现 | 中（违反 /fp:strict；只影响零的符号） | **已提交**（2026-09-21）https://developercommunity.visualstudio.com/t/MSVC-x64-optimizer-folds-compare-and-ble/11155537 |
| 19 | pytorch/pytorch | 新 issue | 编译 NumPy 代码的 dtype / 形状规则不同：`np.cumsum(int8)` 不提升而溢出、`np.square(int8)`→float64、`np.median` 形状 (1,)、`np.any`→uint8、uint16/32/64 直接报错 | 中 | **已提交 #198056**（2026-09-22）https://github.com/pytorch/pytorch/issues/198056 |
| 20 | pytorch/pytorch | **评论**（在 #185337 下，请求 reopen） | 显式 `x.half().float()` 往返被 Inductor 消掉（连 `70000→inf` 都没了）；该 issue 6 月以 completed 关闭，但 2.14 与 nightly 上用更简单的复现仍在 | 中 | **已评论 #185337**（2026-09-22）https://github.com/pytorch/pytorch/issues/185337#issuecomment-5769623200 |
| 21 | pytorch/pytorch | 新 issue | `torch.clamp(int8, -1000, 1000)` 在 Inductor 下全变 -24（边界被绕回成 int8）；nightly 的 eager 已返回原张量，2.14 的 eager 报错 | 中 | **已提交 #198071**（2026-09-22）https://github.com/pytorch/pytorch/issues/198071 |
| 22 | pytorch/pytorch | **评论**（#197554，第二条） | Inductor 下丢失的保护（2026-09-22 调整为 3 项：原“确定性模式下 `empty*` 不填充”已有 #174386，拆到 24 号）：① InferenceMode 外对 inference tensor 做原地修改不再报错（真的改了调用方张量）；② 确定性模式下 `put_`（重复下标）不再报错；③ 确定性模式的 `fill_uninitialized_memory` 对 `empty*` 不生效。④（后补）`F.pad` 负填充裁掉的比输入还多时 eager 报错、Inductor 静默返回全填充值。`aot_eager` 都与 eager 一致；前三项 CPU + CUDA | 中–低 | **已评论 #197554**（2026-09-22）https://github.com/pytorch/pytorch/issues/197554#issuecomment-5769650186 |
| 23 | pytorch/pytorch | 新 issue | **torch.fx：名为 `nan` / `inf` 的 `forward` 形参遮蔽生成源码里同名的浮点常量**：`symbolic_trace` 后 `torch.where(nan, float("nan"), x)` 得 `[1, 1, 3]` 而不是 `[1, nan, 3]`，`clamp(max=float("inf"))` 的上限变成了名叫 `inf` 的张量；`Interpreter` 正确；与已提交的 #197894 同属“生成源码 ≠ Interpreter 语义”，根因不同（custom builtin 名字只对节点改名、不对形参） | 中–低（静默错值，触发面窄） | **已提交 #198072**（2026-09-22）https://github.com/pytorch/pytorch/issues/198072 |
| 24 | pytorch/pytorch | **评论**（#174386，已关闭为 completed） | 确定性模式下 `empty` / `empty_like` / `new_empty` 在 Inductor **CPU** 上仍不按文档填充 NaN / 最大整数（原 issue 的复现程序原样失败，2.14.0 + nightly，Win + Linux；CUDA 上浮点已修、整数仍不填）；请求 reopen | 中–低 | **已评论 #174386**（2026-09-22）https://github.com/pytorch/pytorch/issues/174386#issuecomment-5769669193 |
| 25 | pytorch/pytorch | **评论**（自己的 #197889） | #197889 同一根因的第二类入口：由 float 派生的**整数**实参（`cumsum` 的 dim、`round` 的 decimals、`linspace` 步数、`one_hot` 类数、`adaptive_avg_pool1d` 输出尺寸、`unfold` 窗口）同样沿用旧值——`cumsum` 沿错误维度累加而形状不变；2.14 + nightly；关任一缓存即正确；普查 v2 里接受 SymInt 的位置与按值分支的分解都正常（负结果） | 中（补充信息，帮助修复覆盖全） | **已评论 #197889**（2026-09-22）https://github.com/pytorch/pytorch/issues/197889#issuecomment-5769751990 |

**编号即提交顺序（2026-09-21 按优先级从高到低重排，从 01 开始往下提交即可；之后新发现的高优先级稿用字母后缀插队，如 `02b` 排在 02 与 03 之间）。** 三个依赖已体现在编号里：04（#197554 评论）最后一句要填 01 提交后得到的 issue 号；22（#197554 第二条评论）排在 04 之后；05–17–18 是微软 Developer Community 的三张单（不是 GitHub，需微软账号，17 和 18 优先级低于 05 所以排在后面）。

旧编号 → 新编号：01→01、02→12、03→19、04→04、05→11、06→06、07→14、08→09、09→13、10→20、11→21、12→10、14→02、15→07、16→05、17→17、18→18、19→03、20→22、21→08、22→15、23→16（旧 13 已删除：他人已报 #197434）。`plan/` 下的台账、执行报告、记忆里 2026-09-21 之前的条目用的是旧编号。
09、13、14、20、21 已在 Linux CPU（2.14.0 与 nightly 2.15.0.dev20260920）和 T4 CUDA 上复核（`plan/kaggle_out/intublinux.log`、`intubgpu.log`），结果已写进各草稿：09、20、21 在 CPU 与 CUDA 上逐字相同；14、13 是 CPU 专属，且不同 CPU 上错法不同（14 在一台机器上 `argmin` 返回未初始化的大负数；13 在一台机器上 3 个元素也得 nan）。

## 评论稿怎么提交（03、04、14、20、22、24、25、27、29、30、32、37、38）

这五份不是“别人已经把同一个 bug 报过了”，而是 GitHub 上已有一个与之同根因 / 专门收集这类问题的 issue，新开一条大概率被标成 duplicate，所以把我们的新信息作为**评论**发到那条 issue 下面。每份稿子顶部表格里都有 **提交网址**（带 `#new_comment_field`，打开即跳到评论框）和 **怎么提交** 两行。通用步骤：

1. 登录 GitHub，打开稿子里的提交网址；页面最底部是 “Add a comment” 评论框。
2. 在 **Write** 页签里粘贴稿子中 `## Comment` 标题**下面**到文件末尾的全部内容（不含 `## Comment` 这一行，不含顶部的中文表格）。
3. 点 **Preview** 检查渲染，再点绿色 **Comment**。评论没有标题 / 标签 / 模板字段，别的都不用填。
4. 点评论右上角的时间戳拿到 `…#issuecomment-…` 链接，记到下表“状态”列。

| 稿 | 发到哪条 issue | 那条 issue 的状态（2026-09-21） | 特别注意 |
|---|---|---|---|
| 03 | https://github.com/pytorch/pytorch/issues/143649 | open，未锁定 | 无 |
| 04 | https://github.com/pytorch/pytorch/issues/197554 | open，未锁定，0 条评论 | 先把最后一句的 `#<fill in after filing 01>` 换成 01 的 issue 号 |
| 14 | https://github.com/pytorch/pytorch/issues/191499 | open，未锁定 | 无 |
| 20 | https://github.com/pytorch/pytorch/issues/185337 | closed（completed），未锁定，仍可评论 | 你没有 Reopen 按钮，稿子末尾已请维护者 reopen |
| 22 | https://github.com/pytorch/pytorch/issues/197554 | 同 04 | 在 04 之后单独发一条，不要与 04 合并 |
| 24 | https://github.com/pytorch/pytorch/issues/174386 | closed（completed），未锁定，仍可评论 | 没有 Reopen 按钮，稿子末尾已请维护者 reopen |
| 25 | https://github.com/pytorch/pytorch/issues/197889 | open（你自己的 issue） | 补充评论，随时可发 |
| 26 | pytorch/pytorch | 新 issue | **torch.fx：`GraphModule` 经 `pickle` / `torch.save` 往返后语义静默改变**：`operator.iadd / imul / …` 原地节点回来变成非原地（输入不再被修改；int64 `imul 2.5` 不再报错而返回 float 张量）；Dynamo 捕获的 `buf += g` 图 pickle 后缓冲区停在全 0；`copy.deepcopy` 正确；根因 `_deserialize_graph_module` 对生成的 `forward` 源码**重新符号追踪**，`Proxy` 无 `__iadd__` 系方法；2.14 + nightly | 中 | **已提交 #198077**（2026-09-22）https://github.com/pytorch/pytorch/issues/198077 |
| 27 | pytorch/pytorch | **评论**（#183607，open） | CPU/CUDA float16 融合链中间量不按 float16 舍入：输入本身是 float16（无需显式 cast）时 `y=x*x` 返回 inf 而同一调用返回的 `isinf(y)` 是 False、`y/x` 是 300；`emulate_precision_casts=True` 在 CPU 与 T4 上都修好（原 issue 机器人说无效）；Win/Linux/T4 × 2.14/nightly 六组逐字相同 | 中–低 | **已评论 #183607**（2026-09-22）https://github.com/pytorch/pytorch/issues/183607#issuecomment-5769757314 |
| 28 | pytorch/pytorch | 新 issue | **Inductor 下 `torch.any(uint8)` 返回 bool 而不是 uint8**（eager / aot_eager / `torch.all` 都保留 uint8）；下游算术随之变值（`any(x)*200+100`：eager 44，编译 300 int64）；根因 `lowering.py::reduce_any` 绕过了保留 uint8 的 `_refs.any` 分解，而 `aten.all` 走分解——成对实现不对称；2.14 + nightly，Win + Linux | 中 | **已提交 #198081**（2026-09-22）https://github.com/pytorch/pytorch/issues/198081 |
| 29 | pytorch/pytorch | **评论**（#197554，第三条） | "该 dtype 在 eager 里未实现"一族：`round(int8/uint8, decimals=k)` Inductor 返回 **float32**、`ceil/floor/round(bool)`、`F.glu(int8)`（float32）、`adaptive_max_pool2d(int8)` 都在 eager 抛 NotImplementedError 而 Inductor 照算；`bool - 1` 已有 #195674、upsample 已有 #193811 故不列；2.14 + nightly | 中–低 | **已评论 #197554**（2026-09-22）https://github.com/pytorch/pytorch/issues/197554#issuecomment-5770289099 |
| 30 | pytorch/pytorch | **评论**（自己的 #198071） | `F.pad(uint8, value=-1)` → 255、`F.pad(int8, value=300)` → 44：填充值与 clamp 边界同样回绕，eager 抛 `value cannot be converted … without overflow`；建议在 `ops.constant` 转换处统一检查 | 低–中 | **已评论 #198071**（2026-09-22）https://github.com/pytorch/pytorch/issues/198071#issuecomment-5770296071 |
| 31 | pytorch/pytorch | 新 issue | **复数 `linalg.pinv` / `polar` / `matrix_sqrth` 在任何 TorchDispatchMode 下返回错值**（只做转发的 mode 也一样），因此在 torch.compile 下错（运行时的 `_AnalyzeCustomOpInputOutputMode`）：内核内部 `.mH()` 的惰性共轭没被应用，pinv 恰等于 `vh.mT @ S⁻¹ @ u.mH`；`A@pinv@A≠A`、`U@P≠A`；排除 Conjugate 键可复现；是 #197084 的真正根因；2.14 + nightly，Win/Linux；T4 上 polar 同错、pinv 正确 | **高** | **已提交 #198118**（2026-09-22）https://github.com/pytorch/pytorch/issues/198118 |
| 32 | pytorch/pytorch | **评论**（自己的 #197084） | 更正归因：梯度错源于前向 pinv 值错（转发 mode 下的 eager 梯度与 compile 梯度逐位相同；只前向在 mode 下也错），不是 AOTAutograd 反向公式；指向 31 号 issue；提交时把 `#NNNNNN` 换成 31 的编号 | 高 | **已评论 #197084**（2026-09-22）https://github.com/pytorch/pytorch/issues/197084#issuecomment-5770677350 |
| 33 | pytorch/pytorch | 新 issue | **Inductor `avg_pool1d/2d` 反向在 `ceil_mode=True` 时对越界的最后一个窗口用整核大小做除数**（eager / aot_eager 用裁到含 padding 输入的窗口大小）：`avg_pool1d(x, 3, stride=2, ceil_mode=True)` 最后两个元素梯度 eager 0.833/0.5 vs Inductor 0.667/0.333；前向一致；`count_include_pad=False` 与 3-D（fallback）正确；GoogLeNet 式 `AvgPool2d(3, 2, ceil_mode=True)` 受影响；2.14 + nightly，CPU + T4 | **高** | **已提交 #198119**（2026-09-22）https://github.com/pytorch/pytorch/issues/198119 |
| 34 | pytorch/pytorch | 新 issue | **Inductor CPU `erfinv` 在 ±1 附近精度只有 3～4 位**（MSVC 下 f32 相对误差 7.5e-3、f64 3.6e-3；gcc 下 7.8e-6 / 6.2e-5；eager 与 mpmath 一致；CUDA 正确）：C++ 后端调 ATen 旧 `calc_erfinv`（两步牛顿，`erf(x)-y` 相消）；标量与向量路径都错；2.14 + nightly | 中 | **已提交 #198133**（2026-09-22）https://github.com/pytorch/pytorch/issues/198133 |
| 35 | pytorch/pytorch | 新 issue | **Inductor CPU 向量路径 float64 `acosh` 在 x > 1.34e154 溢出为 inf**（`Vectorized<double>::acosh` = SLEEF 的 `log(x+sqrt(x²-1))`）；标量尾部、eager、float32、CUDA 都有限；#152299 asinh 修法的 float64 同类；2.14 + nightly，Win + Linux | 中–低 | **已提交 #198134**（2026-09-22）https://github.com/pytorch/pytorch/issues/198134 |
| 36 | pytorch/pytorch | 新 issue | **Inductor 在 eager 内核未实现的 dtype 上照算：134 个算子 / 418 个 (算子, dtype) 组合的穷举清单**（bool 卷积/argmax/round、int softmax/损失/池化/var、float 位运算给出无意义值、half 特殊函数、complex 归一化/损失；`one_hot` 接受 float 下标）；Linux 全扫 + Windows 41 例复核（33 静默）；给出通用修法（lowering 前查 eager 内核 dtype 覆盖）；是 29 号评论那一族的完整版，链接伞形 #197554 | 中 | **已提交 #198155**（2026-09-22）https://github.com/pytorch/pytorch/issues/198155 |
| 37 | pytorch/pytorch | **评论**（自己的 #198155） | 同一族在 T4/Triton 上：383 对静默（310 与 CPU 相同，73 CUDA 专属：整数 matmul/mv/dot/tensordot、整数 max_pool、batch_norm 整数/复数——CUDA eager 没有整数 GEMM 而 Triton 模板照算）；96 对只在 CPU 上（half 特殊函数、整数 avg_pool） | 低–中 | **已评论 #198155**（2026-09-22）https://github.com/pytorch/pytorch/issues/198155#issuecomment-5773214257 |
| 38 | pytorch/pytorch | **评论**（自己的 #198118） | 同一机制也打到 `linalg.lstsq` 的 C++ 反向（前向在 mode 下对、梯度差 173）；PyTorch 自带的 `FlopCounterMode` 就能触发（pinv 前向差 1.29）——与 torch.compile 无关，任何在 mode 下剖析复数模型的训练都中；955 个可求导对里只有 pinv/matrix_sqrth/lstsq 的复数梯度变 | 中 | **已评论 #198118**（2026-09-22）https://github.com/pytorch/pytorch/issues/198118#issuecomment-5773243640 |
| 39 | pytorch/pytorch | 新 issue | **Inductor CPU 向量路径 float32 `erf` 在 0 附近失去全部相对精度**：n ≥ 8 时 |x| ≤ 1e-7 直接得 0、1e-5 处相对误差 1.7e-2（`Vectorized<float>::erf()` = Abramowitz–Stegun 7.1.26，误差界 1.5e-7 是绝对的；eager 用 `std::erf`）；向量 `atanh` 对 |x| < eps/2 得 0（f32/f64）；Windows AVX-512 + Linux AVX2、2.14 + nightly 均复现；修法：小 |x| 用泰勒/SLEEF，atanh 用 `log1p` | 中 | **已提交 #198183**（2026-09-22）https://github.com/pytorch/pytorch/issues/198183 |
| 40 | pytorch/pytorch | 新 issue | **Dynamo 丢掉入参 / 对象属性 `OrderedDict` 上的 `move_to_end()`**：重排序被记为 mutation 但不设 `should_reconstruct_all`，回放器看到"无新条目"就什么都不生成（即便生成也是不 clear 的 `update`，保留旧位置）；LRU 缓存命中丢失 → 下次插入淘汰刚用过的条目；`fullgraph=True` 不报；其它 dict/deque/list/set 变更都正确；2.14 + nightly；一行修法 | **高**（静默、常见模式 LRU、纯 Dynamo） | **已提交 #198189**（2026-09-22）https://github.com/pytorch/pytorch/issues/198189 |
| 41 | pytorch/pytorch | 新 issue | **逃出编译区的生成器（返回、或跨 graph break 存活）被重建为已耗尽的 `tuple_iterator`**：`StopIteration.value` 静默变 None，`.send()` / `.throw()` 抛 AttributeError，`type()` 变；`LocalGeneratorObjectVariable.reconstruct` 追踪期跑完生成器再造 `ListIteratorVariable`；faithful 开关无效；2.14 + nightly；建议 graph break 或重建成会 `return rv` 的真生成器 | 中 | **已提交 #198190**（2026-09-22）https://github.com/pytorch/pytorch/issues/198190 |
| 41b | pytorch/pytorch | **评论**（自己的 #198190） | 补充：触发条件 = 生成器体内有张量运算（`yield x` / `yield 1` 的生成器重建正确）；同一重建路径也把生成器表达式 / enumerate / reversed / islice / tee / 部分消费的 list 迭代器 / `Module.children()` 变成 `tuple_iterator`，其余 ~40 种对象正确 | 中 | **已评论 #198190**（2026-09-22）https://github.com/pytorch/pytorch/issues/198190#issuecomment-5776320367 |
| 42 | pytorch/pytorch | 新 issue | **张量算子抛出的 `IndexError` 在编译函数内跳过用户自己的 `except IndexError`**，直接逃出编译调用（`x[i]` / `select` / `sum(dim)` / `softmax(dim)` / `transpose` / `unsqueeze` / `squeeze` / `flatten` / `chunk` / `index_select`）；`RuntimeError` 族自 PR #184990 起能进 handler；`fullgraph=True` 不报、假时也不回退；根因 `run_node` 的 `except IndexError: raise`（#184340 的修法）绕过了 `get_fake_value` 的 observed-exception 分支；是 #184340 修复后剩下的"函数内"一半 | **高**（防御性回退静默失效；纯 Dynamo） | **已提交 #198192**（2026-09-22）https://github.com/pytorch/pytorch/issues/198192 |
| 43 | pytorch/pytorch | 新 issue | **Windows 上 AOTI runner 在一次推理后立刻销毁 → 进程访问违例**（`0xC0000005`），只要模型有 OpenMP 并行内核（输出 ≥ 4096 元素 = `cpp.min_chunk_size`）；`x + 1` 即可复现；sleep 2 s / `OMP_NUM_THREADS=1` / `cpp.threads=1` 都能避免 → 模型 DLL 在 OpenMP 工作线程仍自旋时被 `FreeLibrary`；2.14 + nightly | **高**（进程崩溃，Windows AOTI 基本用法） | **已提交 #198205**（2026-09-22）https://github.com/pytorch/pytorch/issues/198205 |
| 42b | pytorch/pytorch | **评论**（自己的 #198192） | 补充：被跳过的不只是 `except IndexError`——`except Exception` / `LookupError`、`contextlib.suppress`、`__exit__` 吞异常、finally 顺序、嵌套调用、循环 / 推导式 / 生成器里的 handler 全部跳过；`NotImplementedError` 同样；TypeError / ZeroDivisionError / assert / `_check` / `except*` 正常 | 中 | **已评论 #198192**（2026-09-22）https://github.com/pytorch/pytorch/issues/198192#issuecomment-5778031868 |

## 这一轮查重后**不报**的

| 发现 | 结论 |
|---|---|
| `index_select` 负索引被 Inductor 接受 | 重复：pytorch #169779（open） |
| `index_add` 负索引被 Inductor 接受 | 重复：pytorch #185885（open，#197554 成员） |
| eager `torch.div(INT_MIN, -1, rounding_mode='trunc')` 进程崩溃 | 重复：pytorch #138425（open） |
| eager `torch.lcm(INT32_MIN, 13)` 进程崩溃；`torch.gcd` 对 INT_MIN 返回负数 | 重复：pytorch #121343、#187338（open） |
| Inductor 越界时抛 RuntimeError 而 eager 抛 IndexError（21 例） | 设计如此（运行期断言），不报 |
| Numba：`np.fmod` 整数结果错 / `np.median` 含 NaN / `np.clip` NaN 边界 | 重复：numba #8574 / #10095 / #9995（open） |
| Numba：标量整数提升为 int64、无越界检查、除零抛 ZeroDivisionError、float16 不支持、NEP 50 标量规则 | 官方文档列出的偏离，不是缺陷 |
| JAX：`logaddexp2(-1,-1)` 差 1e-8、`denormal ** 0.5` 为 0 | jit 与非 jit 的浮点融合差异，量级在容差边缘，不报 |
| `maximum(0.0, -0.0)` 等有符号零差异（Inductor / Numba / torch._numpy 都有） | pytorch 已有 open #188680 专门讨论"测试对有符号零不敏感"；等 `int_ub_sweep` 全量跑完再统一整理 |
| eager `x ** -0.5` 对 `-0.0` 得 `-inf`、对 `-inf` 得 `nan`（编译后是 `inf` / `0`，与 C `pow` 和 NumPy 一致） | 偏离 IEEE `pow` 的是 **eager**（指数 -0.5 走 `rsqrt` 特化），编译结果反而对；价值低，未写稿 |
| `x + 0` 编译后不再把 `-0.0` 规整成 `+0.0` | 有符号零一类（open #188680）；已作为 07 号稿的一句附注 |
| `x.half().float()` 链、`cast_then_op` 被消掉 | 即 20 号评论稿（#185337），不重复报 |
| 前缀一致性（10.2）：`exp/expm1/exp2/sin/cos/tan/gelu/elu/selu/celu/softplus/hypot/xlogy` 向量主体与标量尾部差 1 ULP（gelu float32 约 8 ULP） | 向量数学库与标量 `std::` 函数的舍入差；没有对齐 / 线程数造成的差异；PyTorch 不承诺逐位一致，不报（负结果） |
| **2.14.0 上 `torch.add(e*d, p, alpha=1-d)`（EMA 更新）在 d 变化后用陈旧的 alpha，静默算错**（默认配置：FX 图缓存 + AOTAutograd 缓存都开才触发；Win/Linux/CUDA） | **已知且已在 nightly 修复**：#194976（2026-08-27 关闭）/ 修复 #195040 “Fix stale float specialization in tensorify_python_scalars”；2.14.0 发布版没带上这个修复。nightly 0911/0921 复核正确 → 不报（证据 `plan/reports_surgery/float_arg_cache_matrix.py`，可作论文里“工具重新发现已知缺陷”的例子） |
| 编译的 Adam/AdamW `step` 与 eager 每步差 ~1e-6（不改超参数也有） | 偏差修正项在编译路径里用 float32 张量算；精度级，不报。lr/betas/eps/wd 的步间修改都被正确感知（10.3 负结果：76 例中 69 例一致） |
| CUDA 确定性模式下 `avg_pool3d` / `reflection_pad1d` / `nll_loss2d` / `interpolate(bicubic, linear)` 的反向 eager 报错、编译后不报 | 编译后的实现本身是确定性的（gather 式 / 排序式），不报错合理，不算缺陷 |
| `std()` 单元素的 “degrees of freedom” 警告在编译后丢失 | 警告对等，价值低，不报 |
| SymInt/SymFloat 其它差异：`min(n, 2.5)` 返回 float 而不是 int；`round(v, 1)`、`v // 1` 丢 `-0.0` 的符号；`round(n/8, 1)` 得 0.6000000000000001；超过 int64 的大整数编译后 OverflowError；`v % 1` 对 inf 编译失败 | 类型/有符号零/大整数属已知限制或响亮失败，价值低，未写稿（记录在 `results/symint/cases.jsonl`） |
| g++ 11.4 / clang++ 14（Kaggle，104,332 个内建函数组合，-O0 对 -O1/2/3） | **0 个真实差异**：全部“值差异”来自 `x * -1.0 → -x` 改变 NaN 符号位后经按位运算 / 比较选择显形，IEEE 与两家编译器文档都允许（负结果；说明 05、17、18 是 MSVC 特有） |
| 大窗口 max_pool（核体积 >25）+ 空间维转置输入 → indices 错、梯度错（旧编号 13 的稿，已删） | **已被他人报告**：#197434（2026-09-17）+ 修复 PR #197596；用户 2026-09-21 指示删除该稿。复现脚本仍在 `plan/reports_layout/max_pool_indices_noncontiguous.py` |
| 2.14.0 上 float64 的 `v = x.item()` 经 `abs(v)` / `v ** 2` 后**既作为 Python 数返回、又喂给张量**时，Inductor 下被降成 float32 精度（0.1 → 0.10000000149） | nightly 2.15.0.dev20260911 上已正常（与 #194976/#195040 同属 `tensorify_python_scalars` 一族的已修缺陷）→ 不报。证据 `plan/reports_symint/item_float32_roundtrip_min2.py` |

## 工具（都在 `plan/` 下）

| 脚本 | 作用 |
|---|---|
| `scripts/error_parity_sweep.py` | OpInfo `error_inputs` + 手写非法输入，过三个后端；eager 抛而编译不抛 = SILENT |
| `scripts/error_parity_batch2.py` | 129 个"校验丢失"小程序（含"反向需要的张量被改"）；01 就是它发现的 |
| `scripts/int_ub_sweep.py` | 整数 / 转换 / IEEE 特殊值语义扫描（261 个用例，仍在跑） |
| `scripts/xtarget_numpy_diff.py` | **跨目标**：同一份 268 个 NumPy 风格程序 × {dynamo(torch._numpy), numba, jax} |
| `scripts/run_issue_snippet.py` | 把草稿里的 ```python 代码块原样跑一遍，核对草稿里引用的输出 |
| `reports_validation/*.py`、`reports_xtarget/*.py` | 每条草稿对应的独立复现脚本（逐用例独立进程） |
| `scripts/layout_alias_sweep.py` | 534 个算子 × 7 种布局/别名 × 前向+反向（`--shard i/n`）；02 的来源（同一扫描发现的另一条已被他人报告为 #197434，原稿已删） |
| `scripts/side_effect_diff.py` | 75 个副作用/状态小程序；10 的来源 |
| `scripts/rewrite_precondition_diff.py` | 183 个"代数改写前提"用例（-0.0 / NaN / 别名敏感）；07、05 的来源 |
| `scripts/prefix_consistency_sweep.py` | 同一输入的前缀、对齐、线程数下编译结果逐位一致性（负结果） |
| `reports_rewrites/msvc_abs/` | 16 的独立 C++ 复现、四档优化级别构建脚本、汇编打印、草稿 C++ 块逐字验证（`verify_draft16.py`） |
| `scripts/cxx_intrinsic_algebra_diff.py` | **C++ 工具链层**差分：109,754 个 SSE/AVX2/AVX-512 内建函数组合（U∘U、B(U,·)、B1(B2)、常量重结合、select 惯用法、洗牌、int↔float 往返），`/Od` 对 `/O1`/`/O2`/`/arch:AVX2`/`/arch:AVX512`（MSVC），`-O0` 对 `-O1/2/3`（g++/clang++，Kaggle `tcc-cxxalgebra`）；05、17、18 的来源 |
| `scripts/host_opt_diff.py` | 同一批程序让 Inductor 编两次，只差宿主编译器优化档（`TORCHINDUCTOR_DEBUG_COMPILE=1` → `/Od`），逐位比较；每个编译函数只放 4 个程序（大函数里 MSVC 不做 abs(abs) 折叠，批量大了会漏报——已验证小批量能重新发现 05 号） |
| `scripts/model_surgery_diff.py` | 10.3/10.4：76 个"编译后动模型"用例（冻结/解冻、改 dtype、换子模块、load_state_dict、共享权重、parametrize、BN/Dropout/LayerNorm 超参数、编译的 optimizer.step 步间改 lr/betas/wd、GradScaler、全局开关）＋ eager 保护机制（anomaly、deterministic、inference tensor、整数除零各形态） |
| `scripts/cxx_algebra_families.py` | 把差分结果按内建函数贪心分族（几千个差异 → 几族） |
| `scripts/run_issue_cpp_snippet.py` | 把草稿里的 ```cpp 代码块原样用 `cl` 在指定选项下编译运行（Git Bash 下要加 `MSYS_NO_PATHCONV=1`） |
| `scripts/symint_arith_diff.py` | 10.5：138 个 Python 标量表达式（SymInt 来自 shape、SymFloat/SymInt 来自 `.item()`）× 取值网格 × {eager, inductor} 后端，对照纯 Python 语义（类型+值+异常）；08、15、16 的来源 |
| `reports_surgery/*.py`、`reports_symint/*.py` | 03、22、08、15、16 的独立复现与隔离脚本（逐用例独立进程；含“哪一个缓存导致陈旧 alpha”的 2×2 矩阵） |
| `scripts/symshape_index_diff.py` | 10.5b：112 个“符号整数流进切片 / 下标 / roll / pad / repeat / split / view / arange / 池化参数”的程序 × 12 个长度（让派生整数跨过 0、长度、两倍长度）× 3 后端；111 个一致（负结果），1 个并入 22 号 |
| `scripts/scalar_arg_sequence_diff.py` | 10.9b：100 个程序，Python float / int 实参逐次变化（静态首调 → 自动动态重编译 → 重复值 → 0/1/负数），默认缓存 + 每例全新缓存目录，每次调用都与 eager 比；release 与 nightly 各跑一份（`results/scalar_seq/{release,nightly}.jsonl`）；02b 的来源 |
