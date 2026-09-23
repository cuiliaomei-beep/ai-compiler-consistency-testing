# source: https://github.com/pytorch/pytorch/issues/174549
# title: [Inconsistency] `torch.nn.FractionalMaxPool2d` generates lower result with `torch.compile`
# state: closed  created: 2026-02-08
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch._inductor.config.fallback_random=True
torch.manual_seed(0)

pool = torch.nn.FractionalMaxPool2d(kernel_size=(1, 1), output_ratio=(0.5, 0.5))
def fn(a):
    return pool(a)

cfunc = torch.compile(fn, backend='inductor')
cfunc_aot_eager = torch.compile(fn, backend='aot_eager')

x1 = torch.randn(1, 10, 10, dtype=torch.float64)
x2 = x1.clone().detach()
x3 = x1.clone().detach()
out1 = fn(x1)
out2 = cfunc(x2)
print(f'{out1=}')
print(f'{out2=}')
torch.testing.assert_close(out1, out2, equal_nan=True)

out3 = cfunc_aot_eager(x3)
print(f'{out3=}')
torch.testing.assert_close(out1, out3, equal_nan=True)  # aot_eager backend also generates this inconsistency.
