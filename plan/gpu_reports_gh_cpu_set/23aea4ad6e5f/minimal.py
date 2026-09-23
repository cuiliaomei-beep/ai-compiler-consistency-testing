import torch
torch.manual_seed(0)

def f(x):
    v1 = torch.full([1, 2], 1, dtype=torch.float32)                    # storage: 2 elements
    v2 = torch.as_strided(v1, size=[64, 64, 3], stride=[1, 64, 192])   # addresses 4480
    return torch.cumsum(v2, 1)

args = (torch.randn(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
