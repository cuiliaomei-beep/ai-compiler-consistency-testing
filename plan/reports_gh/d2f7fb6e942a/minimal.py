import torch
torch.manual_seed(0)

def fn(loc, scale):
    d = torch.distributions.Normal(loc, scale)
    return d.sample()

args = (torch.randn(1).to(torch.float16).requires_grad_(True), torch.randn(1).to(torch.float64))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
