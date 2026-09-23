# source: https://github.com/pytorch/pytorch/issues/167780
# title: [Inductor] combo_kernel fails with CppScheduling backend
# state: closed  created: 2025-11-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
from torch._inductor import config


@config.patch(combo_kernels=True)
def fn(x):
    return torch.ops.aten._adaptive_avg_pool2d(x, (6, 6)), torch.ops.aten._adaptive_avg_pool2d(
        x + 1, (2, 5)
    )

x = torch.randn(2, 4, 16, 16, device="cpu")
torch.compile(fn)(x)
