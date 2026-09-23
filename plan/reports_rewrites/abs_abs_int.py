import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
progs = {"abs": lambda t: t.abs(), "abs.abs": lambda t: t.abs().abs(), "abs+0 .abs": lambda t: (t.abs() + 1).abs(),
         "abs.neg": lambda t: -t.abs(), "abs.abs.abs": lambda t: t.abs().abs().abs(), "abs.relu": lambda t: t.abs().relu(),
         "abs.sign": lambda t: t.abs().sign(), "abs(x)*abs(x)": lambda t: t.abs() * t.abs(), "abs.float": lambda t: t.abs().float()}
for dt in (torch.int8, torch.int16, torch.int32, torch.int64, torch.float32):
    for n in (5, 40):
        x = (torch.arange(n) - n // 2).to(dt)
        for name, f in progs.items():
            torch._dynamo.reset()
            e, c = f(x), torch.compile(f)(x)
            if not torch.equal(e, c):
                bad = (e != c).nonzero().flatten().tolist()
                print(f"DIFF {str(dt):14s} n={n:3d} {name:14s} #bad={len(bad)} first: x={x[bad[0]].item()} eager={e[bad[0]].item()} compiled={c[bad[0]].item()}")
print("done")
