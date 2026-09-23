<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 28: `torch.func.jvp` 在 torch.compile 内对 quantile / addr 触发 `_make_dual` INTERNAL ASSERT

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911（Windows，**逐用例独立进程**：addr / quantile(任意 q) / nanquantile 三个后端全部断言，`scripts/diag_jvp_make_dual_isolated.py`）；Linux Py3.11（2.14.0 与 dev20260912，`kaggle_out/jvp2linux.txt`）相同。2026-09-15 复核发现同一进程内连续跑多个用例时后面的用例可能通过（状态残留），早先 Windows 矩阵里的 ok 即由此而来，已改正 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20jvp%20dynamo%20_make_dual · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20%22primal.is_inference%22（`results/dedup_0913d.txt`，无同报告） |
| 证据包 | `plan/scripts/diag_jvp_make_dual.py`（9 个算子 × 3 后端），`plan/scripts/diag_jvp_addr.py`，`plan/results/forward_ad/FORWARD_AD.md`（6.4d 全量） |
| 建议标签 | oncall: pt2, module: dynamo, module: forward ad |
| 备注 | 任一入口在新进程里都断言；issue 里注明了同进程内的状态依赖，免得维护者用循环脚本复现出混合结果 |

---

## 标题

[dynamo] `torch.func.jvp` inside a compiled function hits `INTERNAL ASSERT FAILED: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference()` (`_make_dual`) for `torch.quantile` / `nanquantile` / `addr` under every backend

## 🐛 Describe the bug

Forward-mode AD works in eager for these operators, but once the `jvp` call is inside a `torch.compile`d function Dynamo produces a graph whose `_make_dual` call is fed inference tensors and the C++ side asserts.

```python
import torch

torch.manual_seed(0)
x, t = torch.randn(3, 4), torch.randn(3, 4)
q = torch.tensor([0.25, 0.75])
f = lambda a: torch.quantile(a, q, dim=0)

print(torch.func.jvp(f, (x,), (t,))[1].shape)        # eager: torch.Size([2, 4])
for backend in ("eager", "aot_eager", "inductor"):
    torch._dynamo.reset()
    torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend=backend)(x, t)
```

```
RuntimeError: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED
at ".../aten/src/ATen/native/AutogradComposite.cpp":2x, please report a bug to PyTorch.
```

Each (operator, backend) below was run in its own fresh interpreter (`scripts/diag_jvp_make_dual_isolated.py`); torch 2.14.0+cpu and the 2026-09-11 nightly give the same table on Windows, and Linux / Python 3.11 (2.14.0 and the 2026-09-12 nightly) matches it:

| op inside `jvp` | backend=eager | aot_eager | inductor |
|---|---|---|---|
| `addr(a, v1, v2)` (also with `beta=0.5, alpha=2.0`) | **assert** | **assert** | **assert** |
| `quantile(a, 0.5)` | **assert** | **assert** | **assert** |
| `quantile(a, 0.3, dim=1)` | **assert** | **assert** | **assert** |
| `quantile(a, tensor([0.25, 0.75]), dim=0)` | **assert** | **assert** | **assert** |
| `nanquantile(a, 0.5)` | **assert** | **assert** | **assert** |
| `median(dim)`, `kthvalue`, `sort` | ok | ok | ok |

One caveat worth knowing when reproducing: the outcome is state-dependent within a process. When several of these cases are run one after another in the same interpreter, some later calls succeed (for example `quantile(a, 0.5)` under `aot_eager` and `inductor` after an earlier failing call), so a script that loops over backends in one process can show a mix of ok / assert. A fresh process fails for every entry marked above.

`backend="eager"` runs exactly the graph Dynamo captured, so the assertion shows that the captured graph itself feeds an inference tensor into `torch._make_dual`; the functionalized backends (`aot_eager`, `inductor`) inherit the same graph and fail the same way.

Expected: same tangent as eager for every backend (or a graph break instead of an internal assertion).

Found by a sweep over all 507 OpInfo operators with forward-AD support comparing `compile(jvp(f))` with eager: no numerical divergence anywhere; these assertions and one hard crash (`ldexp`, reported separately) were the only failures.

### Error logs

```
RuntimeError: InferenceMode::is_enabled() && primal.is_inference() && tangent.is_inference() INTERNAL ASSERT FAILED at "...\\aten\\src\\ATen\\native\\AutogradComposite.cpp":2x, please report a bug to PyTorch.
```

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14; same on the 2026-09-11 nightly wheel. Full `collect_env` as in the other drafts.)
