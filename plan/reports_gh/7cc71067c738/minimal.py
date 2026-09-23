import torch
torch.manual_seed(0)

def fn(x):
    return sum(gn(layer, x) for layer in layers)

args = (torch.randn(4).to(torch.float64).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
