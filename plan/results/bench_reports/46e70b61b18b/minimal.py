import torch
torch.manual_seed(0)

def index_chain(x):
    n = x.shape[0]
    i = n - 1
    y = x[i]
    return y * 2.0 + x[0]

args = (torch.randn(1, 4),)

eager = index_chain(*args)
torch._dynamo.reset()
compiled = torch.compile(index_chain, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
