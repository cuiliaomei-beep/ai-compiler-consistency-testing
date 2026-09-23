import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
pos = torch.tensor([5, 1, 100, 3, 7, 8, 9, 13, 100, 120, 127, 2, 6, 4, 11, 12, 90, 80])
for dt in (torch.uint8, torch.int8, torch.int16, torch.int32, torch.int64):
    for sign, data in (("all > 0", pos), ("all < 0", -pos)):
        if dt == torch.uint8 and sign == "all < 0":
            continue
        x = data.to(dt)
        for name, fn in (("min", torch.min), ("max", torch.max), ("argmin", torch.argmin), ("argmax", torch.argmax), ("amin", torch.amin), ("amax", torch.amax)):
            for n in (15, 16, 18):
                torch._dynamo.reset()
                e, c = fn(x[:n]).item(), torch.compile(fn)(x[:n].clone()).item()
                if e != c:
                    print(f"{str(dt).split('.')[-1]:6s} {sign} n={n:2d} {name:6s} eager={e:5d} inductor={c:5d}")
print("done")
