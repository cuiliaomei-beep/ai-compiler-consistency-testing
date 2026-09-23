# source: https://github.com/pytorch/pytorch/issues/184714
# title: [TMA] Failure when running slice+view operations with TMA enabled on H100
# state: closed  created: 2026-05-21
# mined automatically; the harness records the torch.compile target and its first call

import torch, torch._inductor.config as cfg
cfg.triton.use_tensor_descriptor = True
cfg.assume_aligned_inputs = True

offset = 1

def f(x):
    return x[2:].view(dtype=torch.float32) + 1

x = torch.randn((128 + offset) * 2, dtype=torch.bfloat16, device="cuda")
torch.compile(f)(x); torch.cuda.synchronize()
