"""Special functions at large-magnitude / near-singular arguments: eager vs compiled, long vector (SLEEF vector path on
Linux) vs short (scalar tail).  Lead: acosh(1.79e308) -> inf under Inductor on Linux gcc, finite in eager."""
import torch, math
print("torch", torch.__version__)
F64 = [1e18, 1e100, 1e154, 1e200, 1.7976931348623157e308, 1 + 1e-15, 1 - 1e-16, 0.999999, -0.999999, 1e-320, 700.0, 709.7]
F32 = [1e18, 3e38, 3.4028234663852886e38, 1 + 1e-7, 0.99999994, 0.999999, -0.999999, 1e-45, 88.0, 88.7]
OPS = {"acosh": torch.acosh, "asinh": torch.asinh, "atanh": torch.atanh, "log1p": torch.log1p, "expm1": torch.expm1, "sinh": torch.sinh, "cosh": torch.cosh, "tanh": torch.tanh,
       "exp": torch.exp, "log": torch.log, "log2": torch.log2, "log10": torch.log10, "sqrt": torch.sqrt, "rsqrt": torch.rsqrt, "erf": torch.erf, "erfc": torch.erfc, "erfinv": lambda x: torch.erfinv(x.clamp(-1, 1)),
       "lgamma": torch.lgamma, "digamma": torch.digamma, "i0": torch.i0, "erfcx": torch.special.erfcx, "log_ndtr": torch.special.log_ndtr, "ndtri": lambda x: torch.special.ndtri(x.clamp(1e-6, 1 - 1e-6)),
       "sigmoid": torch.sigmoid, "logsigmoid": torch.nn.functional.logsigmoid, "softplus": torch.nn.functional.softplus, "hypot(x,x)": lambda x: torch.hypot(x, x), "atan2(x,1)": lambda x: torch.atan2(x, torch.ones_like(x)),
       "pow(x,0.5)": lambda x: torch.pow(x.abs(), 0.5), "pow(x,2)": lambda x: torch.pow(x, 2), "reciprocal": torch.reciprocal, "square": torch.square, "abs*abs": lambda x: x.abs() * x.abs()}
for dt, vals in ((torch.float64, F64), (torch.float32, F32)):
    for name, f in OPS.items():
        for n in (3, 64):
            x = torch.tensor((vals * 8)[:n], dtype=dt)
            torch._dynamo.reset()
            try:
                e = f(x); c = torch.compile(f)(x)
            except Exception as ex:
                print(f"?? {name:12s} {str(dt):14s} n={n:2d} {type(ex).__name__}"); continue
            bad = (e.isnan() != c.isnan()) | (e.isinf() != c.isinf()) | ((e - c).abs() > 1e-6 * e.abs().clamp(min=1) + 1e-12) & ~e.isnan() & ~e.isinf()
            if bad.any():
                i = bad.nonzero()[0].item()
                print(f"!! {name:12s} {str(dt):14s} n={n:2d} x={x[i].item()!r}: eager {e[i].item()!r}  compiled {c[i].item()!r}   ({int(bad.sum())} of {n})", flush=True)
print("DONE")
