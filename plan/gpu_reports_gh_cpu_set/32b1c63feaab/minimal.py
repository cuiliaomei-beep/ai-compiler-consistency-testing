import torch
torch.manual_seed(0)



args = (torch.randn(2), torch.randn(2))

eager = add(*args)
torch._dynamo.reset()
compiled = torch.compile(add, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
