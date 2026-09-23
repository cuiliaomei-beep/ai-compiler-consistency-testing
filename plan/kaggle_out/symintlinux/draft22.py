import torch

def bucket(x):
    return round(x.shape[0], -1)

def scaled(x):
    return x * round(x.shape[0] * 5, -1)

f, g = (torch.compile(fn, backend="eager", dynamic=True) for fn in (bucket, scaled))
for n in (14, 15, 16, 25):
    x = torch.ones(n)
    print(f"n={n:2d}  round(n, -1): python {bucket(x):3d} compiled {f(x):3d}   x * round(5n, -1): eager {scaled(x)[0].item():5.0f} compiled {g(x)[0].item():5.0f}")
