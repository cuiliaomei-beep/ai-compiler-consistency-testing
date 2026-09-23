import torch
torch.manual_seed(0)

def _noncontig(t):
    # same values, non-unit innermost stride (a strided view of a wider buffer)
    big = torch.empty(*t.shape[:-1], t.shape[-1] * 2, dtype=t.dtype)
    v = big[..., ::2]
    v.copy_(t)
    return v

def fn(x):
    return torch.argmax(torch.mean(x, dim=-1))

args = (_noncontig(torch.randn(2, 2, 2, 4)),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(*args)
print('eager   :', eager)
print('compiled:', compiled)
