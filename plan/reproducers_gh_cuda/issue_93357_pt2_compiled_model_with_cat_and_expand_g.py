# source: https://github.com/pytorch/pytorch/issues/93357
# title: [pt2] compiled model with cat and expand gives wrong results
# state: closed  created: 2023-01-31
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

p0 = torch.nn.parameter.Parameter(torch.tensor([4, 4, 5, 5, 4, 4, 4, 7, 4]), requires_grad=False)
def fn():
    m = torch.cat([p0, p0], dim=0)
    o = m.expand(1, 1, 1, 18)
    return o

with torch.no_grad():
    ret_eager = fn()

    compiled = torch.compile(fn, backend='inductor', mode='default', dynamic=False, fullgraph=True, )
    ret_compiled = compiled()

    assert torch.allclose(ret_eager, ret_compiled), (ret_eager, ret_compiled) # right; no error

print(f'==== fn OK! ====')

class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self.p1 = torch.nn.parameter.Parameter(torch.tensor([4, 4, 5, 5, 4, 4, 4, 7, 4]), requires_grad=False) # (9,)
        # self.p1 = torch.nn.parameter.Parameter(torch.randint(-5, 5, (9,)), requires_grad=False) # NOTE: also error
        # self.p1 = torch.nn.parameter.Parameter(torch.tensor([4, 4, 5, 5, 4, 4, 4, 7, 4]).float(), requires_grad=False) # NOTE: also error
        # self.p1 = torch.tensor([4, 4, 5, 5, 4, 4, 4, 7, 4]) # NOTE: also error

    def forward(self, ):
        v0 = torch.cat([self.p1, self.p1], dim=0) # v0: (18,)
        # NOTE: directly return v0 works fine
        # NOTE: torch.cat([p0, p0], dim=0) works fine
        v5 = v0.expand(1, 1, 1, 18) # v5: (1, 1, 1, 18)
        return v5

with torch.no_grad():
    model = Model()
    ret_eager = model()

    compiled = torch.compile(model, backend='inductor', mode='default', dynamic=False, fullgraph=True, )
    ret_compiled = compiled()

    assert torch.allclose(ret_eager, ret_compiled), '\n'.join(map(str, ["", ret_eager, ret_compiled]))

'''
Traceback (most recent call last):
  File "/home/colin/code/bug.py", line 38, in <module>
    assert torch.allclose(ret_eager, ret_compiled), '\n'.join(map(str, ["", ret_eager, ret_compiled]))
AssertionError: 
tensor([[[[4, 4, 5, 5, 4, 4, 4, 7, 4, 4, 4, 5, 5, 4, 4, 4, 7, 4]]]])
tensor([[[[136450624, 136476736,         5,         5,         4,         4,
                   4,         7,         4,         4,         4,         5,
                   5,         4,         4,         4,         7,         4]]]])
'''

print(f'==== model OK! ====')
