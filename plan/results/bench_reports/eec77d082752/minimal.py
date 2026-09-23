import torch
torch.manual_seed(0)

def shape_boundary(x):
    if x.shape[0] >= 32:
        return (x * 2.0).sum(dim=0)
    return (x + 1.0).sum(dim=0)

args = (torch.randn(32, 16).to(torch.float16),)

eager = shape_boundary(*args)
torch._dynamo.reset()
compiled = torch.compile(shape_boundary, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
