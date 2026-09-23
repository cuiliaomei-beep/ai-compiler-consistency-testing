"""max_autotune on CPU: which GEMM shapes fail to compile, and with what error."""
import os
import re
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch._inductor import config as IC  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)


def run(label, fn, *args, patch=None):
    patch = patch if patch is not None else {"max_autotune": True, "max_autotune_gemm": True}
    torch._dynamo.reset()
    try:
        e = fn(*args)
        with IC.patch(patch):
            c = torch.compile(fn)(*args)
        err = (c.double() - e.double()).abs().max().item()
        print(f"[{label}] ok max|diff|={err:.3g}")
    except Exception as ex:  # noqa: BLE001
        inner = ex
        while inner.__cause__ is not None:
            inner = inner.__cause__
        msg = str(inner)
        m = re.search(r"error C\d+:[^\n]*|error:[^\n]*", msg)
        first = msg.strip().splitlines()[0] if msg.strip() else ""
        print(f"[{label}] {type(inner).__name__}: {(m.group(0) if m else first)[:200].encode('ascii', 'replace').decode()}")
        m2 = re.search(r"([A-Za-z]:[^\s(]+\.cpp)\((\d+)\)", msg)
        if m2:
            path, line = m2.group(1), int(m2.group(2))
            try:
                lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
                for i in range(max(0, line - 3), min(len(lines), line + 1)):
                    print(f"      {i + 1:4d}| {lines[i][:160]}")
            except Exception:  # noqa: BLE001
                pass


run("addmm scalar bias (2,2)@(2,3)", lambda b, x, y: torch.addmm(b, x, y), torch.tensor(0.5), torch.randn(2, 2), torch.randn(2, 3))
run("addmm vector bias", lambda b, x, y: torch.addmm(b, x, y), torch.randn(3), torch.randn(2, 2), torch.randn(2, 3))
run("mm (2,2)@(2,3)", lambda x, y: x @ y, torch.randn(2, 2), torch.randn(2, 3))
run("mm (64,64)@(64,64)", lambda x, y: x @ y, torch.randn(64, 64), torch.randn(64, 64))
run("bmm (10,5,10)@(10,10,5)", lambda x, y: torch.bmm(x, y), torch.randn(10, 5, 10), torch.randn(10, 10, 5))
run("bmm (4,8,8)@(4,8,8)", lambda x, y: torch.bmm(x, y), torch.randn(4, 8, 8), torch.randn(4, 8, 8))
run("matmul (5,10)@(5,10,5)", lambda x, y: torch.matmul(x, y), torch.randn(5, 10), torch.randn(5, 10, 5))
run("linear (4,16)x(8,16)", lambda x, w: torch.nn.functional.linear(x, w), torch.randn(4, 16), torch.randn(8, 16))
run("mm (2,2)@(2,3) max_autotune only", lambda x, y: x @ y, torch.randn(2, 2), torch.randn(2, 3), patch={"max_autotune": True})
