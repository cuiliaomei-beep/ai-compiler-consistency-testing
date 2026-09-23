"""6.2b: unary operators x input dtype x {plain, autocast(cpu,bf16), out= of another dtype}: compare ONLY the output
dtype / shape / raise-or-not between eager and Inductor (aot_eager agrees with eager for dtype rules, so Inductor is
the interesting backend; ~2 s per compile on CPU).

    python scripts/unary_dtype_sweep.py [--only names] [--modes plain,autocast,out] [--out results/unary_dtype]
"""
import argparse
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402
from torch.testing._internal.opinfo.core import UnaryUfuncInfo  # noqa: E402

torch._dynamo.config.recompile_limit = 10 ** 5
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6

DTYPES = [torch.bool, torch.int32, torch.int64, torch.float16, torch.bfloat16, torch.float32, torch.float64, torch.complex64]
OUT_DTYPES = [torch.float32, torch.float64, torch.bfloat16, torch.int64]


def sig(r):
    if isinstance(r, Exception):
        return f"raise:{type(r).__name__}"
    if isinstance(r, torch.Tensor):
        return f"{str(r.dtype).split('.')[-1]}{tuple(r.shape)}"
    if isinstance(r, (tuple, list)):
        return "(" + ",".join(sig(x) for x in r) + ")"
    return f"{type(r).__name__}"


def mk(dt, g):
    if dt == torch.bool:
        return torch.randint(0, 2, (3, 4), generator=g).bool()
    if dt in (torch.int32, torch.int64):
        return torch.randint(1, 4, (3, 4), generator=g).to(dt)
    if dt.is_complex:
        return torch.complex(torch.rand(3, 4, generator=g) + 0.5, torch.rand(3, 4, generator=g)).to(dt)
    return (torch.rand(3, 4, generator=g) * 0.8 + 0.1).to(dt)      # (0.1, 0.9): valid for log/asin/...


def call(fn, *args, **kw):
    try:
        with torch.no_grad():
            return fn(*args, **kw)
    except Exception as e:  # noqa: BLE001
        return e


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--modes", default="plain,autocast,out")
    ap.add_argument("--backend", default="inductor")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "unary_dtype"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    modes = a.modes.split(",")
    only = set(a.only.split(",")) if a.only else None
    ops = [o for o in op_db if isinstance(o, UnaryUfuncInfo) and (not only or o.name in only)]
    print(f"torch {torch.__version__} | {len(ops)} unary ops | modes {modes} | backend {a.backend}")
    g = torch.Generator().manual_seed(0)
    rows, mism, t0 = [], [], time.time()
    jl = open(os.path.join(a.out, "unary_dtype.jsonl"), "a", encoding="utf-8")
    for oi in ops:
        fn = oi.get_op()
        torch._dynamo.reset()
        cf = torch.compile(fn, backend=a.backend, dynamic=False)
        for dt in DTYPES:
            x = mk(dt, g)
            cases = []
            if "plain" in modes:
                cases.append(("plain", None, {}))
            if "autocast" in modes and (dt.is_floating_point):
                cases.append(("autocast_bf16", torch.autocast("cpu", dtype=torch.bfloat16), {}))
            if "out" in modes:
                for od in OUT_DTYPES:
                    if od != dt:
                        cases.append((f"out={str(od).split('.')[-1]}", None, {"out": torch.empty(0, dtype=od)}))
            for mode, ctx, kw in cases:
                def run(f):
                    kw2 = {k: (v.clone() if isinstance(v, torch.Tensor) else v) for k, v in kw.items()}
                    if ctx is not None:
                        with ctx:
                            return call(f, x, **kw2)
                    return call(f, x, **kw2)
                e, c = run(fn), run(cf)
                se, sc = sig(e), sig(c)
                rec = {"op": oi.name, "dtype": str(dt).split(".")[-1], "mode": mode, "eager": se, "compiled": sc}
                if se != sc:
                    kind = ("raise" if se.startswith("raise") != sc.startswith("raise") else
                            "raise_type" if se.startswith("raise") else "dtype")
                    rec["kind"] = kind
                    mism.append(rec)
                    if kind != "raise_type":
                        print(f"  DTYPE {oi.name:<24} {rec['dtype']:<9} {mode:<14} eager={se} {a.backend}={sc}", flush=True)
                rows.append(rec)
                jl.write(json.dumps(rec) + "\n")
        print(f"[{oi.name}] done ({time.time() - t0:.0f}s, {len(mism)} mismatches so far)", flush=True)
    jl.close()
    kinds = {}
    for m in mism:
        kinds[m["kind"]] = kinds.get(m["kind"], 0) + 1
    lines = [f"# unary dtype sweep ({a.backend}, torch {torch.__version__})", "", f"- cases: {len(rows)}, mismatches: {len(mism)} {kinds}; wall {time.time() - t0:.0f} s", "",
             "| op | dtype | mode | eager | compiled | kind |", "|---|---|---|---|---|---|"]
    for m in sorted(mism, key=lambda r: (r["kind"] != "dtype", r["op"])):
        if m["kind"] != "raise_type":
            lines.append(f"| {m['op']} | {m['dtype']} | {m['mode']} | {m['eager']} | {m['compiled']} | {m['kind']} |")
    lines += ["", f"(raise_type mismatches = {kinds.get('raise_type', 0)}, omitted: exception-class wrapping only)"]
    open(os.path.join(a.out, "UNARY_DTYPE.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"cases": len(rows), "mismatches": len(mism), "kinds": kinds, "wall_s": round(time.time() - t0, 1)}))


if __name__ == "__main__":
    main()
