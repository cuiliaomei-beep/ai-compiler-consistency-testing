# source: https://github.com/pytorch/pytorch/issues/190758
# title: Memory-budget partitioner recomputes RNG ops with fresh randomness in backward, silently corrupting gradients at any activation_memory_budget < 1.0
# state: open  created: 2026-07-22
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F
import torch._functorch.config as fc

fc.activation_memory_budget = 0.0  # also broken at 0.005 and 0.5

w = torch.arange(1.0, 26.0).view(5, 5)

def f(x):
    return F.dropout(x @ w, 0.5, True)

compiled = torch.compile(f)
torch.manual_seed(42)
x = torch.ones(2, 5, requires_grad=True)
out = compiled(x)
out.sum().backward()

mask = (out.detach() != 0).float()   # the mask the forward actually applied
expected = 2.0 * mask @ w.t()        # gradient implied by that mask
print(torch.equal(x.grad, expected)) # main: False — the backward redrew the mask
