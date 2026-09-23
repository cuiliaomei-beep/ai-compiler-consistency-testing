import torch
torch.manual_seed(0)

def f(x):
    with torch.autocast(x.device.type, dtype=torch.bfloat16):
        return model(x)

args = (torch.randn(1, 3, 4, 64).requires_grad_(True),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
