import torch
torch.manual_seed(0)

def string_mode(x, mode):
    if mode == "sum":
        return x.sum(dim=0)
    return x.mean(dim=0)

args = (torch.randn(8, 8), 'sum')

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 8), 'sum')
torch._dynamo.reset()
compiled = torch.compile(string_mode, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(string_mode, backend='inductor')(*args_b)
eager = string_mode(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
