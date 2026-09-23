<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 33（高：Inductor 的 avg_pool 反向在 `ceil_mode=True` 时对最后一个越界窗口用整核大小做除数——梯度错；前向正确）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；1-D / 2-D 都错（3-D 走 fallback，正确）；`aot_eager` 与 eager 一致；Tesla T4 CUDA（2.14.0+cu130 与 nightly dev20260921）逐字相同（Kaggle `tcc-avgpoolgpu`，`plan/kaggle_out/avgpoolgpu/log.txt`）；Linux CPU 同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22：`avg_pool2d backward ceil_mode inductor gradient`、`avg_pool ceil_mode divisor backward compile wrong gradient`、`avg_pool2d_backward ceil_mode count_include_pad inductor`、`inductor avg_pool backward overhanging window divisor`：无同报告 |
| 证据包 | `plan/reports_pairs/avg_pool_ceil_mode_backward.py`；发现来源 `plan/scripts/opinfo_edge_sweep.py --grad`（12.2：OpInfo 全算子 × 边界值 × 反向，float32，454 对；`nn.functional.avg_pool1d` 样本 2） |
| 根因 | `torch/_inductor/lowering.py::avg_pool2d_backward`：`elif count_include_pad or not had_padding: scale = kernel_size[0] * kernel_size[1]`——`count_include_pad=True`（默认）时除数恒为整核大小；eager 的 `avg_pool2d_backward` 用 `(min(hstart + kH, H + padH) - hstart) * (min(wstart + kW, W + padW) - wstart)`，即窗口裁到"含 padding 的输入"——两者只在 `ceil_mode=True` 让最后一个窗口越过输入 + padding 时不同。前向 `_avg_poolnd` 的除数是对的（前向一致） |
| 影响 | `nn.AvgPool2d(k, stride, ceil_mode=True)`（GoogLeNet / Inception 系列的默认池化配置）训练时最后一行/列的梯度偏小：k=3,s=2 在 6×6 输入上 eager 0.278/0.556/0.694 vs Inductor 0.222/0.444/0.444 |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent), module: pooling |

---

## Title

[inductor] `avg_pool1d/2d` backward with `ceil_mode=True` divides the overhanging last window by the full kernel size, so the compiled gradient is wrong where eager and `aot_eager` agree; forward is correct

## Body

### 🐛 Describe the bug

**Summary.** For `F.avg_pool1d` / `F.avg_pool2d` with `ceil_mode=True` and the default `count_include_pad=True`, eager and `backend="aot_eager"` give gradient `1/2` to the two elements of a last window covering two of its three positions, while Inductor gives `1/3` (torch 2.14.0 and nightly, CPU and CUDA, 1-D and 2-D). The forward output is identical in every backend, so a compiled training run gets wrong gradients on the last row and column of every `AvgPool2d(kernel, stride, ceil_mode=True)` layer with no error. Because the backward lowering `avg_pool2d_backward` uses `scale = kH * kW` whenever `count_include_pad` is set, rather than the window clipped to the padded input (`min(hstart + kH, H + pad) - hstart`) used by the eager kernel and the forward lowering, exactly the windows that `ceil_mode` lets overhang are divided by too much.

```python
import torch, torch.nn.functional as F

def grad_of(f, x, backend=None):
    x = x.detach().clone().requires_grad_()
    (f if backend is None else torch.compile(f, backend=backend))(x).sum().backward()
    return x.grad

x1 = torch.arange(6.0).reshape(1, 1, 6)          # avg_pool1d(k=3, s=2, ceil_mode=True): windows [0,1,2] [2,3,4] [4,5]
f1 = lambda x: F.avg_pool1d(x, 3, stride=2, ceil_mode=True)
x2 = torch.arange(36.0).reshape(1, 1, 6, 6)      # the GoogLeNet-style AvgPool2d(3, stride=2, ceil_mode=True)
f2 = lambda x: F.avg_pool2d(x, 3, stride=2, padding=1, ceil_mode=True)
for name, f, x in (("avg_pool1d k=3 s=2 ceil_mode", f1, x1), ("avg_pool2d k=3 s=2 p=1 ceil_mode", f2, x2)):
    torch._dynamo.reset()
    print(name, "| forward same:", torch.allclose(f(x), torch.compile(f)(x)))
    for backend in (None, "aot_eager", "inductor"):
        g = grad_of(f, x, backend)
        print(f"    {str(backend):10s} grad of last elements {[round(v, 4) for v in g.flatten()[-4:].tolist()]}")
```

```
avg_pool1d k=3 s=2 ceil_mode | forward same: True
    None       grad of last elements [0.6667, 0.3333, 0.8333, 0.5]
    aot_eager  grad of last elements [0.6667, 0.3333, 0.8333, 0.5]
    inductor   grad of last elements [0.6667, 0.3333, 0.6667, 0.3333]
avg_pool2d k=3 s=2 p=1 ceil_mode | forward same: True
    None       grad of last elements [0.2778, 0.5556, 0.2778, 0.6944]
    aot_eager  grad of last elements [0.2778, 0.5556, 0.2778, 0.6944]
    inductor   grad of last elements [0.2222, 0.4444, 0.2222, 0.4444]
```

In the 1-D case the last window `[4, 5]` has two elements, so eager's backward spreads `grad_output[2]` as `1/2` to each (element 4 gets `1/3 + 1/2 = 0.8333`, element 5 gets `0.5`); Inductor spreads it as `1/3`. With `count_include_pad=False` the compiled gradient is right (that branch computes the window size), and so is `ceil_mode=False` (no window overhangs). `avg_pool3d` goes through the fallback kernel and is right.

**Root cause and possible fix.** In `torch/_inductor/lowering.py::avg_pool2d_backward`:

```python
if divisor_override is not None:
    scale = divisor_override
elif count_include_pad or not had_padding:
    scale = kernel_size[0] * kernel_size[1]
else:
    scale = compute_pool_size_without_padding(ph, pw)
```

The eager kernel (`avg_pool2d_backward_out_frame`) computes `pool_size = (min(hstart + kH, H + padH) - hstart) * (min(wstart + kW, W + padW) - wstart)` for `count_include_pad=True`, i.e. it clips to the padded input before dividing; only the later clipping to `[0, H)` is skipped. The fix is to use that clipped size (the `hend` / `wend` values that `compute_pool_size_without_padding` computes before its final `ops.minimum(hend, height)`) as `scale` when `count_include_pad` is set and any `ceil_mode` overhang exists, matching what the forward lowering `_avg_poolnd` already does.

### Error logs

No error is raised; the compiled backward returns different gradient values, as shown above.

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

Same output on nightly 2.15.0.dev20260911+cpu, on Linux CPU, and on a Tesla T4 (2.14.0+cu130 and nightly 2.15.0.dev20260921+cu130).
