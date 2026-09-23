"""11.6  torch.export as a third path: every OpInfo op x edge-value inputs, eager vs
  (a) torch.export.export(...).module()                     -- pre-dispatch graph run by the FX interpreter
  (b) ep.run_decompositions().module()                      -- core-ATen decompositions (the AOTI / ExecuTorch input)
No compiler involved, so it runs anywhere.  Reuses the edge-value machinery of opinfo_edge_sweep.py.
    python scripts/export_edge_diff.py --dtypes float32,int64 --shard 0/2 --out results/export_edge/f32_0.jsonl
    python scripts/export_edge_diff.py --report results/export_edge/*.jsonl
"""
import argparse, glob, importlib.util, itertools, json, os, sys, time, traceback
import torch
spec = importlib.util.spec_from_file_location("oe", os.path.join(os.path.dirname(os.path.abspath(__file__)), "opinfo_edge_sweep.py"))
oe = importlib.util.module_from_spec(spec); spec.loader.exec_module(oe)
from torch.testing._internal.common_methods_invocations import op_db


class W(torch.nn.Module):
    def __init__(self, fn, kwargs):
        super().__init__(); self.fn, self.kw = fn, kwargs

    def forward(self, *args):
        return self.fn(*args, **self.kw)


def run_one(op, dtype, max_samples):
    rec = {"op": op.name, "dtype": str(dtype).split(".")[-1], "samples": 0, "diffs": [], "errors": []}
    try:
        samples = list(itertools.islice(op.sample_inputs("cpu", dtype, requires_grad=False), max_samples))
    except Exception as e:  # noqa: BLE001
        rec["verdict"] = "NO_SAMPLES:" + type(e).__name__; return rec
    fn = op.get_op()
    for si, s in enumerate(samples):
        try:
            inp, args, kwargs = oe.replace(s, dtype)
        except Exception as e:  # noqa: BLE001
            rec["errors"].append(f"prep {type(e).__name__}"); continue
        tensors = [inp, *[a for a in args if isinstance(a, torch.Tensor)]]
        if any(not isinstance(a, torch.Tensor) for a in args) or not isinstance(inp, torch.Tensor):
            rec["errors"].append("non-tensor positional arg"); continue
        try:
            eager = fn(inp, *args, **kwargs); eager_err = None
        except Exception as e:  # noqa: BLE001
            eager, eager_err = None, type(e).__name__
        try:
            ep = torch.export.export(W(fn, kwargs), tuple(t.clone() for t in tensors))
        except Exception as e:  # noqa: BLE001
            rec["errors"].append(f"export {type(e).__name__}"); continue
        rec["samples"] += 1
        for label, gm in (("export", ep.module()), ("decomposed", None)):
            if label == "decomposed":
                try:
                    gm = ep.run_decompositions().module()
                except Exception as e:  # noqa: BLE001
                    rec["errors"].append(f"run_decompositions {type(e).__name__}"); continue
            try:
                out = gm(*[t.clone() for t in tensors]); out_err = None
            except Exception as e:  # noqa: BLE001
                out, out_err = None, type(e).__name__
            if eager_err or out_err:
                if eager_err and not out_err:
                    rec["diffs"].append({"i": si, "class": f"SILENT[{label}]", "detail": f"eager raises {eager_err}, {label} returns"})
                elif out_err and not eager_err:
                    rec["diffs"].append({"i": si, "class": f"RAISES[{label}]", "detail": f"{label} raises {out_err}"})
                continue
            fe, fo = oe.flat(eager), oe.flat(out)
            if len(fe) != len(fo):
                rec["diffs"].append({"i": si, "class": f"STRUCT[{label}]", "detail": f"{len(fe)} vs {len(fo)}"}); continue
            for e, c in zip(fe, fo):
                d = oe.diff(e, c)
                if d:
                    rec["diffs"].append({"i": si, "class": ("SIGNZERO" if d == "sign of zero" else "VALUE") + f"[{label}]", "detail": d, "repr": repr(s)[:200]}); break
    classes = sorted({d["class"] for d in rec["diffs"]})
    rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
    return rec


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dtypes", default="float32,int64,bool"); ap.add_argument("--shard", default="0/1"); ap.add_argument("--max-samples", type=int, default=3)
    ap.add_argument("--only", default=None); ap.add_argument("--out", default=None); ap.add_argument("--report", nargs="*", default=None)
    a = ap.parse_args()
    if a.report is not None:
        rows = [json.loads(l) for pat in (a.report or ["results/export_edge/*.jsonl"]) for p in glob.glob(pat) for l in open(p, encoding="utf-8") if l.strip()]
        import collections
        print(len(rows), "pairs", dict(collections.Counter(r["verdict"].split(":")[0] for r in rows)))
        for r in rows:
            ds = [d for d in r["diffs"] if not d["class"].startswith("SIGNZERO")]
            if ds:
                print(f"  {r['op']:38s} {r['dtype']:8s}", "; ".join(f"#{d['i']} {d['class']} {d['detail'][:70]}" for d in ds[:2]))
        return
    k, n = map(int, a.shard.split("/")); out = a.out or f"results/export_edge/cases_{k}.jsonl"
    os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
    dtypes = [getattr(torch, d) for d in a.dtypes.split(",")]
    ops = [op for op in op_db if not any(s in op.name for s in oe.SKIP_SUBSTR) and (a.only is None or op.name == a.only)]
    work = [(op, dt) for op in ops for dt in dtypes if op.supports_dtype(dt, "cpu")][k::n]
    done = oe.done_keys(out)
    todo = [(op, dt) for op, dt in work if (op.name, str(dt).split(".")[-1]) not in done]
    print(f"torch {torch.__version__}: {len(work)} pairs in shard {a.shard}, {len(todo)} to do", flush=True)
    t0 = time.time()
    for i, (op, dt) in enumerate(todo):
        t = time.time()
        try:
            rec = run_one(op, dt, a.max_samples)
        except Exception:  # noqa: BLE001
            rec = {"op": op.name, "dtype": str(dt).split(".")[-1], "verdict": "TOOL_ERROR", "diffs": [], "errors": [traceback.format_exc()[-300:]]}
        with open(out, "a", encoding="utf-8") as f:
            f.write(json.dumps(rec) + "\n")
        print(f"[{i + 1}/{len(todo)}] {rec['verdict']:14s} {op.name} {rec['dtype']} ({time.time() - t:.0f}s, total {time.time() - t0:.0f}s)", flush=True)
    print("SWEEP DONE", flush=True)


if __name__ == "__main__":
    main()
