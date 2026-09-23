"""Gradients of complex linalg ops: eager vs torch.compile (aot_eager / inductor) vs complex128 truth."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
torch._dynamo.config.recompile_limit = 1000
OPS = {
    "pinv": torch.linalg.pinv,
    "pinv_hermitian": lambda a: torch.linalg.pinv(a @ a.mH, hermitian=True),
    "inv": lambda a: torch.linalg.inv(a @ a.mH + torch.eye(a.shape[0], dtype=a.dtype)),
    "solve": lambda a: torch.linalg.solve(a @ a.mH + torch.eye(a.shape[0], dtype=a.dtype), a),
    "svdvals": torch.linalg.svdvals,
    "svd_U_abs": lambda a: torch.linalg.svd(a, full_matrices=False)[0].abs(),
    "qr_R": lambda a: torch.linalg.qr(a)[1],
    "eigvalsh": lambda a: torch.linalg.eigvalsh(a @ a.mH),
    "matrix_norm_fro": lambda a: torch.linalg.matrix_norm(a),
    "matrix_norm_nuc": lambda a: torch.linalg.matrix_norm(a, "nuc"),
    "det": lambda a: torch.linalg.det(a @ a.mH + torch.eye(a.shape[0], dtype=a.dtype)),
    "lstsq": lambda a: torch.linalg.lstsq(a, a[:, :1]).solution,
    "matrix_exp": lambda a: torch.linalg.matrix_exp(a[:2, :2] * 0.1),
    "cholesky": lambda a: torch.linalg.cholesky(a @ a.mH + torch.eye(a.shape[0], dtype=a.dtype)),
    "mm_conj": lambda a: (a @ a.mH),
    "abs_sum": lambda a: a.abs().sum(),
}


def grad_of(fn, a):
    a = a.detach().clone().requires_grad_()
    out = fn(a)
    (out.abs() ** 2).sum().backward()
    return a.grad


g = torch.Generator().manual_seed(0)
for name, fn in OPS.items():
    for dt in (torch.float32, torch.complex64):
        shape = (4, 3)
        base = torch.randn(shape, generator=g)
        a = (torch.complex(base, torch.randn(shape, generator=g)) if dt.is_complex else base).to(dt)
        try:
            truth = grad_of(fn, a.to(torch.complex128 if dt.is_complex else torch.float64))
            ge = grad_of(fn, a)
        except Exception as ex:
            print(f"[{name} {str(dt).split('.')[-1]}] eager raises {type(ex).__name__}: {str(ex)[:60]}"); continue
        res = []
        for b in ("aot_eager", "inductor"):
            torch._dynamo.reset()
            try:
                gc = grad_of(torch.compile(fn, backend=b), a)
                ee = (ge.to(truth.dtype) - truth).abs().max().item(); ec = (gc.to(truth.dtype) - truth).abs().max().item()
                res.append(f"{b}: err {ec:.1e}" + ("  <-- DIFF" if ec > max(4 * ee, 1e-4) else ""))
            except Exception as ex:
                res.append(f"{b}: raise {type(ex).__name__}: {str(ex).splitlines()[0][:70]}")
        ee = (ge.to(truth.dtype) - truth).abs().max().item()
        print(f"[{name} {str(dt).split('.')[-1]}] eager err {ee:.1e} | " + " | ".join(res))
