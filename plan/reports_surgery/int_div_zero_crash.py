"""Integer division by zero under torch.compile: exception (like eager) or process crash?  One fresh process per case."""
import os, subprocess, sys
CASES = {
    "floor_divide int32": "lambda a, b: a // b|int32", "floor_divide int16": "lambda a, b: a // b|int16", "floor_divide int8": "lambda a, b: a // b|int8",
    "floor_divide int64": "lambda a, b: a // b|int64", "floor_divide uint8": "lambda a, b: a // b|uint8",
    "div trunc int32": "lambda a, b: torch.div(a, b, rounding_mode='trunc')|int32", "div trunc int16": "lambda a, b: torch.div(a, b, rounding_mode='trunc')|int16",
    "div trunc int8": "lambda a, b: torch.div(a, b, rounding_mode='trunc')|int8", "div trunc int64": "lambda a, b: torch.div(a, b, rounding_mode='trunc')|int64",
    "div trunc uint8": "lambda a, b: torch.div(a, b, rounding_mode='trunc')|uint8",
    "remainder int16": "lambda a, b: a % b|int16", "remainder int32": "lambda a, b: a % b|int32", "fmod int16": "lambda a, b: torch.fmod(a, b)|int16", "fmod int32": "lambda a, b: torch.fmod(a, b)|int32",
}
CHILD = r'''
import os, sys
sys.path.insert(0, r"%s")
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
f = eval(sys.argv[1]); dt = getattr(torch, sys.argv[2]); backend = sys.argv[3]; n = int(sys.argv[4])
x = torch.arange(1, n + 1).to(dt); d = torch.ones(n, dtype=dt); d[min(7, n - 1)] = 0
g = f if backend == "none" else torch.compile(f, backend=backend)
try:
    print("returned", g(x, d)[:9].tolist())
except Exception as e:
    print("raised", type(e).__name__, str(e)[:60])
''' % os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
if __name__ == "__main__":
    import torch
    print("torch", torch.__version__)
    for name, spec in CASES.items():
        src, dt = spec.split("|")
        for n in (40, 5):
            row = []
            for backend in ("none", "aot_eager", "inductor"):
                r = subprocess.run([sys.executable, "-c", CHILD, src, dt, backend, str(n)], capture_output=True, text=True)
                out = [l for l in r.stdout.splitlines() if l.startswith(("returned", "raised"))]
                row.append(f"{'eager' if backend == 'none' else backend}: " + (out[0][:70] if out else f"PROCESS DIED rc={r.returncode & 0xFFFFFFFF:#x}"))
            print(f"{name:20s} n={n:2d} | " + " | ".join(row), flush=True)
