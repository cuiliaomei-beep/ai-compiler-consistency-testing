# source: https://github.com/pytorch/pytorch/issues/96728
# title: Redundant statement leads to wrong output
# state: closed  created: 2023-03-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
a = torch.tensor([[4.]])
b = torch.tensor([5.])
def forward(a, b):
    a = a.max(0).values
    c = torch.cat((a, b))
    c = c.round()
    b >= a[0]
    return c
print(forward(a, b))
fn_compiled = torch.compile(forward)
print(fn_compiled(a, b))
