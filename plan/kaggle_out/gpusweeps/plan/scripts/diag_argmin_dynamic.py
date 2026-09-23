"""Diagnose: where(mask, x, inf).argmin() under torch.compile(dynamic=True) -> Inductor C++ compile error (CPU).

Prints which shapes trigger it, and the offending generated C++ lines.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402

print(torch.__version__)
torch.manual_seed(0)


def try_case(label, fn, *args):
    torch._dynamo.reset()
    try:
        c = torch.compile(fn, dynamic=True)(*args)
        e = fn(*args)
        print(f"[{label}] ok same={torch.equal(c, e)}")
        return None
    except Exception as ex:  # noqa: BLE001
        inner = ex
        while inner.__cause__ is not None:
            inner = inner.__cause__
        msg = str(inner)
        print(f"[{label}] {type(inner).__name__}")
        return msg


def show_cpp(msg):
    # MSVC: <path>(<line>): error C2100: ...
    m = re.search(r"([A-Za-z]:[^\s(]+\.cpp)\((\d+)\)", msg)
    if not m:
        m = re.search(r"([^\s:]+\.cpp):(\d+):", msg)
    if not m:
        print("   (no file/line in message)", msg[:300].encode("ascii", "replace").decode())
        return
    path, line = m.group(1), int(m.group(2))
    print(f"   {path}:{line}")
    try:
        lines = open(path, encoding="utf-8", errors="replace").read().splitlines()
        for i in range(max(0, line - 6), min(len(lines), line + 2)):
            print(f"   {i + 1:4d}| {lines[i]}")
    except Exception as e:  # noqa: BLE001
        print("   cannot read:", e)


INF = torch.tensor(float("inf"))
msg = try_case("where(mask,x,inf).argmin() x(3,2,1,2) mask(1,2,1,2)",
               lambda x, m: torch.where(m, x, INF).argmin(), torch.randn(3, 2, 1, 2),
               torch.tensor([[[[True, True]], [[False, True]]]]))
if msg:
    show_cpp(msg)
# variations
try_case("x(3,2,2) mask(1,2,2)", lambda x, m: torch.where(m, x, INF).argmin(), torch.randn(3, 2, 2),
         torch.tensor([[[True, True], [False, True]]]))
try_case("x(3,2,2,2) mask(1,2,2,2)", lambda x, m: torch.where(m, x, INF).argmin(), torch.randn(3, 2, 2, 2),
         torch.rand(1, 2, 2, 2) > 0.3)
try_case("x(3,2,1,2) mask(1,2,1,2) argmax", lambda x, m: torch.where(m, x, -INF).argmax(), torch.randn(3, 2, 1, 2),
         torch.tensor([[[[True, True]], [[False, True]]]]))
try_case("x(3,2,1,2) mask(1,2,1,2) amin (no index)", lambda x, m: torch.where(m, x, INF).amin(), torch.randn(3, 2, 1, 2),
         torch.tensor([[[[True, True]], [[False, True]]]]))
try_case("x(3,2,1,2) + m(1,2,1,2) float, argmin", lambda x, m: (x + m).argmin(), torch.randn(3, 2, 1, 2),
         torch.randn(1, 2, 1, 2))
try_case("x(3,2,1,2) argmin alone", lambda x: x.argmin(), torch.randn(3, 2, 1, 2))
try_case("x(3,2,1,2) + m(1,2,1,2) argmin dim=0", lambda x, m: (x + m).argmin(dim=0), torch.randn(3, 2, 1, 2),
         torch.randn(1, 2, 1, 2))
try_case("x(5,2,1,2) + m(1,2,1,2) argmin (odd batch)", lambda x, m: (x + m).argmin(), torch.randn(5, 2, 1, 2),
         torch.randn(1, 2, 1, 2))
try_case("x(3,4,1,4) + m(1,4,1,4) argmin", lambda x, m: (x + m).argmin(), torch.randn(3, 4, 1, 4),
         torch.randn(1, 4, 1, 4))
try_case("x(3,2,1,2) + m(1,2,1,2) argmin, mark_dynamic only x", lambda x, m: (x + m).argmin(),
         torch.randn(3, 2, 1, 2), torch.randn(1, 2, 1, 2))
