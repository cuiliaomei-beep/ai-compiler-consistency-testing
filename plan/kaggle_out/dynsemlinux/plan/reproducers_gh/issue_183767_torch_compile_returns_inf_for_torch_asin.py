# source: https://github.com/pytorch/pytorch/issues/183767
# title: torch.compile returns inf for torch.asinh on large finite float32 inputs while eager returns finite values
# state: closed  created: 2026-05-14
# mined automatically; the harness records the torch.compile target and its first call

import warnings
warnings.filterwarnings("ignore")

import numpy as np
import torch

def fn(x):
    return torch.asinh(x)

x = torch.tensor([3e22, 7e25, -8e23, 1e10], dtype=torch.float32)

eager = fn(x).cpu().numpy()

torch._dynamo.reset()
compiled = torch.compile(fn, backend="inductor", fullgraph=True)(x).cpu().numpy()

print(f"input: {x.cpu().numpy()}")
print(f"eager: {eager}")
print(f"comp : {compiled}")

assert np.isfinite(eager[0]) and 50 < eager[0] < 60
assert np.isinf(compiled[0])
assert np.isinf(compiled[1])
