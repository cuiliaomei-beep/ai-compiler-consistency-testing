# source: https://github.com/pytorch/pytorch/issues/188541
# title: [Inductor][CUDA] F.logsigmoid flushes negative float32 subnormal outputs to +0.0, changing sign-sensitive behavior
# state: open  created: 2026-06-30
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def fn(x):
    y = F.logsigmoid(x)
    return y, torch.signbit(y), y == 0, torch.copysign(torch.ones_like(y), y)

cfn = torch.compile(fn, backend="inductor", fullgraph=True)

xs = torch.tensor([80.0, 85.0, 87.0, 88.0, 90.0, 100.0],
                  device="cuda", dtype=torch.float32)

eager = fn(xs)
compiled = cfn(xs)

print("x:", xs)
print("eager y:", eager[0])
print("compiled y:", compiled[0])
print("eager signbit:", eager[1])
print("compiled signbit:", compiled[1])
print("eager y == 0:", eager[2])
print("compiled y == 0:", compiled[2])
print("eager copysign:", eager[3])
print("compiled copysign:", compiled[3])
