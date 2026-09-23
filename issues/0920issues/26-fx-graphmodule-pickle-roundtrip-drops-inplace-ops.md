<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 26（中：GraphModule 经 pickle / torch.save 往返后语义静默改变——原地运算变成非原地，输入不再被修改）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；纯 `torch.fx`，不需要 C++ 编译器；Linux 复核（Kaggle `tcc-fxpicklelinux`，2026-09-22）：2.14.0+cpu 与 nightly 2.15.0.dev20260921+cpu 上两段代码的输出与下文逐字相同（`plan/kaggle_out/fxpicklelinux/log.txt`） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/bug-report.yml`（纯 FX 缺陷，与 #197894 同一模板） |
| 提交前查重 | 2026-09-22 与 2026-09-22 08:50 两次：`GraphModule pickle in-place iadd lost`、`fx GraphModule torch.save changes graph retrace`、`GraphModule deserialize symbolic trace inplace operator`、`reduce_graph_module retrace semantics`、`fx pickle GraphModule operator.iadd`：无同报告。邻近但不同：#185170、#186418（export 产物的 pickle 失败，是报错不是语义改变） |
| 证据包 | `plan/reports_fx/pickle_roundtrip_changes_semantics.py`（4 个图 × original / deepcopy / pickle / torch.save）、`dynamo_graph_pickle.py`（Dynamo 捕获的 `buf += g` 图，pickle 后缓冲区不再被更新）；发现来源 `plan/scripts/fx_codegen_vs_interpreter.py`（11.1：10,518 张手工构造的 FX 图，比较 Interpreter、`forward`、deepcopy、pickle 四种执行；pickle 这一档 103 张图不同） |
| 触发条件（已隔离） | 图里有 `operator.iadd / isub / imul / itruediv / ifloordiv / imod / ipow / …` 节点（Dynamo 产出的 FX 图会有；`symbolic_trace` 自己产不出来），然后对 GraphModule 做 `pickle` / `torch.save`+`torch.load` / 跨进程传递。`copy.deepcopy` 不受影响 |
| 根因 | `torch/fx/graph_module.py::_deserialize_graph_module` 不保存图，而是把生成的 `forward` 源码用 `Tracer` **重新符号追踪**一遍；`Proxy` 没有 `__iadd__` 等原地魔术方法，Python 于是回退到 `x = x + 1`，追踪到的是 `operator.add` |
| 建议标签 | module: fx, module: correctness (silent) |

---

## Title

[fx] A pickle / `torch.save` round trip silently changes what a `GraphModule` computes: in-place operator nodes (`operator.iadd`, `imul`, …) come back out-of-place, so the input is no longer mutated and dtype errors disappear

## Body

### 🐛 Describe the bug

**Summary.** A `GraphModule` whose graph contains `operator.iadd(x, 1)` adds to its input in place, and so does its `copy.deepcopy`, while the module returned by `pickle.loads(pickle.dumps(gm))` or `torch.save` / `torch.load` computes `x + 1` and leaves the input untouched; for an int64 input and `operator.imul(x, 2.5)` the original raises and the unpickled module returns a float tensor (torch 2.14.0 and nightly). A graph captured by Dynamo, which emits these nodes for `buf += g`, stops updating its buffers after being saved or sent to another process, with no error and plausible generated code (`add = x + 1`). Because unpickling re-traces the generated `forward` source symbolically rather than restoring the stored graph, and `Proxy` defines no in-place magic methods, every in-place operator node is rewritten as its out-of-place form.

```python
import copy, io, operator, pickle
import torch, torch.fx

def build(target, arg):
    g = torch.fx.Graph()
    x = g.placeholder("x")
    g.output(g.call_function(target, (x, arg)))
    return torch.fx.GraphModule(torch.nn.Module(), g)

def run(m, t):
    t = t.clone()
    try:
        return f"returns {m(t).tolist()}, input afterwards {t.tolist()}"
    except RuntimeError:
        return "raises RuntimeError"

for name, gm, t in (("operator.iadd(x, 1)", build(operator.iadd, 1), torch.zeros(3)),
                    ("operator.imul(x, 2.5), int64 x", build(operator.imul, 2.5), torch.ones(3, dtype=torch.int64))):
    buf = io.BytesIO(); torch.save(gm, buf); buf.seek(0)
    print(name)
    for how, m in (("original", gm), ("copy.deepcopy", copy.deepcopy(gm)), ("pickle round trip", pickle.loads(pickle.dumps(gm))),
                   ("torch.save / torch.load", torch.load(buf, weights_only=False))):
        body = " ".join(l.strip() for l in m.code.strip().splitlines()[1:-1])
        print(f"    {how:24s} {run(m, t):60s} | {body}")
```

```
operator.iadd(x, 1)
    original                 returns [1.0, 1.0, 1.0], input afterwards [1.0, 1.0, 1.0]    | x += 1;  iadd = x;  x = None
    copy.deepcopy            returns [1.0, 1.0, 1.0], input afterwards [1.0, 1.0, 1.0]    | x += 1;  iadd = x;  x = None
    pickle round trip        returns [1.0, 1.0, 1.0], input afterwards [0.0, 0.0, 0.0]    | add = x + 1;  x = None
    torch.save / torch.load  returns [1.0, 1.0, 1.0], input afterwards [0.0, 0.0, 0.0]    | add = x + 1;  x = None
operator.imul(x, 2.5), int64 x
    original                 raises RuntimeError                                          | x *= 2.5;  imul = x;  x = None
    copy.deepcopy            raises RuntimeError                                          | x *= 2.5;  imul = x;  x = None
    pickle round trip        returns [2.5, 2.5, 2.5], input afterwards [1, 1, 1]          | mul = x * 2.5;  x = None
    torch.save / torch.load  returns [2.5, 2.5, 2.5], input afterwards [1, 1, 1]          | mul = x * 2.5;  x = None
```

The same happens to a graph that Dynamo captured for ordinary user code:

```python
import pickle, torch

captured = []
def backend(gm, example_inputs):
    captured.append(gm)
    return gm.forward

def step(buf, g):
    buf += g                      # in-place update of an input buffer
    buf *= 0.5
    return buf.sum()

torch.compile(step, backend=backend)(torch.zeros(3), torch.ones(3))
for name, m in (("captured graph", captured[0]), ("after pickle round trip", pickle.loads(pickle.dumps(captured[0])))):
    buf = torch.zeros(3)
    m(buf, torch.ones(3))
    print(f"{name:24s} buffer afterwards {buf.tolist()}")
```

```
captured graph           buffer afterwards [0.5, 0.5, 0.5]
after pickle round trip  buffer afterwards [0.0, 0.0, 0.0]
```

The re-trace changes other nodes as well: `call_method("__rsub__", (x, 1))` comes back as `1 - x` (harmless), and `call_method("__rpow__", (x, -2))` comes back as `operator.pow(-2, x)`, which the code generator prints as `-2 ** x` (#197894), so `[4., -8.]` becomes `[-4., -8.]` after the round trip.

**Root cause and possible fix.** `torch/fx/graph_module.py::_deserialize_graph_module` rebuilds the graph with `KeepModules().trace(com)` from the generated source instead of from the pickled `Graph`. Anything the symbolic tracer cannot express the way the original graph did is rewritten; in-place operators are the case with a semantic difference, because `Proxy` has no `__iadd__`-family methods and the augmented assignment degrades to the binary operator. Options: give `Proxy` in-place magic methods that record `operator.i*` nodes (which also lets `symbolic_trace` see `x += 1`), or serialize the `Graph` itself (nodes and targets) so that a round trip is exact, or at least warn when the re-traced graph differs from the original in its node targets.

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

Same output on nightly 2.15.0.dev20260911+cpu, and on Linux (Python 3.12) with 2.14.0+cpu and nightly 2.15.0.dev20260921+cpu.
