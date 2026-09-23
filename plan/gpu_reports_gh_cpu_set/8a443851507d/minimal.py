import torch
torch.manual_seed(0)

def fn(x): return m3(m2(m1(x))).mean()

args = (torch.randn(8, 10, 11, 10),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
