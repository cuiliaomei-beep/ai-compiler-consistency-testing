import torch
torch.manual_seed(0)

def fn(src, idx):
    x = torch.zeros(1, 8, device="cuda").expand(4, -1)  # stride-0 in dim 0
    return x.index_add(0, idx, src)

args = (torch.randn(1, 8), torch.randint(0, 4, (1,)))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
