import torch
torch.manual_seed(0)

def fn(x):
    return torch.ops.aten.upsample_bilinear2d(x, [16, 15], False, None, None)

args = (torch.randint(0, 4, (1, 1, 1,)).to(torch.int32),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
