import torch
torch.manual_seed(0)

def fn(x):
    return x.max(1, keepdim=True)[1]

args = (torch.randint(0, 4, (1, 8, 4,)).to(torch.bool),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
