import torch

# source unavailable for 'g'
    def make_inputs(ctx: Context, _ns=base_ns, _setup=setup_code,
                    _args=arg_exprs) -> Tuple[Any, ...]:
        # a shallow copy shares the imports/classes but lets `setup` rebind the
        # input names, so every call allocates its own tensors
        ns = dict(_ns)
        exec(_setup, ns)
        return _apply_context(tuple(eval(a, ns) for a in _args), ctx)

# contexts:
#   base: {'variant': 'base'}
#   dtype_float16: {'variant': 'base', 'dtype': 'float16'}
#   dtype_float64: {'variant': 'base', 'dtype': 'float64'}
#   noncontig: {'variant': 'noncontig'}
