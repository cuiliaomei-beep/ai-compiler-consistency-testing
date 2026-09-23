<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 42b（中：#198192 的补充评论——被跳过的不只是 `except IndexError`：`except Exception`、`except LookupError`、`contextlib.suppress`、`__exit__` 吞异常、finally 顺序、re-raise、嵌套调用 / 循环 / 推导式 / 生成器里的 handler 全部被跳过；`NotImplementedError` 同样）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 类型 | **评论**（在自己的 #198192 下） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/198192#new_comment_field |
| **怎么提交** | 打开上面链接，把 `## Comment` 以下内容原样粘贴到评论框，Comment |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260921+cpu（Windows，Python 3.14）；`backend="eager"` |
| 证据包 | `tcc/dynamo_semantics_batch5.py`（33 个异常语义程序，`results/dynsem5/`：22 个程序 44 处分歧全是这一族；TypeError / ZeroDivisionError / assert / `torch._check` / `except*` / warnings 各程序与 eager 一致）；台账 100 |

---

## Comment

Some more shapes of the same defect, in case it helps scope the fix (torch 2.14.0 and nightly 2.15.0.dev20260921, `backend="eager"`). The `IndexError` raised by a tensor op inside the compiled function is not seen by *any* Python construct that would catch it in eager, not only by `except IndexError`:

```python
import contextlib
import torch


def as_exception(x):
    try:
        return x[10]
    except Exception as e:            # the broadest handler
        return f"caught {type(e).__name__}"


def as_lookup_error(x):
    try:
        return x.select(0, 10)
    except LookupError as e:          # IndexError's base class
        return f"caught {type(e).__name__}"


def suppressed(x):
    with contextlib.suppress(IndexError):
        return x.sum(dim=5)
    return "suppressed"


def swallowed_by_exit(x):
    class Swallow:
        def __enter__(self):
            return self
        def __exit__(self, et, ev, tb):
            return True               # swallow everything
    with Swallow():
        return x[100]
    return "swallowed"


def nested_call(x):
    def inner(t):
        return t.softmax(dim=6)
    try:
        return inner(x)
    except IndexError:
        return "caught in caller"


def finally_then_except(x):
    log = []
    try:
        try:
            return x.chunk(2, dim=6)
        finally:
            log.append("finally")
    except IndexError:
        log.append("except")
        return log


def not_implemented(x):
    try:
        return x & x                  # NotImplementedError for float tensors
    except NotImplementedError as e:
        return f"caught {type(e).__name__}"


x = torch.ones(3, 4)
for f in (as_exception, as_lookup_error, suppressed, swallowed_by_exit, nested_call, finally_then_except, not_implemented):
    torch._dynamo.reset()
    try:
        compiled = torch.compile(f, backend="eager")(x)
    except Exception as e:
        compiled = f"ESCAPED {type(e).__name__}"
    print(f"{f.__name__:20s} eager: {f(x)!s:24s} compiled: {compiled}")
```

```
as_exception         eager: caught IndexError        compiled: ESCAPED IndexError
as_lookup_error      eager: caught IndexError        compiled: ESCAPED IndexError
suppressed           eager: suppressed               compiled: ESCAPED IndexError
swallowed_by_exit    eager: swallowed                compiled: ESCAPED IndexError
nested_call          eager: caught in caller         compiled: ESCAPED IndexError
finally_then_except  eager: ['finally', 'except']    compiled: ESCAPED IndexError
not_implemented      eager: caught NotImplementedError compiled: ESCAPED NotImplementedError
```

The same happens for the handler inside a `for` loop with `continue`, inside a list comprehension / `map` helper, in the consumer of a generator (`except IndexError` around `next(it)`), with `sys.exc_info()`, after a bare re-raise, with `raise ... from e`, and inside `with torch.no_grad()`. By contrast, `TypeError` from `x + "s"` or `x.to(dtype="float99")`, `ZeroDivisionError` from `1 / t.item()`, `AssertionError`, `torch._check` failures and `except*` groups all take the handler correctly, so the gap is specific to the exception types that `run_node` re-raises instead of routing through `raise_observed_exception` (`IndexError`, `NotImplementedError`).
