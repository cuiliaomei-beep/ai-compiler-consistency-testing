"""unary sweep leads: abs(complex, out=real of other dtype) and nan_to_num(complex) under compile."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
z = torch.complex(torch.rand(3, 4) + 0.5, torch.rand(3, 4))
zn = z.clone(); zn[0, 0] = complex(float("nan"), 1.0); zn[0, 1] = complex(1.0, float("inf"))
CASES = {
    "abs(complex64, out=float64)": (lambda a: torch.abs(a, out=torch.empty(0, dtype=torch.float64)), z),
    "abs(complex64, out=bfloat16)": (lambda a: torch.abs(a, out=torch.empty(0, dtype=torch.bfloat16)), z),
    "abs(complex64, out=float32)": (lambda a: torch.abs(a, out=torch.empty(0, dtype=torch.float32)), z),
    "abs(float32, out=float64)": (lambda a: torch.abs(a, out=torch.empty(0, dtype=torch.float64)), z.real.clone()),
    "angle(complex64, out=float64)": (lambda a: torch.angle(a, out=torch.empty(0, dtype=torch.float64)), z),
    "nan_to_num(complex64)": (torch.nan_to_num, zn),
    "nan_to_num(complex64, nan=0.5)": (lambda a: torch.nan_to_num(a, nan=0.5), zn),
    "nan_to_num(complex64 no nan)": (torch.nan_to_num, z),
    "nan_to_num(float32)": (torch.nan_to_num, zn.real.clone()),
}
for name, (fn, arg) in CASES.items():
    try:
        e = fn(arg); es = f"{str(e.dtype).split('.')[-1]}{tuple(e.shape)}"
    except Exception as ex:
        es = f"raise {type(ex).__name__}"
    out = []
    for b in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            c = torch.compile(fn, backend=b)(arg); cs = f"{str(c.dtype).split('.')[-1]}{tuple(c.shape)}"
            if not es.startswith("raise") and not torch.equal(torch.isnan(c.to(e.dtype)) if e.is_floating_point() else c.to(e.dtype), torch.isnan(e) if e.is_floating_point() else e):
                cs += " VALUE-DIFF"
        except Exception as ex:
            lines = [l.strip() for l in str(ex).splitlines() if l.strip()]
            key = next((l for l in lines if "Error" in l and "raised" not in l and "BackendCompilerFailed" not in l and "TorchRuntimeError" not in l), lines[0])
            cs = f"raise {type(ex).__name__}: {key[:110]}"
        out.append(f"{b}={cs}")
    print(f"[{name}] eager={es} | " + " | ".join(out))
