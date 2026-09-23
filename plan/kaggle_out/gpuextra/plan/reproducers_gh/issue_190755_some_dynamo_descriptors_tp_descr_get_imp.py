# source: https://github.com/pytorch/pytorch/issues/190755
# title: Some Dynamo descriptors (`tp_descr_get_impl`) are missing a `descr_check` equivalent
# state: closed  created: 2026-07-22
# mined automatically; the harness records the torch.compile target and its first call

import torch

class Borrower:
    append = list.append   # C method_descriptor; its __objclass__ is `list`

def fn(x, obj):
    try:
        m = obj.append     # eager: descr_check raises TypeError HERE (at the bind)
        return x + 1       # dynamo: binds silently -> takes this branch
    except TypeError:
        return x + 2       # eager: takes this branch

x = torch.randn(4)
b = Borrower()

print(fn(x, b).sum())                                              # eager:   x + 2
print(torch.compile(fn, backend="eager", fullgraph=True)(x, b).sum())  # dynamo:  x + 1  (WRONG)
