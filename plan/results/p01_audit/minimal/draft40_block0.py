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
