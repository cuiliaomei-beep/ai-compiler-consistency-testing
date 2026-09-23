"""Which OpInfo instance_norm sample trips the functionalization INTERNAL ASSERT under export + AOTI?"""
import os
import sys
import tempfile

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.export import export  # noqa: E402
from torch._inductor import aoti_compile_and_package  # noqa: E402
from torch.testing._internal.common_methods_invocations import op_db  # noqa: E402

op = [o for o in op_db if o.name == "nn.functional.instance_norm"][0]
work = tempfile.mkdtemp(prefix="tcc_in_")
print(torch.__version__)


def short(v):
    return f"tensor{tuple(v.shape)}" if isinstance(v, torch.Tensor) else repr(v)


for i, s in enumerate(op.sample_inputs("cpu", torch.float32, requires_grad=False)):
    kw = dict(s.kwargs)
    args = (s.input,) + tuple(s.args)

    class M(torch.nn.Module):
        def forward(self, *a):
            return op.op(*a, **kw)
    desc = f"input{tuple(s.input.shape)} kwargs={{{', '.join(f'{k}={short(v)}' for k, v in kw.items())}}}"
    try:
        ep = export(M(), args)
    except Exception as e:  # noqa: BLE001
        print(f"[{i}] export FAIL {type(e).__name__}: {str(e)[:100]} | {desc}")
        continue
    try:
        aoti_compile_and_package(ep, package_path=os.path.join(work, f"m{i}.pt2"))
        print(f"[{i}] ok | {desc}")
    except Exception as e:  # noqa: BLE001
        print(f"[{i}] AOTI FAIL {type(e).__name__}: {str(e)[:160].replace(chr(10), ' ')} | {desc}")
