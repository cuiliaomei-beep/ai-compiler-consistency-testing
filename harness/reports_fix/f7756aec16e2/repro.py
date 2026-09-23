import torch

# source unavailable for 'f'
    def make_inputs(ctx: Context, _base=base_args) -> Tuple[Any, ...]:
        return _apply_context(tuple(_clone(a) for a in _base), ctx)

# contexts:
#   base: {'variant': 'base'}
#   noncontig: {'variant': 'noncontig'}
#   dtype_float64: {'variant': 'base', 'dtype': 'float64'}
