import torch
torch.manual_seed(0)

def f(x):
    num = x.nonzero().numel()
    num = x.new_tensor([num]).item()
    y = w * x
    return y.sum() / num

args = (torch.randn(1),)

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
