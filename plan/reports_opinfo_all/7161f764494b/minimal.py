import torch
torch.manual_seed(0)

def opinfo_cov(*args):
    return torch.cov(*args, correction=1, fweights=None, aweights=torch.tensor([0.3666413426399231, 0.05830073356628418, 0.7006447315216064], dtype=torch.float32))

args = (torch.randn(2, 3),)

eager = opinfo_cov(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_cov, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
