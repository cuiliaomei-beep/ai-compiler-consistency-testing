# source: https://github.com/pytorch/pytorch/issues/177630
# title: `torch.compile(backend="inductor")` silently succeeds on `torch.matmul` (≥3D) with mismatched dtypes (float16 @ float32) where eager raises RuntimeError
# state: closed  created: 2026-03-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

# 4D matmul with mismatched dtypes
a = torch.randn(2, 4, 8, 8, device="cuda", dtype=torch.float16)
b = torch.randn(2, 4, 8, 64, device="cuda", dtype=torch.float32)

# Eager: raises RuntimeError
try:
    out_eager = torch.matmul(a, b)
    print(f"eager: OK dtype={out_eager.dtype}")
except RuntimeError as e:
    print(f"eager: ERROR — {e}")
# Output: eager: ERROR — expected scalar type Half but found Float

# Compiled with inductor: silently succeeds
torch._dynamo.reset()

@torch.compile(backend="inductor", fullgraph=True)
def compiled_matmul(x, y):
    return torch.matmul(x, y)

try:
    out_compiled = compiled_matmul(a, b)
    print(f"compile: OK dtype={out_compiled.dtype}")
except Exception as e:
    print(f"compile: ERROR — {e}")
# Output: compile: OK dtype=torch.float32

# Verify the compiled output is an implicit fp16→fp32 promotion
ref = torch.matmul(a.float(), b)
print(f"max diff vs explicit promotion: {(out_compiled - ref).abs().max().item()}")
# Output: max diff vs explicit promotion: 0.0
