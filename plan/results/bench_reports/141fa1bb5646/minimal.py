import torch
torch.manual_seed(0)

def noncontig_copy(x, w):
    z = x[:, ::2]
    z.copy_(w)
    return x

args = (torch.randn(8, 16), torch.randn(8, 8))

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'layout': 'noncontig'}
args_b = (torch.randn(8, 16)  # NOTE: non-contiguous in the failing run, torch.randn(8, 8)  # NOTE: non-contiguous in the failing run)
torch._dynamo.reset()
compiled = torch.compile(noncontig_copy, backend='eager')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(noncontig_copy, backend='eager')(*args_b)
eager = noncontig_copy(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
