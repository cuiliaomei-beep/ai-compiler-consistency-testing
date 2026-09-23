# source: https://github.com/pytorch/pytorch/issues/170049
# title: `torch.compile` fails to capture user-defined kernels with latest Triton
# state: closed  created: 2025-12-10
# mined automatically; the harness records the torch.compile target and its first call

import torch
import triton
import triton.language as tl

@triton.jit
def _kernel(x_ptr, output_ptr, n_elements, BLOCK_SIZE: tl.constexpr):
    pid = tl.program_id(0)
    offsets = pid * BLOCK_SIZE + tl.arange(0, BLOCK_SIZE)
    mask = offsets < n_elements
    x = tl.load(x_ptr + offsets, mask=mask)
    tl.store(output_ptr + offsets, x, mask=mask)

def kernel(x):
    output = torch.empty_like(x)
    n_elements = x.numel()
    grid = lambda meta: (triton.cdiv(n_elements, meta['BLOCK_SIZE']),)
    _kernel[grid](x, output, n_elements, BLOCK_SIZE=1024)
    return output

x = torch.randn(1024, device='cuda')

compiled_fn = torch.compile(kernel)
result = compiled_fn(x)
print(result)
