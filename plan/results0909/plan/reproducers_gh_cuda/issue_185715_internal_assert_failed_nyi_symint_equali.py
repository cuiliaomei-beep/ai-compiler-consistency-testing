# source: https://github.com/pytorch/pytorch/issues/185715
# title: INTERNAL ASSERT FAILED: NYI SymInt equality in c10/core/Scalar.h when using torch.compile(dynamic=True) and torch.autograd.grad with torch.pow
# state: closed  created: 2026-05-30
# mined automatically; the harness records the torch.compile target and its first call

import torch
import traceback

print("torch", torch.__version__)
torch._dynamo.config.suppress_errors = False

def fn(x, exponent):
    y = torch.pow(x, exponent)
    loss = y.sum()
    grad, = torch.autograd.grad(loss, x)
    return y, grad

x = torch.ones((1, 3), device="cuda", dtype=torch.bfloat16, requires_grad=True)
exponent = 0  

print("\n=== eager ===")
y, g = fn(x, exponent)
print("y:", y)
print("grad:", g)

for backend in ["aot_eager", "inductor"]:
    print(f"\n=== torch.compile backend={backend}, dynamic=True ===")
    compiled_fn = torch.compile(fn, backend=backend, dynamic=True)

    x = torch.ones((1, 3), device="cuda", dtype=torch.bfloat16, requires_grad=True)

    try:
        y, g = compiled_fn(x, exponent)
        print("y:", y)
        print("grad:", g)
    except Exception:
        traceback.print_exc()
