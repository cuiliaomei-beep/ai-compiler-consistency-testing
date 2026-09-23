<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 23（中–低：torch.fx 生成的源码里，名为 `nan` / `inf` 的形参遮蔽同名浮点常量，静默错值）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；纯 `torch.fx`，不需要 C++ 编译器；Linux 复核（Kaggle `tcc-fxlinux`，`plan/kaggle_out/fxlinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921 输出逐字相同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/bug-report.yml`（纯 FX 缺陷；与已提交的 #197894 同一模板） |
| 提交前查重 | 2026-09-22：`fx codegen placeholder named inf nan shadows`、`symbolic_trace argument named nan`、`fx graph python code global inf shadowed parameter`、`torch.fx forward parameter name collides global`、`fx symbolic_trace parameter named nan inf`：无同报告。相关：自己的 #197894（`-2 ** x`，同属“生成源码与 Interpreter 语义不一致”，根因不同） |
| 证据包 | `plan/reports_fx/codegen_param_shadows_inf_nan.py`（symbolic_trace 复现）、`codegen_name_shadowing.py`（16 个占位符名 × 手工构图；中间节点名不受影响） |
| 触发条件（已隔离） | 占位符（= `forward` 的形参）名为 `nan` 或 `inf`，且图里某个节点的实参是 Python 浮点常量 `float("nan")` / `float("inf")`。中间节点叫这些名字没事（会被改名）；形参叫 `torch` 是响亮报错，不是静默 |
| 为什么 torch.compile 不受影响 | Dynamo 把占位符改名为 `L_nan_` 之类，AOT 用 `arg0_1`；受影响的是 `symbolic_trace` 与手工构图的用户 |
| 建议标签 | module: fx, module: correctness (silent) |

---

## Title

[fx] A `forward` parameter named `nan` or `inf` shadows the float constant that the generated code prints as the bare name `nan` / `inf`: `GraphModule.forward` silently uses the tensor instead of the constant (`Interpreter` is correct)

## Body

### 🐛 Describe the bug

**Summary.** For a function with a parameter called `nan` that also uses the constant `float("nan")`, such as `torch.where(nan, float("nan"), x)`, eager and `torch.fx.Interpreter` fill the masked positions with NaN, while the `GraphModule` produced by `torch.fx.symbolic_trace` fills them with the mask itself, because the generated line is `torch.where(nan_1, nan, x)` (torch 2.14.0 and nightly); a parameter called `inf` next to `float("inf")` behaves the same way. The traced module returns finite numbers where NaN or an unbounded limit was requested, with no error and correct-looking source. Because FX prints the two float constants as the global names `nan` and `inf` and renames only the node (`nan_1`), not the parameter, which keeps the user's name in the signature, every graph with such a placeholder and such a constant is affected.

```python
import torch, torch.fx

def mask_invalid(x, nan):                 # `nan`: a boolean mask of invalid entries
    return torch.where(nan, float("nan"), x)

def clip_scores(scores, inf):             # `inf`: a per-element offset; the clamp bound is the constant float("inf")
    return torch.clamp(scores, max=float("inf")) + inf

x = torch.tensor([1.0, 50.0, 3.0])
for f, args in ((mask_invalid, (x, torch.tensor([False, True, False]))), (clip_scores, (x, torch.tensor([10.0, 20.0, 30.0])))):
    gm = torch.fx.symbolic_trace(f)
    print(f.__name__)
    print("    eager              ", f(*args).tolist())
    print("    fx.Interpreter     ", torch.fx.Interpreter(gm).run(*args).tolist())
    print("    GraphModule.forward", gm(*args).tolist())
    print("    " + gm.code.strip().replace("\n", "\n    "))
```

```
mask_invalid
    eager               [1.0, nan, 3.0]
    fx.Interpreter      [1.0, nan, 3.0]
    GraphModule.forward [1.0, 1.0, 3.0]
    def forward(self, x, nan):
        nan_1 = nan
        where = torch.where(nan_1, nan, x);  nan_1 = x = None
        return where
clip_scores
    eager               [11.0, 70.0, 33.0]
    fx.Interpreter      [11.0, 70.0, 33.0]
    GraphModule.forward [11.0, 40.0, 33.0]
    def forward(self, scores, inf):
        inf_1 = inf
        clamp = torch.clamp(scores, max = inf);  scores = None
        add = clamp + inf_1;  clamp = inf_1 = None
        return add
```

In `mask_invalid` the second argument of `torch.where` should be the float NaN and is the boolean mask (`True` becomes `1.0`); in `clip_scores` the clamp bound should be infinity and is the offset tensor, so `50` is clipped to `20`.

**Root cause and possible fix.** `torch/fx/graph.py` registers `inf`, `nan`, `NoneType`, `torch`, `device`, `fx_pytree` and `pytree` with `_register_custom_builtin`, so the generated source refers to them as globals, and `_Namespace.create_name` avoids them for *node* names (hence `nan_1`). The signature, however, is built from the placeholder's `target` (`free_vars.append(f"{node.target}…")`), which must stay the user's parameter name, and that parameter shadows the global inside the function body. A parameter called `torch` fails loudly for the same reason (`torch.clamp` becomes a method lookup on the tensor). Options: emit such constants in a form that cannot be shadowed when a placeholder has one of these names (`float("nan")`, `float("inf")`, or a mangled global such as `_fx_nan`), or reject / warn about placeholders named like a custom builtin.

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

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux) and on Linux with 2.14.0.
