<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 04 条：在总括 issue #197554 下的**评论稿**（不是新 issue）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/197554 （"☂️ [PT2] Validation lost"，2026-09-18 由维护者开；成员列表里已有你提交的 #197095） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/197554#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | issue 处于 open、未锁定（2026-09-21 核对，目前 0 条评论）。最后一句里的占位符**已替换为 01 号稿的真实编号 #197887**，直接粘贴即可。① 登录 GitHub 后打开上面的提交网址（`#new_comment_field` 会直接跳到页面最底部的评论框；没跳的话手动滚到底，找 “Add a comment”）；② 评论框保持在 **Write** 页签，把本文件 `## Comment` 标题**下面**到文件末尾的全部内容原样粘贴进去（不要带 `## Comment` 这一行，也不要带上面这张表）；③ 点 **Preview** 看一眼：代码块、输出块、行内代码都应正常渲染；④ 点绿色的 **Comment** 按钮。评论没有标题、标签、模板字段，不需要填别的；⑤ 发出后点评论右上角的时间戳，复制地址栏里形如 `…/issues/NNNN#issuecomment-XXXXXXXX` 的链接，填到 `README.md` 对应行的“状态”列。 |
| 为什么评论而不是新开 | 该 issue 明说"真正能关掉这一类的是测试基础设施：一个把 OpInfo `error_inputs` 过编译路径的系统扫描"，并写了 "Comment here if you have one and it will be added"。我们的 `error_parity_sweep.py` 就是这个扫描，直接评论命中率最高 |
| 验证版本 | torch 2.14.0+cpu；逐条独立进程复核 `plan/scripts/diag_error_parity_leads.py`、`plan/reports_validation/validation_lost_members.py`（下方输出即该脚本原样输出） |
| 已有成员 / 重复，不再列 | `index_select` 负索引 = #169779；`index_add` 负索引 = #185885；interpolate 零尺寸 = #197095（你的） |
| 证据包 | `plan/scripts/error_parity_sweep.py`（252 个算子、787 例，22 分钟）、`plan/scripts/error_parity_batch2.py`（129 个程序）、`plan/results/error_parity/*.jsonl` |
| 注意 | 第 01 条（保存的视图丢失版本检查 → 错梯度）**单独开 issue**，不要并进这条评论：那条是静默错梯度，优先级高得多；评论末尾提一句并链接即可（开完 01 后把编号填进去） |

---

## Comment

I ran the sweep this issue asks for: every OpInfo `error_inputs` sample (226 operators) plus about 200 hand-written invalid inputs (out-of-bounds and negative indices, shape contracts of the index/scatter family, dtype and `out=` contracts, in-place type promotion, writes through overlapping memory), each executed in eager and under `backend="eager"`, `"aot_eager"`, and `"inductor"`, one fresh process per operator. A case is reported only when eager raises and a compiled backend returns. torch 2.14.0+cpu; 916 cases in total, 20 lost validations. Excluding the ones already tracked (#169779 `index_select` negative index, #185885 `index_add` negative index, #197095), these are new members:

```python
import torch, torch.nn.functional as F

I = lambda *v: torch.tensor(v)
cases = {
    "index_add, source shape mismatch":   (lambda x, i, s: torch.index_add(x, 0, i, s), (torch.zeros(3, 2), I(0, 2), torch.tensor([3., 4.]))),
    "index_copy, negative index":         (lambda x, i, s: torch.index_copy(x, 0, i, s), (torch.zeros(4, 3), I(-1), torch.ones(1, 3))),
    "binary_cross_entropy, input > 1":    (lambda x, t: F.binary_cross_entropy(x, t), (torch.tensor([1.5, 0.2]), torch.tensor([1., 0.]))),
    "repeat_interleave, wrong output_size": (lambda x, r: torch.repeat_interleave(x, r, output_size=9), (torch.arange(3.), I(1, 2, 3))),
    "softmax on int64":                   (lambda x: torch.softmax(x, 0), (I(1, 2, 3),)),
    "layer_norm, float64 weight":         (lambda x, w: F.layer_norm(x, (3,), w), (torch.arange(6.).reshape(2, 3), torch.ones(3, dtype=torch.float64))),
    "one_hot on float":                   (lambda x: F.one_hot(x, 5), (torch.tensor([0.5, 1.5, 2.5]),)),
    "int64.mul_(float tensor)":           (lambda x, y: x.mul_(y), (I(1, 2, 3), torch.tensor([.5, .5, .5]))),
    "float.add_(1j)":                     (lambda x: x.add_(1j), (torch.ones(3),)),
    "take(out= overlapping input)":       (lambda x: torch.take(x, I(1, 2), out=x[:2]), (torch.arange(3),)),
}
for name, (fn, args) in cases.items():
    row = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        g = fn if backend is None else torch.compile(fn, backend=backend)
        try:
            out = g(*[a.clone() for a in args])
            row.append(f"returns {out.flatten()[:4].tolist()}")
        except Exception as e:
            row.append(f"raises {type(e).__name__}")
    print(f"{name:38s} eager: {row[0]:22s} aot_eager: {row[1]:34s} inductor: {row[2]}")
```

```
index_add, source shape mismatch       eager: raises RuntimeError    aot_eager: raises RuntimeError                inductor: returns [3.0, 4.0, 0.0, 0.0]
index_copy, negative index             eager: raises IndexError      aot_eager: raises IndexError                  inductor: returns [0.0, 0.0, 0.0, 0.0]
binary_cross_entropy, input > 1        eager: raises RuntimeError    aot_eager: raises RuntimeError                inductor: returns [nan]
repeat_interleave, wrong output_size   eager: raises RuntimeError    aot_eager: raises RuntimeError                inductor: returns [0.0, 1.0, 1.0, 2.0]
softmax on int64                       eager: raises NotImplementedError aot_eager: raises NotImplementedError         inductor: returns [0, 0, 0]
layer_norm, float64 weight             eager: raises RuntimeError    aot_eager: raises RuntimeError                inductor: returns [-1.2247356176376343, 0.0, 1.2247356176376343, -1.2247356176376343]
one_hot on float                       eager: raises RuntimeError    aot_eager: returns [0, 0, 0, 0]               inductor: returns [0, 0, 0, 0]
int64.mul_(float tensor)               eager: raises RuntimeError    aot_eager: returns [0, 1, 1]                  inductor: returns [0, 1, 1]
float.add_(1j)                         eager: raises RuntimeError    aot_eager: returns [1.0, 1.0, 1.0]            inductor: returns [1.0, 1.0, 1.0]
take(out= overlapping input)           eager: raises RuntimeError    aot_eager: returns [1, 2]                     inductor: returns [1, 2]
```

Notes on the ones that return data rather than merely accepting a harmless input:

- `index_add` with a source of the wrong shape: the Inductor lowering broadcasts the source (`[3, 4]` lands in every selected row); eager requires `source.shape == self.shape` outside `dim`. #121135 reports this for the `randperm_index_add_pattern` only; it is the general lowering.
- `softmax` on an int64 tensor returns int64 zeros, `binary_cross_entropy` with an input outside `[0, 1]` returns `nan`, `float.add_(1j)` silently drops the imaginary part, `int64.mul_(float)` silently truncates: each replaces an eager error with a wrong value.
- The last four rows are lost in `aot_eager` already, so they are decomposition / functionalization checks, not Inductor lowerings.

Two layers lose different checks, which may help to structure the fix: (1) checks lost in `aot_eager` come from meta kernels and decompositions that are more permissive than the eager kernel (`out=` dtype, in-place result-type rule, memory-overlap assertion); (2) checks lost only in `inductor` come from lowerings that never call the meta function's shape validation (index/scatter family) or that compute through a generic pointwise path (`softmax` on integers, `bce`).

The sweep is a single script (OpInfo `error_inputs` + a table of extra cases, per-operator subprocess, JSONL output, about 20 minutes on CPU); happy to turn it into a test under `test/inductor` if that is the infrastructure you have in mind.

A related but more serious loss of an eager safety check (autograd's "modified by an inplace operation" check disappears under Inductor and `backward()` returns wrong gradients) is filed separately as #197887.
