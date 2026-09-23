# source: https://github.com/pytorch/pytorch/issues/174379
# title: [Inductor][PyTorch 2.10] RuntimeError in native_layer_norm_backward with dynamic shapes. Generated inductor code computes incorrect workspace slice.
# state: closed  created: 2026-02-05
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn

linear1 = nn.Linear(1000, 1000).to("cuda")
norm = nn.LayerNorm(1000).to("cuda")

def model(x):
    return norm(linear1(x[:, :-1].reshape(-1, 1000)))

compiled_model = torch.compile(model)
for step in range(100):
    compiled_model(torch.randn(32, 150 + (step % 50), 1000, device="cuda")).sum().backward()
