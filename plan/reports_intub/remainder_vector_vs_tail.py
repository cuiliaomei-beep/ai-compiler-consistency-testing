import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
INF = float("inf")
a = torch.tensor([5.5, -5.5, 0.0, 1e20, 2147483648.0, 7.0, 1.0, -0.0])
b = torch.tensor([INF, -INF, INF, 3.0, 3.0, 0.7, 0.1, 1.0])
for name, fn in (("remainder", torch.remainder), ("a % b", lambda a, b: a % b), ("floor_divide", torch.floor_divide), ("fmod", torch.fmod)):
    for reps in (1, 2, 3):
        x, y = a.repeat(reps), b.repeat(reps)
        torch._dynamo.reset()
        c = torch.compile(fn)(x, y)[:8].tolist()
        e = fn(x, y)[:8].tolist()
        print(f"{name:12s} n={8 * reps:2d} inductor {c}")
    print(f"{'':12s}      eager    {e}")
