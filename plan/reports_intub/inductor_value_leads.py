"""Stand-alone check of the value leads of int_ub_sweep (eager vs aot_eager vs inductor)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
INF = float("inf")
u8 = torch.tensor([0, 1, 2, 3, 7, 8, 9, 13, 100, 254, 255] * 3, dtype=torch.uint8)
f = torch.tensor([1.0, 1.0, -1.0, 0.5, 7.0, 1e20, 2147483648.0, 0.0, -0.0, 5.5, -5.5], dtype=torch.float32)
g = torch.tensor([0.1, 1 / 3, -0.1, 0.1, 0.7, 3.0, 3.0, INF, INF, INF, -INF], dtype=torch.float32)
cases = {
    "argmin(uint8)":               (lambda x: torch.argmin(x), (u8,)),
    "argmax(uint8)":               (lambda x: torch.argmax(x), (u8,)),
    "argmin(uint8[:7])":           (lambda x: torch.argmin(x), (u8[:7],)),
    "min(uint8)":                  (lambda x: torch.min(x), (u8,)),
    "floor_divide(f32, f32)":      (lambda a, b: torch.floor_divide(a, b), (f, g)),
    "a // b":                      (lambda a, b: a // b, (f, g)),
    "remainder(f32, f32)":         (lambda a, b: torch.remainder(a, b), (f, g)),
    "fmod(f32, f32)":              (lambda a, b: torch.fmod(a, b), (f, g)),
    "a % 3.0":                     (lambda a: a % 3.0, (f,)),
    "clamp(int8, -1000, 1000)":    (lambda x: torch.clamp(x, -1000, 1000), (torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8),)),
    "clamp(int8, min=2**40)":      (lambda x: torch.clamp(x, min=2 ** 40), (torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8),)),
    "x.half().float()":            (lambda x: x.to(torch.float16).to(torch.float32), (torch.tensor([0.1, 0.001, 1 / 3, 70000.0]),)),
    "x.bfloat16().float()":        (lambda x: x.to(torch.bfloat16).to(torch.float32), (torch.tensor([0.1, 0.001, 1 / 3, 70000.0]),)),
    "x.int().float()":             (lambda x: x.to(torch.int32).to(torch.float32), (torch.tensor([0.7, -0.7, 2.5, 1e5]),)),
    "acosh(f64 max)":              (lambda x: torch.acosh(x), (torch.tensor([1.7976931348623157e308, 1e200, 2.0], dtype=torch.float64),)),
    "atanh(denormal)":             (lambda x: torch.atanh(x), (torch.tensor([1.1754944e-38, 2.9e-39, -0.0, 0.5]),)),
    "erf(small)":                  (lambda x: torch.erf(x), (torch.tensor([1e-3, 1.1754944e-38, 0.5]),)),
}
print("torch", torch.__version__)
for name, (fn, args) in cases.items():
    rows = []
    for b in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            o = (fn if b is None else torch.compile(fn, backend=b))(*[a.clone() for a in args])
            rows.append(f"{str(o.dtype).split('.')[-1]} {o.flatten().tolist()}")
        except Exception as e:
            rows.append(f"raises {type(e).__name__}: {str(e).splitlines()[0][:70]}")
    flag = "  " if rows[0] == rows[2] else "!!"
    print(f"{flag} {name}\n     eager    : {rows[0]}\n     aot_eager: {rows[1]}\n     inductor : {rows[2]}")
