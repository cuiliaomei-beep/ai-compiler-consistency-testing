# source: https://github.com/pytorch/pytorch/issues/184026
# title: [inductor] `torch.compile` crashes on `conv_transpose2d` with `output_padding` — stride prediction mismatch
# state: closed  created: 2026-05-16
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo
import torch.nn.functional as F

def conv_transpose_fn(x, w):
    return F.conv_transpose2d(x, w, stride=2, padding=1, output_padding=1)

x = torch.randn(2, 16, 4, 4, device='cuda')
w = torch.randn(16, 16, 3, 3, device='cuda')

# aot_eager: works
torch._dynamo.reset()
aot = torch.compile(conv_transpose_fn, backend='aot_eager')(x.clone(), w.clone())  # OK

# Inductor: CRASHES
torch._dynamo.reset()
compiled = torch.compile(conv_transpose_fn, backend='inductor')(x.clone(), w.clone())
# AssertionError: expected size 16==16, stride 1==64 at dim=1; ...
