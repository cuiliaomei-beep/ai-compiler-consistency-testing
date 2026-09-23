# source: https://github.com/pytorch/pytorch/issues/175791
# title: [inductor] Incorrect output when compiling model with expand+broadcasted index put
# state: closed  created: 2026-02-25
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch.manual_seed(0)


def fn(x, y):
    z = x @ y
    expanded = x.expand(1, 2, 4)
    expanded[0, 1] = 1
    return z

cfunc = torch.compile(fn, backend='inductor')

x1 = torch.randn(1, 2, 4, dtype=torch.float32)
y1 = torch.randn(1, 4, 4, dtype=torch.float32)
x2 = x1.clone()
y2 = y1.clone()
out1 = fn(x1, y1)
out2 = cfunc(x2, y2)

torch.testing.assert_close(out1, out2, equal_nan=True)
