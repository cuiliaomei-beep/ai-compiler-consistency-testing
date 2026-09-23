import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__, "| python: 1.0 // 0.1 =", 1.0 // 0.1, " 1.0 % 0.1 =", 1.0 % 0.1)
for dt in (torch.float32, torch.float64):
    a = torch.tensor([1.0, 0.5, 1.0, 6.0, 5.5, 1e20], dtype=dt)
    b = torch.tensor([0.1, 0.1, 1 / 3, 0.2, float("inf"), 3.0], dtype=dt)
    for name, fn in (("a // b", lambda a, b: a // b), ("a % b", lambda a, b: a % b),
                     ("div(floor)", lambda a, b: torch.div(a, b, rounding_mode="floor"))):
        torch._dynamo.reset()
        e = fn(a, b).tolist(); c = torch.compile(fn)(a, b).tolist()
        print(f"{str(dt).split('.')[-1]:8s} {name:11s} eager    {e}\n{'':21s}inductor {c}")
x = torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8)
for name, fn in (("clamp(int8, -1000, 1000)", lambda t: torch.clamp(t, -1000, 1000)), ("clamp(int8, max=300)", lambda t: torch.clamp(t, max=300)),
                 ("clamp(uint8, -2, 5)", lambda t: torch.clamp(t.to(torch.uint8), -2, 5)), ("clamp(int16, -70000, 70000)", lambda t: torch.clamp(t.to(torch.int16), -70000, 70000))):
    out = []
    for b in (None, "inductor"):
        torch._dynamo.reset()
        try:
            out.append(str((fn if b is None else torch.compile(fn))(x.clone()).tolist()))
        except Exception as e:
            out.append("raises " + type(e).__name__ + ": " + str(e).splitlines()[0][:60])
    print(f"{name:28s} eager {out[0]} | inductor {out[1]}")
