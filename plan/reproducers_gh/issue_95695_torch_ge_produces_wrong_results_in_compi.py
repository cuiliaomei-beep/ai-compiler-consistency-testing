# source: https://github.com/pytorch/pytorch/issues/95695
# title: `torch.ge` produces wrong results in compile mode when given int tensors
# state: closed  created: 2023-02-28
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(input):
    return torch.ge(input, 3.5)

x = torch.tensor([3])
# ✔️ x = torch.tensor([3.0])

ret_eager = fn(x)
compiled = torch.compile(fn)
ret_compiled = compiled(x)

print(f"{ret_eager=}", f"{ret_compiled=}")
assert(ret_eager == ret_compiled)
print('==== Check OK! ====')

"""
ret_eager=tensor([False]) ret_compiled=tensor([True])
Traceback (most recent call last):
  File "repro.py", line 13, in <module>
    assert(ret_eager == ret_compiled)
AssertionError
"""
