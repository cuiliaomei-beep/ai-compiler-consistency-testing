import torch
torch.manual_seed(0)

def fn():
    return torch.empty_like(torch.randn(4, 4))

args = (...)  # see execution_trace.json

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
