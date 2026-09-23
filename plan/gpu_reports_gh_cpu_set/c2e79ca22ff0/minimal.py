import torch
torch.manual_seed(0)

def fn(left, right):
    return F.smooth_l1_loss(left, right, beta=-1.0)

args = (torch.randn(1), torch.randn(1))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
