# source: https://github.com/pytorch/pytorch/issues/174386
# title: `torch.compile` ignores `torch.use_deterministic_algorithms(True)` on `empty_like`
# state: closed  created: 2026-02-05
# mined automatically; the harness records the torch.compile target and its first call

import torch

torch._inductor.config.fallback_random=True
torch.use_deterministic_algorithms(True)

def fn():
    return torch.empty_like(torch.randn(4, 4))

cfunc = torch.compile(fn)
out1 = fn()
out2 = cfunc()
torch.testing.assert_close(out1, out2, equal_nan=True)
