import torch
torch.manual_seed(0)

def opinfo_nn_functional_soft_margin_loss(*args):
    return torch.nn.functional.soft_margin_loss(*args, reduction='mean')

args = (torch.randn(1).to(torch.float16), torch.randn(1).to(torch.float16))

eager = opinfo_nn_functional_soft_margin_loss(*args)
torch._dynamo.reset()
compiled = torch.compile(opinfo_nn_functional_soft_margin_loss, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
