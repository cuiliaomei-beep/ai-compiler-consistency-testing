"""11.6  ONNX Runtime: the same exported graph run with graph optimisations disabled (ORT_DISABLE_ALL) and with every
optimisation enabled (ORT_ENABLE_ALL), both compared against PyTorch eager.  Same idea as host_opt_diff.py one level
up: one semantics, two execution paths, only one of which is well tested on edge values.

Corpus: small elementwise / reduction / indexing programs on edge-value inputs (signed zeros, inf, nan, integer limits,
half-way rounding cases), exported with torch.onnx.export (dynamo exporter).  Run with the nightly venv (has onnxruntime):
    ..\\venv_nightly\\Scripts\\python scripts/ort_opt_diff.py --isolate
    ..\\venv_nightly\\Scripts\\python scripts/ort_opt_diff.py --report
"""
import argparse
import io
import json
import math
import os
import sys
import tempfile
import warnings

import numpy as np
import torch

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.sweep_common import jsonl_append, run_isolated  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INF, NAN = float("inf"), float("nan")
warnings.simplefilter("ignore")

F32 = torch.tensor([0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 1.5, 2.5, -2.5, INF, -INF, NAN, 3.4028234663852886e38, -3.4028234663852886e38,
                    1.1754943508222875e-38, -1.1754943508222875e-38, 1e-45, 16777217.0, 0.1, 1e-3, 3.0, 65504.0, -65504.0, 7.0, 1e20, -1e20] * 3)
I64 = torch.tensor([0, 1, -1, 2, -2, 7, -7, 3, 2 ** 31 - 1, -2 ** 31, 2 ** 31, 2 ** 62, -2 ** 62, 2 ** 63 - 1, -2 ** 63, 100, -100, 64, -64, 255, 256] * 3)
I32 = torch.tensor([0, 1, -1, 2, -2, 7, -7, 3, 2 ** 31 - 1, -2 ** 31, 2 ** 30, -2 ** 30, 100, -100, 64, -64, 255, 256, 127, -128, 65535] * 3, dtype=torch.int32)
B = torch.tensor([True, False] * 39)


def roll(t, k=5):
    return torch.roll(t, k)


P = {}


def reg(name, fn, *inputs):
    P[name] = (fn, inputs)


for name, e in {"add": lambda a, b: a + b, "sub": lambda a, b: a - b, "mul": lambda a, b: a * b, "div": lambda a, b: a / b,
                "floor_divide": lambda a, b: torch.floor_divide(a, b), "remainder": lambda a, b: torch.remainder(a, b), "fmod": lambda a, b: torch.fmod(a, b),
                "pow": lambda a, b: torch.pow(a, b), "atan2": lambda a, b: torch.atan2(a, b), "maximum": lambda a, b: torch.maximum(a, b), "minimum": lambda a, b: torch.minimum(a, b),
                "fmax": lambda a, b: torch.fmax(a, b), "hypot": lambda a, b: torch.hypot(a, b), "copysign": lambda a, b: torch.copysign(a, b), "lt": lambda a, b: a < b, "eq": lambda a, b: a == b,
                "where_lt": lambda a, b: torch.where(a < b, a, b), "clamp_tensor": lambda a, b: torch.clamp(a, min=b), "addcmul": lambda a, b: torch.addcmul(a, a, b, value=0.5),
                "lerp": lambda a, b: torch.lerp(a, b, 0.5), "isclose": lambda a, b: torch.isclose(a, b), "sub_then_add_back": lambda a, b: (a - b) + b, "mul_div_back": lambda a, b: (a * b) / b,
                "x_plus_0": lambda a, b: a + 0.0, "x_times_1": lambda a, b: a * 1.0, "x_minus_x": lambda a, b: a - a, "x_div_x": lambda a, b: a / a, "neg_neg": lambda a, b: -(-a),
                "x_mul_0": lambda a, b: a * 0.0, "x_pow_1": lambda a, b: a ** 1.0, "x_pow_0": lambda a, b: a ** 0.0, "x_pow_2": lambda a, b: a ** 2.0, "x_pow_half": lambda a, b: a ** 0.5,
                "sqrt_square": lambda a, b: torch.sqrt(a * a), "exp_log": lambda a, b: torch.exp(torch.log(a)), "log_exp": lambda a, b: torch.log(torch.exp(a)),
                "abs_abs": lambda a, b: torch.abs(torch.abs(a)), "relu_relu": lambda a, b: torch.relu(torch.relu(a)), "cast_roundtrip_f16": lambda a, b: a.half().float(),
                "cast_roundtrip_i32": lambda a, b: a.to(torch.int32).float(), "cast_roundtrip_bf16": lambda a, b: a.bfloat16().float(), "cast_i64_f32_i64": lambda a, b: a.long().float().long(),
                "reshape_transpose_back": lambda a, b: a.reshape(6, 13).t().t().reshape(78), "slice_cat": lambda a, b: torch.cat([a[:40], a[40:]]), "gather_self": lambda a, b: a[torch.arange(78)],
                "sum": lambda a, b: a.sum(), "mean": lambda a, b: a.mean(), "prod": lambda a, b: a[:8].prod(), "max": lambda a, b: a.max(), "min": lambda a, b: a.min(), "amax_neg0": lambda a, b: torch.stack([a, -a]).amax(0),
                "argmax": lambda a, b: a.reshape(6, 13).argmax(1), "argmin": lambda a, b: a.reshape(6, 13).argmin(1), "cumsum": lambda a, b: a.cumsum(0), "cumprod": lambda a, b: a[:10].cumprod(0),
                "softmax": lambda a, b: torch.softmax(a.reshape(6, 13), 1), "log_softmax": lambda a, b: torch.log_softmax(a.reshape(6, 13), 1), "logsumexp": lambda a, b: torch.logsumexp(a.reshape(6, 13), 1),
                "sigmoid": lambda a, b: torch.sigmoid(a), "tanh": lambda a, b: torch.tanh(a), "gelu": lambda a, b: torch.nn.functional.gelu(a), "gelu_tanh": lambda a, b: torch.nn.functional.gelu(a, approximate="tanh"),
                "silu": lambda a, b: torch.nn.functional.silu(a), "softplus": lambda a, b: torch.nn.functional.softplus(a), "elu": lambda a, b: torch.nn.functional.elu(a), "hardtanh": lambda a, b: torch.nn.functional.hardtanh(a),
                "layer_norm": lambda a, b: torch.nn.functional.layer_norm(a.reshape(6, 13), (13,)), "batch_norm_like": lambda a, b: (a.reshape(6, 13) - a.reshape(6, 13).mean(0)) / (a.reshape(6, 13).var(0, unbiased=False) + 1e-5).sqrt(),
                "matmul": lambda a, b: a.reshape(6, 13) @ b.reshape(13, 6), "matmul_then_add": lambda a, b: a.reshape(6, 13) @ b.reshape(13, 6) + a[:6], "bias_gelu": lambda a, b: torch.nn.functional.gelu(a + b),
                "round": lambda a, b: torch.round(a), "floor": lambda a, b: torch.floor(a), "ceil": lambda a, b: torch.ceil(a), "trunc": lambda a, b: torch.trunc(a), "sign": lambda a, b: torch.sign(a),
                "reciprocal": lambda a, b: torch.reciprocal(a), "rsqrt": lambda a, b: torch.rsqrt(a), "erf": lambda a, b: torch.erf(a), "expm1": lambda a, b: torch.expm1(a), "log1p": lambda a, b: torch.log1p(a),
                "isnan": lambda a, b: torch.isnan(a), "isinf": lambda a, b: torch.isinf(a), "nan_to_num": lambda a, b: torch.nan_to_num(a), "clamp_scalar": lambda a, b: a.clamp(-1.0, 1.0),
                "where_isnan": lambda a, b: torch.where(torch.isnan(a), torch.zeros_like(a), a), "div_where_nonzero": lambda a, b: torch.where(b != 0, a / b, torch.zeros_like(a)),
                "chain_fusable": lambda a, b: torch.relu(a * b + a) * 2.0 - b, "mul_add_fma": lambda a, b: a * b + a}.items():
    reg(f"f32:{name}", e, F32, roll(F32))
for name, e in {"add": lambda a, b: a + b, "sub": lambda a, b: a - b, "mul": lambda a, b: a * b, "floor_divide": lambda a, b: torch.floor_divide(a, torch.where(b == 0, torch.ones_like(b), b)),
                "remainder": lambda a, b: torch.remainder(a, torch.where(b == 0, torch.ones_like(b), b)), "div_true": lambda a, b: a / torch.where(b == 0, torch.ones_like(b), b),
                "bitwise_and": lambda a, b: a & b, "bitwise_or": lambda a, b: a | b, "bitwise_xor": lambda a, b: a ^ b, "lshift": lambda a, b: a << (b.abs() % 8), "rshift": lambda a, b: a >> (b.abs() % 8),
                "neg": lambda a, b: -a, "abs": lambda a, b: a.abs(), "sign": lambda a, b: a.sign(), "square": lambda a, b: a * a, "pow2": lambda a, b: a ** 2, "maximum": lambda a, b: torch.maximum(a, b),
                "minimum": lambda a, b: torch.minimum(a, b), "sum": lambda a, b: a.sum(), "prod": lambda a, b: a[:6].prod(), "cumsum": lambda a, b: a.cumsum(0), "max": lambda a, b: a.max(), "argmax": lambda a, b: a.reshape(3, 21).argmax(1),
                "to_float": lambda a, b: a.float(), "to_double": lambda a, b: a.double(), "to_int32": lambda a, b: a.to(torch.int32), "to_int8": lambda a, b: a.to(torch.int8), "to_bool": lambda a, b: a.bool(),
                "to_uint8": lambda a, b: a.to(torch.uint8), "float_roundtrip": lambda a, b: a.float().long(), "x_plus_0": lambda a, b: a + 0, "x_times_1": lambda a, b: a * 1, "x_minus_x": lambda a, b: a - a,
                "mul_div_back": lambda a, b: (a * 3) // 3, "where_lt": lambda a, b: torch.where(a < b, a, b), "clamp": lambda a, b: a.clamp(-100, 100), "eq_self": lambda a, b: a == a,
                "add_then_cast_i32": lambda a, b: (a + b).to(torch.int32), "cast_i32_then_add": lambda a, b: a.to(torch.int32) + b.to(torch.int32), "gather": lambda a, b: a[b.abs() % 63]}.items():
    reg(f"i64:{name}", e, I64, roll(I64))
for name, e in {"add": lambda a, b: a + b, "mul": lambda a, b: a * b, "sub": lambda a, b: a - b, "neg": lambda a, b: -a, "abs": lambda a, b: a.abs(), "square": lambda a, b: a * a,
                "sum": lambda a, b: a.sum(), "cumsum": lambda a, b: a.cumsum(0), "to_int64_back": lambda a, b: a.long().to(torch.int32), "to_int16": lambda a, b: a.to(torch.int16),
                "div_true": lambda a, b: a / torch.where(b == 0, torch.ones_like(b), b), "floor_divide": lambda a, b: torch.floor_divide(a, torch.where(b == 0, torch.ones_like(b), b)),
                "remainder": lambda a, b: torch.remainder(a, torch.where(b == 0, torch.ones_like(b), b)), "lshift": lambda a, b: a << (b.abs() % 8), "maximum": lambda a, b: torch.maximum(a, b)}.items():
    reg(f"i32:{name}", e, I32, roll(I32))
for name, e in {"and": lambda a, b: a & b, "or": lambda a, b: a | b, "xor": lambda a, b: a ^ b, "not": lambda a, b: ~a, "sum": lambda a, b: a.sum(), "to_float": lambda a, b: a.float(),
                "any_all": lambda a, b: torch.stack([a.any(), a.all()]), "where": lambda a, b: torch.where(a, F32, roll(F32)), "add_bool": lambda a, b: a + b, "mul_bool": lambda a, b: a * b}.items():
    reg(f"bool:{name}", e, B, roll(B))


class M(torch.nn.Module):
    def __init__(self, f):
        super().__init__()
        self.f = f

    def forward(self, a, b):
        return self.f(a, b)


def export(fn, inputs):
    import onnx
    m = M(fn).eval()
    with tempfile.TemporaryDirectory() as d:
        path = os.path.join(d, "m.onnx")
        prog = torch.onnx.export(m, tuple(inputs), dynamo=True, report=False, verbose=False)
        prog.save(path)
        return open(path, "rb").read()


def run_ort(model_bytes, inputs, level):
    import onnxruntime as ort
    so = ort.SessionOptions()
    so.graph_optimization_level = level
    so.log_severity_level = 3
    sess = ort.InferenceSession(model_bytes, so, providers=["CPUExecutionProvider"])
    names = [i.name for i in sess.get_inputs()]
    feed = {n: x.numpy() for n, x in zip(names, inputs)}
    return [torch.from_numpy(np.asarray(o)) for o in sess.run(None, feed)]


def norm(v):
    return [t for t in (v if isinstance(v, (tuple, list)) else (v,)) if isinstance(t, torch.Tensor)]


def diff(e, c):
    if e.shape != c.shape:
        return f"shape {tuple(e.shape)} vs {tuple(c.shape)}"
    if e.dtype != c.dtype:
        return f"dtype {e.dtype} vs {c.dtype}"
    if e.numel() == 0:
        return None
    if not e.dtype.is_floating_point:
        if not torch.equal(e, c):
            i = (e != c).nonzero()[0].tolist()
            return f"value at {i}: eager {e[tuple(i)].item()!r} ort {c[tuple(i)].item()!r}"
        return None
    e64, c64 = e.double(), c.double()
    if not torch.equal(e64.isnan(), c64.isnan()):
        i = (e64.isnan() != c64.isnan()).nonzero()[0].tolist()
        return f"nan pattern at {i}: eager {e64[tuple(i)].item()!r} ort {c64[tuple(i)].item()!r}"
    m = ~e64.isnan()
    if not torch.equal(e64[m].isinf(), c64[m].isinf()) or not torch.equal(e64[m][e64[m].isinf()], c64[m][c64[m].isinf()]):
        bad = ((e64.isinf() != c64.isinf()) | (e64.isinf() & (e64 != c64))) & m
        i = bad.nonzero()[0].tolist()
        return f"inf at {i}: eager {e64[tuple(i)].item()!r} ort {c64[tuple(i)].item()!r}"
    fin = m & ~e64.isinf()
    a, b = e64[fin], c64[fin]
    rel = (a - b).abs() / (a.abs() + b.abs()).clamp(min=1.0)
    if rel.numel() and rel.max().item() > 1e-4:
        k = rel.argmax().item()
        return f"value rel {rel.max().item():.3g}: eager {a[k].item()!r} ort {b[k].item()!r}"
    z = fin & (e64 == 0)
    if z.any() and not torch.equal(torch.signbit(e64[z]), torch.signbit(c64[z])):
        return "sign of zero"
    return None


def run_case(name):
    import onnxruntime as ort
    fn, inputs = P[name]
    rec = {"op": name, "diffs": {}}
    try:
        e = norm(fn(*inputs))
    except Exception as ex:  # noqa: BLE001
        rec["verdict"] = "EAGER_RAISES:" + type(ex).__name__
        return rec
    try:
        model = export(fn, inputs)
    except Exception as ex:  # noqa: BLE001
        rec["verdict"] = "EXPORT_FAIL"
        rec["detail"] = f"{type(ex).__name__}: {str(ex)[:200]}"
        return rec
    for label, level in (("disable_all", ort.GraphOptimizationLevel.ORT_DISABLE_ALL), ("enable_all", ort.GraphOptimizationLevel.ORT_ENABLE_ALL)):
        try:
            out = run_ort(model, inputs, level)
        except Exception as ex:  # noqa: BLE001
            rec["diffs"][label] = f"RAISES {type(ex).__name__}: {str(ex)[:200]}"
            continue
        if len(out) != len(e):
            rec["diffs"][label] = f"STRUCT {len(e)} vs {len(out)}"
            continue
        for a, b in zip(e, out):
            d = diff(a, b)
            if d:
                rec["diffs"][label] = ("SIGNZERO " if d == "sign of zero" else "VALUE ") + d
                break
    a, b = rec["diffs"].get("disable_all"), rec["diffs"].get("enable_all")
    rec["verdict"] = "ok" if not a and not b else ("BOTH" if a and b else ("OPT_ONLY" if b else "NOOPT_ONLY"))
    return rec


def report(path):
    rows = [json.loads(l) for l in open(path, encoding="utf-8")]
    print(f"{len(rows)} programs;", {v: sum(1 for r in rows if r['verdict'].split(':')[0] == v) for v in sorted({r['verdict'].split(':')[0] for r in rows})})
    for r in rows:
        if r["verdict"] not in ("ok",) and not r["verdict"].startswith("EXPORT_FAIL"):
            print(f"\n[{r['verdict']}] {r['op']}")
            for k, v in r.get("diffs", {}).items():
                print(f"    {k:12s} {v[:300]}")
    ef = [r["op"] for r in rows if r["verdict"].startswith("EXPORT_FAIL")]
    print("\nexport failed:", len(ef), ef[:40])


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--isolate", action="store_true")
    ap.add_argument("--report", action="store_true")
    ap.add_argument("--out-jsonl", default=os.path.join(ROOT, "results", "ort", "cases.jsonl"))
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out_jsonl), exist_ok=True)
    if a.report:
        return report(a.out_jsonl)
    names = [a.only] if a.only else list(P)
    if a.isolate and not a.only:
        return run_isolated(os.path.abspath(__file__), names, [], a.out_jsonl, timeout=600)
    for n in names:
        try:
            rec = run_case(n)
        except Exception as e:  # noqa: BLE001
            rec = {"op": n, "verdict": "TOOL_ERROR", "diffs": {"tool": f"{type(e).__name__}: {str(e)[:300]}"}}
        jsonl_append(a.out_jsonl, rec)
        print(rec["verdict"], n, rec.get("diffs", rec.get("detail", "")), flush=True)


if __name__ == "__main__":
    main()
