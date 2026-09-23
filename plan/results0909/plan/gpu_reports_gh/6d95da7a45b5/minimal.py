import torch
torch.manual_seed(0)



args = (torch.randn(1), torch.randn(1))

eager = remainder(*args)
torch._dynamo.reset()
compiled = torch.compile(remainder, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
