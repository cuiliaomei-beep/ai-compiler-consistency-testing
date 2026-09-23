# source: https://github.com/pytorch/pytorch/issues/182200
# title: `torch.compile` crashes on `stft`/`fftn`/`rfftn`/`ifftn` backward — meta kernel stride mismatch
# state: open  created: 2026-05-02
# mined automatically; the harness records the torch.compile target and its first call

import torch

# 1. stft backward
x = torch.randn(128, device="cuda", requires_grad=True)

@torch.compile(backend="inductor")
def f_stft(a):
    return torch.stft(a, n_fft=32, hop_length=16, return_complex=True).abs().sum()

f_stft(x).backward()  # AssertionError: stride mismatch
