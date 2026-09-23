import torch
torch.manual_seed(0)

def requires_grad_switch(x):
    y = (x * 3.0).relu()
    return y.sum()

args = (torch.randn(16, 8).requires_grad_(True),)

eager = requires_grad_switch(*args)
torch._dynamo.reset()
compiled = torch.compile(requires_grad_switch, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
