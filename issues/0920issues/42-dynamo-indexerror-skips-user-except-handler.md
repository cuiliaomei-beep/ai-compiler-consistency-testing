<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 42（高：张量算子在编译函数内抛出的 `IndexError` 跳过用户自己的 `except IndexError`，直接逃出编译调用；`RuntimeError` 自 PR #184990 起会进 handler，`IndexError` 没有；`fullgraph=True` 也不报）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；`backend="eager"`，纯 Dynamo；`fullgraph` 真假都一样（假时也不回退到 eager） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22 20:10：`IndexError try except torch.compile not caught`、`dynamo observed exception IndexError fake tensor`、`torch.compile try except tensor IndexError escapes`、`dynamo exception from tensor op not catchable user try`、`dim out of range IndexError torch.compile except`：无同报告。相关但不同：**#184340 / #184364**（2026-05，已关：逃出 `torch.compile` 的异常是 `TorchRuntimeError` 等包装类型而不是 `IndexError`，调用方的 `except IndexError` 接不到；PR #184452 把它改回 IndexError——本稿是**函数内部**的 handler 仍被跳过，正是那次修复之后剩下的一半）；**PR #184990**（2026-08 合入："Route fake RuntimeError through user exception handlers"——只给 `RuntimeError` 接了 handler）；PR #185776；伞形 #197554（维护者的 "Validation lost"，可在评论里链过去） |
| 证据包 | `tcc/dynamo_semantics_batch4.py::try_error_in_except_handler`（语料第 4 批基线分歧，台账 94）；`$TEMP/nested_try.py`、`nested_try2.py`、`exc_types.py`（25 种算子错误：IndexError 族 12/12 逃出，RuntimeError 族 10/11 被捕获——唯一例外 `gather` 越界是运行期数据依赖错误，另当别论；TypeError 族变 `Unsupported`） |
| 根因 | `torch/_dynamo/utils.py`：`run_node` 里 `except IndexError: raise`（注释 "Re-raise IndexError from tensor dim validation … so it reaches the user as IndexError"，PR #184452 加的）把 fake 张量算出的 IndexError 原样抛出；而 `get_fake_value` 只对 `RuntimeError` 分支做 `raise_observed_exception(RuntimeError, tx, args=[msg])`（PR #184990）——IndexError 走不到这一支，从未变成 Dynamo 的 observed exception，帧内的 handler 因而永远不会被跳到，异常直接穿出 `torch.compile` |
| 建议标签 | oncall: pt2, module: dynamo, module: correctness (silent) |

---

## Title

[dynamo] `IndexError` raised by a tensor op inside a compiled function skips the user's own `except IndexError` and escapes the compiled call (`RuntimeError` is routed to the handler since #184990; `fullgraph=True` does not complain)

## Body

### 🐛 Describe the bug

**Summary.** Inside a `torch.compile`d function, `try: x.sum(dim=5) except IndexError: <fallback>` runs the fallback in eager, while the compiled function raises `IndexError` out of the call and never executes the handler (torch 2.14.0 and nightly, `backend="eager"`, `fullgraph=True` or `False`); the same code with a `RuntimeError`-raising op (`x.view(5, 5)`) takes the handler. A user's defensive dimension / index fallback works in eager and silently disappears under compile, with no warning, so the program fails where it used to recover. Because `run_node` re-raises `IndexError` unchanged (the fix for #184340) before `get_fake_value` reaches the branch that turns fake-tensor `RuntimeError`s into observed exceptions, rather than routing every exception type to the user handler, every `IndexError` from dim / index validation (`x[i]`, `select`, `sum(dim)`, `softmax(dim)`, `transpose`, `squeeze`, `chunk`, `index_select`) bypasses `try/except` in compiled code.

```python
import torch

OPS = {
    "x[10]": lambda x: x[10],
    "x.select(0, 10)": lambda x: x.select(0, 10),
    "x.sum(dim=5)": lambda x: x.sum(dim=5),
    "x.softmax(dim=4)": lambda x: x.softmax(dim=4),
    "x.transpose(0, 5)": lambda x: x.transpose(0, 5),
    "x.view(5, 5)": lambda x: x.view(5, 5),  # RuntimeError: handled correctly
    "torch.cat([x, x.t()])": lambda x: torch.cat([x, x.t()]),  # RuntimeError: handled correctly
}


def guarded(x, op):
    try:
        return op(x)
    except (IndexError, RuntimeError) as e:
        return f"fallback after {type(e).__name__}"


x = torch.ones(3, 4)
for name, op in OPS.items():
    torch._dynamo.reset()
    eager = guarded(x, op)
    try:
        compiled = torch.compile(guarded, backend="eager", fullgraph=True)(x, op)
    except Exception as e:
        compiled = f"ESCAPED {type(e).__name__}: {e}"[:70]
    print(f"{name:22s} eager: {eager:28s} compiled: {compiled}")


# the usual defensive pattern, fullgraph=False: no fallback to eager either
def reduce_dim(x, dim):
    try:
        return x.sum(dim)
    except IndexError:
        return x.sum(-1)


torch._dynamo.reset()
print("eager   :", reduce_dim(x, 5).tolist())
try:
    print("compiled:", torch.compile(reduce_dim, backend="eager")(x, 5).tolist())
except IndexError as e:
    print("compiled: IndexError escaped:", str(e).splitlines()[0])
```

```
x[10]                  eager: fallback after IndexError    compiled: ESCAPED IndexError: index 10 is out of bounds for dimension 0 with siz
x.select(0, 10)        eager: fallback after IndexError    compiled: ESCAPED IndexError: select(): index 10 out of range for tensor of size
x.sum(dim=5)           eager: fallback after IndexError    compiled: ESCAPED IndexError: Dimension out of range (expected to be in range of
x.softmax(dim=4)       eager: fallback after IndexError    compiled: ESCAPED IndexError: Dimension out of range (expected to be in range of
x.transpose(0, 5)      eager: fallback after IndexError    compiled: ESCAPED IndexError: Dimension out of range (expected to be in range of
x.view(5, 5)           eager: fallback after RuntimeError  compiled: fallback after RuntimeError
torch.cat([x, x.t()])  eager: fallback after RuntimeError  compiled: fallback after RuntimeError
eager   : [4.0, 4.0, 4.0]
compiled: IndexError escaped: Dimension out of range (expected to be in range of [-2, 1], but got 5)
```

Nothing in the compiled path reports a problem: `fullgraph=True` compiles the function, there is no graph break, and the handler body is simply never reached. The caller-side `except IndexError` around the compiled call *does* work since #184340 / PR #184452 (the exception that escapes is a genuine `IndexError`), which is exactly why the in-function handler being skipped is easy to miss. A handler further out in the same compiled function (nested `try`, handler inside an `except` or `finally` block of another `try`) is skipped the same way; `NotImplementedError` from an op (`x.int() & 1.5`) also escapes; `TypeError`s become `Unsupported`.

**Root cause and possible fix.** `torch/_dynamo/utils.py`: `run_node` ends with

```python
except IndexError:
    # Re-raise IndexError from tensor dim validation (e.g. canonicalize_dim,
    # maybe_wrap_dim) so it reaches the user as IndexError, not RuntimeError.
    raise
except Exception as e:
    raise RuntimeError(make_error_message(e)) ...
```

so an `IndexError` from the fake kernel propagates as-is, while every other failure is wrapped into a `RuntimeError`. `get_fake_value` then handles `except RuntimeError as e:` and calls `raise_observed_exception(RuntimeError, tx, args=[msg])` (PR #184990), which jumps to a live user handler when there is one and otherwise surfaces a `FakeTensorObservedException`; that branch is what makes `except RuntimeError` inside compiled code work. The re-raised `IndexError` is not a `RuntimeError`, so it skips that branch entirely: it never becomes an observed exception, the handler is never jumped to, and the exception unwinds through Dynamo out of the compiled call. The fix is to route it the same way: catch `IndexError` (and `NotImplementedError`) in `get_fake_value` next to `RuntimeError` and call `raise_observed_exception(type(e), tx, args=[msg])` when a live user handler exists, keeping the current re-raise only for the no-handler case so the caller still sees an `IndexError`. A test that the whole `test_exceptions.py` family already has for `RuntimeError` (`try: op() except RuntimeError: fallback`) would catch this for the other exception types if parametrised over them.

### Error logs

`fullgraph=True` compiles without a graph break; the compiled call raises the exception the user's handler was written to catch, e.g.

```
IndexError: Dimension out of range (expected to be in range of [-2, 1], but got 5)
```

### Versions

```
PyTorch version: 2.14.0+cpu
OS: Microsoft Windows 11 Pro for Workstations (10.0.26200 64-bit)
Python version: 3.14.7 (64-bit runtime)
Is CUDA available: False
[pip3] numpy==2.5.2
[pip3] torch==2.14.0+cpu
```

Same output on nightly 2.15.0.dev20260911+cpu. `backend="eager"`, so no Inductor / AOTAutograd involvement.
