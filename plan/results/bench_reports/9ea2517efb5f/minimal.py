import torch
torch.manual_seed(0)

def scalar_compare(x, n):
    if n > 4:
        return x[:n].sum(dim=0)
    return x.sum(dim=0) * n

args = (torch.randn(16, 8), 4)

eager = scalar_compare(*args)
torch._dynamo.reset()
compiled = torch.compile(scalar_compare, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
