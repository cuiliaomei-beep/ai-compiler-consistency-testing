<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 11: aoti_compile_and_package 不能序列化 torch.return_types 输出

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（git `08187d9e0fba026dc8217405802ab5381dc88d90`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20aoti_compile_and_package%20return_types · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20No%20registered%20serialization%20name%20return_types · 2026-09-10 无同报告；相关 open PR #113258（pytree 对 PyStructSequence 的支持，2023 起未合） |
| 证据包 | `plan/reports_aoti/return_types_packaging/`（`minimal_verified.py`、`DEDUP.md`），`plan/scripts/diag_aoti.py` |
| 建议标签 | oncall: pt2, oncall: export, module: aotinductor, module: pytree |
| 严重度 | 低–中（可用性；有绕过办法） |

---

## Title

[aoti] `aoti_compile_and_package` fails for any model returning a `torch.return_types.*` named tuple (`torch.max(x, dim)`, `topk`, `cummax`, …): "No registered serialization name for <class 'torch.return_types.max'>"

## Body

### 🐛 Describe the bug

A module whose output is the named tuple returned by `torch.max(x, dim=...)`, `torch.min(x, dim=...)`, `torch.sort`, `torch.topk`, `torch.mode`, `torch.kthvalue`, `torch.nanmedian`, `torch.cummax` / `cummin`, `torch.aminmax`, `torch.frexp`, `torch.histogram` / `histogramdd`, `torch.svd`, `torch.geqrf`, `torch.lu_unpack`, `torch.triangular_solve`, and every `torch.linalg.*` that returns a structseq (`eig`, `eigh`, `qr`, `slogdet`, `lu`, `lu_factor`, `lu_factor_ex`, `ldl_factor`, `ldl_factor_ex`, `cholesky_ex`, `inv_ex`, `polar`, …) exports and compiles fine, but `torch._inductor.aoti_compile_and_package` cannot serialize the output pytree:

```
NotImplementedError: No registered serialization name for <class 'torch.return_types.max'> found.
Please update your _register_pytree_node call with a `serialized_type_name` kwarg.
```

The message refers to an internal registration the user cannot change. Unpacking the named tuple (`v, i = torch.max(x, dim=0); return v, i`) packages fine, so this is purely the pytree serialization of the structseq types.

```python
import os, tempfile, torch
from torch.export import export
from torch._inductor import aoti_compile_and_package, aoti_load_package

class MaxDim(torch.nn.Module):
    def forward(self, x):
        return torch.max(x, dim=0)          # torch.return_types.max

class MaxDimUnpacked(torch.nn.Module):
    def forward(self, x):
        v, i = torch.max(x, dim=0)
        return v, i

x = torch.randn(4, 5)
work = tempfile.mkdtemp()
for name, m in (("return_types.max", MaxDim()), ("plain tuple", MaxDimUnpacked())):
    ep = export(m, (x,))                     # ok for both
    try:
        p = aoti_compile_and_package(ep, package_path=os.path.join(work, name[:5] + ".pt2"))
        print(name, "aoti ok", [tuple(t.shape) for t in aoti_load_package(p)(x)])
    except Exception as e:
        print(name, type(e).__name__, str(e)[:120])
```

Output on 2.14.0+cpu:

```
return_types.max NotImplementedError: No registered serialization name for <class 'torch.return_types.max'> found. Please update your _register_pytree_node call with a `serialized_type_name` kwarg.
plain tuple aoti ok [(5,), (5,)]
```

`torch.compile` on the same module works and returns the named tuple; `ep.module()(x)` also returns it. Same failure on Linux (Kaggle, torch 2.14.0+cu130) with CPU and CUDA tensors. In a sweep over the OpInfo database (`torch.testing._internal.common_methods_invocations.op_db`, one sample per operator, 2.14.0+cpu) this was the failure for 33 of the 35 operators whose AOTI packaging failed at all.

Still present on nightly torch 2.15.0.dev20260911+cu130 (nightly, git fb8ff0f1, Kaggle: Tesla T4 + Linux CPU): `NotImplementedError: No registered serialization name for <class 'torch.return_types.max'>` with CPU and CUDA tensors.

Expected: either the structseq types carry a `serialized_type_name` so the package round-trips them (as plain tuples or as the named tuple), or export normalises them to tuples with a clear note — not an error naming an internal API.

### Error logs

```
  File "...\torch\_inductor\__init__.py", line 206, in _aoti_compile_and_package_inner
  File "...\torch\_inductor\__init__.py", line 322, in aot_compile
  File "...\torch\_inductor\compile_fx.py", line 3466, in _aoti_flatten_inputs
  File "...\torch\utils\_pytree.py", line 2079, in treespec_dumps
  File "...\torch\utils\_pytree.py", line 1999, in _treespec_to_json
NotImplementedError: No registered serialization name for <class 'torch.return_types.max'> found. Please update your _register_pytree_node call with a `serialized_type_name` kwarg.
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
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64 (used by Inductor / AOTI C++ backend)

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
