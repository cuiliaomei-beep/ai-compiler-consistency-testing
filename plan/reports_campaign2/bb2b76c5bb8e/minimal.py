import torch
torch.manual_seed(0)

def overlapping_views(x):
    a = x[:6]
    b = x[4:]
    a.mul_(2.0)
    b.add_(1.0)
    return x, a, b

args = (torch.randn(10),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(10),)
torch._dynamo.reset()
compiled = torch.compile(overlapping_views, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(overlapping_views, backend='inductor')(*args_b)
eager = overlapping_views(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
