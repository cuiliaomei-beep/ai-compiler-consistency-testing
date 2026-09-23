# source: https://github.com/pytorch/pytorch/issues/195674
# title: torch.compile evaluates subtraction on a bool tensor that eager deliberately rejects (1 - mask)
# state: open  created: 2026-09-02
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    return 1 - (x < 0)

x = torch.randn(4)

with torch.no_grad():
    try:
        f(x)
    except Exception as e:
        print("eager:", type(e).__name__ + ":", str(e).splitlines()[0])
    out = torch.compile(f, backend="inductor")(x)
    print("compiled:", out.dtype, out.tolist())
