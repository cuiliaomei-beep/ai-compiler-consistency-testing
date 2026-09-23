<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 32 条：在**自己的** #197084 下的更正评论（梯度错的真正原因是前向值错：任何 TorchDispatchMode 下 pinv 的内部共轭丢失；指向 31 号新 issue）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/197084 （你 2026-09-15 提交：pinv / matrix_sqrth 复数梯度在 compile 下错，当时归因于 AOTAutograd 追踪反向公式；至今无维护者回应） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/197084#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | 31 已提交为 #198118，正文里的编号已替换好，直接贴即可：① 打开提交网址，滚到底部评论框；② **Write** 页签粘贴 `## Comment` 下面到文件末尾的全部内容；③ **Preview**；④ **Comment**；⑤ 把时间戳链接贴给我登记。 |
| 为什么是评论 | 是对自己 issue 里错误归因的更正，同时把两个 issue 连起来；不改原 issue 正文（保留记录） |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu：转发 mode 下的 eager 梯度与 compile 梯度逐位相同（差 0.0），与 float64 参照差 17.4（原 issue 的 1.7e+01）；只让前向在 mode 下跑、反向在外面跑，梯度同样错 |
| 证据包 | `plan/reports_pairs/conj_lost_under_dispatch_mode.py`；梯度部分见本稿代码块 |
| 优先级 | 高（更正自己的错误归因，避免维护者往 AOTAutograd 反向方向查） |

---

## Comment

Correction on the cause: it is not the traced backward formula. The **forward** value of complex `torch.linalg.pinv` is already wrong whenever a `TorchDispatchMode` is active, and `torch.compile`'s runtime wrapper runs every graph under one (`_AnalyzeCustomOpInputOutputMode`). Details and the affected set (`linalg.pinv` / `pinverse`, `linalg.polar`, `linalg.matrix_sqrth`) are in #198118; here is the gradient side of it, all in eager:

```python
import torch
from torch.utils._python_dispatch import TorchDispatchMode

class Forward(TorchDispatchMode):            # only forwards
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))

torch.manual_seed(0)
def loss(a):
    return (torch.linalg.pinv(a).abs() ** 2).sum()

def grad(fn, a, mode=None):
    a = a.detach().clone().requires_grad_()
    if mode is None:
        fn(a).backward()
    else:
        with mode:
            fn(a).backward()
    return a.grad

a = torch.randn(4, 3, dtype=torch.complex64)
truth = grad(loss, a.to(torch.complex128))
g_eager, g_mode = grad(loss, a), grad(loss, a, Forward())
torch._dynamo.reset()
g_compiled = grad(torch.compile(loss, backend="aot_eager"), a)
print("eager          |grad - truth|", (g_eager.to(torch.complex128) - truth).abs().max().item())
print("under mode     |grad - truth|", (g_mode.to(torch.complex128) - truth).abs().max().item(), "   |mode - compiled|", (g_mode - g_compiled).abs().max().item())
a2 = a.detach().clone().requires_grad_()
with Forward():
    l = loss(a2)                               # forward under the mode, backward outside it
l.backward()
print("fwd in mode, bwd outside |grad - truth|", (a2.grad.to(torch.complex128) - truth).abs().max().item())
```

```
eager          |grad - truth| 1.2571577899445539e-05
under mode     |grad - truth| 17.399362363508732    |mode - compiled| 0.0
fwd in mode, bwd outside |grad - truth| 17.399362363508732
```

The eager gradient computed under a forwarding mode is bit-identical to the compiled one, and it stays wrong when only the forward runs under the mode, so the backward formula is fine and the saved forward output is what is wrong (`pinv` comes back as `vh.mT @ diag(1/s) @ u.mH`, one internal conjugation dropped). `matrix_sqrth` shows the same forward difference under the mode. So the fix belongs to #198118 (the kernels' internal `.mH()` under the `Python` dispatch key), not to AOTAutograd; the labels `module: aotdispatch` / `module: pt2-dispatcher` here are misleading, `module: complex` / `module: linear algebra` / `module: __torch_dispatch__` fit better.
