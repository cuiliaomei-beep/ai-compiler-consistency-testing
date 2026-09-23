<!-- 提交信息（不要复制到 issue 里）；Summary 段按 SUMMARY_WRITING_GUIDE.md 的三句结构写：事实 / 困惑 / 暴露 -->
# pytorch/pytorch — issue 15

| 项 | 值 |
|---|---|
| 提交优先级 | 15 / 27 |
| 原候选编号 | TO_SUBMIT.md 第 8 条；草稿 `plan/issues_0910/08-*.md` |
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml`（🐛 torch.compile Bug Report，label: oncall: pt2） |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20binary_cross_entropy%20weight%20dtype%20compile · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20binary_cross_entropy%20bfloat16%20inductor%20float32 · 2026-09-10 四组关键词无同报告；**#171282**（closed 2026-03-19）是 `binary_cross_entropy_with_logits` 的同一症状，2.14 上 with_logits 已一致、plain 版未修 |
| 证据包 | `plan/reports_decomp/bce_weight_dtype/`（`minimal_verified.py`、`DEDUP.md`），`plan/scripts/confirm_decomp_batch2.py` |
| 建议标签 | oncall: pt2, module: inductor, module: decompositions |

---

## Title

[inductor] `binary_cross_entropy` with a weight of another dtype and `huber_loss` with mixed low-precision inputs return float32 under Inductor; eager and aot_eager return the input dtype

## Body

### 🐛 Describe the bug

**Summary.** `F.binary_cross_entropy` with a `weight` of a different floating dtype and `F.huber_loss` with mixed low-precision inputs do not return the same dtype in eager and under Inductor: eager and `aot_eager` return the input dtype (bfloat16 or float16), while Inductor returns float32, or float64 when the other operand is float64 (CPU; torch 2.14.0 and nightly). A user running a bf16 or fp16 training loop gets a float32 loss after compilation with no message, and `mse_loss`, `l1_loss` and `smooth_l1_loss` on the same inputs agree across all three paths, so only these two losses stand out. Because the result dtype is decided by the Inductor lowering of these two ops rather than by the operator's promotion rule, the divergence appears exactly where the eager kernel and the lowering disagree.

`torch.nn.functional.binary_cross_entropy(input, target, weight=w)` with bfloat16 (or float16) `input`/`target` and a float32 `weight` returns a **bfloat16** tensor in eager and with `backend="aot_eager"`, but a **float32** tensor with `backend="inductor"`. Without `weight`, or with a bf16 `weight`, all three agree on bfloat16. `binary_cross_entropy_with_logits` with a float32 weight is consistent (bf16) on 2.14 — that variant was reported as #171282 and fixed; the plain `binary_cross_entropy` decomposition (`torch/_decomp/decompositions.py`: `loss = loss * weight`) still promotes.

```python
import torch
import torch.nn.functional as F

torch.manual_seed(0)
p = torch.rand(4, 3).to(torch.bfloat16)
t = torch.rand(4, 3).to(torch.bfloat16)
w = torch.rand(4, 3)  # float32

def f(p, t, w):
    return F.binary_cross_entropy(p, t, weight=w)

print("eager    :", f(p, t, w).dtype)                                            # torch.bfloat16
for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    print(f"{backend:<9}:", torch.compile(f, backend=backend)(p, t, w).dtype)  # aot_eager: bfloat16, inductor: float32
```

| inputs | weight | eager | aot_eager | inductor |
|---|---|---|---|---|
| bf16 | float32, `reduction="mean"` | bf16 | bf16 | **float32** |
| bf16 | float32, `reduction="none"` | bf16 `(4,3)` | bf16 | **float32** |
| bf16 | none | bf16 | bf16 | bf16 |
| bf16 | bf16 | bf16 | bf16 | bf16 |
| fp16 | float32 | fp16 | fp16 | **float32** |
| bf16 | float32, `_with_logits` | bf16 | bf16 | bf16 (fixed by #171282) |

Also on Linux CPU (Kaggle, torch 2.10.0+cu128): eager/aot_eager bfloat16, inductor float32. On CUDA (T4) all three return bfloat16, so the promotion is in the CPU lowering path.

Another op with the same symptom (found 2026-09-12 by a dtype-promotion sweep): `F.huber_loss(input_fp16, target_bf16/fp32/fp64)` returns float16 in eager and aot_eager but float32 (float64 for an fp64 target) under Inductor; bf16 input behaves the same, and `delta=` / `reduction="none"` do not change it. `F.smooth_l1_loss`, `F.mse_loss` and `F.l1_loss` with the same inputs agree across all three, so it is specific to the `huber_loss` and `binary_cross_entropy` lowerings. Reproduces on Linux CPU (2.14.0 and the 2026-09-12 nightly); on CUDA eager itself returns float32 so there is no discrepancy there. Script: `scripts/diag_dtype_leads.py`.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU), Linux CPU: eager/aot_eager bfloat16 (0.5039), inductor float32 (0.5014); CUDA consistent.

A related observation on the same op: with a float32 *target* eager raises `RuntimeError: Found dtype Float but expected BFloat16` while inductor computes a float32 result — the compile path lacks eager's dtype check (the family tracked in #144362).

Expected: the output dtype of eager (bfloat16 / float16), as for `binary_cross_entropy_with_logits`.

### Error logs

No error; the dtype differs as shown.

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
