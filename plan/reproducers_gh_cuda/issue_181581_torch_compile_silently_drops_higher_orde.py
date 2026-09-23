# source: https://github.com/pytorch/pytorch/issues/181581
# title: `torch.compile` silently drops higher-order grad graph metadata from `autograd.grad(create_graph=True)` outputs
# state: closed  created: 2026-04-27
# mined automatically; the harness records the torch.compile target and its first call

import torch

x = torch.randn(4, 8, device='cuda', requires_grad=True)
w = torch.randn(8, 8, device='cuda', requires_grad=True)

def f(x, w):
    y = torch.mm(x, w).sum()
    grad_x, = torch.autograd.grad(y, x, create_graph=True)
    return grad_x.sum()

# Eager: requires_grad=True, grad_fn=<SumBackward0>
r_eager = f(x, w)
print(r_eager.requires_grad)  # True 

# Compile: requires_grad=False, grad_fn=None
torch._dynamo.reset()
r_compile = torch.compile(f)(x.clone().detach().requires_grad_(True),
                              w.clone().detach().requires_grad_(True))
print(r_compile.requires_grad)  # False

# Consequence: higher-order backward fails later
r_compile.backward()
# RuntimeError: element 0 of tensors does not require grad and does not have a grad_fn
