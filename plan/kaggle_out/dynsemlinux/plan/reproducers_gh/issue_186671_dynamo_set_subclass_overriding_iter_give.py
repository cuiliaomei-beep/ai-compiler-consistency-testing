# source: https://github.com/pytorch/pytorch/issues/186671
# title: [dynamo] set subclass overriding __iter__ gives wrong result for set comparison under torch.compile
# state: closed  created: 2026-06-09
# mined automatically; the harness records the torch.compile target and its first call

import torch


class MySet(set):
    def __iter__(self):
        return iter([99])  # lie


def fn(s1, s2):
    return s1 == s2


s1 = {1, 2, 3}
s2 = MySet({1, 2, 3})

print("eager:   ", fn(s1, s2))                                                  # True
print("compiled:", torch.compile(fn, backend="eager", fullgraph=True)(s1, s2))  # False
