import torch
torch.manual_seed(0)

def f(x, dx):
    return torch.func.jvp(SinWithZeroJvp.apply, (x,), (dx,))[1]

args = (torch.randn(4).to(torch.float64).requires_grad_(True), torch.randn(4).to(torch.float64))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
