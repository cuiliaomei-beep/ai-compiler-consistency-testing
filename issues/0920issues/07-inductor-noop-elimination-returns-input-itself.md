<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 07（中–高：输出与输入静默别名，默认超参数即触发）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，CPU Inductor）；`aot_eager` 与 eager 一致 → Inductor。Linux 复核（Kaggle `tcc-rewritelinux` / `tcc-rewritegpu`，`plan/kaggle_out/rewritelinux.log`、`rewritegpu.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260920 输出逐字相同；**CUDA（T4，2.14.0+cu130）同样 `out is x: True`、输入被改成 6.0** → 与设备无关 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21，9 组关键词（`remove_no_ops alias input`、`inductor x + 0 returns input`、`compile add zero output aliases input`、`joint_graph remove_no_ops`、`inductor noop returns same tensor as input` 等）：无同报告。相关：#174187 / PR #174938（同一个 pass，修的是"被替换的值之后被原地修改"，已关闭）；#191844（AOTAutograd 里 no-op view 的输出身份，已关闭）；#108918 一类讨论催生了 `post_grad.remove_noop_ops` 里的防护——本条是 `joint_graph.remove_no_ops` 缺同样的防护 |
| 证据包 | `plan/reports_rewrites/noop_returns_input_alias.py`（16 种写法对照）、`noop_alias_realistic.py`（默认超参数触发 + requires_grad + 下游影响）、`output_alias_census.py`（46 个"数学上恒等"的程序普查：只有 ±0 / ×1 / ÷1 这一族（含图内常量张量形式）返回输入本身，cat/stack/repeat/roll/where/pow/索引/位运算等 36 种都是新张量）；发现来源 `plan/scripts/rewrite_precondition_diff.py`（10.1 改写前提差分，用例 `add_zero_is_copy` / `mul_one_is_copy`） |
| 触发条件（已隔离） | 图输出就是 `input ± 0`、`input * 1`、`input / 1`（标量是 Python 常量，被 Dynamo 特化进图里）。`x ** 1`、`x // 1`、`x.clone()`、`x + torch.zeros(())` 不触发 |
| 建议标签 | oncall: pt2, module: inductor, module: correctness (silent) |

---

## Title

[inductor] `x + 0` / `x * 1` / `x / 1.0` as a graph output returns the input tensor itself (`out is x`), so an in-place update of the result silently corrupts the input

## Body

### 🐛 Describe the bug

**Summary.** For a function whose output is `x / temperature`, `buf * momentum` or `x + bias` called with the neutral value (`1.0`, `1.0`, `0`), eager and `aot_eager` return a fresh tensor, while Inductor returns the input object itself (`out is x`; with `requires_grad`, another object on the same storage), on torch 2.14.0 and nightly, CPU and CUDA. A caller that then updates the result in place (`new_buf.add_(g)`, `logits.clamp_(...)`) overwrites its own input with no error, only for the value that makes the operation a no-op: the same code is correct for `temperature=0.9` and wrong for `temperature=1.0`. Because `joint_graph.remove_no_ops` replaces the node by its operand without the check that `post_grad.remove_noop_ops` has ("Don't introduce new aliasing between inputs and outputs"), every graph that returns such a no-op of an input is affected.

```python
import torch

def scale(logits, temperature):
    return logits / temperature

def momentum_step(buf, momentum):
    return buf * momentum

def add_bias(x, bias):
    return x + bias

for name, f, arg in (("logits / 1.0", scale, 1.0), ("logits / 0.9", scale, 0.9),
                     ("buf * 1.0", momentum_step, 1.0), ("x + 0", add_bias, 0)):
    for backend in ("eager (no compile)", "aot_eager", "inductor"):
        torch._dynamo.reset()
        g = f if backend.startswith("eager") else torch.compile(f, backend=backend)
        x = torch.ones(3)
        out = g(x, arg)
        same = out is x
        out.add_(5)                     # the caller updates the *result* in place
        print(f"{name:13s} {backend:19s} out is x: {str(same):5s}  x afterwards: {x.tolist()}")
```

```
logits / 1.0  eager (no compile)  out is x: False  x afterwards: [1.0, 1.0, 1.0]
logits / 1.0  aot_eager           out is x: False  x afterwards: [1.0, 1.0, 1.0]
logits / 1.0  inductor            out is x: True   x afterwards: [6.0, 6.0, 6.0]
logits / 0.9  eager (no compile)  out is x: False  x afterwards: [1.0, 1.0, 1.0]
logits / 0.9  aot_eager           out is x: False  x afterwards: [1.0, 1.0, 1.0]
logits / 0.9  inductor            out is x: False  x afterwards: [1.0, 1.0, 1.0]
buf * 1.0     eager (no compile)  out is x: False  x afterwards: [1.0, 1.0, 1.0]
buf * 1.0     aot_eager           out is x: False  x afterwards: [1.0, 1.0, 1.0]
buf * 1.0     inductor            out is x: True   x afterwards: [6.0, 6.0, 6.0]
x + 0         eager (no compile)  out is x: False  x afterwards: [1.0, 1.0, 1.0]
x + 0         aot_eager           out is x: False  x afterwards: [1.0, 1.0, 1.0]
x + 0         inductor            out is x: True   x afterwards: [6.0, 6.0, 6.0]
```

Also affected: `0 + x`, `x - 0`, `x + 0.0`, `torch.add(x, 0)`, `(x + 0) + 0`, the same operations with a constant tensor built inside the function (`x * torch.ones(3)`, `x + torch.zeros(3)`, `x - torch.zeros_like(x)`, `x / torch.ones_like(x)`, `x * torch.full_like(x, 1.0)`), integer dtypes, an `nn.Module` whose `forward` is `logits / self.t` with `self.t = 1.0`, and inputs with `requires_grad=True` (there `out is x` is `False` but `out.data_ptr() == x.data_ptr()`, so `out.detach().mul_(2)` doubles `x`). Not affected: `x ** 1`, `x // 1`, `x.clone()`, `x + torch.zeros(())`.

A second, smaller consequence of the same elimination: `x + 0` no longer normalises negative zero (`torch.tensor(-0.0) + 0` is `0.` in eager and `-0.` compiled).

**Root cause and possible fix.** `torch/_inductor/fx_passes/joint_graph.py::remove_no_ops` → `replace_no_op` does `node.replace_all_uses_with(replacement)` whenever shape/dtype/device match and the replacement is not mutated (the guard added for #174187). When `replacement` is a placeholder and `node` feeds the graph output, the compiled graph returns its input, but AOTAutograd has already recorded that output as a non-alias, so the runtime wrapper hands the input tensor back to the caller as if it were fresh. `post_grad.py::remove_noop_ops` avoids the same situation with

```python
# Don't introduce new aliasing between inputs and outputs.
if (not node_is_view and node_storage in output_storages
        and (src_storage in input_storages or src_storage in output_storages)):
    continue
```

Applying the same condition in `replace_no_op` (skip, or replace the node by `aten.clone(replacement)` so the arithmetic still disappears) restores eager semantics; the check also has to cover two outputs that would become the same tensor (`return x * 1, x + 0`).

### Error logs

No error is raised.

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

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux), on Linux CPU with 2.14.0, and on CUDA (Tesla T4, 2.14.0+cu130), so the behaviour comes from the shared FX pass and not from a backend.
