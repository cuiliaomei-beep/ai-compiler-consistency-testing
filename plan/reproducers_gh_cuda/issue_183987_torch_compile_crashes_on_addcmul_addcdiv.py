# source: https://github.com/pytorch/pytorch/issues/183987
# title: `torch.compile` crashes on `addcmul_`/`addcdiv_` backward — missing autograd formula for `prims.fma`
# state: closed  created: 2026-05-16
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x, t1, t2):
    y = x.clone()
    y.addcmul_(t1, t2, value=0.5)
    return y.sum()

x = torch.randn(4, 4, device="cuda", requires_grad=True)
t1 = torch.randn(4, 4, device="cuda", requires_grad=True)
t2 = torch.randn(4, 4, device="cuda", requires_grad=True)

# Eager: OK
fn(x, t1, t2).backward()
print("Eager OK")

# Compiled: CRASH
torch._dynamo.reset()
torch.compile(fn)(x, t1, t2).backward()
# RuntimeError: Trying to backward through prims.fma.default
# but no autograd formula was registered.
