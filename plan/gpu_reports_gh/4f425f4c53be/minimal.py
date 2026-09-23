import torch
torch.manual_seed(0)

def f(x, y):
    return torch.slice_scatter(x, y, dim=0, start=0, end=2).sum()

args = (torch.randn(5).requires_grad_(True), torch.randn(2))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
