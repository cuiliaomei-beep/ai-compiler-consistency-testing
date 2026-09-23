# source: https://github.com/pytorch/pytorch/issues/192906
# title: reuse_hash_fn leaves a subscripted capture pinned to the traced index
# state: open  created: 2026-08-11
# mined automatically; the harness records the torch.compile target and its first call

import torch

ncr = torch.compiler.nested_compile_region


class Pool:
    def __init__(self, buffers):
        self.buffers = buffers


class Layer(torch.nn.Module):
    def __init__(self, layer_id, pool):
        super().__init__()
        self.layer_id = layer_id
        self.pool = pool

    def forward(self, x):
        return x.sin() + self.pool.buffers[self.layer_id]


# The key ignores layer_id on purpose: the caller is asserting "same region,
# different slot", which is the reason to reach for reuse_hash_fn on a KV cache.
@ncr(reuse_hash_fn=lambda layer, x: 0)
def gn(layer, x):
    return layer(x)


n = 4
pool = Pool([torch.ones(4) * (i + 1) * 10 for i in range(n)])
layers = [Layer(i, pool) for i in range(n)]


def fn(x):
    return sum(gn(layer, x) for layer in layers)


x = torch.zeros(4)
print(fn(x))                                                    # 100.0
print(torch.compile(fn, backend="aot_eager", fullgraph=True)(x))  # 40.0
