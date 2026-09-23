import torch
torch.manual_seed(0)

def mask_index(x):
    m = x > 0
    return x[m].sum()

args = (torch.randn(8, 8),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 8),)
torch._dynamo.reset()
compiled = torch.compile(mask_index, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(mask_index, backend='inductor')(*args_b)
eager = mask_index(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
