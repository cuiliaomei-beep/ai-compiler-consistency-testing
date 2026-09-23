import torch
torch.manual_seed(0)

def opinfo_std_mean_unbiased(*args):
    return torch.std_mean(*args, False)

args = (torch.randn(0).to(torch.float16),)

eager = opinfo_std_mean_unbiased(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_std_mean_unbiased, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
