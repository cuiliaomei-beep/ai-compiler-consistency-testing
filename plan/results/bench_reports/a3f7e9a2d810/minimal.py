import torch
torch.manual_seed(0)

def conditional_mutation(x):
    if x.shape[0] > 8:
        x.add_(1.0)
    return x

args = (torch.randn(16, 4),)

eager = conditional_mutation(*args)
torch._dynamo.reset()
compiled = torch.compile(conditional_mutation, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
