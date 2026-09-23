<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 20 条：在 #185337 下的**评论稿**（请求 reopen）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/185337 （"[inductor] CPU codegen does not preserve explicit float32 to float16 to float32 cast semantics"，2026-06-02 以 **completed** 关闭） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/185337#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | issue 已 **closed（completed）但未锁定**（2026-09-21 核对），关闭的 issue 照样可以评论；你不是原作者，页面上不会有 Reopen 按钮，所以稿子最后一句是请维护者 reopen。① 登录 GitHub 后打开上面的提交网址（`#new_comment_field` 会直接跳到页面最底部的评论框；没跳的话手动滚到底，找 “Add a comment”）；② 评论框保持在 **Write** 页签，把本文件 `## Comment` 标题**下面**到文件末尾的全部内容原样粘贴进去（不要带 `## Comment` 这一行，也不要带上面这张表）；③ 点 **Preview** 看一眼：代码块、输出块、行内代码都应正常渲染；④ 点绿色的 **Comment** 按钮。评论没有标题、标签、模板字段，不需要填别的；⑤ 发出后点评论右上角的时间戳，复制地址栏里形如 `…/issues/NNNN#issuecomment-XXXXXXXX` 的链接，填到 `README.md` 对应行的“状态”列。 如果一两周没人理，再考虑把同样内容作为新 issue 提交并在正文里引用 #185337。 |
| 为什么是评论 | 同一缺陷；issue 已关闭为 completed，但在其后发布的 2.14.0（2026-09-02）与 nightly 上，用比原报告更简单的复现（没有归约）仍然存在 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu，Windows x64；Linux 复核（Kaggle，`plan/kaggle_out/intublinux.log`、`intubgpu.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 输出相同；**CUDA（T4，2.14.0+cu130）上同样被消掉**（`[0.1, 70000.0]` 原样返回）；`aot_eager` 与 eager 一致 |
| 证据包 | `plan/reports_intub/inductor_value_leads.py`（`x.half().float()`、`x.bfloat16().float()` 两项）；发现来源 `plan/scripts/int_ub_sweep.py`（`float_unary:cast_half_back`：120 个边界值里 54 个不同） |
| 备注 | 若维护者回复"用 `emulate_precision_casts`"：那个开关针对的是融合后中间量的精度，这里是用户**显式写出**的往返转换，且连 `70000 → inf` 的溢出都被消掉，属于语义改变 |

---

## Comment

This still reproduces on the 2.14.0 release and on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), with a smaller program than the one above: no reduction is needed, the explicit round trip alone is dropped. It is not limited to the CPU backend either: on CUDA (Tesla T4, 2.14.0+cu130) `torch.compile(lambda t: t.half().float())` returns `[0.1, 70000.0]` unchanged where eager returns `[0.09997558, inf]`.

```python
import torch

x = torch.tensor([0.1, 0.001, 1 / 3, 70000.0])
for name, fn in (("x.half().float()", lambda x: x.to(torch.float16).to(torch.float32)),
                 ("x.bfloat16().float()", lambda x: x.to(torch.bfloat16).to(torch.float32))):
    torch._dynamo.reset()
    print(f"{name:22s} eager    {fn(x).tolist()}\n{'':22s} inductor {torch.compile(fn)(x).tolist()}")
```

```
x.half().float()       eager    [0.0999755859375, 0.0010004043579101562, 0.333251953125, inf]
                       inductor [0.10000000149011612, 0.0010000000474974513, 0.3333333432674408, 70000.0]
x.bfloat16().float()   eager    [0.10009765625, 0.00099945068359375, 0.333984375, 70144.0]
                       inductor [0.10000000149011612, 0.0010000000474974513, 0.3333333432674408, 70000.0]
```

The compiled function returns its input unchanged: the float16 rounding, the bfloat16 rounding, and the float16 overflow of `70000.0` to `inf` are all gone. `backend="aot_eager"` matches eager, so the pair of casts is removed in Inductor. Programs use this round trip deliberately to emulate reduced precision (quantization-aware code, numerics tests), so the result is a silent semantic change rather than a precision difference. Could this be reopened?
