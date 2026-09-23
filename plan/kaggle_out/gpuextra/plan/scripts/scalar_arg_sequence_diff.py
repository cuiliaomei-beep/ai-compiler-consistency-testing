"""10.9b  Python scalar arguments that change from call to call (automatic dynamic + caches).

The stale-alpha defect (#194976: `torch.add(e * d, p, alpha=1 - d)` reuses the previous `1 - d` once `d` has become an
automatically dynamic float and both the FX-graph cache and the AOTAutograd cache are on) was found by accident in the
model-surgery sweep.  This tool looks for the whole class: a program `f(x, y, s)` takes a Python float or int `s` that
reaches an operator through a keyword (alpha=, value=, min=, eps=, p=, ...), through arithmetic on the scalar
(1 - s, s * s, round(s, 1), s > 0.5, int(s * 10)), or through a shape/index position; one compiled function is called
with a sequence of values (static first call, the automatic-dynamic recompile, repeats, 0 / 1 / negative specials) in
the DEFAULT cache configuration with a fresh cache directory, and every call must equal eager.

    python scripts/scalar_arg_sequence_diff.py --isolate                       # this interpreter
    ..\\venv_nightly\\Scripts\\python.exe scripts/scalar_arg_sequence_diff.py --isolate --out-jsonl results/scalar_seq/nightly.jsonl
    python scripts/scalar_arg_sequence_diff.py --report [--out-jsonl ...]
"""
import argparse
import json
import math
import os
import sys
import tempfile

if os.environ.get("TCC_ISOLATED_CHILD") == "1":                 # fresh on-disk caches for every case, default cache switches
    os.environ["TORCHINDUCTOR_CACHE_DIR"] = tempfile.mkdtemp(prefix="tcc_scalar_seq_")
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
torch._dynamo.config.recompile_limit = 10 ** 4
FSEQ = [0.9, 0.5, 0.25, 0.75, 0.5, 1.0, 0.0, 2.0, -0.5, 0.1, 0.9]
ISEQ = [3, 2, 4, 1, 2, 5, 3, 0, 6, -1, 2]

FP = {  # f(x, y, m, s): x, y 1-D float (8); m (4, 4); s float
    "mul": lambda x, y, m, s: x * s, "rsub": lambda x, y, m, s: s - x, "div": lambda x, y, m, s: x / (s + 3), "rdiv": lambda x, y, m, s: s / (x.abs() + 1), "pow": lambda x, y, m, s: x.abs() ** s,
    "rpow": lambda x, y, m, s: (abs(s) + 1) ** x, "add_alpha": lambda x, y, m, s: torch.add(x, y, alpha=s), "add_alpha_1m": lambda x, y, m, s: torch.add(x, y, alpha=1 - s),
    "ema": lambda x, y, m, s: torch.add(x * s, y, alpha=1 - s), "ema_inplace": lambda x, y, m, s: x.clone().mul_(s).add_(y, alpha=1 - s), "ema_functional": lambda x, y, m, s: x * s + y * (1 - s),
    "sub_alpha": lambda x, y, m, s: torch.sub(x * s, y, alpha=1 - s), "addcmul_value": lambda x, y, m, s: torch.addcmul(x * s, x, y, value=1 - s), "addcdiv_value": lambda x, y, m, s: torch.addcdiv(x * s, x, y.abs() + 1, value=s * 2),
    "lerp": lambda x, y, m, s: torch.lerp(x, y, s), "lerp_derived": lambda x, y, m, s: torch.lerp(x * s, y, 1 - s), "clamp_min": lambda x, y, m, s: x.clamp(min=s), "clamp_sym": lambda x, y, m, s: (x * s).clamp(-abs(s), abs(s) / 2),
    "clamp_derived": lambda x, y, m, s: x.clamp(max=s * 2 - 1), "full_like": lambda x, y, m, s: torch.full_like(x, s) + x * (1 - s), "fill_": lambda x, y, m, s: x.clone().fill_(s * s), "masked_fill": lambda x, y, m, s: (x * s).masked_fill(x > 0, 1 - s),
    "where_scalar": lambda x, y, m, s: torch.where(x > s, x, s), "where_both": lambda x, y, m, s: torch.where(x > s, s * 2, 1 - s), "threshold": lambda x, y, m, s: F.threshold(x * s, s, -s), "leaky_relu": lambda x, y, m, s: F.leaky_relu(x * s, abs(s) / 2),
    "elu_alpha": lambda x, y, m, s: F.elu(x * s, alpha=abs(s) + 0.5), "celu_alpha": lambda x, y, m, s: F.celu(x, alpha=abs(s) + 0.5), "softplus_beta": lambda x, y, m, s: F.softplus(x * s, beta=abs(s) + 0.5, threshold=20 - s),
    "hardtanh": lambda x, y, m, s: F.hardtanh(x * 2, -abs(s) - 0.1, abs(s) + 0.1), "hardshrink": lambda x, y, m, s: F.hardshrink(x * (1 - s), abs(s)), "softshrink": lambda x, y, m, s: F.softshrink(x * (1 - s), abs(s)),
    "normalize_eps": lambda x, y, m, s: F.normalize(m * s, eps=abs(s) + 1e-3), "layer_norm_eps": lambda x, y, m, s: F.layer_norm(m * (1 + s), (4,), eps=abs(s) + 1e-3), "nan_to_num": lambda x, y, m, s: torch.nan_to_num(x / (x - x + s - s), nan=s, posinf=1 - s),
    "addmm_beta_alpha": lambda x, y, m, s: torch.addmm(m, m, m, beta=s, alpha=1 - s), "baddbmm": lambda x, y, m, s: torch.baddbmm(m[None], m[None], m[None], beta=1 - s, alpha=s), "addmv": lambda x, y, m, s: torch.addmv(x[:4], m, y[:4], beta=s, alpha=1 - s),
    "addr": lambda x, y, m, s: torch.addr(m, x[:4], y[:4], beta=1 - s, alpha=s), "norm_p": lambda x, y, m, s: x.norm(p=abs(s) + 1), "dist_p": lambda x, y, m, s: torch.dist(x * s, y, p=abs(s) + 1), "softmax_temp": lambda x, y, m, s: F.softmax(x / (abs(s) + 0.1), 0),
    "quantile": lambda x, y, m, s: torch.quantile(x, min(abs(s), 1.0)), "histc_range": lambda x, y, m, s: torch.histc(x, bins=4, min=-abs(s) - 1, max=abs(s) + 1), "scalar_square": lambda x, y, m, s: x * (s * s) + (1 - s) ** 2,
    "scalar_branch": lambda x, y, m, s: x * s if s > 0.5 else y * (1 - s), "scalar_bool_mul": lambda x, y, m, s: x * (s > 0.5) + y * (s <= 0.5), "scalar_int": lambda x, y, m, s: x * int(s * 10) + (1 - s), "scalar_round": lambda x, y, m, s: x * round(s, 1) + round(1 - s),
    "scalar_math": lambda x, y, m, s: x * math.sin(s) + math.cos(1 - s), "scalar_max": lambda x, y, m, s: x * max(s, 0.3) + min(1 - s, 0.6), "scalar_abs_neg": lambda x, y, m, s: x * abs(s) - (-s), "scalar_floor_div": lambda x, y, m, s: x * (s // 0.25) + (s % 0.25),
    "scalar_tensor": lambda x, y, m, s: x + torch.tensor(s) * (1 - s), "scalar_full": lambda x, y, m, s: x[:3] * torch.full((3,), s) + torch.full((3,), 1 - s), "linspace_end": lambda x, y, m, s: torch.linspace(0, s, 5) * (1 - s),
    "two_uses_kw": lambda x, y, m, s: torch.add(torch.add(x, y, alpha=s), y, alpha=1 - s), "kw_and_clamp": lambda x, y, m, s: torch.add(x, y, alpha=1 - s).clamp(min=s - 1, max=s + 1), "momentum_sgd": lambda x, y, m, s: (x * s + y, y - (x * s + y) * (1 - s)),
    "bn_momentum": lambda x, y, m, s: _bn(m, abs(s) / 2 + 0.01), "dropout_p_eval": lambda x, y, m, s: F.dropout(x, min(abs(s), 0.99), training=False) * s, "scaled_grad": lambda x, y, m, s: _grad(lambda t: (t * s).pow(2).sum() * (1 - s), x),
    "ema_grad": lambda x, y, m, s: _grad(lambda t: torch.add(t * s, y, alpha=1 - s).pow(2).sum(), x), "lerp_grad": lambda x, y, m, s: _grad(lambda t: torch.lerp(t, y, s).pow(2).sum(), x),
}
IP = {  # f(x, y, m, k): k int
    "roll": lambda x, y, m, k: x.roll(k), "index": lambda x, y, m, k: x[k], "slice": lambda x, y, m, k: x[:k], "slice_pair": lambda x, y, m, k: torch.cat([x[k:], y[:k]]), "repeat": lambda x, y, m, k: x[:2].repeat(max(k, 0)),
    "sum_dim": lambda x, y, m, k: m.sum(k % 2), "topk": lambda x, y, m, k: x.topk(max(k, 1)).values, "view": lambda x, y, m, k: x.view(2 ** (abs(k) % 3), -1), "shift": lambda x, y, m, k: x.long() << (k % 5), "int_pow": lambda x, y, m, k: x.long() ** (abs(k) % 4),
    "diag": lambda x, y, m, k: torch.diag(m, k % 3 - 1), "tril": lambda x, y, m, k: m.tril(k - 2), "unfold": lambda x, y, m, k: x.unfold(0, max(k, 1), 1), "pad": lambda x, y, m, k: F.pad(x, (k, 0)), "narrow": lambda x, y, m, k: x.narrow(0, 0, max(k, 0)),
    "full_n": lambda x, y, m, k: torch.full((max(k, 0),), 1.5) * k, "arange": lambda x, y, m, k: torch.arange(k) * (10 - k), "chunk": lambda x, y, m, k: list(x.chunk(max(k, 1))), "kthvalue": lambda x, y, m, k: x.kthvalue(max(k, 1)).values,
    "one_hot": lambda x, y, m, k: F.one_hot(torch.tensor([0, 1, 2]), abs(k) + 3), "repeat_interleave": lambda x, y, m, k: x[:3].repeat_interleave(max(k, 0)), "int_alpha": lambda x, y, m, k: torch.add(x * k, y, alpha=10 - k),
    "int_floordiv": lambda x, y, m, k: (x * 10).long() // (k if k else 1) + (10 - k), "int_mod": lambda x, y, m, k: (x * 10).long() % (k if k else 1), "int_mix": lambda x, y, m, k: x * k + y * (10 - k) + k * k, "int_branch": lambda x, y, m, k: x * k if k % 2 else y * (k + 1),
    "int_clamp": lambda x, y, m, k: (x * 5).clamp(min=k - 3, max=k), "int_loop": lambda x, y, m, k: _loop(x, max(k, 0)), "int_bool": lambda x, y, m, k: x * (k > 2) + y * (k <= 2), "int_truediv": lambda x, y, m, k: x * (k / 4) + (k // 4), "int_neg_index": lambda x, y, m, k: x[-abs(k) - 1] * k,
    "int_new_shape": lambda x, y, m, k: x.new_zeros(abs(k), 2) + k, "int_cumsum_dim": lambda x, y, m, k: m.cumsum(k % 2) * (k % 3), "int_transpose": lambda x, y, m, k: (m * k).transpose(0, k % 2), "int_embedding": lambda x, y, m, k: m[abs(k) % 4] * (10 - k),
    "int_grad": lambda x, y, m, k: _grad(lambda t: (t * k).pow(2).sum() * (10 - k), x),
}


def _bn(m, momentum):
    rm, rv = torch.zeros(4), torch.ones(4)
    out = F.batch_norm(m, rm, rv, training=True, momentum=momentum)
    return out, rm, rv


def _grad(f, x):
    t = x.detach().clone().requires_grad_()
    return torch.autograd.grad(f(t), t)[0]


def _loop(x, k):
    for i in range(k):
        x = x * (i + 1) + 1
    return x


def cases():
    return ["f:" + k for k in FP] + ["i:" + k for k in IP]


def norm(o):
    if isinstance(o, torch.Tensor):
        return {"T": str(o.dtype), "shape": list(o.shape), "v": [("nan" if v != v else float(v)) for v in o.detach().flatten().double().tolist()]}
    if isinstance(o, (list, tuple)):
        return [norm(x) for x in o]
    return o if isinstance(o, (int, float, bool, str)) or o is None else repr(type(o).__name__)


def close(a, b):
    if isinstance(a, dict) and isinstance(b, dict) and "v" in a and "v" in b:
        if a["T"] != b["T"] or a["shape"] != b["shape"]:
            return False
        return all(x == y or (isinstance(x, float) and isinstance(y, float) and abs(x - y) <= 1e-5 * max(1.0, abs(x), abs(y))) for x, y in zip(a["v"], b["v"]))
    if isinstance(a, list) and isinstance(b, list):
        return len(a) == len(b) and all(close(x, y) for x, y in zip(a, b))
    if isinstance(a, float) and isinstance(b, float):
        return a == b or abs(a - b) <= 1e-5 * max(1.0, abs(a), abs(b))
    return a == b


def observe(f, s):
    g = torch.Generator().manual_seed(0)
    x, y, m = torch.randn(8, generator=g), torch.randn(8, generator=g), torch.randn(4, 4, generator=g)
    try:
        return norm(f(x, y, m, s))
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__}


def run_case(name, backends):
    kind, key = name.split(":", 1)
    f, seq = (FP[key], FSEQ) if kind == "f" else (IP[key], ISEQ)
    rec = {"op": name, "torch": torch.__version__, "diffs": []}
    for backend in backends:
        torch._dynamo.reset()
        cf = torch.compile(f, backend=backend)
        for step, s in enumerate(seq):
            want, got = observe(f, s), observe(cf, s)
            if not close(want, got):
                er, cr = isinstance(want, dict) and "raised" in want, isinstance(got, dict) and "raised" in got
                if er and cr:
                    continue
                rec["diffs"].append({"backend": backend, "step": step, "s": s, "class": "SILENT" if er else "RAISES" if cr else "VALUE", "eager": want, "compiled": got})
    classes = sorted({d["class"] for d in rec["diffs"]})
    rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
    return rec


def report(path):
    from collections import Counter
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    print(len(rows), dict(Counter(r["verdict"] for r in rows)), "torch", sorted({r.get("torch", "?") for r in rows}))
    for r in rows:
        if r["verdict"] == "ok":
            continue
        print(f"\n[{r['verdict']}] {r['op']}")
        if r["verdict"] == "CRASH":
            print("   rc", r.get("returncode"), r.get("tail", "")[-300:]); continue
        shown = set()
        for d in r["diffs"]:
            key = (d["backend"], d["class"])
            if key in shown:
                continue
            shown.add(key)
            steps = [(x["step"], x["s"]) for x in r["diffs"] if (x["backend"], x["class"]) == key]
            print(f"   {d['backend']:9s} {d['class']:6s} at (step, s)={steps}: eager {json.dumps(d['eager'])[:130]}  compiled {json.dumps(d['compiled'])[:130]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "scalar_seq", "release.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = a.only.split(",") if a.only else cases()
    if a.isolate:
        return run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=2400)
    for n in names:
        rec = run_case(n, a.backends.split(","))
        jsonl_append(a.out_jsonl, rec)
        if rec["verdict"] != "ok":
            print(f"  !! {n}: {rec['verdict']}", flush=True)


if __name__ == "__main__":
    main()
