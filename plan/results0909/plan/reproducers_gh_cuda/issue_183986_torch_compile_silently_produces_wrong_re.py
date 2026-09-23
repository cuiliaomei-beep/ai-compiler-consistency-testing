# source: https://github.com/pytorch/pytorch/issues/183986
# title: `torch.compile` silently produces wrong results for `index_add`/`index_copy`/`index_fill`/`index_put` on expanded (stride-0) tensors
# state: closed  created: 2026-05-16
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(src, idx):
    x = torch.zeros(1, 8, device="cuda").expand(4, -1)  # stride-0 in dim 0
    return x.index_add(0, idx, src)

src = torch.ones(3, 8, device="cuda")
idx = torch.tensor([0, 1, 0], device="cuda")

eager = fn(src, idx)
compiled = torch.compile(fn, backend="inductor")(src, idx)

print("Eager row 0:", eager[0].tolist())      # [2, 2, 2, 2, 2, 2, 2, 2]
print("Compiled row 0:", compiled[0].tolist()) # [3, 3, 3, 3, 3, 3, 3, 3]  ← WRONG
print("Eager row 2:", eager[2].tolist())       # [0, 0, 0, 0, 0, 0, 0, 0]
print("Compiled row 2:", compiled[2].tolist()) # [3, 3, 3, 3, 3, 3, 3, 3]  ← WRONG
