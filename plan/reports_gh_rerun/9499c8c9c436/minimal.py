import torch
torch.manual_seed(0)

def f(x):
    return 1 - (x < 0)

args = (torch.randn(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
