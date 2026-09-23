# source: https://github.com/pytorch/pytorch/issues/177821
# title: [inductor] torch.compile ignores a complex indexing assignment and produces incorrect result
# state: closed  created: 2026-03-19
# mined automatically; the harness records the torch.compile target and its first call

import torch

def fn(x, y):
    x = 2 * x  # x = [[0,2],[4,6]]
    c = torch.cat([x, y], dim=1)  # c = [[0,2,0,1], [4,6,2,3]]
    c[:, [1, 0]] = c[:, [0, 1]]  # c should be [[2,0,0,1], [6,4,2,3]]
    return c[:, :2] + x  # expected result: `[[2,2],[10,10]]`
    
x1 = torch.arange(4).reshape(2, 2)
y1 = torch.arange(4).reshape(2, 2)
x2 = torch.arange(4).reshape(2, 2)
y2 = torch.arange(4).reshape(2, 2)

cfunc = torch.compile(fn, backend='inductor')
out1 = fn(x1, y1)
out2 = cfunc(x2, y2)

print(f'{out1=}')
print(f'{out2=}')

torch.testing.assert_close(out1, out2, equal_nan=True)
