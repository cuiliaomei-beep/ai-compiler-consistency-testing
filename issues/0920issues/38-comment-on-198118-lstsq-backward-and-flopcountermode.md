<!-- 提交信息（不要复制到 GitHub） -->
# pytorch/pytorch — 0920 第 38 条：在**自己的** #198118 下的补充评论（同一机制也打到 `linalg.lstsq` 的**反向**；PyTorch 自带的 `FlopCounterMode` 就能触发，与 torch.compile 无关）

| 项 | 值 |
|---|---|
| 评论位置 | https://github.com/pytorch/pytorch/issues/198118 （你 2026-09-22 提交的 31：任意 TorchDispatchMode 下复数 pinv/polar/matrix_sqrth 前向值错） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/198118#new_comment_field |
| **怎么提交（是评论，不是新 issue）** | ① 打开提交网址，滚到底部评论框；② **Write** 页签粘贴 `## Comment` 下面到文件末尾的全部内容；③ **Preview**；④ **Comment**；⑤ 把时间戳链接贴给我登记。 |
| 为什么是评论 | 同一根因的两个新事实：① 受影响的还有 C++ 反向公式（`linalg.lstsq` 前向在 mode 下正确、梯度错 100 倍量级）；② 用 PyTorch 自带的 `torch.utils.flop_counter.FlopCounterMode` 就能复现——说明不是 torch.compile 专属，任何在 mode 下训练/剖析复数模型的用户都会中 |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows） |
| 提交前查重 | 2026-09-22 16:20：`lstsq complex gradient TorchDispatchMode`、`FlopCounterMode wrong gradient complex`、`TorchDispatchMode changes numerical result complex linalg`、`linalg_lstsq_backward conj`：只有自己的 #198118 / #197084 |
| 证据包 | `plan/scripts/dispatch_mode_grad_sweep.py`（955 个可求导 (算子, dtype) 对：只有 pinv/pinverse、matrix_sqrth、lstsq 的复数梯度在 mode 下变）、`plan/reports_pairs/lstsq_complex_grad_under_mode.py` |
| 优先级 | 中（补充信息，扩大影响面） |

---

## Comment

Two additions after sweeping the gradients as well (every OpInfo op with autograd, complex64/complex128/float64, eager vs the same computation under a forwarding `TorchDispatchMode`; 955 operator–dtype pairs):

1. **The backward of `torch.linalg.lstsq` is affected too.** Its forward is identical under the mode, but the gradient is not — the C++ `linalg_lstsq_backward` goes through `pinv` and `.mH()` internally. Apart from `lstsq`, only the gradients of `pinv` / `pinverse` and `matrix_sqrth` change (their forwards are the ones in the description); all float64 gradients are unchanged. `torch.compile` happens **not** to be affected for `lstsq`, because AOTAutograd traces the derivative formula op by op instead of calling the composite C++ backward under the mode.

2. **A stock PyTorch mode triggers it**, so this is not specific to `torch.compile`: `torch.utils.flop_counter.FlopCounterMode` — used to profile a training step — gives the same wrong values.

```python
import torch
from torch.utils.flop_counter import FlopCounterMode

torch.manual_seed(0)
A = torch.randn(5, 3, dtype=torch.complex64); B = torch.randn(5, 2, dtype=torch.complex64)

def loss(A, B):
    return (torch.linalg.lstsq(A, B).solution.abs() ** 2).sum()

def grad(A, B, mode=None):
    A = A.detach().clone().requires_grad_(); B = B.detach().clone().requires_grad_()
    if mode is None:
        loss(A, B).backward()
    else:
        with mode:
            loss(A, B).backward()
    return A.grad

ref = grad(A.to(torch.complex128), B.to(torch.complex128))
print("lstsq grad  eager |dA - ref|", (grad(A, B).to(torch.complex128) - ref).abs().max().item())
print("lstsq grad  under FlopCounterMode |dA - ref|", (grad(A, B, FlopCounterMode(display=False)).to(torch.complex128) - ref).abs().max().item())
M = torch.randn(4, 3, dtype=torch.complex64)
with FlopCounterMode(display=False):
    p = torch.linalg.pinv(M)
print("pinv        under FlopCounterMode |pinv - eager|", (p - torch.linalg.pinv(M)).abs().max().item())
```

```
lstsq grad  eager |dA - ref| 4.480225896255682e-05
lstsq grad  under FlopCounterMode |dA - ref| 173.15849216723038
pinv        under FlopCounterMode |pinv - eager| 1.285477638244629
```

So any code that profiles or logs a complex-valued model with a dispatch mode (FLOP counting, logging tensors, memory tracking) trains on wrong gradients for these ops, in plain eager. The fix location is the same: the conjugate views created inside the ATen composites (`linalg_pinv`, `linalg_polar`, `linalg_matrix_sqrth`, and `linalg_lstsq_backward`) are consumed without being materialized while the `Python` dispatch key is in the TLS include set.
