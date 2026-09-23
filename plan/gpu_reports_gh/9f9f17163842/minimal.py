import torch
torch.manual_seed(0)

def row(x):
    return f(x).reshape(())

args = (torch.randn(4, 4).to(torch.float64),)

eager = row(*args)
torch._dynamo.reset()
compiled = torch.compile(row, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
