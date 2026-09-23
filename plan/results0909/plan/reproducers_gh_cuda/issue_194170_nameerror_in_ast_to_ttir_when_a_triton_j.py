# source: https://github.com/pytorch/pytorch/issues/194170
# title: NameError in ast_to_ttir when a triton.jit function is called through a module-level binding whose name differs from its def name (inductor user_defined_triton_kernel_transitive_closure_source_code)
# state: open  created: 2026-08-20
# mined automatically; the harness records the torch.compile target and its first call

import torch, triton, triton.language as tl
from torch.library import triton_op, wrap_triton

def _fwd_body(x_ptr, o_ptr, N: tl.constexpr, BLOCK: tl.constexpr):
    pid = tl.program_id(0)
    offs = pid * BLOCK + tl.arange(0, BLOCK)
    tl.store(o_ptr + offs, tl.load(x_ptr + offs) * 2.0, mask=offs < N)

helper = triton.jit(_fwd_body)          # bound under a DIFFERENT name than the def

@triton.jit
def outer(x_ptr, o_ptr, N: tl.constexpr, BLOCK: tl.constexpr):
    helper(x_ptr, o_ptr, N, BLOCK)      # calls the binding name

@triton_op("repro::double", mutates_args=())
def double(x: torch.Tensor) -> torch.Tensor:
    out = torch.empty_like(x)
    wrap_triton(outer)[(triton.cdiv(x.numel(), 128),)](x, out, x.numel(), BLOCK=128)
    return out

x = torch.randn(1024, device="cuda")
double(x)                                # eager: works
torch.compile(lambda t: double(t))(x)    # NameError: '_fwd_body' is not defined
