"""Full (innermost) tracebacks for the two max_autotune CPU failures."""
import os
import sys
import traceback

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch._inductor import config as IC  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)


def run(label, fn, *args):
    torch._dynamo.reset()
    try:
        with IC.patch({"max_autotune": True, "max_autotune_gemm": True}):
            torch.compile(fn)(*args)
        print(f"[{label}] ok")
    except Exception as ex:  # noqa: BLE001
        inner = ex
        while inner.__cause__ is not None:
            inner = inner.__cause__
        print(f"[{label}] {type(inner).__name__}: {str(inner)[:120]}")
        tb = traceback.format_tb(inner.__traceback__)
        for ln in "".join(tb[-6:]).splitlines():
            if "site-packages" in ln or ln.strip().startswith(("raise", "return", "self.", "return")):
                print("   ", ln.strip()[:170])


run("addmm scalar bias", lambda b, x, y: torch.addmm(b, x, y), torch.tensor(0.5), torch.randn(2, 2), torch.randn(2, 3))
run("bmm", lambda x, y: torch.bmm(x, y), torch.randn(4, 8, 8), torch.randn(4, 8, 8))
