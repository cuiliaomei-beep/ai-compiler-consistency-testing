import torch
torch.manual_seed(0)

def index_chain(x):
    n = x.shape[0]
    i = n - 1
    y = x[i]
    return y * 2.0 + x[0]

args = (torch.randn(8, 4),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 4),)
torch._dynamo.reset()
compiled = torch.compile(index_chain, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(index_chain, backend='inductor')(*args_b)
eager = index_chain(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
