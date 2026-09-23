import torch
torch.manual_seed(0)

def f(x, w, b):
    y = (x @ w).to(torch.bfloat16) + b
    return y, y.mean(-1)

args = (torch.randn(2, 15, 32).to(torch.float64), torch.randn(32, 17).to(torch.float64), torch.randn(17).to(torch.float64))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
