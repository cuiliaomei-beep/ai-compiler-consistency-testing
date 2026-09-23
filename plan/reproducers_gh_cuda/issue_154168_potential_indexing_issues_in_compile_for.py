# source: https://github.com/pytorch/pytorch/issues/154168
# title: Potential indexing issues in compile for large tensors
# state: closed  created: 2025-05-22
# mined automatically; the harness records the torch.compile target and its first call

import torch
import numpy as np

size = (50000, 100000)
t = torch.randint(0, 100, size, dtype=torch.int32, device='cuda') 
op = torch.compile(torch._prims.xor_sum)
print(op(t, dims=(0, 1)))  # tensor(59, device='cuda:0')
print(np.bitwise_xor.reduce(t.cpu().numpy(), axis=(0, 1)))  # 48
