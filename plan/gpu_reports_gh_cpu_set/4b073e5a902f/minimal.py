import torch
torch.manual_seed(0)

def fn(scores, values):
    mask = scores > 0.0
    idx = torch.argmax(mask, dim=1)
    return values[idx].sum()

args = (...)  # see execution_trace.json

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
