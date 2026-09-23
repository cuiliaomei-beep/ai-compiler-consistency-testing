"""Print the full exception a decomposition raises under DecompMode for the forward of OP (first sample)."""
import os
import sys
import traceback

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
import torch  # noqa: E402
from tcc.decomp_diff import DecompMode  # noqa: E402

op_name = sys.argv[1] if len(sys.argv) > 1 else "nn.functional.softsign"
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

op = [o for o in op_db if o.name == op_name][0]
s = next(iter(op.sample_inputs("cpu", torch.float32, requires_grad=False)))
args = (s.input,) + tuple(s.args)
print("eager:", type(op.op(*args, **s.kwargs)))
dm = DecompMode()
try:
    out = dm.run(lambda *a: op.op(*a, **s.kwargs), *args)
    print("decomp ok:", type(out))
except Exception:
    traceback.print_exc()
print("hits:", dm.hits[:12])
