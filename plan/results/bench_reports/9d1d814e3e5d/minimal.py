import torch
torch.manual_seed(0)

def scalar_compare(x, n):
    if n > 4:
        return x[:n].sum(dim=0)
    return x.sum(dim=0) * n

args = (torch.randn(16, 8), 6)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'substitute': {'arg': 1, 'value': 4}}
args_b = (torch.randn(16, 8), 4)
torch._dynamo.reset()
compiled = torch.compile(scalar_compare, backend='eager')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(scalar_compare, backend='eager')(*args_b)
eager = scalar_compare(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
