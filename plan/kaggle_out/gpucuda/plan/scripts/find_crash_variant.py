"""Which input variant of OP kills the interpreter (native abort)? Each variant runs in its own subprocess.

usage: python scripts/find_crash_variant.py OP [--grad] [--decomp]
"""
import subprocess
import sys

HERE = __import__("os").path.dirname(__import__("os").path.dirname(__import__("os").path.abspath(__file__)))
op_name = sys.argv[1]
grad = "--grad" in sys.argv
decomp = "--decomp" in sys.argv

CHILD = r'''
import sys, torch
sys.path.insert(0, %r)
from tcc.decomp_diff import _variants, with_grad, DecompMode, _clones
from torch.testing._internal.common_methods_invocations import op_db
op = [o for o in op_db if o.name == %r][0]
vn, grad, decomp = sys.argv[1], %r, %r
for i, s in enumerate(op.sample_inputs('cpu', torch.float32, requires_grad=False)):
    v = dict(_variants((s.input,) + tuple(s.args)))
    if vn not in v:
        continue
    a = v[vn]
    fn = (lambda *x, _f=op.op, _k=dict(s.kwargs): _f(*x, **_k))
    if grad:
        fn = with_grad(fn)
    print('sample', i, [tuple(t.shape) if isinstance(t, torch.Tensor) else t for t in a], s.kwargs, flush=True)
    try:
        if decomp:
            DecompMode().run(fn, *_clones(a, {})[0])
        else:
            fn(*_clones(a, {})[0])
        print('  ok', flush=True)
    except Exception as e:
        print('  ', type(e).__name__, str(e)[:80], flush=True)
print('done', flush=True)
''' % (HERE, op_name, grad, decomp)

VARIANTS = ["base", "empty_dim0", "size1_dim0", "empty_last", "size1_last", "prime_dim0", "noncontig", "prime_all",
            "zero_dim", "channels_last", "dtype_int64", "dtype_bool", "nan_inf", "huge", "tiny", "dtype_float16",
            "dtype_bfloat16"]
for vn in VARIANTS:
    r = subprocess.run([sys.executable, "-c", CHILD, vn], capture_output=True, text=True, encoding="utf-8",
                       errors="replace")
    tail = r.stdout.strip().splitlines()[-2:] if r.stdout.strip() else []
    flag = "" if r.returncode == 0 else f"  <-- rc {r.returncode} ({r.returncode & 0xFFFFFFFF:#x})"
    print(f"{vn:<15} " + " | ".join(t.strip() for t in tail) + flag)
