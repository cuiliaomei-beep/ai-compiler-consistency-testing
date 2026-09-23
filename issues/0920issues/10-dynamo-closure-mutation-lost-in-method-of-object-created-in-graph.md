<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 10（中–高：Dynamo 静默丢副作用，fullgraph=True 也不报错）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；`backend="eager"` 即可复现 → Dynamo 层，与 AOTAutograd / Inductor 无关；Linux 复核（Kaggle `tcc-sidelinux` / `tcc-sidegpu`，`plan/kaggle_out/sidelinux.log`、`sidegpu.log`）：Linux 上 2.14.0 与 nightly 2.15.0.dev20260920（Python 3.12）输出逐字相同 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-21，7 组关键词（`dynamo side effect lost closure`、`dynamo silently drops side effect`、`closure cell mutation dropped` 等）：无同报告。相关但不同：#196864 / #171590（对无来源对象 setattr 时**崩溃**，已关闭）；#195901 是 CPython 测试集缺口的总表 |
| 证据包 | `plan/reports_sideeffects/closure_mutation_min2.py`（最小复现）、`closure_mutation_minimal.py`（4 种调用形式对照）、`nested_ctx_manager.py`（最初是在"函数内定义的上下文管理器"上发现的）；发现来源 `plan/scripts/side_effect_diff.py`（75 个副作用/状态小程序，用例 `context_manager_exit_runs`） |
| 触发条件（已隔离） | 三者同时成立才触发：类定义在外层函数里（方法通过闭包访问外层变量）＋ 对象在**被编译的函数内部**创建 ＋ 方法里修改闭包捕获的 list / dict。对象在函数外创建、或改成普通嵌套函数、或类与状态都在模块级 → 正常 |
| 建议标签 | oncall: pt2, module: dynamo, module: correctness (silent) |

---

## Title

[dynamo] Mutations of a closure-captured list/dict are silently dropped when they happen in a method of a locally defined class instantiated inside the compiled function (`fullgraph=True`, no graph break)

## Body

### 🐛 Describe the bug

**Summary.** When a compiled function instantiates a locally defined class and calls a method that mutates a list or dict captured from the enclosing scope, eager mutates it on every call and `torch.compile` never does: `list.append`, `dict[k] = v` and `dict[k] += 1` leave the container unchanged, while the tensor result is correct (torch 2.14.0 and nightly; `backend="eager"` with `fullgraph=True` is enough). A helper object that counts calls or records shapes leaves an empty log after compiling, with no graph break and no error, and a context manager written this way loses its state. Because the mutation is replayed correctly when the object is created outside the compiled function or a nested function is used rather than a method, the loss is specific to method closures of objects created while tracing.

```python
import torch

def make(kind):
    state = {"n": 0} if kind.startswith("dict") else []
    class Helper:
        def touch(self):
            if kind == "dict +=":
                state["n"] += 1
            elif kind == "dict setitem":
                state["k"] = 1
            elif kind == "list append":
                state.append(1)
            elif kind == "list +=":
                state.extend([1])
    def f(x):
        Helper().touch()
        return x + 1
    return f, state

for kind in ("dict +=", "dict setitem", "list append", "list +="):
    res = []
    for comp in (False, True):
        torch._dynamo.reset()
        f, state = make(kind)
        g = torch.compile(f, backend="eager", fullgraph=True) if comp else f
        g(torch.ones(1)); g(torch.ones(1))
        res.append(str(state))
    print(f"{kind:13s} eager {res[0]:18s} compiled {res[1]}")
```

```
dict +=       eager {'n': 2}           compiled {'n': 0}
dict setitem  eager {'n': 0, 'k': 1}   compiled {'n': 0}
list append   eager [1, 1]             compiled []
list +=       eager [1, 1]             compiled []
```

Forms that behave correctly with the same `Helper` and the same `state` (from `closure_mutation_minimal.py`):

| call inside the compiled function | compiled result |
|---|---|
| `Helper().touch()` (object created inside `f`) | **mutation lost** |
| `outer.touch()` with `outer = Helper()` created outside `f` | correct |
| a nested function `helper_fn()` that performs the same mutation | correct |
| class and state at module level | correct |

The same defect makes a locally defined context manager lose its side effects:

```python
def run():
    log = []
    class CM:
        def __enter__(self): log.append("enter"); return self
        def __exit__(self, *a): log.append("exit"); return False
    def f(x):
        with CM():
            y = x + 1
        return y * 2
    torch.compile(f, backend="eager")(torch.ones(2))
    return log          # eager: ['enter', 'exit']   compiled: []
```

Expected: the mutation is replayed after the graph runs, as it is for the other three forms; or, if Dynamo cannot track the closure cell of a method of an object without a source, a graph break (an error under `fullgraph=True`) instead of silently dropping the effect.

A likely place to look: the receiver is a `UserDefinedObjectVariable` created during tracing and therefore has no source; the closure cell reached through its method appears to be tracked as a fresh local object rather than as the pre-existing cell of the enclosing frame, so its mutation is never registered with `SideEffects` for replay.

### Error logs

No error and no graph break; the side effect is missing as shown above.

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

Same output on nightly (2.15.0.dev20260911 on Windows, 2.15.0.dev20260920 on Linux) and on Linux with 2.14.0 (Python 3.12), so it does not depend on the Python version or the platform.
