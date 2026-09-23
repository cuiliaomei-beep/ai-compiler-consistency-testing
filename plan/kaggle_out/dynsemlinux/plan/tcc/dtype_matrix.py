"""6.2 dtype-promotion matrix: for binary / ternary / weighted ops, enumerate dtype pairs and argument forms and
compare ONLY (raised?, exception type, output dtype, output shape) between eager and a compiled backend.

No numeric comparison -> no tolerance questions, no false positives from rounding. Item 08 (BCE bf16 x fp32
weight -> Inductor float32) is the seed of this angle.

    python run.py dtypes --backend aot_eager --out results/dtypes_aot          # fast: ~0.2 s / case
    python run.py dtypes --backend inductor --pairs lowprec --out results/dtypes_ind
"""
import itertools
import json
import os
import time
from dataclasses import dataclass, asdict
from typing import Any, Callable, Dict, List, Optional, Tuple

import torch
import torch.nn.functional as F

DTYPES = [torch.bool, torch.int32, torch.int64, torch.float16, torch.bfloat16, torch.float32, torch.float64, torch.complex64]
LOWPREC = [torch.float16, torch.bfloat16]
FORMS = ("tt", "t0", "0t", "ts")     # tensor-tensor, tensor-0d, 0d-tensor, tensor-python-scalar


def _mk(shape, dt, g, kind="any"):
    """A tensor of dtype dt; kind steers the value range (prob in (0,1), positive, class index)."""
    if dt == torch.bool:
        return torch.randint(0, 2, shape, generator=g).bool()
    if dt in (torch.int32, torch.int64, torch.uint8, torch.int8):
        return torch.randint(1, 4, shape, generator=g).to(dt)
    if dt.is_complex:
        re = torch.rand(shape, generator=g) + 0.5
        return torch.complex(re, 0.5 * re).to(dt)
    x = torch.rand(shape, generator=g)
    if kind == "prob":
        return (0.1 + 0.8 * x).to(dt)
    if kind == "pos":
        return (0.5 + x).to(dt)
    return (x - 0.5).to(dt)


def _scalar_for(dt):
    if dt == torch.bool:
        return True
    if not dt.is_floating_point and not dt.is_complex:
        return 2
    if dt.is_complex:
        return 1.5 + 0.5j
    return 1.5


@dataclass
class Case:
    op: str
    dt1: str
    dt2: str
    form: str
    eager: str
    compiled: str
    kind: str           # "dtype" | "shape" | "raise" | "raise_type"


def _sig(r) -> str:
    if isinstance(r, Exception):
        return f"raise:{type(r).__name__}"
    if isinstance(r, torch.Tensor):
        return f"{str(r.dtype).split('.')[-1]}{tuple(r.shape)}"
    if isinstance(r, (tuple, list)):
        return "(" + ",".join(_sig(x) for x in r) + ")"
    return f"{type(r).__name__}:{r!r}"[:60]


def _call(fn, args):
    try:
        return fn(*args)
    except Exception as e:  # noqa: BLE001
        return e


def _full(a, b):
    """b as a tensor shaped like a (python scalar -> full tensor)."""
    return b if isinstance(b, torch.Tensor) else torch.full_like(a, b)


def _vec(w, n=4):
    """weight -> 1-d of length n (for nll / cross_entropy class weights)."""
    if w.dim() == 2:
        return w[0]
    if w.dim() == 1:
        return w
    return w.expand(n)


# --------------------------------------------------------------------------
# the operators: (name, fn(*args), builder(dt1, dt2, form, g) -> args or None)
# --------------------------------------------------------------------------

def _binary_builder(kind1="any", kind2="any"):
    def build(dt1, dt2, form, g):
        a = _mk((3, 4), dt1, g, kind1)
        if form == "tt":
            b = _mk((3, 4), dt2, g, kind2)
        elif form == "t0":
            b = _mk((), dt2, g, kind2)
        elif form == "0t":
            a = _mk((), dt1, g, kind1)
            b = _mk((3, 4), dt2, g, kind2)
        else:
            b = _scalar_for(dt2)
        return (a, b)
    return build


def _weighted_builder(needs_prob=True):
    """(input dt1, target dt1, weight dt2); weight form: same shape / 0-d / broadcast row."""
    def build(dt1, dt2, form, g):
        inp = _mk((3, 4), dt1, g, "prob" if needs_prob else "any")
        tgt = _mk((3, 4), dt1, g, "prob")
        if form == "tt":
            w = _mk((3, 4), dt2, g, "pos")
        elif form == "t0":
            w = _mk((), dt2, g, "pos")
        elif form == "0t":
            w = _mk((4,), dt2, g, "pos")
        else:
            return None
        return (inp, tgt, w)
    return build


def _cond(a):
    return (a.real if a.is_complex() else a) > 0 if a.dtype != torch.bool else a


OPS: List[Tuple[str, Callable, Callable]] = [
    ("add", torch.add, _binary_builder()),
    ("sub", torch.sub, _binary_builder()),
    ("mul", torch.mul, _binary_builder()),
    ("div", torch.div, _binary_builder()),
    ("div_floor", lambda a, b: torch.div(a, b, rounding_mode="floor"), _binary_builder()),
    ("true_divide", torch.true_divide, _binary_builder()),
    ("floor_divide", torch.floor_divide, _binary_builder(kind2="pos")),
    ("remainder", torch.remainder, _binary_builder(kind2="pos")),
    ("fmod", torch.fmod, _binary_builder(kind2="pos")),
    ("pow", torch.pow, _binary_builder(kind1="pos")),
    ("atan2", torch.atan2, _binary_builder()),
    ("copysign", torch.copysign, _binary_builder()),
    ("hypot", torch.hypot, _binary_builder()),
    ("xlogy", torch.xlogy, _binary_builder(kind2="pos")),
    ("logaddexp", torch.logaddexp, _binary_builder()),
    ("logaddexp2", torch.logaddexp2, _binary_builder()),
    ("maximum", torch.maximum, _binary_builder()),
    ("minimum", torch.minimum, _binary_builder()),
    ("fmax", torch.fmax, _binary_builder()),
    ("heaviside", torch.heaviside, _binary_builder()),
    ("ldexp", torch.ldexp, _binary_builder()),
    ("nextafter", torch.nextafter, _binary_builder()),
    ("eq", torch.eq, _binary_builder()),
    ("lt", torch.lt, _binary_builder()),
    ("bitwise_and", torch.bitwise_and, _binary_builder()),
    ("bitwise_xor", torch.bitwise_xor, _binary_builder()),
    ("logical_and", torch.logical_and, _binary_builder()),
    ("dist", torch.dist, _binary_builder()),
    ("mul_sum", lambda a, b: (a * b).sum(), _binary_builder()),
    ("where", lambda a, b: torch.where(_cond(a), a, b), _binary_builder()),
    ("lerp", lambda a, b: torch.lerp(a, b, 0.3), _binary_builder()),
    ("lerp_w", lambda a, b: torch.lerp(a, a, b), _binary_builder()),
    ("addcmul", lambda a, b: torch.addcmul(a, a, b), _binary_builder()),
    ("addcdiv", lambda a, b: torch.addcdiv(a, a, b), _binary_builder(kind2="pos")),
    ("clamp_min_t", lambda a, b: torch.clamp(a, min=b), _binary_builder()),
    ("clamp_minmax_t", lambda a, b: torch.clamp(a, min=b, max=b), _binary_builder()),
    ("masked_fill", lambda a, b: torch.masked_fill(a, _cond(a), b), _binary_builder()),
    ("cat", lambda a, b: torch.cat([a.reshape(-1), _full(a, b).reshape(-1)]), _binary_builder()),
    ("stack", lambda a, b: torch.stack([a, _full(a, b).expand_as(a)]), _binary_builder()),
    ("index_put", lambda a, b: a.clone().index_put_((torch.tensor([0], device=a.device),), _full(a, b).reshape(-1)[0]), _binary_builder()),
    ("scatter_add", lambda a, b: torch.zeros_like(a).scatter_add(0, torch.zeros_like(a, dtype=torch.long), _full(a, b).expand_as(a)), _binary_builder()),
    ("copy_", lambda a, b: a.clone().copy_(b), _binary_builder()),
    ("add_alpha", lambda a, b: torch.add(a, b, alpha=2), _binary_builder()),
    ("rsub", lambda a, b: torch.rsub(a, b), _binary_builder()),
    ("sum_dtype", lambda a, b: torch.sum(a, dtype=_full(a, b).dtype), _binary_builder()),
    ("cumsum_dtype", lambda a, b: torch.cumsum(a, -1, dtype=_full(a, b).dtype) if a.dim() else torch.cumsum(a.reshape(1), 0, dtype=_full(a, b).dtype), _binary_builder()),
    ("softmax_dtype", lambda a, b: torch.softmax(a, -1, dtype=_full(a, b).dtype) if a.dim() else torch.softmax(a.reshape(1), 0, dtype=_full(a, b).dtype), _binary_builder()),
    ("matmul", lambda a, b: a @ _full(a, b).expand_as(a).mT if a.dim() == 2 else a * _full(a, b), _binary_builder()),
    ("linear", lambda a, b: F.linear(a, _full(a, b).expand_as(a)) if a.dim() == 2 else a * _full(a, b), _binary_builder()),
    ("mse_loss", lambda a, b: F.mse_loss(a, _full(a, b).expand_as(a)), _binary_builder()),
    ("l1_loss", lambda a, b: F.l1_loss(a, _full(a, b).expand_as(a)), _binary_builder()),
    ("smooth_l1_loss", lambda a, b: F.smooth_l1_loss(a, _full(a, b).expand_as(a)), _binary_builder()),
    ("huber_loss", lambda a, b: F.huber_loss(a, _full(a, b).expand_as(a)), _binary_builder()),
    ("kl_div", lambda a, b: F.kl_div(a, _full(a, b).expand_as(a), reduction="batchmean" if a.dim() else "sum"), _binary_builder(kind2="pos")),
    ("poisson_nll", lambda a, b: F.poisson_nll_loss(a, _full(a, b).expand_as(a)), _binary_builder(kind2="pos")),
    ("gaussian_nll_var", lambda a, b: F.gaussian_nll_loss(a, a, _full(a, b).expand_as(a)), _binary_builder(kind2="pos")),
    ("cosine_sim", lambda a, b: F.cosine_similarity(a, _full(a, b).expand_as(a), dim=-1) if a.dim() else a * _full(a, b), _binary_builder()),
    # weighted losses: (input dt1, target dt1, weight dt2)
    ("bce_weight", lambda i, t, w: F.binary_cross_entropy(i, t, weight=w), _weighted_builder()),
    ("bce_logits_weight", lambda i, t, w: F.binary_cross_entropy_with_logits(i, t, weight=w), _weighted_builder(False)),
    ("bce_logits_pos_weight", lambda i, t, w: F.binary_cross_entropy_with_logits(i, t, pos_weight=w), _weighted_builder(False)),
    ("nll_weight", lambda i, t, w: F.nll_loss(i, torch.zeros(3, dtype=torch.long, device=i.device), weight=_vec(w)), _weighted_builder(False)),
    ("cross_entropy_weight", lambda i, t, w: F.cross_entropy(i, torch.zeros(3, dtype=torch.long, device=i.device), weight=_vec(w)), _weighted_builder(False)),
    ("cross_entropy_soft_w", lambda i, t, w: F.cross_entropy(i, t, weight=_vec(w)), _weighted_builder(False)),
    ("multilabel_soft_margin_w", lambda i, t, w: F.multilabel_soft_margin_loss(i, _cond(t), weight=_vec(w)), _weighted_builder(False)),
    ("margin_ranking", lambda i, t, w: F.margin_ranking_loss(i, t, torch.ones_like(_full(i, w).expand_as(i))), _weighted_builder(False)),
    ("triplet_margin", lambda i, t, w: F.triplet_margin_loss(i, t, _full(i, w).expand_as(i)), _weighted_builder(False)),
    ("cosine_embedding", lambda i, t, w: F.cosine_embedding_loss(i, t, torch.ones(3, dtype=w.dtype, device=i.device) if not w.dtype.is_complex else torch.ones(3, device=i.device)), _weighted_builder(False)),
    ("layer_norm_w", lambda i, t, w: F.layer_norm(i, (4,), weight=_vec(w), bias=_vec(w)), _weighted_builder(False)),
    ("group_norm_w", lambda i, t, w: F.group_norm(i.reshape(3, 4, 1), 2, weight=_vec(w), bias=_vec(w)), _weighted_builder(False)),
    ("batch_norm_w", lambda i, t, w: F.batch_norm(i, None, None, weight=_vec(w), bias=_vec(w), training=True), _weighted_builder(False)),
    ("rms_norm_w", lambda i, t, w: F.rms_norm(i, (4,), weight=_vec(w)), _weighted_builder(False)),
    ("prelu_w", lambda i, t, w: F.prelu(i, _vec(w)), _weighted_builder(False)),
    ("embedding_bag_w", lambda i, t, w: F.embedding_bag(torch.tensor([[0, 1, 2]], device=i.device), i, per_sample_weights=_vec(w, 3).reshape(1, 3), mode="sum"), _weighted_builder(False)),
]


def pairs(mode: str) -> List[Tuple[torch.dtype, torch.dtype]]:
    if mode == "lowprec":
        return [(a, b) for a in DTYPES for b in DTYPES if a in LOWPREC or b in LOWPREC]
    if mode == "float":
        fl = [d for d in DTYPES if d.is_floating_point or d.is_complex]
        return [(a, b) for a in fl for b in fl]
    return list(itertools.product(DTYPES, DTYPES))


def sweep(backend: str = "aot_eager", pair_mode: str = "all", only: Optional[List[str]] = None,
          forms: Tuple[str, ...] = FORMS, autocast: bool = False, log=print, jsonl: Optional[str] = None,
          seed: int = 0, device: str = "cpu") -> Dict[str, Any]:
    import torch._dynamo
    torch._dynamo.config.recompile_limit = 10 ** 6      # every dtype pair is a legitimate recompile
    torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
    g = torch.Generator().manual_seed(seed)
    cases: List[Case] = []
    n = 0
    t0 = time.time()
    ops = [(nm, f, b) for nm, f, b in OPS if not only or nm in only]
    for nm, f, build in ops:
        torch._dynamo.reset()
        cf = torch.compile(f, backend=backend, dynamic=False)
        for dt1, dt2 in pairs(pair_mode):
            for form in forms:
                args = build(dt1, dt2, form, g)
                if args is None:
                    continue
                if device != "cpu":
                    args = tuple(x.to(device) if isinstance(x, torch.Tensor) else x for x in args)
                n += 1
                with torch.no_grad():
                    if autocast:
                        with torch.autocast("cuda" if device.startswith("cuda") else "cpu", dtype=torch.bfloat16):
                            re = _call(f, args)
                            rc = _call(cf, args)
                    else:
                        re = _call(f, args)
                        rc = _call(cf, args)
                se, sc = _sig(re), _sig(rc)
                if se == sc:
                    continue
                if se.startswith("raise") != sc.startswith("raise"):
                    kind = "raise"
                elif se.startswith("raise"):
                    kind = "raise_type"
                elif se.split("(")[0] != sc.split("(")[0]:
                    kind = "dtype"
                else:
                    kind = "shape"
                c = Case(nm, str(dt1).split(".")[-1], str(dt2).split(".")[-1], form, se, sc, kind)
                cases.append(c)
                log(f"  DTYPE {nm:<24} {c.dt1:>9} x {c.dt2:<9} {form}  eager={se}  {backend}={sc}")
                if jsonl:
                    with open(jsonl, "a", encoding="utf-8") as fh:
                        fh.write(json.dumps(asdict(c)) + "\n")
        log(f"[{nm}] done: {n} cases so far, {len(cases)} mismatches, {time.time() - t0:.0f}s")
    return {"backend": backend, "pairs": pair_mode, "autocast": autocast, "device": device, "cases": n,
            "mismatches": [asdict(c) for c in cases], "wall_s": round(time.time() - t0, 1)}


def write_report(res: Dict[str, Any], out_dir: str) -> str:
    os.makedirs(out_dir, exist_ok=True)
    json.dump(res, open(os.path.join(out_dir, "dtype_matrix.json"), "w"), indent=1)
    ms = res["mismatches"]
    by_op: Dict[str, List[Dict[str, Any]]] = {}
    for m in ms:
        by_op.setdefault(m["op"], []).append(m)
    kinds = {k: sum(m["kind"] == k for m in ms) for k in ("dtype", "raise", "raise_type", "shape")}
    lines = [f"# dtype-promotion matrix ({res['backend']}, pairs={res['pairs']}, autocast={res['autocast']})", "",
             f"- cases: {res['cases']}, mismatches: {len(ms)} {kinds}; wall {res['wall_s']} s", ""]
    for op, lst in sorted(by_op.items(), key=lambda kv: -len(kv[1])):
        lines.append(f"## {op} ({len(lst)})")
        lines.append("| dt1 | dt2 | form | eager | compiled | kind |")
        lines.append("|---|---|---|---|---|---|")
        for m in lst:
            lines.append(f"| {m['dt1']} | {m['dt2']} | {m['form']} | {m['eager']} | {m['compiled']} | {m['kind']} |")
        lines.append("")
    p = os.path.join(out_dir, "DTYPE_MATRIX.md")
    open(p, "w", encoding="utf-8").write("\n".join(lines))
    return p
