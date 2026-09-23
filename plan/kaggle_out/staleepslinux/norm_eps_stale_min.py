"""Residual of the stale-float family (#194976): a Python float that both scales the input and, through arithmetic, sets `eps` of a normalisation op."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_norm_eps_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F

def f(x, s):
    return F.rms_norm(x * s, (4,), eps=s + 1e-3)

dev = "cuda" if torch.cuda.is_available() and os.environ.get("TCC_DEV", "cuda") == "cuda" else "cpu"
torch.manual_seed(0)
x = torch.randn(4, 4, device=dev)
cf = torch.compile(f)
print("torch", torch.__version__, dev, "| FX_GRAPH_CACHE =", os.environ.get("TORCHINDUCTOR_FX_GRAPH_CACHE", "default"), "| AUTOGRAD_CACHE =", os.environ.get("TORCHINDUCTOR_AUTOGRAD_CACHE", "default"))
for s in (0.9, 0.5, 0.25, 0.75, 0.5, 2.0):
    want, got = f(x, s), cf(x, s)
    err = (want - got).abs().max().item()
    # which eps would explain the compiled result?
    guess = min((0.9, 0.5, 0.25, 0.75, 2.0), key=lambda e: (F.rms_norm(x * s, (4,), eps=e + 1e-3) - got).abs().max().item())
    print(f"   s={s:<5} max |eager - compiled| = {err:.4f}   compiled result matches eps computed from s={guess}")
