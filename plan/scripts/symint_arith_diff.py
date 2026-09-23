"""10.5  Python scalar arithmetic on SymInt / SymFloat versus plain Python.

Under `dynamic=True`, `x.shape[0]` is a SymInt and (with capture_scalar_outputs) `t.item()` is a SymFloat/SymInt;
Python arithmetic on them is evaluated by SymPy and, under Inductor, printed into the generated wrapper / kernels.
Python's own semantics (floor division and modulo of negatives, banker's rounding, int() truncation, big integers,
bool arithmetic, exceptions) are the specification.  Each expression is compiled once and evaluated on a grid of
concrete sizes / scalar values; the Python value (type and value) and a tensor built from it must equal eager's.

    python scripts/symint_arith_diff.py --isolate
    python scripts/symint_arith_diff.py --report
"""
import argparse
import json
import math
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
torch._dynamo.config.capture_scalar_outputs = True
torch._dynamo.config.recompile_limit = 10 ** 4

# a, b: sizes (SymInt);  n = a - 10 (negative values);  u: float scalar from .item();  k: int scalar from .item()
INT = {
    "floordiv_pos": lambda a, b, n: a // 3, "floordiv_neg": lambda a, b, n: n // 3, "floordiv_negdiv": lambda a, b, n: n // -3, "floordiv_sym": lambda a, b, n: n // b,
    "mod_pos": lambda a, b, n: a % 3, "mod_neg": lambda a, b, n: n % 3, "mod_negdiv": lambda a, b, n: n % -3, "mod_sym": lambda a, b, n: n % b, "mod_sym_neg": lambda a, b, n: a % (b - 20),
    "divmod_neg": lambda a, b, n: list(divmod(n, 3)), "divmod_sym": lambda a, b, n: list(divmod(n, b)), "neg_floordiv": lambda a, b, n: -a // 2, "floordiv_identity": lambda a, b, n: n // b * b + n % b == n,
    "truediv": lambda a, b, n: a / b, "truediv_neg": lambda a, b, n: n / 3, "truediv_roundtrip": lambda a, b, n: a / 3 * 3 == a, "int_truediv": lambda a, b, n: int(n / 3), "int_truediv_sym": lambda a, b, n: int(n / b),
    "round_half": lambda a, b, n: round(a / 2), "round_half_neg": lambda a, b, n: round(n / 2), "round_ndigits": lambda a, b, n: round(a / 8, 1), "round_int_neg_digits": lambda a, b, n: round(a * 5, -1),
    "floor_div": lambda a, b, n: math.floor(n / 3), "ceil_div": lambda a, b, n: math.ceil(n / 3), "trunc_div": lambda a, b, n: math.trunc(n / 3), "ceil_idiom": lambda a, b, n: -(-a // b), "ceil_idiom2": lambda a, b, n: (a + b - 1) // b,
    "pow2": lambda a, b, n: n ** 2, "pow3_neg": lambda a, b, n: n ** 3, "pow_neg_exp": lambda a, b, n: a ** -1, "pow_sym": lambda a, b, n: 2 ** a, "pow_sym_neg_base": lambda a, b, n: (-2) ** a, "pow_half": lambda a, b, n: a ** 0.5,
    "pow_mod": lambda a, b, n: pow(a, b, 7), "pow_zero_zero": lambda a, b, n: (a - a) ** (b - b), "big_mul": lambda a, b, n: a * 3037000500 * 3037000500, "big_pow": lambda a, b, n: (a + 2) ** 40, "big_shift": lambda a, b, n: a << 62,
    "big_mod": lambda a, b, n: (a * 4611686018427387904 * 4) % 1000003, "lshift": lambda a, b, n: a << 3, "rshift_neg": lambda a, b, n: n >> 1, "and_neg": lambda a, b, n: n & 7, "or_neg": lambda a, b, n: n | 1, "xor_neg": lambda a, b, n: n ^ 5, "invert": lambda a, b, n: ~a,
    "abs_neg": lambda a, b, n: abs(n), "neg": lambda a, b, n: -n, "min_mixed": lambda a, b, n: min(a, 2.5), "max_mixed": lambda a, b, n: max(n, 2.5), "min_sym": lambda a, b, n: min(n, b), "max_three": lambda a, b, n: max(a, b, 4),
    "bool_of": lambda a, b, n: bool(n), "not_of": lambda a, b, n: not n, "and_value": lambda a, b, n: n and b, "or_value": lambda a, b, n: n or b, "bool_arith": lambda a, b, n: (a > b) + (a == b) * 2, "cmp_chain": lambda a, b, n: 0 < n < b,
    "ternary": lambda a, b, n: a if a > b else -b, "float_of": lambda a, b, n: float(n), "int_of_float_mul": lambda a, b, n: int(a * 0.1), "int_of_float_mul_neg": lambda a, b, n: int(n * 0.7), "float_floordiv": lambda a, b, n: (n / 2) // 1,
    "float_mod": lambda a, b, n: (n / 2) % 1, "float_mod_negdiv": lambda a, b, n: (a / 2) % -1, "sqrt": lambda a, b, n: math.sqrt(a), "isqrt_idiom": lambda a, b, n: int(a ** 0.5), "log2": lambda a, b, n: math.log2(a + 1), "exp": lambda a, b, n: math.exp(-a),
    "sin": lambda a, b, n: math.sin(a), "div_zero": lambda a, b, n: a // (b - b), "mod_zero": lambda a, b, n: a % (b - b), "truediv_zero": lambda a, b, n: a / (b - b), "sqrt_neg": lambda a, b, n: math.sqrt(n), "sum_range": lambda a, b, n: sum(range(a)),
    "len_range_step": lambda a, b, n: len(range(0, a, 3)), "len_range_neg": lambda a, b, n: len(range(a, 0, -2)), "slice_len": lambda a, b, n: len(list(range(20))[n:b]), "str_len": lambda a, b, n: len(str(a)), "hash_like": lambda a, b, n: (a * 2654435761) % 4294967296,
    "gcd": lambda a, b, n: math.gcd(a, b), "bit_length_idiom": lambda a, b, n: a.bit_length() if isinstance(a, int) else int(a).bit_length(), "is_even_branch": lambda a, b, n: "even" if a % 2 == 0 else "odd",
}
FLT = {
    "round": lambda u: round(u), "round1": lambda u: round(u, 1), "int": lambda u: int(u), "floor": lambda u: math.floor(u), "ceil": lambda u: math.ceil(u), "trunc": lambda u: math.trunc(u),
    "floordiv1": lambda u: u // 1, "mod1": lambda u: u % 1, "mod_m1": lambda u: u % -1, "neg_mod3": lambda u: -u % 3, "divmod2": lambda u: list(divmod(u, 2)), "pow2": lambda u: u ** 2, "pow_half": lambda u: abs(u) ** 0.5,
    "abs": lambda u: abs(u), "self_eq": lambda u: u == u, "max0": lambda u: max(u, 0), "min0": lambda u: min(u, 0.0), "max_rev": lambda u: max(0.0, u), "isnan": lambda u: math.isnan(u), "isinf": lambda u: math.isinf(u), "bool": lambda u: bool(u),
    "mul0": lambda u: u * 0, "sub_self": lambda u: u - u, "div_self": lambda u: u / u, "copysign": lambda u: math.copysign(1.0, u), "lt_chain": lambda u: -1 < u <= 2.5, "ternary": lambda u: u if u > 0 else -u,
    "int_times": lambda u: int(u * 3), "round_half_even": lambda u: round(u * 2) / 2, "sqrt": lambda u: math.sqrt(u), "exp": lambda u: math.exp(u), "log": lambda u: math.log(u), "fmod": lambda u: math.fmod(u, 2), "hypot": lambda u: math.hypot(u, 3.0),
    "to_int_index": lambda u: [10, 20, 30, 40][int(u) % 4], "truthy_branch": lambda u: "t" if u else "f",
}
ITM = {  # k: Python int from an int64 tensor .item()
    "floordiv3": lambda k: k // 3, "mod3": lambda k: k % 3, "mod_m3": lambda k: k % -3, "divmod": lambda k: list(divmod(k, 7)), "pow2": lambda k: k ** 2, "mul_big": lambda k: k * k * k, "lshift": lambda k: k << 2 if k >= 0 else k,
    "rshift": lambda k: k >> 1, "abs": lambda k: abs(k), "neg": lambda k: -k, "truediv": lambda k: k / 4, "round_half": lambda k: round(k / 2), "int_div": lambda k: int(k / 3), "bool": lambda k: bool(k), "and7": lambda k: k & 7, "invert": lambda k: ~k,
    "float": lambda k: float(k), "cmp": lambda k: (k > 0) - (k < 0), "plus_one": lambda k: k + 1, "minus_one": lambda k: k - 1,
}
SIZES = [(0, 1), (1, 1), (2, 3), (3, 2), (5, 7), (7, 7), (8, 3), (10, 4), (11, 25), (13, 20), (17, 5), (64, 9)]
FLOATS = [0.5, -0.5, 1.5, 2.5, -2.5, 0.0, -0.0, 3.0, -7.25, 1e20, -1e20, 1e-320, float("inf"), float("-inf"), float("nan"), 0.1, 16777217.0, 4.35]
INTS = [0, 1, -1, 7, -7, 10, -10, 2 ** 31 - 1, -2 ** 31, 2 ** 31, 2 ** 62, -2 ** 62, 2 ** 63 - 1, -2 ** 63, 3037000500]


def cases():
    return ["i:" + k for k in INT] + ["f:" + k for k in FLT] + ["k:" + k for k in ITM]


def tensorize(v):
    try:
        if isinstance(v, (list, tuple)):
            return torch.tensor([float(x) for x in v], dtype=torch.float64)
        if isinstance(v, str):
            return torch.zeros(())
        return torch.full((2,), v, dtype=torch.float64)
    except OverflowError:
        return torch.zeros(())


def make(name):
    kind, key = name.split(":", 1)
    if kind == "i":
        e = INT[key]
        def prog(x, y):
            a, b = x.shape[0], y.shape[0]
            v = e(a, b, a - 10)
            return v, tensorize(v)
        def inputs():
            for a, b in SIZES:
                x, y = torch.ones(a), torch.ones(b)
                if os.environ.get("TCC_NO_MARK") != "1":      # mark_dynamic turns legitimate specialisations into ConstraintViolationError
                    if a > 1: torch._dynamo.mark_dynamic(x, 0)
                    if b > 1: torch._dynamo.mark_dynamic(y, 0)
                yield f"a={a},b={b}", (x, y)
    else:
        e = FLT[key] if kind == "f" else ITM[key]
        def prog(x):
            v = e(x.item())
            return v, tensorize(v)
        def inputs():
            for val in (FLOATS if kind == "f" else INTS):
                yield repr(val), (torch.tensor(val, dtype=torch.float64 if kind == "f" else torch.int64),)
    return prog, inputs


def norm(v):
    if isinstance(v, torch.Tensor):
        return ["T"] + [norm(x) for x in v.flatten().tolist()]
    if isinstance(v, (list, tuple)):
        return [norm(x) for x in v]
    if isinstance(v, float):
        return ["float", "nan" if v != v else repr(v)]
    if isinstance(v, bool):
        return ["bool", v]
    if isinstance(v, int):
        return ["int", str(v)]
    if isinstance(v, str):
        return ["str", v]
    return [type(v).__name__, repr(v)[:60]]


def observe(f, args):
    try:
        v, t = f(*args)
        return {"v": norm(v), "t": norm(t)}
    except Exception as e:  # noqa: BLE001
        return {"raised": type(e).__name__}


def run_case(name, backends):
    prog, inputs = make(name)
    rec = {"op": name, "diffs": [], "n": 0}
    for backend in backends:
        torch._dynamo.reset()
        if backend == "inductor_cppwrap":      # 11.3: the C++ wrapper generator (AOTI path) against the default Python wrapper
            cf = torch.compile(prog, backend="inductor", dynamic=True, options={"cpp_wrapper": True})
        else:
            cf = torch.compile(prog, backend=backend, dynamic=True)
        for label, args in inputs():
            e = observe(prog, args)
            c = observe(cf, args)
            rec["n"] += 1
            if e != c:
                both_raise = "raised" in e and "raised" in c
                rec["diffs"].append({"backend": backend, "input": label, "eager": e, "compiled": c,
                                     "class": "exc-type" if both_raise else ("SILENT" if "raised" in e else ("RAISES" if "raised" in c else "VALUE"))})
    classes = sorted({d["class"] for d in rec["diffs"]})
    rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
    return rec


def report(path):
    from collections import Counter
    rows = [json.loads(l) for l in open(path, encoding="utf-8") if l.strip()]
    print(len(rows), dict(Counter(r["verdict"] for r in rows)))
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
            n = sum(1 for x in r["diffs"] if (x["backend"], x["class"]) == key)
            print(f"   {d['backend']:9s} {d['class']:8s} x{n}  at {d['input']}: eager {json.dumps(d['eager'])[:150]}  compiled {json.dumps(d['compiled'])[:150]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backends", default="eager,inductor")
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "symint", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = a.only.split(",") if a.only else cases()
    if a.isolate:
        return run_isolated(os.path.abspath(__file__), names, ["--backends", a.backends], a.out_jsonl, timeout=1800)
    for n in names:
        rec = run_case(n, a.backends.split(","))
        jsonl_append(a.out_jsonl, rec)
        if rec["verdict"] != "ok":
            print(f"  !! {n}: {rec['verdict']}", flush=True)


if __name__ == "__main__":
    main()
