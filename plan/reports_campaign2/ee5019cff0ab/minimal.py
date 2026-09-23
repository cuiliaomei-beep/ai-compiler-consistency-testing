import torch
torch.manual_seed(0)

def reshape_dim(x, k):
    return x.reshape(k, -1).sum(dim=1)

args = (torch.randn(8, 8), 4)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 8), 4)
torch._dynamo.reset()
compiled = torch.compile(reshape_dim, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(reshape_dim, backend='inductor')(*args_b)
eager = reshape_dim(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
