# source: https://github.com/pytorch/pytorch/issues/185575
# title: [inductor] Upsample(mode='area') fails under torch.compile(dynamic=True) — "cannot determine truth value of Relational" in _adaptive_avg_pool2d lowering
# state: closed  created: 2026-05-29
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

x = torch.randn(1, 3, 15, 19)
m = nn.Upsample(scale_factor=2, mode='area')
m = torch.compile(m, dynamic=True)
m(x)    #crash here!
