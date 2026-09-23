<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 23: `torch.compile(opt.step)`，SGD + `foreach=True` + 复数参数 → Inductor 断言失败

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows + Linux）；nightly 2.15.0.dev20260911（Windows）/ dev20260912（Linux，`kaggle_out/leads2linux.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20foreach%20complex%20compile%20optimizer · https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20%22is%20not%20an%20OpOverload%22（`results/dedup_0912c.txt`，无同报告）。相关：PR #178192 "[Full Inductor] Handle operator.getitem on IR nodes in GraphLowering"（未合并，2026-06-22 stale 关闭）处理的是同一断言的另一个触发路径（MultiOutputLayout），说明该断言是已知薄弱点 |
| 证据包 | `plan/scripts/diag_optim_complex_foreach.py`（8 个优化器 × complex64/float32 × 4 路对照），`plan/scripts/optimizer_step_diff.py` + `plan/results/optim/OPTIM.md`（6.4 全量差分） |
| 建议标签 | oncall: pt2, module: inductor, module: optimizer |
| 备注 | eager 与 aot_eager 都能正确更新复数参数，只有 Inductor 挂；`foreach=False` 正常；Adam/AdamW/RMSprop/Adagrad 的 foreach 复数路径正常（它们对复数先 `view_as_real`，SGD 的 foreach 实现直接对复数张量调 `_foreach_add_`） |

---

## 标题

[inductor] `torch.compile(optimizer.step)` fails for SGD with `foreach=True` on complex parameters: "AssertionError: <built-in function getitem> is not an OpOverload" (eager and aot_eager work)

## 🐛 Describe the bug

```python
import torch

p = torch.nn.Parameter(torch.complex(torch.randn(3, 2), torch.randn(3, 2)))
opt = torch.optim.SGD([p], lr=0.1, foreach=True)
p.grad = torch.ones_like(p)

opt.step()                                  # eager: fine
torch.compile(opt.step, backend="aot_eager")()   # fine
torch.compile(opt.step)()                   # Inductor:
# torch._inductor.exc.InductorError: AssertionError: <built-in function getitem> is not an OpOverload
```

Matrix (torch 2.14.0+cpu, same on the 2026-09-11 nightly; `scripts/diag_optim_complex_foreach.py`):

| optimizer | flags | complex64 param | float32 param |
|---|---|---|---|
| SGD | foreach=True | eager ok, aot_eager ok, **inductor AssertionError** | all ok |
| SGD | foreach=True, momentum=0.9 (also nesterov / weight_decay / maximize / dampening) | **inductor AssertionError** | all ok |
| SGD | foreach=False | all ok | all ok |
| Adam / AdamW / RMSprop / Adagrad | foreach=True | all ok | all ok |

So it is specifically the SGD `foreach` implementation on complex tensors. Those optimizers that work handle complex parameters by `torch.view_as_real` before the `_foreach_*` calls (`torch/optim/adam.py` etc.); `torch/optim/sgd.py::_multi_tensor_sgd` calls `torch._foreach_add_(device_params, device_grads, alpha=-lr)` directly on the complex tensors. Inductor has no lowering for the complex `_foreach_add_`, the node becomes a fallback whose list output is then indexed by `operator.getitem` on something that is no longer a python list, and `GraphLowering.call_function` (`torch/_inductor/graph.py`, `raise AssertionError(f"{target} is not an OpOverload")`) rejects it.

Expected: same parameter update as eager (or a graceful fallback for the complex foreach op).

### Error logs

```
  File ".../torch/_inductor/graph.py", line 2062, in run_node
  File ".../torch/fx/interpreter.py", line 294, in run_node
  File ".../torch/_inductor/graph.py", line 1418, in call_function
    raise AssertionError(f"{target} is not an OpOverload")
torch._inductor.exc.InductorError: AssertionError: <built-in function getitem> is not an OpOverload
```

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14, MSVC 19.44; same on the 2026-09-11 nightly wheel and on Linux/Python 3.11 with torch 2.14.0+cpu and 2.15.0.dev20260912+cpu. Full `collect_env` as in the other drafts.)
