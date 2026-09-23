import torch
torch.manual_seed(0)

def fn(x):
        y = x * 2.0
        y.detach_()
        z = y + 1.0
        return z, y.requires_grad

args = (torch.randn(4).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
