import torch
torch.manual_seed(0)



args = (torch.randn(1), torch.randn(1))

eager = add(*args)
torch._dynamo.reset()
compiled = torch.compile(add, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
