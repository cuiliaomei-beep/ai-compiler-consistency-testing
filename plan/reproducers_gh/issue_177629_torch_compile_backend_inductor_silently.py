# source: https://github.com/pytorch/pytorch/issues/177629
# title: `torch.compile(backend="inductor")` silently succeeds on `torch.bmm` with mismatched dtypes (float16 @ float32) where eager raises RuntimeError
# state: closed  created: 2026-03-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

a = torch.randn(2, 8, 8, dtype=torch.float16)
b = torch.randn(2, 8, 64, dtype=torch.float32)

# CPU Eager: RuntimeError
try:
    torch.bmm(a, b)
except RuntimeError as e:
    print(f"CPU eager: ERROR — {e}")
# Output: CPU eager: ERROR — expected scalar type Float but found Half

# CPU Compiled: silently succeeds
torch._dynamo.reset()

@torch.compile(backend="inductor", fullgraph=True)
def compiled_bmm(x, y):
    return torch.bmm(x, y)

out = compiled_bmm(a, b)
print(f"CPU compile: OK dtype={out.dtype}")
# Output: CPU compile: OK dtype=torch.float32
