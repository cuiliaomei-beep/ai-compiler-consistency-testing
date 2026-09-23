"""Independent confirmation of decomposition-sweep hits.

usage: python scripts/confirm_decomp2.py OP VARIANT [--dtype float32] [--backend inductor]

Runs every OpInfo sample of OP through the VARIANT transformation used by the sweep,
compares eager with torch.compile, and prints the first differing samples verbosely
(inputs, kwargs, eager result / exception, compiled result / exception).
"""
import argparse
import os
import sys
import traceback

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)

import torch  # noqa: E402
from tcc.decomp_diff import _variants, _clone, _clones, _run, _fp64  # noqa: E402
from tcc.oracle import Config, compare  # noqa: E402
from tcc.observe import is_tensor  # noqa: E402
from tcc.compat import compile_fn, dynamo_reset, ensure_msvc_env  # noqa: E402

ensure_msvc_env()


def brief(x):
    if is_tensor(x):
        s = f"tensor{tuple(x.shape)} {x.dtype}"
        if x.numel() <= 12:
            s += f" {x.tolist()}"
        elif x.is_floating_point():
            s += f" min={x.min().item():.4g} max={x.max().item():.4g}"
        return s
    if isinstance(x, (tuple, list)):
        return type(x).__name__ + "(" + ", ".join(brief(a) for a in x) + ")"
    return repr(x)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("op")
    ap.add_argument("variant")
    ap.add_argument("--dtype", default="float32")
    ap.add_argument("--backend", default="inductor")
    ap.add_argument("--max", type=int, default=3)
    a = ap.parse_args()
    from torch.testing._internal.common_methods_invocations import op_db
    dt = getattr(torch, a.dtype)
    ops = [o for o in op_db if o.name == a.op]
    if not ops:
        print("no such op")
        return 1
    cfg = Config()
    shown = 0
    for op in ops:
        for s in op.sample_inputs("cpu", dt, requires_grad=False):
            if not is_tensor(s.input):
                continue
            args0 = (s.input,) + tuple(s.args)
            kw = dict(s.kwargs)
            try:
                variants = dict(_variants(args0))
            except Exception:
                continue
            if a.variant not in variants:
                continue
            args = variants[a.variant]

            def fn(*x, _op=op.op, _kw=kw):
                return _op(*x, **_kw)
            real = _run(fn, _clones(args, {})[0], "eager")
            ref64 = _fp64(fn, args) if real.ok else None
            dynamo_reset()
            try:
                cf = compile_fn(fn, a.backend)
                got = _run(cf, _clones(args, {})[0], f"compiled[{a.backend}]")
            finally:
                dynamo_reset()
            c = compare(real, got, ref64, cfg, ["value", "metadata", "exception"])
            if not c.differs:
                continue
            shown += 1
            print("=" * 78)
            print(f"{a.op} [{a.variant}] sample: args={brief(args)} kwargs={kw}")
            print(f"  eager   : ok={real.ok} exc={real.exception} {(real.exception_msg or '')[:160]}")
            if real.ok:
                print(f"            out={brief(real.outputs)}")
            print(f"  compiled: ok={got.ok} exc={got.exception_inner or got.exception} {(got.exception_msg or '')[:160]}")
            if got.ok:
                print(f"            out={brief(got.outputs)}")
            if ref64 is not None and ref64.ok:
                print(f"  fp64    : out={brief(ref64.outputs)}")
            for f in c.findings[:3]:
                print(f"  finding : [{f.kind}] {f.detail[:200]}")
            if shown >= a.max:
                return 0
    print(f"{shown} differing sample(s)")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except SystemExit:
        raise
    except Exception:
        traceback.print_exc()
