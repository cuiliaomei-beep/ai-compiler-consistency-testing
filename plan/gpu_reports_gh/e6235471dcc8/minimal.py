import torch
torch.manual_seed(0)

def fn(x):
    return sum(outer(l, x) for l in layers)

args = (torch.randn(8).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
