import torch
torch.manual_seed(0)

def f(x1, x2):

    x1.mul_(2)

    return x1 + x2

args = (torch.randn(2).to(torch.float16), torch.randn(2).to(torch.float16))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
