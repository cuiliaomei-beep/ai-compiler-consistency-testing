# source: https://github.com/pytorch/pytorch/issues/177451
# title: torch.compile fails on conv2d with kernel size larger than input size, while meta device succeeds
# state: closed  created: 2026-03-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.nn.functional as F

input_tensor = torch.randn(2,4,5,5)
weight_tensor = torch.randn(6,4,3,3)

bias = None
stride = 3
padding = 0
dilation = [2, 3]
groups = 1

def conv_func(input, weight):
  return F.conv2d(input, weight, bias=bias, stride=stride, padding=padding, dilation=dilation, groups=groups)

try:
  eager_shape = conv_func(input_tensor, weight_tensor).shape
  print(eager_shape)
except Exception as e:
  print(e)

try:
  compiled_conv = torch.compile(conv_func, dynamic=True)
  symbolic_shape = compiled_conv(input_tensor, weight_tensor).shape
  print(symbolic_shape)
except Exception as e:
  print(e)

try:
  input_meta = input_tensor.to('meta')
  weight_meta = weight_tensor.to('meta')
  with torch.device('meta'):
    meta_shape = conv_func(input_meta, weight_meta).shape
  print(meta_shape)
except Exception as e:
  print(e)
