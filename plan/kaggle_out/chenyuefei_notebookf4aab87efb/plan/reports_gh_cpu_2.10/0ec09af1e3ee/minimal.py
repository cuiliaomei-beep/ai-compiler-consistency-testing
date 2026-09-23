import torch
torch.manual_seed(0)

def f(x):
    return torch.full((2,), x.item(), dtype=torch.bool).sum()

args = (torch.tensor(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
