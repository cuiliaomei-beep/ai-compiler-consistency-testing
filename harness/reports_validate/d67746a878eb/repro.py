import torch

def _f_grad(x):
    y = (x * 3.0).relu()
    return y.sum()

def _in_grad(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(32, 32, requires_grad=bool(ctx.get("requires_grad", False))),)

# contexts:
#   nograd: {'requires_grad': False}
#   grad: {'requires_grad': True}
