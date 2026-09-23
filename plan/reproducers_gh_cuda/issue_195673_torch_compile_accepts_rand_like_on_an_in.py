# source: https://github.com/pytorch/pytorch/issues/195673
# title: torch.compile accepts rand_like on an integer tensor that eager rejects, and returns an all-zero tensor
# state: open  created: 2026-09-02
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    return torch.rand_like(x)

x = torch.ones(4, dtype=torch.int64)

with torch.no_grad():
    try:
        f(x)
    except Exception as e:
        print("eager:", type(e).__name__ + ":", str(e).splitlines()[0])
    out = torch.compile(f, backend="inductor")(x)
    print("compiled:", out.dtype, out.tolist())
