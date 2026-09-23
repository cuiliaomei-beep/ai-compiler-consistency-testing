<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — issue draft 22: 完整追踪的函数内 `str(KeyError(...))` 丢掉 CPython 的引号

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu（Windows Py3.14 + Linux Py3.11）；nightly 2.15.0.dev20260911（Windows）/ dev20260912（Linux，`kaggle_out/leads2linux.txt`）。backend=eager，`fullgraph=True` 或任何没有 graph break 的追踪 |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | https://github.com/pytorch/pytorch/issues?q=is%3Aissue%20dynamo%20KeyError%20str（`results/dedup_0912b.txt`） |
| 证据包 | `plan/scripts/diag_keyerror_str.py`，`plan/results/dynsem2/DYNSEM.md`（`exception_after_graph_break` 命中——原程序里 graph break 之后的段落反而是对的，分歧出在被追踪的段落） |
| 建议标签 | oncall: pt2, module: dynamo |
| 备注 | 低优先级；但代码里 `if "'x'" in str(e)` 或把 `str(e)` 写进日志/断言的用户会看到差异。Linux 已复核，相同 |

---

## 标题

[dynamo] `str(KeyError(...))` inside a traced region omits the quotes CPython adds (`"'k'"` in eager, `'k'` compiled)

## 🐛 Describe the bug

CPython's `KeyError.__str__` returns the `repr` of a single argument (`str(KeyError("k")) == "'k'"`). Inside a `torch.compile`d function that Dynamo traces fully, `str(e)` for a caught `KeyError` returns the plain message instead:

```python
import torch


def f(x):
    try:
        raise KeyError("k")
    except KeyError as e:
        return x, str(e), f"key error: {e}"


def g(x):
    d = {}
    try:
        d["missing"]
    except KeyError as e:
        return x, str(e)


x = torch.zeros(1)
print(f(x)[1:])                                             # ("'k'", "key error: 'k'")
print(torch.compile(f, backend="eager", fullgraph=True)(x)[1:])   # ('k', 'key error: k')
print(g(x)[1], torch.compile(g, backend="eager", fullgraph=True)(x)[1])   # 'missing' 'missing' -> "'missing'" vs 'missing'
```

Output (torch 2.14.0+cpu and 2.15.0.dev20260911+cpu):

```
("'k'", "key error: 'k'")
('k', 'key error: k')
'missing' missing
```

`repr(e)` and `e.args` are not affected. Other exception types (`ValueError("v")` → `'v'`) agree because their `__str__` is the base one. If the `try` block sits after a graph break (e.g. `torch._dynamo.graph_break()` right before it), the real exception object is used and the result matches eager — which is how the differential test first noticed it: the same program gave the right string in the resumed part and the wrong one in the traced part.

Expected: `str(e)` identical to eager (Dynamo's exception variable should dispatch `__str__` to the concrete exception class, `KeyError.__str__`, not `BaseException.__str__`).

### Error logs

No error; string differs.

### Versions

(torch 2.14.0+cpu, Windows 11, Python 3.14; same on the 2026-09-11 nightly wheel, and on Linux with Python 3.11: torch 2.14.0+cpu and 2.15.0.dev20260912+cpu.)
