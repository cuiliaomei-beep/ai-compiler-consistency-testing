import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_ln_eps_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__, "FX_GRAPH_CACHE", os.environ.get("TORCHINDUCTOR_FX_GRAPH_CACHE", "default"), "AUTOGRAD_CACHE", os.environ.get("TORCHINDUCTOR_AUTOGRAD_CACHE", "default"))
torch.manual_seed(0)
x = torch.randn(4, 4)
progs = {
    "layer_norm(x * (1 + s), eps=abs(s) + 1e-3)   [sweep case]": lambda x, s: F.layer_norm(x * (1 + s), (4,), eps=abs(s) + 1e-3),
    "layer_norm(x, eps=abs(s) + 1e-3)": lambda x, s: F.layer_norm(x, (4,), eps=abs(s) + 1e-3),
    "layer_norm(x, eps=s + 1e-3)": lambda x, s: F.layer_norm(x, (4,), eps=s + 1e-3),
    "layer_norm(x * s, eps=s)": lambda x, s: F.layer_norm(x * s, (4,), eps=s),
    "layer_norm(x * (1 + s), eps=1e-3)": lambda x, s: F.layer_norm(x * (1 + s), (4,), eps=1e-3),
    "group_norm(x * s, 2, eps=s + 1e-3)": lambda x, s: F.group_norm(x * s, 2, eps=s + 1e-3),
    "rms_norm(x * s, eps=s + 1e-3)": lambda x, s: F.rms_norm(x * s, (4,), eps=s + 1e-3),
    "batch_norm(x * s, train, eps=s + 1e-3)": lambda x, s: F.batch_norm(x * s, None, None, training=True, eps=s + 1e-3),
}
for name, f in progs.items():
    for backend in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        g = torch.compile(f, backend=backend)
        bad = []
        for s in (0.9, 0.5, 0.25, 0.75, 0.5, 2.0):
            err = (f(x, s) - g(x, s)).abs().max().item()
            if err >= 1e-5:
                bad.append(f"s={s}: max err {err:.3f}")
        print("!!" if bad else "  ", f"{name:58s} {backend:9s}", "; ".join(bad))
