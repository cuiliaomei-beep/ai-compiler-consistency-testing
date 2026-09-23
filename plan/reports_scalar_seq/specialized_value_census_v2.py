"""11.2  "A value was specialised into the graph but is not part of what the caches key on" -- census v2.

v1 (specialized_float_kwarg_census.py) covered float parameters of operators (-> issue #197889).  v2 covers the other
ways a Python float / int that changes between calls can be burned into a compiled artifact:
  S  the float decides a SHAPE or an index (int(s * k), arange / linspace lengths, slice bounds, pad widths, repeat counts)
  D  a decomposition / lowering BRANCHES on the value (pow exponent 2 / 0.5 / -1 / 0, addmm beta == 0, lerp weight,
     dropout p in {0, 1}, clamp with min > max, softplus threshold, norm p in {1, 2, inf})
  B  the value reaches the graph as a SymBool / comparison rather than through a Python branch
  I  int arguments: same shapes through an int that is dynamic
Every program also multiplies the input by `s` so that the scalar becomes a dynamic graph input (the #197889 condition).
Default caches, fresh cache directory; every call is compared with eager; special values come late in the sequence.
"""
import os
import sys
import tempfile

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_v2_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch
import torch.nn.functional as F

print("torch", torch.__version__, flush=True)
torch.manual_seed(0)
X = torch.randn(8, 8)
NANX = X.clone(); NANX[0, 0] = float("nan")
FSEQ = (0.9, 0.5, 0.25, 0.75, 1.0, 0.0, 2.0, 0.5, -0.5, 0.125)
ISEQ = (3, 2, 4, 1, 5, 0, 2, 7)

FP = {
    # S: shapes / indices from the float
    "S zeros(int(s*8))": lambda x, s: x[0, :1] * s + torch.zeros(int(abs(s) * 8) + 1),
    "S x[: int(s*8)]": lambda x, s: (x * s)[: int(abs(s) * 8)],
    "S x[int(s*7)]": lambda x, s: (x * s)[int(abs(s) * 7) % 8],
    "S arange(0, s, 0.125)": lambda x, s: x[0, 0] * s + torch.arange(0, abs(s) + 0.01, 0.125),
    "S linspace steps int(s*8)+2": lambda x, s: x[0, 0] * s + torch.linspace(0, 1, int(abs(s) * 8) + 2),
    "S pad int(s*4)": lambda x, s: F.pad(x * s, (int(abs(s) * 4), 0)),
    "S repeat int(s*4)+1": lambda x, s: (x * s)[:1].repeat(int(abs(s) * 4) + 1, 1),
    "S roll int(s*8)": lambda x, s: (x * s).roll(int(s * 8), 0),
    "S topk int(s*6)+1": lambda x, s: (x * s).topk(int(abs(s) * 6) + 1).values,
    "S narrow int(s*6)": lambda x, s: (x * s).narrow(0, 0, int(abs(s) * 6) + 1),
    "S view(-1, 2**int(s*2))": lambda x, s: (x * s).reshape(-1, 2 ** int(abs(s) * 2)),
    "S tril(int(s*4))": lambda x, s: (x * s).tril(int(s * 4)),
    "S round(decimals=int(s*4))": lambda x, s: (x * s).round(decimals=int(abs(s) * 4)),
    "S cumsum(dim=int(s*2)%2)": lambda x, s: (x * s).cumsum(int(abs(s) * 2) % 2),
    "S one_hot(num_classes=int(s*8)+3)": lambda x, s: F.one_hot(torch.tensor([0, 1, 2]), int(abs(s) * 8) + 3) * (x[0, 0] * s),
    "S adaptive_avg_pool1d(int(s*6)+1)": lambda x, s: F.adaptive_avg_pool1d((x * s)[None], int(abs(s) * 6) + 1),
    "S interpolate size=int(s*8)+2": lambda x, s: F.interpolate((x * s)[None], size=int(abs(s) * 8) + 2),
    "S unfold size int(s*4)+1": lambda x, s: (x * s).unfold(0, int(abs(s) * 4) + 1, 1),
    # D: value-dependent decompositions
    "D pow(x, s*2)": lambda x, s: (x.abs() * (abs(s) + 1)) ** (s * 2),
    "D pow(x, s) at 0 with nan": lambda x, s: (NANX * (s + 3)) ** s,
    "D addmm beta=s (nan input, beta 0)": lambda x, s: torch.addmm(NANX, x * (s + 3), x, beta=s, alpha=1 - s),
    "D baddbmm beta=1-s": lambda x, s: torch.baddbmm(NANX[None], (x * (s + 3))[None], x[None], beta=1 - s, alpha=s),
    "D addcmul value=s (inf operand, value 0)": lambda x, s: torch.addcmul(x * (s + 3), x / 0.0, x, value=s),
    "D lerp weight 1-s": lambda x, s: torch.lerp(x * (s + 3), NANX, 1 - s),
    "D dropout p=s (0 or 1, train)": lambda x, s: F.dropout(x * (s + 3), p=s, training=True) if s in (0.0, 1.0) else x * (s + 3),
    "D clamp(min=s, max=1-s) crossing": lambda x, s: (x * (s + 3)).clamp(min=s, max=1 - s),
    "D hardtanh(-s, s) crossing": lambda x, s: F.hardtanh(x * (abs(s) + 3), -abs(s) - 0.01, abs(s) + 0.01),
    "D softplus beta=s+1 threshold=s*20": lambda x, s: F.softplus(x * (s + 3), beta=abs(s) + 1, threshold=abs(s) * 20),
    "D norm p=s*2": lambda x, s: (x * (s + 3)).norm(p=abs(s) * 2 + 0.5, dim=1),
    "D normalize p=s*2": lambda x, s: F.normalize(x * (s + 3), p=abs(s) * 2 + 0.5),
    "D mul by s==0 with nan": lambda x, s: NANX * s,
    "D where(x > s, s, 1-s)": lambda x, s: torch.where(x > s, s, 1 - s) * x,
    "D celu alpha=s+0.5": lambda x, s: F.celu(x * (s + 3), alpha=abs(s) + 0.5),
    "D logit eps=s/8": lambda x, s: torch.logit((x * (s + 3)).sigmoid(), eps=abs(s) / 8),
    "D std correction=int(s*2)": lambda x, s: (x * (s + 3)).std(correction=int(abs(s) * 2) % 2),
    "D leaky_relu(x, s) negative slope > 1": lambda x, s: F.leaky_relu(x * (s + 3), s * 2),
    # B: SymBool / comparisons as tensors' multipliers
    "B x * (s > 0.5)": lambda x, s: x * (s + 3) * (s > 0.5),
    "B x * (s == 1.0) + (s != 0.0)": lambda x, s: x * (s + 3) * (s == 1.0) + (s != 0.0),
    "B full((2,), s > 0.5)": lambda x, s: torch.full((2,), s > 0.5) & (x[0, :2] * (s + 3) > -100),
    "B masked_fill(x > 0, s > 0.5)": lambda x, s: (x * (s + 3)).masked_fill(x > 0, float(s > 0.5)),
    "B max(s, 0.3) * x + min(1-s, 0.6)": lambda x, s: x * (s + 3) * max(s, 0.3) + min(1 - s, 0.6),
    "B abs(s) and round(s, 1)": lambda x, s: x * (s + 3) * abs(s) + round(s, 1),
    "B int(s) + math-free floor": lambda x, s: x * (s + 3) + int(s) + (s // 0.5),
}
IP = {
    "I x[:k] * k": lambda x, k: (x * k)[: k],
    "I roll(k) + k % 3": lambda x, k: (x * k).roll(k, 1) + k % 3,
    "I pow(x, k)": lambda x, k: x ** k,
    "I x.long() ** k": lambda x, k: (x * 3).long() ** k,
    "I topk(k + 1)": lambda x, k: (x * k).topk(k + 1).values,
    "I repeat(k + 1)": lambda x, k: (x * k)[:1].repeat(k + 1, 1),
    "I addmm beta=k (0 with nan)": lambda x, k: torch.addmm(NANX, x * (k + 1), x, beta=k),
    "I arange(k) * (10 - k)": lambda x, k: x[0, 0] * k + torch.arange(k) * (10 - k),
    "I x.sum(k % 2) * (k // 2)": lambda x, k: (x * (k + 1)).sum(k % 2) * (k // 2),
    "I F.pad(x, (k, k % 2))": lambda x, k: F.pad(x * (k + 1), (k, k % 2)),
    "I tril(k - 2)": lambda x, k: (x * (k + 1)).tril(k - 2),
    "I one_hot(idx % (k + 1), k + 1)": lambda x, k: F.one_hot(torch.arange(4) % (k + 1), k + 1) * (k + 1),
    "I unflatten(0, (k or 1, -1))": lambda x, k: (x * (k + 1)).unflatten(0, (2 ** (k % 3), -1)),
}


def flat(o):
    if isinstance(o, (tuple, list)):
        return [t for x in o for t in flat(x)]
    return [o]


def run(name, f, seq):
    torch._dynamo.reset()
    try:
        g = torch.compile(f)
    except Exception as e:  # noqa: BLE001
        print("ER", name, type(e).__name__, flush=True); return
    bad = []
    for s in seq:
        try:
            w = flat(f(X.clone(), s)); werr = None
        except Exception as e:  # noqa: BLE001
            w, werr = None, type(e).__name__
        try:
            r = flat(g(X.clone(), s)); rerr = None
        except Exception as e:  # noqa: BLE001
            r, rerr = None, type(e).__name__
        if werr or rerr:
            if bool(werr) != bool(rerr):
                bad.append(f"s={s}: eager {'raises ' + werr if werr else 'ok'} / compiled {'raises ' + rerr if rerr else 'ok'}")
            continue
        for a, b in zip(w, r):
            if a.shape != b.shape or a.dtype != b.dtype:
                bad.append(f"s={s}: shape/dtype eager {tuple(a.shape)} {a.dtype} compiled {tuple(b.shape)} {b.dtype}"); break
            if not torch.allclose(a.double(), b.double(), rtol=1e-4, atol=1e-5, equal_nan=True):
                bad.append(f"s={s}: max err {(torch.nan_to_num(a.double()) - torch.nan_to_num(b.double())).abs().max().item():.3g} (nan pattern equal: {torch.equal(a.isnan(), b.isnan())})"); break
    print("!!" if bad else "  ", f"{name:44s}", "; ".join(bad[:4]), flush=True)


for name, f in FP.items():
    run(name, f, FSEQ)
for name, f in IP.items():
    run(name, f, ISEQ)
print("DONE", flush=True)
