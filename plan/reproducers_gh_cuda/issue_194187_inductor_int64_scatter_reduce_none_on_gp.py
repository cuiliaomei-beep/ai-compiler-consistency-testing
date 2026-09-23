# source: https://github.com/pytorch/pytorch/issues/194187
# title: [inductor] int64 scatter_ (reduce=None) on GPU devices falls back without deterministic algorithms, unlike index_put_
# state: open  created: 2026-08-20
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch.manual_seed(0)
dev = "cuda"


def fn(x, idx, src):
    # x.index_put_((idx,), src)
    x.scatter_(0, idx, src)
    return x


torch._inductor.config.fx_graph_cache = False

x = torch.zeros(64, dtype=torch.int64, device=dev)
idx = torch.randperm(64, device=dev)[:32]
src = torch.randint(1, 9, (32,), dtype=torch.int64, device=dev)

torch.compile(fn)(x, idx, src)
