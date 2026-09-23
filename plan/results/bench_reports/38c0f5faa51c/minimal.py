import torch
torch.manual_seed(0)

def noncontig_copy(x, w):
    z = x[:, ::2]
    z.copy_(w)
    return x

args = (torch.randn(8, 16), torch.randn(8, 8))

eager = noncontig_copy(*args)
torch._dynamo.reset()
compiled = torch.compile(noncontig_copy, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
