import torch
torch.manual_seed(0)

def loss(x):
    return SinWithZeroBackward.apply(x).sum()

args = (torch.randn(4).to(torch.float64).requires_grad_(True),)

eager = loss(*args)
torch._dynamo.reset()
compiled = torch.compile(loss, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
