<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 41（中：从编译函数返回、或跨 graph break 存活的生成器被重建成已耗尽的 `tuple_iterator`——`StopIteration.value` 静默变 None，`.send()` / `.throw()` 抛 AttributeError，`type()` 变）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；`backend="eager"`；`torch._dynamo.config.enable_faithful_generator_behavior` 真/假都一样；**Linux x86-64 / Python 3.12 已复核**（Kaggle `tcc-dynsemlinux`，torch 2.14.0 与 nightly 2.15.0.dev20260922：`graph_break_insertion_diff.py` 的 `gen_send` / `gen_throw` / `gen_return_value_stopiteration` 分歧与 Windows 逐条相同） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22（约 19:20）：`generator graph break tuple_iterator`、`dynamo generator send graph break`、`StopIteration value generator dynamo`、`generator reconstruct exhaust graph break`、`generator send after graph break AttributeError`、`generator alive across graph break`、`generator StopIteration value None compile`、`tuple_iterator dynamo`：无同报告。相关但不同：#149037 / PR #185769（**内联**生成器的返回值丢失——已修，本稿的无 graph break、不返回生成器的情形因此是对的）；#146628 / PR #185920（重建生成器时检测张量修改——同一重建路径，管的是副作用检测）；PR #188622 / #188738（嵌套 graph break 下**已耗尽**生成器的重建）；PR #188825（`.throw` / `.close` 的子生成器支持——内联路径） |
| 证据包 | `plan/scripts/reconstruct_diff.py`（12.6：79 种返回对象的重建差分——enumerate / reversed / islice / tee / 部分消费的 list_iterator / 生成器表达式 / `Module.children()` 同样变 tuple_iterator，其余 partial / namedtuple / 异常链 / defaultdict / deque / ChainMap / 切片 / 大整数 / dict 视图等全部一致）、`$TEMP/gen_kinds.py`（触发条件）；`plan/scripts/graph_break_insertion_diff.py`（7.6：语料逐语句插 graph break，`gen_send` / `gen_throw` 新增 AttributeError、`gen_return_value_stopiteration` 返回值 42 → None）；`$TEMP/gb_min.py`、`od_input.py`（最小化：返回生成器即可复现，不需要 graph break） |
| 根因 | 触发条件：生成器体内有张量运算（`yield x*1`）；只 yield 已有对象（`yield x`、`yield 1`）的生成器会被重建成真生成器、返回值也在。`torch/_dynamo/variables/functions.py` `LocalGeneratorObjectVariable.reconstruct`：`self.remaining_items = unpack_iterable(tx, self)`（追踪期把生成器跑到耗尽）然后 `ListIteratorVariable(self.remaining_items).reconstruct(codegen)`——重建出来的是元组迭代器：没有 `send` / `throw` / `close`、没有 `gi_frame`、`StopIteration.value` 丢失、惰性丢失（副作用全部提前发生）。设计源自 PR #145223（"只在无副作用时重建生成器"），但值的丢失是静默的 |
| 建议标签 | oncall: pt2, module: dynamo, module: correctness (silent) |

---

## Title

[dynamo] A generator that leaves a compiled region (returned, or alive across a graph break) comes back as an exhausted `tuple_iterator`: `StopIteration.value` is silently `None`, `.send()` / `.throw()` raise AttributeError, `type()` changes

## Body

### 🐛 Describe the bug

**Summary.** A compiled function that returns a generator object, or that hits a graph break while a local generator is still suspended, hands the caller a `tuple_iterator` holding the remaining yields, while eager hands back the `generator` (torch 2.14.0 and nightly, `backend="eager"`, both settings of `enable_faithful_generator_behavior`). The yielded values match, so the substitution is invisible until the caller uses what a tuple iterator lacks: the generator's return value arrives as `StopIteration.value = None` with no error, and `.send()` / `.throw()` raise `AttributeError: 'tuple_iterator' object has no attribute 'send'` where eager works. Because `LocalGeneratorObjectVariable.reconstruct` unpacks the rest of the generator at trace time and reconstructs a `ListIteratorVariable`, rather than a real generator or a graph break, the return value, coroutine protocol and laziness of every escaping generator are lost.

```python
import torch


def make(x):
    def gen():
        yield x * 1
        yield x * 2
        return "done"
    return gen()


def consume(it):
    out = [type(it).__name__]
    try:
        while True:
            out.append(next(it).sum().item())
    except StopIteration as e:
        out.append(f"StopIteration.value={e.value!r}")
    return out


x = torch.ones(2)
print("eager   :", consume(make(x)))
print("compiled:", consume(torch.compile(make, backend="eager")(x)))


def accumulate(x):
    def acc(t):
        total = t
        while True:
            v = yield total
            if v is None:
                return
            total = total + v
    g = acc(x)
    next(g)
    torch._dynamo.graph_break()  # any graph break while the generator is suspended
    return [g.send(x).tolist(), g.send(x * 2).tolist()]


print("eager   :", accumulate(x))
try:
    print("compiled:", torch.compile(accumulate, backend="eager")(x))
except AttributeError as e:
    print("compiled:", type(e).__name__, e)
```

```
eager   : ['generator', 2.0, 4.0, "StopIteration.value='done'"]
compiled: ['tuple_iterator', 2.0, 4.0, 'StopIteration.value=None']
eager   : [[2.0, 2.0], [4.0, 4.0]]
compiled: AttributeError 'tuple_iterator' object has no attribute 'send'
```

The first case needs no graph break at all: returning the generator is enough. The trigger is tensor work inside the generator body: a generator that only yields pre-existing objects (`yield x`, `yield 1`) comes back as a real `generator` with its return value intact, while `yield x * 1` (or `yield t + 1` on a parameter) is exhausted at trace time and returned as a `tuple_iterator` with `StopIteration.value = None`. The same reconstruction replaces other lazy iterators that escape a compiled frame when their items had to be traced: a generator expression `(t * 2 for t in ...)`, `enumerate(...)`, `reversed(...)`, `itertools.islice` / `itertools.tee`, a partially consumed `list_iterator`, and `nn.Module.children()` all return as `tuple_iterator` (for those without `send` / `throw` / a return value the only visible change is `type()`, so the generator case is the one that changes results). The second case is what happens to *any* program that keeps a generator in a local and then graph-breaks for an unrelated reason (a `print`, an unsupported call, a data-dependent branch): the resume function receives a tuple iterator, and `.send()`, `.throw()`, `.close()`-with-`finally` semantics and `type(g)` checks all change. (`gi.throw(ValueError(...))` fails the same way; `.close()` happens to "work" only because the exhausted iterator has nothing left to close.) With no graph break and no escaping generator, i.e. the fully inlined path, everything above is correct, including the return value since PR #185769.

**Root cause and possible fix.** `torch/_dynamo/variables/functions.py`, `LocalGeneratorObjectVariable.reconstruct`: if the generator's frame is not finished, `self.remaining_items = unpack_iterable(tx, self)` runs the generator body to exhaustion at trace time, and then `variables.ListIteratorVariable(self.remaining_items).reconstruct(codegen)` emits a tuple iterator. This reconstruction is only guarded against *side effects inside the generator* (`disallow_side_effects_in_generator`, and #185920 for tensor mutations), not against the object being observably different afterwards. Two fixes are possible: (a) graph-break (fall back to eager for the frame) whenever a suspended generator has to be reconstructed, which keeps eager semantics at some performance cost; or (b) keep the exhaustion approach but reconstruct a real generator that replays the collected items and finally `return`s the collected `StopIteration.value` (a small generator function `def _replay(items, rv): yield from items; return rv`), which restores `type()`, `StopIteration.value`, `.throw()` and `.close()`; `.send()` with a non-`None` argument cannot be emulated that way and should still graph-break. Either way, silently returning `None` as the generator's return value should not survive.

### Error logs

The return-value case raises nothing (the value is silently `None`). The `.send()` case:

```
AttributeError: 'tuple_iterator' object has no attribute 'send'
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

Same output on nightly 2.15.0.dev20260911+cpu; identical with `torch._dynamo.config.enable_faithful_generator_behavior = False`. `backend="eager"`, so no Inductor / AOTAutograd involvement.
