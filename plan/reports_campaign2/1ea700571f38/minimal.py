import torch
torch.manual_seed(0)

def python_flag(x, fast):
    if fast:
        return x.sum(dim=0) * 0.5
    return (x * 0.5).sum(dim=0)

args = (torch.randn(16, 8), True)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(16, 8), True)
torch._dynamo.reset()
compiled = torch.compile(python_flag, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(python_flag, backend='inductor')(*args_b)
eager = python_flag(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
