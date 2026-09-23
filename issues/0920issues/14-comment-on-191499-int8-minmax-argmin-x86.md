<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 14 条：在 #191499 下的**评论稿**（不是新 issue）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/191499 （"[Inductor][CPU] torch.compile returns 0 for short positive uint8/int8 amin reductions on Apple Silicon"，open，2026-07-29） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/191499#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | issue 处于 open、未锁定（2026-09-21 核对）。① 登录 GitHub 后打开上面的提交网址（`#new_comment_field` 会直接跳到页面最底部的评论框；没跳的话手动滚到底，找 “Add a comment”）；② 评论框保持在 **Write** 页签，把本文件 `## Comment` 标题**下面**到文件末尾的全部内容原样粘贴进去（不要带 `## Comment` 这一行，也不要带上面这张表）；③ 点 **Preview** 看一眼：代码块、输出块、行内代码都应正常渲染；④ 点绿色的 **Comment** 按钮。评论没有标题、标签、模板字段，不需要填别的；⑤ 发出后点评论右上角的时间戳，复制地址栏里形如 `…/issues/NNNN#issuecomment-XXXXXXXX` 的链接，填到 `README.md` 对应行的“状态”列。 |
| 为什么是评论 | 同一根因（部分向量加载后未屏蔽的通道参与归约）。原 issue 只报了 Apple Silicon 上 `amin` 得 0；我们补三点新信息：x86-64 AVX2 同样受影响（阈值 16 个元素）、`amax`/`max` 对全负 int8 同样错、**`argmin`/`argmax` 返回 -1（非法下标）** |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu，Windows 11 x64（AVX2，MSVC）；Linux 复核（Kaggle，`plan/kaggle_out/intublinux.log`、`intubgpu.log`）：两台 Linux x86-64 机器（GCC）上同样出错但**错法不同**——一台 `argmin`=0、全负 int8 的 `max`=1；另一台 `min`=0、`argmin`=**-8473051087277178060（未初始化的下标）**；nightly 2.15.0.dev20260920 同样；CUDA（Triton）正确；`plan/reports_intub/int8_minmax_vector_padding.py`、`argmin_uint8_vectorized.py` |
| 相关 PR（2026-09-22 查重补充） | #191543（open，2026-07-29，“Fix int8/uint8 min/max vectorized reductions polluted by inactive lanes”，Fixes #191499）：修的是 `amin`/`amax` 的未屏蔽通道；我们评论里的 `argmin`/`argmax` 与 x86 上的表现是否被它覆盖**没有验证过**，所以评论仍有价值，可在评论末尾提醒 PR 作者顺带测 arg-归约 |
| 发现来源 | `plan/scripts/int_ub_sweep.py`（用例 `int_unary:argmin`，uint8，n=33） |

---

## Comment

This is not specific to Apple Silicon. On x86-64 (AVX2, Windows 11, MSVC; torch 2.14.0+cpu and nightly 2.15.0.dev20260911+cpu) the same defect appears once the reduction has 16 or more elements, and it affects more than `amin`:

```python
import torch

pos = torch.tensor([5, 1, 100, 3, 7, 8, 9, 13, 100, 120, 127, 2, 6, 4, 11, 12, 90, 80])
for dtype, x in ((torch.uint8, pos), (torch.int8, pos), (torch.int8, -pos)):
    x = x.to(dtype)
    for name, fn in (("min", torch.min), ("max", torch.max), ("argmin", torch.argmin), ("argmax", torch.argmax)):
        torch._dynamo.reset()
        e, c = fn(x).item(), torch.compile(fn)(x.clone()).item()
        if e != c:
            print(f"{str(dtype):12s} first={x[0].item():3d}  {name:6s} eager={e:4d}  inductor={c:4d}")
```

```
torch.uint8  first=  5  min    eager=   1  inductor=   0
torch.uint8  first=  5  argmin eager=   1  inductor=  -1
torch.int8   first=  5  min    eager=   1  inductor=   0
torch.int8   first=  5  argmin eager=   1  inductor=  -1
torch.int8   first= -5  max    eager=  -1  inductor=   0
torch.int8   first= -5  argmax eager=   1  inductor=  -1
```

New relative to the original report:

- **x86-64 is affected**; with 15 elements the results are correct, with 16 or more they are wrong (8-bit vectors have 32 lanes here, the reduction loads them 16 at a time).
- **`max` / `amax` of an all-negative int8 tensor returns 0**, the mirror image of `amin` on positive data. The value `0` does not occur in the input.
- **`argmin` / `argmax` return `-1`**, which is not a valid index; `torch.min(x, dim).indices` does the same. Code that indexes with the result reads the last element instead of failing.
- int16, int32, int64 and floating dtypes are correct on the same data, and so is CUDA (Triton).
- **The wrong value depends on the CPU.** The same script on two Linux x86-64 machines (GCC, torch 2.14.0 and nightly 2.15.0.dev20260920) gives `argmin = 0`, `max = 1` (all-negative int8, eager `-1`), `argmax = 0` on one, and `min = 0`, `argmin = -8473051087277178060`, `max = 0`, `argmax = 0` on the other; the last index is uninitialised memory, so the lanes that were not loaded are not even guaranteed to be zero.

The generated kernel shows the cause described above, a partial load followed by an unmasked combine:

```cpp
auto tmp0 = at::vec::Vectorized<uint8_t>::loadu(in_ptr0 + x0, static_cast<int64_t>(16));
tmp_acc0_vec = argmin_combine_vec<uint8_t, 1, 2, true>(tmp_acc0_vec, tmp0, x0);
```

`loadu(ptr, 16)` fills the other 16 lanes with zeros, and those lanes take part in the reduction (value 0, index -1). Passing the tail size to the combine step for the main loop as well (as the scalar-tail branch already does with `static_cast<int64_t>(1LL)`), or loading the remaining lanes with the reduction's identity, fixes all four operators.
