import torch
torch.manual_seed(0)

def fn(x):
    return torch.quantile(x, 0.5)

args = (torch.randn(5),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
