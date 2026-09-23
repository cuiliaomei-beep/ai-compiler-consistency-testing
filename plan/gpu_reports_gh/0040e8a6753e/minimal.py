import torch
torch.manual_seed(0)

def fn(x):
    values = [x * 2, x * 3, x * 4]
    selected = values.pop(x.shape[0] - 2)
    return selected +values[0]

args = (torch.randn(3),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
