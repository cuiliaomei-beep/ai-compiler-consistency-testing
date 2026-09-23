import torch
torch.manual_seed(0)

def alias_returned(x):
    y = x.transpose(0, 1)
    return y

args = (torch.randn(4, 6),)

eager = alias_returned(*args)
torch._dynamo.reset()
compiled = torch.compile(alias_returned, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
