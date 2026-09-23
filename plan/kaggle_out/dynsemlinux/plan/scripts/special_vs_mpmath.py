"""8.3  Unary math / special functions vs a 30-digit mpmath reference: eager and torch.compile (Inductor CPU) on dense
near-singularity and large-magnitude arguments, 64-element tensors (vector path) for float32 and float64.
A case is reported when the compiled relative error exceeds both 1e-6 and 100x the eager error (so libm ULP noise
is ignored and only algorithmic losses like erfinv's Newton cancellation or acosh's overflow show up), or when the
NaN/inf pattern differs from eager.
    python scripts/special_vs_mpmath.py          -> results/special_mpmath.jsonl
"""
import json
import math
import os
import sys
import tempfile

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_sp_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from mpmath import mp  # noqa: E402

mp.dps = 30
print("torch", torch.__version__, flush=True)

# name -> (torch fn, mpmath fn, domain sampler)
def dom(lo, hi, extra=()):
    return lambda fi: [v for v in list(extra) + [lo + (hi - lo) * k / 60 for k in range(61)] if lo <= v <= hi]


near1 = lambda fi: [1 - fi.eps * 2 ** k for k in range(0, 24)] + [-(1 - fi.eps * 2 ** k) for k in range(0, 24)] + [0.5, -0.5, 0.9, -0.9, 0.99, 0.999, fi.tiny, -fi.tiny]
large = lambda fi: [fi.max / 2 ** k for k in range(0, 40, 2)] + [math.sqrt(fi.max) * 1.01, math.sqrt(fi.max) * 0.99, 1e4, 1e2, 10.0, 2.0, 1.0 + fi.eps, 1.0 + 1e-6]
around0 = lambda fi: [fi.tiny * 2 ** k for k in range(0, 40, 3)] + [fi.eps, fi.eps ** 2, 1e-3, 0.1, 0.5, -0.5, -1e-3, -fi.eps, 0.0, -0.0]
pos_large = lambda fi: [v for v in large(fi)] + [0.5, 1.5, 3.0, 20.0, 50.0]
FN = {
    "erfinv": (torch.erfinv, mp.erfinv, near1), "atanh": (torch.atanh, mp.atanh, near1), "acosh": (torch.acosh, mp.acosh, large), "asinh": (torch.asinh, mp.asinh, large),
    "sinh": (torch.sinh, mp.sinh, lambda fi: [v for v in large(fi) if v < 700] + [88.0, 89.0, 709.0, 710.0, 1e-3]), "cosh": (torch.cosh, mp.cosh, lambda fi: [88.0, 89.0, 709.0, 710.0, 1.0, 20.0]),
    "tanh": (torch.tanh, mp.tanh, large), "expm1": (torch.expm1, mp.expm1, around0), "log1p": (torch.log1p, lambda x: mp.log(1 + x), lambda fi: around0(fi) + large(fi)),
    "exp": (torch.exp, mp.exp, lambda fi: [88.0, 88.7, 709.0, 709.7, -100.0, -700.0, -745.0, 1e-3]), "log": (torch.log, mp.log, lambda fi: [v for v in around0(fi) if v > 0] + large(fi)),
    "log2": (torch.log2, lambda x: mp.log(x, 2), lambda fi: [v for v in around0(fi) if v > 0] + large(fi)), "log10": (torch.log10, mp.log10, lambda fi: [v for v in around0(fi) if v > 0] + large(fi)),
    "sqrt": (torch.sqrt, mp.sqrt, lambda fi: [v for v in around0(fi) if v >= 0] + large(fi)), "rsqrt": (torch.rsqrt, lambda x: 1 / mp.sqrt(x), lambda fi: [v for v in around0(fi) if v > 0] + large(fi)),
    "erf": (torch.erf, mp.erf, lambda fi: around0(fi) + [1.0, 3.0, 5.0, 6.0, 10.0]), "erfc": (torch.erfc, mp.erfc, lambda fi: [1.0, 3.0, 5.0, 9.0, 10.0, 26.0, 27.0, 0.1, -3.0, -5.0]),
    "erfcx": (torch.special.erfcx, lambda x: mp.exp(x * x) * mp.erfc(x), lambda fi: [0.1, 1.0, 5.0, 10.0, 100.0, 1e3, 1e4, 1e6, -1.0, -5.0, -10.0, -20.0, -26.0]),
    "lgamma": (torch.lgamma, mp.loggamma, lambda fi: [v for v in around0(fi) if v > 0] + [0.5, 1.0, 2.0, 10.0, 100.0, 1e3, 1e5, 1e10, 1e30, -0.5, -1.5, -2.5, -10.5, -100.5]),
    "digamma": (torch.digamma, mp.digamma, lambda fi: [v for v in around0(fi) if v > 0] + [0.5, 1.0, 10.0, 1e3, 1e10, -0.5, -1.5, -10.5]),
    "i0": (torch.i0, lambda x: mp.besseli(0, x), lambda fi: around0(fi) + [1.0, 10.0, 50.0, 88.0, 700.0]), "i0e": (torch.special.i0e, lambda x: mp.exp(-abs(x)) * mp.besseli(0, x), lambda fi: around0(fi) + [1.0, 10.0, 50.0, 700.0, 1e5, 1e10]),
    "i1": (torch.special.i1, lambda x: mp.besseli(1, x), lambda fi: around0(fi) + [1.0, 10.0, 50.0, 88.0, 700.0]), "i1e": (torch.special.i1e, lambda x: mp.exp(-abs(x)) * mp.besseli(1, x), lambda fi: around0(fi) + [1.0, 10.0, 700.0, 1e5, 1e10]),
    "ndtri": (torch.special.ndtri, lambda x: mp.sqrt(2) * mp.erfinv(2 * x - 1), lambda fi: [fi.tiny, 1e-300 if fi.eps < 1e-10 else 1e-37, 1e-10, 1e-5, 0.01, 0.5, 0.99, 1 - 1e-5, 1 - 1e-7, 1 - fi.eps]),
    "ndtr": (torch.special.ndtr, mp.ncdf, lambda fi: [-40.0, -38.0, -30.0, -10.0, -5.0, -1.0, 0.0, 1.0, 5.0, 10.0, 40.0]), "log_ndtr": (torch.special.log_ndtr, lambda x: mp.log(mp.ncdf(x)), lambda fi: [-1e5, -1e3, -100.0, -40.0, -10.0, -1.0, 0.0, 1.0, 10.0, 40.0]),
    "sinc": (torch.sinc, lambda x: 1 if x == 0 else mp.sin(mp.pi * x) / (mp.pi * x), lambda fi: around0(fi) + [1.0, 0.5, 1e3, 1e5, 1e8]),
    "sigmoid": (torch.sigmoid, lambda x: 1 / (1 + mp.exp(-x)), lambda fi: [-100.0, -90.0, -88.0, -20.0, 0.0, 20.0, 88.0, 100.0, 1e4]), "logsigmoid": (torch.nn.functional.logsigmoid, lambda x: -mp.log(1 + mp.exp(-x)), lambda fi: [-1e4, -100.0, -20.0, 0.0, 20.0, 100.0, 1e4]),
    "softplus": (torch.nn.functional.softplus, lambda x: mp.log(1 + mp.exp(x)), lambda fi: [-100.0, -20.0, -1.0, 0.0, 1.0, 19.0, 21.0, 100.0, 1e4]),
    "sin": (torch.sin, mp.sin, lambda fi: [1e3, 1e5, 1e7, 1e9, 1e15, 1e20, 3.14159, 0.5, math.pi] ), "cos": (torch.cos, mp.cos, lambda fi: [1e3, 1e5, 1e7, 1e9, 1e15, 1e20, 1.5707963, math.pi / 2]),
    "tan": (torch.tan, mp.tan, lambda fi: [1.5707963, 1.5707963267948966, 1e3, 1e5, 1e7, 1e9, 1e15]), "atan": (torch.atan, mp.atan, large), "asin": (torch.asin, mp.asin, near1), "acos": (torch.acos, mp.acos, near1),
    "exp2": (torch.exp2, lambda x: mp.power(2, x), lambda fi: [-150.0, -126.0, 0.5, 100.0, 127.0, 127.9, 1023.0, 1023.9]), "reciprocal": (torch.reciprocal, lambda x: 1 / x, lambda fi: around0(fi) + large(fi)),
    "square": (torch.square, lambda x: x * x, lambda fi: large(fi) + around0(fi)), "abs": (torch.abs, abs, lambda fi: large(fi) + around0(fi)),
}


def run():
    out = open("results/special_mpmath.jsonl", "w", encoding="utf-8")
    n_flag = 0
    for name, (tf, mf, sampler) in FN.items():
        for dt in (torch.float32, torch.float64):
            fi = torch.finfo(dt)
            vals = sorted({float(torch.tensor(v, dtype=dt).item()) for v in sampler(fi)})
            x = torch.tensor((vals * 64)[:64] if len(vals) < 64 else vals[:64], dtype=dt)
            torch._dynamo.reset()
            try:
                e = tf(x); c = torch.compile(tf)(x)
            except Exception as ex:  # noqa: BLE001
                out.write(json.dumps({"fn": name, "dtype": str(dt), "error": type(ex).__name__}) + "\n"); continue
            rows = []
            for i in range(len(x)):
                v = x[i].item()
                try:
                    r = mf(mp.mpf(v)); r = float(r.real) if hasattr(r, "real") else float(r)
                except Exception:  # noqa: BLE001
                    continue
                ev, cv = e[i].item(), c[i].item()
                nan_mismatch = (math.isnan(ev) != math.isnan(cv)) or (math.isinf(ev) != math.isinf(cv))
                if nan_mismatch:
                    rows.append({"x": v, "eager": ev, "compiled": cv, "ref": r, "kind": "nan/inf pattern"}); continue
                if math.isnan(ev) or math.isinf(ev) or math.isnan(r) or math.isinf(r):
                    continue
                scale = max(abs(r), fi.tiny)
                ee, ce = abs(ev - r) / scale, abs(cv - r) / scale
                if ce > 1e-6 and ce > 100 * max(ee, fi.eps / 4):
                    rows.append({"x": v, "eager": ev, "compiled": cv, "ref": r, "eager_rel": ee, "compiled_rel": ce, "kind": "accuracy"})
            rec = {"fn": name, "dtype": str(dt).split(".")[-1], "n": len(x), "flagged": rows}
            out.write(json.dumps(rec) + "\n")
            if rows:
                n_flag += 1
                w = max(rows, key=lambda r: r.get("compiled_rel", 1.0))
                print(f"!! {name:10s} {rec['dtype']:8s} {len(rows):2d}/{len(x)}  worst x={w['x']!r}: eager {w['eager']!r} compiled {w['compiled']!r} ref {w['ref']!r} [{w['kind']}]", flush=True)
    print(f"DONE: {n_flag} (fn, dtype) flagged", flush=True)


if __name__ == "__main__":
    run()
