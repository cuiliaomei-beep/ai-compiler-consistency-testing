import math, os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
torch._dynamo.config.capture_scalar_outputs = True
print("torch", torch.__version__)
progs = {
    "u != u  (returned)": lambda loss: (lambda u: u != u)(loss.item()),
    "u == u  (returned)": lambda loss: (lambda u: u == u)(loss.item()),
    "math.isnan(u)": lambda loss: math.isnan(loss.item()),
    "skip step if u != u": lambda loss: (lambda u: torch.zeros(2) if u != u else torch.full((2,), 1.0))(loss.item()),
    "x * (u == u)": lambda loss: torch.ones(2) * (loss.item() == loss.item()),
    "u < u or u >= u": lambda loss: (lambda u: u >= u)(loss.item()),
    "max(u, 0.0)": lambda loss: max(loss.item(), 0.0),
    "min(u, 0.0)": lambda loss: min(loss.item(), 0.0),
    "u - u": lambda loss: loss.item() - loss.item(),
    "u * 0": lambda loss: loss.item() * 0,
    "u / u": lambda loss: (lambda u: u / u)(loss.item() + 1.0),
}
for name, f in progs.items():
    for backend in ("eager", "aot_eager", "inductor"):
        outs = []
        for dyn in (None,):
            torch._dynamo.reset()
            g = torch.compile(f, backend=backend)
            row = []
            for v in (1.0, float("nan"), float("inf")):
                t = torch.tensor(v, dtype=torch.float64)
                try:
                    w = f(t); r = g(t)
                    w, r = [x.tolist() if isinstance(x, torch.Tensor) else x for x in (w, r)]
                    same = (w == r) or (isinstance(w, float) and isinstance(r, float) and w != w and r != r)
                    row.append("ok" if same else f"in={v}: python {w} compiled {r}")
                except Exception as e:
                    row.append(f"in={v}: raises {type(e).__name__}")
        bad = [x for x in row if x != "ok"]
        print("!!" if bad else "  ", f"{name:24s} {backend:10s}", "; ".join(bad))
