"""(generalised copy: any dtypes via --dtypes)  Every OpInfo op that supports the given dtypes: run the sample inputs plainly and under a no-op TorchDispatchMode,
compare.  Motivation: aten.linalg_polar returns a wrong Hermitian factor (imaginary parts of the off-diagonal dropped)
as soon as any TorchDispatchMode is active, and torch.compile's runtime wrapper runs every graph under one
(_AnalyzeCustomOpInputOutputMode), so this is the family behind the linalg.polar difference seen by
scripts/opinfo_edge_sweep.py.  Pure eager: no compiler needed.

    python scripts/dispatch_mode_complex_sweep.py [--dtypes complex64,complex128] [--only linalg.polar]
"""
import argparse
import itertools
import json
import os

import torch
from torch.testing._internal.common_methods_invocations import op_db
from torch.utils._python_dispatch import TorchDispatchMode


class Noop(TorchDispatchMode):
    def __torch_dispatch__(self, func, types, args=(), kwargs=None):
        return func(*args, **(kwargs or {}))


def flat(o):
    if isinstance(o, torch.Tensor):
        return [o]
    if isinstance(o, (list, tuple)) or hasattr(o, "_fields"):
        return [t for x in tuple(o) for t in flat(x)]
    if isinstance(o, dict):
        return [t for x in o.values() for t in flat(x)]
    return []


def diff(e, c):
    if e.shape != c.shape or e.dtype != c.dtype:
        return f"shape/dtype {tuple(e.shape)} {e.dtype} vs {tuple(c.shape)} {c.dtype}"
    if e.numel() == 0:
        return None
    e, c = e.detach(), c.detach()
    if e.is_complex():
        e, c = torch.view_as_real(e.resolve_conj()), torch.view_as_real(c.resolve_conj())
    if not e.dtype.is_floating_point:
        return None if torch.equal(e, c) else "value (exact dtype)"
    e64, c64 = e.double(), c.double()
    if not torch.equal(e64.isnan(), c64.isnan()):
        return "nan pattern"
    m = ~e64.isnan()
    d = (e64[m] - c64[m]).abs().max().item() if m.any() else 0.0
    scale = max(1.0, e64[m].abs().max().item()) if m.any() else 1.0
    return f"max abs diff {d:.3g}" if d > 1e-4 * scale else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dtypes", default="float32,float64,complex64,int64,bool,float16,bfloat16")
    ap.add_argument("--only", default=None)
    ap.add_argument("--max-samples", type=int, default=6)
    ap.add_argument("--out", default="results/pairs/dispatch_mode_all.jsonl")
    a = ap.parse_args()
    os.makedirs(os.path.dirname(a.out), exist_ok=True)
    dtypes = [getattr(torch, d) for d in a.dtypes.split(",")]
    SKIP = ('empty', 'rand', 'normal', 'bernoulli', 'multinomial', 'dropout', 'rrelu', 'uniform', 'exponential', 'geometric', 'cauchy', 'log_normal', 'poisson', 'new_empty', 'resize', 'unique', 'nonzero', 'signal.windows')
    ops = [op for op in op_db if (a.only is None or op.name == a.only) and not any(k in op.name for k in SKIP)]
    torch.manual_seed(0)
    n_pairs = n_diff = 0
    with open(a.out, "w", encoding="utf-8") as f:
        for op in ops:
            for dt in dtypes:
                if not op.supports_dtype(dt, "cpu"):
                    continue
                try:
                    samples = list(itertools.islice(op.sample_inputs("cpu", dt, requires_grad=False), a.max_samples))
                except Exception:  # noqa: BLE001
                    continue
                fn = op.get_op()
                findings = []
                for si, s in enumerate(samples):
                    try:
                        plain = fn(s.input, *s.args, **s.kwargs)
                    except Exception:  # noqa: BLE001
                        continue
                    try:
                        with Noop():
                            under = fn(s.input, *s.args, **s.kwargs)
                    except Exception as e:  # noqa: BLE001
                        findings.append({"i": si, "detail": f"raises under mode: {type(e).__name__}"}); continue
                    fp, fu = flat(plain), flat(under)
                    if len(fp) != len(fu):
                        findings.append({"i": si, "detail": "structure"}); continue
                    for e, c in zip(fp, fu):
                        d = diff(e, c)
                        if d:
                            findings.append({"i": si, "detail": d, "sample": repr(s)[:200]}); break
                n_pairs += 1
                rec = {"op": op.name, "dtype": str(dt).split(".")[-1], "samples": len(samples), "findings": findings}
                f.write(json.dumps(rec) + "\n")
                if findings:
                    n_diff += 1
                    print(f"!! {op.name:36s} {rec['dtype']:10s} {findings[0]['detail']}   ({len(findings)}/{len(samples)} samples)", flush=True)
    print(f"{n_pairs} (op, dtype) pairs, {n_diff} differ under a no-op TorchDispatchMode")


if __name__ == "__main__":
    main()
