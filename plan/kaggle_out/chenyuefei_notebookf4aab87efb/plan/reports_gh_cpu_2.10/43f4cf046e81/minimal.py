import torch
torch.manual_seed(0)

def fn(x):
    return torch.acosh(x)

args = (torch.randn(2),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
