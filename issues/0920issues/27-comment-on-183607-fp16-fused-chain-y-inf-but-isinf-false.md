<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 27 条：在 #183607 下的**评论稿**（float16 融合链的中间量不按 float16 舍入：同一次调用里 `y` 是 inf 而 `isinf(y)` 是 False；`emulate_precision_casts=True` 在 CPU 与 CUDA 上都修好）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/183607 （"torch.compile changes fp16 overflow behavior for cast-to-float16 multiplication"，2026-05-13，open；标签 triaged, module: half, module: correctness (silent), module: inductor；jansel 问 `TORCHINDUCTOR_EMULATE_PRECISION_CASTS=1` 是否有效，复现机器人答"无效"） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/183607#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | ① 登录 GitHub 后打开上面的提交网址，滚到页面最底部的评论框；② 在 **Write** 页签粘贴本文件 `## Comment` 标题**下面**到文件末尾的全部内容；③ 点 **Preview** 检查渲染；④ 点绿色 **Comment**；⑤ 点评论右上角时间戳，把 `…#issuecomment-…` 链接贴给我登记。 |
| 为什么是评论 | 根因与 #183607 相同（Inductor 把 float16 的融合逐点链整体在 float32 里算，只在存储时舍回 float16），新开会被并回去。补充三点原 issue 没有的信息：不需要显式 `.to(float16)`，输入本身是 float16 也一样；同一次调用返回的 `y` 与 `isinf(y)` 互相矛盾；`emulate_precision_casts=True` 在 CPU 与 T4 CUDA、2.14.0 与 nightly 上都能修好——与机器人的结论相反 |
| 验证版本 | Windows：torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu；Linux CPU：2.14.0 与 nightly 2.15.0.dev20260921；Tesla T4：2.14.0+cu130 与 nightly 2.15.0.dev20260921+cu130（Kaggle `tcc-halflinux`、`tcc-halfgpu`，`plan/kaggle_out/half*/log.txt`）——六种组合逐字相同 |
| 提交前查重 | 2026-09-22 与 2026-09-22 08:50 两次：`inductor cpu float16 intermediate float32 overflow`、`inductor float16 cpu isinf`、`inductor bfloat16 cpu intermediate precision eager mismatch`、`inductor low precision intermediate upcast float store`：#183607 即本体；相关 #185337（显式 f32→f16→f32 cast，已关闭，本批 20 号评论稿）、PR #195223（只在比较前保留舍入，已关闭未合） |
| 证据包 | `plan/reports_pairs/half_intermediates_cpu.py`（生成的 C++ 内核：`convert<float>` → 整条链 → `convert<at::Half>` 只在 store 时；`isinf` 读的是 float 中间量 `tmp2`） |
| 优先级 | 中–低（已有 issue，补充信息；排在 25 之后） |

---

## Comment

The same happens without any explicit cast, when the input itself is float16, and it makes one call return values that contradict each other. On CPU the generated C++ converts the `at::Half` input to `float`, runs the whole fused chain in `float`, and converts back to `at::Half` only in the store, so `y = x * x` is `inf` in the stored output but still `90000.0` in the register that `y / x` and `isinf(y)` read:

```python
import torch

def f(x):
    y = x * x
    return y, y / x, torch.isinf(y), torch.where(torch.isinf(y), torch.zeros_like(y), y)

x = torch.full((40,), 300.0, dtype=torch.float16)
print("eager   ", [o[0].item() for o in f(x)])
print("compiled", [o[0].item() for o in torch.compile(f)(x)])
torch._dynamo.reset()
with torch._inductor.config.patch(emulate_precision_casts=True):
    print("emulate ", [o[0].item() for o in torch.compile(f)(x)])
```

```
eager    [inf, inf, True, 0.0]
compiled [inf, 300.0, False, inf]
emulate  [inf, inf, True, 0.0]
```

The returned `y` is `inf` while the returned `isinf(y)` is `False`, and the `where` meant to scrub infinities passes `inf` through. Same output on Windows and Linux CPU and on a Tesla T4 (`x` on `cuda`), with 2.14.0 and nightly 2.15.0.dev20260921.

On the question above: `emulate_precision_casts=True` does fix it here — both this program and the `x.to(torch.float16)` one from the description (`inf` instead of `25000000.0`), on CPU and on the T4, with 2.14.0 and nightly. So the mechanism the option guards is the whole story; the open question is only whether the default should preserve the float16 rounding at boundaries that are observable in the same forward (a stored output that is also consumed, and comparisons such as `isinf`), which is what #195223 tried for comparisons.
