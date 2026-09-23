"""F.interpolate with a non-integer scale_factor: eager vs torch.compile (found via the binding-form rebind check)."""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)


def check(label, fn, *args, dyn=None):
    e = fn(*args)
    torch._dynamo.reset()
    try:
        c = torch.compile(fn, dynamic=dyn)(*args)
    except Exception as ex:  # noqa: BLE001
        inner = ex
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"[{label}] compiled raised {type(inner).__name__}: {str(inner)[:100]}")
        return
    if c.shape != e.shape:
        print(f"[{label}] SHAPE eager {tuple(e.shape)} vs compiled {tuple(c.shape)}")
        return
    err = (c.double() - e.double()).abs().max().item()
    print(f"[{label}] shape {tuple(e.shape)} max|diff|={err:.3g}" + ("   <-- DIFF" if err > 1e-5 else ""))


x = torch.randn(2, 3, 5)
for sf in (0.6, 1.15, 1.5, 2.3, 0.55):
    for rs in (None, True, False):
        check(f"1d nearest scale={sf} recompute={rs}",
              lambda x, _s=sf, _r=rs: F.interpolate(x, scale_factor=_s, mode="nearest", recompute_scale_factor=_r), x)
x2 = torch.randn(1, 2, 4, 6)
for mode in ("nearest", "nearest-exact", "bilinear", "bicubic"):
    for sf in (1.15, 2.3):
        check(f"2d {mode} scale={sf}", lambda x, _s=sf, _m=mode: F.interpolate(x, scale_factor=_s, mode=_m), x2)
check("1d nearest scale=1.15 dynamic=True",
      lambda x: F.interpolate(x, scale_factor=1.15, mode="nearest"), x, dyn=True)
check("1d nearest size=6 (same output size as 1.15)", lambda x: F.interpolate(x, size=6, mode="nearest"), x)
# print the actual index pattern so the report can state which side follows the documented formula
e = F.interpolate(torch.arange(5.0).view(1, 1, 5), scale_factor=1.15, mode="nearest")
torch._dynamo.reset()
c = torch.compile(lambda x: F.interpolate(x, scale_factor=1.15, mode="nearest"))(torch.arange(5.0).view(1, 1, 5))
print("source index used per output element, eager   :", e.flatten().tolist())
print("source index used per output element, compiled:", c.flatten().tolist())
