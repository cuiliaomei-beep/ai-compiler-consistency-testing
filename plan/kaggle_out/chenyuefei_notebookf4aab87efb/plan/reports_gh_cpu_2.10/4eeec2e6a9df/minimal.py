import torch
torch.manual_seed(0)

def f(x):
    return F.dropout(x @ w, 0.5, True)

args = (torch.randn(5),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
