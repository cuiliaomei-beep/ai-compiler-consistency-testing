import torch
torch.manual_seed(0)

def opinfo_std_mean_unbiased_397(*args):
    return torch.std_mean(*args, True)

args = (torch.randn(0, 1),)

eager = opinfo_std_mean_unbiased_397(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_std_mean_unbiased_397, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
