import torch
torch.manual_seed(0)

def fn(x):
    return torch.signbit(x)

args = (torch.randn(3).to(torch.float64),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
