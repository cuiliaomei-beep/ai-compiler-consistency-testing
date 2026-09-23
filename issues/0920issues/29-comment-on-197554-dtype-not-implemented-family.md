<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 29 条：在 #197554（☂️ Validation lost）下的**第三条评论**（"该 dtype 在 eager 里未实现"这一族：`round(int, decimals)`、`ceil/floor/trunc/round(bool)`、`glu(int8)`、`adaptive_max_pool2d(int8)`）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/197554 （malfet 的伞形 issue；你已发过 04、22 两条评论） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/197554#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | ① 打开提交网址，滚到底部评论框；② **Write** 页签粘贴本文件 `## Comment` 下面到文件末尾的全部内容；③ **Preview** 检查；④ 点 **Comment**；⑤ 点评论时间戳，把 `…#issuecomment-…` 链接贴给我登记。 |
| 为什么是评论 | 与 04（参数校验丢失）、22（模式/张量类别保护丢失）同属"eager 会拒绝、Inductor 照算"；这一族的共同点是 eager 内核对该 dtype **未实现**（`NotImplementedError`），Inductor 的 lowering/分解不看 dtype 直接生成代码。`bool - 1` 同族但已有 #195674，不重复列 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；`aot_eager` 在每一行都与 eager 一致 |
| 提交前查重 | 2026-09-22：`round decimals int tensor compile float32`、`ceil bool tensor torch.compile not implemented`、`glu int inductor not implemented`：无同报告；`bool tensor subtraction compile` → #195674（已有，故不列）；`upsample int32 compile` → #193811（已有，故不列） |
| 证据包 | `plan/reports_pairs/dtype_not_implemented_lost.py`；发现来源 `plan/reports_pairs/lowering_vs_decomp_special_cases.py`（12.1：有专门 lowering 且分解含 dtype 特判的算子 × 触发特判的输入，106 例） |
| 优先级 | 中–低（补充信息；`round(int, decimals)` 顺带把 dtype 变成 float32，值得单独一句） |

---

## Comment

A third group, where the eager kernel is **not implemented for the dtype** and says so, while the Inductor-compiled function computes something anyway (`backend="aot_eager"` raises like eager in every row; torch 2.14.0 and nightly):

```python
import torch, torch.nn.functional as F

b = torch.tensor([True, False, True]); i8 = torch.tensor([[1, -2], [3, 4]], dtype=torch.int8); u8 = torch.tensor([1, 200, 3], dtype=torch.uint8)
cases = {"round(int8, decimals=-1)": (lambda x: torch.round(x, decimals=-1), i8), "round(uint8, decimals=1)": (lambda x: torch.round(x, decimals=1), u8),
         "ceil(bool)": (lambda x: torch.ceil(x), b), "floor(bool)": (lambda x: torch.floor(x), b), "round(bool)": (lambda x: torch.round(x), b),
         "F.glu(int8)": (lambda x: F.glu(x), i8), "adaptive_max_pool2d(int8)": (lambda x: F.adaptive_max_pool2d(x[None], (1, 1)), i8)}
for name, (fn, x) in cases.items():
    row = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            r = fn(x.clone()) if backend is None else torch.compile(fn, backend=backend)(x.clone())
            row.append(f"returns {r.tolist()} {str(r.dtype).split('.')[-1]}")
        except Exception as e:
            row.append(f"raises {type(e).__name__}: {str(e).splitlines()[0][:45]}")
    print(f"{name:26s} eager {row[0]}\n{'':26s} inductor {row[2]}")
```

```
round(int8, decimals=-1)   eager raises NotImplementedError: "round_cpu" not implemented for 'Char'
                           inductor returns [[0.0, -0.0], [0.0, 0.0]] float32
round(uint8, decimals=1)   eager raises NotImplementedError: "round_cpu" not implemented for 'Byte'
                           inductor returns [1.0, 200.0, 3.0] float32
ceil(bool)                 eager raises NotImplementedError: "ceil_vml_cpu" not implemented for 'Bool'
                           inductor returns [True, False, True] bool
floor(bool)                eager raises NotImplementedError: "floor_vml_cpu" not implemented for 'Bool'
                           inductor returns [True, False, True] bool
round(bool)                eager raises NotImplementedError: "round_vml_cpu" not implemented for 'Bool'
                           inductor returns [True, False, True] bool
F.glu(int8)                eager raises NotImplementedError: "glu_cpu" not implemented for 'Char'
                           inductor returns [[0.11920291930437088], [2.9460413455963135]] float32
adaptive_max_pool2d(int8)  eager raises NotImplementedError: "adaptive_max_pool2d" not implemented for 'Ch
                           inductor returns [[[4]]] int8
```

Two of them do more than skip the check: `torch.round(int_tensor, decimals=k)` comes back as **float32** (the `round` decomposition scales by `10**k` in floating point and never casts back), and `F.glu(int8)` returns float32 as well (`sigmoid` promotes). The others return the input dtype, so the only observable difference is that a program which eager rejects runs under `torch.compile`. `1 - bool_tensor` belongs to the same group and is already tracked as #195674; `upsample_*` on integer input as #193811.

A cheap general fix for this group would be for the Inductor lowering (or the decomposition registration) to consult the same dtype support table the eager kernels use (`AT_DISPATCH_*` coverage, as exposed through the OpInfo dtype lists) and fall back to the ATen kernel — which raises — when the input dtype is not in it. For `round` with `decimals` the decomposition can additionally cast the result back to the input dtype.
