import torch
torch.manual_seed(0)

def contiguous_read(x):
    if x.is_contiguous():
        return x.view(-1).sum()
    return x.reshape(-1).sum()

args = (torch.randn(8, 8),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'layout': 'noncontig'}
args_b = (torch.randn(8, 8)  # NOTE: non-contiguous in the failing run,)
torch._dynamo.reset()
compiled = torch.compile(contiguous_read, backend='eager')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(contiguous_read, backend='eager')(*args_b)
eager = contiguous_read(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
