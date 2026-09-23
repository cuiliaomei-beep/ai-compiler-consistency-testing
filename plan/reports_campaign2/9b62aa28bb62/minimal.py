import torch
torch.manual_seed(0)

def mod_tiling(x):
    n = x.shape[0]
    if n % 16 == 0:
        return x.reshape(n // 16, 16, -1).sum(dim=1)
    pad = 16 - n % 16
    y = torch.cat([x, x[:pad]], dim=0)
    return y.reshape(-1, 16, x.shape[1]).sum(dim=1)

args = (torch.randn(32, 8),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(32, 8),)
torch._dynamo.reset()
compiled = torch.compile(mod_tiling, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(mod_tiling, backend='inductor')(*args_b)
eager = mod_tiling(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
