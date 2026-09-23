"""Cross-target consistency differential: one NumPy-style corpus, several Python-driven compilers.

The same small array programs are compiled by
  dynamo : torch.compile over NumPy code (Dynamo translates numpy calls to torch._numpy)   reference: CPython + NumPy
  numba  : numba.njit                                                                      reference: CPython + NumPy
  jax    : jax.jit over jax.numpy                                                          reference: the same function
                                                                                           run op-by-op (jax.disable_jit)
and compared on dtype, shape, values (NaN pattern, infinities, sign of zero, tight tolerance) and exception
behaviour.  Inputs are edge-value vectors (integer limits, shifts around the bit width, signed zeros, NaN,
infinities, denormals, half-way rounding cases) long enough to reach vectorised loops and scalar tails.

Each target needs its own interpreter:
    python                         scripts/xtarget_numpy_diff.py --target dynamo --isolate
    ..\\venv_xtarget\\Scripts\\python scripts/xtarget_numpy_diff.py --target numba  --isolate
    ..\\venv_xtarget\\Scripts\\python scripts/xtarget_numpy_diff.py --target jax    --isolate
Results: results/xtarget/<target>.jsonl ; summary with  --report
"""
import argparse
import json
import os
import sys
import traceback
import warnings

import numpy as np

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, ROOT)
INF, NAN = float("inf"), float("nan")
INT_DTYPES = ["int8", "int16", "int32", "int64", "uint8", "uint16", "uint32", "uint64"]
FLOAT_DTYPES = ["float32", "float64"]

# (name, params, expression, input kind, tags).  `xp` is numpy or jax.numpy.
P = []


def prog(name, params, expr, kind, tags=""):
    P.append({"name": name, "params": params, "expr": expr, "kind": kind, "tags": tags.split()})


for op in ["add", "subtract", "multiply", "bitwise_and", "bitwise_or", "bitwise_xor", "maximum", "minimum",
           "left_shift", "right_shift", "gcd", "lcm", "less", "equal", "true_divide"]:
    prog(f"ii_{op}", "a, b", f"xp.{op}(a, b)", "ii")
for op in ["floor_divide", "remainder", "mod", "fmod", "divmod0"]:
    e = "xp.floor_divide(a, b) * b + xp.remainder(a, b)" if op == "divmod0" else f"xp.{op}(a, b)"
    prog(f"ii_{op}", "a, b", e, "ii_nz")
prog("ii_floor_divide_zero", "a, b", "xp.floor_divide(a, b)", "ii", "divzero")
prog("ii_remainder_zero", "a, b", "xp.remainder(a, b)", "ii", "divzero")
prog("ii_power", "a, b", "xp.power(a, b)", "ii_pow")
prog("ii_power_neg", "a, b", "xp.power(a, b)", "ii", "raises")
prog("ii_pyops", "a, b", "(a + b) * a - b", "ii")
prog("ii_floordiv_op", "a, b", "a // b", "ii_nz")
prog("ii_mod_op", "a, b", "a % b", "ii_nz")
prog("ii_shift_ops", "a, b", "(a << 1) >> 1", "ii")
prog("ii_where", "a, b", "xp.where(a < b, a, b)", "ii")
prog("ii_absdiff", "a, b", "xp.abs(a - b)", "ii")
for name, e in {"negative": "xp.negative(a)", "abs": "xp.abs(a)", "sign": "xp.sign(a)", "invert": "xp.invert(a)",
                "square": "xp.square(a)", "neg_op": "-a", "mul3": "a * 3", "add1": "a + 1", "floordiv_m1": "a // -1",
                "floordiv_3": "a // 3", "mod_m3": "a % -3", "pow2": "a ** 2", "pow3": "a ** 3", "lshift70": "a << 70",
                "rshift70": "a >> 70", "true_div": "a / 3", "div_zero": "a / 0", "sqrt": "xp.sqrt(a)",
                "reciprocal": "xp.reciprocal(a)", "sum": "xp.sum(a)", "prod": "xp.prod(a)", "cumsum": "xp.cumsum(a)",
                "cumprod": "xp.cumprod(a)", "mean": "xp.mean(a)", "max": "xp.max(a)", "argmax": "xp.argmax(a)",
                "argmin": "xp.argmin(a)", "sort": "xp.sort(a)", "clip_wide": "xp.clip(a, -1000, 1000)",
                "clip_narrow": "xp.clip(a, -2, 5)", "astype_i8": "a.astype(xp.int8)", "astype_u8": "a.astype(xp.uint8)",
                "astype_f32_back": "a.astype(xp.float32).astype(a.dtype)", "astype_bool": "a.astype(xp.bool_)",
                "cmp_float": "a < 1e30", "eq_2p53": "a == 9007199254740992.0", "add_float": "a + 0.5",
                "add_bool": "(a > 0) + (a > 1)", "sum_bool": "xp.sum(a > 0)", "count_nonzero": "xp.count_nonzero(a)",
                "diff": "xp.diff(a)", "sum_dtype": "xp.sum(a, dtype=a.dtype)", "std": "xp.std(a)", "var": "xp.var(a)",
                "bincount_u": "xp.sum(a == xp.max(a))", "flip": "a[::-1]", "stride2": "a[::2] + a[1::2][: a[::2].shape[0]]",
                "neg_index": "a[-1] + a[-2]", "any": "xp.any(a)", "all": "xp.all(a)", "unique": "xp.unique(a)",
                }.items():
    prog(f"i_{name}", "a", e, "i")
for op in ["add", "subtract", "multiply", "true_divide", "floor_divide", "remainder", "fmod", "power", "arctan2", "hypot",
           "copysign", "nextafter", "maximum", "minimum", "fmax", "fmin", "logaddexp", "logaddexp2", "less", "less_equal",
           "equal", "not_equal", "heaviside"]:
    prog(f"ff_{op}", "a, b", f"xp.{op}(a, b)", "ff")
prog("ff_where", "a, b", "xp.where(a < b, a, b)", "ff")
prog("ff_clip_arr", "a, b", "xp.clip(a, b, b + 1.0)", "ff")
prog("ff_floordiv_op", "a, b", "a // b", "ff")
prog("ff_mod_op", "a, b", "a % b", "ff")
prog("ff_pow_op", "a, b", "a ** b", "ff")
prog("ff_isclose", "a, b", "xp.isclose(a, b)", "ff")
for name, e in {"rint": "xp.rint(a)", "round": "xp.round(a)", "round1": "xp.round(a, 1)", "around_m1": "xp.round(a, -1)",
                "trunc": "xp.trunc(a)", "floor": "xp.floor(a)", "ceil": "xp.ceil(a)", "fix": "xp.fix(a)", "sign": "xp.sign(a)",
                "signbit": "xp.signbit(a)", "abs": "xp.abs(a)", "negative": "xp.negative(a)", "sqrt": "xp.sqrt(a)",
                "cbrt": "xp.cbrt(a)", "reciprocal": "xp.reciprocal(a)", "square": "xp.square(a)", "exp": "xp.exp(a)",
                "expm1": "xp.expm1(a)", "exp2": "xp.exp2(a)", "log": "xp.log(a)", "log1p": "xp.log1p(a)", "log2": "xp.log2(a)",
                "log10": "xp.log10(a)", "sin": "xp.sin(a)", "cos": "xp.cos(a)", "tan": "xp.tan(a)", "arcsin": "xp.arcsin(a)",
                "arccos": "xp.arccos(a)", "arctan": "xp.arctan(a)", "sinh": "xp.sinh(a)", "cosh": "xp.cosh(a)",
                "tanh": "xp.tanh(a)", "arcsinh": "xp.arcsinh(a)", "arccosh": "xp.arccosh(a)", "arctanh": "xp.arctanh(a)",
                "sinc": "xp.sinc(a)", "isnan": "xp.isnan(a)", "isinf": "xp.isinf(a)", "isfinite": "xp.isfinite(a)",
                "nan_to_num": "xp.nan_to_num(a)", "clip": "xp.clip(a, -1.0, 1.0)", "clip_inverted": "xp.clip(a, 2.0, -2.0)",
                "pow_half": "a ** 0.5", "pow_m1": "a ** -1", "pow_0": "a ** 0", "pow_third": "a ** (1 / 3)",
                "rpow2": "2.0 ** a", "rpow0": "0.0 ** a", "rpow_neg": "(-2.0) ** a", "mod3": "a % 3.0", "mod_m3": "a % -3.0",
                "mod0": "a % 0.0", "floordiv3": "a // 3.0", "floordiv0": "a // 0.0", "div0": "a / 0.0", "mul0": "a * 0.0",
                "mul_m0": "a * -0.0", "sub_self": "a - a", "maximum0": "xp.maximum(a, 0.0)", "minimum_m0": "xp.minimum(a, -0.0)",
                "sum": "xp.sum(a)", "prod": "xp.prod(a)", "mean": "xp.mean(a)", "std": "xp.std(a)", "var": "xp.var(a)",
                "max": "xp.max(a)", "min": "xp.min(a)", "argmax": "xp.argmax(a)", "argmin": "xp.argmin(a)",
                "nansum": "xp.nansum(a)", "nanmax": "xp.nanmax(a)", "nanmin": "xp.nanmin(a)", "nanmean": "xp.nanmean(a)",
                "nanargmax": "xp.nanargmax(a)", "cumsum": "xp.cumsum(a)", "cumprod": "xp.cumprod(a)", "sort": "xp.sort(a)",
                "argsort": "xp.argsort(a)", "median": "xp.median(a)", "nanmedian": "xp.nanmedian(a)", "ptp": "xp.ptp(a)",
                "diff": "xp.diff(a)", "astype_i32": "a.astype(xp.int32)", "astype_i64": "a.astype(xp.int64)",
                "astype_u8": "a.astype(xp.uint8)", "astype_i8": "a.astype(xp.int8)", "astype_bool": "a.astype(xp.bool_)",
                "astype_f16": "a.astype(xp.float16)", "astype_f16_back": "a.astype(xp.float16).astype(a.dtype)",
                "searchsorted": "xp.searchsorted(xp.sort(a), a)", "any": "xp.any(a)", "all": "xp.all(a)",
                "count_nonzero": "xp.count_nonzero(a)", "dot_self": "xp.dot(a, a)", "linspace_like": "xp.linspace(0.0, 1.0, 7) * a[:7]",
                "arange_step": "xp.arange(0.0, 1.0, 0.1).shape[0] + a[:1]", "percentile": "xp.percentile(a, 50)",
                "quantile": "xp.quantile(a, 0.25)", "interp": "xp.interp(a, xp.array([0.0, 1.0, 2.0]), xp.array([0.0, 10.0, 20.0]))",
                "convolve": "xp.convolve(a[:8], a[:3])", "outer_sum": "xp.sum(xp.outer(a[:6], a[:6]))",
                "trapz_like": "xp.sum((a[1:] + a[:-1]) * 0.5)", "lexmax": "xp.max(xp.stack((a, -a)), axis=0)",
                }.items():
    prog(f"f_{name}", "a", e, "f")
for name, e in {"add": "a + b", "mul": "a * b", "true_div": "a / b", "where": "xp.where(a > 0, a, b)", "maximum": "xp.maximum(a, b)",
                "power": "xp.power(a, 2) + b", "concat": "xp.concatenate((a, b))", "stack_sum": "xp.sum(xp.stack((a, b)), axis=0)",
                "eq": "a == b", "lt": "a < b", "add_scalar_f": "a + 1.5", "add_scalar_big": "a + 300", "mul_true": "a * True",
                "floor_divide": "xp.floor_divide(a, b + (b == 0))", "bitand_bool": "(a > 0) & (b > 0)", "sum_pair": "xp.sum(a) + xp.sum(b)",
                }.items():
    prog(f"mix_{name}", "a, b", e, "mix", "promotion")
for name, e in {"matmul": "a @ a.T", "sum_axis0": "xp.sum(a, axis=0)", "sum_axis1_keep": "xp.sum(a, axis=1, keepdims=True)",
                "mean_axis": "xp.mean(a, axis=-1)", "transpose_add": "a.T + a.T", "reshape": "a.reshape(5, 4) * 2",
                "ravel_f": "xp.ravel(a.T)", "cumsum_axis": "xp.cumsum(a, axis=1)", "argmax_axis": "xp.argmax(a, axis=0)",
                "sort_axis": "xp.sort(a, axis=0)", "bool_mask_sum": "xp.sum(a * (a > 0))", "fancy_rows": "a[xp.array([0, -1, 2])]",
                "slice_step": "a[::2, 1::2]", "neg_slice": "a[::-1, ::-1]", "broadcast": "a + a[:, :1]", "norm": "xp.linalg.norm(a)",
                "trace": "xp.trace(a)", "diag": "xp.diag(a)", "tril": "xp.tril(a)", "clip_std": "xp.clip(a, -1, 1).std()",
                "var_axis": "xp.var(a, axis=0)", "min_axis": "xp.min(a, axis=1)", "prod_axis": "xp.prod(a, axis=1)",
                "where3": "xp.where(a > 0.5, 1.0, a)", "expand": "xp.expand_dims(a, 0) - a", "swap": "xp.swapaxes(a, 0, 1) @ a",
                "einsum": "xp.einsum('ij,kj->ik', a, a)", "inv_like": "xp.linalg.inv(a[:4, :4] @ a[:4, :4].T + xp.eye(4))",
                "det": "xp.linalg.det(a[:4, :4])", "solve": "xp.linalg.solve(a[:4, :4] + 4 * xp.eye(4), a[:4, 0])",
                }.items():
    prog(f"m_{name}", "a", e, "m")
prog("oob_index", "a", "a[a.shape[0]]", "f", "oob raises")
prog("oob_fancy", "a", "a[xp.array([0, 9999])]", "f", "oob raises")
prog("zero_size_sum", "a", "xp.sum(a[:0]) + xp.prod(a[:0])", "f")
prog("zero_size_max", "a", "xp.max(a[:0])", "f", "raises")
prog("zero_size_mean", "a", "xp.mean(a[:0])", "f")
prog("int_scalar_overflow", "a", "a + 2 ** 40", "i", "promotion")
prog("uint_neg_scalar", "a", "a + (-1)", "i", "promotion")
prog("loop_accumulate", "a", "_loop_sum(a)", "f", "loop")
prog("loop_int_accumulate", "a", "_loop_sum(a)", "i", "loop")

HELPERS = """
def _loop_sum(a):
    s = a[0] * 0
    for i in range(a.shape[0]):
        s = s + a[i] * (i % 3)
    return s
"""


# ---- inputs ------------------------------------------------------------------------------------------------------
def int_edges(dt):
    ii = np.iinfo(dt)
    vals = [ii.min, ii.min + 1, ii.max - 1, ii.max, 0, 1, 2, 3, 7, 13, ii.bits - 1, ii.bits, ii.bits + 1, 100]
    if ii.min < 0:
        vals += [-1, -2, -3, -7, -13, -100, -ii.bits]
    return np.array(sorted({v for v in vals if ii.min <= v <= ii.max}), dtype=dt)


def float_edges(dt):
    fi = np.finfo(dt)
    with warnings.catch_warnings():
        warnings.simplefilter("ignore")
        return np.array([0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 1.5, -1.5, 2.5, -2.5, 3.0, -3.0, 7.0, -7.0, 0.1, -0.1, 1e-3, 1e20,
                         -1e20, INF, -INF, NAN, fi.max, -fi.max, fi.tiny, -fi.tiny, fi.tiny / 4, fi.eps, 1.0 + fi.eps,
                         2.0 ** 23 + 0.5, 2.0 ** 24 + 1, 2.0 ** 31, -(2.0 ** 31) - 1, 2.0 ** 63, 255.9, 256.0, 127.5, -128.5,
                         1 / 3], dtype=dt)


def pairs(v):
    return np.repeat(v, v.size), np.tile(v, v.size)


def inputs_for(kind):
    """Yield (label, args)."""
    if kind in ("ii", "ii_nz", "ii_pow"):
        for dt in INT_DTYPES:
            a, b = pairs(int_edges(dt))
            if kind == "ii_nz":
                m = b != 0
                a, b = a[m], b[m]
            if kind == "ii_pow":
                m = (b >= 0) & (b <= 70)
                a, b = a[m], b[m]
            yield dt, (a, b)
    elif kind == "i":
        for dt in INT_DTYPES:
            yield dt, (np.tile(int_edges(dt), 3),)
    elif kind == "ff":
        for dt in FLOAT_DTYPES:
            yield dt, pairs(float_edges(dt))
    elif kind == "f":
        for dt in FLOAT_DTYPES:
            yield dt, (np.tile(float_edges(dt), 3),)
    elif kind == "mix":
        combos = [("int8", "int16"), ("uint8", "int8"), ("int32", "uint8"), ("int64", "float32"), ("int32", "float32"),
                  ("uint64", "int64"), ("uint32", "int32"), ("bool", "int8"), ("bool", "float32"), ("float16", "float32"),
                  ("int16", "float16"), ("uint16", "float16"), ("int64", "uint64"), ("float32", "float64")]
        for da, db in combos:
            rng = np.random.default_rng(0)
            a = (rng.integers(-5, 6, 24) if da != "bool" else rng.integers(0, 2, 24)).astype(da)
            b = (rng.integers(-5, 6, 24) if db != "bool" else rng.integers(0, 2, 24)).astype(db)
            yield f"{da}x{db}", (a, b)
    elif kind == "m":
        for dt in FLOAT_DTYPES:
            rng = np.random.default_rng(1)
            yield dt, (rng.standard_normal((4, 5)).astype(dt),)
    else:
        raise SystemExit(kind)


# ---- targets -----------------------------------------------------------------------------------------------------
class Target:
    name = "?"
    unsupported = ()

    def make(self, src, fname):  # -> (reference_callable, compiled_callable, to_input, from_output)
        raise NotImplementedError


class DynamoTarget(Target):
    name = "dynamo"

    def __init__(self, backend):
        from tcc.compat import ensure_msvc_env
        ensure_msvc_env()
        import torch
        self.torch, self.backend = torch, backend
        torch._dynamo.config.recompile_limit = 10 ** 4
        self.version = f"torch {torch.__version__} backend={backend}"

    def make(self, src, fname):
        ns = {"xp": np, "np": np}
        exec(HELPERS + src, ns)
        f = ns[fname]
        self.torch._dynamo.reset()
        return f, self.torch.compile(f, backend=self.backend), (lambda x: x.copy()), (lambda o: o)

    def is_unsupported(self, e):
        return False


class NumbaTarget(Target):
    name = "numba"
    options = {}          # 11.6: numba_parallel / numba_fastmath compare plain njit (the reference) with the same pipeline plus one flag

    def __init__(self, _backend):
        import numba
        self.numba = numba
        self.version = f"numba {numba.__version__} numpy {np.__version__} options={self.options}"

    def make(self, src, fname):
        ns = {"xp": np, "np": np}
        helpers = HELPERS.replace("def _loop_sum", "@_njit\ndef _loop_sum")
        ns["_njit"] = self.numba.njit(**self.options)
        exec(helpers + src, ns)
        f = ns[fname]
        ref_ns = {"xp": np, "np": np}
        if self.options:
            ref_ns["_njit"] = self.numba.njit
            exec(helpers + src, ref_ns)
            return self.numba.njit(ref_ns[fname]), self.numba.njit(**self.options)(f), (lambda x: x.copy()), (lambda o: o)
        exec(HELPERS + src, ref_ns)
        return ref_ns[fname], self.numba.njit(f), (lambda x: x.copy()), (lambda o: o)

    def is_unsupported(self, e):
        from numba.core import errors
        return isinstance(e, (errors.TypingError, errors.UnsupportedError, errors.NumbaNotImplementedError, errors.LoweringError))


class JaxTarget(Target):
    name = "jax"

    def __init__(self, _backend):
        import jax
        jax.config.update("jax_enable_x64", True)
        import jax.numpy as jnp
        self.jax, self.jnp = jax, jnp
        self.version = f"jax {jax.__version__}"

    def make(self, src, fname):
        ns = {"xp": self.jnp, "np": np}
        exec(HELPERS + src, ns)
        f = ns[fname]
        jax = self.jax

        def ref(*a):
            with jax.disable_jit():
                return f(*a)

        return ref, jax.jit(f), (lambda x: self.jnp.asarray(x)), (lambda o: jax.tree_util.tree_map(np.asarray, o))

    def is_unsupported(self, e):
        return isinstance(e, (NotImplementedError,)) or "ConcretizationTypeError" in type(e).__name__ \
            or "TracerBoolConversionError" in type(e).__name__ or "NonConcreteBooleanIndexError" in type(e).__name__ \
            or "size argument" in str(e) or "Abstract tracer value" in str(e)


class NumbaParallelTarget(NumbaTarget):
    name = "numba_parallel"
    options = {"parallel": True}


class NumbaFastmathTarget(NumbaTarget):
    name = "numba_fastmath"
    options = {"fastmath": True}


TARGETS = {"dynamo": DynamoTarget, "numba": NumbaTarget, "jax": JaxTarget, "numba_parallel": NumbaParallelTarget, "numba_fastmath": NumbaFastmathTarget}


# ---- comparison ----------------------------------------------------------------------------------------------------
def flat(o):
    if isinstance(o, (tuple, list)):
        return [x for y in o for x in flat(y)]
    return [o]


def show(mask, args, e, c):
    idx = np.flatnonzero(mask)[:4]
    ew = all(getattr(a, "size", 0) == e.size for a in args)
    rows = []
    for i in idx:
        ins = [a.ravel()[i].item() for a in args] if ew else "-"
        rows.append(f"in={ins} ref={e.ravel()[i].item()!r} got={c.ravel()[i].item()!r}")
    return f"{int(mask.sum())}/{e.size}: " + "; ".join(rows)


def diff(ref, got, args):
    out = []
    rs, gs = flat(ref), flat(got)
    if len(rs) != len(gs):
        return [("structure", f"{len(rs)} vs {len(gs)} outputs")]
    for r, g in zip(rs, gs):
        tr, tg = type(r).__name__, type(g).__name__
        r, g = np.asarray(r), np.asarray(g)
        if r.shape != g.shape:
            out.append(("shape", f"{r.shape} vs {g.shape}"))
            continue
        if r.dtype != g.dtype:
            out.append(("dtype", f"ref {r.dtype} ({tr}) vs got {g.dtype} ({tg})"))
            if r.dtype.kind not in "biuf" or g.dtype.kind not in "biuf":
                continue
        if r.size == 0:
            continue
        with np.errstate(all="ignore"), warnings.catch_warnings():
            warnings.simplefilter("ignore")
            if r.dtype.kind == "f" or g.dtype.kind == "f":
                rd, gd = r.astype(np.float64).ravel(), g.astype(np.float64).ravel()
                rn, gn = np.isnan(rd), np.isnan(gd)
                if not np.array_equal(rn, gn):
                    out.append(("value", "NaN pattern " + show(rn != gn, args, rd, gd)))
                ok = ~(rn | gn)
                tol = 2e-5 if min(r.dtype.itemsize, g.dtype.itemsize) <= 4 else 1e-11
                close = (rd == gd) | (np.isfinite(rd) & np.isfinite(gd) & (np.abs(rd - gd) <= tol * np.maximum(np.abs(rd), np.abs(gd))))
                tiny = np.finfo(r.dtype if r.dtype.kind == "f" else np.float64).tiny * 4
                close |= (np.abs(rd) <= tiny) & (np.abs(gd) <= tiny)
                bad = ok & ~close
                if bad.any():
                    out.append(("value", show(bad, args, rd, gd)))
                z = ok & (rd == 0) & (gd == 0) & (np.signbit(rd) != np.signbit(gd))
                if z.any():
                    out.append(("signed_zero", show(z, args, rd, gd)))
            else:
                bad = r.ravel().astype(object) != g.ravel().astype(object) if r.dtype != g.dtype else r.ravel() != g.ravel()
                bad = np.asarray(bad, dtype=bool)
                if bad.any():
                    out.append(("value", show(bad, args, r.ravel(), g.ravel())))
    return out


def run_program(t, p, verbose):
    src = f"def f({p['params']}):\n    return {p['expr']}\n"
    recs = []
    for label, args in inputs_for(p["kind"]):
        for take in (None, 1, 7):
            if take and (p["kind"] == "m" or args[0].size <= take):
                continue
            a2 = tuple(a[:take] for a in args) if take else args
            try:
                ref_f, comp_f, to_in, from_out = t.make(src, "f")
            except Exception as e:  # noqa: BLE001
                recs.append({"category": "harness", "where": label, "detail": repr(e)[:300]})
                break
            r = g = r_exc = g_exc = None
            with np.errstate(all="ignore"), warnings.catch_warnings():
                warnings.simplefilter("ignore")
                try:
                    r = from_out(ref_f(*[to_in(x) for x in a2]))
                except Exception as e:  # noqa: BLE001
                    r_exc = e
                try:
                    g = from_out(comp_f(*[to_in(x) for x in a2]))
                except Exception as e:  # noqa: BLE001
                    g_exc = e
            where = f"{label} n={a2[0].size}"
            if g_exc is not None and t.is_unsupported(g_exc):
                recs.append({"category": "unsupported", "where": where, "detail": f"{type(g_exc).__name__}: {str(g_exc)[:160]}"})
                break
            if r_exc is not None or g_exc is not None:
                if (r_exc is None) != (g_exc is None):
                    recs.append({"category": "raise", "where": where,
                                 "ref": f"{type(r_exc).__name__}: {str(r_exc)[:200]}" if r_exc else "returned " + repr(flat(r)[0])[:120],
                                 "got": f"{type(g_exc).__name__}: {str(g_exc)[:300]}" if g_exc else "returned " + repr(flat(g)[0])[:120]})
                elif type(r_exc).__name__ != type(g_exc).__name__ and type(r_exc).__name__ not in str(g_exc):
                    recs.append({"category": "raise_type", "where": where, "ref": type(r_exc).__name__,
                                 "got": f"{type(g_exc).__name__}: {str(g_exc)[:160]}"})
                continue
            for cat, detail in diff(r, g, a2):
                recs.append({"category": cat, "where": where, "detail": detail})
            if verbose:
                print("   ", p["name"], where, [x["category"] for x in recs if x["where"] == where] or "ok", flush=True)
    return recs


def report(out_dir):
    for tname in TARGETS:
        path = os.path.join(out_dir, f"{tname}.jsonl")
        if not os.path.exists(path):
            continue
        rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
        print(f"\n# {tname}: {len(rows)} programs")
        from collections import Counter
        print("  verdicts:", dict(Counter(r["verdict"] for r in rows)))
        for r in rows:
            cats = {}
            for f in r.get("findings", []):
                cats.setdefault(f["category"], []).append(f)
            for cat in ("value", "dtype", "shape", "raise", "signed_zero", "structure", "CRASH"):
                if cat in cats:
                    f = cats[cat][0]
                    print(f"  [{cat}] {r['op']} ({len(cats[cat])}x) {f['where']}: {(f.get('detail') or (f.get('ref', '') + ' | ' + f.get('got', '')))[:230]}")
            if r["verdict"] == "CRASH":
                print(f"  [CRASH] {r['op']} rc={r.get('returncode')} {r.get('tail', '')[-200:]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--target", choices=list(TARGETS), default=None)
    ap.add_argument("--backend", default="eager", help="dynamo target only: eager | aot_eager | inductor")
    ap.add_argument("--only", default=None)
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-dir", default=os.path.join(ROOT, "results", "xtarget"))
    ap.add_argument("--out-jsonl", default=None)
    a = ap.parse_args()
    os.makedirs(a.out_dir, exist_ok=True)
    if a.report:
        return report(a.out_dir)
    out = a.out_jsonl or os.path.join(a.out_dir, f"{a.target}.jsonl")
    names = a.only.split(",") if a.only else [p["name"] for p in P]
    if a.isolate:
        from tcc.sweep_common import run_isolated
        run_isolated(os.path.abspath(__file__), names, ["--target", a.target, "--backend", a.backend, "--out-dir", a.out_dir],
                     out, timeout=1200, label=f":{a.target}")
        return
    t = TARGETS[a.target](a.backend)
    print(t.version, "|", len(names), "programs", flush=True)
    byname = {p["name"]: p for p in P}
    for n in names:
        try:
            recs = run_program(t, byname[n], a.verbose)
        except Exception as e:  # noqa: BLE001
            recs = [{"category": "harness", "where": n, "detail": repr(e)[:300], "tb": traceback.format_exc()[-500:]}]
        cats = sorted({r["category"] for r in recs})
        with open(out, "a", encoding="utf-8") as f:
            f.write(json.dumps({"op": n, "verdict": ",".join(cats) or "ok", "target": t.version, "expr": byname[n]["expr"],
                                "tags": byname[n]["tags"], "findings": recs}, default=str) + "\n")
        if cats and cats != ["unsupported"]:
            print(f"  !! {n}: {cats}", flush=True)


if __name__ == "__main__":
    main()
