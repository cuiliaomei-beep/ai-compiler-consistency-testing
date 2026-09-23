<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 31（高：复数 `linalg.pinv` / `polar` / `matrix_sqrth` 在任何 TorchDispatchMode 下（因此在 torch.compile 下）返回错值——ATen 内核内部的共轭视图未被应用；这是 #197084 的真正根因）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；complex64 与 complex128 都错，float32 正确；Linux CPU 2.14.0 与 nightly dev20260921 同 Windows；Tesla T4 CUDA（2.14.0+cu130 与 nightly）：`polar` 同样错（|mode − eager| 2.07 / 1.78），`pinv` 在 CUDA 上正确（cuSOLVER 路径不走同一内部公式）——Kaggle `tcc-conjgpu`，`plan/kaggle_out/conjgpu/log.txt` |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/bug-report.yml`（核心分发器缺陷，不是 PT2 专属；torch.compile 只是最常见入口） |
| 提交前查重 | 2026-09-22：`TorchDispatchMode conj complex wrong result`、`conjugate view TorchDispatchMode composite kernel`、`Python dispatch key conjugate fallback skipped`、`linalg.pinv complex compile wrong`、`linalg.polar torch.compile complex`、`conj bit lost dispatch mode mH`：无同报告。相关：**#197084（你自己的，第一轮）**报的是 pinv 复数梯度在 compile 下错，归因于 AOTAutograd 追踪反向公式——本 issue 证明那个归因不对：前向值本身就错，且一个只做转发的 TorchDispatchMode 就能在 eager 里逐位复现 compile 的梯度；32 号稿在 #197084 下更正 |
| 证据包 | `plan/reports_pairs/conj_lost_under_dispatch_mode.py`（主复现）、`python_key_conj_composites.py`（51 个复数 linalg 组合内核，只有 pinv/pinverse/polar 出错）、`$TEMP/linalg_scan.py` 逻辑已并入（全 `torch.linalg` 命名空间扫描：pinv、polar、matrix_sqrth）；发现来源 `scripts/opinfo_edge_sweep.py` int64/float64/complex64 组（Linux，`linalg.polar complex64` 一行）→ 逐层定位到 `_AnalyzeCustomOpInputOutputMode` → 任意 TorchDispatchMode → 排除 Conjugate 分发键可复现 |
| 根因（观察到的机制） | 在 `__torch_dispatch__` 里调用 `func(*args)` 时，TLS 的 include 集含 `Python` 键；`aten.linalg_pinv` 等 C++ 组合内核在内部对 SVD 结果取 `.mH()`（惰性共轭视图）再 `matmul`，此时共轭没有被物化：pinv 结果恰等于 `vh.mT @ diag(1/s) @ u.mH`（`vh` 少了一次共轭）；`polar` 的 `P` 变成 `(X + X.mT)/2`（虚部相消）。同样的公式在 Python 里逐算子写出、在同一个 mode 下计算是对的（每个算子单独经过分发器，共轭回退会跑）。`torch._C._ExcludeDispatchKeyGuard(Conjugate)` 下的 eager 结果与之完全一致，说明 Python 键存在时组合内核内部的 Conjugate 回退被跳过 |
| 影响范围 | 任何 TorchDispatchMode（LoggingTensorMode、FakeTensorMode 之外的用户 mode、`torch.compile` 运行时的 `_AnalyzeCustomOpInputOutputMode`、`torch.export` 的 mode 等）下，复数 `linalg.pinv` / `pinverse` / `linalg.polar` / `linalg.matrix_sqrth` 的前向值与依赖它们的梯度 |
| 建议标签 | module: complex, module: linear algebra, module: __torch_dispatch__, module: correctness (silent), oncall: pt2 |

---

## Title

Complex `linalg.pinv` / `linalg.polar` / `linalg.matrix_sqrth` return wrong values under any `TorchDispatchMode` (hence under `torch.compile`): a conjugate view taken inside the ATen kernel is not applied

## Body

### 🐛 Describe the bug

**Summary.** Complex `torch.linalg.pinv`, `linalg.polar` and `linalg.matrix_sqrth` return one result in plain eager and another while any `TorchDispatchMode` is active, even one that only calls `func(*args)`, and `torch.compile` returns the second because its runtime runs every graph under `_AnalyzeCustomOpInputOutputMode` (torch 2.14.0 and nightly; float inputs are unaffected). A user gets `A @ pinv(A) @ A != A` and `U @ P != A` with no error, and every gradient built on these values (#197084) is wrong for the same reason. Because the kernel conjugates the SVD factors internally with `.mH()` and that lazy conjugate view is consumed unmaterialized when the `Python` dispatch key is in the thread-local include set, rather than through the Conjugate fallback that the same formula written op by op uses, the result equals `vh.mT @ diag(1/s) @ u.mH`.

```python
import torch
from torch.utils._python_dispatch import TorchDispatchMode

class Forward(TorchDispatchMode):            # does nothing but forward
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))

def manual_pinv(a):                          # the same formula, op by op
    u, s, vh = torch.linalg.svd(a, full_matrices=False)
    return vh.mH @ torch.diag(1 / s).to(a.dtype) @ u.mH

torch.manual_seed(0)
A = torch.randn(4, 3, dtype=torch.complex64)
ref = torch.linalg.pinv(A)
with Forward():
    under_mode, manual = torch.linalg.pinv(A), manual_pinv(A)
torch._dynamo.reset()
compiled = torch.compile(torch.linalg.pinv)(A)
u, s, vh = torch.linalg.svd(A, full_matrices=False)
print("|pinv under mode - eager|   ", (under_mode - ref).abs().max().item())
print("|pinv compiled   - eager|   ", (compiled - ref).abs().max().item())
print("|op-by-op under mode - eager|", (manual - ref).abs().max().item())
print("under mode == vh.mT @ S^-1 @ u.mH:", torch.allclose(under_mode, vh.mT @ torch.diag(1 / s).to(A.dtype) @ u.mH, atol=1e-5))
print("A @ pinv(A) @ A == A:  eager", torch.allclose(A @ ref @ A, A, atol=1e-5), " compiled", torch.allclose(A @ compiled @ A, A, atol=1e-5))
P = torch.linalg.polar(A)[1]
with Forward():
    P_mode = torch.linalg.polar(A)[1]
print("polar P[0, 1]: eager", P[0, 1].item(), " under mode", P_mode[0, 1].item())
```

```
|pinv under mode - eager|    1.1541486978530884
|pinv compiled   - eager|    1.1541486978530884
|op-by-op under mode - eager| 0.0
under mode == vh.mT @ S^-1 @ u.mH: True
A @ pinv(A) @ A == A:  eager True  compiled False
polar P[0, 1]: eager (0.34345024824142456+0.11318771541118622j)  under mode (0.34345024824142456+0j)
```

How this was narrowed down: the compiled graph contains only `aten.linalg_polar.default` / `aten.linalg_pinv.atol_rtol_tensor` (no decomposition), and running that graph module directly gives the eager result; inside AOTAutograd's runtime wrapper the same call is wrong, and the only difference in dispatcher state there is the active `_AnalyzeCustomOpInputOutputMode` (TLS include set gains `Python` and `PythonTLSSnapshot`). A plain forwarding mode reproduces it, and so does eager under `torch._C._ExcludeDispatchKeyGuard(DispatchKeySet(DispatchKey.Conjugate))`, which gives the identical wrong tensors. Scanning every `torch.linalg` function and 51 complex composite calls under the forwarding mode, the affected ones are `linalg.pinv` / `pinverse`, `linalg.polar` (the Hermitian factor `P`, which comes back as `(X + X.mT) / 2` so the imaginary parts of its off-diagonal cancel) and `linalg.matrix_sqrth`; `lstsq`, `solve`, `inv`, `eigh`, `cholesky_*`, `lu_solve(adjoint=True)`, `householder_product`, `ormqr`, `vdot`, `matmul` with `.mH` and the rest agree.

This is also the actual cause of #197084 (wrong gradients of complex `pinv` / `matrix_sqrth` under `torch.compile`): with the forwarding mode active in eager, the gradient of `(pinv(a).abs() ** 2).sum()` differs from the double-precision reference by the same `1.7e+01` and is bit-identical to the compiled gradient, and it stays wrong when only the forward runs under the mode, so the backward formula is fine and it is the saved forward output that is wrong.

**Possible fix.** Inside these kernels the conjugate views produced by `.mH()` are consumed by `at::matmul` on the path taken when the `Python` key is in the TLS include set; either these kernels should call `.resolve_conj()` (or `conj_physical`) before the matmul, or the Python fallback should preserve the Conjugate/Negative fallbacks when it re-dispatches for ops that were not intercepted by a mode. A regression test that runs the complex `linalg` OpInfo samples under a forwarding `TorchDispatchMode` would catch this class.

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu and on Linux (2.14.0+cpu, nightly 2.15.0.dev20260921+cpu). On a Tesla T4 (2.14.0+cu130 and nightly) `linalg.polar` is wrong in the same way (`|P under mode - eager| = 2.07` for complex64), while `linalg.pinv` on CUDA agrees with eager, so the CUDA `pinv` kernel does not take the affected path.
