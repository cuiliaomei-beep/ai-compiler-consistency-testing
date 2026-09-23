import torch
torch.manual_seed(0)

def opinfo_var_mean_unbiased_390(*args):
    return torch.var_mean(*args, False)

args = (torch.randn(0).to(torch.float16),)

eager = opinfo_var_mean_unbiased_390(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_var_mean_unbiased_390, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
