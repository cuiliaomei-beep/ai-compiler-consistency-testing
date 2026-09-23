import torch
torch.manual_seed(0)

def opinfo_cov(*args):
    return torch.cov(*args, **{'correction': 0, 'fweights': None, 'aweights': tensor([0.2598, 0.3666])})

args = (torch.randn(2),)

eager = opinfo_cov(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_cov, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
