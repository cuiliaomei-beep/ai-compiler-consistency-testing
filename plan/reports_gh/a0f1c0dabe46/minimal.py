import torch
torch.manual_seed(0)

def fn(x):
    return sum(outer(l, x) for l in layers)

args = (torch.randn(8).to(torch.float64),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
