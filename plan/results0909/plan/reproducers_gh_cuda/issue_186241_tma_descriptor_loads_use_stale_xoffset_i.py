# source: https://github.com/pytorch/pytorch/issues/186241
# title: TMA descriptor loads use stale `xoffset` in mix-order reduction loop
# state: closed  created: 2026-06-04
# mined automatically; the harness records the torch.compile target and its first call

import os
os.environ["CUDA_LAUNCH_BLOCKING"] = "1"

import torch
import torch._inductor.config as inductor_config
from torch._dynamo.utils import same

inductor_config.triton.use_tensor_descriptor = True
inductor_config.assume_aligned_inputs = True

def f(x, w, eps):
    orig_dtype = x.dtype
    x = x.float()
    rsqrt = torch.rsqrt((x * x).sum(dim=-1) / x.shape[-1] + eps)
    return (x * rsqrt[:, None] * w).to(dtype=orig_dtype)

torch.manual_seed(1337)
M, N = 1000000, 256
x = torch.randn(M, N, dtype=torch.bfloat16, device='cuda', requires_grad=True)
w = torch.randn(N, dtype=torch.bfloat16, device='cuda', requires_grad=True)
dy = torch.randn_like(x)

opt_f = torch.compile(f, options={'split_reductions': False})

out = f(x, w, 1e-5); out.backward(dy)
ref = (x.grad.clone(), w.grad.clone())
x.grad = w.grad = None

out = opt_f(x, w, 1e-5); out.backward(dy)
act = (x.grad.clone(), w.grad.clone())
assert same(ref, act, tol=1e-2), "Wrong result or crash"
