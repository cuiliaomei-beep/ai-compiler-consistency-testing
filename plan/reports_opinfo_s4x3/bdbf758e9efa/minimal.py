import torch
torch.manual_seed(0)

def opinfo_cov(*args):
    return torch.cov(*args, correction=0, fweights=torch.tensor([7, 4], dtype=torch.int32), aweights=torch.tensor([0.25984418392181396, 0.3666413426399231], dtype=torch.float32))

args = (torch.randn(1, 2),)

eager = opinfo_cov(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_cov, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
