import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
x = torch.tensor([5, 1, 200, 3, 7, 8, 9, 13, 100, 254, 255, 2, 6, 4, 11, 12, 90, 80], dtype=torch.uint8)
for n in (15, 16, 18):
    for name, fn in (("argmin", torch.argmin), ("argmax", torch.argmax), ("min", torch.min), ("max", torch.max)):
        torch._dynamo.reset()
        e = fn(x[:n]).item(); c = torch.compile(fn)(x[:n].clone()).item()
        print(f"n={n:2d} {name:6s} eager={e:4d} inductor={c:4d} {'' if e == c else '   <-- differs'}")
y = x.reshape(2, 9).repeat(1, 2)          # (2, 18): vectorised inner reduction
torch._dynamo.reset()
print("argmin(dim=1) eager", torch.argmin(y, 1).tolist(), "inductor", torch.compile(lambda t: torch.argmin(t, 1))(y).tolist())
torch._dynamo.reset()
print("argmax(dim=1) eager", torch.argmax(y, 1).tolist(), "inductor", torch.compile(lambda t: torch.argmax(t, 1))(y).tolist())
torch._dynamo.reset()
print("min(dim=1).indices eager", torch.min(y, 1).indices.tolist(), "inductor", torch.compile(lambda t: torch.min(t, 1).indices)(y).tolist())
