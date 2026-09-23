"""Run every OpInfo sample of OP under torch.compile(dynamic=True) and print the failing ones.

usage: python scripts/confirm_dynamic.py OP [--backend inductor]
"""
import argparse
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402


def short(v):
    if isinstance(v, torch.Tensor):
        return f"tensor{tuple(v.shape)}" + (f" {v.tolist()}" if v.numel() <= 12 else "")
    return repr(v)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("op")
    ap.add_argument("--backend", default="inductor")
    ap.add_argument("--dtype", default="float32")
    a = ap.parse_args()
    from torch.testing._internal.common_methods_invocations import op_db
    ops = [o for o in op_db if o.name == a.op]
    print(torch.__version__, "entries", len(ops))
    n_fail = n = 0
    for op in ops:
        for s in op.sample_inputs("cpu", getattr(torch, a.dtype), requires_grad=False):
            args = (s.input,) + tuple(s.args)
            kw = dict(s.kwargs)

            def f(*x, _op=op.op, _kw=kw):
                return _op(*x, **_kw)
            try:
                e = f(*args)
            except Exception as ex:  # noqa: BLE001
                print("EAGER FAIL", tuple(s.input.shape), type(ex).__name__)
                continue
            n += 1
            torch._dynamo.reset()
            try:
                c = torch.compile(f, dynamic=True, backend=a.backend)(*args)
                ok = isinstance(c, torch.Tensor) and c.shape == e.shape and torch.equal(c, e)
                r = "ok" if ok else f"DIFF {getattr(c, 'shape', None)} vs {e.shape}"
            except Exception as ex:  # noqa: BLE001
                inner = ex
                while inner.__cause__ is not None:
                    inner = inner.__cause__
                r = f"{type(inner).__name__}: {str(inner)[:500]}"
            if r != "ok":
                n_fail += 1
                print(f"FAIL input={short(s.input)} args={[short(x) for x in s.args]} "
                      f"kwargs={{{', '.join(f'{k}={short(v)}' for k, v in kw.items())}}}")
                print("   ", r)
    print(f"done: {n_fail}/{n} samples fail under dynamic=True")


if __name__ == "__main__":
    main()
