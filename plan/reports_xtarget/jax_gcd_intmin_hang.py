"""JAX: jnp.gcd / jnp.lcm with the minimum integer never terminates (eager and jit).  NumPy returns immediately."""
import subprocess, sys
if len(sys.argv) == 5:
    import jax; jax.config.update("jax_enable_x64", True)
    import jax.numpy as jnp, numpy as np
    op, dt, a, b = sys.argv[1:]
    x, y = np.array([int(a)], dtype=dt), np.array([int(b)], dtype=dt)
    print("NUMPY", getattr(np, op)(x, y).tolist(), flush=True)
    print("RESULT", np.asarray(getattr(jnp, op)(jnp.asarray(x), jnp.asarray(y))).tolist(), flush=True)
else:
    import jax; print("jax", jax.__version__)
    cases = [("gcd", "int8", -128, 6), ("gcd", "int8", 6, -128), ("gcd", "int8", -128, 0), ("gcd", "int8", -127, 6),
             ("gcd", "int32", -2**31, 6), ("gcd", "int64", -2**63, 6), ("gcd", "int64", 6, -2**63), ("lcm", "int32", -2**31, 6),
             ("lcm", "int64", 6, -2**63), ("gcd", "int32", 12, 18)]
    for op, dt, a, b in cases:
        try:
            p = subprocess.run([sys.executable, __file__, op, dt, str(a), str(b)], capture_output=True, text=True, timeout=60)
            out = " ".join(l for l in p.stdout.splitlines() if l.startswith(("NUMPY", "RESULT"))) or "EXIT " + hex(p.returncode & 0xffffffff)
        except subprocess.TimeoutExpired as e:
            so = e.stdout or ""; so = so.decode() if isinstance(so, bytes) else so; out = so.strip() + "  -> jax: NO RESULT AFTER 60 s (killed)"
        print(f"jnp.{op}({dt} {a}, {b}): {out}", flush=True)
