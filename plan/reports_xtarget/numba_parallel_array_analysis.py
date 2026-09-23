"""numba.njit(parallel=True) rejects programs that plain njit (and NumPy) run: the parfor array-analysis pass asserts on
size equivalence it cannot prove (slice of a fixed length, broadcasting a row against a matrix)."""
import numpy as np, numba
print("numba", numba.__version__, "numpy", np.__version__)

def linspace_times_slice(a):
    return np.linspace(0.0, 1.0, 7) * a[:7]

def broadcast_row(a):
    return a + a[0]              # (m, n) + (n,)

def pow_m1(a):
    return a ** -1

def mean_empty(a):
    return np.mean(a[:0])

for name, f, arg in (("linspace(0,1,7) * a[:7]", linspace_times_slice, np.arange(10.0)),
                     ("a + a[0]  (2-D + row)", broadcast_row, np.arange(12.0).reshape(3, 4)),
                     ("a ** -1 (float32 with 0)", pow_m1, np.array([0.0, 2.0, 4.0], dtype=np.float32)),
                     ("np.mean(a[:0])", mean_empty, np.arange(5.0))):
    print(name)
    for label, jit in (("numpy", lambda g: g), ("njit", numba.njit), ("njit(parallel=True)", numba.njit(parallel=True))):
        try:
            out = jit(f)(arg.copy())
            print(f"    {label:20s} {np.asarray(out).tolist()}")
        except Exception as e:
            print(f"    {label:20s} raises {type(e).__name__}: {str(e).splitlines()[0][:100]}")
