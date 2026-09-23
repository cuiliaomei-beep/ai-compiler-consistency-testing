"""Which operators bake a Python-float argument into the graph while the same float stays a dynamic input elsewhere?
f(x, s) uses `x * s` (keeps s dynamic) and passes an expression of s to a float parameter of an op.  Default caches, fresh cache dir."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_fk_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import torch, torch.nn.functional as F
print("torch", torch.__version__, flush=True)
torch.manual_seed(0)
X = torch.randn(4, 4)
P = {
    "rms_norm eps": lambda x, s: F.rms_norm(x * s, (4,), eps=s + 1e-3), "layer_norm eps": lambda x, s: F.layer_norm(x * s, (4,), eps=s + 1e-3),
    "group_norm eps": lambda x, s: F.group_norm(x * s, 2, eps=s + 1e-3), "batch_norm eps": lambda x, s: F.batch_norm(x * s, None, None, training=True, eps=s + 1e-3),
    "batch_norm momentum": lambda x, s: _bn(x * s, s / 4), "instance_norm eps": lambda x, s: F.instance_norm((x * s)[None], eps=s + 1e-3),
    "dropout p (eval)": lambda x, s: F.dropout(x * s, p=s / 4, training=False), "leaky_relu slope": lambda x, s: F.leaky_relu(x * s, s / 4), "elu alpha": lambda x, s: F.elu(x * s, alpha=s + 0.5),
    "celu alpha": lambda x, s: F.celu(x * s, alpha=s + 0.5), "softplus beta": lambda x, s: F.softplus(x * s, beta=s + 0.5), "hardtanh bounds": lambda x, s: F.hardtanh(x * s, -s - 0.1, s + 0.1),
    "threshold": lambda x, s: F.threshold(x * s, s / 2, -s), "hardshrink": lambda x, s: F.hardshrink(x * s, s / 2), "softshrink": lambda x, s: F.softshrink(x * s, s / 2), "rrelu eval": lambda x, s: F.rrelu(x * s, s / 8, s / 4),
    "normalize eps": lambda x, s: F.normalize(x * s * 1e-3, eps=s + 1e-3), "normalize p": lambda x, s: F.normalize(x * s, p=s + 1.0), "norm p": lambda x, s: (x * s).norm(p=s + 1.0), "cosine_similarity eps": lambda x, s: F.cosine_similarity(x * s * 1e-3, x.flip(0), eps=s + 1e-3),
    "pairwise_distance p": lambda x, s: F.pairwise_distance(x * s, x.flip(0), p=s + 1.0), "cdist p": lambda x, s: torch.cdist(x * s, x, p=s + 1.0), "quantile q": lambda x, s: torch.quantile(x * s, s / 4),
    "nan_to_num nan": lambda x, s: torch.nan_to_num((x * s) / (x - x), nan=s + 1.0), "interpolate scale_factor": lambda x, s: F.interpolate((x * s)[None], scale_factor=1.0 + s, mode="nearest"),
    "interpolate linear scale": lambda x, s: F.interpolate((x * s)[None], scale_factor=1.0 + s, mode="linear"), "full fill": lambda x, s: x * s + torch.full((4,), s + 1.0), "linspace end": lambda x, s: x * s + torch.linspace(0, s + 1.0, 4),
    "arange step": lambda x, s: (x * s)[0, :2] + torch.arange(0.0, s + 0.05, (s + 0.05) / 2)[:2], "gelu-free: lerp weight": lambda x, s: torch.lerp(x * s, x, s / 4), "addcmul value": lambda x, s: torch.addcmul(x * s, x, x, value=1 - s),
    "addmm beta/alpha": lambda x, s: torch.addmm(x * s, x, x, beta=s, alpha=1 - s), "baddbmm": lambda x, s: torch.baddbmm((x * s)[None], x[None], x[None], beta=1 - s, alpha=s), "clamp": lambda x, s: (x * s).clamp(-s, s),
    "masked_fill": lambda x, s: (x * s).masked_fill(x > 0, s + 1), "where scalar": lambda x, s: torch.where(x > 0, x * s, s + 1.0), "pow exponent": lambda x, s: (x * s).abs() ** (s + 0.5), "histc range": lambda x, s: torch.histc(x * s, bins=4, min=-s - 1, max=s + 1),
    "smooth_l1 beta": lambda x, s: F.smooth_l1_loss(x * s, x, beta=s + 0.1), "huber delta": lambda x, s: F.huber_loss(x * s, x, delta=s + 0.1), "label_smoothing": lambda x, s: F.cross_entropy(x * s, torch.tensor([0, 1, 2, 3]), label_smoothing=s / 4),
    "poisson_nll eps": lambda x, s: F.poisson_nll_loss((x * s).abs(), x.abs(), log_input=False, eps=s + 1e-3), "gaussian_nll eps": lambda x, s: F.gaussian_nll_loss(x * s, x, x.abs(), eps=s + 1e-3), "margin_ranking margin": lambda x, s: F.margin_ranking_loss(x * s, x, x.sign(), margin=s),
    "triplet margin": lambda x, s: F.triplet_margin_loss(x * s, x.flip(0), x.flip(1), margin=s + 0.5), "gumbel-free: softmax temperature": lambda x, s: F.softmax(x * s / (s + 0.5), -1), "sdpa scale": lambda x, s: F.scaled_dot_product_attention((x * s)[None], x[None], x[None], scale=s + 0.5),
    "std correction-free: var+eps sqrt": lambda x, s: (x * s) / torch.sqrt(x.var() + (s + 1e-3)), "logit eps": lambda x, s: torch.logit((x * s).sigmoid(), eps=s / 8), "clip_grad-free: renorm maxnorm": lambda x, s: torch.renorm(x * s, 2, 0, s + 0.5),
    "bernoulli-free: tril diag": lambda x, s: (x * s).tril(int(s * 2)), "isclose rtol": lambda x, s: torch.isclose(x * s, x, rtol=s), "allclose-free: bucketize": lambda x, s: torch.bucketize(x * s, torch.tensor([-s, 0.0, s])),
}
def _bn(x, m):
    rm, rv = torch.zeros(4), torch.ones(4)
    return F.batch_norm(x, rm, rv, training=True, momentum=m), rm, rv
def flat(o):
    return torch.cat([t.double().flatten() for t in (o if isinstance(o, tuple) else (o,))])
for name, f in P.items():
    torch._dynamo.reset()
    try:
        g = torch.compile(f)
        bad = []
        for s in (0.9, 0.5, 0.25, 0.75):
            w, r = flat(f(X, s)), flat(g(X, s))
            err = (torch.nan_to_num(w) - torch.nan_to_num(r)).abs().max().item() if w.shape == r.shape else float("inf")
            if err > 1e-5:
                bad.append(f"s={s}: err {err:.3g}")
        print("!!" if bad else "  ", f"{name:36s}", "; ".join(bad), flush=True)
    except Exception as e:
        print("ER", f"{name:36s}", type(e).__name__, str(e).splitlines()[0][:100], flush=True)
