"""max_autotune: linalg.matrix_power on an empty batch (0, 2, 2) -> which error?"""
import os
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch._inductor import config as IC  # noqa: E402

print(torch.__version__)


def run(label, fn, *args):
    torch._dynamo.reset()
    try:
        e = fn(*args)
        with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
            c = torch.compile(fn)(*args)
        print(f"[{label}] ok shape={tuple(c.shape)} same={torch.equal(c, e)}")
    except Exception as ex:  # noqa: BLE001
        inner = ex
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"[{label}] {type(inner).__name__}: {str(inner)[:150]}")


for n in (0, 1, 2, 3, -1):
    run(f"matrix_power n={n} on (0,2,2)", lambda x, _n=n: torch.linalg.matrix_power(x, _n), torch.empty(0, 2, 2))
run("matrix_power n=2 on (3,2,2)", lambda x: torch.linalg.matrix_power(x, 2), torch.randn(3, 2, 2))
run("bmm empty batch (0,2,2)@(0,2,2)", lambda a, b: torch.bmm(a, b), torch.empty(0, 2, 2), torch.empty(0, 2, 2))
run("mm (0,2)@(2,3)", lambda a, b: torch.mm(a, b), torch.empty(0, 2), torch.randn(2, 3))
run("mm (2,0)@(0,3)", lambda a, b: torch.mm(a, b), torch.empty(2, 0), torch.empty(0, 3))
run("matmul (0,2,2)@(0,2,2)", lambda a, b: a @ b, torch.empty(0, 2, 2), torch.empty(0, 2, 2))
