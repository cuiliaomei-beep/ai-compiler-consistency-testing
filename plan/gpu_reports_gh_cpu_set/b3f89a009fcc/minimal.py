import torch
torch.manual_seed(0)

def f(x):
    return torch.rand_like(x)

args = (torch.randint(0, 4, (1,)),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
