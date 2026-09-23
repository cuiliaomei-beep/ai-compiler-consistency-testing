<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 30 条：在**自己的** #198071（clamp 的 Python 边界越界回绕）下的补充评论：`F.pad(..., value=)` 的填充值同样回绕

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/198071 （你 2026-09-22 提交的 21：`clamp(int8_tensor, -1000, 1000)` 得 -24） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/198071#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | ① 打开提交网址，滚到底部评论框；② **Write** 页签粘贴本文件 `## Comment` 下面到文件末尾的全部内容；③ **Preview** 检查；④ 点 **Comment**；⑤ 点评论时间戳，把 `…#issuecomment-…` 链接贴给我登记。 |
| 为什么是评论 | 同一机制（Python 标量按目标 dtype 转成 C++ 常量时截断/回绕，eager 的 `value cannot be converted to type X without overflow` 校验丢失），入口从 `clamp` 的边界换成 `constant_pad_nd` 的 `value`；放同一 issue 下便于一起修 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；`aot_eager` 与 eager 一致 |
| 提交前查重 | 2026-09-22：`constant_pad_nd value overflow uint8 compile`、`pad value out of range dtype inductor wraps`：无同报告 |
| 证据包 | `plan/reports_pairs/dtype_not_implemented_lost.py`（最后三例）；发现来源 `plan/reports_pairs/lowering_vs_decomp_special_cases.py`（12.1） |
| 优先级 | 低–中（补充信息） |

---

## Comment

The same wrap happens for the fill value of `F.pad` / `constant_pad_nd`, which is another Python scalar that Inductor bakes into the kernel as a constant of the tensor's dtype (torch 2.14.0 and nightly; `aot_eager` raises like eager):

```python
import torch, torch.nn.functional as F

u8 = torch.tensor([1, 200, 3], dtype=torch.uint8); i8 = torch.tensor([[1, -2], [3, 4]], dtype=torch.int8)
for name, fn, x in (("F.pad(uint8, (1, 1), value=-1)", lambda x: F.pad(x, (1, 1), value=-1), u8),
                    ("F.pad(int8, (1, 0), value=300)", lambda x: F.pad(x, (1, 0), value=300), i8)):
    torch._dynamo.reset()
    try:
        e = f"returns {fn(x).tolist()}"
    except RuntimeError as ex:
        e = f"raises RuntimeError: {str(ex)[:55]}"
    print(f"{name:32s} eager    {e}\n{'':32s} inductor returns {torch.compile(fn)(x).tolist()}")
```

```
F.pad(uint8, (1, 1), value=-1)   eager    raises RuntimeError: value cannot be converted to type uint8_t without overf
                                 inductor returns [255, 1, 200, 3, 255]
F.pad(int8, (1, 0), value=300)   eager    raises RuntimeError: value cannot be converted to type int8_t without overfl
                                 inductor returns [[44, 1, -2], [44, 3, 4]]
```

So the check belongs where the scalar is converted, not in `clamp` alone: every lowering that turns a Python number into `ops.constant(value, dtype)` for an integer dtype could verify `iinfo(dtype).min <= value <= iinfo(dtype).max` (a compile-time check, since the value is a constant) and raise the same error as eager.
