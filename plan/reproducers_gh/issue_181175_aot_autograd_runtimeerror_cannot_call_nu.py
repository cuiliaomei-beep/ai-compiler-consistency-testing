# source: https://github.com/pytorch/pytorch/issues/181175
# title: [aot_autograd] RuntimeError: Cannot call numel() on tensor with symbolic sizes/strides in _convolution_double_backward when using torch.compile(dynamic=True) with torch.func.grad over ConvTranspose2d
# state: closed  created: 2026-04-22
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn as nn
import torch.func as _torch_func

_m_t3759174 = nn.BatchNorm2d(5).eval()
_m_t3759182 = nn.ConvTranspose2d(5, 2, 3)
_m_t3759183 = nn.MaxPool2d(2)

torch.manual_seed(0)
t3759172 = torch.randn([3, 5, 14, 15])

def fn(x):
    x = _m_t3759174(x)
    x = _m_t3759182(x)
    x = _m_t3759183(x)
    return torch.softmax(x, dim=0).mean()

# All of these work fine:
_torch_func.grad(fn)(t3759172)                          # eager grad
torch.compile(_torch_func.grad(fn))(t3759172)           # static compile
torch.compile(fn, dynamic=True)(t3759172)               # dynamic, no grad

# This crashes:
torch.compile(_torch_func.grad(fn), dynamic=True)(t3759172)
