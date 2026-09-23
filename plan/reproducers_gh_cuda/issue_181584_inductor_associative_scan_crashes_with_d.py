# source: https://github.com/pytorch/pytorch/issues/181584
# title: [inductor] `associative_scan` crashes with `dynamic=True` for ndim >= 2
# state: closed  created: 2026-04-27
# mined automatically; the harness records the torch.compile target and its first call

import torch

def combine_fn(a, b):
    return a + b

x = torch.randn(4, 8, device='cuda')

# Static: works
torch._dynamo.reset()
r = torch.compile(
    lambda x: torch._higher_order_ops.associative_scan(combine_fn, x, dim=0)
)(x)
print(f"static: OK, shape={r.shape}")

# Dynamic: crashes
torch._dynamo.reset()
r = torch.compile(
    lambda x: torch._higher_order_ops.associative_scan(combine_fn, x, dim=0),
    dynamic=True
)(x)
# LoweringException: RuntimeError: Unable to generate code for
# associative_scan op, because there are lifted arguments
