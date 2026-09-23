import torch
torch.manual_seed(0)

def fn(v, o):
    nt = torch.nested.nested_tensor_from_jagged(v, o)
    return F.layer_norm(nt, [8]).values().sum()

args = (torch.randn(15, 8), torch.randint(0, 4, (4,)))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
