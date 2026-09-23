"""torch.linalg.pinv: gradient w.r.t. a complex input is wrong under torch.compile (aot_eager and inductor), right in eager."""
import torch
print("torch", torch.__version__)
torch.manual_seed(0)


def loss(a):
    return (torch.linalg.pinv(a).abs() ** 2).sum()


def grad(fn, a):
    a = a.detach().clone().requires_grad_()
    fn(a).backward()
    return a.grad


for dtype in (torch.float32, torch.complex64):
    a = torch.randn(4, 3, dtype=dtype)
    truth = grad(loss, a.to(torch.complex128 if dtype.is_complex else torch.float64))
    g_eager = grad(loss, a)
    torch._dynamo.reset()
    g_aot = grad(torch.compile(loss, backend="aot_eager"), a)
    torch._dynamo.reset()
    g_ind = grad(torch.compile(loss), a)
    err = lambda g: (g.to(truth.dtype) - truth).abs().max().item()
    print(f"{str(dtype).split('.')[-1]:>9}: eager err {err(g_eager):.1e} | aot_eager err {err(g_aot):.1e} | inductor err {err(g_ind):.1e}")
    if dtype.is_complex:
        print("   eager grad[0]   :", g_eager[0].tolist())
        print("   compiled grad[0]:", g_ind[0].tolist())
        print("   truth grad[0]   :", [complex(round(c.real, 5), round(c.imag, 5)) for c in truth[0].tolist()])
# double-check via torch.autograd.gradcheck-style finite differences on the compiled function
a = torch.randn(4, 3, dtype=torch.complex128)
torch._dynamo.reset()
try:
    ok = torch.autograd.gradcheck(torch.compile(loss, backend="aot_eager"), (a.requires_grad_(),), eps=1e-6, atol=1e-4, raise_exception=False)
    print("gradcheck(compiled pinv loss, complex128):", ok, "| eager:", torch.autograd.gradcheck(loss, (a,), eps=1e-6, atol=1e-4, raise_exception=False))
except Exception as e:
    print("gradcheck raised", type(e).__name__, str(e)[:100])
