import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
torch._dynamo.config.capture_scalar_outputs = True
print("torch", torch.__version__)
progs = {
    "return abs(v)": lambda x: abs(x.item()),
    "return (abs(v), full((2,), abs(v), f64))": lambda x: (abs(x.item()), torch.full((2,), abs(x.item()), dtype=torch.float64)),
    "return (v * 3, full((2,), v * 3, f64))": lambda x: (x.item() * 3, torch.full((2,), x.item() * 3, dtype=torch.float64)),
    "full((2,), v, f64)": lambda x: torch.full((2,), x.item(), dtype=torch.float64),
    "full((2,), v * 3, f64)": lambda x: torch.full((2,), x.item() * 3, dtype=torch.float64),
    "y_f64 * v": lambda x: torch.ones(2, dtype=torch.float64) * x.item(),
    "y_f64 * (v * 3)": lambda x: torch.ones(2, dtype=torch.float64) * (x.item() * 3),
    "y_f64 + v ** 2": lambda x: torch.ones(2, dtype=torch.float64) + x.item() ** 2,
    "y_f64.clamp(max=v)": lambda x: torch.ones(2, dtype=torch.float64).clamp(max=x.item()),
    "y_f64 * int(v)": lambda x: torch.ones(2, dtype=torch.float64) * int(x.item() * 1e8),
}
def show(o):
    if isinstance(o, tuple): return "(" + ", ".join(show(t) for t in o) + ")"
    return repr(o.tolist() if isinstance(o, torch.Tensor) else o)
for name, f in progs.items():
    for backend, dyn in (("aot_eager", None), ("inductor", None), ("inductor", True)):
        torch._dynamo.reset()
        g = torch.compile(f, backend=backend, dynamic=dyn)
        bad = []
        for v in (0.5, 0.1, 4.35, 16777217.0):
            x = torch.tensor(v, dtype=torch.float64)
            w, r = show(f(x)), show(g(x))
            if w != r:
                bad.append(f"v={v}: eager {w} compiled {r}")
        print("!!" if bad else "  ", f"{name:42s} {backend:9s} dynamic={dyn}", " ; ".join(bad)[:230])
