import torch
torch.manual_seed(0)

def fn(x, y):
    x.div_(y)
    z = torch.nn.functional.softmax(x, dim=-1)
    return z, x.detach()

args = (torch.randn(2, 4, 2, 4).to(torch.float16), torch.randn(4, 1, 1).to(torch.float16))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
