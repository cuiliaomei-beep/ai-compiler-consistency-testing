"""10.13 (5): host-compiler differential on the kernels Inductor really generates.

The same programs are compiled by Inductor twice, in two fresh processes that differ only in the optimisation level
handed to the host C++ compiler (TORCHINDUCTOR_DEBUG_COMPILE=1 -> /Od or -O0; default -> /O2 or -O3), each with its
own cache directory.  Inductor emits the same C++ in both, so any bit-level difference in the results is produced by
the host compiler's optimiser (or by undefined behaviour in the generated C++ that the optimiser exposes).

Corpus: the 94 unary + 41 binary pointwise programs of prefix_consistency_sweep.py on 10 dtypes (edge values spread
over vector body and scalar tail), plus all compositions f(g(x)) of a set of cheap unary programs.  Programs are
batched (several outputs per compiled function) to keep the number of host-compiler invocations manageable.

    python scripts/host_opt_diff.py --shard 0/3        # driver (detached run friendly; resumes from the jsonl)
    python scripts/host_opt_diff.py --report
Results: results/host_opt/cases_s<i>.jsonl
"""
import argparse
import glob
import json
import os
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, ROOT)
OUT = os.path.join(ROOT, "results", "host_opt")
BATCH = 16
GROUP = 4
PAIR_DTYPES = ("float32", "float64", "int32", "int8")
PAIR_SET = ["abs", "neg", "sign", "relu", "floor", "round", "trunc", "square", "reciprocal", "sqrt", "clamp", "bitwise_not_i",
            "rshift1", "where_self", "mod3", "floordiv3", "cast_i32", "cast_i8", "cast_f16", "nan_to_num", "mul_add", "hardtanh"]


def batches():
    """[(batch_id, kind, dtype_name, [program names])]; kind: u, b, p:<inner> (pairs f(inner(x)))."""
    from scripts.prefix_consistency_sweep import B, DTYPES, U
    out = []
    for dt in DTYPES:
        d = str(dt).replace("torch.", "")
        for kind, names in (("u", list(U)), ("b", list(B))):
            for i in range(0, len(names), BATCH):
                out.append((f"{kind}:{d}:{i // BATCH}", kind, d, names[i:i + BATCH]))
        for inner in (PAIR_SET if d in PAIR_DTYPES else []):
            out.append((f"p:{d}:{inner}", "p:" + inner, d, PAIR_SET))
    return out


def worker(spec_path, out_path):
    import torch
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
    from scripts.prefix_consistency_sweep import B, U, data
    spec = json.load(open(spec_path))
    dt = getattr(torch, spec["dtype"])
    kind, names = spec["kind"], spec["names"]
    x, y = data(dt, 1), data(dt, 2)
    progs = {}
    for n in names:                                    # keep only what eager accepts for this dtype
        if kind == "u":
            f, args = U[n], (x,)
        elif kind == "b":
            f, args = B[n], (x, y)
        else:
            inner = U[kind[2:]]
            f, args = (lambda t, g=U[n], h=inner: g(h(t))), (x,)
        try:
            f(*args)
            progs[n] = f
        except Exception:
            pass
    res = {"eager": {}, "compiled": {}, "error": None}
    if progs:
        args = (x, y) if kind == "b" else (x,)
        keys = list(progs)
        na = len(args)
        # every program gets its own inputs of its own length (70 + i): equal lengths would be fused into one kernel, where a
        # shared inner value has several uses (single-use peepholes such as MSVC's abs(abs(x)) do not fire) and one
        # non-vectorisable program turns the whole kernel scalar.  Distinct lengths -> one kernel per program, all built in
        # parallel by Inductor's compile pool.
        # Small groups: in one large generated function MSVC does not apply the abs(abs(x)) fold at all, so large batches hide
        # host-compiler defects; GROUP programs per compiled function keeps the known defect visible (checked).
        errors = []
        for g0 in range(0, len(keys), GROUP):
            grp = keys[g0:g0 + GROUP]
            flat = [torch.cat([t, t[:i]]) for i, _ in enumerate(grp) for t in args]
            fn = lambda *a, grp=grp: tuple(progs[k](*a[i * na:(i + 1) * na]) for i, k in enumerate(grp))
            torch._dynamo.reset()
            try:
                outs = torch.compile(fn, dynamic=False)(*flat)
                for i, (k, o) in enumerate(zip(grp, outs)):
                    res["compiled"][k] = o
                    res["eager"][k] = progs[k](*flat[i * na:(i + 1) * na])
            except Exception as e:
                errors.append(f"{grp}: {type(e).__name__}: {str(e)[:200]}")
        res["error"] = "; ".join(errors) or None
    torch.save(res, out_path)


def run_worker(spec, debug_compile, tmp):
    spec_path = os.path.join(tmp, "spec.json")
    json.dump(spec, open(spec_path, "w"))
    out_path = os.path.join(tmp, f"out_{debug_compile}.pt")
    env = dict(os.environ, TORCHINDUCTOR_DEBUG_COMPILE=str(debug_compile), TORCHINDUCTOR_CACHE_DIR=os.path.join(tmp, f"cache_{debug_compile}"),
               PYTHONUTF8="1", TORCHINDUCTOR_FX_GRAPH_CACHE="0")
    try:
        r = subprocess.run([sys.executable, os.path.abspath(__file__), "--worker", spec_path, out_path], env=env, capture_output=True, text=True, timeout=3600)
    except subprocess.TimeoutExpired:
        return None, "timeout"
    if r.returncode or not os.path.exists(out_path):
        return None, f"exit {r.returncode}: {r.stderr[-300:]}"
    import torch
    return torch.load(out_path, weights_only=False), None


def bits(t):
    import torch
    t = t.contiguous()
    return t.view(torch.uint8) if t.dtype != torch.bool else t.to(torch.uint8)


def compare(spec, opt, dbg):
    import torch
    rows = []
    for k in opt["compiled"]:
        a, b = opt["compiled"][k], dbg["compiled"].get(k)
        if b is None:
            continue
        if a.dtype == b.dtype and a.shape == b.shape and torch.equal(bits(a), bits(b)):
            continue
        rec = {"program": k, "class": "bits"}
        if a.dtype != b.dtype or a.shape != b.shape:
            rec["class"] = "meta"
        else:
            nan_same = a.is_floating_point() and torch.equal(torch.nan_to_num(a.double(), nan=12345.0), torch.nan_to_num(b.double(), nan=12345.0)) \
                and torch.equal(torch.signbit(a), torch.signbit(b))
            if nan_same:
                rec["class"] = "nan-bits"
            else:
                i = int((bits(a).reshape(a.numel(), -1) != bits(b).reshape(a.numel(), -1)).any(dim=1).nonzero()[0])
                e = opt["eager"][k]
                rec.update(index=i, optimised=repr(a.flatten()[i].item()), unoptimised=repr(b.flatten()[i].item()), eager=repr(e.flatten()[i].item()),
                           n_diff=int((bits(a).reshape(a.numel(), -1) != bits(b).reshape(a.numel(), -1)).any(dim=1).sum()))
        rows.append(rec)
    return rows


def report():
    rows = []
    for p in sorted(glob.glob(os.path.join(OUT, "cases_s*.jsonl"))):
        rows += [json.loads(l) for l in open(p, encoding="utf-8")]
    st = {}
    for r in rows:
        st[r["status"]] = st.get(r["status"], 0) + 1
    print(len(rows), "batches", st)
    for r in rows:
        if r["status"] == "DIFF":
            for d in r["diffs"]:
                if d["class"] != "nan-bits":
                    print(f"[{d['class']}] {r['id']} {d['program']}: i={d.get('index')} /O2 {d.get('optimised')}  /Od {d.get('unoptimised')}  eager {d.get('eager')}  (#diff {d.get('n_diff')})")
        elif r["status"] not in ("ok",):
            print(f"[{r['status']}] {r['id']}: {str(r.get('detail'))[:160]}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--worker", nargs=2)
    ap.add_argument("--shard", default="0/1")
    ap.add_argument("--only", default="")
    ap.add_argument("--report", action="store_true")
    a = ap.parse_args()
    if a.worker:
        return worker(*a.worker)
    if a.report:
        return report()
    from tcc.sweep_common import jsonl_append, jsonl_done
    os.makedirs(OUT, exist_ok=True)
    si, sn = (int(v) for v in a.shard.split("/"))
    path = os.path.join(OUT, f"cases_s{si}.jsonl")
    done = jsonl_done(path, key="id")
    todo = [b for k, b in enumerate(batches()) if k % sn == si and b[0] not in done and (not a.only or a.only in b[0])]
    print(f"shard {si}/{sn}: {len(todo)} batches to run", flush=True)
    for bid, kind, d, names in todo:
        spec = {"kind": kind, "dtype": d, "names": names}
        with tempfile.TemporaryDirectory(ignore_cleanup_errors=True) as tmp:
            opt, e1 = run_worker(spec, 0, tmp)
            dbg, e2 = run_worker(spec, 1, tmp)
            if e1 or e2:
                rec = {"id": bid, "status": "CRASH", "detail": {"optimised": e1, "unoptimised": e2}}
            else:
                diffs = compare(spec, opt, dbg)
                rec = {"id": bid, "status": "DIFF" if diffs else "ok", "n": len(opt["compiled"]), "diffs": diffs}
                if opt["error"] or dbg["error"]:
                    rec["errors"] = {"optimised": opt["error"], "unoptimised": dbg["error"]}
                    if bool(opt["error"]) != bool(dbg["error"]):
                        rec["status"] = "ERROR_PARITY"
        jsonl_append(path, rec)
        print(bid, rec["status"], [f"{x['program']}:{x['class']}" for x in rec.get("diffs", [])], flush=True)
    print("finished", flush=True)


if __name__ == "__main__":
    main()
