import torch
torch.manual_seed(0)

def stride_read(x):
    if x.stride(0) == 1:
        return x.t().contiguous().sum(dim=0)
    return x.sum(dim=1)

args = (torch.randn(8, 8)  # NOTE: non-contiguous in the failing run,)

eager = stride_read(*args)
torch._dynamo.reset()
compiled = torch.compile(stride_read, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
