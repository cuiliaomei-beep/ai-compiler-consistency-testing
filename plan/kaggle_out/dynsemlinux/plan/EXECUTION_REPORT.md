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

**当前断点（2026-09-20）**：第四/五轮换角度开始。用户要求"换思路找更多 issue"并明确：**照旧做成可跑的工具**（脚本 + 隔离子进程 + 逐条 jsonl 落盘可续跑），确认的缺陷要**附修复建议**（定位到 torch 源码里的 lowering / decomposition / Dynamo VariableTracker 文件）。角度全部写在 `NEXT_DIRECTIONS.md`：§7（输入轴：布局/别名、原地修改、钩子、自定义反向、守卫序列、graph break 插入、AOTI 取回）与 §8（判据轴：error_inputs 错误一致性、整数/转换 UB、特殊函数 vs mpmath 真值、NumPy-in-Dynamo、控制流高阶算子、数据依赖形状/SymPy、Python 版本与平台差分、编译组合律、异常前副作用重放、CI 跳过清单挖掘、autocast 全算子、cudagraphs 陈旧输出）。合并优先级在 §8 末尾：8.1 → 8.2 → 7.1 → 8.4/8.7 → 7.3/7.2/8.9 → 8.3/8.5/8.6 → 其余。**已写代码**：`tcc/sweep_common.py`（公共：jsonl 追加/续跑、`run_isolated` 逐项子进程、`compare` 含 fp64 参照的"编译比 eager 差 10 倍才报"判据）、`scripts/error_parity_sweep.py`（8.1：226 个 OpInfo `error_inputs` + 约 70 条手写越界/形状错误用例；判定 SILENT / OTHER_TYPE / WRAPPED / ok；`--isolate`）。**8.1 全量已跑完（2026-09-20，22 分钟）**：`results/error_parity/cases.jsonl`，252 个算子、787 例：755 ok、21 OTHER_TYPE（异常类型不同，未分诊）、**4 条 SILENT 线索（未分诊、未查重）**：① `index_select` 负索引 `[-1, 0]`——eager 与 aot_eager 抛 "INDICES element is out of DATA bounds"，Inductor 静默按回绕返回；② `index_add` 的 source 形状不匹配——Inductor 静默；③ `take(out=与输入重叠的内存)`——aot_eager/inductor 不做重叠检查；④ `complex(real, imag, out=错误复数 dtype)`——aot_eager/inductor 接受。下一步：逐条写独立最小复现（新进程，2.14 + nightly）、查重（多半属 #144362 "compile 缺 eager 校验"一族，①② 值得单独看）、定位到 lowering/分解给修复建议。脚本里 eager 参照的键已从 `eager` 改为 `eager_ref`（旧记录里该键被 backend=eager 的结果覆盖）。接下来：8.2 `scripts/int_ub_sweep.py`、7.1 `scripts/layout_alias_sweep.py`（都还没写），同样用 PowerShell `Start-Process` 分离运行到 `results/int_ub/`、`results/layout_alias/`。

（注：本会话里曾把后半段工作误标为 09-22 / 09-23，实际机器日期一直是 2026-09-21；下面“凌晨 / 上午 / 中午 / 晚 / 夜 / 深夜”只表示先后顺序，不是真实钟点。脚本文件名里的 0922 / 0923 同理。）

**当前断点（2026-09-21）**：用户指示删除草稿 13（他人已报 #197434），并要求把 `0920issues/` 按优先级从高到低重新编号、从 01 开始依次提交 → 已完成（`scripts/_renumber_0923.py`；旧→新：01→01、02→12、03→19、04→04、05→11、06→06、07→14、08→09、09→13、10→20、11→21、12→10、14→02、15→07、16→05、17→17、18→18、19→03、20→22、21→08、22→15、23→16；README 顶部有同一张映射表）。**下文历史断点里的“草稿 NN”都是旧编号。** 后台：`scalar_arg_sequence_diff.py`（release + nightly，`results/scalar_seq/`）、Kaggle `tcc-int32gpu`（32 位索引边界）。

**当前断点（2026-09-21 收工）——明天从这里接着做**

1. **提交（用户手工，方案 A）**：今天已提交 14 条并登记在 `0920issues/FILED.md`（PyTorch issue #197887 #197888 #197889 #197893 #197894 #197895 #197896；评论 #143649、#197554 下各一条；微软 11155532 / 11155535 / 11155537；numba #10845；jax #40840）。**还剩 9 条**：12、13、15、16、19、21（PyTorch 新 issue）与 14、20、22（评论）。用户说明天继续；**开始前先按根因关键词对这 9 条重新查重**，用户贴链接后跑 `python scripts/mark_filed.py <稿号> <url>`。规则见 `D:\wsl\personal\dr\paper\CLAUDE.md`，交稿前跑 `python scripts/check_issue_drafts.py`。
2. **两轮 issue 的结果记录**：`toxic_compile/ISSUE_OUTCOMES.md`（刷新：`python scripts/issue_status_report.py && python scripts/issue_outcomes.py`）。第一轮 27 条：2 已修复、5 维护者确认、8 他人复现/有修复 PR、1 有争议、11 无回应；第二轮 14 条均无回应。**论文里 “11 确认 / 9 修复” 与证据不符（实际 7 / 2），未改，等用户定口径**。注意 PyTorch 的 `triaged` 常由机器人打，不单独算确认。
3. **未写稿的新线索（明天第一件事）**：torch.fx 代码生成的**名字遮蔽**——被 `symbolic_trace` 的函数若有名为 `nan`（或 `inf`）的参数、图里又有浮点常量 `float("nan")` / `float("inf")`，生成的 `forward` 把常量写成裸名字 `nan` / `inf`，被同名形参遮蔽：`torch.where(mask, float("nan"), x)`（形参叫 `nan`）得到 `[1, 1, 3]` 而不是 `[1, nan, 3]`；`Interpreter` 正确；2.14 与 nightly 0911 都复现；参数名为 `torch` 时是响亮报错。根因：`fx/graph.py` 用 `_register_custom_builtin("inf"/"nan"/"torch"/"device"/…)` 把这些名字当全局使用，`_Namespace` 只给**节点名**改名（`nan_1`），但函数签名仍用占位符的原名 `nan`。查重 4 组关键词无同报告。证据：`plan/reports_fx/codegen_name_shadowing.py`、`codegen_param_shadows_inf_nan.py`（后者里 `clip_scores` 例子不敏感，写稿时把 scores 改成含大于上限的值，如 `[1, 50, 3]` 对上限 `[10, 20, 30]`）。与已提交的 #197894（`-2 ** x`）同属 “FX 生成的 Python 源码与 Interpreter 语义不一致”，根因不同，单独成稿，优先级中–低，编号接在 22 之后（`23`）。
4. **今天跑完的扫描（都已分诊、记账）**：10.1 改写前提、10.2 前缀一致性、10.3/10.4 模型手术与保护机制、10.5 SymInt/SymFloat 标量算术、10.5b 符号形状、10.7 32 位索引（T4）、10.9b 标量实参序列（release + nightly）、10.13 C++ 工具链层（MSVC / g++ / clang++）与 host_opt。没有后台任务在跑。
5. **下一步挖掘方向（按预期产出排序）**见 `NEXT_DIRECTIONS.md` §11。

**2026-09-21 晚**：10.9b `scalar_arg_sequence_diff.py` 在 nightly 上发现 #194976 的残留 → **新草稿 02b（高）**：变化的 Python float 被烤进缓存图，18 个算子中招（含 `interpolate` 错形状）；2.14 + nightly 0921、Win/Linux、CPU/CUDA 都已复核，根因用 `TORCH_LOGS=graph_code,aot_graphs,recompiles` 钉死。release / nightly 两份全量扫描仍在后台跑（`results/scalar_seq/`），跑完看 `--report`：release 上出错的程序预计几十个（都属已修的 #194976，不单独报），nightly 上除 02b 外若还有别的差异需要分诊。

**2026-09-21 补充**：① 五份评论稿（03、04、14、20、22）顶部加了“提交网址”（带 `#new_comment_field`）与“怎么提交”两行，README 新增“评论稿怎么提交”一节（四条目标 issue 均未锁定；#185337 已关闭但可评论）。② 按 `D:\wsl\personal\dr\paper\SUMMARY_WRITING_GUIDE.md` 审计全部 17 份 issue 稿的 Summary：06、11 补了 **Summary.** 标签并改成三句式；01、05、07、08、09、10、12、13、16、17、18、19 改写到 ≤130 词、第三句以 Because 开头、去掉弱化词（`scripts/_summary_guide_0923.py`，不带参数即为检查器）。③ 10.7 32 位索引边界（T4，2.14 + nightly）：26 项可比较的全部一致（负结果）。④ 后台仍在跑 `scalar_arg_sequence_diff.py`（release + nightly）。

**历史断点（2026-09-21 深夜）**：10.5b `symshape_index_diff.py` 跑完（112 程序，111 一致；`F.pad` 负填充裁过头的校验丢失并入草稿 20 第 4 项）。本轮（09-21 深夜 → 09-21 深夜）新增工具 7 个：`rewrite_precondition_diff`、`cxx_intrinsic_algebra_diff`（+`cxx_algebra_families`、`run_issue_cpp_snippet`）、`host_opt_diff`、`model_surgery_diff`、`symint_arith_diff`、`symshape_index_diff`；新增草稿 15–23（其中 16–18 报给微软），13 降级为评论。没有后台任务在跑。下一步候选：10.6 全 lowering 表 × 边界值、10.7 int32 索引、10.9 缓存键完备性（受“陈旧 alpha”启发）、10.13 后续（maskload/maskstore、真实内核语料扩到归约与 float16）、10.11 ONNX Runtime 适配；论文侧：把跨目标与工具链层的结果写进 RQ5/讨论（目前 paper_tcc 还没反映 0920issues 的任何内容）。

**历史断点（2026-09-21 夜）**：`host_opt_diff.py`（178 批）与 10.2 前缀扫描（135 程序）都跑完：前者只重新发现 abs(abs)（草稿 16），后者最大 7.6 ε，均记为负结果（`TO_SUBMIT.md`）。草稿 19 追加了“符号尺寸 `%` 除零崩进程”的第二条路径；19、21–23 的 Linux 复核已写回。后台在跑 10.5b `scripts/symshape_index_diff.py --isolate`（112 个“符号整数流进切片/形状算子”的程序 × 12 个长度 × 3 后端；`results/symshape/cases.jsonl`，`--report` 看结果）。下一步：分诊 symshape；10.6 全 lowering 表；10.7 int32 索引；10.9 缓存键完备性。

**历史断点（2026-09-21 晚）**：10.3/10.4（`model_surgery_diff.py`，76 例）与 10.5（`symint_arith_diff.py`，138 例）跑完并分诊 → **草稿 19（trunc 除零崩进程，评论 #143649）、20（#197554 第二条评论：inference tensor / 确定性模式）、21（torch.fx `-2 ** x` 优先级错，静默错值）、22（SymInt round 负 ndigits 恒等）、23（SymFloat NaN 自比较被折叠）**，全部在 2.14 + nightly 上逐字验证；19、20 已在 Linux/T4 复核，21–23 的 Linux 复核在 Kaggle `tcc-symintlinux`（日志 `kaggle_out/symintlinux.log`，出来后把“结果出来后补一句”替换掉）。g++ 11.4 / clang++ 14 内建函数差分：干净（负结果）。2.14.0 的“陈旧 alpha”是已修的 #194976（不报）。后台仍在跑：`host_opt_diff.py` 3 分片（`results/host_opt/`）、10.2 前缀扫描收尾。`0920issues/` 现 23 份（README 有顺序）。下一步：读 host_opt 报告；10.6 全 lowering 表 × 边界值；10.7 int32 索引；10.9 环境变量 × 缓存键（陈旧 alpha 这类“缓存键漏了某个特化值”的缺陷值得系统化：同一程序换标量/换全局开关后命中缓存是否仍正确）。

**历史断点（2026-09-21 中午）**：后台在跑三件事——① `scripts/host_opt_diff.py` 3 个分片（`results/host_opt/cases_s*.jsonl`，`--report` 看结果）；② `scripts/model_surgery_diff.py --isolate`（`results/surgery/cases.jsonl`，`--report`）；③ Kaggle `tcc-cxxalgebra`（g++ 已出结果：干净；clang++ 重跑中，日志 `kaggle_out/cxxalgebra.log`）。草稿 18 已按词表 v3 的结果扩大（LE/GE/NLE + AVX-512 mask_blend）；草稿 15 补了图内常量张量形式与 46 程序别名普查。接下来：分诊 ①②③ → 10.4 若有 SILENT 并入 #197554 评论稿（04）；再做 10.5 标量算术 / 10.6 全 lowering 表。

**历史断点（2026-09-21 上午）**：新增 10.13 **C++ 工具链层差分** `scripts/cxx_intrinsic_algebra_diff.py`（109,754 个内建函数组合，`/Od` 对优化档）→ MSVC 19.44 三个缺陷：**草稿 16（abs∘abs→x）、17（向量 x+0.0 被消，/fp:strict 也错）、18（LE-select→vmaxps，±0 选错）**，都报给微软 Developer Community（需用户的微软账号，站内先搜重）。14/15 已在 Linux + T4 复核（14 仅 CPU；15 CPU+CUDA 都中）。g++/clang++ 同款差分在 Kaggle `tcc-cxxalgebra`（第一次因给非 AVX-512 机器传了 -mavx512* 而 SIGILL，已修并重推）。10.2 前缀扫描仍在跑，只有 1 ULP 级差异。`0920issues/` 现 18 份。下一步：读 `kaggle_out/cxxalgebra.log`；10.13 后续②⑤（maskload/真实内核语料）；10.3 模型手术/超参数；10.4 安全机制。

**历史断点（2026-09-21 凌晨）**：10.1 改写前提差分跑完并分诊（183 例，9 DIFF）→ **台账 45 / 草稿 15（Inductor `x*1`/`x+0` 返回输入本身）**、**台账 46 / 草稿 16（MSVC 误编译 `abs(abs(x))`，报给微软——第一条 PyTorch 之下的工具链缺陷）**；**草稿 13 被 #197434 + PR #197596 抢先，降级为可选评论**（教训：查重要按根因关键词而不是按我们触发的算子名，且提交前当天再查一次）。Kaggle `tcc-rewritelinux` / `tcc-rewritegpu` 复核 14、15 与 abs(abs)（结果在 `kaggle_out/`）。10.2 前缀扫描仍在跑（`results/prefix/`），目前只有 1 ULP 级差异。下一步：10.13（新）C++ 工具链层差分 `scripts/cxx_intrinsic_algebra_diff.py`（同一 Vectorized<T> 组合 `/Od` vs `/O2`）；然后 10.3 模型手术/超参数、10.4 安全机制。

**历史断点（2026-09-21 深夜）**：7.1 布局/别名扫描跑完（534 算子，527 一致）→ **两条高优先级静默错梯度：台账 43 / 草稿 13（大窗口 max_pool + 转置输入，CPU 与 CUDA 都错）、台账 44 / 草稿 14（adaptive_max_pool3d + channels_last_3d，根因是 eager 内核读非连续 indices）**；12、13 已在 Linux（2.14 + nightly 0920）复核，13 在 T4 CUDA 上同样复现，均已写回草稿。`0920issues/` 现有 14 份（README 有提交顺序：01 → 13 → 14 → 04 → 08 → 12 → …）。下一步：`python scripts/prefix_consistency_sweep.py --isolate`（10.2，已启动则看 `results/prefix/`）；然后 10.1 改写前提、10.3 模型手术/超参数。

**历史断点（2026-09-21 晚）**：(1) 07–11 已在 Linux CPU（2.14.0 + nightly dev20260920）与 T4 CUDA 复核并写回草稿：08/10/11 三处逐字相同（10 在 CUDA 上同样被消掉）；07/09 CPU 专属且不同 CPU 错法不同（07 在一台机器上 `argmin` 返回未初始化的大负数；09 在一台机器上 3 个元素也得 nan）。(2) **副作用/状态差分 `scripts/side_effect_diff.py`（75 例）跑完：71 一致；新缺陷 1 条 = 台账 42 / 草稿 12（Dynamo 丢闭包修改）**，其余 3 条差异为文档化限制或固有差异（见台账 42 下方说明）。(3) 7.1 布局/别名扫描改成 4 路分片在跑（`results/layout_alias/cases_s{0..3}.jsonl`，`python scripts/layout_alias_sweep.py --report` 汇总全部分片；单路时约 2 分钟/算子）。(4) 用户再次要新角度 → `NEXT_DIRECTIONS.md` **§10 第六轮**（按"什么最出货"反推：改写前提、前缀一致性、模型手术/超参数、保护机制、标量算术、全 lowering 表、32 位索引、随机分布、环境×缓存键、历史无关性、ONNX/Numba 并行/CPython JIT、全局模式）；已写 `scripts/prefix_consistency_sweep.py`（10.2），因机器被布局扫描占满，冒烟超时，**等布局扫描结束后再跑**：`python scripts/prefix_consistency_sweep.py --isolate`。

**历史断点（2026-09-21）——8.2 整数/IEEE 扫描跑完并分诊**：`results/int_ub/cases.jsonl` 261 例（231 ok、value 13、signed_zero 15、raise 2、CRASH 2、ub 2；2.2 小时）。逐条独立脚本复核（`reports_intub/*.py`，2.14 + nightly 都复现，全部 Inductor 独有、aot_eager 与 eager 一致）并查重：
- **(A) int8/uint8 的 `min/max/amin/amax/argmin/argmax` 在元素数 ≥16 时错**：全正的 uint8/int8 `min` 得 0、`argmin` 得 **-1**；全负 int8 `max` 得 0、`argmax` 得 -1；int16 及以上正常。根因：生成代码用 `Vectorized<uint8_t>::loadu(ptr, 16)` 只装 16 个元素，其余 16 个通道补 0 却参与归约。**已有 open #191499（Apple Silicon，只报了 amin 得 0）→ 写评论补充：x86-64 AVX2 同样、阈值 16、`amax` 全负、`arg*` 返回 -1**（`reports_intub/int8_minmax_vector_padding.py`、`argmin_uint8_vectorized.py`）。
- **(B) 浮点 `floor_divide` / `//` / `div(rounding_mode='floor')` 差 1**：`1.0 // 0.1` Python 与 eager 得 9，Inductor 得 **10**（float32 与 float64 都是；`0.5//0.1`→5、`6.0//0.2`→30）。根因 `torch/_inductor/lowering.py::_floor_div_floating` = `floor(div_rn(a, b))`，而 eager 是 fmod 算法；与 open #184408（CUDA trunc 差 1，其中说 floor 已用 div_rn"修好"）相关但不同 → 新 issue。
- **(C) CPU 向量化 `remainder` / `%`**：除数为 ±inf 得 **nan**（eager 得被除数）、`1e20 % 3` 得 0（eager 2）、结果精度差；长度 3（标量尾）正确、长度 ≥8（向量路径）错 → 同一元素的结果取决于张量长度。根因 `codegen/cpp.py::CppVecOverrides.remainder`：`a - floordiv(a,b)*b`（标量路径用 `mod()`）。open #194345 只报 CUDA 且说"compiled CPU 正确"→ 新 issue（或在其下评论）。
- **(D) 显式 `x.half().float()` / `x.bfloat16().float()` 往返被 Inductor 消掉**（`70000.→inf` 也没了）：#185337（closed **completed** 2026-06-02）在 2.14 与 nightly 上用更简单的复现仍在 → 评论请求 reopen。
- **(E) `torch.clamp(int8, -1000, 1000)`**：2.14 eager 抛 "value cannot be converted…"，nightly eager 返回原张量；Inductor 两版都把边界绕回成 int8（全 -24；`max=300`→44）→ 新 issue（小）。
- 其余：`atanh(次正规数)`→0、`erf` 近似误差 3e-5、`acosh(f64 max)`（未在独立脚本复现，不报）、有符号零 15 条（open #188680 伞形，可评论补清单）、float→int 越界转换（UB，不报）、eager 崩溃 2 条（重复，见下）。
草稿 07–11 写入 `..\0920issues\`。

**历史断点（2026-09-20 深夜）——本轮产出 6 份新提交稿，全部未提交**：目录 `..\0920issues\`（README 有提交顺序与"不报"清单），台账 `TO_SUBMIT.md` 第 31–36 行。① **31 高**：Inductor 丢失 autograd 的"反向需要的张量被改"检查 → `x@w`/`bmm`/`einsum`/3 维 linear 等**静默错梯度**（Win/Linux、CPU/CUDA、2.14/nightly 全复现；根因用 `_version` 实测：存的是输入的视图，Inductor 下版本计数器独立）；② 32/33：torch._numpy 值错与 dtype/形状错（`np.fix`、`np.cbrt`、`np.clip`、`np.cumsum(int8)`…，根因逐条定位）；③ 34：在维护者总括 issue #197554 下的评论稿（方法 + 10 个新成员）；④ 35：**JAX** `jnp.gcd/lcm` 遇 INT_MIN 死循环；⑤ 36：**Numba** `np.remainder/mod/divmod(MIN_INT, -1)` 杀进程。草稿里的每段 python 代码都用 `scripts/run_issue_snippet.py` 原样跑过、输出逐字核对。**仍在跑/待办**：`results/int_ub/`（8.2 全量，约 5 小时，跑完用 jsonl 里 `verdict` 含 value/raise 的条目分诊；有符号零一类先对照 open #188680）；Kaggle `tcc-xtargetlinux`（JAX/Numba 两条的 Linux 复核，`kaggle_out/xtargetlinux.log`，出来后在 05/06 草稿头部补一句）；未做：7.1 布局/别名扫描、7.3 钩子、ONNX Runtime 与 Triton 适配器（§9 表）。

**2026-09-20 晚 续挖（用户："按之前思路继续挖" + "工具还不能测 PyTorch 以外的"）**：
- 8.1 四条 SILENT 线索逐条独立进程复核（`scripts/diag_error_parity_leads.py`）并查重：① `index_select` 负索引被 Inductor 回绕接受 = **重复** open #169779；② **`index_add` 的 source 形状不匹配**：eager/backend=eager/aot_eager 都抛 "source tensor shape must match self tensor shape"，**Inductor 静默按广播算出结果**（`[3,4,0,0,3,4]`；(4,3)+source(2,1) 同样；dynamic=True 同样）——相关但不同：#121135（只说 randperm 模式）、#185885（负索引）；③ `take(out=与输入重叠)` 与 ④ `complex(out=错误 dtype)`：aot_eager/inductor 都接受，低价值。**关键发现：维护者 2026-09-18 新开的总括 issue #197554 "☂️ [PT2] Validation lost" 明确说"需要的是一个把 OpInfo `error_inputs` 过编译路径的系统扫描"——正是 8.1 这个工具；而且它的成员列表里已经有用户提交的 #197095（interpolate 零尺寸）**。建议用户在 #197554 下评论：附扫描方法 + 新成员（②③④）。21 条 OTHER_TYPE 全是"Inductor 运行期越界断言抛 RuntimeError 而 eager 抛 IndexError"，设计如此，不报。
- 8.1 第二批 `scripts/error_parity_batch2.py`（129 个小程序：index/scatter 族形状契约、dtype 契约、`out=` 契约、原地类型提升、重叠内存写、autograd 原地规则、**反向需要的张量被改**〔7.2 子项〕）→ `results/error_parity/batch2.jsonl`，`--report` 出摘要。分离运行中。
- 8.2 `scripts/int_ub_sweep.py`（261 个用例：整数二元/一元、浮点二元/一元的 IEEE 特殊值、float→int 转换；判据含 NaN 模式、有符号零；每用例全长 + 前 1 + 前 7 个元素三种长度）→ `results/int_ub/cases.jsonl`，分离运行中（每用例约 80 s，全量约 5 小时）。冒烟已见：`maximum(0.0, -0.0)` eager `0.0`、Inductor `-0.0`（有符号零；注意 open #188680 正是"OpInfo 对有符号零不敏感"）。
- eager 整数边界崩溃两条，**均重复**：`torch.div(INT_MIN, -1, rounding_mode='trunc')` 进程 0xC0000095 = open #138425；`torch.lcm(INT32_MIN, 13)` 进程崩溃 = open #121343（根因是 `torch.gcd` 对 INT_MIN 返回 −1 = open #187338）。结论：eager 整数极值这块已被别人挖过，重心放在"编译 vs eager"与非 PyTorch 目标。
- **跨目标（NEXT_DIRECTIONS §9）**：新环境 `..\venv_xtarget`（Py3.14：numpy 2.5.3、numba 0.67.0、jax 0.11.2、onnxruntime 1.30）。`scripts/xtarget_numpy_diff.py`：同一份 268 个 NumPy 风格小程序 × 三个目标适配器——`dynamo`（torch.compile 包 numpy 代码，参照=真 NumPy）、`numba`（njit，参照=真 NumPy）、`jax`（jit，参照=`jax.disable_jit()` 下的同一函数）。三个目标分离运行中，`results/xtarget/<target>.jsonl`，`python scripts/xtarget_numpy_diff.py --report`。**中途线索（未分诊、未在各自仓库查重）**：Numba——`np.remainder`/`divmod` 在 INT_MIN % −1 上**进程崩溃**（NumPy 返回 0）、`np.floor_divide(int8 −128, −1)` 得 0（NumPy −128）、移位量为负/≥位宽时结果不同、`np.lcm` 符号不同、`int64+float32`→float32（NumPy float64）；torch._numpy——**`np.square(int8)` 返回 float64 且不回绕**（NumPy 返回 int8）、`np.true_divide(int8,int8)` 得 float32（NumPy float64；先查 `torch._dynamo.config.numpy_default_float`）、uint16/32/64 直接 NotImplementedError 而不是回退、`np.gcd` 符号；JAX——`jnp.gcd` 在某些极值输入上**不终止**（扫描卡在 `ii_gcd`，`scripts/diag_jax_gcd_hang.py` 在逐输入定位）。
- `tcc/sweep_common.py` 现在在没有 torch 的解释器里也能 import（跨目标用）。

**论文 LaTeX 工程（2026-09-20，用户要求）**：`D:\wsl\personal\dr\paper\toxic_compile\paper_tcc\`（`README.md` 有目录说明、编译方法、每张图表的数据出处、待作者确认事项）。模板 `\documentclass[acmsmall,screen,review,anonymous]{acmart}`；当前版面：正文 18.0 页（要求 17.8–18）、参考文献 3.34 页（要求 ≤4）、55 条（要求 ≥40，全部来自 dblp，条目前有 `%` 链接、title 用 `{{}}`、无 editor）。章节/图/表/文献分目录；10 张图类型各不相同（流程图、代码+分层结果条、依赖图、时序图、斜率图、气泡散点、阶梯线+堆叠柱、棒棒糖+条形、热力图+堆叠条、对数散点）。issue 口径按用户给定：27 条已提交、**11 已确认、9 已修复**，RQ5 答案里写了 PyTorch 的影响力。写作规范：`C:\Users\clm\.claude\skills\academic-research-skills`（已 clone，以后写作都遵循）。本机新装 MiKTeX 25.12（`%LOCALAPPDATA%\Programs\MiKTeX`）；编译 `powershell -ExecutionPolicy Bypass -File build.ps1`，量页数 `python build/measure.py --png`。dblp 网页被 Anubis 反爬挡住，文献改走官方 SPARQL 接口 `https://sparql.dblp.org` 生成（`bib/fetch_dblp.py`，缺 `timestamp` 字段）。RQ2 基线只有 Random 与 NNSmith 是真跑过的，TorchProbe/FreeFuzz/TitanFuzz 未跑，已在论文 5.1 与 6.3 如实写明。台账仍是 `TO_SUBMIT.md`（1–30），已提交仅 #197084，其余由用户手工提交；**未经用户明示不得提交任何 issue**。

**历史断点（2026-09-15）**：应用户要求做了误报复核（`scripts/verify_0913_issues.py`：27 条各在新进程重写最小复现，2.14 与 nightly 各一遍）。结果 25 条重现、1 条需 GPU；**两处修正**：(a) 第 28/07 条前向 AD 断言——早先同进程矩阵里的 ok 是状态残留，逐用例独立进程（`scripts/diag_jvp_make_dual_isolated.py`）下三个后端全部断言，issue/草稿/台账已改；(b) 第 12/13 条 export——"静默丢更新"不成立（`scripts/diag_export_lifted_mutation.py`：lifted constant 与原张量同存储，导出模块照样原地更新），保留 run_decompositions 报错 + AOTI 内部断言，Summary 已改写。ldexp 文档未规定 dtype，第 18/08 条依据不变。**2026-09-15 提交了第一条**：0913issues/01（pinv / matrix_sqrth 复数梯度）→ https://github.com/pytorch/pytorch/issues/197084 ，用 GitHub CLI（`C:\Program Files\GitHub CLI\gh.exe`，账号 cuiliaomei-beep，浏览器授权）以 `gh issue create --body-file` 提交，正文去掉了私有文件引用；其余 26 条 + 2 条评论**由用户自己在网页上发**（2026-09-15 决定）。用户直接用 `0913issues/NN-*.md` 原草稿在网页上粘贴（曾生成过带 AI 声明的 paste/ 目录，用户不需要，已删除）。PyTorch `AI_POLICY.md` 要求 AI 生成内容须声明并圈起、须有人负责、不接受全自主 agent 提交——因此没有做定时批量提交；是否加声明由用户决定。#197084 目前没有声明，建议用户在网页上补一句。

**历史断点（2026-09-13 晚）**：按用户要求生成了提交稿目录 `D:\wsl\personal\dr\paper	oxic_compile913issues\`（27 条新 issue + 2 条评论，编号 = 建议提交顺序，Summary 段按 `SUMMARY_WRITING_GUIDE.md` 三句结构；README 有编号对应表；生成脚本在会话 scratchpad `make_0913_issues.py`，源是 `plan/issues_0910`）。**仍未提交任何 issue**。

**历史断点（2026-09-13 第三轮结束）**：§6.10 末尾的角度全部执行完（一元 dtype × autocast × out=、二阶导[不适用]、前向 AD 实/复、vmap、Dynamo 第三批）。候选 **30 条**：新增 26（#144247 部分重复→评论）、27（ldexp 前向 AD 进程崩溃）、28（`_make_dual` 断言，Linux 三后端）、29（#190275 重复）、30（abs out= dtype）。草稿 27/28 已写（`issues_0910/27,28`），30 只在台账。本机与 Kaggle 无任务在跑。下一批想法在 `NEXT_DIRECTIONS.md` §6.11 末尾（hessian/jacrev 经编译、二元 out=、CUDA 上重跑 6.2b/6.4d）。

**历史断点（2026-09-13 夜，用户关机）**：第二轮换角度（NEXT_DIRECTIONS §6）全部执行完毕，本机与 Kaggle 无任务在跑，关机安全。明天 "继续" 从这里起：先看本段与 §3.O、`NEXT_DIRECTIONS.md` §6.10。候选从 13 条增加到 **25 条**（`issues_0910/14–25`，README 有索引；`TO_SUBMIT.md` 第 14–25 行），全部在 2.14 与 nightly、Windows 与 Linux 上复核过，全部未提交。各角度产出见 §3.O 与 `NEXT_DIRECTIONS.md` §6.10。用户下一步决定：是否/以何顺序提交；或继续 §6.10 末尾列出的下一批角度。

**历史断点（2026-09-12 上午）**：13 条候选草稿等用户决定是否提交。为提交前复核 + 路线 C（版本差分）第一步，推送了两个 nightly 任务：`tcc-nightlycpu`（nightly CPU：`scripts/verify_candidates_cuda.py cpu` + decomp 差分 fwd/grad 各 1 轮）和 `tcc-nightlygpu`（nightly cu130，T4：verify_candidates cuda + cpu）。nightly 复核全部完成（GPU/CPU/Windows 三个环境 13 条全部仍在，已写入草稿；分解差分 nightly 独有的两条线索一条是 #175084 重复、一条是并列值梯度归属的平台差异，都不报，见 §3.N）。第二轮换角度的建议写在 `NEXT_DIRECTIONS.md` §6，等用户选。以下命令仅供复查：

```bash
cd D:\wsl\personal\dr\paper	oxic_compile\plan
python kaggle\drive.py status nightlycpu nightlygpu
python kaggle\kernel_log.py chenyuefei/tcc-nightlycpu kaggle_out
ightlycpu.log
python kaggle\kernel_log.py chenyuefei/tcc-nightlygpu kaggle_out
ightlygpu.log
python scripts\kaggle_log.py kaggle_out
ightlygpu.log      # 逐条 case 01–13 / G1–G7 的 PASS/FAIL 表
```
把每条候选的 nightly 状态填进 `TO_SUBMIT.md` 与 `issues_0910/README.md`（"nightly 仍在 / 已修"），已修的草稿改为不提交。

**历史断点（2026-09-11 下午）**：推荐清单五项（5.6 磁盘缓存、5.8 AOTI、GPU 扫描、5.4 接入 Phase 1、§21 同设备基准）全部完成并分诊；13 条候选草稿在 `issues_0910/`（含 2.14 CUDA 复核证据）；`benchmark/historical_bugs.json` 67 条（35 条 Verified）。Kaggle 上只剩 `tcc-models`（torchvision 真实模型上 T4）在跑，`results\kaggle_wait7.log` 的 waiter 完成后拉汇总与日志到 `kaggle_out\models\`；看 `gpu_reports_models\CAMPAIGN.md` 的候选数，有候选再按签名用 `--file-pattern` 拉 `issue.md`。Kaggle 输出下载用 `--file-pattern` 只取小文件（CDN 对大批量下载反复 SSL 断连），内核日志用 `kaggle\kernel_log.py`。

**历史断点（2026-09-10 22:30）**：本机所有扫描已跑完并分诊；Kaggle 上还有两个 T4 任务在跑（`tcc-gpucuda`：metamorphic/aoti/binding 的 CUDA 步骤；`tcc-bindinggpu` v2：绑定变体流水线），第 1 项两个 notebook 已 COMPLETE 但输出下载被 CDN 反复断开、尚未拉全。明天开机后：

```bash
cd D:\wsl\personal\dr\paper\toxic_compile\plan
python kaggle\drive.py status gpucuda bindinggpu chenyuefei/notebook955c6cac50 chenyuefei/notebookf4aab87efb
python kaggle\drive.py pull chenyuefei/notebookf4aab87efb chenyuefei/notebook955c6cac50   # 第 1 项 A(2.10)/B(2.14)，自带重试，已下载的文件跳过
python kaggle\drive.py pull gpucuda bindinggpu                                              # 状态 COMPLETE 后
# 第 1 项合成同设备基准（两目录都要有 KNOWN_BUGS.md）：
python scripts\build_benchmark.py --old kaggle_out\chenyuefei_notebookf4aab87efb\plan\reports_gh_cpu_2.10 --old-version "2.10.0+cpu (Kaggle CPU)" --new kaggle_out\chenyuefei_notebook955c6cac50\plan\reports_gh_cpu_2.14 --new-version "2.14.0+cpu (Kaggle CPU)" --verified
# 第 3 项分诊：
type kaggle_out\gpucuda\plan\gpu_results_meta_cfg\METAMORPHIC.md
type kaggle_out\gpucuda\plan\gpu_results_aoti\AOTI.md
python scripts\binding_summary.py kaggle_out\gpucuda\plan\gpu_results_binding\binding.json
# 第 7 项：kaggle_out\bindinggpu\plan\gpu_reports_binding_*\SUMMARY.md
```
如果 `pull` 一直因 SSL 断开失败，备选：在网页上打开该 notebook 的 Output 页 → Download all，解压到 `kaggle_out\<名>\`。`models` GPU 任务（`kaggle\jobs\models.py`）等 GPU 配额空出来再 `python kaggle\drive.py push models`。

**当前断点（2026-09-22 19:40；最新，从这里续）**：
- 0920 批 **01–35 全部提交**。14:00 前新增：33 → #198119（avg_pool 反向 ceil_mode）、34 → #198133（Inductor CPU `erfinv` 近 ±1 精度只有 3～4 位：`calc_erfinv` 两步牛顿相消；MSVC 7.5e-3、glibc 7.8e-6；CUDA 正确）、35 → #198134（float64 向量 `acosh` 在 x > √DBL_MAX 溢出，SLEEF；float32/CUDA/标量尾部正确）。
- 34/35 来自新探针 `reports_pairs/large_arg_special_functions.py`（36 个特殊函数 × 大参数/近奇点 × n=3/64）——教训：**探针张量长度必须 ≥ 向量宽度**，否则只测到标量尾部（之前的手工探针因此漏掉）。
- **19:40**：三条新扫描跑完并记账——8.3b 二元函数/归约 vs mpmath（台账 88：9 命中全是已报族 #198057/#194345/#197895/#197089，无新缺陷）、8.8 编译组合律（台账 86：232 对，21 差异全可解释，负）、8.10 CI 跳过/容差清单（台账 87：Windows 上无一复现，负）。39 → #198183 已登记。**本机与 Kaggle 无任务在跑。** 下一步：7.6 AST 逐语句插 graph break、8.7 Python 版本差分（需装 3.11–3.13 解释器）、GPU 项等 Kaggle 配额。
- **18:45 收工点**：8.5 HOP（台账 84，负结果）、7.4 自定义算子（台账 83，负结果；pinv 一例可补到 #198118）、8.3 特殊函数 vs mpmath（台账 85）三条并行扫描全部跑完分诊。8.3 产出 **39 号新稿**（`0920issues/39-inductor-cpu-vector-erf-atanh-lose-accuracy-near-zero.md`：Inductor CPU 向量 float32 `erf` 近 0 全丢相对精度 + 向量 `atanh` 小 |x| 得 0；2.14 + nightly、Windows AVX-512 + Linux AVX2（Kaggle `tcc-erflinux` 已取回：Linux 下 n=3 也错）；checker 通过，输出为真实运行结果）。**39 已由用户提交 → #198183（18:56，已 `mark_filed`；0920 批 01–39 全部完成，FILED.md 39 项 GitHub + 3 项微软）。****本机与 Kaggle 均无任务在跑、无轮询。** 计划剩余项：8.9 副作用/graph-break 重放、7.6、8.8 编译组合、8.7/8.10/8.12、Triton/TileLang 目标；可选评论 #6976、#158087、#198118 的 custom-op pinv 补充（NEXT_DIRECTIONS §12.5）。
- **17:00 收工点**：`tcc-edgesing` v2 取回分诊 = 负结果（台账 80 已更新）。**本机与 Kaggle 均无任务在跑、无轮询。** 0920 批 01–38 全部完成。下一步见 NEXT_DIRECTIONS §12（检测器化：`dispatch_mode_sweep` / `dispatch_mode_grad_sweep` / `opinfo_edge_sweep` 四种模式；论文更新）。
- **16:40**：37、38 已由用户发出并登记（`FILED.md` 共 38 项 + 微软 3 项；0920 批 01–38 全部完成）。唯一未完：Kaggle `tcc-edgesing` v2（Linux f32/f64 近奇点重跑，不轮询；取回后与 `edgefp32`/`edgewide` 比对只看新增行）。
- **16:25**：新工具 `scripts/dispatch_mode_grad_sweep.py`（梯度版 dispatch-mode 差分）→ **38 号评论稿**（#198118 下：lstsq 反向 + FlopCounterMode 触发，台账 82）。待用户提交：37（#198155 评论）、38（#198118 评论）。`tcc-edgesing` v2 仍在跑（不轮询）。
- **16:05**：`tcc-edgeunsupgpu` 取回并分诊 → **37 号评论稿**（#198155 下：T4 383 对静默，73 CUDA 专属，台账 81）。`tcc-edgesing` v2 仍在跑（不轮询）。
- **15:40 状态**：36 → **#198155** 已提交（0920 批 01–36 全部提交）。本机四个分片跑完并分诊：export 差分负结果（台账 79）；Windows f32/f64 近奇点重跑无新族（台账 80）。边界表又补了 `nextafter(1, 0)`（erfinv 现在被扫描命中），Kaggle `tcc-edgesing` 已用新表重推；`tcc-edgeunsupgpu`（T4）仍在跑。**两者都不轮询**；取回：`python drive.py pull edgesing` / `pull edgeunsupgpu`，日志 `=====JSONL BEGIN/END` 间切 jsonl，`--report` 看，与 `kaggle_out/edgefp32`、`edgewide`（CPU）或 `edgeunsup`（Linux 同族）比对只看新增。
- **15:20 另起（不轮询）**：`scripts/export_edge_diff.py`（11.6 第三条部署路径：`torch.export.export(...).module()` 与 `ep.run_decompositions().module()` vs eager，OpInfo × 边界值，float32/int64/bool，纯 Python 无需编译器）本机两分片 `results/export_edge/cases_{0,1}.jsonl`；看结果 `python scripts/export_edge_diff.py --report`。半精度特殊函数探针（`$TEMP/half_special.py` 逻辑）= 负结果，只有已知的中间量族。
- **15:05 在跑（不轮询）**：Kaggle `tcc-edgesing`（Linux，float32/float64，边界值表新增近奇点值 `1±eps`、`√max·1.01`、`π/2` 等——erfinv/acosh 之前被漏掉的原因）、`tcc-edgeunsupgpu`（T4，`--unsupported --device cuda`：36 号稿那一族在 Triton 上的对照）；本机两分片 `results/opinfo_edge/sing_f_{0,1}.jsonl`（同 edgesing，MSVC）。取回/分诊：`python drive.py pull <job>`；`python scripts/opinfo_edge_sweep.py --report <jsonl>`；与旧结果比对只看新增行。
- **14:55 已分诊**：`edgeunsup` → **36 号稿**（134 算子 / 418 对，5 组机制，台账 77）；`edgedyn` → 负结果（台账 78）。原记录：**Kaggle 两个扫描已完成并取回（14:05），尚未分诊**：`kaggle_out/edgeunsup/`（`opinfo_edge_sweep.py --unsupported`：全算子 × 不支持的 dtype，29 号稿那一族的穷举）、`kaggle_out/edgedyn/`（`--dynamic`）。日志里 `=====JSONL BEGIN/END` 之间是 jsonl（`cases.jsonl` 若为空则从日志里切出来）；分诊命令 `python scripts/opinfo_edge_sweep.py --report kaggle_out/<job>/cases.jsonl`，先把差异归入已知族（低精度中间量 #183607、符号零 #188680、inf/NaN 结合律、已提交项），剩下的才追。**本机与 Kaggle 都没有任务在跑、没有轮询进程**（用户 14:05 要求暂停轮询）。
- 工具更新：`opinfo_edge_sweep.py` 新增 `--grad` / `--dynamic` / `--unsupported` / `--device`，sticky CUDA error 自动重启；`scripts/dispatch_mode_sweep.py`（eager vs 转发 TorchDispatchMode，全算子，2,529 对，负结果除 pinv/polar 族）。
- 下一步：分诊两个 Kaggle 结果；把 12.1 的静态审计做完整；探针类（特殊函数、归约）扩到 bfloat16/float16 与 CUDA。

**当前断点（2026-09-22 11:15；最新，从这里续）**：
- 今天累计：0920 批 **01–32 全部提交**（`FILED.md` 31 项 + 微软 3 项）；今日新提 28 → #198081（any(uint8)）、29（#197554 第三条评论）、30（#198071 评论）、31 → **#198118**（复数 pinv/polar/matrix_sqrth 在任何 TorchDispatchMode 下前向值错——#197084 的真正根因；高）、32（#197084 更正评论）。**待提交：33**（Inductor avg_pool 反向 ceil_mode 除数错，高；CPU + T4，2.14 + nightly）。
- 规则更新：`check_issue_drafts.py` 按提交链接模板检查表单字段（Error logs 等）；CLAUDE.md 第 2b 条。
- 12.1 收尾：`reports_pairs/lowering_vs_decomp_special_cases.py`（106 例）→ 29/30 号稿；台账 68–70。12.2 收尾：`opinfo_edge_sweep.py --grad` float32 508 对 → 33 号稿；台账 72–73。11.4 的 int64/float64/complex64 组（Linux）与 T4 全 dtype 第二版（sticky CUDA error 自动重启）跑完：`kaggle_out/edgewide`、`edgegpu`；complex64 的 `linalg.polar` 一行 → 逐层定位到 TorchDispatchMode → 31 号稿；其余归已知族（`acosh` float64 max 在 gcc/SLEEF 下 inf 只在 Linux，未写稿）。
- **新工具**：`scripts/dispatch_mode_complex_sweep.py`（OpInfo 复数算子 × 转发 mode，纯 eager）、`reports_pairs/python_key_conj_composites.py`、`conj_lost_under_dispatch_mode.py`、`avg_pool_ceil_mode_backward.py`、`boundary_grad_hardtanh_relu6.py`（负结果）。
- **下一步**：把 dispatch-mode 差分推广到全 dtype 全算子（`scripts/dispatch_mode_sweep.py`，纯 eager，几分钟）；然后 §12 其余。

**当前断点（2026-09-22 09:40；最新，从这里续）**：
- **0920 批 27 稿全部提交完**（`FILED.md`：16 新 issue + 8 评论 + 3 微软工单）。今天用户提交：12 #198052、19 #198056、13 #198057、15 #198064、16 #198070、21 #198071、23 #198072、26 #198077；评论 14（#191499）、20（#185337）、22（#197554 第二条）、24（#174386）、25（自己的 #197889）、27（#183607）。`ISSUE_OUTCOMES.md` 已刷新（第二轮 27 项：3 确认 / 4 复现 / 20 无回应；今天新提的全是机器人标签）。
- **新稿 28（待提交，`check_issue_drafts.py` 通过）**：Inductor 下 `torch.any(uint8)` 返回 bool（eager / aot_eager / `torch.all` 保留 uint8；`any(x)*200+100` eager 44 vs 编译 300）；根因 `lowering.py::reduce_any` 绕过保留 uint8 的 `_refs.any` 分解、`aten.all` 无 lowering 走分解——11.3 的成对不对称；2.14 + nightly，Win + Linux + T4。提交链接 `issues/new?template=pt2-bug-report.yml`；提交日再查重。
- **11.4 收尾**：`scripts/opinfo_edge_sweep.py`（`--device cpu|cuda`，崩溃可续跑）跑完 f16/bf16（本机 + Linux）、int8/uint8/int16/bool（Linux）、float32/int32（Linux）、T4 全 dtype：唯一新可报项 = 28 号稿；其余归入 #183607（低精度中间量）、#188680（符号零）、inf/NaN 边界的算法/结合律差异（addcdiv、std/var、norm、并行扫描 cumprod）、gcc FMA 收缩、已提交项再发现（自己的 #197108、#193757 BCE）。台账 63–65、67。
- **11.6 收尾**：ONNX Runtime 优化级别差分（`scripts/ort_opt_diff.py`，154 程序）两级一致 = 负结果；Numba fastmath 全在文档契约内；Numba parallel 丢失自身 lowering 的 ZeroDivisionError（`//`、`%`、`/`；Windows 上 `**` 负指数给未初始化内存）= numba #6976（2021 起 open），`a + a[:, :1]` AssertionError = #3729 → 不报（台账 64、66；可选：在 #6976 下补充 0.67 现状）。
- **工具新增**：`scripts/opinfo_edge_sweep.py`、`scripts/ort_opt_diff.py`、`scripts/cpp_wrapper_diff.py`、`scripts/overrides_pair_audit.py`、`xtarget_numpy_diff.py` 的 `numba_parallel` / `numba_fastmath` target、`symint_arith_diff.py` 的 `inductor_cppwrap` 后端；Kaggle 作业生成器 `make_opinfo_edge_job.py`、`make_opinfo_edge_gpu_job.py`、`make_recheck_half.py`、`make_recheck_fxpickle.py`。`venv_nightly` 里新装了 onnxruntime / onnx / onnxscript。
- **下一步候选**（§11 已全部过一遍；新角度写在 NEXT_DIRECTIONS §12）：① 把 28 的模式做成静态审计——枚举 `_inductor/lowering.py` 里有专门 lowering、且 `_refs`/`_decomp` 分解里带 dtype 特判（uint8 / bool / 整数提升）的算子，逐个对比返回 dtype；② OpInfo 边界值扫描加 `dynamic=True` 与反向（`requires_grad`）两档；③ 在 #6976 下补充评论（可选）。

**当前断点（2026-09-22 续，时钟约 10:00）**：
- 提交登记新增：13 → #198057、14 → 评论 `#191499#issuecomment-5769459765`、15 → #198064（`FILED.md` 共 19 项）。还剩：新 issue 16、21、23、26；评论 20、22、24、25、**27**（新写：#183607 下，float16 融合链 `y` 是 inf 而 `isinf(y)` 是 False，`emulate_precision_casts=True` 在 CPU 与 T4 上都修好，六组平台逐字相同）。
- 11.3 收尾：Python wrapper vs C++ wrapper 差分为负结果（台账 62）；副产物台账 59（复数 `repr` → `infj` NameError，响亮）、61（`int(item())` 非有限值 → INT64_MIN，= #158087）。
- 11.4：`scripts/opinfo_edge_sweep.py`（OpInfo 全算子 × 边界值；崩溃可续跑 `.inprogress` 标记）本机 f16/bf16 组跑完 = 负结果（台账 63，全归入 #183607 / #188680 / 已提交项）；Kaggle `tcc-edgeint`（int8/uint8/int16/bool）与 `tcc-edgefp32`（float32/int32）第二版运行中（第一版在 `div` 整数除零处被 SIGFPE 杀死）。结果取回：`python drive.py pull <job>`，日志里 `=====JSONL BEGIN/END` 之间是 jsonl，用 `python scripts/opinfo_edge_sweep.py --report <file>` 看。
- 11.5：本机只有 MSVC 14.44（票里那一版），无更新版本可复测。
- 下一步：取回两组 Kaggle 结果分诊（int 组重点：8.2 未覆盖的算子）→ 11.6（ONNX Runtime 差分、Numba parallel）。

**当前断点（2026-09-22，时钟 07:40；最新，从这里续）**：
- **提交登记**：用户今天又手工提交了 12 → #198052、19 → #198056（`0920issues/FILED.md`，共 16 项已提交）。还剩用户待提交：新 issue 13、15、16、21、23、26；评论 14（#191499）、20（#185337）、22（#197554 第二条）、24（#174386）、25（自己的 #197889）。提交当天要再查重；贴链接后用 `python scripts/mark_filed.py <稿号> <url>` 登记。**我不代提交。**
- **今天新写的稿（均过 `check_issue_drafts.py`，代码块在 2.14 + nightly 原样执行）**：23（fx 形参名 `nan`/`inf` 遮蔽浮点常量；Linux 已复核）、24（评论 #174386：确定性模式 `empty*` 在 CPU 上仍不填充；从 22 拆出，22 改为 3 项）、25（评论自己的 #197889：由 float 派生的 int 实参同样沿用旧值，11.2 普查 v2 的产出）、26（**GraphModule 经 pickle / torch.save 往返后原地运算变非原地**，Dynamo 捕获的 `buf += g` 图受影响；Linux 2.14 + nightly dev20260921 已复核，`kaggle_out/fxpicklelinux/log.txt`）。台账行 55–58。
- **11.1 FX 差分已收尾**（`scripts/fx_codegen_vs_interpreter.py`，10,518 图，`results/fx_codegen/cases_2.14.0.jsonl`）：真缺陷三族 = pow 优先级（已提交 #197894，现有修复 PR #198053）、名字遮蔽（23）、pickle 重新追踪（26）。其余全是工具假象或不值得报：字面量当原地目标的 BUILD_ERROR、`inf += …` 的 UnboundLocalError（遮蔽族的响亮形态）、pickle 时常量表达式在加载期求值（`-2/0` 在 load 时抛 ZeroDivisionError）、`operator.not_/truth` 节点无法 unpickle（TraceError，响亮）、Interpreter 不支持 kwargs 且 `*args` 给 list、`**kwargs` 给 `[]`（极低，不报）。
- **11.2 已收尾**：普查 v2（56 程序，nightly 7 静默错 + 5 编译失败）→ 25 号评论稿；接受 SymInt 的位置 / 按值分支的分解 / SymBool 全部正确（负结果，已写进 25 号稿头）。
- **11.3 进行中**：① `scripts/overrides_pair_audit.py`（CppOverrides vs CppVecOverrides 同名方法并排，输出 `results/pairs/overrides_audit_nightly.txt`）：除已知的 truncdiv（03）、remainder（13）外无新不对称；`fmaximum` 标量 `std::max` / 向量 `blendv(a,b,a<b)` 对 NaN 都不符合 fmax 语义，但只被 Triton 侧的 "fmax" 归约用到，CPU 不可达，不报；nightly 的向量 `asinh` 新公式经代数核对正确。② **新的成对路径：Python wrapper vs C++ wrapper（`cpp_wrapper=True`，AOTI 的路径；本机 MSVC 可用）**——`scripts/symint_arith_diff.py` 加了 `inductor_cppwrap` 后端（138 个符号表达式，`results/cppwrap/symint_214.jsonl`，分离运行中）；新工具 `scripts/cpp_wrapper_diff.py`（174 个程序：fallback 内核的特殊浮点 / 大整数 / 复数 / Optional / int 列表 / 字符串实参，返回 Python 数，输出别名，输入原地修改；eager vs py wrapper vs cpp wrapper；`results/cppwrap/cases_2.14.0.jsonl`，分离运行中）。中期结果：符号表达式 38/138 里 cpp 专属的只有 `round(a/2)` 响亮报错；程序 22/174 全 ok；cpp wrapper 不支持返回 Python 数（`Unsupported scalar_to_tensor_handle`，响亮）。**续跑**：两个命令都带 `--isolate`，重跑同一命令即从 jsonl 断点续；看结果用 `python scripts/cpp_wrapper_diff.py --report`。
- **issue 结果台账**：`toxic_compile/ISSUE_OUTCOMES.md` 今天刷新两次（第一轮 27：2 修复 / 6 维护者确认 / 9 他人复现 / 1 争议 / 9 无回应；第二轮 16 项：3 确认 / 4 复现 / 9 无回应）。论文里的 27/11/9 口径仍待用户决定，论文未改。
- **下一步**：等两个 cpp_wrapper 扫描跑完并分诊 → 11.4（全 lowering 表 × 边界值，建议放 Kaggle gcc 上跑）→ 11.5（词表 v4 / 新 MSVC 复测）→ 11.6 其余（ONNX Runtime、Numba parallel）。

**当前断点（2026-09-10 下午，历史）**：`TO_SUBMIT.md` 已有 10 条候选（用户决定全部暂不提交）。按用户要求做了第二轮系统查重（`results/dedup_0910.md`，每条 4–5 组关键词）并按 `0909ISSUEs` 的格式为 10 条各写了可直接粘贴的 issue 草稿：`issues_0910/`（README 是优先级与查重结论；01–06、08–10 用 `pt2-bug-report.yml` 模板，07 pdist 是 eager 崩溃用 `bug-report.yml`）。查重过程中修正了第 4 条的根因（`_refs/linalg` 对负 `dim` 未规范化，`dim=1` 正常、`dim=-1` 失败）。expand(-1) 0 维与 open #70398 同根、interpolate bilinear 是 #175154 的实例，README 里给了评论稿而非新 issue。本机 `collect_env` 在中文 Windows 上解码失败，用 `scripts/collect_env_safe.py`。已跑完并分诊：decomp 全量 ×2 种子、decomp --grad ×2 种子、metamorphic 全量、binding 全量、max_autotune（GEMM 子集）。仍在后台（中断则同一命令续跑，`--isolate` 的按 JSONL/progress.json 跳过已完成）：

```bash
python run.py metamorphic --isolate --samples 3 --seed 1 --relations config --configs dynamic --chunk-size 20 --out results\meta_dynamic_s1   # dynamic=True × 3 样本
python run.py metamorphic --isolate --samples 2 --seed 2 --relations config --configs max_autotune --chunk-size 20 --out results\meta_autotune_all
python run.py metamorphic --source both --models 30 --max-nodes 12 --relations config,reuse --configs dynamic,no_fusion,no_inplace,no_vec,cpp_wrapper --jsonl results\meta_graph\metamorphic.jsonl --out results\meta_graph   # 150 图 × 13 配置太慢（>10 h），改为 30 图 × 5 配置；JSONL 有进度
python run.py campaign --from-dir reproducers_models --backend inductor --reruns 1 --max-contexts 4 --test-budget 6 --time-budget 300 --isolate --child-timeout 900 --out reports_models   # densenet121 已移入 _skip/
```
跑完后：`results\<dir>\METAMORPHIC.md` 看 violations；`reports_models\SUMMARY.md` 看候选；分诊方法同 §3。

**Kaggle 已自动化（2026-09-10 傍晚）**：`kaggle/drive.py`（`dataset` / `push <job>` / `status` / `log` / `pull` / `wait`）通过 Kaggle API 上传数据集版本、推送 `kaggle/jobs/*.py` 为 script kernel（自动开 Internet/GPU、挂 `chenyuefei/tcc-plan`）、轮询并把输出拉回 `kaggle_out/<job>/`。认证用 `%USERPROFILE%\.kaggle\access_token`（新版 token，`kaggle config view` 能看到用户名）。当前在 Kaggle 上跑着：用户网页起的第 1 项 A/B（`notebook955c6cac50` / `notebookf4aab87efb`，torch 2.10 / 2.14 CPU 各跑一遍 `reproducers_gh`），我推的 `tcc-gpu-sweeps`（第 3 项）和 `tcc-bindinggpu`（第 7 项）；`python kaggle\drive.py wait ...` 在后台（`results\kaggle_wait.log`），完成即拉回。拉回后：第 1 项用 `scripts\build_benchmark.py --old kaggle_out\<A>\plan\reports_gh_cpu_2.10 --new kaggle_out\<B>\plan\reports_gh_cpu_2.14 --verified`，第 3 项用 `decomp_triage.py` / `METAMORPHIC.md` / `AOTI.md` / `binding_summary.py` 分诊，第 7 项看 `SUMMARY.md`。`models` 任务（真实模型 GPU）尚未推，等 GPU 配额。
**第一轮结果（2026-09-10 22:00）**：API 推送的 GPU 任务默认分到 **P100（sm_60）**，torch 2.10+cu128 在它上面"no kernel image is available"，所以 `tcc-gpu-sweeps` 里只有不依赖 CUDA 的 decomp / decomp --grad 两步有效（Linux CPU、torch 2.10：553/558 个算子，分诊结果都是已知族或 2.14 已修的，如 max_unpool2d channels_last #187195、`norm(dim=-1)` 形状 #183121；`pdist` 零行 backward 在 Linux 上也 SIGSEGV），`tcc-bindinggpu` 全部程序 CUDA 失败。已改为 `machine_shape = NvidiaTeslaT4`（`kaggle/drive.py`），重推 `tcc-gpucuda`（只含 metamorphic / aoti / binding 三个 CUDA 步骤）与 `tcc-bindinggpu` v2，`results\kaggle_wait2.log` 轮询。本机真实模型 campaign 跑完：63 个程序、1 候选（FCN 式模型 bf16 autocast 梯度）经 fp32 真值复核为 Invalid，8 个大模型超时未测。
**T4 第二轮（2026-09-11 上午拉回，`kaggle_out/gpucuda/`，torch 2.10.0+cu128）**：
- 配置差分 `gpu_results_meta_cfg`：561 算子、6 455 次编译、9 条违背——8 条 `dynamic=True`（cov #190669、max_pool2d backward #122129、quantile/nanquantile #179383（2.14 已修）、adaptive_avg_pool2d / interpolate / upsample_bilinear 的"cannot determine truth value of Relational"= open #185510 族、combinations r=1）+ **1 条 `cudagraphs`：`x.new_zeros((2,3), device='cpu')`（x 在 CUDA）eager 与默认编译返回 CPU 张量，开 cudagraphs 返回 CUDA 张量**（新线索，待 2.14 验证）。
- 绑定形式 `gpu_results_binding`：357 算子、9 835 次编译、114 条、8 条形式独有：adaptive_avg_pool2d 的 output_size 经参数/闭包/`.item()` 传入成 SymInt 时触发 #185510 类失败（字面量/容器形式正常），max_pool2d backward 同 #122129；rebind 里 `nonzero_static` 改 size、`grid_sampler_2d` 改插值模式后失败，待 2.14 验证。
- AOTI `gpu_results_aoti`：export 544/561 成功，但 AOTI 打包 542 失败——全部是 Kaggle 镜像上 `g++` 编译 CUDA C++ wrapper 的环境错误，不是缺陷；CUDA 上的 AOTI 需要另配工具链，暂放。
- `tcc-gpuverify`（`scripts/verify_candidates_cuda.py`，CUDA + Linux CPU 各跑一遍全部候选与线索 G1–G7）：v1/v2 因 cu128 索引只到 2.11 仍是 torch 2.10，结果已写入各草稿的跨平台段落与 `TO_SUBMIT.md` 待判定表（第 3/4/6 条 CUDA 复现，第 5/8/9 条 CPU 专属，第 7 条 CUDA 正常，第 2 条 Windows 专属，G1 new_zeros/cudagraphs 与 G6 nonzero_static rebind 在 2.10 CUDA 成立）。v3（PyPI 的 torch 2.14.0+cu130，T4 + Linux CPU，2026-09-11 上午）结论：第 3/4/6/10 条 CUDA 复现；第 1 条 Linux g++ 同样失败（`error: invalid type argument of unary '*' (have 'int')`），Triton 正常；第 5/8/9 CPU 专属；第 7 Linux CPU 段错误；第 2 Windows 专属；第 11/12 Linux 复现；G2/G5/G6 已修；**G1 成立 → TO_SUBMIT 第 13 条 / `issues_0910/13-*.md`**。跨平台句子已写进各草稿。另发现绑定变体 campaign 在 `--isolate` 下子进程没收到 `--binding-variants` 参数（T4 上实际跑的是原版 reproducer），已修 `campaign.py` 的透传并重推 `tcc-bindinggpu` v3。v3（T4，2.10）跑了 197 个语料变体（0 候选）与 727 个 issue-reproducer 变体：后者报 40 个"原版没检出、变体检出"的程序，逐条看是 **harness 假象**——变体函数二次 exec 后 `__module__` 指向 reproducer 加载器的合成模块名 `_repro_issue_…`，Dynamo 追踪时 import 失败（`InternalTorchDynamoError: ModuleNotFoundError`），所有形式一起"命中"。已修 `tcc/binding_ast.py`：变体 exec 进注册到 `sys.modules` 的真实模块对象；本机复测无此错误。v4（`--reruns 2`，与原版对照口径一致）已推。教训：变体程序的"全部形式同时命中且原版不命中"是 harness 问题的信号，先看 issue.md 的 Actual 段再下结论。
**v4 结果（T4，2.10，`--reruns 2`，2026-09-11 下午）**：语料 197 个变体 1 133 次测试 0 候选；issue reproducer 720 个变体（108 个 reproducer 无可改写的标量字面量或目标是 nn.Module，跳过）：33 个程序的变体检出与原版一致，2 个"变体独有"（#176599、#182225）但 7 种形式同时命中，与绑定方式无关；**没有任何"仅部分绑定形式检出"的程序**。结论与 OpInfo 扫描一致：2.10/2.14 对绑定形式的处理在真实程序上是一致的，该因子的价值在于精确刻画 #122129 族的触发条件，而不是新缺陷。`kaggle/kernel_log.py` 可单独取内核日志（CLI 要下载完全部文件才写日志）。

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
- `scripts/make_model_reproducers.py` → `reproducers_models/`（73 个文件）：torchvision 14 个小模型（resnet18、mobilenet v2/v3、squeezenet、shufflenet、efficientnet_b0、regnet、mnasnet、convnext_tiny、densenet121、googlenet、小 ViT、小 Swin、FCN 式分割头）× {fp32、channels_last、bf16 autocast、train、dynamic=True} + 5 个 torchvision.ops（roi_align、nms、box_iou、deform_conv2d、StochasticDepth/FrozenBN），随机权重、固定种子、64×64 输入，走 `--from-dir` 录制模式（含 BN 的模块由 `Program.reset` 恢复状态）。本机装了 torchvision 0.29.0+cpu（`--no-deps`，未动 torch）。resnet18 一个程序 4 个上下文约 260 s，整批在后台：`reports_models/`（`--max-contexts 4 --test-budget 6 --time-budget 300`）。Kaggle 打包已包含该目录，`kaggle/campaign_gpu.sh` 新增第 0 步（decomp / metamorphic / binding 三个扫描在 GPU 上）和第 2 步（真实模型）。**GPU 结果（`tcc-models`，T4，torch 2.10.0+cu128，2026-09-11，`kaggle_out/models/plan/gpu_reports_models/`）**：68 个程序、237 次测试、**0 候选**，3 个 swin 变体超时（1 200 s）。加上本机 CPU 的 63 个程序（1 候选、复核为 Invalid），真实模型这条线在 2.10 GPU / 2.14 CPU 上都没有产出——小型 torchvision 模型上 eager/compile 一致性已经很好，缺陷集中在算子边角输入与非默认配置。

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

### 3.N nightly 复核（路线 C 第一步，2026-09-12 起）

- 目的：提交 issue 前确认 13 条候选在 main（nightly）上是否仍在；同时为版本差分（2.10 → 2.14 → nightly）补上第三个点。
- 任务：`kaggle/jobs/nightlycpu.py`（nightly CPU 轮子：verify_candidates cpu + decomp 差分 fwd/grad 各一轮）、`kaggle/jobs/nightlygpu.py`（nightly cu130，T4：verify_candidates cuda + cpu）。
- `tcc-nightlygpu` 结果（2026-09-12，torch 2.15.0.dev20260911+cu130，git fb8ff0f1，T4 + Linux CPU；日志 `kaggle_out/nightlygpu.txt`）：**13 条全部仍在 main 上**，现象与 2.14 一致；第 2 条（Windows 专属）改查 main 源码，`cpp_bmm_template.py` 仍缺 `{{export_declaration}}`。已把 "Still present on nightly" 句写进 13 条草稿、`issues_0910/README.md`、`TO_SUBMIT.md`。
- `tcc-nightlycpu` 结果（nightly CPU，verify 同上；decomp fwd 576 算子 108 分歧、grad 574 算子 128 分歧，各 1 样本；`kaggle_out/nightlycpu/plan/nightly_results_decomp*/`）。与本机 2.14 两个种子按 (op, variant, kind) 集合比对（`scripts/nightly_decomp_diff.py`）：nightly 独有 fwd 3 条、grad 6 条，其余差异都是采样数不同（2.14 跑了 2 样本）或旧 harness 的 TypeError 假象。逐条判定：int64/bool 输入 eager NotImplementedError 而 compile 正常（mse_loss、linear_cross_entropy、batch_norm、celu、group/layer_norm）= 已记录不报的一族；celu nan_inf 梯度 NaN 模式 = 已记录的语义争议族；pinv bool meta = eager 自身报错。真正的新线索两条：
  - `nn.functional.nll_loss` channels_last 4-D 输入反向：eager 抛 `grad_input must be contiguous`，Inductor 正常。本机 2.14 与 Windows nightly（`../venv_nightly`，2.15.0.dev20260911+cpu）都复现 → 不是 nightly 独有，是 2.14 采样没抽到 4-D 样本。查重：#175084 同一缺陷，修复 PR #175246 被 revert 后 stale 关闭 → Duplicate，记入 TO_SUBMIT 不提交表。
  - `quantile` prime_dim0 (7,2,1,2) 反向：Linux nightly 上 compiled 梯度误差 0.75、eager 0（confirmed）。本机 2.14 与 Windows nightly 上遍历全部 46 个 OpInfo 样本（`scripts/diag_nightly_grad_leads.py`）及 harness 同参数（`results/nightly_lead_quantile_win`）都 0 分歧；Linux nightly 上诊断脚本也 0 分歧。可疑来源：PR #188394（2026-07-25 合并，2.14 之后）把 CPU quantile 改为 nth_element 部分选择，作者自述"值有重复时梯度归属可能不同"。`tcc-nightlylead` v2：Linux nightly 上 seed 0 稳定复现（samples 1 报 nanquantile、samples 2 报 quantile、isolated 复跑再报 quantile），seed 1 不报。原因查清：`prime_dim0` 变体用 `resize_dim` **平铺**放大维度 → 输入带并列值；用刻意构造的并列值输入（`scripts/diag_quantile_ties.py`，自包含 Kaggle 任务 `tcc-nightlyties`）在 **Linux 2.14.0 与 nightly 都复现、Windows 两版都不复现**：eager 把并列 quantile 的梯度给 index 0，compile 给 index 2（全等输入 keepdim：最后一行 vs 第 3 行）。与 PR #188394 无关（2.14 也有），是 sort 并列次序的平台差异；任一并列元素都是合法次梯度，PyTorch 不承诺 → 判定不报，记入 TO_SUBMIT 待判定表。顺手修了 `run.py`：`--isolate` 之前忽略 `--only`（v2 的 isolated 复跑因此跑了全部 574 个算子）。
- 本机新增 `..env_nightly`（Windows，torch 2.15.0.dev20260911+cpu，装了 numpy/expecttest/hypothesis）：用 `..env_nightly\Scripts\python.exe run.py ...` 可直接在本机 nightly 上复核。已用它跑 `scripts/verify_candidates_cuda.py cpu`（`results/nightly_verify_windows.txt`）：Windows nightly 上第 1–12 条全部复现，第 2 条（bmm max_autotune，Windows 专属）也复现。至此 13 条候选在 2.14（Win/Linux/CUDA）与 nightly（Win/Linux/CUDA）上都已复核。

### 3.O 第二轮换角度（NEXT_DIRECTIONS §6，2026-09-12 晚开始；用户指示"先不提交草稿，继续按照新思路挖掘"）

| 角度 | 实现 | 状态 / 结果 |
|---|---|---|
| 6.3 新变体 `dtype_complex64` / `large_reduce` / `large_reduce_bf16` | `tcc/decomp_diff.py::_variants` | fwd 全量完成（561 算子，1918 变体，21 分歧，63 分钟）：`dtype_complex64` 的 25 条全是 "eager 无复数内核抛 NotImplementedError/RuntimeError、分解正常算出"（isin、norm 族、interpolate、max_unpool、losses、nansum/nanmean）= 已判不报的一族；`large_reduce` 在分解差分里 0 分歧（归约由 Inductor 直接 lowering，不经分解，所以这里测不到——真正的累加测试是下一行的脚本）。grad 版完成（552 算子，24 分歧）：除已知一族外，**`linalg.pinv` dtype_complex64 梯度错 0.10（confirmed）→ 第 24 条**；`max_pool1d` 的 `module 'torch._inductor' has no attribute 'lowering'` 是 harness 子进程 import 顺序假象 |
| 6.3 大归约累加扫描 | `scripts/large_reduce_sweep.py`（31 算子 × 9 组值 × 3 dtype，N=1e5，eager vs compile vs fp64） | 837 例 26 flag：**var/std 家族在均值 1e5 数据上误差 3e-3 vs eager 5e-8**（并入第 5 条草稿），1e18 溢出 / 1e-30 下溢（第 5 条已有），fp16 prod 累加 |
| 6.2 dtype 提升矩阵 | `tcc/dtype_matrix.py`，`run.py dtypes`（72 算子 × 8 dtype² × 4 形式，只比 dtype/形状/是否抛错） | aot_eager 全量 17664 例：0 dtype 分歧、18 raise 型（全是死代码 DCE 机制，不报）、2375 异常类型包装（噪声）。Inductor 版在 Kaggle（`tcc-dtypesgpu`：CUDA 全对 + autocast + Linux CPU 低精度对）跑；本机 inductor 冒烟复现第 8 条并多出 fp16×fp64→float64 |
| 6.1 Inductor 配置开关 | `tcc/metamorphic.py::config_sets` +14 个开关 | Kaggle `tcc-knobscpu`（Linux CPU，torch 2.14）完成：OpInfo 593 算子 × 20 个配置 = 11765 次编译，**0 违例**（`kaggle_out/knobscpu/plan/knobs_opinfo/METAMORPHIC.md`）。多算子程序那一步因 `--isolate` 吞掉了 `--source both`（已修 run.py），实际又跑了一遍 OpInfo；本机排队的 `results/knobs_local`（source both，40 个 NNSmith + 语料）会补上。**6.1 在单算子层面是负结果**：冷门 codegen 开关没有改变任何 OpInfo 算子的输出 |
| 6.4 编译的 optimizer.step 差分 | `scripts/optimizer_step_diff.py`（11 个优化器 × 各自标志 × foreach/fused × 6 种参数集，3 步，比较参数与状态） | 全量完成（`results/optim/OPTIM.md`，1584 个配置）：只有两类 flag——**23** SGD `foreach=True` + 复数参数 Inductor 断言失败（eager/aot_eager 正常，nightly 同）；Adam/AdamW `capturable=True` 在 CPU 上 eager 断言、compile 照跑（校验被绕过，不报，待判定表）；其余 11 个优化器 × 标志 × foreach/fused × 6 种参数集的参数与状态全部一致（bf16/fp64/复数/grad=None/标量参数） |
| 6.5 0/1 特化 + 环境标志变化后复用 | `scripts/reuse_env_diff.py`（20 个程序 × dynamic {F,T,None} × batch {0,1,2,5}；20 个环境翻转：autocast、grad mode、default dtype、deterministic、flush_denormal、线程数、mkldnn、全局常量、train/eval、buffer/param 外部修改、inference_mode、matmul precision、输入布局/dtype 切换） | 完成（`results/reuse_env/REUSE_ENV.md`，260 项检查，5 分钟）：21 条 flag 全是假象或已知——NaN 比较未按 nan==nan 处理（已修）、异常类型包装、autocast 下 bf16 舍入差 2 ulp、`m.train()` 后 dropout 掩码不同与 `manual_seed` 后 `torch.rand` 不同（编译版用 Inductor 自己的 RNG，文档已注明，`fallback_random=True` 才逐位一致）。**0/1 特化（batch 3 编译后喂 0/1/2/5，三种 dynamic 设置）与 20 种环境翻转都没发现真分歧** → 6.5 负结果 |
| 6.7 PR 驱动差分 | `scripts/pr_driven_diff.py`：GitHub commits API 取最近 N 天改 `aten/native`、`_decomp/_refs`、`_inductor/lowering|codegen`、`_dynamo/variables`、`optim` 的提交，标题里的算子名 ∩ OpInfo，过滤 MPS/ROCm/XPU；输出 `results/pr_ops.json` 与下一步命令 | 10 天：122 个提交、26 个算子名。值得盯的 CPU 相关提交：#196371（Inductor 大内层循环归约改标量累加器 → 用 nightly 重跑 `large_reduce_sweep`，`results/pr_large_reduce_nightly`）、#192025（向量化整数 remainder 尾块除数）、#194077（nD linear 走 `_unsafe_view`）、#196658（matrix_exp 系数修正）。nightly 结果：`large_reduce_sweep` 与 2.14 完全相同的 26 条 flag（#196371 没改变 var/std 家族的累加行为，第 5 条含均值 1e5 的例子在 nightly 仍在）；14 个算子的 metamorphic config 504 次编译 0 违例；decomp --grad 只有已知一族（int64/bool、pad 的 meta 步长 channels_last vs 真实——直接测 pad 各模式编译输出步长与 eager 一致，仅 FakeTensor 步长不同，不报） |
| 6.3′ 复数输入梯度全量扫描（由第 24 条推广） | `scripts/complex_grad_sweep.py`：所有支持 complex64 自动求导的 OpInfo 算子 × 3 样本，eager vs aot_eager vs complex128 真值（不编 C++，几分钟） | 完成（`results/complex_grad/COMPLEX_GRAD.md`）：只 flag `linalg.pinv`、`pinverse`、`linalg.matrix_sqrth` → 第 24 条扩成两个算子；其余复数算子的反向在 AOTAutograd 下都对，说明是这两条反向公式（都含 `.mH`→`_conj`）追踪的问题，不是复数自动求导整体 |
| 6.4b compiled_autograd 差分 | `scripts/compiled_autograd_diff.py`：前向 eager，反向图由 `torch._dynamo.compiled_autograd._enable(torch.compile(backend=aot_eager))` 编译；所有 float32 自动求导 OpInfo 算子各 1 样本，比较输入梯度 | 完成（`results/compiled_autograd/COMPILED_AUTOGRAD.md`）：数值上无分歧；**25** `F.interpolate` 的 bilinear/bicubic/linear/trilinear 反向在 compiled_autograd 下 `isIntList() INTERNAL ASSERT`（nearest 正常，2.14 + nightly）；其余 flag 是多输入列表算子的 harness 假象（`inputs` 为空）与 sparse |
| 第三轮（§6.10 末尾，2026-09-13 起） | (A) `scripts/unary_dtype_sweep.py`：一元算子 × 8 dtype × {plain, autocast bf16, out= 另一 dtype}，Inductor；(B) `scripts/double_backward_sweep.py`：二阶导；(C) `scripts/forward_ad_sweep.py`：`torch.func.jvp` 经编译算子 | (A) 完成（`results/unary_dtype/UNARY_DTYPE.md`，~100 一元算子 × 8 dtype × {plain, autocast, out=} ≈ 2000 例）：0 条纯 dtype 分歧（autocast 下也无）；raise 型除已知"eager 无 int/bool 内核、compile 经分解正常"一族外有 3 条：**26** bitwise_not/and/or/xor 对 float 返回垃圾（#144247 部分重复→评论）、**29** `nan_to_num(complex)` Inductor 编译失败（isneginf 不支持复数）、**30** `abs(complex, out=float64/bf16)` compile 拒绝 eager 接受的 out dtype；(B) **不适用**：`torch.compile` + aot_autograd 明确不支持 double backward（RuntimeError 有说明），不是缺陷；(C) 完成（`results/forward_ad/FORWARD_AD.md`，507 算子，`compile(jvp(f))` 形式——`jvp(compile(f))` 不会触发编译）：数值 0 分歧；**27** `ldexp` 的 jvp 在 aot_eager 下进程 access violation（两次让全量扫描无声退出，`--skip ldexp` 后跑完）；**28** `quantile(q tensor)` 三后端、`addr/quantile/nanquantile` eager 后端 `_make_dual` INTERNAL ASSERT（Linux 上三后端全断言）。复数输入版（`--dtype complex64`）：只有 addr 同一断言，无新发现。(D) `scripts/vmap_sweep.py`：`compile(vmap(f))` vs eager vmap vs 循环真值：678 算子（481 可批处理）0 分歧、0 异常 → 负结果 |
| 6.6 Dynamo Python 语义差分 | `tcc/dynamo_semantics.py`（77 个小程序），`run.py dynsem` | 13 秒跑完，8 条分歧 → **2 条真缺陷**：(14) `random.shuffle/sample` 每次调用同一结果；(15) 函数内 `random.seed` 首调用不生效。另 numpy 标量→ndarray（设计限制）、异常类型包装（噪声）。Linux 复核 `tcc-randomlinux` 在跑 |

新增候选（2026-09-12 晚，全部未提交，草稿在 `issues_0910/14–21`）：
- 14 `random.shuffle/sample` 编译后每次调用同一结果（根因：`RandomVariable.shuffle/sample` 在追踪时算好置换当常量，无运行时回放）；15 函数内 `random.seed` 首调用不生效。2.14 + nightly，Windows + Linux（`kaggle_out/randomlinux.txt`）。
- 16 `dynamic=True` 下 f-string 格式说明符作用于 SymInt/SymFloat → InternalTorchDynamoError（Win Py3.14 + Linux Py3.11 都复现）；17 `dynamic=True` 下含张量的 namedtuple `==` → RecursionError（**只在 Python 3.14**，Linux Py3.11 不复现）。`dynsem --dynamic` 发现。
- 18 `torch.ldexp` Inductor 输出 dtype 双向错（来源 PR #171721 原生 lowering）；19 `huber_loss` 混合低精度 → Inductor float32（并入第 8 条草稿）；20 `lerp(bool, bool, 0-d weight)` Inductor 编译失败；21 `sum(half, dtype=bool)` C++ 编译错 / `prod(dtype=bool)` 断言。dtype 矩阵 Inductor 版（Kaggle T4 CUDA 9344 例 + autocast 1825 + Linux CPU 4088 例）+ 本机/Windows nightly 复核；`kaggle_out/leadslinux.txt` 为 Linux 2.14 + nightly 复核。
- 6.6 第三批 34 个程序（`tcc/dynamo_semantics_batch3.py`，共 185 个）：只有 `__torch_function__` 子类被额外调用（追踪副作用，不报）与 `threading.local` 的 repr 假象，无新缺陷 → Dynamo 语义差分三批共 5 条真缺陷后趋于饱和。
- 6.6 第二批 74 个程序（`tcc/dynamo_semantics_more.py`，共 151 个，静态 15 条 / dynamic 21 条分歧）：新增真缺陷 1 条（22：完整追踪时 `str(KeyError(...))` 丢引号）；其余是 numpy 标量→ndarray（已知）、异常类型包装（噪声）、`deepcopy_module_state` 的浮点相等误报。dynamic 独有的 6 条都是 16/17 的重复入口。
- 查重：`results/dedup_0912.txt`，均无同报告。
- 不报（待判定表）：numpy 标量→0 维 ndarray（设计限制）、masked_fill(bool, complex) eager 过宽松、死代码 DCE 吞掉报错、eager 无 bool/half 内核而 compile 正常的 ~30 组 raise 型差异（老结论）。
复现脚本：`reports_dynsem/random_module/minimal_verified.py`、`scripts/diag_random_compile.py`、`scripts/diag_dynsem_leads.py`、`scripts/diag_dynamic_fstring_namedtuple.py`、`scripts/diag_dtype_leads.py`。

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
2. §21 历史基准：**2026-09-10 已用现有数据填了第一版**（`scripts/build_benchmark.py`）——同一批 `reproducers_gh/` 在 2.10.0+cu128（Kaggle）与 2.14.0+cpu 上的检出结果做交集：160 个两版本都跑过的程序里，26 条"closed、2.10 检出、2.14 未检出"作为 buggy/fixed 对（`Kind: fixed`），10 条 open 且两版都检出作阳性对照（`present`），17 条只在 2.10/CUDA 检出的 open issue 单列（`device?`）。`Verified` 全为 false：两次运行的设备不同（cuda vs cpu），严格的同设备版本对要在 Kaggle 上用 2.10 与 2.14 的 CPU 轮子各跑一次（`RUN_ON_KAGGLE.md`）。**同设备版本对（2026-09-11）**：用户在 Kaggle 上用同一 Linux CPU 镜像分别装 torch 2.10.0+cpu 与 2.14.0+cpu 跑同一批 `reproducers_gh/`（193 个程序；2.10：open 32/70、closed 50/123；2.14：open 29/70、closed 16/123）。`build_benchmark.py --old ... --new ... --verified` 重建：**35 条 buggy/fixed 对（Verified=true）**、26 条两版都检出的 open issue、6 条只在 2.10 检出的 open issue（`old-only`，可能已在 2.14 修但 issue 未关，待人工核）。原始报告在 `kaggle_out/chenyuefei_notebook{f4aab87efb,955c6cac50}/plan/reports_gh_cpu_*/`（只拉了汇总与 JSON；逐条记录目录因 CDN 断连未全部下载）。
（此前 cuda-vs-cpu 版本的说明保留于下。）修复提交用 `fix_in_release.py` 查（`benchmark/fix_status_2.14.json`）：26 条中 8 条的关闭提交确认在 v2.14.0 内（最硬的 buggy/fixed 对），17 条 issue 是被 PR 引用/手工关闭、关闭事件上没有提交（需人工从 PR 找），1 条（#193661）关闭提交不在 2.14 内却在 2.14 上未检出——要么是 CUDA 专属、要么我们漏检，标为待查。
3. 最小化器在真实候选上验证（目前只在注入缺陷上跑过 `--minimize`）。
4. 有 GPU 时：E4（Inductor+Triton）层、Triton `@triton.jit`/TileLang 执行路径（现在只有边界识别）。
5. 外部基线：安装 TorchProbe/FreeFuzz/TitanFuzz 后用 Setting B 接口比较；或用它们的产出目录跑 `--external`。
6. 论文写作时把本文件 §3 的表按 §25 的指标名（BugDetectionRate / TestEfficiency / TTF）重排。

> 2026-09-08 上午另起一轮：`--opinfo 703 --seed 2` 全算子 OpInfo campaign 在后台运行，日志 `results/rq5_opinfo_all.log`，报告 `reports_opinfo_all/`（约 1 小时；用 `python run.py campaign --status <sig>=<Status> --out reports_opinfo_all` 维护台账）。
