import torch
torch.manual_seed(0)

def fn(t):
    class Holder:
        items = []

    Holder.items.append(1)
    y = t * 2
    torch._dynamo.graph_break()
    Holder.items.append(2)
    z = y * 3
    return z.sum() + len(Holder.items)

args = (torch.randn(3).to(torch.float16),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
