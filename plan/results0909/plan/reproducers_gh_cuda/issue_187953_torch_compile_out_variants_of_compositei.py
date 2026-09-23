# source: https://github.com/pytorch/pytorch/issues/187953
# title: torch.compile: out= variants of CompositeImplicitAutograd linalg ops (linalg.norm, cholesky, ...) recompile on every input shape
# state: open  created: 2026-06-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch._logging.set_logs(recompiles=True)

def f(x):
    out = x.new_empty(x.shape[0])
    torch.linalg.norm(x, dim=1, out=out)
    return out

cf = torch.compile(f)
for n in range(4, 10):
    cf(torch.randn(n, 6))   # recompiles on every n
