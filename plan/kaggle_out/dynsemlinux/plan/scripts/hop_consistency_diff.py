"""8.5  Control-flow higher-order ops: torch.cond / while_loop / scan / associative_scan / torch.utils.checkpoint.
Each program runs in eager (the HOPs' Python implementations) and under torch.compile with backend eager / aot_eager /
inductor; values (NaN pattern, inf, sign of zero), dtype, shape, aliasing with the input, input mutation, gradients and
exception behaviour are compared.  Inputs include edge values and data-dependent predicates on both sides of the branch.
    python scripts/hop_consistency_diff.py [--backends eager,aot_eager,inductor] [--only NAME]
"""
import argparse
import json
import os
import sys
import tempfile

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_hop_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402
from torch._higher_order_ops import associative_scan, scan, while_loop  # noqa: E402
from torch.utils.checkpoint import checkpoint  # noqa: E402

torch._dynamo.config.capture_scalar_outputs = True
INF, NAN = float("inf"), float("nan")
X = torch.tensor([1.5, -2.0, 0.0, -0.0, INF, -INF, NAN, 3.0])
XI = torch.tensor([1, -2, 0, 7, -128, 127, 3, 5])
P = {}


def prog(name, f, *inputs):
    P[name] = (f, inputs)


# --- torch.cond
prog("cond: pred from data, both branches elementwise", lambda x: torch.cond(x.sum().isnan(), lambda x: x * 2, lambda x: x + 1, (x,)), X)
prog("cond: pred false, true branch sqrt", lambda x: torch.cond(x.shape[0] > 100, lambda x: x.sqrt(), lambda x: x.abs(), (x,)), X)
prog("cond: branches return different dtype (int vs float)", lambda x: torch.cond(x.sum() > 0, lambda x: x.long(), lambda x: x, (x,)), X.abs())
prog("cond: branch returns view of input", lambda x: torch.cond(x[0] > 0, lambda x: x[1:], lambda x: x[:-1], (x,)), X)
prog("cond: branch returns input itself", lambda x: torch.cond(x[0] > 0, lambda x: x, lambda x: x * 2, (x,)), X)
prog("cond: closure over outer tensor", lambda x, w: torch.cond(x[0] > 0, lambda x: x * w, lambda x: x / w, (x,)), X, torch.tensor([2.0]))
prog("cond: python bool pred", lambda x: torch.cond(True, lambda x: x * 2, lambda x: x + 1, (x,)), X)
prog("cond: pred is 0-d int tensor 0", lambda x: torch.cond(torch.tensor(0), lambda x: x * 2, lambda x: x + 1, (x,)), X)
prog("cond: pred NaN tensor", lambda x: torch.cond(torch.tensor(NAN), lambda x: x * 2, lambda x: x + 1, (x,)), X)
prog("cond: nested cond", lambda x: torch.cond(x[0] > 0, lambda x: torch.cond(x[1] > 0, lambda x: x + 1, lambda x: x + 2, (x,)), lambda x: x + 3, (x,)), X)
prog("cond: branches reduce to 0-d", lambda x: torch.cond(x[0] > 0, lambda x: x.nansum(), lambda x: x.sum(), (x,)), X)
prog("cond: int floor_divide / mod in branches", lambda x: torch.cond(x[0] > 0, lambda x: x // 3, lambda x: x % 3, (x,)), XI)
prog("cond: in-place inside branch on clone", lambda x: torch.cond(x[0] > 0, lambda x: x.clone().add_(1), lambda x: x.clone().mul_(2), (x,)), X)
prog("cond: grad through both branches", lambda x: torch.cond(x[0] > 0, lambda x: (x * x).sum(), lambda x: x.abs().sum(), (x,)), X.clone().requires_grad_())
prog("cond: pred from inf comparison", lambda x: torch.cond((x == INF).any(), lambda x: x.clamp(max=1.0), lambda x: x, (x,)), X)
prog("cond: bool tensor operands", lambda b: torch.cond(b.any(), lambda b: ~b, lambda b: b, (b,)), torch.tensor([True, False, True]))
prog("cond: float16 branch overflow", lambda x: torch.cond(x[0] > 0, lambda x: x * 65504.0, lambda x: x / 65504.0, (x,)), torch.tensor([300.0, 0.5], dtype=torch.float16))
prog("cond: branch with 0-size slice", lambda x: torch.cond(x[0] > 0, lambda x: x[:0].sum(), lambda x: x.sum(), (x,)), X)

# --- while_loop
prog("while_loop: count to 5", lambda x: while_loop(lambda i, x: i < 5, lambda i, x: (i + 1, x * 2), (torch.tensor(0), x)), X)
prog("while_loop: zero iterations", lambda x: while_loop(lambda i, x: i < 0, lambda i, x: (i + 1, x * 2), (torch.tensor(0), x)), X)
prog("while_loop: stop cond with NaN sum", lambda x: while_loop(lambda i, x: (i < 4) & (x.sum() < 100), lambda i, x: (i + 1, x + 1), (torch.tensor(0), x)), X)
prog("while_loop: int8 overflow wrap", lambda x: while_loop(lambda i, x: i < 3, lambda i, x: (i + 1, x * 2), (torch.tensor(0), x)), XI.to(torch.int8))
prog("while_loop: body returns carried input unchanged", lambda x: while_loop(lambda i, x: i < 3, lambda i, x: (i + 1, x), (torch.tensor(0), x)), X)
prog("while_loop: float counter 0.1 steps", lambda x: while_loop(lambda i, x: i < 1.0, lambda i, x: (i + 0.1, x + 1), (torch.tensor(0.0), x)), X)
prog("while_loop: grad through loop", lambda x: while_loop(lambda i, x: i < 3, lambda i, x: (i + 1, x * 1.5), (torch.tensor(0), x))[1].sum(), X.clone().requires_grad_())

# --- scan
prog("scan: running sum", lambda x: scan(lambda c, y: (c + y, c + y), torch.zeros(()), x), X)
prog("scan: running sum reverse", lambda x: scan(lambda c, y: (c + y, c + y), torch.zeros(()), x, reverse=True), X)
prog("scan: running max with nan", lambda x: scan(lambda c, y: (torch.maximum(c, y), torch.maximum(c, y)), torch.tensor(-INF), x), X)
prog("scan: int8 product wraps", lambda x: scan(lambda c, y: (c * y, c * y), torch.tensor(1, dtype=torch.int8), x), XI.to(torch.int8))
prog("scan: float carry, int xs", lambda x: scan(lambda c, y: (c + y, c), torch.zeros(()), x), XI)
prog("scan: length 1", lambda x: scan(lambda c, y: (c + y, c + y), torch.zeros(()), x[:1]), X)
prog("scan: 2-D along dim=1", lambda x: scan(lambda c, y: (c + y, c * y), torch.zeros(4), x.reshape(4, 2), dim=1), X)
prog("scan: grad", lambda x: scan(lambda c, y: (c * y, c), torch.ones(()), x)[1].sum(), X.clone().requires_grad_())

# --- associative_scan
prog("assoc_scan: add pointwise", lambda x: associative_scan(lambda a, b: a + b, x, 0), X)
prog("assoc_scan: add generic", lambda x: associative_scan(lambda a, b: a + b, x, 0, combine_mode="generic"), X)
prog("assoc_scan: mul with 0 and inf", lambda x: associative_scan(lambda a, b: a * b, x, 0), X)
prog("assoc_scan: max with nan", lambda x: associative_scan(lambda a, b: torch.maximum(a, b), x, 0), X)
prog("assoc_scan: reverse", lambda x: associative_scan(lambda a, b: a + b, x, 0, reverse=True), X)
prog("assoc_scan: int64 add", lambda x: associative_scan(lambda a, b: a + b, x, 0), XI)
prog("assoc_scan: 2-D dim=1", lambda x: associative_scan(lambda a, b: a + b, x.reshape(2, 4), 1), X)
prog("assoc_scan: cancellation vs cumsum", lambda x: associative_scan(lambda a, b: a + b, x, 0) - torch.cumsum(x, 0), torch.tensor([1e8, 1.0, -1e8, 1.0]))
prog("assoc_scan: grad", lambda x: associative_scan(lambda a, b: a * b, x, 0).sum(), torch.tensor([1.0, 2.0, 3.0, 4.0]).requires_grad_())

# --- checkpoint
prog("checkpoint: values", lambda x: checkpoint(lambda x: (x * 2).sin(), x, use_reentrant=False), X)
prog("checkpoint: grad", lambda x: checkpoint(lambda x: (x * x).sin().sum(), x, use_reentrant=False), X.clone().requires_grad_())
prog("checkpoint: dropout inside, rng preserved", lambda x: checkpoint(lambda x: F.dropout(x, 0.5, True), x, use_reentrant=False, preserve_rng_state=True), torch.ones(64))
prog("checkpoint: returns input view", lambda x: checkpoint(lambda x: x[1:], x, use_reentrant=False), X)
prog("checkpoint: in-place on clone inside", lambda x: checkpoint(lambda x: x.clone().add_(1), x, use_reentrant=False), X)


def norm(v):
    if isinstance(v, torch.Tensor):
        t = v.detach()
        return {"dtype": str(t.dtype), "shape": list(t.shape), "vals": [repr(x) for x in t.double().flatten().tolist()[:64]], "req": bool(v.requires_grad)}
    if isinstance(v, (tuple, list)):
        return [norm(x) for x in v]
    return repr(v)


def compare(a, b):
    if isinstance(a, dict) and isinstance(b, dict):
        if a["dtype"] != b["dtype"] or a["shape"] != b["shape"]:
            return f"dtype/shape {a['dtype']}{a['shape']} vs {b['dtype']}{b['shape']}"
        for x, y in zip(a["vals"], b["vals"]):
            if x != y:
                fx, fy = float(x), float(y)
                if (fx != fx) and (fy != fy):
                    continue
                if fx == fy or abs(fx - fy) <= 1e-5 * max(1.0, abs(fx), abs(fy)):
                    continue
                return f"value {x} vs {y}"
        return None
    if isinstance(a, list) and isinstance(b, list):
        if len(a) != len(b):
            return f"len {len(a)} vs {len(b)}"
        for x, y in zip(a, b):
            r = compare(x, y)
            if r:
                return r
        return None
    return None if a == b else f"{a} vs {b}"


def observe(f, inputs):
    ins = [x.clone().requires_grad_(x.requires_grad) if isinstance(x, torch.Tensor) else x for x in inputs]
    torch.manual_seed(0)
    try:
        out = f(*ins)
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__, "msg": str(e)[:200]}
    rec = {"out": norm(out), "inputs_after": [norm(x) for x in ins if isinstance(x, torch.Tensor)]}
    alias = []
    for o in (out if isinstance(out, (tuple, list)) else (out,)):
        if isinstance(o, torch.Tensor):
            alias.append(any(isinstance(x, torch.Tensor) and o.untyped_storage().data_ptr() == x.untyped_storage().data_ptr() for x in ins))
    rec["alias"] = alias
    if isinstance(out, torch.Tensor) and out.requires_grad and out.dim() == 0:
        try:
            g = torch.autograd.grad(out, [x for x in ins if isinstance(x, torch.Tensor) and x.requires_grad], allow_unused=True)
            rec["grad"] = [norm(x) if x is not None else None for x in g]
        except Exception as e:  # noqa: BLE001
            rec["grad"] = "raises " + type(e).__name__
    return rec


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--backends", default="eager,aot_eager,inductor")
    ap.add_argument("--only", default=None)
    ap.add_argument("--out", default="results/hop/cases.jsonl")
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    done = set()
    if os.path.exists(a.out):
        for l in open(a.out, encoding="utf-8"):
            try:
                done.add(json.loads(l)["op"])
            except Exception:  # noqa: BLE001
                pass
    with open(a.out, "a", encoding="utf-8") as f:
        for name, (fn, inputs) in P.items():
            if (a.only and a.only not in name) or name in done:
                continue
            e = observe(fn, inputs)
            rec = {"op": name, "eager": "raises " + e["raised"] if "raised" in e else "ok", "diffs": {}}
            for b in a.backends.split(","):
                torch._dynamo.reset()
                c = observe(torch.compile(fn, backend=b, fullgraph=False), inputs)
                if "raised" in e or "raised" in c:
                    if ("raised" in e) != ("raised" in c):
                        rec["diffs"][b] = ("SILENT eager raises " + e["raised"]) if "raised" in e else f"RAISES {c['raised']}: {c['msg'][:120]}"
                    elif e["raised"] != c["raised"]:
                        rec["diffs"][b] = f"exc-type {e['raised']} vs {c['raised']}"
                    continue
                for key in ("out", "inputs_after", "alias", "grad"):
                    if key in e or key in c:
                        r = compare(e.get(key), c.get(key))
                        if r:
                            rec["diffs"][b] = f"{key.upper()} {r}"
                            break
            rec["verdict"] = "ok" if not rec["diffs"] else "DIFF"
            f.write(json.dumps(rec) + "\n")
            print(f"{rec['verdict']:5s} {name:52s} {rec['diffs'] if rec['diffs'] else ''}"[:220], flush=True)


if __name__ == "__main__":
    main()
