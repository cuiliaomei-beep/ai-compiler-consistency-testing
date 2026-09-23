# source: https://github.com/pytorch/pytorch/issues/184415
# title: [Inductor] `torch._foreach_sub` silently ignores `alpha` under `torch.compile`
# state: closed  created: 2026-05-19
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(a, b):
    return torch._foreach_sub(a, b, alpha=2.0)

torch.manual_seed(42)
a = [torch.randn(4, device='cuda') for _ in range(3)]
b = [torch.randn(4, device='cuda') for _ in range(3)]

eager = fn(a, b)
compiled = torch.compile(fn)([t.clone() for t in a], [t.clone() for t in b])

for i in range(3):
    print(f"eager[{i}]:    {eager[i].tolist()}")
    print(f"compiled[{i}]: {compiled[i].tolist()}")
    print(f"  match: {torch.equal(eager[i], compiled[i])}")  # False

# compiled output exactly matches alpha=1 (no alpha):
no_alpha = torch._foreach_sub(a, b)
for i in range(3):
    assert torch.equal(compiled[i], no_alpha[i]), "compiled should match no-alpha"
print("\nalpha was silently ignored: compiled == no_alpha for all tensors")
