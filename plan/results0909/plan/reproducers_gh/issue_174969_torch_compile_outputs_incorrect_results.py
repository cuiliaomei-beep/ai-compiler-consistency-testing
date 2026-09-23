# source: https://github.com/pytorch/pytorch/issues/174969
# title: torch.compile outputs incorrect results when applying `add_` on transposed tensor
# state: closed  created: 2026-02-13
# mined automatically; the harness records the torch.compile target and its first call

import torch
torch._inductor.config.fallback_random = True


def fn(x, y):
    return x.add_(y).reshape(-1, 1, 3)
torch.manual_seed(0)

x1 = torch.ones([1, 2, 3]).transpose(1, 2)
y1 = torch.randn([1, 3, 1])
print(x1, y1)
'''
tensor([[[1., 1.],
         [1., 1.],
         [1., 1.]]]),
tensor([[[ 1.5410],
         [-0.2934],
         [-2.1788]]])
'''
x2 = x1.clone()
y2 = y1.clone()
cfunc = torch.compile(fn, backend='inductor')

out1 = fn(x1, y1)
print(out1)
'''
tensor([[[ 2.5410,  2.5410,  0.7066]],

        [[ 0.7066, -1.1788, -1.1788]]])
'''
out2 = cfunc(x2, y2)
print(out2)
'''
tensor([[[ 4.0820,  4.0820,  0.4131]],

        [[ 0.4131, -3.3576, -3.3576]]])
'''

torch.testing.assert_close(out1, out2, equal_nan=True)
