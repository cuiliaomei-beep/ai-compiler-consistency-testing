# 待提交清单（RQ5，计划 §18.6：人工审核后才提交）

| # | 发现 | 版本 | 状态 | 提交稿 | 查重 | 备注 |
|---|---|---|---|---|---|---|
| 1 | `torch.var_mean` / `torch.std_mean` 对空张量在 Inductor 下返回 `(nan, 0.)`，eager/aot_eager 为 `(nan, nan)`（mean 分量错误，inductor_codegen）；覆盖 correction=1/0、fp32/fp16、形状 (0,)/(0,1)、dynamic 开关 | torch 2.14.0+cpu | **待提交**（用户 2026-09-08 决定暂不提交） | `reports_opinfo_all/0211b330cc67/ISSUE_FINAL.md` | 非重复；相关 #113167（已关闭，不同情形）、#61901、#191229 | 已手工验证 `minimal_verified.py`；第 4 轮四个上下文 2/2，第 6 轮 std_mean/var_mean 共 5 个程序再次命中 |

提交时：把 `ISSUE_FINAL.md` 粘到 pytorch/pytorch 的 issue tracker，然后

```bash
python run.py campaign --status 0211b330cc67=Submitted --out reports_opinfo_all
```

之后在本表登记 issue 编号，并随开发者回复更新为 Confirmed / Fixed / Duplicate / Invalid。

## 待人工复核后决定（第七轮：已关闭 issue 在 2.14.0 上仍复现）

| issue | 现象（2.14.0+cpu） | 关闭情况 | 建议 |
|---|---|---|---|
| #177821 `[inductor] torch.compile ignores a complex indexing assignment` | issue 自带脚本原样复现：整数输出精确不等（`out1=[[2,2],[10,10]]` vs `out2=[[4,0],[12,8]]`） | 2026-05-06 关闭为 completed，**无评论、无关联 PR/提交** | 最值得跟进：评论请求 reopen，附 2.14.0 复现 |
| #176679 tensor subclass `__torch_function__` 结果错误 | aot_eager/inductor 抛 `TypeError`，eager 正常 | 2026-03-11 关闭，仅有"能复现，待定优先级"评论 | 复核后评论 reopen |
| #174386 `use_deterministic_algorithms` 下 `empty_like` 未填 NaN | 复现 1/2 次 | 修复提交在 2.14.0 内 | 多次运行确认稳定性后再定 |
| #184405 dtype 切换后返回过期 float32 | 复现 1/2 次 | 修复提交在 2.14.0 内 | 同上 |
| #182131 fp16 cast 前后数值差 3.9e-4 | 2/2 复现，误差小 | 修复提交在 2.14.0 内 | 可能是修复只缩小而未消除差异；对照 PR 判断 |

## 不提交的（已查重或判为无效）

| 发现 | 结论 |
|---|---|
| `torch.cov(x, aweights=w)` + `dynamic=True` 追踪失败 | Duplicate：PR #190669 正在修（`reports_opinfo/7972f93b54ff/DEDUP.md`） |
| `soft_margin_loss` fp16 eager `inf` vs Inductor 有限值 | Invalid：eager 溢出，编译结果更接近 fp64 真值 |
| `new_empty` / `new_empty_strided` 值差异 | Invalid：未初始化内存，比较无意义 |
| `aten.max_pool2d_with_indices_backward` + `dynamic=True`：来自函数参数的 int 成为 SymInt，`int[2]` 形参拒绝 SymInt 标量 | Duplicate / 相关 #122129（open，同一错误类）；已验证 `reports_opinfo_all/6468272fac80/minimal_verified.py` |
| `F.multi_margin_loss` float16 CPU：eager 抛 `NotImplementedError`（Half 无 CPU kernel），aot_eager/inductor 经分解正常返回 | Duplicate / #144362 的实例（open："compile 缺少 eager 有的 dtype 检查"）；`reports_opinfo_s3/11ddea7fd13c/DEDUP.md` |
| `F.hinge_embedding_loss(reduction='sum', margin≈8.4)`：编译误差 1.1e-6 vs eager 1.8e-7 | Invalid：求和重结合的 1 ULP 级差异，PyTorch 自己的 `same(fp64_ref)` 判为可接受；oracle 已加该否决 |

## 待判定

（无）
