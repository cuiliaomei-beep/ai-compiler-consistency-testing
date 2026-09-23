import torch
torch.manual_seed(0)

def exception_path(x):
    if x.shape[0] < 4:
        raise ValueError("need at least 4 rows")
    return x.sum(dim=0)

args = (torch.randn(3, 4),)

eager = exception_path(*args)
torch._dynamo.reset()
compiled = torch.compile(exception_path, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
