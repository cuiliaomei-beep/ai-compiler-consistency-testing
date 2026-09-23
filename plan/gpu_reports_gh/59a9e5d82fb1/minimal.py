import torch
torch.manual_seed(0)

def f(x, idx):
    res = torch.zeros(1, x.shape[1], device=x.device, dtype=x.dtype)
    res.scatter_add_(0, idx.unsqueeze(-1).expand(-1, x.shape[1]), x)
    return torch.index_select(res, 0, idx)

args = (torch.randn(2, 1), torch.randint(0, 4, (2,)))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
