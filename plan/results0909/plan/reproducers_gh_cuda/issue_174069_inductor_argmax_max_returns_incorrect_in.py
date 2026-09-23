# source: https://github.com/pytorch/pytorch/issues/174069
# title: [Inductor] argmax/max returns incorrect indices for boolean tensors on CUDA
# state: closed  created: 2026-02-02
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo

device = 'cuda'

def fn(x):
    return x.max(1, keepdim=True)[1]

# Boolean tensor with True starting at position 4
mask = torch.zeros(4, 8, 32, device=device, dtype=torch.bool)
mask[:, 4:, :] = True

result_eager = fn(mask)
torch._dynamo.reset()
result_compiled = torch.compile(fn, backend='inductor')(mask)

print(f'Expected index: 4')
print(f'Eager result: {result_eager[0, 0, 0].item()}')
print(f'Inductor result: {result_compiled[0, 0, 0].item()}')
# Output:
# Expected index: 4
# Eager result: 4
# Inductor result: 1  # WRONG!
