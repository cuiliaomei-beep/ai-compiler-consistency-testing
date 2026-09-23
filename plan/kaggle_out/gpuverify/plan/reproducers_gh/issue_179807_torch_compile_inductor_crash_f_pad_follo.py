# source: https://github.com/pytorch/pytorch/issues/179807
# title: `torch.compile` inductor crash: `F.pad` followed by `stft`
# state: closed  created: 2026-04-09
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.nn.functional as F


class Model(nn.Module):
    def __init__(self):
        super().__init__()
        self._window = torch.hann_window(320)

    def forward(self, x):
        x = F.pad(x, (0, 318))
        return x.stft(n_fft=512, hop_length=160, win_length=320,
                       return_complex=True, window=self._window, pad_mode="constant")


model = Model()
x = torch.randn(2, 2)

ret_eager = model(x.clone())
print(f"Eager OK: {ret_eager.shape}")

compiled = torch.compile(model)
ret_compiled = compiled(x.clone())
print(f"Compile OK: {ret_compiled.shape}")
