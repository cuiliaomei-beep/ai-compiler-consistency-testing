import torch
torch.manual_seed(0)

def chunk_inplace(x):
    a, b = x.chunk(2, dim=0)
    a.mul_(3.0)
    return b + a.sum()

args = (torch.randn(8, 4),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 4),)
torch._dynamo.reset()
compiled = torch.compile(chunk_inplace, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(chunk_inplace, backend='inductor')(*args_b)
eager = chunk_inplace(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
