# source: https://github.com/pytorch/pytorch/issues/171306
# title: The precision of pow(x, 0.5) and libdevice.sqrt is inconsistent.
# state: closed  created: 2025-12-26
# mined automatically; the harness records the torch.compile target and its first call

import torch


def fn(x):
    return torch.ops.aten.pow.Tensor_Scalar(x, 0.5)

x = torch.randn((64, 1), dtype=torch.float32, device="cuda")
x = torch.abs(x)
eager_ret = fn(x)
opt_ret = torch.compile(fn)(x)
torch.testing.assert_close(eager_ret, opt_ret, equal_nan=True, atol=0.0, rtol=0.0)
