import torch
torch.manual_seed(0)

def flag_and_shape(x, flag):
    if flag and x.shape[0] > 32:
        return x[:32].sum(dim=0) * 2.0
    return x.sum(dim=0)

args = (torch.randn(32, 8), True)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'substitute': {'arg': 1, 'value': True}}
args_b = (torch.randn(32, 8), True)
torch._dynamo.reset()
compiled = torch.compile(flag_and_shape, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(flag_and_shape, backend='inductor')(*args_b)
eager = flag_and_shape(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
