import torch
torch.manual_seed(0)

def f(x, idx):
    with torch.amp.autocast('cpu', dtype=torch.bfloat16):
        return x.index_select(0, idx)

args = (torch.randn(1), torch.randint(0, 4, (1,)))

eager = f(*args)
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
