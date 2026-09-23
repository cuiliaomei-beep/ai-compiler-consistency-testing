import torch
torch.manual_seed(0)

def fn(x):
    y = x.to(torch.float16)
    return (y * y).to(torch.float32)

args = (torch.randn(1),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
