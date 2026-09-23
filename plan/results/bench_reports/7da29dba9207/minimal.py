import torch
torch.manual_seed(0)

def dtype_reduce(x):
    return (x * x).sum(dim=-1) / (x.abs().mean(dim=-1) + 1e-6)

args = (torch.randn(64, 128),)

eager = dtype_reduce(*args)
torch._dynamo.reset()
compiled = torch.compile(dtype_reduce, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
