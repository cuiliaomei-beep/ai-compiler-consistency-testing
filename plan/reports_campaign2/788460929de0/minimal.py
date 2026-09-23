import torch
torch.manual_seed(0)

def dtype_read(x):
    if x.dtype == torch.float16:
        return (x.float() * x.float()).sum(dim=-1).half()
    return (x * x).sum(dim=-1)

args = (torch.randn(16, 8),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(16, 8),)
torch._dynamo.reset()
compiled = torch.compile(dtype_read, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(dtype_read, backend='inductor')(*args_b)
eager = dtype_read(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
