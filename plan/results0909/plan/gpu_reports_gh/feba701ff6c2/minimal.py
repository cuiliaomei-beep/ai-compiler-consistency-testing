import torch
torch.manual_seed(0)

compiled_fn = torch.compile(lambda x: F.multilabel_margin_loss(x, target))

args = (torch.randn(1, 5),)

eager = <lambda>(*args)
torch._dynamo.reset()
compiled = torch.compile(<lambda>, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
