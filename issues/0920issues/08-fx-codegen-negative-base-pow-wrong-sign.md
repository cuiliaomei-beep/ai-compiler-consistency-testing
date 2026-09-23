<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 08（中–高：torch.fx 代码生成的运算符优先级错误，静默错值）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；纯 `torch.fx` 即可复现，不需要 C++ 编译器；Linux 复核（Kaggle `tcc-symintlinux`，`plan/kaggle_out/symintlinux.log`）：Linux CPU 2.14.0 与 nightly 2.15.0.dev20260921（Python 3.12）输出逐字相同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=bug-report.yml （纯 FX 缺陷用通用模板；若想挂到 PT2，用 pt2-bug-report.yml 亦可） |
| 提交前查重 | 2026-09-21：`fx codegen pow negative precedence`、`fx graph python code operator.pow negative literal`、`torch.fx magic method format negative number parentheses`、`symbolic_trace negative base power wrong`、`dynamo negative base pow symint wrong sign`、`SymInt pow negative base`：无同报告 |
| 证据包 | `plan/reports_symint/fx_codegen_negative_pow.py`（纯 FX 最小复现）、`negative_base_pow.py`（Dynamo 下 7 种写法 × eager/inductor 后端）、`scalar_semantics_leads.py`；发现来源 `plan/scripts/symint_arith_diff.py`（10.5 SymInt/SymFloat 标量算术差分，用例 `i:pow_sym_neg_base`） |
| 触发条件（已隔离） | FX 图里有 `operator.pow(负数字面量, 节点)`。来源：`symbolic_trace` 里 `(-2.0) ** x.shape[0]`；Dynamo `dynamic=True` 下 `(-1) ** x.shape[0]`（SymInt 指数）。`backend="eager"` / `"aot_eager"` 直接执行 FX 生成的 `forward` → 错；Inductor 自己算符号表达式 → 返回 Python 数时对，但流进张量时编译失败（RecursionError） |
| 建议标签 | module: fx, oncall: pt2, module: dynamic shapes, module: correctness (silent) |

---

## Title

[fx] Generated code for `operator.pow(-2, x)` is `-2 ** x`, which Python evaluates as `-(2 ** x)`: `GraphModule.forward` returns the wrong sign (`Interpreter` is correct); reachable from `torch.compile(dynamic=True)` via `(-1) ** x.shape[0]`

## Body

### 🐛 Describe the bug

**Summary.** For an FX node `operator.pow(-2, x)`, `torch.fx.Interpreter` computes `(-2) ** x`, while the Python source that `GraphModule` generates is `pow_1 = -2 ** x`, which Python parses as `-(2 ** x)`, so `gm(2)` returns `-4` instead of `4` (torch 2.14.0 and nightly). Any program that raises a negative constant to a traced power silently gets the wrong sign for even exponents: under `torch.compile(dynamic=True)` with `backend="eager"` or `"aot_eager"`, the alternating-sign idiom `x * (-1) ** x.shape[0]` returns `-x` for every length, and `torch.fx.symbolic_trace` is wrong too. Because the code generator formats the template `"{} ** {}"` with the plain `repr` of each argument rather than parenthesising it, and `**` binds tighter than unary minus, every negative literal used as the base of `pow` is affected.

```python
import operator
import torch, torch.fx

g = torch.fx.Graph()
x = g.placeholder("x")
g.output(g.call_function(operator.pow, (-2, x)))
gm = torch.fx.GraphModule(torch.nn.Module(), g)
print(gm.code.strip())
print("Interpreter:", torch.fx.Interpreter(gm).run(2), " GraphModule.forward:", gm(2), " Python (-2) ** 2:", (-2) ** 2)

def alternating_sign(x):
    return x * (-1) ** x.shape[0]

for backend in ("eager", "aot_eager"):
    torch._dynamo.reset()
    f = torch.compile(alternating_sign, backend=backend, dynamic=True)
    print(backend, [(n, alternating_sign(torch.ones(n))[0].item(), f(torch.ones(n))[0].item()) for n in (2, 3, 4)], "  # (n, eager, compiled)")
```

```
def forward(self, x):
    pow_1 = -2 ** x;  x = None
    return pow_1
Interpreter: 4  GraphModule.forward: -4  Python (-2) ** 2: 4
eager [(2, 1.0, -1.0), (3, -1.0, -1.0), (4, 1.0, -1.0)]   # (n, eager, compiled)
aot_eager [(2, 1.0, -1.0), (3, -1.0, -1.0), (4, 1.0, -1.0)]   # (n, eager, compiled)
```

The Dynamo graph for the second program is `pow_1 = -1 ** s77; mul = l_x_ * pow_1`. With `backend="inductor"` the same program does not return a wrong value but fails to compile (`InductorError: RecursionError` while generating code for `ops.index_expr(PowByNatural(-1, s77), torch.float32)`), which is a separate problem.

**Root cause and fix.** `torch/fx/graph.py`, in the "pretty print operators" branch of the code generator:

```python
f"{magic_methods[node.target.__name__].format(*(_get_repr(a) for a in node.args))}"
```

with `magic_methods["pow"] = "{} ** {}"`. Wrapping a literal first operand of `pow` in parentheses when it is a negative number (or always emitting `({}) ** {}` for non-`Node` arguments) fixes it; `neg`, `sub`, `mod`, `floordiv`, shifts and bitwise templates do not have the problem because unary minus binds tighter than those operators.

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

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260921 on Linux) and on Linux with 2.14.0 (Python 3.12).
