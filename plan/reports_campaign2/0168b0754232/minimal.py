import torch
torch.manual_seed(0)

def gather_shape(x):
    n = x.shape[0]
    idx = torch.arange(n - 1, device=x.device)
    return x.index_select(0, idx).sum(dim=0)

args = (torch.randn(8, 4),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 4),)
torch._dynamo.reset()
compiled = torch.compile(gather_shape, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(gather_shape, backend='inductor')(*args_b)
eager = gather_shape(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
