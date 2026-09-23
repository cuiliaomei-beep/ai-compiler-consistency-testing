import torch
torch.manual_seed(0)

def opinfo_cov_252(*args):
    return torch.cov(*args, correction=1, fweights=None, aweights=torch.tensor([0.25984418392181396, 0.3666413426399231], dtype=torch.float32))

args = (torch.randn(3, 2),)

eager = opinfo_cov_252(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_cov_252, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
