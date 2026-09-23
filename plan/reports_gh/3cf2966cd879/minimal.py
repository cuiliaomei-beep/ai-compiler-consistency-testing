import torch
torch.manual_seed(0)

def fn(t):

    class Holder:
        items = []
    y = t * 2
    torch._dynamo.graph_break()
    Holder.items.append(2)
    z = y * 3
    return z.sum() + len(Holder.items)

args = (torch.randn(1).to(torch.float64),)

# context A then context B on the same compiled callable (no reset)
# A = {} (base)
# B = {'dtype': 'float16'}
args_b = (torch.randn(3).to(torch.float16),)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')
compiled(*args)              # warm the cache under A
warm = compiled(*args_b)     # execute under B without a reset
torch._dynamo.reset()
cold = torch.compile(fn, backend='inductor')(*args_b)
eager = fn(*args_b)
print('eager :', eager)
print('cold  :', cold)
print('warm  :', warm)
