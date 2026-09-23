import torch
torch.manual_seed(0)

def f(x):
    return torch.clamp(x, min=-3.4e39, max=3.4e39)

args = (torch.randn(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
