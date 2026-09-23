import torch
torch.manual_seed(0)

def shape_boundary(x):
    if x.shape[0] >= 32:
        return (x * 2.0).sum(dim=0)
    return (x + 1.0).sum(dim=0)

args = (torch.randn(32, 16),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(32, 16),)
torch._dynamo.reset()
compiled = torch.compile(shape_boundary, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(shape_boundary, backend='inductor')(*args_b)
eager = shape_boundary(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
