import torch
torch.manual_seed(0)

def dtype_read(x):
    if x.dtype == torch.float16:
        return (x.float() * x.float()).sum(dim=-1).half()
    return (x * x).sum(dim=-1)

args = (torch.randn(16, 8).requires_grad_(True),)

eager = dtype_read(*args)
torch._dynamo.reset()
compiled = torch.compile(dtype_read, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
