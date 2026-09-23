import torch
torch.manual_seed(0)

def fn(x):
    x = m1(x)
    x = torch.log(torch.clamp(x, min=1e-6))
    x = torch.pow(x, 2)
    x = m2(x)
    return x.mean()

args = (torch.randn(12, 8, 5, 13).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
