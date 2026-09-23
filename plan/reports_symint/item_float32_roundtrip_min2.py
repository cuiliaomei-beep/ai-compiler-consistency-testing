import os, sys
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
    "(abs(v), full(abs(v)))  two .item() calls": lambda x: (abs(x.item()), torch.full((2,), abs(x.item()), **F64)),
    "(abs(v), full(abs(v)))  one .item() call": lambda x: (lambda v: (abs(v), torch.full((2,), abs(v), **F64)))(x.item()),
    "(v, full(v))": lambda x: (lambda v: (v, torch.full((2,), v, **F64)))(x.item()),
    "(abs(v), ones_f64 * 2)": lambda x: (abs(x.item()), torch.ones(2, **F64) * 2),
    "(v ** 2, full(v ** 2))": lambda x: (lambda v: (v ** 2, torch.full((2,), v ** 2, **F64)))(x.item()),
    "abs(v) only": lambda x: abs(x.item()),
}
for name, f in progs.items():
    for backend in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        x = torch.tensor(0.1, **F64)
        w, r = f(x), torch.compile(f, backend=backend)(x)
        show = lambda o: (o[0], o[1].tolist()) if isinstance(o, tuple) else o
        print("!!" if show(w) != show(r) else "  ", f"{name:44s} {backend:9s} eager {show(w)}  compiled {show(r)}")
