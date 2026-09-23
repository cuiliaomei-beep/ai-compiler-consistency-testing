# source: https://github.com/pytorch/pytorch/issues/181625
# title: `AssertionError: expected size/stride mismatch` in Inductor-generated code for `torch.fft.fft` after `MultiheadAttention`, with warning about unsupported complex op codegen
# state: closed  created: 2026-04-27
# mined automatically; the harness records the torch.compile target and its first call

import os, tempfile
os.environ.setdefault('TORCHINDUCTOR_CACHE_DIR', tempfile.mkdtemp(prefix='inductor_'))

import torch
import torch.nn as nn
import torch.nn.functional as F

m_mha      = nn.MultiheadAttention(4, 2, batch_first=True).eval()
m_hardswish = nn.Hardswish()

torch.manual_seed(0)
x = torch.randn([4, 12, 4])

def model():
    out = F.scaled_dot_product_attention(x, x, x)   # [4, 12, 4]
    out, _ = m_mha(out, out, out)                    # [4, 12, 4]
    out = torch.fft.fft(out).abs()                   # [4, 12, 4] real
    out = m_hardswish(out)                           # [4, 12, 4]
    return out

# Eager: works fine
print("Eager output is finite:", torch.isfinite(model()).all().item())

# Compiled: crashes with stride mismatch in generated code
compiled_model = torch.compile(model, backend='inductor')
compiled_model()  # ← AssertionError: expected size/stride mismatch at _fft_r2c
