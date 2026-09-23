import torch
torch.manual_seed(0)

def alias_returned(x):
    y = x.transpose(0, 1)
    return y

args = (torch.randn(4, 6),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(4, 6),)
torch._dynamo.reset()
compiled = torch.compile(alias_returned, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(alias_returned, backend='inductor')(*args_b)
eager = alias_returned(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
