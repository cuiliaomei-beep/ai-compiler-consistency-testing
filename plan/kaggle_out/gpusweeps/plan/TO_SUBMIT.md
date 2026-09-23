# 待提交清单（RQ5，计划 §18.6：人工审核后才提交）

> **2026-09-09 用户决定：第 1–5 条全部暂不提交，仅登记。** 未经用户明确指示不得提交任何 issue。第 6–10 条（2026-09-10）同样只登记。
> **2026-09-10 下午**：按 `0909ISSUEs` 的格式为第 1–10 条各写了一份可直接粘贴的 issue 草稿 → `issues_0910/`（README 有优先级与查重结论；`results/dedup_0910.md` 是系统查重记录）。expand(-1) 0 维一条与 open #70398 同根，改为评论稿。

| # | 发现 | 版本 | 状态 | 提交稿 | 查重 | 备注 |
|---|---|---|---|---|---|---|
| 1 | `torch.var_mean` / `torch.std_mean` 对空张量在 Inductor 下返回 `(nan, 0.)`，eager/aot_eager 为 `(nan, nan)`（mean 分量错误，inductor_codegen）；覆盖 correction=1/0、fp32/fp16、形状 (0,)/(0,1)、dynamic 开关 | torch 2.14.0+cpu | **待提交**（用户 2026-09-08 决定暂不提交） | `reports_opinfo_all/0211b330cc67/ISSUE_FINAL.md` | 非重复；相关 #113167（已关闭，不同情形）、#61901、#191229 | 已手工验证 `minimal_verified.py`；第 4 轮四个上下文 2/2，第 6 轮 std_mean/var_mean 共 5 个程序再次命中 |

提交时：把 `ISSUE_FINAL.md` 粘到 pytorch/pytorch 的 issue tracker，然后

```bash
python run.py campaign --status 0211b330cc67=Submitted --out reports_opinfo_all
```

之后在本表登记 issue 编号，并随开发者回复更新为 Confirmed / Fixed / Duplicate / Invalid。

| 2 | `torch.std / var / var_mean / std_mean` 对 1e30 量级 float32 输入，Inductor 全部返回 NaN；eager 的 `std` 为有限值 9.56e29 且等于 fp64 真值。**补充（2026-09-10，反向差分）**：对 1e-30 量级输入，编译后 `std` 前向返回 0、**梯度全 0**，eager/fp64 前向 1.44e-30、梯度为正确的 O(1) 值（0.318…）；correction=0、逐维同样。根因相同：Inductor 用 fp32 累加方差（平方偏差 1e-60 下溢），CPU eager 用 double | torch 2.14.0+cpu | **待提交**（分解差分发现，2026-09-09） | `reports_decomp/std_var_large_values/minimal_verified.py`、`minimal_verified_tiny_grad.py` | 开 issue #173793（LayerNorm、CUDA、1e37）同根因；#173989 只修了 LayerNorm CPU 路径 → 新实例 | 建议在 #173793 下评论附复现，或另开 issue 引用它；梯度归零是比 NaN 更隐蔽的后果（训练静默停滞），报告时以它为主 |
| 3 | `F.interpolate(torch.empty(2,3,0), size=3)`（空的空间维）：eager 抛 "Input and output sizes should be greater than 0"，aot_eager 抛 IndexError，**Inductor 返回 (2,3,3) 全 NaN**——生成的内核对 0 元素缓冲区越界读；linear / 2-D bilinear 同样；反向情形（W=1、scale 0.6 → 输出 0）compile 静默返回空张量 | torch 2.14.0+cpu | **待提交**（分解差分，2026-09-09） | `reports_decomp/interpolate_zero_size/minimal_verified.py` | 未见同报告；同族 #195550（adaptive_avg_pool2d 校验）、#144362（compile 缺校验）；#184848/#191850 不同 | 越界读在 CUDA 上可能是 IMA，值得单独报 |
| 4 | `torch.linalg.vector_norm(torch.empty(0,5), ord=inf, dim=-1)`（空 batch，被归约维非空）：eager 返回 shape (0,)，compile（eager/aot_eager/inductor 后端都在 Dynamo 追踪期）抛 "cannot compute the inf norm on the dimension -1 because this dimension is empty"；`dim=1` 正常、`dim=-1`/`(-1,)` 失败；ord=-inf / 负数同样，ord=2/0.5/0 正常 | torch 2.14.0+cpu | **待提交**（分解差分，2026-09-09；根因 2026-09-10 修正） | `reports_decomp/vector_norm_empty_batch/minimal_verified.py`、`issues_0910/04-*.md` | 未见同报告；#148809 改过同一检查但保留了未规范化的索引 | 根因：`_refs/linalg/__init__.py` 121 行 `sym_or(x.numel() != 0, d < len(shape) and d >= 0 and shape[d] != 0)` 对负 `d` 直接为假，没做 `d % ndim` |
| 6 | CPU Inductor `dynamic=True`：`(x + m).argmin()`（x (3,4,4)、m (1,4,4) 广播，内维尺寸相等）生成的 C++ 里 arg-reduction 索引写成 `ks1**2*x0 + x1`（Python 幂运算符），C++ 编译失败；static / aot_eager / 逐维 argmin / amin 正常 | torch 2.14.0+cpu | **待提交**（变形关系配置差分，2026-09-10） | `reports_metamorphic/argmin_pow_dynamic/minimal_verified.py` | 未见同报告；#171870（s390x 向量算子缺失）、#193680（融合 arg-reduction 索引值错）、#186373（关 duck sizing 草稿）都不是 | 根因：`torch/_inductor/codegen/cpp.py` 3749 与 256 行用 `str(index)` 而非 `cexpr_index(index)`；两行修复 |
| 11 | `aoti_compile_and_package` 对返回 `torch.return_types.*` 命名元组的模型（`torch.max(x, dim)`、`topk`、`kthvalue`、`cummax/cummin`、`aminmax`、`frexp`、`geqrf`、`lu_unpack`、`nanmedian`）打包失败：`NotImplementedError: No registered serialization name for <class 'torch.return_types.max'>`；export / torch.compile 正常，拆成普通元组返回即可打包 | torch 2.14.0+cpu | **待提交（低–中）**（export/AOTI 差分，2026-09-10） | `reports_aoti/return_types_packaging/minimal_verified.py` | 未见同报告；相关 open PR #113258（pytree 支持 PyStructSequence，2023 至今未合） | 错误信息指向用户无法操作的内部注册调用 |
| 12 | `F.instance_norm` / `F.batch_norm` 的 running stats 是闭包捕获的普通张量（非 buffer）时：eager/compile 正常并原地更新；`torch.export` 成功但**静默丢掉更新**；`ep.run_decompositions()` 给出正确报错"Constant lifted_tensor_0 is mutated…register it as buffer"；`aoti_compile_and_package` 却抛 **INTERNAL ASSERT**（RegisterFunctionalization_2.cpp:8058，"please report a bug"） | torch 2.14.0+cpu | **待提交**（export/AOTI 差分，2026-09-10；OpInfo instance_norm 全部 8 个带 running stats 的样本命中） | `reports_aoti/lifted_constant_mutation/minimal_verified.py` | 未见同报告；#150008（closed）是同一断言类的另一触发（narrow 视图上的 copy_） | 两处不一致：export 时不报、AOTI 报内部断言 |
| 10 | **eager 侧硬崩溃**：`F.pdist(torch.empty(0, d, requires_grad=True)).sum().backward()` 让进程以 0xC0000094（整数除零）退出，无 Python 异常；(1, d)、(2, d) 正常。**Linux 也复现**（Kaggle，torch 2.10.0+cpu，SIGSEGV，2026-09-10） | torch 2.14.0+cpu（Win）/ 2.10.0+cpu（Linux） | **待提交（eager 缺陷）**（反向分解差分，2026-09-10） | `reports_decomp/pdist_empty_backward_crash/minimal_verified.py`（子进程逐例运行） | 未见同报告（4 组关键词） | `pdist_backward` 未对行数为 0 设防；compile 路径调用同一 kernel 同样崩溃 |
| 8 | **Windows CPU + `max_autotune`：`torch.bmm` / 批量 `matmul` 必然失败**——`LoweringException: AttributeError: function 'cpp_CppMicroGemmFP32Vec' not found`；`mm`/`addmm`/`linear` 正常 | torch 2.14.0+cpu（Windows/MSVC） | **待提交**（配置差分 max_autotune，2026-09-10） | `reports_metamorphic/bmm_autotune_windows_export/minimal_verified.py` | 未见同报告 | 根因一行：`cpp_bmm_template.py` 第 44 行 `extern "C"` 漏了 `{{export_declaration}}`（`__declspec(dllexport)`），gemm/grouped_gemm 模板都有；自动调优的基准 DLL 里找不到符号 |
| 9 | `max_autotune` + `torch.addmm(标量 bias, x, y)`：lowering 抛 `IndexError: list index out of range`（`kernel/mm.py` 714 行先取 `get_stride()[0]` 再查秩）；1-d/2-d bias 与默认配置正常 | torch 2.14.0+cpu | **待提交（低）**（配置差分，2026-09-10） | `reports_metamorphic/addmm_scalar_bias_autotune/minimal_verified.py` | 同一行有 open PR #185578（issue #185533，SliceView 触发），其 guard 不覆盖 0-d | 建议在 #185533 下评论请求把秩检查前置 |
| 7 | `F.channel_shuffle` / `native_channel_shuffle` 对 channels_last 输入：eager/aot_eager 输出保持 channels_last，Inductor 输出变成 contiguous；同输入的 group_norm 在 Inductor 下保持 | torch 2.14.0+cpu | **待提交（低）**（meta 步长差分，2026-09-10） | `reports_decomp/channel_shuffle_channels_last/minimal_verified.py` | 无同报告；同族已修：#187195（max_unpool2d）、#179830（upsample_nearest3d）、#179837（pad）、open #192681（batch_norm） | 一句话 issue 引用同族 PR |
| 5 | `F.binary_cross_entropy(p_bf16, t_bf16, weight=w_fp32)`：eager/aot_eager 返回 bfloat16，Inductor 返回 float32（fp16 同）；无 weight 或 weight 同 dtype 时一致。另：target 为 fp32 时 eager 报 dtype 错、Inductor 照算 | torch 2.14.0+cpu | **待提交（低）**（分解差分，2026-09-09） | `reports_decomp/bce_weight_dtype/minimal_verified.py` | #171282（closed 2026-03-19）是 with_logits 版同一症状，2.14 上 with_logits 已一致，plain 版未修 → 同类新实例 | 一句话 issue 引用 #171282 即可 |

## 待人工复核后决定（第七轮：已关闭 issue 在 2.14.0 上仍复现）

| issue | 现象（2.14.0+cpu） | 关闭情况 | 建议 |
|---|---|---|---|
| #177821 `[inductor] torch.compile ignores a complex indexing assignment` | issue 自带脚本原样复现：整数输出精确不等（`out1=[[2,2],[10,10]]` vs `out2=[[4,0],[12,8]]`） | 2026-05-06 关闭为 completed，**无评论、无关联 PR/提交** | 最值得跟进：评论请求 reopen，附 2.14.0 复现 |
| #176679 tensor subclass `__torch_function__` 结果错误 | aot_eager/inductor 抛 `TypeError`，eager 正常 | 2026-03-11 关闭，仅有"能复现，待定优先级"评论 | 复核后评论 reopen |
| #174386 `use_deterministic_algorithms` 下 `empty_like` 未填 NaN | 复现 1/2 次 | 修复提交在 2.14.0 内 | 多次运行确认稳定性后再定 |
| #184405 dtype 切换后返回过期 float32 | 复现 1/2 次 | 修复提交在 2.14.0 内 | 同上 |
| #182131 fp16 cast 前后数值差 3.9e-4 | 2/2 复现，误差小 | 修复提交在 2.14.0 内 | 可能是修复只缩小而未消除差异；对照 PR 判断 |

## 待人工复核（GPU，torch 2.10.0+cu128 on Kaggle T4；需在 GPU 环境用 issue 原脚本确认）

| issue | 现象 | 关闭情况 | 建议 |
|---|---|---|---|
| ~~#122381~~ CUDA attention 潜在越界 | 读脚本后判为 **Invalid**：模型含 `nn.Dropout(0.1)` 且处于 training 模式，eager 与 compile 的随机流本就不同，误差 1.11 是 dropout 随机性，不是缺陷。载入器已改为：含 Dropout 的模块目标自动切到 `eval()` 并在 notes 里标注 | 2024-05-14 关闭 | 不提交 |
| #113641 `compiling double inplace clamp on strides produces wrong result` | 2.10 上 Dynamo 抛 `InternalTorchDynamoError`，eager 正常（五个上下文 2/2）；同一脚本在本机 2.14.0 CPU 上三路一致 | 2023-11-17 关闭为 completed | 大概率是 2.10 特有、后续版本已修的 Dynamo 崩溃；可在 Kaggle 上 `!python kaggle/verify/issue_113641_*.py` 看 2.10 的实际报错，若确为已修则不提交 |

## 不提交的（已查重或判为无效）

| 发现 | 结论 |
|---|---|
| `torch.cov(x, aweights=w)` + `dynamic=True` 追踪失败 | Duplicate：PR #190669 正在修（`reports_opinfo/7972f93b54ff/DEDUP.md`） |
| `soft_margin_loss` fp16 eager `inf` vs Inductor 有限值 | Invalid：eager 溢出，编译结果更接近 fp64 真值 |
| `new_empty` / `new_empty_strided` 值差异 | Invalid：未初始化内存，比较无意义 |
| `aten.max_pool2d_with_indices_backward` + `dynamic=True`：来自函数参数的 int 成为 SymInt，`int[2]` 形参拒绝 SymInt 标量 | Duplicate / 相关 #122129（open，同一错误类）；已验证 `reports_opinfo_all/6468272fac80/minimal_verified.py` |
| `index_add` 到空维：Inductor 生成内核越界断言，eager 正常返回 | Duplicate：PR #186532（2026-08-18 合并，2.14 分支切割后）修的正是"非法索引编译通过后在后端代码里失败"；`reports_decomp/index_add_empty_dim/DEDUP.md` |
| `F.multi_margin_loss` float16 CPU：eager 抛 `NotImplementedError`（Half 无 CPU kernel），aot_eager/inductor 经分解正常返回 | Duplicate / #144362 的实例（open："compile 缺少 eager 有的 dtype 检查"）；`reports_opinfo_s3/11ddea7fd13c/DEDUP.md` |
| `F.hinge_embedding_loss(reduction='sum', margin≈8.4)`：编译误差 1.1e-6 vs eager 1.8e-7 | Invalid：求和重结合的 1 ULP 级差异，PyTorch 自己的 `same(fp64_ref)` 判为可接受；oracle 已加该否决 |
| `index_reduce` 到空维 / size-1 维的越界 index：eager IndexError，Inductor 静默返回或内核断言 | Duplicate 族：#186532（index_add，已合）、#185977（open PR，仅 index_add）；index_reduce 是同一分解族，可在 #185977 下提一句 |
| `F.cross_entropy` / `linear_cross_entropy` bf16/fp16 输入 + fp32 weight：eager 抛 "expected scalar type BFloat16 but found Float"，compile 照算 | #144362 族（compile 缺 eager 的 dtype 检查）实例，不单独报 |
| `torch.native_batch_norm` training、每通道仅 1 个值（输入 (1,1)）：eager 返回，compile 抛 ZeroDivisionError（分解里 1/(N−1)） | 低：`F.batch_norm` 的 Python 包装在 eager 就拒绝该情形，只有直接调 legacy `native_batch_norm` 才触发；#147287 建议移除该算子 |
| `F.multilabel_margin_loss` 输入含 NaN：eager（含 fp64）返回有限值，compile 返回 NaN | 分歧在 eager 端：C++ `std::max(0, nan)` 吞掉 NaN，compile 的 clamp 传播 NaN 更合理；#141017 已修过该分解的其它问题。不报 |
| `F.max_pool2d` 窗口完全落在 padding 内（W=1、dilation 2、ceil_mode）：eager 索引 1/3，compile 索引 −2/1 | 两侧索引都无意义（eager 的 3 也越界），输入非法。不报 |
| `torch.linalg.eigvals` 输入含 NaN：eager 进程直接被 MKL 中止（"Parameter 3 was incorrect on entry to SGEBAL"） | 非 compile 问题；#93124（2023 关闭）在 2.14.0 Windows 上仍复现，#185247（open）同症状。可作为 closed-but-reproduces 附带提一下 |
| `F.interpolate` 2-D `scale_factor=1.15`（输出尺寸等于输入尺寸）nearest / bilinear 编译结果与 eager 不同（偏差 3.6 / 2.7）；1-D、nearest-exact、bicubic 一致 | Duplicate：open #175154（scale 1.3、nearest、high priority），PR #184848 未合；bilinear 是该 issue 未提到的模式，可在 #175154 下补一句。`scripts/confirm_interp_scale.py` |
| `max_pool2d_with_indices_backward` `kernel_size` 以位置/默认/`**kwargs`/闭包/`tensor.item()` 形式传入且 `dynamic=True`：失败；以字面量/全局/属性/列表/字典传入：通过 | #122129 族（已在上表）；绑定形式扫描给出了精确触发条件，不另报 |
| `masked.argmin` `dynamic=True` C++ 编译失败 | 已归入第 6 条（根因是通用的 arg-reduction 索引打印，masked 只是入口） |
| `F.pixel_unshuffle` 空 batch：eager/aot_eager 返回输入形状 (0,1,6,6)，Inductor 返回正确的 (0,9,2,2) | eager 侧缺陷，Duplicate：open #192816 "Return the documented shape from pixel_unshuffle for a zero-element input" |
| `torch.tensor(1.5).expand(-1, 5, 5)`：eager 返回形状为 **(-1, 5, 5)** 的张量（numel 为负），compile 正确报错 | eager 侧缺陷（0 维张量跳过了"-1 不能用于新增前导维"的检查）；查重未见同报告；非 compile 问题，可单独作为 eager issue 报 |
| 约 40 个算子 int64/bool 输入：eager 抛 NotImplementedError（无整数 kernel），compile 经分解正常返回（softmax/gelu/silu/celu/hardswish/interpolate/max_unpool/grid_sample/round/lerp/…） | #144362 族（open，"compile 缺 eager 的 dtype 检查"）；`results/decomp_full_s1/` 有完整清单，可作为该 issue 的补充列表 |
| `hardswish` / `smooth_l1_loss` / `multi_margin_loss` 输入含 NaN 时**梯度**的 NaN 模式与 eager 不同 | 反向分解在 NaN 传播上与 eager kernel 的 where/mask 写法不同；语义争议大，不报 |

## 待判定

（无）
