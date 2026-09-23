"""Does the MSVC blendv/cmp-LE fold (0920issues/18) surface through Inductor on Windows?"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
import torch._inductor.config as cfg
print("torch", torch.__version__)
progs = {"where(x <= y, y, x)": lambda x, y: torch.where(x <= y, y, x), "where(x <= y, x, y)": lambda x, y: torch.where(x <= y, x, y),
         "where(x >= y, y, x)": lambda x, y: torch.where(x >= y, y, x), "where(x < y, y, x)": lambda x, y: torch.where(x < y, y, x)}
for simd in (256, 512):
    cfg.cpp.simdlen = simd
    for dt in (torch.float32, torch.float64):
        x = torch.tensor([0.0, -0.0] * 16, dtype=dt); y = torch.tensor([-0.0, 0.0] * 16, dtype=dt)
        for name, f in progs.items():
            torch._dynamo.reset()
            e, c = f(x, y), torch.compile(f)(x, y)
            same = torch.equal(torch.signbit(e), torch.signbit(c))
            print(f"simdlen={simd} {str(dt):14s} {name:22s} sign bits equal: {same}   eager {e[:2].tolist()} compiled {c[:2].tolist()}")
