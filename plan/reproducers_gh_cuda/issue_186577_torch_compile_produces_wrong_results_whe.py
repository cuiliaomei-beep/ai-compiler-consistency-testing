# source: https://github.com/pytorch/pytorch/issues/186577
# title: `torch.compile` produces wrong results when `F.layer_norm` is fused with `reciprocal`/`rsqrt` epilogue
# state: closed  created: 2026-06-08
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

x = torch.randn(64, 128, device='cuda')

def fn(x):
    return torch.reciprocal(torch.abs(F.layer_norm(x, [128])) + 1e-6)

eager = fn(x)

torch._dynamo.reset()
aot = torch.compile(fn, backend='aot_eager')(x)

torch._dynamo.reset()
compiled = torch.compile(fn, backend='inductor')(x)

print(f"eager vs aot_eager: {(eager - aot).abs().max().item():.4e}")    # 0.0000e+00
print(f"eager vs inductor:  {(eager - compiled).abs().max().item():.4e}")  # ~9e-01
