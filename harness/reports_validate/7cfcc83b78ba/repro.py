import torch

def _f_view_inplace(x):
    y = x.view(-1)
    y[0] = y[0] + 1.0
    return x

def _in_view(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(8, 8, dtype=ctx.get("dtype", "float32")),)

# contexts:
#   fp32: {'dtype': 'float32'}
#   fp16: {'dtype': 'float16'}
