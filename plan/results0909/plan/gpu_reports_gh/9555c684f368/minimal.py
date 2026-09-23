import torch
torch.manual_seed(0)

def f(offsets, values):
    return torch.searchsorted(offsets[1:], values, right=True)

args = (torch.randint(0, 4, (2,)), torch.randint(0, 4, (6,)))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
