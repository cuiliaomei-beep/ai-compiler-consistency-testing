# source: https://github.com/pytorch/pytorch/issues/184014
# title: [inductor] `force_layout_optimization=True` crashes on `conv2d + avg_pool2d + flatten` — stride mismatch
# state: closed  created: 2026-05-16
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch._dynamo
import torch._inductor.config as inductor_config
import torch.nn.functional as F

def model_fn(x, w):
    y = F.conv2d(x, w, padding=1)
    y = F.relu(y)
    y = F.avg_pool2d(y, 2)
    return y.flatten(1)

x = torch.randn(4, 16, 8, 8, device='cuda')
w = torch.randn(32, 16, 3, 3, device='cuda')

# Without config: works
torch._dynamo.reset()
result = torch.compile(model_fn, backend='inductor')(x, w)  # OK

# With force_layout_optimization: CRASHES
torch._dynamo.reset()
with inductor_config.patch({"force_layout_optimization": True}):
    result = torch.compile(model_fn, backend='inductor')(x, w)
# AssertionError: expected size 32==32, stride 1==64 at dim=1; ...
# Error in op: torch.ops.aten.convolution.default
