import torch

def _f_dtype_reduce(x):
    return (x * x).sum(dim=-1) / (x.abs().mean(dim=-1) + 1e-6)

def _in_dtype(ctx: Context) -> Tuple[Any, ...]:
    return (_randn(64, 128, dtype=ctx.get("dtype", "float32")),)

# contexts:
#   fp32: {'dtype': 'float32'}
#   fp16: {'dtype': 'float16'}
#   bf16: {'dtype': 'bfloat16'}
