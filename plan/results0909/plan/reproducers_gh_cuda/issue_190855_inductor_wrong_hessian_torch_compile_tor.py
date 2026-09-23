# source: https://github.com/pytorch/pytorch/issues/190855
# title: [inductor] Wrong Hessian: `torch.compile(torch.func.hessian(f))` miscompiles the derivative of `torch.trace` — a constant is added to every Hessian entry
# state: open  created: 2026-07-23
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch.func import hessian

torch.set_default_dtype(torch.float64)

n = 3

def f(t):
    return torch.mean(1.0 / (t + torch.trace(t) * torch.eye(n, dtype=t.dtype)))

x = torch.tensor([[0.10, 0.20, 0.30],
                  [0.40, 0.50, 0.60],
                  [0.70, 0.80, 0.95]])

H_eager = hessian(f)(x).reshape(n * n, n * n)

H_ind = torch.compile(hessian(f))(x).reshape(n * n, n * n)
print("\neager    row 5:", [f"{v:+.6f}" for v in H_eager[5].tolist()])
print("inductor row 5:", [f"{v:+.6f}" for v in H_ind[5].tolist()])
print("diff     row 5:", [f"{v:+.6f}" for v in (H_ind - H_eager)[5].tolist()])
