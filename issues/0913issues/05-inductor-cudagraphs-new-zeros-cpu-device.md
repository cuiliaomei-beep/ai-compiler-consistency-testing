<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 05

| 项 | 值 |
|---|---|
| 提交优先级 | 05 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 13 条；草稿 `plan/issues_0910/13-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cu130（Kaggle，Tesla T4，Linux）；torch 2.10.0+cu128 同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20cudagraphs%20new_zeros%20device%20cpu · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20cudagraphs%20cpu%20output%20wrong%20device · 2026-09-11 五组关键词无同报告；相关 open PR #190555（cudagraph 分区里跨设备的 fallback 内核读 CPU 输入，issue #190233）是同一"跨设备 + cudagraph"家族，但症状是读错内存，不是输出设备被改 |
| 证据包 | `plan/kaggle_out/gpuverify/tcc-gpuverify.log`（G1 / G1b），`plan/kaggle_out/gpucuda/plan/gpu_results_meta_cfg/METAMORPHIC.md`（配置差分原始命中），`plan/scripts/verify_candidates_cuda.py` |
| 建议标签 | oncall: pt2, module: inductor, module: cuda graphs |
| 备注 | 只在开 cudagraphs 时出现；`torch.compile(mode="reduce-overhead")` 默认打开 cudagraphs，所以普通用户会撞到 |

---

## Title

[inductor][cudagraphs] `x.new_zeros(shape, device="cpu")` inside a compiled function returns a **CUDA** tensor when `triton.cudagraphs` is on (eager and default config return a CPU tensor)

## Body

### 🐛 Describe the bug

**Summary.** With `triton.cudagraphs` enabled, `x.new_zeros(shape, device="cpu")` for a CUDA `x` does not return the device the program asked for: eager and the default compiled configuration return a CPU tensor, while the cudagraphs path returns a CUDA tensor (torch 2.10.0+cu128 and 2.14.0+cu130, Tesla T4). A user who enables `mode="reduce-overhead"` gets tensors on the wrong device downstream, which surfaces as device-mismatch errors far from the line that created the tensor. Because the device is decided by the cudagraphs lowering rather than by the explicit `device=` argument, it is the compilation mode and not the program that determines where the tensor lives.

A compiled function that creates a tensor with an explicit `device="cpu"` (here `x.new_zeros((2, 3), device="cpu")` with `x` on CUDA) returns a CPU tensor in eager mode and with the default Inductor configuration, but a **CUDA** tensor when CUDA graphs are enabled (`torch._inductor.config.triton.cudagraphs = True`, which is what `mode="reduce-overhead"` sets). The explicit device argument is silently overridden, so downstream code that expects a CPU tensor (e.g. feeding it to a CPU-only op, `.numpy()`, or comparing `.device`) breaks only in the cudagraphs configuration.

```python
import torch
from torch._inductor import config as IC

def f(x):
    return x.new_zeros((2, 3), device="cpu")

x = torch.randn(5, device="cuda")
print("eager            :", f(x).device)                          # cpu

torch._dynamo.reset()
print("inductor default :", torch.compile(f)(x).device)           # cpu

torch._dynamo.reset()
with IC.patch({"triton.cudagraphs": True}):
    print("inductor cudagraph:", torch.compile(f)(x).device)      # cuda:0   <-- wrong
# equivalently: torch.compile(f, mode="reduce-overhead")(x).device
```

Observed on a Tesla T4 with torch 2.14.0+cu130 (and 2.10.0+cu128):

| configuration | output device |
|---|---|
| eager | cpu |
| `torch.compile(f)` (default) | cpu |
| `torch.compile(f)` with `triton.cudagraphs=True` | **cuda:0** |

Values are all zeros in every case; only the device differs. Found by a configuration differential that compiles the same OpInfo sample under several Inductor configurations and compares the results with each other (the OpInfo sample for `new_zeros` passes `device='cpu'` explicitly).

Expected: a CPU tensor, as eager and the default configuration produce — or, if a CPU-resident output cannot live in a CUDA-graph-captured region, the graph should be partitioned around it (as #190555 proposes for cross-device *fallback* kernels) rather than moving the result to the wrong device.

### Error logs

No error; the output device differs as shown.

### Versions

```
PyTorch version: 2.14.0+cu130
Is debug build: False
CUDA used to build PyTorch: 13.0
OS: Ubuntu 22.04 (Kaggle notebook image), Linux 6.12, glibc 2.35
Python version: 3.12.13
GPU: Tesla T4 (compute capability 7.5), driver as provided by the Kaggle image
Is CUDA available: True
Versions of relevant libraries:
[pip3] torch==2.14.0+cu130 (installed from PyPI into the Kaggle image)
```

(The same reproducer on torch 2.10.0+cu128 / Tesla T4 behaves identically.)

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): with `triton.cudagraphs=True` the compiled function returns a CUDA tensor, eager and the default config return a CPU tensor.
