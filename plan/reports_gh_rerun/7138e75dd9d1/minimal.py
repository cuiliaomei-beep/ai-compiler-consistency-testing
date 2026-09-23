import torch
torch.manual_seed(0)

def fn(t):
    return torch.nn.functional.binary_cross_entropy(torch.ones_like(t), t)

args = (torch.randn(1),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
