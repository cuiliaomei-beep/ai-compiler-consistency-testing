# source: https://github.com/pytorch/pytorch/issues/195402
# title: [inductor] Out-of-bounds index aborts the process (SIGABRT) instead of raising, when the generated kernel is parallelised
# state: open  created: 2026-08-31
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x, idx):
    return (x - 0.5)[idx]

x = torch.randn(1, 8, 66, 66)     # dim 0 has size 1
idx = torch.tensor([[1]])         # index 1 -> out of bounds on dim 0

try:
    f(x, idx)
except IndexError as e:
    print("eager raises catchable IndexError:", e)

print("calling compiled...", flush=True)
torch.compile(f, backend="inductor")(x, idx)   # process aborts
print("NOT REACHED")
