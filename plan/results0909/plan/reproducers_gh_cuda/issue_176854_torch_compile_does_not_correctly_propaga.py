# source: https://github.com/pytorch/pytorch/issues/176854
# title: torch.compile does not correctly propagate detach_() in-place autograd semantics
# state: closed  created: 2026-03-09
# mined automatically; the harness records the torch.compile target and its first call

import torch

def test_detach_inplace_autograd():
    def fn(x):
        y = x * 2.0
        y.detach_()
        z = y + 1.0
        return z, y.requires_grad

    x = torch.randn(4, requires_grad=True)
    z_e, rg_e = fn(x)
    z_c, rg_c = torch.compile(fn, backend="eager")(x)
    assert rg_e == rg_c, f"requires_grad: {rg_e} vs {rg_c}"
    assert torch.allclose(z_e, z_c)

t = test_detach_inplace_autograd
try:
    t()
    print(f"PASSED: {t.__name__}")
except Exception as e:
    print(f"FAILED: {t.__name__}: {e}")
