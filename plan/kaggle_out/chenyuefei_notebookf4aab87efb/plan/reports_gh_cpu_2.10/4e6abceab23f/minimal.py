import torch
torch.manual_seed(0)

def _noncontig(t):
    # same values, non-unit innermost stride (a strided view of a wider buffer)
    big = torch.empty(*t.shape[:-1], t.shape[-1] * 2, dtype=t.dtype)
    v = big[..., ::2]
    v.copy_(t)
    return v

def fn(x, y):
    return x.add_(y).reshape(-1, 1, 3)

args = (_noncontig(torch.randn(3, 2)), _noncontig(torch.randn(3, 1)))

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
