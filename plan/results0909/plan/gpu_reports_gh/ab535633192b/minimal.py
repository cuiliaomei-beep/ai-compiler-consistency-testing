import torch
torch.manual_seed(0)

def fn(q: torch.Tensor) -> torch.Tensor:
    h, s2 = gn(q)
    # ``torch.full`` reaches ``tensor_constructor.inner``; ``s2`` is wrapped
    # as ``ShapeAsConstantBuffer(expr=2*s)`` at the HOP boundary, and
    # ``sympy.expand`` on that IR node raises ``SympifyError``.
    scratch = torch.full((s2, 8, 288), 0.0, dtype=h.dtype, device=h.device)
    return h.sum() + scratch.sum() * 0.0

args = (torch.randn(128, 64).requires_grad_(True),)

eager = fn(*args)
torch._dynamo.reset()
compiled = torch.compile(fn, backend='eager')(*args)
print('eager   :', eager)
print('compiled:', compiled)
