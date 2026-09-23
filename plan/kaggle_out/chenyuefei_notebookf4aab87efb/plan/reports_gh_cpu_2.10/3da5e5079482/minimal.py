import torch
torch.manual_seed(0)

def fn(x):
    return torch.sinh(x)

args = (torch.randn(4).to(torch.bfloat16),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
