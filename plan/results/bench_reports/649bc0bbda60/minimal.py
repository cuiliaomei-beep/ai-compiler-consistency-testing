import torch
torch.manual_seed(0)

def view_inplace(x):
    y = x.view(-1)
    y[0] = y[0] + 1.0
    return x

args = (torch.randn(8, 8),)

eager = view_inplace(*args)
torch._dynamo.reset()
compiled = torch.compile(view_inplace, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
