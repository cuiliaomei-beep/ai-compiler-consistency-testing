# source: https://github.com/pytorch/pytorch/issues/177631
# title: [inductor] torch.compile produces incorrect results when applying `index_put` and `sort` on the return of `pad`
# state: closed  created: 2026-03-17
# mined automatically; the harness records the torch.compile target and its first call

import torch


def fn(a):
    b = torch.nn.functional.pad(a, (0, 0))
    a[0] = 1  # a[0, 0] = 1 will not cause inconsistency
    sorted_tensor, _ = torch.sort(b) # return b here will not cause inconsistency
    return sorted_tensor

x1 = torch.zeros((2, 2), dtype=torch.float32)
x2 = torch.zeros((2, 2), dtype=torch.float32)

cfunc = torch.compile(fn, backend='inductor')
out1 = fn(x1)
out2 = cfunc(x2)

print(f'{out1=}')
print(f'{out2=}')
torch.testing.assert_close(out1, out2, equal_nan=True)

'''
out1=tensor([[0., 0.],
        [0., 0.]])
out2=tensor([[1., 1.],
        [0., 0.]])
'''
