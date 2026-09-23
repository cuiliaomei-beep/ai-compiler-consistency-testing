import torch

# source unavailable for 'f'
    def make_inputs(ctx: Context, _b=base) -> Tuple[Any, ...]:
        fresh = tuple(
            (a.detach().clone().requires_grad_(a.requires_grad)
             if torch is not None and isinstance(a, torch.Tensor) else a)
            for a in _b
        )
        return _apply_context(fresh, ctx)

# contexts:
#   base: {'variant': 'base'}
#   noncontig: {'variant': 'noncontig'}
#   dtype_float64: {'variant': 'base', 'dtype': 'float64'}
