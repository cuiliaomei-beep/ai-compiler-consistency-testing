import torch
torch.manual_seed(0)

def contiguous_read(x):
    if x.is_contiguous():
        return x.view(-1).sum()
    return x.reshape(-1).sum()

args = (torch.randn(8, 8)  # NOTE: non-contiguous in the failing run,)

eager = contiguous_read(*args)
torch._dynamo.reset()
compiled = torch.compile(contiguous_read, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
