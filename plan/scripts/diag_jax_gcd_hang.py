"""Does jnp.gcd / jnp.lcm terminate on integer edge values?  One process per probe, 40 s timeout."""
import subprocess, sys
VALS = {"int8": [-128, -127, -1, 0, 1, 127], "int32": [-2**31, -1, 0, 1], "int64": [-2**63, -1, 0, 1], "uint8": [0, 1, 255]}
if len(sys.argv) == 6:
    import jax; jax.config.update("jax_enable_x64", True)
    import jax.numpy as jnp, numpy as np
    op, dt, a, b, mode = sys.argv[1:]
    f = getattr(jnp, op)
    x, y = jnp.asarray(np.array([int(a)], dtype=dt)), jnp.asarray(np.array([int(b)], dtype=dt))
    if mode == "jit":
        f = jax.jit(f)
    print("RESULT", np.asarray(f(x, y)).tolist(), "numpy:", getattr(np, op)(np.array([int(a)], dtype=dt), np.array([int(b)], dtype=dt)).tolist())
else:
    for op in ("gcd", "lcm"):
        for dt, vals in VALS.items():
            for a in vals:
                for b in vals:
                    for mode in ("eager", "jit"):
                        try:
                            p = subprocess.run([sys.executable, __file__, op, dt, str(a), str(b), mode], capture_output=True, text=True, timeout=40)
                            line = [l for l in p.stdout.splitlines() if l.startswith("RESULT")]
                            res = line[0][7:] if line else "EXIT " + hex(p.returncode & 0xffffffff)
                        except subprocess.TimeoutExpired:
                            res = "HANG (>40 s)"
                        if "HANG" in res or "EXIT" in res or (mode == "jit"):
                            pass
                        print(f"{op} {dt} a={a} b={b} {mode}: {res}", flush=True)
