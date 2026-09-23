"""numba.njit(parallel=True) vs plain numba.njit on the same functions (11.6)."""
import numpy as np, numba, traceback
print("numba", numba.__version__, "numpy", np.__version__)

def stride2(a):
    return a[::2] + a[1::2][: a[::2].shape[0]]

def pow_neg(a, b):
    return np.power(a, b)

def rshift(a):
    return a >> 70

def recip(a):
    return np.reciprocal(a)

a8 = np.array([-128, -1, 0, 1, 2, 3, 5, 7, 127], dtype=np.int8)
cases = [("a[::2] + a[1::2][:n]", stride2, (np.arange(9, dtype=np.int8),)),
         ("np.power(int8, negative int8)", pow_neg, (np.array([2, 3, -2, 5], dtype=np.int8), np.array([-1, -2, -1, -3], dtype=np.int8))),
         ("int8 >> 70", rshift, (a8,)),
         ("np.reciprocal(int16 with 0)", recip, (np.array([0, 1, 2, -3], dtype=np.int16),))]
for name, f, args in cases:
    print(name)
    for label, jit in (("numpy", lambda g: g), ("njit", numba.njit), ("njit(parallel=True)", numba.njit(parallel=True))):
        try:
            out = jit(f)(*[x.copy() for x in args])
            print(f"    {label:20s} {out.tolist()} {out.dtype}")
        except Exception as e:
            print(f"    {label:20s} raises {type(e).__name__}: {str(e).splitlines()[0][:110]}")
