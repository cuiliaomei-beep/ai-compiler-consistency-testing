# source: https://github.com/pytorch/pytorch/issues/184247
# title: [Inductor] Incorrect epilogue fusion for user-defined Triton kernels when output has layout-changing ops (`.T.contiguous()`)
# state: closed  created: 2026-05-18
# mined automatically; the harness records the torch.compile target and its first call

import torch

import triton 
import triton.language as tl

torch._inductor.config.epilogue_fusion_user_defined_triton_kernel = True

@triton.jit
def add_kernel(in_ptr0, in_ptr1, out_ptr, n_elements, BLOCK_SIZE: tl.constexpr):
    pid = tl.program_id(0)
    offs = pid * BLOCK_SIZE + tl.arange(0, BLOCK_SIZE)
    mask = offs < n_elements
    x = tl.load(in_ptr0 + offs, mask=mask)
    y = tl.load(in_ptr1 + offs, mask=mask)
    tl.store(out_ptr + offs, x + y, mask=mask)


def fn(a, b):
    out = torch.empty_like(a)
    grid = (triton.cdiv(a.numel(), 1024),)
    add_kernel[grid](a, b, out, a.numel(), BLOCK_SIZE=1024)
    return out.T.contiguous()

a = torch.randn(32, 32, device="cuda").double()
b = torch.randn(32, 32, device="cuda").double()

fn_compiled = torch.compile(fn)
torch.testing.assert_close(fn_compiled(a, b), fn(a, b))
