import torch

def _f_overlapping(x):
    a = x[:6]
    b = x[4:]
    a.mul_(2.0)
    b.add_(1.0)
    return x, a, b

def _in_overlapping(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(10, dtype=ctx.get("dtype", "float32")),)

# contexts:
#   fp32: {'dtype': 'float32'}
#   fp16: {'dtype': 'float16'}
