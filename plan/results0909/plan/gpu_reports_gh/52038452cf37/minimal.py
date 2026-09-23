import torch
torch.manual_seed(0)

def fn(x):
    y = F.logsigmoid(x)
    return y, torch.signbit(y), y == 0, torch.copysign(torch.ones_like(y), y)

args = (torch.randn(6),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
