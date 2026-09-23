"""Gradient of complex torch.linalg.lstsq under a forwarding TorchDispatchMode / under torch.compile vs eager and a
complex128 reference.  The forward is right under the mode; the C++ backward (linalg_lstsq_backward, which uses pinv and
.mH internally) is not -- the same mechanism as #198118."""
import torch
from torch.utils._python_dispatch import TorchDispatchMode

print("torch", torch.__version__)


class Forward(TorchDispatchMode):
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))


def loss(A, B):
    return (torch.linalg.lstsq(A, B).solution.abs() ** 2).sum()


def grad(fn, A, B, mode=None):
    A = A.detach().clone().requires_grad_(); B = B.detach().clone().requires_grad_()
    if mode is None:
        fn(A, B).backward()
    else:
        with mode:
            fn(A, B).backward()
    return A.grad, B.grad


torch.manual_seed(0)
for dt in (torch.complex64, torch.complex128, torch.float64):
    A = torch.randn(5, 3, dtype=dt); B = torch.randn(5, 2, dtype=dt)
    ref = grad(loss, A.to(torch.complex128) if dt.is_complex else A, B.to(torch.complex128) if dt.is_complex else B)
    e = grad(loss, A, B); m = grad(loss, A, B, Forward())
    torch._dynamo.reset()
    c = grad(torch.compile(loss, backend="aot_eager"), A, B)
    with Forward():
        fwd_mode = torch.linalg.lstsq(A, B).solution
    print(f"{str(dt):16s} forward under mode == eager: {torch.allclose(fwd_mode, torch.linalg.lstsq(A, B).solution, atol=1e-5)}")
    for name, g in (("eager", e), ("under mode", m), ("compiled aot_eager", c)):
        print(f"    {name:20s} |dA - ref| {(g[0].to(ref[0].dtype) - ref[0]).abs().max().item():.3g}   |dB - ref| {(g[1].to(ref[1].dtype) - ref[1]).abs().max().item():.3g}")
    print(f"    under mode == compiled: {torch.allclose(m[0], c[0]) and torch.allclose(m[1], c[1])}")
