import torch
torch.manual_seed(0)

def f(t):
    return torch.mean(1.0 / (t + torch.trace(t) * torch.eye(n, dtype=t.dtype)))

args = (torch.randn(3, 3).to(torch.float64),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
