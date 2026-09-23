import torch
torch.manual_seed(0)

def f(inp, m1, m2):
    return torch.addmm(inp, m1, m2)

args = (torch.randn(7, 1), torch.randn(1, 1), torch.randn(1, 1))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
