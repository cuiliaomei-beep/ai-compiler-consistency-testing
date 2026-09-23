import torch
torch.manual_seed(0)

def python_flag_semantic(x, use_relu):
    if use_relu:
        return x.relu().sum(dim=-1)
    return x.tanh().sum(dim=-1)

args = (torch.randn(16, 8).requires_grad_(True), True)

eager = python_flag_semantic(*args)
torch._dynamo.reset()
compiled = torch.compile(python_flag_semantic, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
