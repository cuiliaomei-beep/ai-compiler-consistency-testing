<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 25

| 项 | 值 |
|---|---|
| 提交优先级 | 25 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 9 条；草稿 `plan/issues_0910/09-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20channel_shuffle%20channels_last · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20native_channel_shuffle%20torch.compile · 2026-09-10 四组关键词无同报告；#189649（open，groups > channels 的 FPE）是另一问题；同族已修：#187195（max_unpool2d）、#179830 / #179272（upsample_nearest3d）、#179837（pad），open #192681（batch_norm fake strides） |
| 证据包 | `plan/reports_decomp/channel_shuffle_channels_last/`（`minimal_verified.py`、`DEDUP.md`），`plan/scripts/confirm_batch3.py` |
| 建议标签 | oncall: pt2, module: inductor, module: memory format |

---

## Title

[inductor] `F.channel_shuffle` / `native_channel_shuffle` drop the channels_last memory format of the input (eager and aot_eager preserve it)

## Body

### 🐛 Describe the bug

**Summary.** `F.channel_shuffle` on a channels_last input does not preserve memory format under Inductor: eager and `aot_eager` return a channels_last tensor, while Inductor returns a contiguous one, and `group_norm` on the same input keeps channels_last under Inductor (CPU, torch 2.14.0 and nightly). A user relying on the output layout for a following convolution gets an extra copy or a layout-dependent numerical difference without any message. Because the output strides are decided by the lowering rather than carried from the input as the eager kernel does, this joins the family already fixed for `max_unpool2d`, `upsample_nearest3d` and `pad`.

For a channels_last input, eager `torch.nn.functional.channel_shuffle` (and `torch.native_channel_shuffle`) return a channels_last tensor; `backend="aot_eager"` does too; `backend="inductor"` returns a contiguous (NCHW) tensor. `F.group_norm` on the same input keeps channels_last under Inductor, so this is specific to the channel_shuffle lowering. A ShuffleNet-style model that runs in channels_last therefore silently switches layout in the middle of the compiled graph, and any downstream `is_contiguous(memory_format=...)` / `stride()` / `as_strided` logic diverges from eager. This is the same class as the fixed #187195 (max_unpool2d), #179272 (upsample_nearest3d) and #179837 (pad).

```python
import torch
import torch.nn.functional as F

x = torch.randn(2, 6, 8, 8).contiguous(memory_format=torch.channels_last)

def f(x):
    return F.channel_shuffle(x, 2)

y = f(x)
print("eager    :", y.stride(), y.is_contiguous(memory_format=torch.channels_last))
for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    y = torch.compile(f, backend=backend)(x)
    print(f"{backend:<9}:", y.stride(), y.is_contiguous(memory_format=torch.channels_last))
```

Output on 2.14.0+cpu:

```
eager    : (384, 1, 48, 6) True
aot_eager: (384, 1, 48, 6) True
inductor : (384, 64, 8, 1) False
```

`torch.native_channel_shuffle(x, 2)` behaves identically. Values are equal; only the output strides differ.

Also on Linux CPU (Kaggle, torch 2.10.0+cu128): eager/aot_eager `(384, 1, 48, 6)`, inductor `(384, 64, 8, 1)`. (On CUDA the eager kernel itself returns a contiguous tensor, so there is no discrepancy there.)

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU), Linux CPU: eager/aot_eager `(384, 1, 48, 6)`, inductor `(384, 64, 8, 1)`.

Expected: the compiled output has the same memory format as eager (channels_last), as the other layout-preserving ops do after the fixes cited above.

### Error logs

No error; strides differ as shown.

### Versions

```
PyTorch version: 2.14.0+cpu
Is debug build: False
CUDA used to build PyTorch: None
ROCM used to build PyTorch: N/A

OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
GCC version: Could not collect
Clang version: Could not collect
CMake version: Could not collect
Libc version: N/A
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64 (used by Inductor's C++ backend)

Python version: 3.14.7 (tags/v3.14.7:823f032, Aug  5 2026, 10:51:32) [MSC v.1944 64 bit (AMD64)] (64-bit runtime)
Python platform: Windows-11-10.0.26200-SP0
Is CUDA available: False
CUDA runtime version: No CUDA
GPU models and configuration: No CUDA
Is XPU available: False
Is XNNPACK available: False

CPU:
Name: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
Manufacturer: GenuineIntel
Architecture: 9

Versions of relevant libraries:
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
[pip3] torchvision==0.29.0+cpu
[conda] Could not collect
```
