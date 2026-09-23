"""AOTI sweep follow-ups: (a) ops returning torch.return_types cannot be packaged; (b) instance_norm internal assert."""
import os
import sys
import tempfile
import traceback

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402
from torch.export import export  # noqa: E402
from torch._inductor import aoti_compile_and_package, aoti_load_package  # noqa: E402

print(torch.__version__)
work = tempfile.mkdtemp(prefix="tcc_aoti_diag_")


def run(label, mod, args):
    print(f"[{label}]")
    try:
        e = mod(*args)
        print("   eager    : ok", type(e).__name__)
    except Exception as ex:  # noqa: BLE001
        print("   eager    :", type(ex).__name__, str(ex)[:120])
        return
    try:
        ep = export(mod, args)
        out = ep.module()(*args)
        print("   export   : ok", type(out).__name__)
    except Exception as ex:  # noqa: BLE001
        print("   export   :", type(ex).__name__, str(ex)[:200].replace("\n", " "))
        return
    try:
        torch._dynamo.reset()
        c = torch.compile(mod)(*args)
        print("   compile  : ok", type(c).__name__)
    except Exception as ex:  # noqa: BLE001
        print("   compile  :", type(ex).__name__, str(ex)[:120])
    try:
        path = aoti_compile_and_package(ep, package_path=os.path.join(work, label.replace(" ", "_") + ".pt2"))
        r = aoti_load_package(path)
        out = r(*args)
        print("   aoti     : ok", type(out).__name__, [tuple(t.shape) for t in (out if isinstance(out, (tuple, list)) else [out])])
    except Exception as ex:  # noqa: BLE001
        msg = str(ex).replace("\n", " ")
        print("   aoti     :", type(ex).__name__, msg[:260])


class MaxDim(torch.nn.Module):
    def forward(self, x):
        return torch.max(x, dim=0)


class MaxDimUnpacked(torch.nn.Module):
    def forward(self, x):
        v, i = torch.max(x, dim=0)
        return v, i


class TopK(torch.nn.Module):
    def forward(self, x):
        return torch.topk(x, 2)


class InstNorm(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.register_buffer("rm", torch.zeros(3))
        self.register_buffer("rv", torch.ones(3))

    def forward(self, x):
        return F.instance_norm(x, self.rm, self.rv, use_input_stats=True)


class InstNormNoStats(torch.nn.Module):
    def forward(self, x):
        return F.instance_norm(x)


class InstNormFn(torch.nn.Module):
    def forward(self, x, rm, rv):
        return F.instance_norm(x, rm, rv, use_input_stats=True)


x = torch.randn(4, 5)
run("max dim (return_types)", MaxDim(), (x,))
run("max dim unpacked tuple", MaxDimUnpacked(), (x,))
run("topk (return_types)", TopK(), (x,))
x4 = torch.randn(2, 3, 4, 4)
run("instance_norm with running stats (buffers)", InstNorm(), (x4,))
run("instance_norm with running stats (inputs)", InstNormFn(), (x4, torch.zeros(3), torch.ones(3)))
run("instance_norm no stats", InstNormNoStats(), (x4,))
