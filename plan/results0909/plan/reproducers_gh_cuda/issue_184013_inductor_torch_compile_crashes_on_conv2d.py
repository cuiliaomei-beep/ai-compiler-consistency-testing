# source: https://github.com/pytorch/pytorch/issues/184013
# title: [inductor] `torch.compile` crashes on `conv2d` with cuDNN disabled — stride prediction mismatch
# state: closed  created: 2026-05-16
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo
import torch.nn.functional as F

torch.backends.cudnn.enabled = False

def conv_fn(x, w):
    return F.conv2d(x, w, padding=1)

x = torch.randn(2, 16, 8, 8, device='cuda')
w = torch.randn(16, 16, 3, 3, device='cuda')

# Eager: works
eager = conv_fn(x, w)

# aot_eager: works
torch._dynamo.reset()
aot = torch.compile(conv_fn, backend='aot_eager')(x.clone(), w.clone())
assert (eager - aot).abs().max() < 1e-6  # correct

# Inductor: CRASHES
torch._dynamo.reset()
compiled = torch.compile(conv_fn, backend='inductor')(x.clone(), w.clone())
# AssertionError: expected size 16==16, stride 64==1 at dim=1;
#   expected size 8==8, stride 8==128 at dim=2;
#   expected size 8==8, stride 1==16 at dim=3
# Error in op: torch.ops.aten.convolution.default
