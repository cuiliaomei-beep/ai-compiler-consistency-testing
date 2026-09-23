<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 28（中：`torch.any` 在 uint8 上返回 bool 而不是 uint8；`torch.all` 正确——成对实现不对称）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows）；Linux CPU 2.14.0（Kaggle `tcc-edgeint`，发现来源）；Tesla T4 CUDA 2.14.0+cu130 与 nightly 2.15.0.dev20260921+cu130 同样返回 bool（Kaggle `tcc-scangpu`，`plan/kaggle_out/scangpu/log.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22：`any uint8 returns bool compile`、`torch.any uint8 dtype inductor`、`any all uint8 output dtype torch.compile`、`reduce_any uint8`、`any() uint8 legacy inductor`：无同报告（#198056 是 torch._numpy 的 `np.any` 返回 uint8，方向相反、层不同） |
| 证据包 | `plan/reports_pairs/cuda_scan_and_any_u8.py`（后半段）；发现来源 `plan/scripts/opinfo_edge_sweep.py`（11.4：OpInfo 全算子 × 边界值 × int8/uint8/int16/bool，Linux，1455 对里唯一的 dtype 差异） |
| 根因 | `torch/_refs/__init__.py::any` 与 `all` 都在 uint8 输入时把结果转回 uint8（注释 "Preserves uint8 -- probably a legacy mask thing"）；但 Inductor 在 `torch/_inductor/lowering.py` 里给 `aten.any` 单独注册了 `reduce_any`（`to_dtype(x, bool)` 后做 `any` 归约，直接返回 bool），绕过了分解；`aten.all` 没有专门 lowering，走分解，所以保留 uint8。`aot_eager` 正确 |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent) |

---

## Title

[inductor] `torch.any` on a uint8 tensor returns bool under `torch.compile` (eager and `torch.all` keep uint8), so downstream uint8 arithmetic silently changes

## Body

### 🐛 Describe the bug

**Summary.** `torch.any(x)` and `x.any(dim)` on a uint8 tensor return uint8 in eager and under `backend="aot_eager"`, while the Inductor-compiled function returns bool (torch 2.14.0 and nightly, CPU and CUDA); `torch.all` on the same tensor keeps uint8 under every backend. A user sees the compiled result change dtype without any warning, and arithmetic on it changes value because the bool is promoted to int64 instead of wrapping in uint8 (`torch.any(x) * 200 + 100` is `44` in eager and `300` compiled). Because Inductor registers its own `reduce_any` lowering that casts to bool and returns the bool reduction rather than going through the `_refs.any` decomposition that restores uint8 (which `aten.all` still uses), only `any` loses the legacy uint8 result type.

```python
import torch

x = torch.tensor([[0, 3], [0, 0]], dtype=torch.uint8)
for name, f in {"torch.any(x)": lambda x: torch.any(x), "torch.all(x)": lambda x: torch.all(x), "x.any(0)": lambda x: x.any(0),
                "any(x) * 200 + 100": lambda x: torch.any(x) * 200 + 100}.items():
    e = f(x)
    row = [f"eager {e.tolist()} {e.dtype}"]
    for backend in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        c = torch.compile(f, backend=backend)(x)
        row.append(f"{backend} {c.tolist()} {c.dtype}")
    print(f"{name:20s} " + " | ".join(row))
```

```
torch.any(x)         eager 1 torch.uint8 | aot_eager 1 torch.uint8 | inductor True torch.bool
torch.all(x)         eager 0 torch.uint8 | aot_eager 0 torch.uint8 | inductor 0 torch.uint8
x.any(0)             eager [0, 1] torch.uint8 | aot_eager [0, 1] torch.uint8 | inductor [False, True] torch.bool
any(x) * 200 + 100   eager 44 torch.uint8 | aot_eager 44 torch.uint8 | inductor 300 torch.int64
```

**Root cause and possible fix.** `torch/_refs/__init__.py` has both `any` and `all` convert the result back to uint8 when the input is uint8 ("Preserves uint8 -- probably a legacy mask thing"), and `aten.all` reaches Inductor through that decomposition. `aten.any` does not: `torch/_inductor/lowering.py` registers `reduce_any`, which does `x = to_dtype(x, torch.bool)` and returns `make_reduction("any")(x, ...)`, so the result is bool. Either drop the dedicated lowering and let `aten.any` decompose like `aten.all`, or make `reduce_any` cast the result back to uint8 when the input dtype is uint8, matching the eager kernel.

### Error logs

No error is raised; the compiled function returns `torch.bool` where eager returns `torch.uint8`, and the values of the dependent arithmetic differ as shown above (`44` vs `300`).

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
MSVC: Microsoft (R) C/C++ Optimizing Compiler Version 19.44.35228 for x64
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
CPU: 11th Gen Intel(R) Core(TM) i9-11900T @ 1.50GHz
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu, on Linux with 2.14.0+cpu, and on a Tesla T4 (`x` on `cuda`) with 2.14.0+cu130 and nightly 2.15.0.dev20260921+cu130.
