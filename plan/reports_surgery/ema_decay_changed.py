import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)

def run(backend, decays):
    torch._dynamo.reset()
    p = torch.tensor([1.0, 2.0, 3.0]); ema = torch.zeros(3)
    def upd(decay):
        with torch.no_grad():
            ema.mul_(decay).add_(p, alpha=1 - decay)
    f = upd if backend is None else torch.compile(upd, backend=backend)
    hist = []
    for d in decays:
        f(d); hist.append([round(v, 4) for v in ema.tolist()])
    return hist

for decays in ([0.9, 0.9, 0.5, 1.0, 0.0], [0.5, 0.0], [0.0], [1.0, 0.0], [0.5, 1.0], [0.9, 0.5, 0.25]):
    e = run(None, decays)
    for b in ("eager", "aot_eager", "inductor"):
        c = run(b, decays)
        flag = "  " if c == e else "!!"
        print(flag, decays, b, "eager", e[-1], "compiled", c[-1], "" if c == e else f"first differing step {[i for i, (x, y) in enumerate(zip(e, c)) if x != y][0]}")
