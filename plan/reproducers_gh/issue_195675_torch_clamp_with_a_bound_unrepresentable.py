# source: https://github.com/pytorch/pytorch/issues/195675
# title: torch.clamp with a bound unrepresentable in the tensor dtype: eager raises, torch.compile ignores the bound
# state: open  created: 2026-09-02
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    return torch.clamp(x, min=-3.4e39, max=3.4e39)   # beyond float32 range

x = torch.randn(4)

with torch.no_grad():
    try:
        f(x)
    except Exception as e:
        print("eager:", type(e).__name__ + ":", str(e).splitlines()[0])
    out = torch.compile(f, backend="inductor")(x)
    print("compiled:", out.dtype, "max|out| =", out.abs().max().item())
