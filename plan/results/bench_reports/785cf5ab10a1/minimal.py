import torch
torch.manual_seed(0)

def chunk_inplace(x):
    a, b = x.chunk(2, dim=0)
    a.mul_(3.0)
    return b + a.sum()

args = (torch.randn(8, 4),)

eager = chunk_inplace(*args)
torch._dynamo.reset()
compiled = torch.compile(chunk_inplace, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
