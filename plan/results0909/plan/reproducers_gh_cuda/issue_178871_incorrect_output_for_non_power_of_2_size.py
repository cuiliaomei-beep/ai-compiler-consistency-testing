# source: https://github.com/pytorch/pytorch/issues/178871
# title: Incorrect output for non-power-of-2-sized fusion of scalar broadcast and scatter-add
# state: closed  created: 2026-03-31
# mined automatically; the harness records the torch.compile target and its first call

import torch


def f(x, bias, idx):
    src = x + bias  # scalar broadcast fused with scatter by inductor
    out = torch.zeros(1, 1, device=x.device, dtype=x.dtype)
    return out.scatter_reduce(
        0, idx.unsqueeze(-1).expand_as(src), src, "sum", include_self=True
    )


for N in range(1, 65):
    device = torch.device("cuda")

    x    = torch.randn(N, 1, device=device)
    bias = torch.tensor([0.020368], device=device)
    idx  = torch.zeros(N, dtype=torch.long, device=device)

    ref = f(x, bias, idx)
    torch.compiler.reset()
    test = torch.compile(f, backend="inductor", fullgraph=True, dynamic=False)(x, bias, idx)

    diff      = test.item() - ref.item()
    next_pow2 = 1 << (N - 1).bit_length()
    expected  = (next_pow2 - N) * bias.item()
    print(f"N={N:2d}  diff={diff:+.6f}  expected={expected:+.6f}")
