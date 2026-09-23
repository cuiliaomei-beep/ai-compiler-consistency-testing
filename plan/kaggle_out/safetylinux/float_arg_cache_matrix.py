"""Which cache makes `torch.add(e * d, p, alpha=1 - d)` return a stale alpha?  Run in a fresh TORCHINDUCTOR_CACHE_DIR."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch
p = torch.tensor([1.0, 2.0, 3.0])
f = lambda e, d: torch.add(e * d, p, alpha=1 - d)
cf = torch.compile(f)
row = []
for d in (0.9, 0.5, 0.25, 0.75, 0.5, 0.1):
    want, got = f(torch.ones(3), d), cf(torch.ones(3), d)
    row.append(f"d={d}: {'ok' if torch.allclose(want, got) else 'WRONG got ' + str([round(v, 3) for v in got.tolist()]) + ' want ' + str([round(v, 3) for v in want.tolist()])}")
print(torch.__version__, "FX_GRAPH_CACHE=" + os.environ.get("TORCHINDUCTOR_FX_GRAPH_CACHE", "default"), "AUTOGRAD_CACHE=" + os.environ.get("TORCHINDUCTOR_AUTOGRAD_CACHE", "default"))
for r in row:
    print("   ", r)
