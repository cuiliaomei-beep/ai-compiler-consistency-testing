# source: https://github.com/pytorch/pytorch/issues/128202
# title: Wrong result for Inplace tensor update on transpose for some devices with torch 2.3.0
# state: closed  created: 2024-06-07
# mined automatically; the harness records the torch.compile target and its first call

import torch
import habana_frameworks.torch.core as htcore

def fn(a):
 b = a.t()
 b.mul_(1.0)
 return b   

x = torch.arange(6).reshape([2, 3]).to('hpu')

print("x ", x.cpu())

compiled_fn = torch.compile(fn, backend="hpu_backend")        
y = compiled_fn(x)

print("y ", y.cpu())
