import torch
torch.manual_seed(0)

def f(x, c):
    z = torch.where(c, torch.full_like(x, 0.5), torch.full_like(x, -0.5))
    y = z.to(torch.float16) + x.to(torch.float16)
    return y, y.float().sum()

args = (torch.randn(2).requires_grad_(True), torch.randint(0, 4, (2,)).to(torch.bool))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
