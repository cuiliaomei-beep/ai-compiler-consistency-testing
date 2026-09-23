import torch
torch.manual_seed(0)

def loop_bound(x, n):
    for _ in range(n):
        x = x * 1.5 + 1.0
    return x

args = (torch.randn(8, 4), 3)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'substitute': {'arg': 1, 'value': 0}}
args_b = (torch.randn(8, 4), 0)
torch._dynamo.reset()
compiled = torch.compile(loop_bound, backend='eager')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(loop_bound, backend='eager')(*args_b)
eager = loop_bound(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
