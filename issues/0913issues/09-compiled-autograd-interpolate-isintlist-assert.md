<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 09

| 项 | 值 |
|---|---|
| 提交优先级 | 09 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 25 条；草稿 `plan/issues_0910/25-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows Py3.14 + Linux Py3.11）；nightly 2.15.0.dev20260911（Windows）/ dev20260912（Linux，`kaggle_out/calinux.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20compiled_autograd%20interpolate · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20isIntList%20compiled_autograd（`results/dedup_0913b.txt`，无同报告） |
| 证据包 | `plan/scripts/diag_compiled_autograd_interpolate.py`，`plan/scripts/compiled_autograd_diff.py` + `plan/results/compiled_autograd/COMPILED_AUTOGRAD.md`（全部 float32 自动求导 OpInfo 算子的 compiled_autograd 差分：只有 interpolate/upsample 家族失败） |
| 建议标签 | oncall: pt2, module: compiled autograd, module: dynamo |
| 备注 | compiled_autograd 是 opt-in 功能，但 interpolate 是 CNN/分割模型的常规算子；错误里带 "INTERNAL ASSERT FAILED ... please report a bug"。`nearest` / `nearest-exact` / `area` 正常，只有带 `align_corners` + `scales` 双精度参数的 upsample 反向出错 |

---

## Title

[compiled autograd] backward of `F.interpolate(mode="bilinear"/"bicubic"/"linear"/"trilinear")` fails with `isIntList() INTERNAL ASSERT FAILED` while running meta for `aten.upsample_bilinear2d_backward`

## Body

### 🐛 Describe the bug

**Summary.** With compiled autograd enabled, the backward of `F.interpolate` in `bilinear`, `bicubic`, `linear` and `trilinear` modes does not run: eager backward and the `nearest`/`area` modes work, while the compiled-autograd graph fails in fake-tensor propagation with `isIntList() INTERNAL ASSERT FAILED` for `aten.upsample_bilinear2d_backward` under every backend (torch 2.14.0 and nightly, Windows and Linux). A user who turns on compiled autograd for a segmentation or super-resolution model gets an internal assertion at the first backward pass instead of a graph break. Because the `UpsampleBilinear2DBackward0` node packs `output_size`, `align_corners` and the scale factors in a form the meta kernel does not accept, every upsample backward that carries these arguments is affected.

With compiled autograd enabled, the backward pass of `F.interpolate` in the linear-interpolation modes fails inside Dynamo's fake-tensor propagation. Plain eager backward is fine, and so are `mode="nearest"`, `"nearest-exact"` and `"area"`.

```python
import torch
import torch.nn.functional as F

x = torch.randn(1, 2, 4, 4, requires_grad=True)
y = F.interpolate(x, scale_factor=2, mode="bilinear")        # same with size=(8, 8), align_corners=True, bicubic, linear, trilinear
y.sum().backward()                                            # eager: fine

x.grad = None
with torch._dynamo.compiled_autograd._enable(torch.compile(backend="eager")):   # same with aot_eager / inductor
    F.interpolate(x, scale_factor=2, mode="bilinear").sum().backward()
```

```
torch._dynamo.exc.TorchRuntimeError: RuntimeError when making fake tensor call
  Explanation: Dynamo failed to run FX node with fake tensors: call_function
    torch._dynamo.compiled_autograd.ops.UpsampleBilinear2DBackward0(*([FakeTensor(..., size=(1, s79, s57, s40))], [True], False, [...], 2.0, 2.0, [...]), **{}):
  got RuntimeError('isIntList() INTERNAL ASSERT FAILED at "...aten/src/ATen/core/ivalue_inl.h"...')
E ... failed while attempting to run meta for aten.upsample_bilinear2d_backward.default
```

Matrix (torch 2.14.0+cpu; identical on the 2026-09-11 nightly; compiled-autograd backend eager / aot_eager / inductor all behave the same):

| interpolate call | eager backward | compiled autograd |
|---|---|---|
| `mode="nearest"`, size or scale_factor | ok | ok |
| `mode="nearest-exact"`, scale_factor | ok | ok |
| `mode="area"` | ok | ok |
| `mode="bilinear"`, size=(8,8) / scale_factor=2 / align_corners=True / recompute_scale_factor=True | ok | **INTERNAL ASSERT** |
| `mode="bicubic"`, size or scale_factor | ok | **INTERNAL ASSERT** |
| `mode="linear"` (3-d input), `mode="trilinear"` (5-d input) | ok | **INTERNAL ASSERT** |
| `F.adaptive_avg_pool2d`, `F.conv2d` (controls) | ok | ok |

The generated compiled-autograd op `UpsampleBilinear2DBackward0` receives its arguments as `([grad], [True], False, [sym sizes], 2.0, 2.0, [sym sizes])`; the meta function for `aten.upsample_bilinear2d_backward` then trips `isIntList()` — the `output_size` / `input_size` int lists and the `align_corners` / `scales_h` / `scales_w` scalars appear to be packed in a different order or type from what the meta kernel expects. Only the upsample backward nodes that carry `align_corners` and optional `double` scale arguments fail; the nearest variants (no `align_corners`) are fine.

Expected: compiled autograd computes the same gradient as eager (or at least graph-breaks / falls back for this node instead of an internal assertion).

Found by running compiled autograd over every float32 OpInfo operator with autograd support and comparing input gradients with eager: the interpolate / upsample family were the only operators that failed (`scripts/compiled_autograd_diff.py`).

### Error logs

```
E torch/_subclasses/fake_tensor.py:3212 failed while attempting to run meta for aten.upsample_bilinear2d_backward.default
RuntimeError: isIntList() INTERNAL ASSERT FAILED at "...\\aten\\src\\ATen\\core\\ivalue_inl.h": ... please report a bug to PyTorch.
torch._dynamo.exc.TorchRuntimeError: RuntimeError when making fake tensor call
  Explanation: Dynamo failed to run FX node with fake tensors: call_function torch._dynamo.compiled_autograd.ops.UpsampleBilinear2DBackward0(...)
```

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14; same on the 2026-09-11 nightly wheel and on Linux / Python 3.11 with torch 2.14.0+cpu and 2.15.0.dev20260912+cpu. Full `collect_env` as in the other drafts.)
