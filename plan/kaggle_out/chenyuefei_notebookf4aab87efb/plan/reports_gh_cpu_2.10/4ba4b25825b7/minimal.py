import torch
torch.manual_seed(0)

def f_bug(x):
    y = -x.abs()
    return torch.cat([y, y]).sum()

args = (torch.randint(0, 4, (1,)).to(torch.uint8),)

eager = f_bug(*args)
torch._dynamo.reset()
compiled = torch.compile(f_bug, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
