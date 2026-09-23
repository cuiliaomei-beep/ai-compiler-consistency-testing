# source: https://github.com/pytorch/pytorch/issues/195665
# title: [inductor] torch.compile skips as_strided's storage-bounds check and reads out of bounds, returning non-reproducible memory
# state: open  created: 2026-09-02
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    v1 = torch.full([1, 2], 1, dtype=torch.float32)                    # storage: 2 elements
    v2 = torch.as_strided(v1, size=[64, 64, 3], stride=[1, 64, 192])   # addresses 4480
    return torch.cumsum(v2, 1)

x = torch.randn(64, 1)

with torch.no_grad():
    try:
        f(x)
    except Exception as e:
        print("eager:", type(e).__name__ + ":", str(e).splitlines()[0])

    for i in range(3):
        torch._dynamo.reset()
        o = torch.compile(f, backend="inductor")(x)
        finite = o[torch.isfinite(o)]
        print(f"compiled run{i}: shape={tuple(o.shape)} nan={bool(torch.isnan(o).any())} "
              f"max_finite={finite.abs().max().item():.6g}")
