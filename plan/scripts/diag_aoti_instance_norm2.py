"""Minimal: F.instance_norm with running stats captured as module-level tensors (not buffers) -> export ok,
run_decompositions / aoti_compile_and_package INTERNAL ASSERT (functionalization: mutating a non-functional tensor)."""
import os
import sys
import tempfile

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
import torch.nn.functional as F  # noqa: E402
from torch.export import export  # noqa: E402
from torch._inductor import aoti_compile_and_package  # noqa: E402

print(torch.__version__)
RM = torch.zeros(3)
RV = torch.ones(3)


class M(torch.nn.Module):
    def forward(self, x):
        return F.instance_norm(x, RM, RV, use_input_stats=True)   # updates RM / RV in place (momentum 0.1)


class MBuf(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.register_buffer("rm", torch.zeros(3))
        self.register_buffer("rv", torch.ones(3))

    def forward(self, x):
        return F.instance_norm(x, self.rm, self.rv, use_input_stats=True)


class MBatchNorm(torch.nn.Module):
    def forward(self, x):
        return F.batch_norm(x, RM, RV, training=True)          # same pattern with batch_norm


def step(label, fn):
    try:
        r = fn()
        print(f"   {label:<22}: ok")
        return r
    except Exception as e:  # noqa: BLE001
        print(f"   {label:<22}: {type(e).__name__}: {str(e)[:150].replace(chr(10), ' ')}")
        return None


x = torch.randn(2, 3, 4, 4)
work = tempfile.mkdtemp(prefix="tcc_in2_")
for name, mod in (("captured global tensors", M()), ("registered buffers", MBuf()), ("batch_norm captured", MBatchNorm())):
    print(f"[{name}]")
    step("eager", lambda: mod(x))
    torch._dynamo.reset()
    step("torch.compile", lambda: torch.compile(mod)(x))
    ep = step("export", lambda: export(mod, (x,)))
    if ep is None:
        continue
    step("ep.module()(x)", lambda: ep.module()(x))
    step("run_decompositions", lambda: ep.run_decompositions())
    step("aoti_compile_and_package", lambda: aoti_compile_and_package(ep, package_path=os.path.join(work, name[:6] + ".pt2")))
    print("   RM after eager runs:", RM.tolist()[:3] if name != "registered buffers" else "n/a")
