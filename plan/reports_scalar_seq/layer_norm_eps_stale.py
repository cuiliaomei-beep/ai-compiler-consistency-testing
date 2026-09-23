"""F.layer_norm(x, shape, eps=<python float that changes between calls>): does the compiled function use the current eps?  Fresh cache dir."""
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
    "layer_norm(x, (4,), eps=s)": lambda x, s: F.layer_norm(x, (4,), eps=s),
    "layer_norm(x, (4,), w, b, eps=s)": lambda x, s: F.layer_norm(x, (4,), torch.ones(4), torch.zeros(4), eps=s),
    "group_norm(x, 2, eps=s)": lambda x, s: F.group_norm(x, 2, eps=s),
    "batch_norm(train, eps=s)": lambda x, s: F.batch_norm(x, None, None, training=True, eps=s),
    "instance_norm(eps=s)": lambda x, s: F.instance_norm(x[None], eps=s),
    "rms_norm(eps=s)": lambda x, s: F.rms_norm(x, (4,), eps=s),
    "manual: (x - mean) / sqrt(var + s)": lambda x, s: (x - x.mean(1, keepdim=True)) / torch.sqrt(x.var(1, unbiased=False, keepdim=True) + s),
    "cosine_similarity(eps=s)": lambda x, s: F.cosine_similarity(x, x.flip(0), eps=s),
    "normalize(eps=s)": lambda x, s: F.normalize(x * 1e-3, eps=s),
}
for name, f in progs.items():
    for backend in ("aot_eager", "inductor"):
        torch._dynamo.reset()
        g = torch.compile(f, backend=backend)
        row = []
        for s in (1.0, 0.5, 0.25, 0.75, 0.5, 2.0):
            want, got = f(x, s), g(x, s)
            err = (want - got).abs().max().item()
            row.append("ok" if err < 1e-5 else f"s={s}: max err {err:.3f}")
        bad = [r for r in row if r != "ok"]
        print("!!" if bad else "  ", f"{name:38s} {backend:9s}", "; ".join(bad))
