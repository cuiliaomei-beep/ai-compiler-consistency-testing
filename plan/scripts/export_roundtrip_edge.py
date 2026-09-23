"""7.7  "Bring the artifact back and run it": for every OpInfo op (one edge-filled sample, see opinfo_edge_sweep) the
deployment artifacts are produced, written to disk, loaded back and executed, and their outputs compared with eager:
    SL  torch.export.export(...) -> torch.export.save -> torch.export.load -> .module()(...)
    AO  torch._inductor.aoti_compile_and_package -> aoti_load_package -> runner(...)
Earlier sweeps (5.8, tcc/aoti_diff.py) executed the AOTI runner in-process on plain samples; this one adds the
save/load round trip, the edge values (inf/nan/max/near-singular) and the dtype/stride comparison of the loaded artifact.
Resumable: one JSON line per (op, dtype); rerun to continue.
    python scripts/export_roundtrip_edge.py [--dtype float32] [--only op]   -> results/export_roundtrip/<dtype>.jsonl
"""
import argparse
import io
import itertools
import json
import os
import shutil
import sys
import tempfile
import time

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_rt_"))
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

import opinfo_edge_sweep as oes  # noqa: E402  (replace / diff / flat / SKIP_SUBSTR)


def take_samples(gen, n):
    """Take n samples and CLOSE the OpInfo generator right away: its @torch.no_grad decorator otherwise runs
    set_grad_enabled in the GC finaliser, possibly in the middle of a later trace (spurious graph nodes)."""
    out = []
    try:
        for _ in range(n):
            try:
                out.append(next(gen))
            except StopIteration:
                break
    finally:
        # OpInfo.sample_inputs returns a TrackedInputIter; the @torch.no_grad generator is its child_iter
        for g in (getattr(gen, "child_iter", None), gen):
            try:
                g.close()
            except Exception:  # noqa: BLE001
                pass
        import gc
        gc.collect()  # run any remaining finalisers now, not in the middle of a later trace
    return out

SKIP = set(oes.SKIP_SUBSTR) | {"nonzero", "unique", "masked_select", "item", "tolist", "sparse", "segment_reduce", "histogram", "bucketize", "searchsorted"}
INFRA_ERRS = ("Unsupported", "UserError", "InductorError", "LoweringException", "BackendCompilerFailed", "TorchRuntimeError", "UnsupportedOperatorException", "GuardOnDataDependentSymNode", "ConstraintViolationError", "AssertionError", "CppCompileError")


class Wrap(torch.nn.Module):
    def __init__(self, fn, kwargs):
        super().__init__()
        self.fn, self.kw = fn, kwargs

    def forward(self, *args):
        return self.fn(*args, **self.kw)


def tensors_only(args):
    """export needs tensor positional inputs; non-tensor args are baked into kwargs via a closure."""
    pos, const = [], []
    for a in args:
        (pos if isinstance(a, torch.Tensor) else const).append(a)
    return pos, const


def run_paths(fn, inp, args, kwargs, work):
    """returns dict path -> (output or None, error name or None)"""
    tens, const = tensors_only([inp, *args])
    if const:
        def fn2(*t, _fn=fn, _all=[inp, *args], _kw=kwargs):
            it = iter(t)
            full = [next(it) if isinstance(a, torch.Tensor) else a for a in _all]
            return _fn(*full, **_kw)
        m, ex_args = Wrap(fn2, {}), tuple(tens)
    else:
        m, ex_args = Wrap(fn, kwargs), tuple(tens)
    out = {}
    try:
        ep = torch.export.export(m, ex_args)
    except Exception as e:  # noqa: BLE001
        return {"SL": (None, "export:" + type(e).__name__), "AO": (None, "export:" + type(e).__name__)}
    try:
        buf = io.BytesIO()
        torch.export.save(ep, buf)
        buf.seek(0)
        ep2 = torch.export.load(buf)
        out["SL"] = (ep2.module()(*ex_args), None)
    except Exception as e:  # noqa: BLE001
        out["SL"] = (None, type(e).__name__ + ": " + str(e).splitlines()[0][:200] if str(e) else type(e).__name__)
    try:
        from torch._inductor import aoti_compile_and_package, aoti_load_package
        path = aoti_compile_and_package(ep, package_path=os.path.join(work, "m.pt2"))
        runner = aoti_load_package(path)
        out["AO"] = (runner(*ex_args), None)
    except Exception as e:  # noqa: BLE001
        out["AO"] = (None, type(e).__name__ + ": " + str(e).splitlines()[0][:200] if str(e) else type(e).__name__)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dtype", default="float32")
    ap.add_argument("--only", default=None)
    ap.add_argument("--samples", type=int, default=1)
    a = ap.parse_args()
    dtype = getattr(torch, a.dtype)
    os.makedirs("results/export_roundtrip", exist_ok=True)
    out_path = f"results/export_roundtrip/{a.dtype}.jsonl"
    done = set()
    if os.path.exists(out_path):
        for line in open(out_path, encoding="utf-8"):
            try:
                done.add(json.loads(line)["op"])
            except Exception:  # noqa: BLE001
                pass
    marker = out_path + ".inprogress"
    if os.path.exists(marker) and a.only is None:  # the previous process died (hard crash) inside this op: record and skip it
        crashed = open(marker).read().strip()
        with open(out_path, "a", encoding="utf-8") as fh:
            fh.write(json.dumps({"op": crashed, "dtype": a.dtype, "samples": 0, "diffs": [{"i": 0, "path": "?", "class": "CRASH", "detail": "process died (hard crash) while running export / save-load / AOTI for this op"}], "errors": [], "verdict": "DIFF:CRASH"}) + "\n")
        done.add(crashed)
        os.remove(marker)
        print(f"previous process crashed inside {crashed}: recorded as CRASH, skipping", flush=True)
    ops = [op for op in op_db if not any(s in op.name for s in SKIP) and (a.only is None or op.name == a.only) and op.name not in done]
    print(f"torch {torch.__version__}; {len(ops)} ops to do ({len(done)} done); dtype {dtype}", flush=True)
    t_all = time.time()
    for n, op in enumerate(ops, 1):
        rec = {"op": op.name, "dtype": a.dtype, "samples": 0, "diffs": [], "errors": []}
        marker = out_path + ".inprogress"
        open(marker, "w").write(op.name)
        t0 = time.time()
        try:
            if not op.supports_dtype(dtype, "cpu"):
                rec["verdict"] = "NO_SAMPLES:dtype"
            else:
                samples = take_samples(op.sample_inputs("cpu", dtype, requires_grad=False), a.samples)
                fn = op.get_op()
                for si, s in enumerate(samples):
                    try:
                        inp, args, kwargs = oes.replace(s, dtype)
                    except Exception as e:  # noqa: BLE001
                        rec["errors"].append(f"prep {type(e).__name__}"); continue
                    if not isinstance(inp, torch.Tensor):
                        continue
                    try:
                        eager = fn(inp, *args, **kwargs); eager_err = None
                    except Exception as e:  # noqa: BLE001
                        eager, eager_err = None, type(e).__name__
                    work = tempfile.mkdtemp(prefix="tcc_rt_pkg_")
                    import gc; gc.collect()  # finalise the sample iterator (enumerate-wrapped @no_grad generator) before tracing
                    try:
                        paths = run_paths(fn, inp, args, kwargs, work)
                    finally:
                        shutil.rmtree(work, ignore_errors=True)
                    rec["samples"] += 1
                    for pname, (res, err) in paths.items():
                        if eager_err and err is None:
                            rec["diffs"].append({"i": si, "path": pname, "class": "SILENT", "detail": f"eager raises {eager_err}, {pname} returns"}); continue
                        if err:
                            if not eager_err and not any(k in err.split(":")[0] for k in INFRA_ERRS) and not err.startswith("export:"):
                                rec["diffs"].append({"i": si, "path": pname, "class": "RAISES", "detail": err})
                            else:
                                rec["errors"].append(f"{pname} {err}")
                            continue
                        if eager_err:
                            continue
                        fe, fc = [t.detach() for t in oes.flat(eager)], [t.detach() for t in oes.flat(res)]
                        if len(fe) != len(fc):
                            rec["diffs"].append({"i": si, "path": pname, "class": "STRUCT", "detail": f"{len(fe)} vs {len(fc)} tensors"}); continue
                        for e, c in zip(fe, fc):
                            d = oes.diff(e, c)
                            if d:
                                rec["diffs"].append({"i": si, "path": pname, "class": "SIGNZERO" if d == "sign of zero" else "VALUE", "detail": d, "repr": repr(s)[:200]}); break
                            if e.stride() != c.stride() and e.numel() > 1:
                                rec["diffs"].append({"i": si, "path": pname, "class": "STRIDE", "detail": f"{e.stride()} vs {c.stride()}"}); break
                classes = sorted({d["class"] for d in rec["diffs"]})
                rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
        except Exception as e:  # noqa: BLE001
            rec["verdict"] = "ERROR:" + type(e).__name__
        with open(out_path, "a", encoding="utf-8") as fh:
            fh.write(json.dumps(rec) + "\n")
        if os.path.exists(marker):
            os.remove(marker)
        if rec["diffs"] or n % 25 == 0:
            print(f"[{n}/{len(ops)}] {op.name}: {rec['verdict']} ({time.time() - t0:.0f}s, total {time.time() - t_all:.0f}s)" + (f"  {rec['diffs'][0]}" if rec["diffs"] else ""), flush=True)
    print("SWEEP DONE", flush=True)


if __name__ == "__main__":
    main()
