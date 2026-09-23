import torch
torch.manual_seed(0)

def fn(x, w):
    x = torch.matmul(x, w)
    x = x.to(torch.bfloat16).float()  # intentional precision truncation
    x = x * torch.sigmoid(x)
    return x.sum(dim=1)

args = (torch.randn(4, 4, 32).requires_grad_(True), torch.randn(32, 4))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
