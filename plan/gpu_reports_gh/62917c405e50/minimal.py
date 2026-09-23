import torch
torch.manual_seed(0)

def model(x):
    return torch.func.grad(loss)(x)

args = (torch.randn(4).to(torch.float16),)

eager = model(*args)
torch._dynamo.reset()
compiled = torch.compile(model, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
