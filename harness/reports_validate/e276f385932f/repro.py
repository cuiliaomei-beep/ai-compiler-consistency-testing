import torch

def _f_noncontig(x, w):
    z = x[:, ::2]
    z.copy_(w)
    return x

def _in_noncontig(ctx: Context) -> Tuple[Any, ...]:
    n = ctx.get("cols", 16)
    dt = ctx.get("dtype", "float32")
    return (_randn(8, n, dtype=dt), _randn(8, n // 2, dtype=dt))

# contexts:
#   cols16: {'cols': 16}
#   cols32: {'cols': 32}
