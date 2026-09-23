# source: https://github.com/pytorch/pytorch/issues/183018
# title: `torch.compile` + `torch._higher_order_ops.map`: Inductor generates invalid C++ wrapper code (CppCompileError)
# state: closed  created: 2026-05-09
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

torch.manual_seed(42)
xs = torch.randn(8, 64, device='cuda')  # no requires_grad

def body_fn(x):
    return F.gelu(x)

def fn(xs):
    return torch._higher_order_ops.map(body_fn, xs).sum()

# Eager — OK
print(fn(xs))

# Compiled — CRASH
torch._dynamo.reset()
fn_c = torch.compile(fn, fullgraph=True)
print(fn_c(xs))  # <-- CppCompileError
