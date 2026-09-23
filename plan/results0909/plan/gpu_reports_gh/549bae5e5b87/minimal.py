import torch
torch.manual_seed(0)

def f():
    ones = torch.ones((2, 4, 4), dtype=torch.bool)
    return ones.cumsum(1, dtype=torch.bfloat16)

args = (...)  # see execution_trace.json

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
