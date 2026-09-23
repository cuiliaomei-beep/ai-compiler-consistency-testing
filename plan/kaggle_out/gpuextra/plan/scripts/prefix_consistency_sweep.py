"""10.2 Prefix consistency: for a pointwise program the value computed for element i must not depend on how many
elements follow it, on the alignment of the buffer, or on the thread count.

Both sides are compiled results, so the comparison is bit-exact (NaN == NaN, signed zeros distinguished):
    compiled(f)(x[:n])  ==  compiled(f)(x)[:n]            for n in LENGTHS
    compiled(f)(x_off)  ==  compiled(f)(x)                 x_off = same values at storage_offset 1 (unaligned)
    compiled(f)(x) with 1 thread == with all threads
Eager is evaluated too and reported alongside, to tell which path is the wrong one.  One dynamic-shape artifact
serves all lengths (the same kernel places element i in the vector body or in the tail depending on n); a few
static-shape compilations cover the specialised kernels.

    python scripts/prefix_consistency_sweep.py --isolate
    python scripts/prefix_consistency_sweep.py --only remainder,floor_divide --verbose
    python scripts/prefix_consistency_sweep.py --report
"""
import argparse
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402

from tcc.sweep_common import exc_info, jsonl_append, run_isolated  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INF, NAN = float("inf"), float("nan")
LENGTHS = [1, 2, 3, 5, 7, 8, 9, 15, 16, 17, 31, 32, 33, 47, 63, 64, 65]
STATIC_LENGTHS = [3, 9, 17, 33]
N = 70

U = {  # unary pointwise programs
    "abs": torch.abs, "neg": torch.neg, "sign": torch.sign, "sgn": torch.sgn, "signbit": torch.signbit, "reciprocal": torch.reciprocal,
    "sqrt": torch.sqrt, "rsqrt": torch.rsqrt, "square": torch.square, "exp": torch.exp, "expm1": torch.expm1, "exp2": torch.exp2,
    "log": torch.log, "log1p": torch.log1p, "log2": torch.log2, "log10": torch.log10, "sin": torch.sin, "cos": torch.cos,
    "tan": torch.tan, "asin": torch.asin, "acos": torch.acos, "atan": torch.atan, "sinh": torch.sinh, "cosh": torch.cosh,
    "tanh": torch.tanh, "asinh": torch.asinh, "acosh": torch.acosh, "atanh": torch.atanh, "erf": torch.erf, "erfc": torch.erfc,
    "erfinv": torch.erfinv, "lgamma": torch.lgamma, "digamma": torch.digamma, "sigmoid": torch.sigmoid, "logit": torch.logit,
    "sinc": torch.sinc, "i0": torch.i0, "round": torch.round, "round_dec": lambda x: torch.round(x, decimals=1), "trunc": torch.trunc,
    "floor": torch.floor, "ceil": torch.ceil, "frac": torch.frac, "nan_to_num": torch.nan_to_num, "isnan": torch.isnan,
    "isinf": torch.isinf, "isfinite": torch.isfinite, "logical_not": torch.logical_not, "bitwise_not_i": None,
    "relu": torch.relu, "relu6": F.relu6, "gelu": F.gelu, "gelu_tanh": lambda x: F.gelu(x, approximate="tanh"), "silu": F.silu,
    "mish": F.mish, "elu": F.elu, "selu": F.selu, "celu": F.celu, "softplus": F.softplus, "hardtanh": F.hardtanh,
    "hardswish": F.hardswish, "hardsigmoid": F.hardsigmoid, "leaky_relu": F.leaky_relu, "logsigmoid": F.logsigmoid,
    "softsign": F.softsign, "tanhshrink": F.tanhshrink, "softshrink": F.softshrink, "hardshrink": F.hardshrink,
    "clamp": lambda x: torch.clamp(x, -1.5, 2.5), "clamp_min": lambda x: torch.clamp_min(x, 0.0), "pow2": lambda x: x ** 2,
    "pow_half": lambda x: x ** 0.5, "pow3": lambda x: x ** 3, "pow_m1": lambda x: x ** -1, "rpow": lambda x: 2.0 ** x,
    "mod3": lambda x: x % 3, "mod_m3": lambda x: x % -3, "fmod3": lambda x: torch.fmod(x, 3), "floordiv3": lambda x: x // 3,
    "floordiv_m3": lambda x: x // -3, "div3": lambda x: x / 3, "div_trunc": lambda x: torch.div(x, 3, rounding_mode="trunc"),
    "mul_add": lambda x: x * 3 + 1, "sub_self": lambda x: x - x, "cast_i32": lambda x: x.to(torch.int32), "cast_i8": lambda x: x.to(torch.int8),
    "cast_u8": lambda x: x.to(torch.uint8), "cast_f16": lambda x: x.to(torch.float16), "cast_bf16": lambda x: x.to(torch.bfloat16),
    "cast_f64": lambda x: x.to(torch.float64), "cast_bool": lambda x: x.to(torch.bool), "where_self": lambda x: torch.where(x > 0, x, -x),
    "lshift1": None, "rshift1": None,
}
U["bitwise_not_i"] = torch.bitwise_not
U["lshift1"] = lambda x: x << 1
U["rshift1"] = lambda x: x >> 1
B = {  # binary pointwise programs f(a, b)
    "add": torch.add, "sub": torch.sub, "mul": torch.mul, "div": torch.div, "floor_divide": torch.floor_divide,
    "div_trunc": lambda a, b: torch.div(a, b, rounding_mode="trunc"), "remainder": torch.remainder, "fmod": torch.fmod,
    "pow": torch.pow, "atan2": torch.atan2, "hypot": torch.hypot, "copysign": torch.copysign, "nextafter": torch.nextafter,
    "maximum": torch.maximum, "minimum": torch.minimum, "fmax": torch.fmax, "fmin": torch.fmin, "logaddexp": torch.logaddexp,
    "xlogy": torch.xlogy, "heaviside": torch.heaviside, "lt": torch.lt, "le": torch.le, "eq": torch.eq, "ne": torch.ne,
    "where": lambda a, b: torch.where(a < b, a, b), "lerp": lambda a, b: torch.lerp(a, b, 0.3), "addcmul": lambda a, b: torch.addcmul(a, a, b),
    "addcdiv": lambda a, b: torch.addcdiv(a, a, b), "clamp_t": lambda a, b: torch.clamp(a, min=b), "bitwise_and": torch.bitwise_and,
    "bitwise_or": torch.bitwise_or, "bitwise_xor": torch.bitwise_xor, "lshift": torch.bitwise_left_shift, "rshift": torch.bitwise_right_shift,
    "gcd": torch.gcd, "logical_and": torch.logical_and, "logical_xor": torch.logical_xor, "isclose": torch.isclose,
    "smooth_l1": lambda a, b: F.smooth_l1_loss(a, b, reduction="none"), "huber": lambda a, b: F.huber_loss(a, b, reduction="none"),
    "mse": lambda a, b: F.mse_loss(a, b, reduction="none"),
}
DTYPES = [torch.float32, torch.float64, torch.float16, torch.bfloat16, torch.int8, torch.uint8, torch.int16, torch.int32, torch.int64, torch.bool]


def data(dtype, seed):
    g = torch.Generator().manual_seed(seed)
    if dtype == torch.bool:
        return torch.rand(N, generator=g) > 0.5
    if dtype.is_floating_point:
        x = torch.randn(N, generator=g, dtype=torch.float64) * 3
        special = [0.0, -0.0, INF, -INF, NAN, 1.0, -1.0, 0.5, -0.5, 2.5, -2.5, 1e-40, -1e-40, 1e20, -1e20, 65504.0, 3.0, -3.0, 0.1, 7.0]
        for k, v in enumerate(special):                 # spread the specials over vector body and tail positions
            x[(k * 7 + seed) % N] = v
        return x.to(dtype)
    ii = torch.iinfo(dtype)
    x = torch.randint(max(ii.min, -50), min(ii.max, 50) + 1, (N,), generator=g, dtype=torch.int64)
    for k, v in enumerate([ii.min, ii.max, 0, 1, ii.max - 1, ii.min + 1, 3, 7, ii.bits - 1, ii.bits]):
        x[(k * 11 + seed) % N] = v
    return x.to(dtype)


def same(a, b):
    if a.dtype != b.dtype or a.shape != b.shape:
        return False
    if a.is_floating_point():
        a, b = a.double(), b.double()
        return bool((((a == b) & (torch.signbit(a) == torch.signbit(b))) | (torch.isnan(a) & torch.isnan(b))).all())
    return bool(torch.equal(a, b))


def first_diff(full, part, eager, n):
    a, b = full[:n], part
    for i in range(n):
        if not same(a[i:i + 1], b[i:i + 1]):
            return f"i={i}: in full-length run {a[i].item()!r}, in length-{n} run {b[i].item()!r}, eager {eager[i].item()!r}"
    return "dtype/shape"


def check(name, fn, args, dtype, verbose):
    recs = []
    tag = f"{name} {str(dtype).split('.')[-1]}"
    try:
        eager = fn(*args)
    except Exception:  # noqa: BLE001
        return recs                                   # not defined for this dtype
    if not isinstance(eager, torch.Tensor) or eager.shape != args[0].shape:
        return recs
    for mode in ("dynamic", "static"):
        torch._dynamo.reset()
        try:
            cf = torch.compile(fn, dynamic=(mode == "dynamic"))
            full = cf(*[a.clone() for a in args])
            for n in (LENGTHS if mode == "dynamic" else STATIC_LENGTHS):
                part = cf(*[a[:n].clone() for a in args])
                if not same(full[:n], part):
                    recs.append({"category": "prefix", "where": f"{tag} {mode} n={n}", "detail": first_diff(full, part, eager, n)})
                    break
            if mode == "dynamic":
                offs = []
                for a in args:
                    buf = torch.empty(N + 1, dtype=a.dtype)
                    buf[1:].copy_(a)
                    offs.append(buf[1:])
                off = cf(*offs)
                if not same(full, off):
                    recs.append({"category": "alignment", "where": tag, "detail": first_diff(full, off, eager, N)})
                nt = torch.get_num_threads()
                torch.set_num_threads(1)
                one = cf(*[a.clone() for a in args])
                torch.set_num_threads(nt)
                if not same(full, one):
                    recs.append({"category": "threads", "where": tag, "detail": first_diff(full, one, eager, N)})
        except Exception as e:  # noqa: BLE001
            recs.append({"category": "compile_error", "where": f"{tag} {mode}", "detail": exc_info(e)[:200]})
    if verbose:
        print("   ", tag, [r["category"] for r in recs] or "ok", flush=True)
    return recs


def report(path):
    from collections import Counter
    import glob
    rows = []
    for f in sorted(glob.glob(path.replace(".jsonl", "*.jsonl"))):
        rows += [json.loads(l) for l in open(f, encoding="utf-8") if l.strip()]
    print(len(rows), dict(Counter(r["verdict"] for r in rows)))
    for r in rows:
        if r["verdict"] == "CRASH":
            print(f"[CRASH] {r['op']} rc={r.get('returncode')}")
        seen = set()
        for f in r.get("findings", []):
            if f["category"] == "compile_error" or (f["category"], f["where"].split()[1]) in seen:
                continue
            seen.add((f["category"], f["where"].split()[1]))
            print(f"[{f['category']}] {f['where']}: {f['detail'][:200]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "prefix", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    progs = {f"u:{k}": (v, 1) for k, v in U.items()}
    progs.update({f"b:{k}": (v, 2) for k, v in B.items()})
    names = a.only.split(",") if a.only else list(progs)
    names = [n if n in progs else next((p for p in progs if p.split(":", 1)[1] == n), n) for n in names]
    if a.isolate:
        run_isolated(os.path.abspath(__file__), names, [], a.out_jsonl, timeout=3600)
        return
    for n in names:
        fn, arity = progs[n]
        recs = []
        for dt in DTYPES:
            args = tuple(data(dt, s) for s in range(arity))
            recs += check(n, fn, args, dt, a.verbose)
        real = sorted({r["category"] for r in recs if r["category"] != "compile_error"})
        jsonl_append(a.out_jsonl, {"op": n, "verdict": ",".join(real) or "ok", "findings": recs})
        if real:
            print(f"  !! {n}: {real}", flush=True)
            for r in [x for x in recs if x["category"] != "compile_error"][:3]:
                print("       ", r["where"], "|", r["detail"][:170], flush=True)


if __name__ == "__main__":
    main()
