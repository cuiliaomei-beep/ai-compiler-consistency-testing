"""Inductor CPU vector path: acosh overflows to inf for large float64 (formula log(x + sqrt(x*x - 1))), erfinv loses
3-4 digits near +-1.  Both depend on tensor length (>= 16/32 elements take the vector path; short tails are right)."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_ve_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import math, torch

print("torch", torch.__version__)
try:
    from mpmath import mp, erfinv as mp_erfinv
    mp.dps = 30
    ref = lambda v: float(mp_erfinv(mp.mpf(v)))
except ImportError:
    ref = None
for dt in (torch.float64, torch.float32):
    for n in (3, 8, 16, 32, 64):
        x = torch.full((n,), 1e200 if dt == torch.float64 else 3e38, dtype=dt)
        torch._dynamo.reset()
        print(f"acosh  {str(dt):14s} n={n:2d} eager {torch.acosh(x)[0].item():.6g}  compiled {torch.compile(torch.acosh)(x)[0].item():.6g}")
for dt, v in ((torch.float32, 0.99999994), (torch.float32, 0.9999), (torch.float32, 0.999), (torch.float32, 0.99), (torch.float64, 1 - 1e-16), (torch.float64, 1 - 1e-12), (torch.float64, 0.9999), (torch.float64, 0.99)):
    for n in (3, 64):
        x = torch.full((n,), v, dtype=dt)
        torch._dynamo.reset()
        e = torch.erfinv(x)[0].item(); c = torch.compile(torch.erfinv)(x)[0].item()
        r = ref(float(x[0].item())) if ref else float("nan")
        print(f"erfinv {str(dt):14s} x={x[0].item()!r:22} n={n:2d} eager {e:.9g}  compiled {c:.9g}  mpmath {r:.9g}  rel err eager {abs(e - r) / r:.2e} compiled {abs(c - r) / r:.2e}")
