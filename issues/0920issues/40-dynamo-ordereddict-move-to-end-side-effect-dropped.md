<!-- 提交信息（不要复制到 issue 里） -->
# pytorch/pytorch — 0920 issue 40（中：Dynamo 丢掉传入字典上的 `OrderedDict.move_to_end()`——重排序不作为副作用回放，LRU 缓存淘汰错条目；`fullgraph=True` 也不报错）

| 项 | 值 |
|---|---|
| 仓库 | https://github.com/pytorch/pytorch |
| 验证版本 | torch 2.14.0+cpu 与 nightly 2.15.0.dev20260911+cpu（Windows，Python 3.14）；`backend="eager"`，与后端无关，纯 Dynamo；**Linux x86-64 / Python 3.12 已复核**（Kaggle `tcc-dynsemlinux`，torch 2.14.0 与 nightly 2.15.0.dev20260922：`graph_break_insertion_diff.py` 的 `collections_types` 分歧与 Windows 逐条相同） |
| **提交 issue 链接** | https://github.com/pytorch/pytorch/issues/new?template=pt2-bug-report.yml |
| 使用的模板 | `.github/ISSUE_TEMPLATE/pt2-bug-report.yml` |
| 提交前查重 | 2026-09-22（约 19:20）：`move_to_end torch.compile`、`OrderedDict mutation lost compile`、`dict input mutation not applied dynamo side effect`、`OrderedDict side effect dynamo popitem`、`dynamo dict mutation input argument reorder`：无同报告。相关但不同：#155152（实现 `move_to_end(last=False)` 的 PR，只管追踪值，不管回放）、#191365 / #189549（OrderedDict 变量重构 PR）、#196208（并发修改 OrderedDict 崩溃） |
| 证据包 | `plan/scripts/graph_break_insertion_diff.py`（7.6：语料 185 程序逐语句插 graph break；`collections_types` 在 `od['a']=…` 与 `move_to_end` 前后各插一个 break 时键序变 `['z','a']`）；`$TEMP/od_input.py`、`od_variants.py`、`od_bisect.py`（最小化：不需要 graph break，字典是入参或对象属性即可） |
| 根因 | `torch/_dynamo/variables/dicts.py` `OrderedDictVariable.move_to_end`：调 `side_effects.mutation(self)` 并重排 `self.items`，但**不设 `should_reconstruct_all`**；`side_effects.py` 的回放处理器 `_codegen_const_dict_or_set_mutation` 只在 `has_new_items()` 为真时生成代码（"Skip codegen if there are no new items"），而 `has_new_items()` = `should_reconstruct_all or 键/值有变化`——纯重排两者皆假 → 什么都不回放。即便回放，也只有键被删除时才 `clear()` 再 `update()`，`update()` 对已有键保留原位置，同样丢重排。全局字典的 `should_reconstruct_all` 为真（非 local source），所以全局 OrderedDict 正确；入参、对象属性（local source）丢失 |
| 建议标签 | oncall: pt2, module: dynamo, module: correctness (silent) |

---

## Title

[dynamo] `OrderedDict.move_to_end()` on a dict passed into a compiled function is silently dropped: the reorder is not replayed as a side effect, so an LRU cache evicts the wrong entry (`fullgraph=True` does not complain)

## Body

### 🐛 Describe the bug

**Summary.** Calling `cache.move_to_end("a")` on an `OrderedDict` argument (or object attribute) inside a `torch.compile`d function leaves the dict in its old order after the call, while eager moves `"a"` to the end and the same reorder written as `cache["a"] = cache.pop("a")` is replayed correctly (torch 2.14.0 and nightly, `backend="eager"`, so this is Dynamo alone). A user who keeps an LRU cache next to a compiled step gets no error, the return values are right, and only the cache's key order is wrong, so the next insertion evicts the entry that was just used. Because `OrderedDictVariable.move_to_end` records the mutation without marking the dict for full reconstruction, the side-effect replay in `side_effects.py` sees no new items and emits nothing, rather than clearing and rebuilding the dict in its traced order.

```python
import collections
import torch


def touch(cache, x):
    cache.move_to_end("a")  # mark "a" as most recently used
    return x + 1


def touch2(cache, x):
    cache["a"] = cache.pop("a")  # the same reorder, spelled with pop + reinsert
    return x + 1


for f in (touch, touch2):
    for mode in ("eager", "compiled"):
        cache = collections.OrderedDict(a=1, b=2, c=3)
        fn = f if mode == "eager" else torch.compile(f, backend="eager", fullgraph=True)
        fn(cache, torch.ones(2))
        print(f"{f.__name__:6s} {mode:8s} order afterwards: {list(cache)}")


class LRU:
    def __init__(self, cap):
        self.d, self.cap = collections.OrderedDict(), cap

    def get(self, k):
        self.d.move_to_end(k)
        return self.d[k]

    def put(self, k, v):
        self.d[k] = v
        if len(self.d) > self.cap:
            self.d.popitem(last=False)


def step(cache, x):
    cache.get("a")  # cache hit: "a" becomes the most recently used entry
    return x + 1


for mode in ("eager", "compiled"):
    cache = LRU(2)
    cache.put("a", 1)
    cache.put("b", 2)
    fn = step if mode == "eager" else torch.compile(step, backend="eager")
    fn(cache, torch.ones(2))
    cache.put("c", 3)  # outside the compiled region: evicts the least recently used entry
    print(f"LRU    {mode:8s} after get('a') then put('c'): {list(cache.d)}")
```

```
touch  eager    order afterwards: ['b', 'c', 'a']
touch  compiled order afterwards: ['a', 'b', 'c']
touch2 eager    order afterwards: ['b', 'c', 'a']
touch2 compiled order afterwards: ['b', 'c', 'a']
LRU    eager    after get('a') then put('c'): ['a', 'c']
LRU    compiled after get('a') then put('c'): ['b', 'c']
```

`fullgraph=True` raises nothing, so there is no hint that a mutation was dropped. `move_to_end(k, last=False)` is dropped the same way. Every other `OrderedDict` / `dict` mutation I tried on an input dict is replayed correctly (`popitem`, `del`, `clear`, `update`, `setdefault`, `pop` + reinsert), as are `deque.rotate` / `appendleft`, `list.reverse` / `sort` / `insert` and set mutations. A *global* `OrderedDict` is also fine, and so is a dict created inside the compiled function, which is why the plain `torch.compile` test-suite cases do not catch this: the reorder is only lost on a dict that comes in through a local source (argument, attribute of an argument).

**Root cause and possible fix.** `torch/_dynamo/variables/dicts.py`, `OrderedDictVariable.move_to_end`, calls `tx.output.side_effects.mutation(self)` and reorders `self.items`, but does not set `self.should_reconstruct_all`. The replay handler `_codegen_const_dict_or_set_mutation` in `torch/_dynamo/side_effects.py` starts with "(1) Skip codegen if there are no new items": `has_new_items()` is `should_reconstruct_all or any(key/value changed)`, and a pure reorder changes neither, so nothing is emitted for the dict. (Even when something else does make `has_new_items()` true, e.g. a later `d["q"] = 9`, the replay is `d.update(new_items)` without `clear()`, and `dict.update` keeps the existing position of existing keys, so the reorder is still lost; only a key *removal* sets `should_reconstruct_all` and triggers `clear()` + `update()`, which is why `move_to_end` followed by `popitem` happens to come out right.) The fix is one line: `move_to_end` should set `self.should_reconstruct_all = True` (as `popitem` effectively does through key removal), so that the dict is cleared and rebuilt in the traced order at the end of the frame. Globals already take that path (`should_reconstruct_all` is `True` for non-local sources), which is why the global-dict variant works.

### Error logs

No error is raised; `fullgraph=True` compiles the function without complaint and the dict order after the call is wrong as shown above.

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
