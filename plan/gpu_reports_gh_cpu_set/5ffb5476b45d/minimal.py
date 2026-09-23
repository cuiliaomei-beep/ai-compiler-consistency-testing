import torch
torch.manual_seed(0)

def fn():
    x = torch.ones([4, 5, 6, 6])
    t = bn(x)
    t = elu(t)
    t = gn(t)
    return torch.log(torch.clamp(t, min=1e-6))

args = (...)  # see execution_trace.json

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
