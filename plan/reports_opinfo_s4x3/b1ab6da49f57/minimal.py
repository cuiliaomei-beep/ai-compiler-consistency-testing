import torch
torch.manual_seed(0)

def opinfo_var_mean_unbiased(*args):
    return torch.var_mean(*args, True)

args = (torch.randn(0, 1),)

eager = opinfo_var_mean_unbiased(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_var_mean_unbiased, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
