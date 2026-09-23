import torch
torch.manual_seed(0)

def none_check(x, bias=None):
    if bias is None:
        return x * 2.0
    return x * 2.0 + bias

args = (torch.randn(8, 8), None)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(8, 8), None)
torch._dynamo.reset()
compiled = torch.compile(none_check, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(none_check, backend='inductor')(*args_b)
eager = none_check(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
