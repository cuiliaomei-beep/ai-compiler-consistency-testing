import torch
torch.manual_seed(0)

f = lambda x: torch.repeat_interleave((x + 1).flatten(), 2).flip(0)

args = (torch.randn(2, 2),)

eager = <lambda>(*args)
torch._dynamo.reset()
compiled = torch.compile(<lambda>, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
