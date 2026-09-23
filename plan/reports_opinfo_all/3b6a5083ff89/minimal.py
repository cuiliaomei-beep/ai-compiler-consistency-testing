import torch
torch.manual_seed(0)

def opinfo_var_mean(*args):
    return torch.var_mean(*args)

args = (torch.randn(0),)

eager = opinfo_var_mean(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_var_mean, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
