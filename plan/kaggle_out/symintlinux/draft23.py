import math
import torch

torch._dynamo.config.capture_scalar_outputs = True

def step(loss, param):
    v = loss.item()
    if v != v:                      # standard NaN check: skip the update
        return param
    return param - 0.1 * v

def step_isnan(loss, param):
    v = loss.item()
    if math.isnan(v):
        return param
    return param - 0.1 * v

param, nan = torch.ones(2), torch.tensor(float("nan"))
for name, fn in (("v != v", step), ("math.isnan(v)", step_isnan)):
    print(f"{name:14s} eager {fn(nan, param).tolist()}", end="")
    for backend in ("eager", "aot_eager", "inductor"):
        torch._dynamo.reset()
        print(f"   {backend} {torch.compile(fn, backend=backend)(nan, param).tolist()}", end="")
    print()

sub = lambda t: t.item() - t.item()
torch._dynamo.reset()
print("v - v for v = inf:  eager", sub(torch.tensor(float("inf"))), "  inductor", torch.compile(sub)(torch.tensor(float("inf"))))
