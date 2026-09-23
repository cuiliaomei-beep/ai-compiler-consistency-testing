import torch
torch.manual_seed(0)

def f(x):
    x = x.clone()
    return x.t().argmax()

args = (torch.randn(5, 3),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
