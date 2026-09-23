# source: https://github.com/pytorch/pytorch/issues/185543
# title: [inductor] Gradient mismatch between eager and inductor for torch.quantile on tied values
# state: closed  created: 2026-05-28
# mined automatically; the harness records the torch.compile target and its first call

import torch

assert torch.cuda.is_available()

print("torch:", torch.__version__)
print("cuda:", torch.version.cuda)

def fn(x):
    y = torch.quantile(x, 0.0, dim=1, keepdim=True)
    return torch.nan_to_num(y, nan=0.0).sum()

def run(f, x0):
    x = x0.detach().clone().requires_grad_(True)
    loss = f(x)
    grad, = torch.autograd.grad(loss, x)
    torch.cuda.synchronize()
    return loss.detach(), grad.detach()

x = torch.tensor(
    [
        [float("nan"), float("nan"), float("nan")],
        [0.0, 0.0, 0.0],
    ],
    device="cuda",
    dtype=torch.float64,
)

compiled_fn = torch.compile(fn, backend="inductor", fullgraph=True)

loss_eager, grad_eager = run(fn, x)
loss_inductor, grad_inductor = run(compiled_fn, x)

print("\ninput:")
print(x)

print("\neager loss:")
print(loss_eager)
print("inductor loss:")
print(loss_inductor)
print("loss equal:", torch.equal(loss_eager, loss_inductor))

print("\neager grad:")
print(grad_eager)

print("\ninductor grad:")
print(grad_inductor)

print("\ngrad equal:", torch.equal(grad_eager, grad_inductor))
print("eager nonzero mask:")
print((grad_eager != 0).cpu().tolist())
print("inductor nonzero mask:")
print((grad_inductor != 0).cpu().tolist())

assert torch.equal(loss_eager, loss_inductor)
assert not torch.equal(grad_eager, grad_inductor)
