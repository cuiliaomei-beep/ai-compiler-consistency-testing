import torch
torch.manual_seed(0)

lambda x: torch.nn.functional.fractional_max_pool2d(
    x, 3, output_size=(4, 4), return_indices=True),

args = (torch.randn(1, 8, 8),)

eager = <lambda>(*args)
torch._dynamo.reset()
compiled = torch.compile(<lambda>, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
