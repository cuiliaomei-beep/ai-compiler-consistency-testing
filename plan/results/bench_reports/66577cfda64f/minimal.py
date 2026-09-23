import torch
torch.manual_seed(0)

def requires_grad_switch(x):
    y = (x * 3.0).relu()
    return y.sum()

args = (torch.randn(16, 8),)

# context A then context B on the same compiled callable (no reset)
# A = {'requires_grad': {'arg': 0, 'value': False}}
# B = {} (base)
args_b = (torch.randn(16, 8).requires_grad_(True),)
torch._dynamo.reset()
compiled = torch.compile(requires_grad_switch, backend='eager')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(requires_grad_switch, backend='eager')(*args_b)
eager = requires_grad_switch(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
