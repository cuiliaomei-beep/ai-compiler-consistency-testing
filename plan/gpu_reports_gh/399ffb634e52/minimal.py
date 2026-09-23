import torch
torch.manual_seed(0)

def fn(x):
    y = torch.quantile(x, 0.0, dim=1, keepdim=True)
    return torch.nan_to_num(y, nan=0.0).sum()

args = (torch.randn(2, 3).to(torch.float64).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
