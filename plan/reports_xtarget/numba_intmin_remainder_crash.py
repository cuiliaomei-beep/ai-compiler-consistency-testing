"""Numba: integer remainder / floor_divide of INT_MIN by -1.  NumPy returns 0 / INT_MIN; one process per probe."""
import subprocess, sys
PROBES = ["np.remainder(a, b)", "a % b", "np.mod(a, b)", "np.fmod(a, b)", "np.floor_divide(a, b)", "a // b", "np.divmod(a, b)[1]"]
DTYPES = ["int8", "int16", "int32", "int64"]
if len(sys.argv) == 4:
    import numpy as np, numba
    expr, dt, mode = sys.argv[1:]
    ns = {"np": np}
    exec(f"def f(a, b):\n    return {expr}\n", ns)
    f = ns["f"] if mode == "numpy" else numba.njit(ns["f"])
    ii = np.iinfo(dt)
    a, b = np.array([ii.min, 7], dtype=dt), np.array([-1, -1], dtype=dt)
    print("RESULT", f(a, b).tolist())
else:
    import numpy as np, numba
    print("numba", numba.__version__, "numpy", np.__version__, sys.version.split()[0])
    for expr in PROBES:
        for dt in DTYPES:
            row = []
            for mode in ("numpy", "njit"):
                p = subprocess.run([sys.executable, __file__, expr, dt, mode], capture_output=True, text=True, timeout=300)
                line = [l for l in p.stdout.splitlines() if l.startswith("RESULT")]
                row.append(f"{mode}: " + (line[0][7:] if line else "EXIT " + hex(p.returncode & 0xffffffff)))
            print(f"{expr:24s} {dt:6s} " + " | ".join(row), flush=True)
