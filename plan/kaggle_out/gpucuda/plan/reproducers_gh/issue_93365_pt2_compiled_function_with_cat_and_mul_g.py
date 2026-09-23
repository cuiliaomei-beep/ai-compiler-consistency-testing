# source: https://github.com/pytorch/pytorch/issues/93365
# title: [pt2] compiled function with cat and mul gives wrong results
# state: closed  created: 2023-01-31
# mined automatically; the harness records the torch.compile target and its first call

import torch

p0 = torch.tensor([[4.9334, 5.5571]])
p1 = torch.tensor([[4.5627, 5.6945]])
# torch.rand(1) # no error
# p0 = torch.rand(2) # ERROR

def fn():
    v7 = torch.cat([p0, p0], dim=0) # ERROR
    # v7 = torch.cat([p1, p1], dim=0) # ERROR
    # v7 = torch.cat([p1, p0], dim=0) # ERROR
    v1 = torch.mul(v7, v7) # v1: (5, 2)
    return v7, v1

ret_eager = fn()

compiled = torch.compile(fn)
ret_compiled = compiled()

assert torch.allclose(ret_eager[0], ret_compiled[0]), '\n'.join(map(str, ["", ret_eager[0], ret_compiled[0]]))
# ^^^ no error
assert torch.allclose(ret_eager[1], ret_compiled[1]), '\n'.join(map(str, ["", ret_eager[1], ret_compiled[1]]))
''' ^^^ WRONG!
Traceback (most recent call last):
  File "/home/colin/bug.py", line 23, in <module>
    assert torch.allclose(ret_eager[1], ret_compiled[1]), '\n'.join(map(str, ["", ret_eager[1], ret_compiled[1]]))
AssertionError: 
tensor([[24.3384, 30.8814],
        [24.3384, 30.8814]])
tensor([[0., 0.],
        [0., 0.]])
'''
