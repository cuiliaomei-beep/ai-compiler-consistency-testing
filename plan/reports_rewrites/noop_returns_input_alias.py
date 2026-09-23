import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
print("torch", torch.__version__)
progs = {
    "x + 0": lambda x: x + 0, "x + 0.0": lambda x: x + 0.0, "0 + x": lambda x: 0 + x, "x - 0": lambda x: x - 0, "x * 1": lambda x: x * 1,
    "x * 1.0": lambda x: x * 1.0, "x / 1": lambda x: x / 1, "x ** 1": lambda x: x ** 1, "x // 1": lambda x: x // 1,
    "torch.add(x, 0)": lambda x: torch.add(x, 0), "x + torch.zeros(())": lambda x: x + torch.zeros(()), "x.clone()": lambda x: x.clone(),
    "x + 0 (int64)": lambda x: x + 0, "(x + 0) + 0": lambda x: (x + 0) + 0, "x + 0 then * 1": lambda x: (x + 0) * 1,
    "(x + 0, x)": lambda x: (x + 0, x),
}
for name, f in progs.items():
    rows = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        x = torch.arange(1.0, 5.0) if "int64" not in name else torch.arange(1, 5)
        g = f if backend is None else torch.compile(f, backend=backend)
        y = g(x)
        y = y[0] if isinstance(y, tuple) else y
        same_storage = y.data_ptr() == x.data_ptr()
        y.mul_(2)                                   # the caller mutates the *result*
        rows.append(f"{'eager' if backend is None else backend}: result is input={y is x} shares storage={same_storage} x after y.mul_(2)={x.tolist()}")
    flag = "!!" if "True" in rows[2] else "  "
    print(flag, f"{name:22s}", " | ".join(rows))
print("--- int8 abs(abs(x))")
x = torch.tensor([0, 1, -1, 127, -128, 126, 7, 100], dtype=torch.int8)
for name, f in (("x.abs()", lambda t: t.abs()), ("x.abs().abs()", lambda t: t.abs().abs()), ("abs(neg(abs))", lambda t: (-t.abs()).abs())):
    torch._dynamo.reset()
    print(f"{name:16s} eager {f(x).tolist()} inductor {torch.compile(f)(x).tolist()}")
