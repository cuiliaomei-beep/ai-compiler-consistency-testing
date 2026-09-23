# source: https://github.com/pytorch/pytorch/issues/160840
# title: `torch.nn.functional.interpolate` generates inconsistent computation results after `torch.compile`
# state: closed  created: 2025-08-17
# mined automatically; the harness records the torch.compile target and its first call

import torch
import numpy as np

torch.manual_seed(0)
torch._inductor.config.fallback_random=True

def foo(input):
    interpolate = torch.nn.functional.interpolate(
        input,
        size=[40, 40],
        scale_factor=None,
        mode="bicubic",
        align_corners=None,
        recompute_scale_factor=None,
        antialias=False,
    )
    squeeze = interpolate.squeeze(0)
    argmin = squeeze.argmin(1)
    return argmin


np.random.seed(0)
x = np.random.uniform(0, 10, size=(1, 40, 1, 1))  # dtype = float64

cfoo = torch.compile(foo)
eager_res = foo(torch.from_numpy(x))
compile_res = cfoo(torch.from_numpy(x))
torch.testing.assert_close(eager_res, compile_res)
