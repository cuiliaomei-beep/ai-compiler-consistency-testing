# source: https://github.com/pytorch/pytorch/issues/188084
# title: [BUG] Inductor reinplaces `index_put` on expanded view and silently corrupts gradients
# state: closed  created: 2026-06-24
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.func import grad_and_value, vmap

torch.set_default_dtype(torch.float64)

B, D = 4, 4
idx = torch.tensor([0, 2])
w = torch.tensor([1.0, -1.0])
X = torch.randn(B, D)


def f(x):
    stacked = torch.stack([x[..., k] for k in range(D)], dim=-1)
    return (torch.index_select(stacked, -1, idx) * w).sum(-1)


def ref_grad():
    Xr = X.clone().requires_grad_(True)
    vals = torch.stack([f(Xr[i : i + 1]).reshape(()) for i in range(B)])
    return torch.autograd.grad(vals.sum(), Xr)[0]


def row(x):
    return f(x).reshape(())


ref = ref_grad()

for backend in ("eager", "aot_eager", "inductor"):
    torch._dynamo.reset()
    g, v = torch.compile(
        vmap(grad_and_value(row)),
        backend=backend,
        fullgraph=True,
        dynamic=True,
    )(X.clone())
    print(backend, "max grad err:", (g - ref).abs().max().item())
    print("  ref[0]     =", ref[0].tolist())
    print("  compiled[0]=", g[0].tolist())
