import torch
torch.manual_seed(0)

def overlapping_views(x):
    a = x[:6]
    b = x[4:]
    a.mul_(2.0)
    b.add_(1.0)
    return x, a, b

args = (torch.randn(10),)

eager = overlapping_views(*args)
torch._dynamo.reset()
compiled = torch.compile(overlapping_views, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
