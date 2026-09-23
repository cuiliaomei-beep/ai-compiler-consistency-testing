"""8.3b  Binary elementwise functions and reductions vs a 30-digit mpmath reference (extension of special_vs_mpmath.py,
which only covers unary functions).  eager and torch.compile (Inductor CPU) on 64-element float32/float64 tensors so
the vector path is exercised; a case is reported when the compiled relative error exceeds both 1e-6 and 100x the eager
error, or when the NaN/inf pattern differs from eager.
    python scripts/binary_vs_mpmath.py          -> results/binary_mpmath.jsonl
"""
import itertools
import json
import math
import os
import sys
import tempfile

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_bin_"))
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from mpmath import mp  # noqa: E402

mp.dps = 30
print("torch", torch.__version__, flush=True)


def fl(v):
    return float(v.real) if hasattr(v, "real") else float(v)


# ---------------- binary elementwise: name -> (torch fn, mpmath fn, x samples, y samples) ----------------
def small(fi):
    return [fi.tiny, fi.eps ** 2, fi.eps, 1e-6, 1e-3, 0.1]


def big(fi):
    return [1e3, 1e6, math.sqrt(fi.max) * 0.99, math.sqrt(fi.max) * 1.01, fi.max / 4, fi.max]


def mixed(fi):
    return [-fi.max / 2, -1e6, -3.5, -1.0, -0.5, -1e-3, -fi.tiny, -0.0, 0.0, fi.tiny, 1e-3, 0.5, 1.0, 3.5, 1e6, fi.max / 2]


BIN = {
    "pow": (torch.pow, lambda x, y: mp.power(x, y), lambda fi: [-8.0, -2.0, -1.0, -0.5, 0.0, 0.5, 1.0, 2.0, 10.0, 1e3, fi.tiny, fi.max], lambda fi: [-3.0, -1.0, -0.5, 0.0, 0.5, 1.0, 2.0, 3.0, 4.0, 0.333, 10.0, 100.0, 1e-3, 1e-6]),
    "atan2": (torch.atan2, mp.atan2, mixed, mixed),
    "hypot": (torch.hypot, mp.hypot, lambda fi: small(fi) + big(fi), lambda fi: small(fi) + big(fi)),
    "xlogy": (torch.xlogy, lambda x, y: 0 if x == 0 else x * mp.log(y), lambda fi: [0.0, fi.tiny, 1e-3, 1.0, 1e3, fi.max / 4], lambda fi: [fi.tiny, fi.eps, 1e-3, 1.0 - fi.eps, 1.0, 1.0 + fi.eps, 2.0, 1e6, fi.max]),
    "xlog1py": (torch.special.xlog1py, lambda x, y: 0 if x == 0 else x * mp.log1p(y), lambda fi: [0.0, fi.tiny, 1e-3, 1.0, 1e3], lambda fi: [-1.0 + fi.eps, -0.5, -fi.eps, -fi.tiny, 0.0, fi.tiny, fi.eps, 1e-3, 1.0, 1e6, fi.max]),
    "logaddexp": (torch.logaddexp, lambda x, y: mp.log(mp.exp(x) + mp.exp(y)), lambda fi: [-1e30, -1e6, -100.0, -1.0, 0.0, 1.0, 88.0, 89.0, 700.0, 710.0, 1e6, 1e30], lambda fi: [-1e30, -1e6, -100.0, -1.0, 0.0, 1.0, 88.0, 89.0, 700.0, 710.0, 1e6, 1e30]),
    "logaddexp2": (torch.logaddexp2, lambda x, y: mp.log(mp.power(2, x) + mp.power(2, y), 2), lambda fi: [-1e30, -1e6, -100.0, -1.0, 0.0, 1.0, 126.0, 128.0, 1023.0, 1025.0, 1e6, 1e30], lambda fi: [-1e30, -1e6, -100.0, -1.0, 0.0, 1.0, 126.0, 128.0, 1023.0, 1025.0, 1e6, 1e30]),
    "fmod": (torch.fmod, lambda x, y: mp.fmod(x, y), lambda fi: [-1e30, -1e6, -7.5, -1.0, -fi.eps, 0.0, fi.eps, 1.0, 7.5, 1e6, 1e30, fi.max], lambda fi: [-3.0, -1.0, -0.1, 0.1, 0.3, 1.0, 3.0, 1e-6, 1e6, fi.tiny]),
    "remainder": (torch.remainder, lambda x, y: x - y * mp.floor(x / y), lambda fi: [-1e30, -1e6, -7.5, -1.0, -fi.eps, 0.0, fi.eps, 1.0, 7.5, 1e6, 1e30, fi.max], lambda fi: [-3.0, -1.0, -0.1, 0.1, 0.3, 1.0, 3.0, 1e-6, 1e6, fi.tiny]),
    "copysign": (torch.copysign, lambda x, y: abs(x) if (y > 0 or (y == 0 and math.copysign(1, float(y)) > 0)) else -abs(x), mixed, lambda fi: [-1.0, -0.0, 0.0, 1.0, fi.tiny, -fi.tiny]),
    "ldexp": (torch.ldexp, lambda x, y: x * mp.power(2, int(y)), lambda fi: [1.0, 1.5, -1.5, fi.tiny, fi.max / 2, 3.0], lambda fi: [-200.0, -150.0, -126.0, -1.0, 0.0, 1.0, 100.0, 126.0, 127.0, 128.0, 1000.0]),
    "zeta": (torch.special.zeta, mp.zeta, lambda fi: [1.0 + 1e-3, 1.5, 2.0, 3.0, 10.0, 50.0, 100.0, 1e3, 1e4], lambda fi: [1.0, 2.0, 0.5, 10.0, 100.0, 1e3, 1e5, fi.tiny]),
    "polygamma1": (lambda x, y: torch.polygamma(1, y), lambda x, y: mp.polygamma(1, y), lambda fi: [1.0], lambda fi: [fi.tiny, 1e-6, 1e-3, 0.5, 1.0, 2.0, 10.0, 100.0, 1e3, 1e6, 1e10, -0.5, -1.5, -2.5, -10.5]),
    "polygamma2": (lambda x, y: torch.polygamma(2, y), lambda x, y: mp.polygamma(2, y), lambda fi: [1.0], lambda fi: [fi.tiny, 1e-6, 1e-3, 0.5, 1.0, 2.0, 10.0, 100.0, 1e3, 1e6, -0.5, -1.5, -10.5]),
    "igamma": (torch.igamma, lambda a, x: mp.gammainc(a, 0, x, regularized=True), lambda fi: [1e-3, 0.5, 1.0, 2.0, 10.0, 100.0, 1e3], lambda fi: [fi.tiny, 1e-6, 1e-3, 0.5, 1.0, 10.0, 100.0, 1e3, 1e4]),
    "igammac": (torch.igammac, lambda a, x: mp.gammainc(a, x, mp.inf, regularized=True), lambda fi: [1e-3, 0.5, 1.0, 2.0, 10.0, 100.0, 1e3], lambda fi: [fi.tiny, 1e-6, 1e-3, 0.5, 1.0, 10.0, 100.0, 1e3, 1e4]),
    "lerp": (lambda x, y: torch.lerp(x, y, torch.full_like(x, 0.999999)), lambda x, y: x + mp.mpf("0.999999") * (y - x), lambda fi: [-1e30, -1e6, -1.0, 0.0, 1.0, 1e6, 1e30], lambda fi: [-1e30, -1e6, -1.0, 0.0, 1.0, 1e6, 1e30]),
    "div": (torch.div, lambda x, y: x / y, mixed, lambda fi: [-1e6, -3.0, -fi.tiny, fi.tiny, 3.0, 1e6, fi.max, fi.eps]),
    "floor_divide": (torch.floor_divide, lambda x, y: mp.floor(x / y), lambda fi: [-1e30, -1e6, -7.5, -1.0, -fi.eps, 0.0, fi.eps, 1.0, 7.5, 1e6, 1e30, fi.max], lambda fi: [-3.0, -1.0, -0.1, 0.1, 0.3, 1.0, 3.0, 1e-6, 1e6]),
    "sub": (torch.sub, lambda x, y: x - y, lambda fi: [1.0, 1.0 + fi.eps, 1e6, 1e6 + 1, fi.max, -fi.max, 1e-3], lambda fi: [1.0, 1.0 + fi.eps, 1e6, 1e6 + 1, fi.max, -fi.max, 1e-3]),
    "mul": (torch.mul, lambda x, y: x * y, lambda fi: [fi.tiny, fi.eps, 1.0, 1e10, math.sqrt(fi.max), fi.max, -fi.max], lambda fi: [fi.tiny, fi.eps, 1.0, 1e10, math.sqrt(fi.max), fi.max, -fi.max]),
    "fmax": (torch.fmax, lambda x, y: max(x, y), mixed, mixed), "maximum": (torch.maximum, lambda x, y: max(x, y), mixed, mixed),
    "nextafter": (torch.nextafter, None, mixed, mixed),
}

# ---------------- reductions: name -> (torch fn, mpmath fn over python list, input builders) ----------------
def patt(fi):
    m = fi.max
    return {
        "big_cancel": [m / 2, -m / 2, 1.0] * 21 + [0.0],
        "alternating_ones": [1.0, -1.0] * 31 + [1e-3, 1e-3],
        "tiny": [fi.tiny] * 64, "tiny_mixed": [fi.tiny, fi.eps, 1e-3, 1.0] * 16,
        "large_uniform": [m / 8] * 64, "large_uniform_neg": [-m / 8] * 64, "sqrtmax": [math.sqrt(m) * 1.01] * 64,
        "wide_range": [fi.tiny * 2 ** k for k in range(0, 60, 2)] + [1.0] * 34,
        "one_plus_eps": [1.0 + fi.eps] * 64, "ramp": [float(k) for k in range(64)], "small_then_big": [1e-30] * 63 + [1e30],
        "logsumexp_big": [700.0, 709.0, 710.0, 88.0, 89.0] * 12 + [0.0] * 4, "logsumexp_neg": [-1e30, -1e6, -745.0, -100.0] * 16,
        "prod_under": [0.5] * 64, "prod_over": [2.0] * 64, "prod_mixed": [1e-10, 1e10] * 32, "prod_neg": [-1.5] * 64,
        "nan_inf": [1.0, float("inf"), -1.0] * 21 + [0.0],
    }


RED = {
    "sum": (torch.sum, lambda xs: mp.fsum(xs)), "mean": (torch.mean, lambda xs: mp.fsum(xs) / len(xs)),
    "prod": (torch.prod, lambda xs: mp.fprod(xs)), "logsumexp": (lambda x: torch.logsumexp(x, 0), lambda xs: mp.log(mp.fsum(mp.exp(v) for v in xs))),
    "norm2": (lambda x: torch.linalg.vector_norm(x, 2), lambda xs: mp.sqrt(mp.fsum(v * v for v in xs))), "norm1": (lambda x: torch.linalg.vector_norm(x, 1), lambda xs: mp.fsum(abs(v) for v in xs)),
    "norminf": (lambda x: torch.linalg.vector_norm(x, float("inf")), lambda xs: max(abs(v) for v in xs)), "norm3": (lambda x: torch.linalg.vector_norm(x, 3), lambda xs: mp.power(mp.fsum(abs(v) ** 3 for v in xs), mp.mpf(1) / 3)),
    "var": (lambda x: torch.var(x), lambda xs: (lambda m: mp.fsum((v - m) ** 2 for v in xs) / (len(xs) - 1))(mp.fsum(xs) / len(xs))),
    "std": (lambda x: torch.std(x), lambda xs: mp.sqrt((lambda m: mp.fsum((v - m) ** 2 for v in xs) / (len(xs) - 1))(mp.fsum(xs) / len(xs)))),
    "cumsum_last": (lambda x: torch.cumsum(x, 0)[-1], lambda xs: mp.fsum(xs)), "cumprod_last": (lambda x: torch.cumprod(x, 0)[-1], lambda xs: mp.fprod(xs)),
    "logcumsumexp_last": (lambda x: torch.logcumsumexp(x, 0)[-1], lambda xs: mp.log(mp.fsum(mp.exp(v) for v in xs))),
    "softmax_first": (lambda x: torch.softmax(x, 0)[0], lambda xs: mp.exp(xs[0]) / mp.fsum(mp.exp(v) for v in xs)),
    "log_softmax_first": (lambda x: torch.log_softmax(x, 0)[0], lambda xs: xs[0] - mp.log(mp.fsum(mp.exp(v) for v in xs))),
    "dot_self": (lambda x: torch.dot(x, x), lambda xs: mp.fsum(v * v for v in xs)), "amax": (torch.amax, lambda xs: max(xs)),
    "dist": (lambda x: torch.dist(x, torch.flip(x, [0])), lambda xs: mp.sqrt(mp.fsum((xs[i] - xs[-1 - i]) ** 2 for i in range(len(xs))))),
}


def flag(ev, cv, r, fi):
    if (math.isnan(ev) != math.isnan(cv)) or (math.isinf(ev) != math.isinf(cv)) or (math.isinf(ev) and math.isinf(cv) and (ev > 0) != (cv > 0)):
        return "nan/inf pattern", None, None
    if math.isnan(ev) or math.isinf(ev) or math.isnan(r) or math.isinf(r):
        return None, None, None
    scale = max(abs(r), fi.tiny)
    ee, ce = abs(ev - r) / scale, abs(cv - r) / scale
    if ce > 1e-6 and ce > 100 * max(ee, fi.eps / 4):
        return "accuracy", ee, ce
    return None, ee, ce


def run():
    out = open("results/binary_mpmath.jsonl", "w", encoding="utf-8")
    n_flag = 0
    for name, (tf, mf, xs, ys) in BIN.items():
        for dt in (torch.float32, torch.float64):
            fi = torch.finfo(dt)
            pairs = list(itertools.product(sorted({float(torch.tensor(v, dtype=dt).item()) for v in xs(fi)}), sorted({float(torch.tensor(v, dtype=dt).item()) for v in ys(fi)})))
            rows = []
            for k in range(0, len(pairs), 64):
                chunk = (pairs[k:k + 64] * 64)[:64]
                x = torch.tensor([p[0] for p in chunk], dtype=dt); y = torch.tensor([p[1] for p in chunk], dtype=dt)
                torch._dynamo.reset()
                try:
                    e = tf(x, y); c = torch.compile(tf)(x, y)
                except Exception as ex:  # noqa: BLE001
                    rows.append({"error": type(ex).__name__, "msg": str(ex)[:200]}); break
                for i in range(64):
                    ev, cv = e[i].item(), c[i].item()
                    if mf is None:  # exact functions: compare bit-for-bit
                        if not (ev == cv or (math.isnan(ev) and math.isnan(cv))):
                            rows.append({"x": chunk[i][0], "y": chunk[i][1], "eager": ev, "compiled": cv, "kind": "mismatch"})
                        continue
                    try:
                        r = fl(mf(mp.mpf(chunk[i][0]), mp.mpf(chunk[i][1])))
                    except Exception:  # noqa: BLE001
                        continue
                    kind, ee, ce = flag(ev, cv, r, fi)
                    if kind:
                        rows.append({"x": chunk[i][0], "y": chunk[i][1], "eager": ev, "compiled": cv, "ref": r, "eager_rel": ee, "compiled_rel": ce, "kind": kind})
            rec = {"fn": name, "dtype": str(dt).split(".")[-1], "pairs": len(pairs), "flagged": rows}
            out.write(json.dumps(rec) + "\n"); out.flush()
            if rows:
                n_flag += 1
                w = max(rows, key=lambda r: r.get("compiled_rel") or 1.0)
                print(f"!! {name:12s} {rec['dtype']:8s} {len(rows):3d}/{len(pairs)}  worst {w}", flush=True)
    for name, (tf, mf) in RED.items():
        for dt in (torch.float32, torch.float64):
            fi = torch.finfo(dt)
            rows = []
            for pname, vals in patt(fi).items():
                x = torch.tensor(vals, dtype=dt)
                torch._dynamo.reset()
                try:
                    e = tf(x); c = torch.compile(tf)(x)
                except Exception as ex:  # noqa: BLE001
                    rows.append({"pattern": pname, "error": type(ex).__name__, "msg": str(ex)[:200]}); continue
                try:
                    r = fl(mf([mp.mpf(v) for v in x.tolist()]))
                except Exception:  # noqa: BLE001
                    continue
                ev, cv = e.item(), c.item()
                kind, ee, ce = flag(ev, cv, r, fi)
                if kind:
                    rows.append({"pattern": pname, "eager": ev, "compiled": cv, "ref": r, "eager_rel": ee, "compiled_rel": ce, "kind": kind})
            rec = {"fn": "red:" + name, "dtype": str(dt).split(".")[-1], "patterns": len(patt(fi)), "flagged": rows}
            out.write(json.dumps(rec) + "\n"); out.flush()
            if rows:
                n_flag += 1
                for w in rows:
                    print(f"!! red:{name:14s} {rec['dtype']:8s} {w}", flush=True)
    print(f"DONE: {n_flag} (fn, dtype) flagged", flush=True)


if __name__ == "__main__":
    run()
