"""`a % (b - 20)` on symbolic sizes when b == 20: ZeroDivisionError (Python) or process death?  Fresh process per backend/variant."""
import os, subprocess, sys
CHILD = r'''
import sys
sys.path.insert(0, r"%s")
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
backend, mark, expr = sys.argv[1], sys.argv[2] == "mark", sys.argv[3]
f = eval(expr)
g = torch.compile(f, backend=backend, dynamic=True)
for a, b in ((13, 25), (11, 22), (13, 20)):
    x, y = torch.ones(a), torch.ones(b)
    if mark:
        torch._dynamo.mark_dynamic(x, 0); torch._dynamo.mark_dynamic(y, 0)
    try:
        r = g(x, y)
        print("RESULT", (a, b), r.tolist() if isinstance(r, torch.Tensor) else r, flush=True)
    except Exception as e:
        print("RESULT", (a, b), "raises", type(e).__name__, flush=True)
''' % os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXPRS = {"returned int: a % (b - 20)": "lambda x, y: x.shape[0] % (y.shape[0] - 20)",
         "returned int: a // (b - 20)": "lambda x, y: x.shape[0] // (y.shape[0] - 20)",
         "into tensor: full((2,), a % (b - 20))": "lambda x, y: torch.full((2,), x.shape[0] % (y.shape[0] - 20), dtype=torch.float64)",
         "into shape: zeros(a % (b - 20) + 1)": "lambda x, y: torch.zeros(x.shape[0] % (y.shape[0] - 20) + 1).shape[0]"}
if __name__ == "__main__":
    for name, expr in EXPRS.items():
        for mark in ("mark", "nomark"):
            for backend in ("eager", "inductor"):
                r = subprocess.run([sys.executable, "-c", CHILD, backend, mark, expr], capture_output=True, text=True)
                lines = [l[7:] for l in r.stdout.splitlines() if l.startswith("RESULT")]
                died = "" if r.returncode == 0 else f"  PROCESS DIED rc={r.returncode & 0xFFFFFFFF:#x}"
                print(f"{name:40s} {mark:6s} {backend:9s} {' | '.join(lines)}{died}", flush=True)
