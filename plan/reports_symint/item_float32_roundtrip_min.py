import math, os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
torch._dynamo.config.capture_scalar_outputs = True
print("torch", torch.__version__)
F64 = dict(dtype=torch.float64)
progs = {
    "full((2,), abs(v), f64)": lambda x: torch.full((2,), abs(x.item()), **F64),
    "full((2,), v ** 2, f64)": lambda x: torch.full((2,), x.item() ** 2, **F64),
    "full((2,), v ** 0.5, f64)": lambda x: torch.full((2,), abs(x.item()) ** 0.5, **F64),
    "full((2,), math.sqrt(v), f64)": lambda x: torch.full((2,), math.sqrt(abs(x.item())), **F64),
    "full((2,), math.sin(v), f64)": lambda x: torch.full((2,), math.sin(x.item()), **F64),
    "full((2,), -v, f64)": lambda x: torch.full((2,), -x.item(), **F64),
    "full((2,), v + 1, f64)": lambda x: torch.full((2,), x.item() + 1, **F64),
    "full((2,), max(v, 0.05), f64)": lambda x: torch.full((2,), max(x.item(), 0.05), **F64),
    "full((2,), round(v, 3), f64)": lambda x: torch.full((2,), round(x.item(), 3), **F64),
    "ones_f64 * abs(v)": lambda x: torch.ones(2, **F64) * abs(x.item()),
    "ones_f64 * v ** 2": lambda x: torch.ones(2, **F64) * x.item() ** 2,
    "ones_f64 + math.sqrt(v)": lambda x: torch.ones(2, **F64) + math.sqrt(abs(x.item())),
    "ones_f64.clamp(max=abs(v))": lambda x: torch.ones(2, **F64).clamp(max=abs(x.item())),
    "ones_f64 * abs(y_f64.sum().item())": lambda x: torch.ones(2, **F64) * abs((x * 1).sum().item()),
}
for name, f in progs.items():
    row = []
    for backend in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        g = torch.compile(f, backend=backend)
        x = torch.tensor(0.1, **F64)
        w, r = f(x)[0].item(), g(x)[0].item()
        row.append(f"{backend}: {'ok' if w == r else 'eager %r compiled %r' % (w, r)}")
    print("!!" if "compiled" in " ".join(row) else "  ", f"{name:38s}", " | ".join(row))
