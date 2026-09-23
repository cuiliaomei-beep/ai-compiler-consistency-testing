import torch
torch.manual_seed(0)

def conditional_mutation(x):
    if x.shape[0] > 8:
        x.add_(1.0)
    return x

args = (torch.randn(16, 4),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'requires_grad': {'arg': 0, 'value': False}}
args_b = (torch.randn(16, 4),)
torch._dynamo.reset()
compiled = torch.compile(conditional_mutation, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(conditional_mutation, backend='inductor')(*args_b)
eager = conditional_mutation(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
