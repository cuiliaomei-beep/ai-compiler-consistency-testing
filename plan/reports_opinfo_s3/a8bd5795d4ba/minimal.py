import torch
torch.manual_seed(0)

def opinfo_new_empty(*args):
    return torch.new_empty(*args, (10,), dtype=torch.float64)

args = (torch.randn(5),)

eager = opinfo_new_empty(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_new_empty, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
