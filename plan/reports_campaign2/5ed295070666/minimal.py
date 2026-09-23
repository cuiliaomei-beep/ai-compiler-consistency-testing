import torch
torch.manual_seed(0)

def dtype_reduce(x):
    return (x * x).sum(dim=-1) / (x.abs().mean(dim=-1) + 1e-6)

args = (torch.randn(64, 128),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(64, 128),)
torch._dynamo.reset()
compiled = torch.compile(dtype_reduce, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(dtype_reduce, backend='inductor')(*args_b)
eager = dtype_reduce(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
