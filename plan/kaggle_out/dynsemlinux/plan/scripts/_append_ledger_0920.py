"""One-off: append the 2026-09-20 candidates to TO_SUBMIT.md (kept for the record)."""
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
p = os.path.join(ROOT, "TO_SUBMIT.md")
s = open(p, encoding="utf-8").read()
if "## 2026-09-20 第四/五轮新增" not in s:
    s += """

## 2026-09-20 第四/五轮新增（提交稿在 `../0920issues/`，README 有提交顺序；全部**未提交**，由用户手工提交）

| # | 发现 | 版本 | 状态 | 提交稿 | 查重 | 备注 |
|---|---|---|---|---|---|---|
| 31 | **Inductor 下 autograd 的"反向需要的张量被原地修改"检查丢失 → 静默错梯度**：`out = compiled(x, w)`（`x @ w`、`bmm`、`einsum`、3 维 `F.linear`、`matmul`、`addmm`、`x[0] * p`、attention 式）之后 `x.add_(1)` 再 `backward()`：eager / backend=eager / aot_eager / aot_eager_decomp_partition 都抛 "modified by an inplace operation"，**Inductor 不抛并返回用改后的 x 算的梯度**（误差 1–4）。`x.t() @ p`、`x * p`、2 维 linear、conv2d、MLP 正常报错 | 2.14.0+cpu 与 nightly（Win）；Linux CPU 2.14.0 + nightly dev20260919；T4 CUDA 2.14.0+cu130（`kaggle_out/savedviewlinux.log`、`savedviewgpu.log`），12 个变体的表四个环境完全相同 | **待提交（高：静默错梯度）**（8.1 第二批 `error_parity_batch2.py` 的 `saved_input_modified_before_backward`） | `0920issues/01-*.md`；`reports_validation/saved_tensor_mutation.py`、`saved_view_variants.py` | 无同报告（4 组关键词）；#113737、#158561 相关但不同 | 根因实测：前向图把输入的**视图**（`permute(primals_1)`）存给反向；aot_eager 下存的张量与 x 共享版本计数器（`x.add_` 后 `_version` 1/1），Inductor 下同存储但版本计数器独立（1/0）。修复建议三选一写在草稿里 |
| 32 | **torch._numpy 值错**：`np.fix(1.5)=2.0`（`round as fix`）、`np.cbrt(-8)=nan`（`pow(x,1/3)`）、`np.clip(int8,-1000,1000)` 全为 -24 / `np.clip(uint8,-2,5)` 全为 5（Python 边界被转成数组 dtype）、`np.sign(nan)=0`、`np.heaviside(nan,h)=0` | 2.14.0 + nightly（Win），backend=eager 即可 | **待提交（中–高）**（§9 跨目标 `xtarget_numpy_diff.py --target dynamo`） | `0920issues/02-*.md`；`reports_xtarget/dynamo_numpy_semantics.py` | 无同报告；同类已被接受：#195978、#194866 | 每条根因一行，修复写在草稿表里 |
| 33 | **torch._numpy dtype/形状**：`np.cumsum/cumprod(int8)` 不提升而溢出、`np.square/reciprocal(int)`→float64（被列在 `_fp_unary`）、`int8/int8`→float32、`np.sum(uint8)`→int64、`np.any(uint8)`→uint8、`np.median/percentile/quantile` 形状 (1,)、uint16/32/64 运算 NotImplementedError | 同上 | **待提交（中）** | `0920issues/03-*.md` | 无同报告 | `numpy_default_float` 默认 float64，不是它造成的 |
| 34 | **#197554 "[PT2] Validation lost" 的评论**：方法（error_inputs 过编译路径，916 例，20 条校验丢失）+ 10 个新成员：`index_add` source 形状不符被 Inductor 广播、`index_copy` 负索引、`bce` 输入越界→nan、`repeat_interleave(output_size=错)`、`softmax(int64)`→全 0、`layer_norm` float64 权重、`one_hot(float)`、`int64.mul_(float)`、`float.add_(1j)` 丢虚部、`take(out=重叠)` | 2.14.0+cpu | **待评论（高：维护者点名要这个扫描；成员表里已有用户的 #197095）** | `0920issues/04-*.md`；`reports_validation/validation_lost_members.py` | 已排除已有成员 #169779、#185885、#197095；#121135 只覆盖 randperm 模式 | 先提交 31，再把编号填进评论末句 |
| 35 | **JAX：`jnp.gcd` / `jnp.lcm` 遇整型最小值永不返回**（eager 与 jit 都是；`(-128, 6)`、`(6, INT64_MIN)` 等；另一参数为 0 时正常） | jax 0.11.2 CPU（Win）；Linux 复核 `tcc-xtargetlinux` | **待提交到 jax-ml/jax（中–高）** | `0920issues/05-*.md`；`reports_xtarget/jax_gcd_intmin_hang.py` | jax 仓库无同报告（#11378、#12728 不同） | 根因：`abs(INT_MIN)` 仍为负，循环末尾的大小交换使状态在 (-2,0)/(0,-2) 间振荡 |
| 36 | **Numba：`np.remainder/np.mod/np.divmod` 在 `MIN_INT % -1` 上杀死进程**（0xC0000095；四种有符号 dtype；`a % b` 正常）；`np.floor_divide(MIN_INT,-1)`=0（NumPy 为 MIN_INT） | numba 0.67.0 / numpy 2.5.3（Win）；Linux 复核同上 | **待提交到 numba/numba（高：硬崩溃）** | `0920issues/06-*.md`；`reports_xtarget/numba_intmin_remainder_crash.py` | numba 仓库无同报告；`np.fmod` 整数错 = #8574 重复、median NaN = #10095、clip NaN = #9995 | 根因：`np_int_srem_impl` 只防除数 0，缺 `(MIN_INT,-1)` 判断（`np_int_sdiv_impl` 有） |

本轮查重后不报的（重复）：`index_select` 负索引 #169779；`index_add` 负索引 #185885；eager `div(trunc)` INT_MIN 崩溃 #138425；eager `lcm` 崩溃 #121343 / `gcd` 负值 #187338。JAX 的 jit-vs-eager 一致性在 268 个程序上除第 35 条外干净（负结果，可写进论文外部效度）。
"""
    open(p, "w", encoding="utf-8").write(s)
    print("ledger appended")
else:
    print("already appended")
