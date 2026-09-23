# source: https://github.com/pytorch/pytorch/issues/184027
# title: [inductor] `torch.compile` crashes on convolutions when weight is a plain tensor — stride prediction mismatch
# state: open  created: 2026-05-16
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo
import torch.nn.functional as F

def conv_fn(x, w):
    return F.conv2d(x, w, padding=1)

x = torch.randn(4, 16, 8, 8, device='cuda')
w = torch.randn(16, 16, 3, 3, device='cuda')

# Plain tensor weight: CRASHES
torch._dynamo.reset()
compiled = torch.compile(conv_fn, backend='inductor')(x, w)
# AssertionError: expected size 16==16, stride 1==64 at dim=1; ...

# nn.Parameter weight: WORKS
torch._dynamo.reset()
w_param = torch.nn.Parameter(w.clone())
compiled = torch.compile(conv_fn, backend='inductor')(x, w_param)  # OK
