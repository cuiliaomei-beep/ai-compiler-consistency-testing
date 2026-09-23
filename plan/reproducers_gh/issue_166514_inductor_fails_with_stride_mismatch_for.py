# source: https://github.com/pytorch/pytorch/issues/166514
# title: Inductor Fails with Stride Mismatch for `torch.fft.ifft` Due to Incorrect Meta Kernel Implementation
# state: closed  created: 2025-10-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

class FFTModel(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(3, 64, kernel_size=3, padding=1)
    
    def forward(self, x):
        x = self.conv(x)
        x = torch.fft.ifft(x, n=256)
        x = torch.real(x)
        return x

model = FFTModel()
x = torch.randn(4, 3, 32, 32)

backends = ["eager", "aot_eager", "inductor"]

for backend in backends:
    try:
        compiled_model = torch.compile(model, backend=backend)
        output = compiled_model(x)
        print(f"✅ '{backend}': Success, output shape {output.shape}")
    except Exception as e:
        print(f"❌ '{backend}': Failed - {str(e)}")
