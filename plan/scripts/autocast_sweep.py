"""8.11  autocast over every OpInfo op: under torch.autocast("cpu", dtype=bfloat16) (and float16), eager vs
torch.compile on float32 samples.  Compared: output dtype (autocast's cast policy must be the same on both sides),
values (loose tolerance, half precision), NaN/inf pattern, exception parity.  6.2b covered unary ops only.
Resumable: one JSON line per op; rerun to continue.
    python scripts/autocast_sweep.py [--acdtype bfloat16|float16] [--only op] -> results/autocast/<acdtype>.jsonl
"""
import argparse
import itertools
import json
import os
import sys
import tempfile
import time

os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_ac_"))
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

import opinfo_edge_sweep as oes  # noqa: E402


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

INFRA_ERRS = ("BackendCompilerFailed", "Unsupported", "InductorError", "LoweringException", "TorchRuntimeError")


def vdiff(e, c):
    if e.shape != c.shape or e.dtype != c.dtype:
        return "DTYPE", f"{tuple(e.shape)} {e.dtype} vs {tuple(c.shape)} {c.dtype}"
    if e.numel() == 0 or not (e.dtype.is_floating_point or e.is_complex()):
        return (None, None) if (e.numel() == 0 or torch.equal(e, c)) else ("VALUE", "int/bool mismatch")
    if e.is_complex():
        e, c = torch.view_as_real(e.resolve_conj()), torch.view_as_real(c.resolve_conj())
    e64, c64 = e.double(), c.double()
    if not torch.equal(e64.isnan(), c64.isnan()):
        return "NAN", "nan pattern differs"
    m = ~e64.isnan()
    if not torch.equal(e64[m].isinf(), c64[m].isinf()):
        return "INF", "inf pattern differs"
    fin = m & ~e64.isinf()
    a, b = e64[fin], c64[fin]
    rel = (a - b).abs() / (a.abs() + b.abs()).clamp(min=1.0)
    if rel.numel() and rel.max().item() > 3e-2:
        k = rel.argmax().item()
        return "VALUE", f"rel {rel.max().item():.3g}: eager {a[k].item()!r} compiled {b[k].item()!r}"
    return None, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--acdtype", default="bfloat16")
    ap.add_argument("--only", default=None)
    ap.add_argument("--samples", type=int, default=2)
    a = ap.parse_args()
    acdt = getattr(torch, a.acdtype)
    os.makedirs("results/autocast", exist_ok=True)
    out_path = f"results/autocast/{a.acdtype}.jsonl"
    done = set()
    if os.path.exists(out_path):
        for line in open(out_path, encoding="utf-8"):
            try:
                done.add(json.loads(line)["op"])
            except Exception:  # noqa: BLE001
                pass
    ops = [op for op in op_db if not any(s in op.name for s in oes.SKIP_SUBSTR) and (a.only is None or op.name == a.only) and op.name not in done]
    print(f"torch {torch.__version__}; {len(ops)} ops to do ({len(done)} done); autocast {acdt}", flush=True)
    t_all = time.time()
    for n, op in enumerate(ops, 1):
        rec = {"op": op.name, "acdtype": a.acdtype, "samples": 0, "diffs": [], "errors": []}
        t0 = time.time()
        try:
            if not op.supports_dtype(torch.float32, "cpu"):
                rec["verdict"] = "NO_SAMPLES:dtype"
            else:
                samples = take_samples(op.sample_inputs("cpu", torch.float32, requires_grad=False), a.samples)
                fn = op.get_op()
                for si, s in enumerate(samples):
                    inp, args, kwargs = s.input, s.args, s.kwargs
                    with torch.autocast("cpu", dtype=acdt):
                        try:
                            eager = fn(inp, *args, **kwargs); eager_err = None
                        except Exception as e:  # noqa: BLE001
                            eager, eager_err = None, type(e).__name__
                    torch._dynamo.reset()
                    import gc; gc.collect()
                    with torch.autocast("cpu", dtype=acdt):
                        try:
                            comp = torch.compile(fn)(inp, *args, **kwargs); comp_err = None
                        except Exception as e:  # noqa: BLE001
                            comp, comp_err = None, type(e).__name__
                    rec["samples"] += 1
                    if eager_err or comp_err:
                        if eager_err and not comp_err:
                            rec["diffs"].append({"i": si, "class": "SILENT", "detail": f"eager raises {eager_err}, compiled returns"})
                        elif comp_err and not eager_err and comp_err not in INFRA_ERRS:
                            rec["diffs"].append({"i": si, "class": "RAISES", "detail": comp_err})
                        elif comp_err:
                            rec["errors"].append(comp_err)
                        continue
                    fe, fc = [t.detach() for t in oes.flat(eager)], [t.detach() for t in oes.flat(comp)]
                    if len(fe) != len(fc):
                        rec["diffs"].append({"i": si, "class": "STRUCT", "detail": f"{len(fe)} vs {len(fc)}"}); continue
                    for e, c in zip(fe, fc):
                        cls, d = vdiff(e, c)
                        if cls:
                            rec["diffs"].append({"i": si, "class": cls, "detail": d, "repr": repr(s)[:200]}); break
                classes = sorted({d["class"] for d in rec["diffs"]})
                rec["verdict"] = "ok" if not classes else "DIFF:" + "+".join(classes)
        except Exception as e:  # noqa: BLE001
            rec["verdict"] = "ERROR:" + type(e).__name__
        with open(out_path, "a", encoding="utf-8") as fh:
            fh.write(json.dumps(rec) + "\n")
        if rec["diffs"] or n % 50 == 0:
            print(f"[{n}/{len(ops)}] {op.name}: {rec['verdict']} ({time.time() - t0:.0f}s, total {time.time() - t_all:.0f}s)" + (f"  {rec['diffs'][0]}" if rec["diffs"] else ""), flush=True)
    print("SWEEP DONE", flush=True)


if __name__ == "__main__":
    main()
