"""Stand-alone checks of the symint_arith_diff leads.  No mark_dynamic (avoids ConstraintViolation noise); dynamic=True."""
import math, os, subprocess, sys
CHILD_PRE = r'''
import os, sys, math
sys.path.insert(0, r"%s")
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
torch._dynamo.config.capture_scalar_outputs = True
''' % os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CASES = {
    # name: (program source taking tensors, list of input-constructor sources)
    "abs(x.item()) float64": ("lambda x: abs(x.item())", ["torch.tensor(0.1, dtype=torch.float64)", "torch.tensor(-0.3, dtype=torch.float64)"]),
    "x.item() ** 2": ("lambda x: x.item() ** 2", ["torch.tensor(0.1, dtype=torch.float64)", "torch.tensor(0.7, dtype=torch.float64)"]),
    "x.item() * 3": ("lambda x: x.item() * 3", ["torch.tensor(0.1, dtype=torch.float64)", "torch.tensor(0.7, dtype=torch.float64)"]),
    "x.item() + 1 (returned in tensor)": ("lambda x: torch.full((1,), x.item() + 1, dtype=torch.float64)", ["torch.tensor(0.1, dtype=torch.float64)", "torch.tensor(0.7, dtype=torch.float64)"]),
    "int(x.item()) big float": ("lambda x: torch.full((1,), int(x.item()), dtype=torch.float64)", ["torch.tensor(16777217.0, dtype=torch.float64)", "torch.tensor(33554435.0, dtype=torch.float64)"]),
    "u == u (nan)": ("lambda x: (lambda u: u == u)(x.item())", ["torch.tensor(1.0, dtype=torch.float64)", "torch.tensor(float('nan'), dtype=torch.float64)"]),
    "u != u (nan)": ("lambda x: (lambda u: u != u)(x.item())", ["torch.tensor(1.0, dtype=torch.float64)", "torch.tensor(float('nan'), dtype=torch.float64)"]),
    "math.isnan(u)": ("lambda x: math.isnan(x.item())", ["torch.tensor(1.0, dtype=torch.float64)", "torch.tensor(float('nan'), dtype=torch.float64)"]),
    "(-2) ** n, n = x.shape[0]": ("lambda x: (-2) ** x.shape[0]", ["torch.ones(2)", "torch.ones(3)", "torch.ones(4)"]),
    "(-1) ** n": ("lambda x: (-1) ** x.shape[0]", ["torch.ones(2)", "torch.ones(3)", "torch.ones(4)"]),
    "(2 - n) ** 2": ("lambda x: (2 - x.shape[0]) ** 2", ["torch.ones(5)", "torch.ones(6)", "torch.ones(7)"]),
    "round(n * 5, -1)": ("lambda x: round(x.shape[0] * 5, -1)", ["torch.ones(3)", "torch.ones(5)", "torch.ones(7)"]),
    "round(n / 2)": ("lambda x: round(x.shape[0] / 2)", ["torch.ones(3)", "torch.ones(5)", "torch.ones(7)"]),
    "n % (m - 20), m = 20": ("lambda x, y: x.shape[0] % (y.shape[0] - 20)", ["(torch.ones(13), torch.ones(25))", "(torch.ones(11), torch.ones(22))", "(torch.ones(13), torch.ones(20))"]),
    "n // (m - 20), m = 20": ("lambda x, y: x.shape[0] // (y.shape[0] - 20)", ["(torch.ones(13), torch.ones(25))", "(torch.ones(11), torch.ones(22))", "(torch.ones(13), torch.ones(20))"]),
    "min(n, 2.5) type": ("lambda x: type(min(x.shape[0], 2.5)).__name__", ["torch.ones(2)", "torch.ones(3)", "torch.ones(5)"]),
    "round(u, 1) at -0.0": ("lambda x: math.copysign(1.0, round(x.item(), 1))", ["torch.tensor(0.26, dtype=torch.float64)", "torch.tensor(-0.0, dtype=torch.float64)"]),
}
CHILD_RUN = r'''
src, backend = sys.argv[1], sys.argv[2]
f = eval(src)
g = f if backend == "none" else torch.compile(f, backend=backend, dynamic=True)
outs = []
for a in sys.argv[3:]:
    args = eval(a); args = args if isinstance(args, tuple) else (args,)
    try:
        r = g(*args)
        outs.append(repr(r.tolist() if isinstance(r, torch.Tensor) else r))
    except Exception as e:
        outs.append("raises " + type(e).__name__)
print("RESULT", " | ".join(outs))
'''
if __name__ == "__main__":
    import torch
    print("torch", torch.__version__)
    for name, (src, inputs) in CASES.items():
        rows = {}
        for backend in ("none", "eager", "aot_eager", "inductor"):
            r = subprocess.run([sys.executable, "-c", CHILD_PRE + CHILD_RUN, src, backend, *inputs], capture_output=True, text=True)
            line = [l for l in r.stdout.splitlines() if l.startswith("RESULT")]
            rows[backend] = line[0][7:] if line else f"PROCESS DIED rc={r.returncode & 0xFFFFFFFF:#x}"
        flag = "!!" if any(v != rows["none"] for v in rows.values()) else "  "
        print(f"{flag} {name}")
        for b, v in rows.items():
            if b == "none" or v != rows["none"]:
                print(f"       {'python/eager' if b == 'none' else b:12s} {v}")
