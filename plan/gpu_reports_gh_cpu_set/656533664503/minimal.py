import torch
torch.manual_seed(0)

def fn(x, target, weight):
    return F.cross_entropy(
        x,
        target,
        weight=weight,
        reduction="none",
    )

args = (torch.randn(3, 5), torch.randn(3, 5), torch.randn(5))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
