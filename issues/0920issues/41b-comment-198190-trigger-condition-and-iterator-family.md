<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 41b（中：#198190 的补充评论——触发条件是生成器体内有张量运算；同一重建路径也把 enumerate / reversed / islice / tee / 部分消费的 list 迭代器 / 生成器表达式 / `Module.children()` 变成 `tuple_iterator`）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 类型 | **评论**（在自己的 #198190 下） |
| **提交网址** | https://github.com/pytorch/pytorch/issues/198190#new_comment_field |
| **怎么提交** | 打开上面链接，把 `## Comment` 以下内容原样粘贴到评论框，Comment |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；`backend="eager"` |
| 证据包 | `plan/scripts/reconstruct_diff.py`（79 种返回对象的重建差分，`results/reconstruct/cases.jsonl`）、`$TEMP/gen_kinds.py`（触发条件）；台账 90 |
| 说明 | 这段是 41 提交后才补进稿子的（触发条件 + 迭代器族），维护者没看到，所以单独作为评论 |

---

## Comment

Two additions after more probing (same versions: 2.14.0 and nightly, `backend="eager"`).

**1. The trigger is tensor work inside the generator body.** A generator that only yields pre-existing objects is reconstructed as a real `generator` and keeps its return value; as soon as the body computes on tensors, it is exhausted at trace time and comes back as a `tuple_iterator` with `StopIteration.value = None`:

```python
import torch


def yield_x(x):
    def g():
        yield x
        return 7
    return g()


def yield_op(x):
    def g():
        yield x * 1
        return 7
    return g()


def yield_const(x):
    def g():
        yield 1
        return 7
    return g()


def started_no_op(x):
    def g():
        yield x
        yield x
        return 7
    it = g()
    next(it)
    return it


for f in (yield_x, yield_op, yield_const, started_no_op):
    torch._dynamo.reset()
    it = torch.compile(f, backend="eager")(torch.ones(2))
    try:
        while True:
            next(it)
    except StopIteration as e:
        rv = e.value
    print(f"{f.__name__:14s} type={type(it).__name__:15s} StopIteration.value={rv!r}")
```

```
yield_x        type=generator       StopIteration.value=7
yield_op       type=tuple_iterator  StopIteration.value=None
yield_const    type=generator       StopIteration.value=7
started_no_op  type=generator       StopIteration.value=7
```

**2. The same reconstruction replaces other lazy iterators that escape a compiled frame** once their items had to be traced. Returning each of these from a compiled function gives a `tuple_iterator` where eager gives the original type: a generator expression `(t * 2 for t in [x, x + 1])`, `enumerate([x, x * 2], start=3)`, `reversed([x, x * 2, x * 3])`, `itertools.islice([x, x * 2, x * 3], 2)`, `itertools.tee([x, x * 2])[0]`, a partially consumed `iter([x, x * 2, x * 3])`, `nn.Sequential(...).children()`, and a partially consumed generator. For the ones without `send` / `throw` / a return value the only visible change is `type()`; `zip`, `map`, `filter`, `itertools.chain` / `accumulate` / `product` / `zip_longest` / `count`, `range` iterators, dict views and iterators, `functools.partial`, closures, namedtuples, exceptions with `__cause__`, `defaultdict` / `Counter` / `OrderedDict` / `deque` / `ChainMap`, slices and the other ~40 object kinds I tried come back with the right type and behaviour, so the problem is specific to the "exhaust and replay" path for iterators whose remaining items were produced by traced tensor operations.
