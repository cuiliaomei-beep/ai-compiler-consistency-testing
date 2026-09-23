<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 12

| 项 | 值 |
|---|---|
| 提交优先级 | 12 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 3 条；草稿 `plan/issues_0910/03-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20interpolate%20empty%20tensor%20compile · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20upsample%20empty%20input%20torch.compile · 2026-09-10 五组关键词无同报告；同族 open #193811（upsample_bilinear2d 在 compile 下接受 int32）、#195550（adaptive_avg_pool2d 校验）——不同检查，本条特点是越界读 |
| 证据包 | `plan/reports_decomp/interpolate_zero_size/`（`minimal_verified.py`、`DEDUP.md`、`ISSUE_FINAL.md`），`plan/scripts/confirm_decomp_batch2.py` |
| 建议标签 | oncall: pt2, module: inductor, module: decompositions, topic: memory safety |

---

## Title

[inductor] `F.interpolate` on a zero-size spatial dim returns uninitialised data (NaN) from an out-of-bounds read instead of raising; output size 0 is accepted silently

## Body

### 🐛 Describe the bug

**Summary.** `F.interpolate` on an input with an empty spatial dimension does not behave the same in eager and under Inductor: eager raises "Input and output sizes should be greater than 0", `aot_eager` raises IndexError, while Inductor returns a `(2, 3, 3)` tensor of NaN read from outside a zero-element buffer (CPU and CUDA, torch 2.14.0 and nightly). A user who compiles a pipeline that occasionally sees empty batches gets NaN outputs downstream instead of the error eager would have raised. Because the generated kernel reads past a zero-element input rather than checking it, the out-of-bounds read is decided by the lowering, and on CUDA the same access pattern is an illegal memory access waiting to happen.

Eager `torch.nn.functional.interpolate` validates the spatial sizes and raises `RuntimeError: Input and output sizes should be greater than 0`. Under `torch.compile` that check never runs: `backend="aot_eager"` raises an `IndexError` from the decomposition's gather, and `backend="inductor"` **returns a tensor of the requested shape filled with NaN** — the generated kernel reads past a 0-element buffer (no bounds check is emitted for that load). On CUDA an unchecked load of this kind would be an illegal memory access.

```python
import torch
import torch.nn.functional as F

x = torch.empty(2, 3, 0)          # empty spatial dim

def f(x):
    return F.interpolate(x, size=3, mode="nearest")

try:
    f(x)
except RuntimeError as e:
    print("eager    :", e)         # Input and output sizes should be greater than 0, but got input (W: 0) and output (W: 3)

torch._dynamo.reset()
try:
    torch.compile(f, backend="aot_eager")(x)
except Exception as e:
    print("aot_eager:", type(e).__name__)   # TorchRuntimeError (IndexError: index is out of bounds for dimension with size 0)

torch._dynamo.reset()
out = torch.compile(f, backend="inductor")(x)
print("inductor :", out.shape, int(torch.isnan(out).sum()), "NaNs")   # torch.Size([2, 3, 3]) 18 NaNs
```

Same for `mode="linear"` (1-D) and `mode="bilinear"` with `H = 0` on a 4-D input. The reverse case is also accepted silently: with `x = torch.randn(2, 3, 1)`, `F.interpolate(x, scale_factor=0.6, mode="nearest", recompute_scale_factor=False)` raises in eager (output size 0) but returns an empty `(2, 3, 0)` tensor under compile (and `ZeroDivisionError` inside the fake-tensor path with `recompute_scale_factor=True`).

| case | eager | aot_eager | inductor |
|---|---|---|---|
| `(2,3,0)` → `size=3`, nearest | RuntimeError | IndexError | `(2,3,3)` all NaN |
| `(2,3,0)` → `size=3`, linear | RuntimeError | IndexError | `(2,3,3)` all NaN |
| `(1,2,0,4)` → `size=(3,3)`, bilinear | RuntimeError | IndexError | `(1,2,3,3)` all NaN |
| `(2,3,1)` → `scale_factor=0.6` (output 0), nearest | RuntimeError | `(2,3,0)` | `(2,3,0)` |

Not Windows-specific: the same call on Linux (Kaggle, torch 2.10.0+cu128) gives the identical outcome on **CPU** and on a **Tesla T4** (`inductor: (2, 3, 3) nan 18` after `torch.cuda.synchronize()`, eager raises).

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): eager raises, inductor returns `(2, 3, 3)` with 18 NaNs on both CPU and CUDA.

Cause: the eager check lives in the C++ kernels (and in `upsample_common_check` of the meta registration), but `upsample_nearest1d.vec` / `upsample_linear1d.vec` and the 2-D variants are decomposed by their `CompositeImplicitAutograd` `py_impl` in `torch/_decomp/decompositions.py` *before* any meta check runs, and the decomposition does not validate the sizes. Inductor then lowers an `index` with a source index computed from a 0-size dim.

Expected: the same `RuntimeError` as eager (or at least an error), never a tensor of uninitialised memory.

### Error logs

No error is raised by Inductor (that is the problem). aot_eager raises from the decomposition's gather at run time:

```
IndexError: index is out of bounds for dimension with size 0
```

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
