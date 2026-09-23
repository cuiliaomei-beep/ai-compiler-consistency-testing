import torch

def _f_flag(x, fast: bool):
    if fast:
        return x.sum(dim=0) * 0.5
    return (x * 0.5).sum(dim=0)

def _in_flag(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(32, 32), bool(ctx.get("fast", True)))

# contexts:
#   fast: {'fast': True}
#   slow: {'fast': False}
