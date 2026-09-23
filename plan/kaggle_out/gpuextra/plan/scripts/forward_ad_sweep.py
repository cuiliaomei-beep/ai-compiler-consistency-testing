"""6.4d: forward-mode AD (torch.func.jvp) through a compiled operator vs eager, for OpInfo ops with
supports_forward_ad. Compare primal output and tangent with float64 eager truth.

    python scripts/forward_ad_sweep.py [--only ...] [--backend aot_eager] [--out results/forward_ad]
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

torch._dynamo.config.recompile_limit = 10 ** 4
torch._dynamo.config.accumulated_recompile_limit = 10 ** 6


def jvp_of(fn, sample, dtype):
    def cast(t):
        if isinstance(t, torch.Tensor) and (t.is_floating_point() or t.is_complex()):
            return t.detach().to(dtype)
        return t
    inp, args = cast(sample.input), [cast(a) for a in sample.args]
    kwargs = {k: cast(v) for k, v in sample.kwargs.items()}
    if not (isinstance(inp, torch.Tensor) and (inp.is_floating_point() or inp.is_complex())):
        return None
    g = torch.Generator().manual_seed(1)
    tangent = (torch.complex(torch.randn(inp.shape, generator=g), torch.randn(inp.shape, generator=g)) if dtype.is_complex else torch.randn(inp.shape, generator=g)).to(dtype)

    def f(x):
        out = fn(x, *args, **kwargs)
        outs = out if isinstance(out, (tuple, list)) else [out]
        return tuple(o for o in outs if isinstance(o, torch.Tensor) and (o.is_floating_point() or o.is_complex()))

    if getattr(fn, "_tcc_compile_backend", None):
        # torch.compile does not engage inside a functorch transform; compile the jvp wrapper instead
        run = torch.compile(lambda x, t: torch.func.jvp(f, (x,), (t,)), backend=fn._tcc_compile_backend)
        primal, tan = run(inp, tangent)
    else:
        primal, tan = torch.func.jvp(f, (inp,), (tangent,))
    return [p.detach() for p in primal], [t.detach() for t in tan]


def maxerr(xs, truth):
    worst, scale = 0.0, 1e-30
    for x, t in zip(xs, truth):
        if x.shape != t.shape or t.numel() == 0:
            continue
        fin = torch.isfinite(t)
        if not torch.equal(torch.isfinite(x), fin):
            return float("inf"), 1.0
        if fin.any():
            worst = max(worst, (x.to(t.dtype) - t)[fin].abs().max().item())
            scale = max(scale, t[fin].abs().max().item())
    return worst, scale


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--only", default=None)
    ap.add_argument("--backend", default="aot_eager")
    ap.add_argument("--dtype", default="float32", choices=["float32", "complex64"])
    ap.add_argument("--skip", default="", help="comma-separated op names to skip (native crashers)")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--out", default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "results", "forward_ad"))
    a = ap.parse_args()
    os.makedirs(a.out, exist_ok=True)
    only = set(a.only.split(",")) if a.only else None
    DT = getattr(torch, a.dtype); DT_HI = torch.complex128 if DT.is_complex else torch.float64
    skip = set(a.skip.split(",")) if a.skip else set()
    ops = [o for o in op_db if o.supports_forward_ad and DT in o.dtypes and (not only or o.name in only) and o.name not in skip]
    print(f"torch {torch.__version__} | {len(ops)} ops with forward AD ({a.dtype}) | backend {a.backend}")
    rows, flagged, t0 = [], [], time.time()
    for i, oi in enumerate(ops):
        if a.verbose:
            print(f"  > {oi.name}", flush=True)
        try:
            s = next(iter(oi.sample_inputs("cpu", DT, requires_grad=False)))
        except Exception:
            continue
        fn = oi.get_op()
        try:
            truth = jvp_of(fn, s, DT_HI)
            eag = jvp_of(fn, s, DT)
            if truth is None or eag is None:
                continue
            torch._dynamo.reset()
            marked = (lambda *args, **kw: fn(*args, **kw))
            marked._tcc_compile_backend = a.backend
            comp = jvp_of(marked, s, DT)
        except Exception as e:  # noqa: BLE001
            msg = f"{type(e).__name__}: {str(e).splitlines()[0][:120]}"
            rows.append({"op": oi.name, "error": msg})
            try:
                jvp_of(fn, s, DT)
                flagged.append({"op": oi.name, "error": msg}); print(f"  FLAG {oi.name:<34} compiled raised: {msg}", flush=True)
            except Exception:
                pass
            continue
        ep, sp = maxerr(eag[0], truth[0]); cp, _ = maxerr(comp[0], truth[0])
        et, st = maxerr(eag[1], truth[1]); ct, _ = maxerr(comp[1], truth[1])
        rec = {"op": oi.name, "primal_err": (ep, cp, sp), "tangent_err": (et, ct, st)}
        rec["flag"] = cp > max(4 * ep, 1e-4 * max(sp, 1.0)) or ct > max(4 * et, 1e-4 * max(st, 1.0)) or len(comp[1]) != len(truth[1])
        rows.append(rec)
        if rec["flag"]:
            flagged.append(rec)
            print(f"  FLAG {oi.name:<34} primal {ep:.1e}/{cp:.1e}  tangent {et:.1e}/{ct:.1e} (scale {st:.1e})", flush=True)
        if i % 50 == 49:
            print(f"  ... {i + 1}/{len(ops)} ({time.time() - t0:.0f}s, {len(flagged)} flagged)", flush=True)
    json.dump(rows, open(os.path.join(a.out, "forward_ad.json"), "w"), indent=1, default=str)
    lines = [f"# forward-mode AD through compiled ops ({a.backend}, torch {torch.__version__})", "", f"- ops: {len(ops)}, rows: {len(rows)}, flagged: {len(flagged)}; wall {time.time() - t0:.0f} s", "", "| op | finding |", "|---|---|"]
    for r in flagged:
        lines.append(f"| {r['op']} | {r.get('error') or f'primal {r['primal_err'][0]:.1e}/{r['primal_err'][1]:.1e}, tangent {r['tangent_err'][0]:.1e}/{r['tangent_err'][1]:.1e}'} |")
    open(os.path.join(a.out, "FORWARD_AD.md"), "w", encoding="utf-8").write("\n".join(lines) + "\n")
    print(json.dumps({"ops": len(ops), "flagged": len(flagged), "wall_s": round(time.time() - t0, 1)}))


if __name__ == "__main__":
    main()
