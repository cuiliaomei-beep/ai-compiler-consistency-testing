# source: https://github.com/pytorch/pytorch/issues/180956
# title: `torch.compile` produces wrong results for `adaptive_avg_pool2d` + `flatten` + `sum` fusion
# state: closed  created: 2026-04-21
# mined automatically; the harness records the torch.compile target and its first call

import torch

x = torch.randn(3, 33, 8, 8, dtype=torch.float64, device='cuda')

def f(x):
    return torch.nn.functional.adaptive_avg_pool2d(x, 7).flatten(1).sum(dim=-1)

# Eager — correct
print(f"eager = {f(x).tolist()}")

# Inductor — wrong
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(x)
print(f"inductor = {compiled.tolist()}")
print(f"max_diff = {(f(x) - compiled).abs().max().item():.2e}")
# max_diff ~ 5e+00 to 8e+01 depending on seed
