import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
p = torch.tensor([1.0, 2.0, 3.0])
progs = {
    "e.mul_(d).add_(p, alpha=1-d)": lambda e, d: e.mul_(d).add_(p, alpha=1 - d),
    "e*d + p*(1-d)   (functional)": lambda e, d: e * d + p * (1 - d),
    "torch.add(e*d, p, alpha=1-d)": lambda e, d: torch.add(e * d, p, alpha=1 - d),
    "torch.add(e, p, alpha=d)": lambda e, d: torch.add(e, p, alpha=d),
    "torch.add(e, p, alpha=1-d)": lambda e, d: torch.add(e, p, alpha=1 - d),
    "torch.add(e, p, alpha=d*2)": lambda e, d: torch.add(e, p, alpha=d * 2),
    "e + p*(1-d)": lambda e, d: e + p * (1 - d),
    "torch.lerp(p, e, d)": lambda e, d: torch.lerp(p, e, d),
    "torch.sub(e, p, alpha=1-d)": lambda e, d: torch.sub(e, p, alpha=1 - d),
    "torch.addcmul(e, p, p, value=1-d)": lambda e, d: torch.addcmul(e, p, p, value=1 - d),
    "e.add_(p, alpha=1-d)": lambda e, d: e.add_(p, alpha=1 - d),
    "e.mul_(1-d)": lambda e, d: e.mul_(1 - d),
}
for name, f in progs.items():
    for backend in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        cf = torch.compile(f, backend=backend)
        bad = []
        for d in (0.9, 0.5, 0.25, 0.75):
            want = f(torch.ones(3), d).tolist(); got = cf(torch.ones(3), d).tolist()
            if max(abs(a - b) for a, b in zip(want, got)) > 1e-6:
                bad.append((d, [round(v, 4) for v in want], [round(v, 4) for v in got]))
        print("!!" if bad else "  ", f"{name:36s} {backend:10s}", bad[:2])
