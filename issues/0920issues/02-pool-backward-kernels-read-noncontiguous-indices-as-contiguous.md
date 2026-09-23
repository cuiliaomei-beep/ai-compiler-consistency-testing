<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 02（高：静默错梯度；根因在 eager 的 C++ 内核，经 torch.compile 对普通用户可达）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，CPU）。内核级复现不需要 torch.compile；用户级复现需要 Inductor（`aot_eager` 正确）；Linux 复核（Kaggle `tcc-rewritelinux` / `tcc-rewritegpu`，`plan/kaggle_out/rewritelinux.log`、`rewritegpu.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 两个代码块输出逐字相同（max diff 282；三个内核 False）；**CUDA（T4，2.14.0+cu130）上编译后的梯度正确** → 只影响 CPU 内核 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml （用户可见的症状在 torch.compile 下；正文写明根因在 ATen 内核，维护者会自行加 `module: pooling` / `module: memory format`） |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21：`adaptive_max_pool3d backward indices contiguous`、`adaptive_max_pool3d channels_last`、`adaptive_max_pool3d gradient wrong`、`pool backward non-contiguous indices`：无同报告。属于 ☂️ #195547（ATen 内核缺检查/缺规范化）一类，可在正文引用 |
| 证据包 | `plan/reports_layout/pool_backward_noncontiguous_indices.py`（6 个池化反向内核 × 非连续 indices）、`compiled_pool_grad_channels_last.py`（5 个池化 × 连续/channels_last × 三后端）、`adaptive_max_pool3d_chlast_grad.py`；发现来源 `plan/scripts/layout_alias_sweep.py`（7.1，`nn.functional.adaptive_max_pool3d` 的 chlast 变体，梯度误差 2.98） |
| 根因 | `adaptive_max_pool3d_backward`、`fractional_max_pool2d_backward`、`fractional_max_pool3d_backward` 的 CPU 内核对 `grad_output` 做了 `.contiguous()`，对 `indices` 没做，直接按连续内存读 `indices.data_ptr()`。eager 里 indices 总是前向刚产出的连续张量，所以平时撞不到；Inductor 为 channels_last_3d 输入把存给反向的 indices 排成 channels_last 步长，就触发 |
| 建议标签 | module: pooling, module: memory format, module: correctness (silent), oncall: pt2 |

---

## Title

`adaptive_max_pool3d_backward` and `fractional_max_pool{2,3}d_backward` read a non-contiguous `indices` tensor as if it were contiguous: silently wrong gradients, reached from `torch.compile` with `channels_last_3d` inputs

## Body

### 🐛 Describe the bug

**Summary.** For `F.adaptive_max_pool3d` on a `channels_last_3d` input, eager and `aot_eager` compute the same input gradient, and Inductor computes a different one: the forward values and indices are identical, but `backward()` scatters the gradient to the wrong positions (max difference 282 in the example below; torch 2.14.0 and nightly). A 3-D CNN that follows the memory-format recommendation and is then compiled trains with silently wrong gradients through every adaptive max pool. Because the CPU kernels of `adaptive_max_pool3d_backward`, `fractional_max_pool2d_backward`, and `fractional_max_pool3d_backward` make `grad_output` contiguous but read `indices` through its raw data pointer, any caller that passes non-contiguous indices gets a wrong result; eager autograd never does, Inductor does as soon as it lays the saved indices out in the input's memory format.

User-level reproduction (needs Inductor):

```python
import torch, torch.nn.functional as F

torch.manual_seed(0)
f = lambda t: F.adaptive_max_pool3d(t, (2, 3, 5))
x = torch.randperm(1 * 4 * 4 * 6 * 5).float().reshape(1, 4, 4, 6, 5)
for name, xin in (("contiguous", x), ("channels_last_3d", x.contiguous(memory_format=torch.channels_last_3d))):
    grads = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        t = xin.detach().clone(memory_format=torch.preserve_format).requires_grad_()
        out = (f if backend is None else torch.compile(f, backend=backend))(t)
        (out * torch.arange(1.0, out.numel() + 1).reshape(out.shape)).sum().backward()
        grads.append(t.grad.clone())
    print(f"{name:17s} aot_eager == eager: {torch.equal(grads[0], grads[1])}   inductor == eager: {torch.equal(grads[0], grads[2])}"
          f"   max diff {(grads[0] - grads[2]).abs().max().item():.0f}")
```

```
contiguous        aot_eager == eager: True   inductor == eager: True   max diff 0
channels_last_3d  aot_eager == eager: True   inductor == eager: False   max diff 282
```

Kernel-level reproduction (eager only, no compiler involved): the same values in `indices`, once contiguous and once with `channels_last` strides.

```python
import torch, torch.nn.functional as F

torch.manual_seed(0)
A = torch.ops.aten
x3 = torch.randperm(240).float().reshape(1, 4, 4, 3, 5)
x3w = torch.cat([x3, x3], 3)
x2 = torch.randperm(120).float().reshape(1, 4, 6, 5)
rs2, rs3 = torch.full((1, 4, 2), 0.5), torch.full((1, 4, 3), 0.5)
cases = []
v, i = F.adaptive_max_pool3d(x3, (2, 3, 5), return_indices=True)
cases.append(("adaptive_max_pool3d_backward", lambda go, idx: A.adaptive_max_pool3d_backward(go, x3, idx), v, i, torch.channels_last_3d))
v, i = F.adaptive_max_pool2d(x2, (3, 5), return_indices=True)
cases.append(("adaptive_max_pool2d_backward", lambda go, idx: A.adaptive_max_pool2d_backward(go, x2, idx), v, i, torch.channels_last))
v, i = F.max_pool3d(x3, 2, 1, return_indices=True)
cases.append(("max_pool3d_with_indices_backward", lambda go, idx: A.max_pool3d_with_indices_backward(go, x3, [2, 2, 2], [1, 1, 1], [0, 0, 0], [1, 1, 1], False, idx), v, i, torch.channels_last_3d))
v, i = F.fractional_max_pool2d(x2, 2, output_size=(3, 3), return_indices=True, _random_samples=rs2)
cases.append(("fractional_max_pool2d_backward", lambda go, idx: A.fractional_max_pool2d_backward(go, x2, [2, 2], [3, 3], idx), v, i, torch.channels_last))
v, i = F.fractional_max_pool3d(x3w, 2, output_size=(2, 2, 2), return_indices=True, _random_samples=rs3)
cases.append(("fractional_max_pool3d_backward", lambda go, idx: A.fractional_max_pool3d_backward(go, x3w, [2, 2, 2], [2, 2, 2], idx), v, i, torch.channels_last_3d))
for name, fn, v, idx, fmt in cases:
    go = torch.arange(1.0, v.numel() + 1).reshape(v.shape)
    idx_nc = idx.contiguous(memory_format=fmt)                      # equal values, channels_last strides
    same = torch.equal(fn(go, idx), fn(go, idx_nc))
    print(f"{name:34s} indices strides {str(tuple(idx_nc.stride())):22s} same gradient as with contiguous indices: {same}")
```

```
adaptive_max_pool3d_backward       indices strides (120, 1, 60, 20, 4)    same gradient as with contiguous indices: False
adaptive_max_pool2d_backward       indices strides (60, 1, 20, 4)         same gradient as with contiguous indices: True
max_pool3d_with_indices_backward   indices strides (96, 1, 32, 16, 4)     same gradient as with contiguous indices: True
fractional_max_pool2d_backward     indices strides (36, 1, 12, 4)         same gradient as with contiguous indices: False
fractional_max_pool3d_backward     indices strides (32, 1, 16, 8, 4)      same gradient as with contiguous indices: False
```

`adaptive_max_pool2d_backward` and `max_pool{2,3}d_with_indices_backward` normalize `indices` and are correct; the other three are not. Passing a channels_last `grad_output` or `self` to the affected kernels is handled correctly, only `indices` is read without `.contiguous()`.

**Possible fix.** In `aten/src/ATen/native/AdaptiveMaxPooling3d.cpp`, `FractionalMaxPool2d.cpp`, and `FractionalMaxPool3d.cpp` (backward, CPU; the CUDA counterparts are worth the same look), take `indices.contiguous()` next to the existing `gradOutput.contiguous()`; the 2-D adaptive kernel and the `max_pool{2,3}d_with_indices_backward` kernels are correct in the table above, so they evidently normalize the argument already. Independently, Inductor's fallback for these ops could `require_contiguous` the `indices` argument. This belongs to the class tracked in #195547 (a precondition the kernel relies on but never establishes).

### Error logs

No error is raised; the gradients differ as shown above.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux) and on Linux with 2.14.0. On CUDA (Tesla T4, 2.14.0+cu130) the compiled gradient matches eager, so only the CPU kernels are affected.
