# source: https://github.com/pytorch/pytorch/issues/183765
# title: torch.compile overflows torch.cosh near float32 boundary while eager returns finite values
# state: closed  created: 2026-05-14
# mined automatically; the harness records the torch.compile target and its first call

import warnings
warnings.filterwarnings("ignore")

import numpy as np
import torch

def fn(x):
    return torch.cosh(x)

x = torch.tensor([88.85, 88.9, 89.1, -89.2], dtype=torch.float32)

eager = fn(x).cpu().numpy()

torch._dynamo.reset()
compiled = torch.compile(fn, backend="inductor", fullgraph=True)(x).cpu().numpy()

print(f"input: {x.cpu().numpy()}")
print(f"eager: {eager}")
print(f"comp : {compiled}")

assert np.isfinite(eager[0]) and eager[0] > 1e38
assert np.isinf(compiled[0])
