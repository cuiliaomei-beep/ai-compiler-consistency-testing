# source: https://github.com/pytorch/pytorch/issues/170939
# title: [Inductor] F.pdist fails with "RuntimeError: _pdist_forward requires contiguous input" on non-contiguous inputs
# state: closed  created: 2025-12-20
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

def fn(x):
    # Creating a non-contiguous tensor via permute
    x = x.permute(1, 0)
    return F.pdist(x)

x = torch.randn(16, 100)

print(f"Input is contiguous: {x.permute(1,0).is_contiguous()}") # False

# 1. Eager Mode (Success)
print("Running Eager...")
try:
    fn(x)
    print("Eager Success.")
except Exception as e:
    print(f"Eager Failed: {e}")

# 2. Compile Mode (Fail)
print("Running Compile...")
opt_fn = torch.compile(fn, backend="inductor")

try:
    opt_fn(x)
    print("Compile Success.")
except Exception as e:
    print("\n[Confirmed Bug Capture]")
    # Printing the core error message
    print(f"Error: {e}")
