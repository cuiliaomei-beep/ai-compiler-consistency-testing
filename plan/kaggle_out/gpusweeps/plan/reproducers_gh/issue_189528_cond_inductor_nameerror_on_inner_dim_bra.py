# source: https://github.com/pytorch/pytorch/issues/189528
# title: [cond] Inductor NameError on inner-dim branch output mismatch
# state: closed  created: 2026-07-10
# mined automatically; the harness records the torch.compile target and its first call

import torch

def h(x, y):
    pred = torch.tensor(True)

    def true_fn():
        return torch.ones(x.shape[0], x.shape[1])

    def false_fn():
        return torch.zeros(x.shape[0], y.shape[1])

    return torch.cond(pred, true_fn, false_fn)

torch.compile(h, backend="inductor", fullgraph=True, dynamic=True)(torch.randn(5, 7), torch.randn(5, 8))
