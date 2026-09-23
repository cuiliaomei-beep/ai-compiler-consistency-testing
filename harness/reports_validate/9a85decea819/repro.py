import torch

def _f_shape_boundary(x):
    if x.shape[0] >= 32:
        return (x * 2.0).sum(dim=0)
    return (x + 1.0).sum(dim=0)

def _in_shape_boundary(ctx: Context) -> Tuple[Any, ...]:
    n = ctx.get("rows", 32)
    return (_randn(n, 16),)

# contexts:
#   rows31: {'rows': 31}
#   rows32: {'rows': 32}
#   rows33: {'rows': 33}
