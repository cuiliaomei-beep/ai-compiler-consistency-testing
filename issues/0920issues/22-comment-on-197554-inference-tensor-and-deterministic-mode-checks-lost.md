<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 22 条：在 #197554（☂️ [PT2] Validation lost）下的**第二条评论稿**：模式类保护在 Inductor 下丢失

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/197554 （与 04 号评论稿同一个伞形 issue；04 讲的是"算子入参校验"，本条讲的是"模式/张量种类的保护"，建议分两条评论发，先发 04） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/197554#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | 与 04 号是同一个 issue 下的**第二条**评论：先发 04，隔一会儿（或等有人回复后）再发这条，不要合并成一条——两条主题不同，分开便于维护者逐条建成员。① 登录 GitHub 后打开上面的提交网址（`#new_comment_field` 会直接跳到页面最底部的评论框；没跳的话手动滚到底，找 “Add a comment”）；② 评论框保持在 **Write** 页签，把本文件 `## Comment` 标题**下面**到文件末尾的全部内容原样粘贴进去（不要带 `## Comment` 这一行，也不要带上面这张表）；③ 点 **Preview** 看一眼：代码块、输出块、行内代码都应正常渲染；④ 点绿色的 **Comment** 按钮。评论没有标题、标签、模板字段，不需要填别的；⑤ 发出后点评论右上角的时间戳，复制地址栏里形如 `…/issues/NNNN#issuecomment-XXXXXXXX` 的链接，填到 `README.md` 对应行的“状态”列。 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；Linux 复核（Kaggle `tcc-safetylinux` / `tcc-safetygpu`，`plan/kaggle_out/safetylinux.log`、`safetygpu.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921 输出逐字相同；T4 CUDA（2.14.0+cu130）上前两项同样丢失，第三项在 CUDA 上只有整数 `empty` 不填充。三项都是 `aot_eager` 与 eager 一致、只有 Inductor 不同 |
| 提交前查重 | 2026-09-21：`inference tensor inplace torch.compile no error`、`use_deterministic_algorithms torch.compile error not raised`、`fill_uninitialized_memory torch.compile empty`、`deterministic algorithms inductor put_` —— 无同报告。相关但不同：#113707（closed，compile 的 backward 不遵守 deterministic）、#162522（closed，在图里调用 `use_deterministic_algorithms` 的追踪问题） |
| 第 4 项来源 | `plan/scripts/symshape_index_diff.py`（10.5b，用例 `pad_both`）；隔离 `plan/reports_symshape/negative_pad_beyond_input.py`（9 种写法 × eager/aot_eager/inductor 静态与动态）；2.14 + nightly；查重（`constant_pad_nd negative padding inductor` 等 3 组）无同报告，邻近但不同：#195582（open，BatchNorm 后接收缩 pad 的错值）、#194558（closed，就地 pad 优化崩溃） |
| 证据包 | `plan/reports_surgery/safety_mechanisms_lost.py`（10 行对照）、`deterministic_mode_parity.py`（确定性模式下 36 个"无确定性实现"的算子前向/反向 × CPU/CUDA 的报错对等性 + 7 种 `empty*` 的填充）；发现来源 `plan/scripts/model_surgery_diff.py`（10.4，76 例中 3 例） |
| 没有写进评论的 | CUDA 上 `avg_pool3d` / `reflection_pad1d` / `nll_loss2d` 的反向、`interpolate(bicubic/linear)` 的反向在确定性模式下 eager 报错而编译后不报——但编译后的实现是 gather 式/排序式的确定性实现，不报错是合理的，**不算缺陷** |
| 2026-09-22 调整 | 原第 3 项（确定性模式下 `empty*` 不填充）查重发现已有 #174386（closed completed，但 CPU 上仍复现）→ 从本评论拆出，单独成 24 号评论稿发到 #174386 下；本稿现在是 3 项：inference tensor、`put_`、`F.pad` |
| 严重度 | 中–低。第一项是静默绕过 InferenceMode 的安全约束；第二、三项是 `use_deterministic_algorithms(True)` 的文档承诺在编译后不成立 |

---

## Comment

Three more members. The first two are of a slightly different kind: the check that is lost is not an argument validation but a protection tied to a mode or to the kind of tensor. All three behave like eager under `backend="aot_eager"` and differ only under Inductor (2.14.0 and nightly, Windows and Linux CPU; the first two also on CUDA).

```python
import torch, torch.nn.functional as F

def outcome(fn, check, *args, backend=None, deterministic=False):
    torch._dynamo.reset()
    torch.use_deterministic_algorithms(deterministic)
    try:
        out = (fn if backend is None else torch.compile(fn, backend=backend))(*args)
        return "returns " + str(check(out))
    except RuntimeError as e:
        return "raises RuntimeError: " + str(e)[:42]
    finally:
        torch.use_deterministic_algorithms(False)

def inference_tensor():
    with torch.inference_mode():
        return torch.ones(3)

cases = {   # name: (compiled function, check applied to its result outside the compiled region, inputs, deterministic mode)
    "in-place op on an inference tensor, outside InferenceMode": (lambda t: t.add_(1), lambda y: y.tolist(), lambda: (inference_tensor(),), False),
    "deterministic mode: put_ with duplicate indices": (lambda x, i, v: x.put_(i, v), lambda y: y.tolist(), lambda: (torch.zeros(4), torch.tensor([1, 1]), torch.tensor([1.0, 2.0])), True),
    "F.pad cropping more than the input has: pad(x[3], (-4, 4))": (lambda x: F.pad(x, (-4, 4)), lambda y: y.tolist(), lambda: (torch.arange(1.0, 4.0),), False),
}
for name, (fn, check, make, det) in cases.items():
    print(name)
    for backend in (None, "aot_eager", "inductor"):
        print(f"    {str(backend):10s} {outcome(fn, check, *make(), backend=backend, deterministic=det)}")
```

```
in-place op on an inference tensor, outside InferenceMode
    None       raises RuntimeError: Inplace update to inference tensor outside
    aot_eager  raises RuntimeError: Inplace update to inference tensor outside
    inductor   returns [2.0, 2.0, 2.0]
deterministic mode: put_ with duplicate indices
    None       raises RuntimeError: put_ does not have a deterministic impleme
    aot_eager  raises RuntimeError: put_ does not have a deterministic impleme
    inductor   returns [0.0, 2.0, 0.0, 0.0]
F.pad cropping more than the input has: pad(x[3], (-4, 4))
    None       raises RuntimeError: narrow(): length must be non-negative.
    aot_eager  raises RuntimeError: narrow(): length must be non-negative.
    inductor   returns [0.0, 0.0, 0.0]
```

1. **Inference tensors.** Eager forbids in-place updates of an inference tensor outside `InferenceMode`; the Inductor-compiled function mutates it (the caller's tensor really changes to `[2., 2., 2.]`). The check lives in the ADInplaceOrView kernels, which the compiled graph does not go through, and nothing re-creates it for a mutated graph input that `is_inference()`.
2. **`put_` under `torch.use_deterministic_algorithms(True)`.** Eager raises because the result with duplicate indices depends on write order; Inductor lowers it to its own scatter and runs it (same on CUDA, where the order is a real race).
3. **`F.pad` with a negative pad larger than the dimension.** `F.pad(x, (-4, 4))` on a length-3 tensor asks to crop four elements from a side that has three; eager raises from `narrow()`, the Inductor `constant_pad_nd` lowering returns a tensor made only of the fill value (`[0., 0., 0.]`, or `[9., 9., 9.]` with `value=9`). Same for 2-D inputs and for either side. (An ordinary argument validation, like the ones in my previous comment; found later with a sweep over symbolic slice / pad / roll amounts.)

Possible fixes: (1) in AOTAutograd's runtime wrapper, when a graph input is mutated and `input.is_inference()` while inference mode is off, raise the same error before running the graph; (2) make the `put` / `index_put` lowering fall back to the ATen kernel (which raises) when `torch.are_deterministic_algorithms_enabled()` and `accumulate=False`, as is already done for some scatter lowerings; (3) check `-pad <= size` per side in the `constant_pad_nd` lowering (the meta function can raise the same error).

A fourth loss of the same kind, deterministic mode's `fill_uninitialized_memory` not being honoured for `empty` / `empty_like` / `new_empty` under Inductor on CPU, is already tracked as #174386; it still reproduces there, details in my comment on that issue.
