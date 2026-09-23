# source: https://github.com/pytorch/pytorch/issues/182275
# title: [inductor] SympifyError: cannot sympify ShapeAsConstantBuffer when nested_compile_region returns SymInt consumed by torch.full
# state: closed  created: 2026-05-04
# mined automatically; the harness records the torch.compile target and its first call

# python repro.py
import torch
from torch.compiler import nested_compile_region


@nested_compile_region
def gn(q: torch.Tensor):
    # Return both a tensor and a SymInt -- the SymInt is the trigger.
    return q.sin().cos() * 2.0, q.shape[0] * 2


@torch.compile(fullgraph=True, dynamic=True)
def fn(q: torch.Tensor) -> torch.Tensor:
    h, s2 = gn(q)
    # ``torch.full`` reaches ``tensor_constructor.inner``; ``s2`` is wrapped
    # as ``ShapeAsConstantBuffer(expr=2*s)`` at the HOP boundary, and
    # ``sympy.expand`` on that IR node raises ``SympifyError``.
    scratch = torch.full((s2, 8, 288), 0.0, dtype=h.dtype, device=h.device)
    return h.sum() + scratch.sum() * 0.0


q = torch.randn(128, 64, device="cuda", requires_grad=True)
torch._dynamo.mark_dynamic(q, 0)
loss = fn(q)
loss.backward()
