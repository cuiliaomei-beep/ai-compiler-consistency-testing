import torch
torch.manual_seed(0)

def python_flag_semantic(x, use_relu):
    if use_relu:
        return x.relu().sum(dim=-1)
    return x.tanh().sum(dim=-1)

args = (torch.randn(16, 8), True)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'substitute': {'arg': 1, 'value': True}}
args_b = (torch.randn(16, 8), True)
torch._dynamo.reset()
compiled = torch.compile(python_flag_semantic, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(python_flag_semantic, backend='inductor')(*args_b)
eager = python_flag_semantic(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
