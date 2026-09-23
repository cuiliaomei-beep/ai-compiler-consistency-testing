"""float16 tensors on CPU: Inductor's C++ kernels load at::Half, convert to float, do the whole fused chain in float and
convert back only on store.  Consequences checked here, with and without `emulate_precision_casts`:
  * an intermediate that overflows float16 is inf in eager and finite in the compiled chain ((x*x)/x -> 300 instead of inf)
  * within ONE call the returned y = x*x is inf while the returned isinf(y) is False (CSE reuses the float product)
Related: #183607 (open, explicit .to(float16) variant), #185337, PR #195223 (closed, comparisons only)."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_half_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch
import torch._inductor.config as ic

print("torch", torch.__version__, "cuda", torch.cuda.is_available())


def f(x):
    y = x * x
    return y, y / x, torch.isinf(y), torch.where(torch.isinf(y), torch.zeros_like(y), y)


def g(x):                      # the #183607 shape: explicit cast
    y = x.to(torch.float16)
    return (y * y).to(torch.float32)


for dev in ["cpu"] + (["cuda"] if torch.cuda.is_available() else []):
    x = torch.full((40,), 300.0, dtype=torch.float16, device=dev)
    x32 = torch.full((40,), 5000.0, device=dev)
    print(f"[{dev}] eager                          ", [o[0].item() for o in f(x)], "| cast variant", g(x32)[0].item())
    for emu in (False, True):
        torch._dynamo.reset()
        with ic.patch(emulate_precision_casts=emu):
            out = torch.compile(f)(x)
            torch._dynamo.reset()
            out2 = torch.compile(g)(x32)
        print(f"[{dev}] compiled emulate_precision_casts={emu!s:5s}", [o[0].item() for o in out], "| cast variant", out2[0].item())
