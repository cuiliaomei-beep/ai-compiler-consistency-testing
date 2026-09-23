<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 04: vector_norm(ord=inf) 空 batch 在 compile 下报错

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20vector_norm%20empty%20batch%20compile · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20vector_norm%20cannot%20compute%20the%20inf%20norm · 2026-09-10 五组关键词无同报告；#148809（2025-04 改过同一检查）保留了 `numel()` 判断 |
| 证据包 | `plan/reports_decomp/vector_norm_empty_batch/`（`minimal_verified.py`、`DEDUP.md`、`ISSUE_FINAL.md`），`plan/scripts/verify_issue_claims.py` |
| 建议标签 | oncall: pt2, module: fakeTensor, module: decompositions, module: linear algebra |

---

## Title

[pt2] `linalg.vector_norm(ord=inf / -inf / negative, dim=-1)` on an empty *batch* fails at trace time — the empty-dimension check in `_refs/linalg` does not canonicalize a negative `dim` (eager returns an empty result)

## Body

### 🐛 Describe the bug

`torch.linalg.vector_norm(x, ord=float("inf"), dim=-1)` with `x` of shape `(0, 5)` returns `tensor([])` (shape `(0,)`) in eager: the reduced dimension has 5 elements, only the batch dimension is empty. Under `torch.compile` — with `backend="eager"`, `"aot_eager"` and `"inductor"` alike, i.e. already at Dynamo's fake-tensor tracing — the reference implementation raises

```
linalg.vector_norm cannot compute the inf norm on the dimension -1 because this dimension is empty and the operation does not have an identity
```

The dimension `-1` is *not* empty; it is the batch dimension that is. Writing the same reduction with a non-negative index (`dim=1`) compiles fine. Same for `ord=-inf` and any negative `ord`; `ord=2`, `0.5`, `0` (which have an identity) are fine. Also reachable through `torch.norm(x, p=float("inf"), dim=-1)` and `torch.linalg.norm(x, ord=float("inf"), dim=-1)`. A batch that happens to be empty (max-norm gradient clipping, per-row norms of a masked/empty selection) therefore crashes compiled code that works eagerly — and `dim=-1` is the usual spelling.

```python
import torch

x = torch.empty(0, 5)

def f(x):
    return torch.linalg.vector_norm(x, ord=float("inf"), dim=-1)

print("eager   :", f(x))                                       # tensor([])
for backend in ("aot_eager", "inductor"):
    torch._dynamo.reset()
    try:
        print(backend, ":", torch.compile(f, backend=backend)(x))
    except Exception as e:
        print(backend, ": raised", type(e).__name__)           # TorchRuntimeError (RuntimeError: linalg.vector_norm cannot compute the inf norm on an empty tensor ...)
```

| call on `x` of shape `(0, 5)` | eager | torch.compile (eager / aot_eager / inductor backends) |
|---|---|---|
| `vector_norm(x, ord=inf, dim=-1)` | `tensor([])` | **error** |
| `vector_norm(x, ord=inf, dim=(-1,))` | `tensor([])` | **error** |
| `vector_norm(x, ord=-2.1, dim=-1)` | `tensor([])` | **error** |
| `vector_norm(x, ord=inf, dim=1)` | `tensor([])` | ok |
| `vector_norm(x, ord=inf, dim=(1,))` | `tensor([])` | ok |
| `vector_norm(x, ord=2, dim=-1)` | `tensor([])` | ok |
| `vector_norm(x, ord=inf, dim=0)` (reducing the empty dim) | error (correct) | error (correct) |
| `vector_norm(torch.randn(3, 5), ord=inf, dim=-1)` | ok | ok |

Also reproduces on Linux (Kaggle, torch 2.10.0+cu128) on CPU and on a Tesla T4: `dim=-1` fails at trace time, `dim=1` compiles.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): `dim=-1` fails at trace time under aot_eager and inductor on CPU and CUDA, `dim=1` compiles.

Cause: `_check_vector_norm_args` in `torch/_refs/linalg/__init__.py` (2.14.0, lines 119–126) checks, for every requested dim `d`,

```python
torch._check(
    sym_or(x.numel() != 0, d < len(shape) and d >= 0 and shape[d] != 0),
    lambda: f"linalg.vector_norm cannot compute the {ord} norm on the dimension {d} because this dimension is empty ...",
)
```

`d` is the raw user value: for `d = -1` the predicate `d >= 0` is false, and because `x.numel() == 0` for an empty batch the `sym_or` fails. The dimension has to be canonicalized (`d % ndim`, as eager's C++ check does) before `shape[d]` is inspected. #148809 inlined the size-oblivious guards of this check but kept the un-normalized index.

Expected: `tensor([])` of shape `(0,)`, as in eager — the reduced dimension is not empty.

### Error logs

```
torch._dynamo.exc.TorchRuntimeError: RuntimeError when making fake tensor call
...
  File "...\torch\_refs\linalg\__init__.py", line 146, in vector_norm
    _check_vector_norm_args(x, ord, dim)
  File "...\torch\_refs\linalg\__init__.py", line 121, in _check_vector_norm_args
    torch._check(
RuntimeError: linalg.vector_norm cannot compute the inf norm on the dimension -1 because this dimension is empty and the operation does not have an identity
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
