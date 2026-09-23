"""8.2 Integer / cast / IEEE-special-value semantics: eager kernels define the behaviour, generated C++ may not.

For every (case, dtype) the same edge-value vectors are run in eager mode and under torch.compile.  Integer and
bool results must match exactly; float results must agree in NaN pattern, infinities, sign of zero, and value
(tight relative tolerance, because libm differences are legal).  The edge vectors are long enough (hundreds of
elements from the outer product of the edge values) to reach both the vectorised loop body and the scalar tail,
and each case is repeated on the first 1 and 7 elements to force tail-only kernels.

Categories in the report:
  value        results differ where eager behaviour is well defined          <- report candidates
  signed_zero  only the sign of a zero differs
  raise        one side raises, the other returns
  ub           inputs for which C++ itself is undefined (out-of-range float->int casts); listed, not counted

    python scripts/int_ub_sweep.py --isolate
    python scripts/int_ub_sweep.py --only int_binary:floor_divide --verbose
"""
import argparse
import os
import sys
import traceback

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

from tcc.sweep_common import exc_info, jsonl_append, run_isolated  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

INT_DTYPES = [torch.int8, torch.int16, torch.int32, torch.int64, torch.uint8]
FLOAT_DTYPES = [torch.float32, torch.float64]
INF, NAN = float("inf"), float("nan")


def int_edges(dtype):
    ii = torch.iinfo(dtype)
    vals = [ii.min, ii.min + 1, ii.max - 1, ii.max, 0, 1, 2, 3, 7, 13, ii.bits - 1, ii.bits, ii.bits + 1, 100]
    if ii.min < 0:
        vals += [-1, -2, -3, -7, -13, -100, -(ii.bits), -(ii.bits - 1)]
    vals = sorted({v for v in vals if ii.min <= v <= ii.max})
    return torch.tensor(vals, dtype=dtype)


def float_edges(dtype):
    fi = torch.finfo(dtype)
    vals = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 1.5, -1.5, 2.5, -2.5, 3.0, -3.0, 7.0, -7.0, 0.1, -0.1, 1e-3, 1e20, -1e20,
            INF, -INF, NAN, fi.max, -fi.max, fi.tiny, -fi.tiny, fi.tiny / 4, -fi.tiny / 4, fi.eps, 1.0 + fi.eps,
            2.0 ** 23 + 0.5, 2.0 ** 24 + 1, 2.0 ** 31, -(2.0 ** 31) - 1, 2.0 ** 63, 255.9, 256.0, 127.5, -128.5, 1 / 3]
    return torch.tensor(vals, dtype=dtype)


def pairs(v):
    a = v.repeat_interleave(v.numel())
    b = v.repeat(v.numel())
    return a, b


def drop_zero_divisor(a, b):
    m = b != 0
    return a[m], b[m]


def nonneg_exponent(a, b):
    m = (b >= 0) & (b <= 70)
    return a[m], b[m]


# ---- case tables ---------------------------------------------------------------------------------------------
INT_BINARY = {
    "add": (torch.add, None), "sub": (torch.sub, None), "mul": (torch.mul, None),
    "floor_divide": (torch.floor_divide, drop_zero_divisor),
    "div_trunc": (lambda a, b: torch.div(a, b, rounding_mode="trunc"), drop_zero_divisor),
    "div_floor": (lambda a, b: torch.div(a, b, rounding_mode="floor"), drop_zero_divisor),
    "true_divide": (torch.true_divide, None),
    "remainder": (torch.remainder, drop_zero_divisor), "fmod": (torch.fmod, drop_zero_divisor),
    "pow": (torch.pow, nonneg_exponent),
    "lshift": (torch.bitwise_left_shift, None), "rshift": (torch.bitwise_right_shift, None),
    "and": (torch.bitwise_and, None), "or": (torch.bitwise_or, None), "xor": (torch.bitwise_xor, None),
    "maximum": (torch.maximum, None), "minimum": (torch.minimum, None),
    "gcd": (torch.gcd, None), "lcm": (torch.lcm, None),
    "lt": (torch.lt, None), "eq": (torch.eq, None),
    "where_lt": (lambda a, b: torch.where(a < b, a, b), None),
    "abs_diff": (lambda a, b: (a - b).abs(), None),
    "mul_add": (lambda a, b: a * b + a, None),
    "floor_divide_zero": (torch.floor_divide, None),       # raise parity on division by zero
    "remainder_zero": (torch.remainder, None),
}
INT_UNARY = {
    "neg": torch.neg, "abs": torch.abs, "sign": torch.sign, "sgn": torch.sgn, "bitwise_not": torch.bitwise_not,
    "square": torch.square, "mul_self": lambda x: x * x, "add_scalar": lambda x: x + 1, "sub_scalar": lambda x: x - 1,
    "mul_scalar": lambda x: x * 3, "mul_neg1": lambda x: x * -1, "floordiv_neg1": lambda x: x // -1,
    "floordiv_3": lambda x: x // 3, "floordiv_neg3": lambda x: x // -3, "mod_3": lambda x: x % 3,
    "mod_neg3": lambda x: x % -3, "fmod_neg3": lambda x: torch.fmod(x, -3),
    "lshift_1": lambda x: x << 1, "rshift_1": lambda x: x >> 1, "lshift_bits": lambda x: x << 70, "rshift_bits": lambda x: x >> 70,
    "pow_2": lambda x: x ** 2, "pow_3": lambda x: x ** 3, "pow_0": lambda x: x ** 0,
    "to_float_back": lambda x: x.to(torch.float32).to(x.dtype), "to_double_back": lambda x: x.to(torch.float64).to(x.dtype),
    "to_int8": lambda x: x.to(torch.int8), "to_uint8": lambda x: x.to(torch.uint8), "to_int16": lambda x: x.to(torch.int16),
    "to_bool": lambda x: x.to(torch.bool), "to_half": lambda x: x.to(torch.float16),
    "sum": torch.sum, "prod": torch.prod, "cumsum": lambda x: torch.cumsum(x, 0), "cumprod": lambda x: torch.cumprod(x, 0),
    "sum_same_dtype": lambda x: torch.sum(x, dtype=x.dtype), "cumsum_same_dtype": lambda x: torch.cumsum(x, 0, dtype=x.dtype),
    "max": torch.max, "min": torch.min, "argmax": torch.argmax, "argmin": torch.argmin,
    "clamp_wide": lambda x: torch.clamp(x, -1000, 1000), "clamp_narrow": lambda x: torch.clamp(x, -2, 5),
    "clamp_min_big": lambda x: torch.clamp(x, min=2 ** 40), "clamp_float_bound": lambda x: torch.clamp(x, -1.5, 2.5),
    "sqrt": torch.sqrt, "reciprocal": torch.reciprocal, "exp2": torch.exp2, "rsqrt": torch.rsqrt,
    "eq_float": lambda x: x == 2.0 ** 53, "lt_float": lambda x: x < 1e30, "cmp_big_float": lambda x: x.to(torch.int64) < 9.3e18,
    "mean_error": lambda x: x.float().mean(), "true_div_scalar": lambda x: x / 3, "div_scalar_zero": lambda x: x / 0,
    "count_nonzero": torch.count_nonzero, "bincount_like": lambda x: (x == x.max()).sum(),
    "add_bool": lambda x: (x > 0) + (x > 1), "sum_bool": lambda x: (x > 0).sum(), "neg_bool_cast": lambda x: -(x > 0).to(x.dtype),
    "sign_mul": lambda x: torch.sign(x) * x, "abs_neg": lambda x: -torch.abs(x), "heaviside": lambda x: torch.heaviside(x, x),
}
FLOAT_BINARY = {
    "div": torch.div, "floor_divide": torch.floor_divide, "div_trunc": lambda a, b: torch.div(a, b, rounding_mode="trunc"),
    "div_floor": lambda a, b: torch.div(a, b, rounding_mode="floor"),
    "remainder": torch.remainder, "fmod": torch.fmod, "pow": torch.pow, "float_power": torch.float_power,
    "atan2": torch.atan2, "hypot": torch.hypot, "copysign": torch.copysign, "nextafter": torch.nextafter,
    "maximum": torch.maximum, "minimum": torch.minimum, "fmax": torch.fmax, "fmin": torch.fmin,
    "logaddexp": torch.logaddexp, "logaddexp2": torch.logaddexp2, "xlogy": torch.xlogy, "xlog1py": torch.special.xlog1py,
    "heaviside": torch.heaviside, "mul": torch.mul, "add": torch.add, "sub": torch.sub,
    "lt": torch.lt, "le": torch.le, "eq": torch.eq, "ne": torch.ne,
    "where_lt": lambda a, b: torch.where(a < b, a, b), "clamp_tensor": lambda a, b: torch.clamp(a, min=b),
    "clamp_max_tensor": lambda a, b: torch.clamp(a, max=b), "lerp_half": lambda a, b: torch.lerp(a, b, 0.5),
    "ldexp": lambda a, b: torch.ldexp(a, b.nan_to_num(0, 0, 0).clamp(-2000, 2000).to(torch.int32)),
    "isclose": torch.isclose, "dist_like": lambda a, b: (a - b).abs(), "addcmul": lambda a, b: torch.addcmul(a, a, b),
    "addcdiv": lambda a, b: torch.addcdiv(a, a, b),
}
FLOAT_UNARY = {
    "round": torch.round, "round_dec1": lambda x: torch.round(x, decimals=1), "round_decm1": lambda x: torch.round(x, decimals=-1),
    "trunc": torch.trunc, "floor": torch.floor, "ceil": torch.ceil, "frac": torch.frac,
    "sign": torch.sign, "sgn": torch.sgn, "signbit": torch.signbit, "abs": torch.abs, "neg": torch.neg,
    "sqrt": torch.sqrt, "rsqrt": torch.rsqrt, "reciprocal": torch.reciprocal, "square": torch.square,
    "exp": torch.exp, "expm1": torch.expm1, "exp2": torch.exp2, "log": torch.log, "log1p": torch.log1p, "log2": torch.log2,
    "log10": torch.log10, "sigmoid": torch.sigmoid, "tanh": torch.tanh, "atan": torch.atan, "asin": torch.asin,
    "acos": torch.acos, "sinh": torch.sinh, "cosh": torch.cosh, "asinh": torch.asinh, "acosh": torch.acosh,
    "atanh": torch.atanh, "erf": torch.erf, "erfc": torch.erfc, "erfinv": torch.erfinv, "lgamma": torch.lgamma,
    "digamma": torch.digamma, "sinc": torch.sinc, "logit": torch.logit, "i0": torch.i0, "relu": torch.relu,
    "nan_to_num": torch.nan_to_num, "isnan": torch.isnan, "isinf": torch.isinf, "isfinite": torch.isfinite,
    "isposinf": torch.isposinf, "isneginf": torch.isneginf, "to_bool": lambda x: x.to(torch.bool),
    "clamp": lambda x: torch.clamp(x, -1.0, 1.0), "clamp_nan_bound": lambda x: torch.clamp(x, min=NAN),
    "clamp_inverted": lambda x: torch.clamp(x, 2.0, -2.0), "hardtanh": torch.nn.functional.hardtanh,
    "relu6": torch.nn.functional.relu6, "softplus": torch.nn.functional.softplus, "gelu": torch.nn.functional.gelu,
    "silu": torch.nn.functional.silu, "mish": torch.nn.functional.mish, "hardswish": torch.nn.functional.hardswish,
    "hardsigmoid": torch.nn.functional.hardsigmoid, "elu": torch.nn.functional.elu, "selu": torch.nn.functional.selu,
    "logsigmoid": torch.nn.functional.logsigmoid, "softsign": torch.nn.functional.softsign,
    "threshold": lambda x: torch.nn.functional.threshold(x, 0.0, -0.0), "leaky_relu": torch.nn.functional.leaky_relu,
    "pow_half": lambda x: x ** 0.5, "pow_neg1": lambda x: x ** -1, "pow_2": lambda x: x ** 2, "pow_0": lambda x: x ** 0,
    "pow_third": lambda x: x ** (1 / 3), "pow_3": lambda x: x ** 3, "pow_neg2": lambda x: x ** -2.0,
    "rpow_2": lambda x: 2.0 ** x, "rpow_0": lambda x: 0.0 ** x, "rpow_neg": lambda x: (-2.0) ** x, "rpow_1": lambda x: 1.0 ** x,
    "mod_scalar": lambda x: x % 3.0, "mod_neg_scalar": lambda x: x % -3.0, "mod_zero": lambda x: x % 0.0,
    "fmod_scalar": lambda x: torch.fmod(x, -3.0), "floordiv_scalar": lambda x: x // 3.0, "floordiv_neg": lambda x: x // -3.0,
    "floordiv_zero": lambda x: x // 0.0, "div_zero": lambda x: x / 0.0, "div_negzero": lambda x: x / -0.0,
    "mul_zero": lambda x: x * 0.0, "mul_negzero": lambda x: x * -0.0, "add_negzero": lambda x: x + -0.0, "sub_self": lambda x: x - x,
    "max_scalar_zero": lambda x: torch.clamp_min(x, 0.0), "min_scalar_negzero": lambda x: torch.clamp_max(x, -0.0),
    "maximum_negzero": lambda x: torch.maximum(x, torch.full_like(x, -0.0)), "minimum_zero": lambda x: torch.minimum(x, torch.zeros_like(x)),
    "sum": torch.sum, "prod": torch.prod, "max": torch.max, "min": torch.min, "argmax": torch.argmax, "argmin": torch.argmin,
    "amax": lambda x: torch.amax(x, 0), "nansum": torch.nansum, "nanmean": torch.nanmean, "cummax": lambda x: torch.cummax(x, 0)[0],
    "cummin_idx": lambda x: torch.cummin(x, 0)[1], "cumsum": lambda x: torch.cumsum(x, 0), "logcumsumexp": lambda x: torch.logcumsumexp(x, 0),
    "logsumexp": lambda x: torch.logsumexp(x, 0), "softmax": lambda x: torch.softmax(x, 0), "log_softmax": lambda x: torch.log_softmax(x, 0),
    "sort_vals": lambda x: torch.sort(x)[0], "sort_desc": lambda x: torch.sort(x, descending=True)[0], "topk": lambda x: torch.topk(x, 5)[0],
    "median": torch.median, "nanmedian": torch.nanmedian, "unique_sorted_like": lambda x: torch.sort(x.nan_to_num())[1],
    "std": torch.std, "var": torch.var, "norm": torch.linalg.vector_norm, "norm_inf": lambda x: torch.linalg.vector_norm(x, ord=INF),
    "cast_half": lambda x: x.to(torch.float16), "cast_bf16": lambda x: x.to(torch.bfloat16), "cast_f32": lambda x: x.to(torch.float32),
    "cast_half_back": lambda x: x.to(torch.float16).to(x.dtype),
}
# float -> integer casts; out-of-range and non-finite inputs are undefined behaviour in C++ and in the docs ("ub")
CASTS = {f"to_{str(d).split('.')[-1]}": (lambda x, d=d: x.to(d)) for d in INT_DTYPES}
CASTS.update({"trunc_to_int32": lambda x: x.trunc().to(torch.int32), "round_to_int64": lambda x: x.round().to(torch.int64),
              "clamp_to_int8": lambda x: x.clamp(-128, 127).to(torch.int8), "floor_to_uint8": lambda x: x.floor().to(torch.uint8),
              "int_roundtrip": lambda x: x.to(torch.int32).to(x.dtype), "long_mul": lambda x: x.to(torch.int64) * 3})


def in_range_mask(x, dtype):
    ii = torch.iinfo(dtype)
    return torch.isfinite(x) & (x > ii.min - 1) & (x < ii.max + 1)


def all_cases():
    out = []
    out += [f"int_binary:{k}" for k in INT_BINARY]
    out += [f"int_unary:{k}" for k in INT_UNARY]
    out += [f"float_binary:{k}" for k in FLOAT_BINARY]
    out += [f"float_unary:{k}" for k in FLOAT_UNARY]
    out += [f"cast:{k}" for k in CASTS]
    return out


def build(case, dtype):
    """Return (fn, args, ub_mask_fn or None)."""
    fam, name = case.split(":", 1)
    if fam == "int_binary":
        fn, filt = INT_BINARY[name]
        a, b = pairs(int_edges(dtype))
        if filt:
            a, b = filt(a, b)
        return fn, (a, b), None
    if fam == "int_unary":
        v = int_edges(dtype)
        return INT_UNARY[name], (v.repeat(3),), None
    if fam == "float_binary":
        a, b = pairs(float_edges(dtype))
        return FLOAT_BINARY[name], (a, b), None
    if fam == "float_unary":
        v = float_edges(dtype)
        return FLOAT_UNARY[name], (v.repeat(3),), None
    if fam == "cast":
        v = float_edges(dtype).repeat(3)
        return CASTS[name], (v,), "cast"
    raise SystemExit(case)


def dtypes_for(case):
    return INT_DTYPES if case.startswith("int_") else FLOAT_DTYPES


def run(fn, args):
    try:
        with torch.no_grad():
            o = fn(*[a.clone() for a in args])
        return o, None
    except Exception as e:  # noqa: BLE001
        return None, e


def diff(e, c, args):
    """Return list of (category, detail)."""
    if e.shape != c.shape:
        return [("value", f"shape {tuple(e.shape)} vs {tuple(c.shape)}")]
    if e.dtype != c.dtype:
        return [("value", f"dtype {e.dtype} vs {c.dtype}")]
    found = []
    ef, cf = e.flatten(), c.flatten()
    elementwise = all(a.numel() == ef.numel() for a in args)

    def show(mask):
        idx = mask.nonzero().flatten()[:4].tolist()
        rows = []
        for i in idx:
            ins = [a.flatten()[i].item() for a in args] if elementwise else "reduction"
            rows.append(f"in={ins} eager={ef[i].item()!r} comp={cf[i].item()!r}")
        return f"{int(mask.sum())}/{ef.numel()} differ: " + "; ".join(rows)

    if e.is_floating_point():
        en, cn = torch.isnan(ef), torch.isnan(cf)
        if not torch.equal(en, cn):
            found.append(("value", "NaN pattern " + show(en != cn)))
        ok = ~(en | cn)
        ed, cd = ef.double(), cf.double()
        tol = 2e-5 if e.dtype in (torch.float32, torch.float16, torch.bfloat16) else 1e-11
        bad = ok & (ed != cd) & ~(((ed - cd).abs() <= tol * torch.maximum(ed.abs(), cd.abs())) & torch.isfinite(ed) & torch.isfinite(cd))
        # denormal-range absolute slack
        tiny = torch.finfo(e.dtype).tiny * 4
        bad = bad & ~((ed.abs() <= tiny) & (cd.abs() <= tiny) & (torch.sign(ed) == torch.sign(cd)))
        if bad.any():
            found.append(("value", show(bad)))
        z = ok & (ed == 0) & (cd == 0) & (torch.signbit(ef) != torch.signbit(cf))
        if z.any():
            found.append(("signed_zero", show(z)))
    else:
        bad = ef != cf
        if bad.any():
            found.append(("value", show(bad)))
    return found


def check(case, dtype, backends, verbose):
    fn, args, ub = build(case, dtype)
    recs = []
    for take in (None, 1, 7):
        a2 = tuple(a[:take] for a in args) if take else args
        if any(a.numel() == 0 for a in a2):
            continue
        e, e_exc = run(fn, a2)
        for b in backends:
            torch._dynamo.reset()
            c, c_exc = run(torch.compile(fn, backend=b), a2)
            tag = f"{case} {str(dtype).split('.')[-1]} n={a2[0].numel()} {b}"
            if e_exc is not None or c_exc is not None:
                if (e_exc is None) != (c_exc is None):
                    recs.append({"category": "raise", "where": tag, "eager": exc_info(e_exc) if e_exc else "returned",
                                 "compiled": exc_info(c_exc)[:300] if c_exc else "returned " + str(c.flatten()[:6].tolist())})
                continue
            es = e if isinstance(e, (tuple, list)) else [e]
            cs = c if isinstance(c, (tuple, list)) else [c]
            for eo, co in zip(es, cs):
                if not isinstance(eo, torch.Tensor):
                    eo, co = torch.as_tensor(eo), torch.as_tensor(co)
                for cat, detail in diff(eo, co, a2):
                    if ub == "cast":
                        # split: are all differing elements outside the target range?
                        cat = "ub_or_value"
                    recs.append({"category": cat, "where": tag, "detail": detail})
            if verbose:
                print("   ", tag, "->", [r["category"] for r in recs if r["where"] == tag] or "ok", flush=True)
    return recs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="aot_eager,inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--timeout", type=int, default=1800)
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "int_ub", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    names = a.only.split(",") if a.only else all_cases()
    if a.isolate:
        run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=a.timeout)
        return
    backends = a.backends.split(",")
    print(f"torch {torch.__version__} | {len(names)} cases | {backends}", flush=True)
    for case in names:
        recs = []
        for dt in dtypes_for(case):
            try:
                recs += check(case, dt, backends, a.verbose)
            except Exception as e:  # noqa: BLE001
                recs.append({"category": "harness", "where": f"{case} {dt}", "detail": exc_info(e), "tb": traceback.format_exc()[-600:]})
        cats = sorted({r["category"] for r in recs})
        jsonl_append(a.out_jsonl, {"op": case, "verdict": ",".join(cats) or "ok", "findings": recs})
        if recs:
            print(f"  !! {case}: {cats}", flush=True)
            for r in recs[:3]:
                print("      ", r["where"], "|", (r.get("detail") or r.get("compiled") or "")[:220], flush=True)


if __name__ == "__main__":
    main()
