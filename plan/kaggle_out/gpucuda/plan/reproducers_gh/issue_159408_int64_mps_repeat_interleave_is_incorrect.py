# source: https://github.com/pytorch/pytorch/issues/159408
# title: int64 mps repeat_interleave is incorrect under torch.compile
# state: closed  created: 2025-07-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
device = 'mps'
dtype = torch.int64
# https://github.com/pytorch/pytorch/issues/147160
def f(input, repeats):
    return torch.repeat_interleave(input, repeats, dim=0, output_size=3) + 1

input = torch.tensor([[1, 2], [3, 4]], dtype=dtype, device=device)
repeat = torch.tensor([1, 2], device=device)
f_compiled = torch.compile(f)
output = f_compiled(input, repeat)
reference = f(input, repeat)
print(output, reference)
