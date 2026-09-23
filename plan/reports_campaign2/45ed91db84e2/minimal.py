import torch
torch.manual_seed(0)

def exception_path(x):
    if x.shape[0] < 4:
        raise ValueError("need at least 4 rows")
    return x.sum(dim=0)

args = (torch.randn(8, 4),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 4),)
torch._dynamo.reset()
compiled = torch.compile(exception_path, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(exception_path, backend='inductor')(*args_b)
eager = exception_path(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
