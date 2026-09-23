# source: https://github.com/pytorch/pytorch/issues/180848
# title: `torch.compile` produces wrong results when fusing `adaptive_avg_pool2d` with `flatten + sum`
# state: closed  created: 2026-04-20
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    y = torch.nn.functional.adaptive_avg_pool2d(x, 7)
    return y.flatten(1).sum(dim=-1)

torch.manual_seed(42)
x = torch.randn(2, 33, 8, 8, dtype=torch.float64, device='cuda')

# Eager — correct
print(f"Eager: {f(x).tolist()}")
# [-52.27041819362077, 30.75847231895647]

# Inductor — wrong
torch._dynamo.reset()
compiled = torch.compile(f, backend='inductor')(x)
print(f"Inductor: {compiled.tolist()}")
# [-52.27041819362077, 34.325837206874446]  ← second element is wrong

print(f"Max diff: {(f(x) - compiled).abs().max().item()}")
# 3.567365  ← catastrophic for fp64
