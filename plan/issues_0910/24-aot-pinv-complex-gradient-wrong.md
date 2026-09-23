<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 24: `torch.linalg.pinv` / `linalg.matrix_sqrth` 复数输入的梯度在 torch.compile / AOTAutograd 下算错

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows Py3.14 + Linux Py3.11）；nightly 2.15.0.dev20260911（Windows）/ dev20260912（Linux，`kaggle_out/pinvlinux.txt`：aot_eager 与 inductor 误差 1.4e-1，eager 5.8e-7） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20pinv%20complex%20gradient · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20aot_autograd%20complex%20conj%20gradient（`results/dedup_0913.txt`，无同报告）。相关但不同：open #184101（Inductor 对转置复数张量 `abs()/angle()` 反向的步长断言崩溃，aot_eager 正常——本条 aot_eager 就错，且是静默错值） |
| 证据包 | `plan/reports_decomp/pinv_complex_grad/minimal_verified.py`（含 gradcheck），`plan/scripts/complex_grad_sweep.py` + `plan/results/complex_grad/COMPLEX_GRAD.md`（全部复数自动求导 OpInfo 算子的扫描：只有 pinv/pinverse/matrix_sqrth），`plan/scripts/diag_matrix_sqrth_grad.py`，`plan/scripts/diag_complex_linalg_grad.py`（16 个 linalg 函数 × 实/复 × 三路），`plan/results/decomp_newvar_grad/DECOMP_DIFF.md`（6.3 复数变体 grad 扫描的原始命中） |
| 建议标签 | oncall: pt2, module: aotdispatch, module: complex, module: correctness (silent) |
| 备注 | 定位：`torch.compile(backend="eager")`（只 Dynamo）正确，`torch.func.grad` 正确，`functionalize` 正确，`aot_function`（不经 Dynamo）就错 → 在 AOTAutograd 追踪反向的环节。追踪出的反向图含 `aten._conj.default`（`pinv_backward` 里的 `.mH`），怀疑是 conj 视图在 AOT 追踪/functionalization 里丢了共轭位。float32 完全正确，`pinv(hermitian=True)` 与 inv/solve/svd/qr/eigvalsh/lstsq/det/cholesky/matrix_exp 的复数梯度都正确 |

---

## 标题

[aot_autograd] wrong gradients for `torch.linalg.pinv` and `torch.linalg.matrix_sqrth` with complex input under torch.compile (aot_eager and inductor); eager, functorch and Dynamo-only are correct

## 🐛 Describe the bug

The gradient of a loss that goes through `torch.linalg.pinv` of a **complex** matrix is wrong once the function is compiled. `gradcheck` passes in eager and fails on the compiled function.

```python
import torch

torch.manual_seed(0)


def loss(a):
    return (torch.linalg.pinv(a).abs() ** 2).sum()


def grad(fn, a):
    a = a.detach().clone().requires_grad_()
    fn(a).backward()
    return a.grad


a = torch.randn(4, 3, dtype=torch.complex64)
truth = grad(loss, a.to(torch.complex128))
for name, fn in [("eager", loss), ("compile(backend=eager)", torch.compile(loss, backend="eager")),
                 ("compile(aot_eager)", torch.compile(loss, backend="aot_eager")), ("compile(inductor)", torch.compile(loss))]:
    torch._dynamo.reset()
    print(f"{name:<24} max |grad - truth| = {(grad(fn, a).to(torch.complex128) - truth).abs().max().item():.1e}")

a128 = torch.randn(4, 3, dtype=torch.complex128, requires_grad=True)
print("gradcheck eager   :", torch.autograd.gradcheck(loss, (a128,), eps=1e-6, atol=1e-4, raise_exception=False))
print("gradcheck compiled:", torch.autograd.gradcheck(torch.compile(loss, backend="aot_eager"), (a128,), eps=1e-6, atol=1e-4, raise_exception=False))
```

Output (torch 2.14.0+cpu; same on the 2026-09-11 nightly):

```
eager                    max |grad - truth| = 1.3e-05
compile(backend=eager)   max |grad - truth| = 1.3e-05
compile(aot_eager)       max |grad - truth| = 1.7e+01
compile(inductor)        max |grad - truth| = 1.7e+01
gradcheck eager   : True
gradcheck compiled: False
```

The compiled gradient is not slightly off, it is a different tensor (first row eager `[-0.5897+0.0005j, -0.5655-0.2723j, -0.5190-0.7107j]`, compiled `[-0.0124+0.0438j, -1.5919-0.0432j, -1.3720-2.4505j]`). With a `float32` input all four agree (error 2.5e-5 for every path).

Localisation:

- `torch.compile(backend="eager")` (Dynamo only, no AOTAutograd) is correct; `torch.func.grad(loss)` and `torch.func.functionalize(loss)` are correct; `torch._functorch.aot_autograd.aot_function(loss, nop, nop)` without Dynamo is already wrong → the problem is in how AOTAutograd traces the backward of `linalg_pinv`.
- The traced forward keeps `aten.linalg_pinv.atol_rtol_tensor` as one node; the traced backward consists of `_conj`, `mm`, `transpose`, `mul`, `sub`, `neg`, `sgn`, `pow`, `expand`, `clone`, `detach` — i.e. the C++ `pinv_backward` formula (which uses `.mH`) traced into aten ops. The `aten._conj.default` nodes are the suspicious part: the conjugation appears to be lost or applied to the wrong operand somewhere between tracing and execution.
- Other complex linear-algebra gradients traced the same way are right: `pinv(hermitian=True)`, `inv`, `solve`, `svd`/`svdvals`, `qr`, `eigvalsh`, `lstsq`, `det`, `cholesky`, `matrix_exp`, `matrix_norm` all match eager under `aot_eager` and `inductor` (`scripts/diag_complex_linalg_grad.py`).

A second operator with the same signature: `torch.linalg.matrix_sqrth`. For `loss(a) = (matrix_sqrth(a @ a.mH + I).abs() ** 2).sum()` with a `complex64` (4, 4) input, eager / Dynamo-only error vs complex128 is 2.2e-6, `aot_eager` and `inductor` give 9.6e-1; float32 agrees everywhere. Its traced backward again contains `aten._conj.default` (plus `_linalg_eigh`, `mm`, `div`, ...). Same numbers on Linux / Python 3.11 (2.14.0 and the 2026-09-12 nightly, `kaggle_out/sqrthlinux.txt`). A sweep over every OpInfo operator that supports complex64 autograd (`scripts/complex_grad_sweep.py`, 3 samples each, eager vs `aot_eager`) flags exactly `linalg.pinv`, `pinverse` and `linalg.matrix_sqrth` — nothing else — so this is not a general complex-autograd problem but something specific to how these two backward formulas are traced.

Expected: the compiled gradient equals the eager gradient (and passes gradcheck), as it does for real inputs.

### Error logs

No error; silent wrong gradient (gradcheck output above).

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14; same on the 2026-09-11 nightly wheel, and on Linux / Python 3.11 with torch 2.14.0+cpu and 2.15.0.dev20260912+cpu. Full `collect_env` as in the other drafts. CPU only; the bug is in tracing so the device should not matter.)
