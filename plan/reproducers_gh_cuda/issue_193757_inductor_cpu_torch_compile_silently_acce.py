# source: https://github.com/pytorch/pytorch/issues/193757
# title: [inductor][cpu] torch.compile silently accepts `binary_cross_entropy` targets outside `[0, 1]` that eager rejects
# state: open  created: 2026-08-17
# mined automatically; the harness records the torch.compile target and its first call

import torch

target = torch.ones(4, 4) * 1.5  # invalid: outside [0, 1]

def fn(t):
    return torch.nn.functional.binary_cross_entropy(torch.ones_like(t), t)

try:
    fn(target)
    print("eager   = accepted")
except RuntimeError as e:
    print("eager   raises:", e)  # all elements of target should be between 0 and 1

print("compiled=", torch.compile(fn)(target))  # tensor(-50.) instead of an error
