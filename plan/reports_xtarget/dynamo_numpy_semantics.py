"""NumPy code under torch.compile (Dynamo -> torch._numpy) vs the same code in CPython + NumPy.

    python reports_xtarget/dynamo_numpy_semantics.py [backend]      # backend: eager (default) | inductor
"""
import os, sys, warnings
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import numpy as np, torch
warnings.simplefilter("ignore")
backend = sys.argv[1] if len(sys.argv) > 1 else "eager"
i8 = np.array([-128, -100, -3, 0, 5, 100, 127], dtype=np.int8)
u8 = np.array([0, 1, 3, 200, 255], dtype=np.uint8)
f4 = np.array([1.5, -1.5, 2.5, -0.5, 8.0, -8.0, np.nan], dtype=np.float32)
CASES = [
    ("np.fix(x)",                     lambda x: np.fix(x), f4),
    ("np.cbrt(x)",                    lambda x: np.cbrt(x), f4),
    ("np.sign(x)",                    lambda x: np.sign(x), f4),
    ("np.heaviside(x, 0.5)",          lambda x: np.heaviside(x, np.float32(0.5)), f4),
    ("np.clip(int8, -1000, 1000)",    lambda x: np.clip(x, -1000, 1000), i8),
    ("np.clip(uint8, -2, 5)",         lambda x: np.clip(x, -2, 5), u8),
    ("np.cumsum(int8)",               lambda x: np.cumsum(x), i8),
    ("np.cumprod(int8)",              lambda x: np.cumprod(x), i8),
    ("np.square(int8)",               lambda x: np.square(x), i8),
    ("np.reciprocal(int8)",           lambda x: np.reciprocal(x), i8),
    ("np.sqrt(int8)",                 lambda x: np.sqrt(np.abs(x)), i8),
    ("np.true_divide(int8, int8)",    lambda x: np.true_divide(x, x + (x == 0)), i8),
    ("np.sum(uint8)",                 lambda x: np.sum(x), u8),
    ("np.any(uint8)",                 lambda x: np.any(x), u8),
    ("np.median(x)",                  lambda x: np.median(x[:5]), f4),
    ("np.percentile(x, 50)",          lambda x: np.percentile(x[:5], 50), f4),
    ("np.quantile(x, 0.25)",          lambda x: np.quantile(x[:5], 0.25), f4),
    ("np.searchsorted(sorted, x)",    lambda x: np.searchsorted(np.sort(x), x), f4),
    ("np.remainder(x, denormal)",     lambda x: np.remainder(x[:3], np.float32(3e-39)), f4),
    ("x.astype(uint16) + 1",          lambda x: x.astype(np.uint16) + np.uint16(1), u8),
    ("np.gcd(int8, 6)",               lambda x: np.gcd(x, np.int8(6)), i8),
]
print("torch", torch.__version__, "numpy", np.__version__, "backend", backend)
print(f"numpy_default_float={torch._dynamo.config.numpy_default_float!r}")
def show(o):
    o = np.asarray(o)
    return f"{o.dtype}{list(o.shape)} {o.tolist()}"
for name, fn, arg in CASES:
    ref = show(fn(arg.copy()))
    torch._dynamo.reset()
    try:
        got = show(torch.compile(fn, backend=backend)(arg.copy()))
    except Exception as e:
        got = f"raised {type(e).__name__}: {str(e).splitlines()[0][:90]}"
    flag = "  " if ref == got else "!!"
    print(f"{flag} {name}\n     numpy   : {ref}\n     compiled: {got}")
