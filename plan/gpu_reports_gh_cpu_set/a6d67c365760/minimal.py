import torch
torch.manual_seed(0)

def fn():
    torch.manual_seed(0)
    out = torch.randint(0, 100, (4,1), dtype=torch.int64)  # Shape and integer range are not important.
    other = torch.randint(0, 100, (2,1), dtype=torch.int64) # No inconsistency if remove this line, although the value won't be returned.
    return out

args = (...)  # see execution_trace.json

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
