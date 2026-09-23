"""numba.njit(parallel=True): the ZeroDivisionError that Numba's own lowering raises (error_model='python') for
integer // and % by zero and for float ** negative-integer with a 0 base is lost inside a parallel region; the loop
continues and the output element keeps whatever the buffer held (0 / uninitialised memory).  Plain njit raises; an
explicit `raise` inside prange propagates."""
import platform, numpy as np, numba
print("numba", numba.__version__, "numpy", np.__version__, "python", platform.python_version(), platform.system())
a = np.array([0.0, 2.0, 4.0]); k = np.array([0, 2, 4])

def make(body):
    src = f"def f(a):\n    out = np.empty(a.shape[0], dtype=np.float64)\n    for i in RANGE(a.shape[0]):\n        out[i] = {body}\n    return out\n"
    ns_s = {"np": np, "RANGE": range}; ns_p = {"np": np, "RANGE": numba.prange}
    exec(src, ns_s); exec(src, ns_p)
    return numba.njit(ns_s["f"]), numba.njit(parallel=True)(ns_p["f"])

for body, arg in (("a[i] ** -1", a), ("a[i] ** -2", a), ("7 // int(a[i])", k), ("7 % int(a[i])", k), ("1.0 / a[i]", a), ("float(7 // int(a[i])) if a[i] != 0 else -1.0", k)):
    serial, parallel = make(body)
    row = []
    for label, f in (("njit", serial), ("njit(parallel=True)", parallel)):
        try: row.append(f"{label} -> {f(arg.copy()).tolist()}")
        except Exception as e: row.append(f"{label} -> raises {type(e).__name__}")
    print(f"{body:44s} " + " | ".join(row))

@numba.njit(parallel=True)
def arr(a):
    return a ** -1
try: print(f"{'whole-array a ** -1, parallel=True':44s} -> {arr(a.copy()).tolist()}   (NumPy: {(a ** -1).tolist()})")
except Exception as e: print("whole-array raises", type(e).__name__)
