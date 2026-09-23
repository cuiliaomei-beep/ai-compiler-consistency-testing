"""Print the full exception a decomposition raises under DecompMode for a forward+backward of OP."""
import os
import sys
import traceback

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
import torch  # noqa: E402
from tcc.decomp_diff import DecompMode, with_grad  # noqa: E402

op_name = sys.argv[1] if len(sys.argv) > 1 else "std"
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

op = [o for o in op_db if o.name == op_name][0]
s = next(iter(op.sample_inputs("cpu", torch.float32, requires_grad=False)))
kw = dict(s.kwargs)
fn = with_grad(lambda *a, _f=op.op, _kw=kw: _f(*a, **_kw))
args = (s.input,) + tuple(s.args)
print("eager:", [tuple(t.shape) if isinstance(t, torch.Tensor) else t for t in fn(*args)])
dm = DecompMode()
try:
    out = dm.run(fn, *args)
    print("decomp:", [tuple(t.shape) if isinstance(t, torch.Tensor) else t for t in out])
except Exception:
    traceback.print_exc()
print("hits:", dm.hits[:12])
