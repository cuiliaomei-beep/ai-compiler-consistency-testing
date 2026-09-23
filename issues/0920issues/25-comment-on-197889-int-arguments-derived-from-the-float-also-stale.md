<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 25 条：在**自己的** #197889 下的补充评论（同一根因的第二类入口：由 float 派生的**整数**实参）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/197889 （你 2026-09-21 提交的 02b：变化的 Python float 被烤进缓存图） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/197889#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | ① 登录 GitHub 后打开上面的提交网址，滚到页面最底部的评论框；② 在 **Write** 页签粘贴本文件 `## Comment` 标题**下面**到文件末尾的全部内容；③ 点 **Preview** 检查渲染；④ 点绿色 **Comment**；⑤ 点评论右上角时间戳，把 `…#issuecomment-…` 链接贴给我登记。 |
| 为什么是评论而不是新 issue | 根因与 #197889 完全相同（追踪期把派生自 float 符号的表达式特化，ShapeEnv 守卫不进 AOTAutogradCache 的键），只是入口从“算子的 double 形参”换成“算子的 int 形参”；新开会被并回去。作为补充评论可以让修复覆盖这一类 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；关掉 FX 图缓存或 AOTAutograd 缓存任一个即正确（与 #197889 相同） |
| 证据包 | `plan/reports_scalar_seq/specialized_value_census_v2.py`（11.2 普查 v2：56 个程序——形状/下标类 18、按值分支的分解类 18、SymBool 类 7、int 实参类 13；nightly 上 7 个静默错、5 个编译失败）；日志 `plan/results/scalar_seq/census_v2_nightly.log` |
| 普查里**没问题**的（负结果） | 接受 SymInt 的位置都对：`zeros(int(s*8))`、切片 / 下标、`F.pad`、`repeat`、`roll`、`topk`、`narrow`、`tril`；按值分支的分解都对：`pow` 指数 2/0.5/0、`addmm`/`baddbmm` 的 beta=0（NaN 传播）、`addcmul` value=0、`lerp`、`dropout` p∈{0,1}、`clamp` min>max、`softplus`、`norm`/`normalize` 的 p；SymBool 进张量运算、int 实参序列也都对 |
| 提交前查重 | 2026-09-22 08:50：`AOTAutogradCache stale int argument derived float cumsum dim`、`specialized int from float item cached graph stale`：无同报告；根因即 #197889 本体，故为评论 |
| 优先级 | 中（补充信息；#197889 本体是高） |

---

## Comment

A second entry point with the same root cause: **integer** arguments computed from the float. `int(s * k)` on the dynamic float is a symbolic integer; operators that accept a SymInt there are fine (`torch.zeros(int(s*8))`, slicing, `F.pad`, `repeat`, `roll`, `topk`, `narrow`, `tril` all follow `s`), but operators whose schema takes a plain `int` specialise it during tracing, and from the third distinct `s` on the cached artifact keeps the value of the second call:

```python
import torch, torch.nn.functional as F

torch.manual_seed(0)
x = torch.randn(8, 8)
programs = {
    "cumsum(dim=int(s*2) % 2)":            lambda s: (x * s).cumsum(int(s * 2) % 2),
    "round(decimals=int(s*4))":            lambda s: (x * s).round(decimals=int(s * 4)),
    "linspace(0, 1, int(s*8) + 2)":        lambda s: x[0, 0] * s + torch.linspace(0, 1, int(s * 8) + 2),
    "one_hot(num_classes=int(s*8) + 3)":   lambda s: F.one_hot(torch.tensor([0, 1, 2]), int(s * 8) + 3) * (x[0, 0] * s),
    "adaptive_avg_pool1d(int(s*6) + 1)":   lambda s: F.adaptive_avg_pool1d((x * s)[None], int(s * 6) + 1),
    "unfold(0, int(s*4) + 1, 1)":          lambda s: (x * s).unfold(0, int(s * 4) + 1, 1),
}
for name, f in programs.items():
    torch._dynamo.reset()
    cf = torch.compile(f)
    row = []
    for s in (0.9, 0.5, 0.25, 1.0):
        want, got = f(s), cf(s)
        row.append("ok" if want.shape == got.shape and torch.allclose(want, got) else
                   (f"shape {tuple(got.shape)} != {tuple(want.shape)}" if want.shape != got.shape else f"max abs diff {(want - got).abs().max().item():.3g}"))
    print(f"{name:36s} " + " | ".join(f"s={s}: {r}" for s, r in zip((0.9, 0.5, 0.25, 1.0), row)))
```

```
cumsum(dim=int(s*2) % 2)             s=0.9: ok | s=0.5: ok | s=0.25: max abs diff 1.79 | s=1.0: max abs diff 7.18
round(decimals=int(s*4))             s=0.9: ok | s=0.5: ok | s=0.25: max abs diff 0.05 | s=1.0: max abs diff 0.0049
linspace(0, 1, int(s*8) + 2)         s=0.9: ok | s=0.5: ok | s=0.25: shape (6,) != (4,) | s=1.0: shape (6,) != (10,)
one_hot(num_classes=int(s*8) + 3)    s=0.9: ok | s=0.5: ok | s=0.25: shape (3, 7) != (3, 5) | s=1.0: shape (3, 7) != (3, 11)
adaptive_avg_pool1d(int(s*6) + 1)    s=0.9: ok | s=0.5: ok | s=0.25: shape (1, 8, 4) != (1, 8, 2) | s=1.0: shape (1, 8, 4) != (1, 8, 7)
unfold(0, int(s*4) + 1, 1)           s=0.9: ok | s=0.5: ok | s=0.25: shape (6, 8, 3) != (7, 8, 2) | s=1.0: shape (6, 8, 3) != (4, 8, 5)
```

`cumsum` accumulates along the wrong dimension and `round` uses the wrong number of decimals with no shape change to give it away. As in the description, either `TORCHINDUCTOR_FX_GRAPH_CACHE=0` or `TORCHINDUCTOR_AUTOGRAD_CACHE=0` makes every row `ok`. So a fix at the cache level (or a restart-and-specialise for any symbol whose *derived* expression gets specialised, integer-valued ones included) would cover both families; a fix limited to float schema arguments would leave these.

For completeness, value-dependent decompositions are not affected: `pow` with exponent 2 / 0.5 / 0, `addmm` / `baddbmm` with `beta=0` on a NaN input, `addcmul(value=0)`, `lerp`, `dropout` with p in {0, 1}, `clamp` with min > max, `softplus`, `norm` / `normalize` p all track `s` correctly.
