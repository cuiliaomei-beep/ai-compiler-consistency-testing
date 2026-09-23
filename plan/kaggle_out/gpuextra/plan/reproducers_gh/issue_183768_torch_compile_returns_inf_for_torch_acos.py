# source: https://github.com/pytorch/pytorch/issues/183768
# title: torch.compile returns inf for torch.acosh on large finite float32 inputs while eager returns finite values
# state: open  created: 2026-05-14
# mined automatically; the harness records the torch.compile target and its first call

import warnings
warnings.filterwarnings("ignore")

import numpy as np
import torch

def fn(x):
    return torch.acosh(x)

x = torch.tensor([5e22, 9e25, 7e21, 2.0], dtype=torch.float32)

eager = fn(x).cpu().numpy()

torch._dynamo.reset()
compiled = torch.compile(fn, backend="inductor", fullgraph=True)(x).cpu().numpy()

print(f"input: {x.cpu().numpy()}")
print(f"eager: {eager}")
print(f"comp : {compiled}")

assert np.isfinite(eager[0]) and 50 < eager[0] < 60
assert np.isinf(compiled[0])
assert np.isinf(compiled[1])
