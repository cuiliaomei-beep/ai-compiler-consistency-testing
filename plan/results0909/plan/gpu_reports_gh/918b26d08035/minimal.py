import torch
torch.manual_seed(0)

def fn(x, src):
    return torch.diagonal_scatter(x, src, 0).sum()

args = (torch.randn(1, 2).requires_grad_(True), torch.randn(1))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
