import torch
torch.manual_seed(0)

def f(x, index, src, out):
    return torch.scatter(x, 1, index, src, out=out)

args = (torch.randn(1, 2), torch.randint(0, 4, (1, 2,)), torch.randn(1, 2), torch.randn(1, 2))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
