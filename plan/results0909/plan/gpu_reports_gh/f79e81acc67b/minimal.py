import torch
torch.manual_seed(0)

def fn(x):
    mask = x == 1
    return mask.max(dim=1, keepdim=True)

args = (torch.randint(0, 4, (1, 8,)),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
