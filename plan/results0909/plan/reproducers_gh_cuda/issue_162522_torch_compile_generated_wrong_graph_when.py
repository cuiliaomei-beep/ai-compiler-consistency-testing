# source: https://github.com/pytorch/pytorch/issues/162522
# title: torch.compile generated wrong graph when tracing torch.use_deterministic_algorithms
# state: closed  created: 2025-09-09
# mined automatically; the harness records the torch.compile target and its first call

import torch

@torch.compile(backend="inductor")
def fn(src, index, base_tensor):
    src = src + 10
    torch.use_deterministic_algorithms(True)
    base_tensor.scatter_(0, index, src)
    return base_tensor.clone() + 1

src = torch.tensor([[100.0], [200.0], [300.0]], device="cuda")
index = torch.tensor([[0], [0], [0]], device="cuda")
base_tensor = torch.zeros(2, 1, device="cuda")

out = fn(src, index, base_tensor)
print(out)
