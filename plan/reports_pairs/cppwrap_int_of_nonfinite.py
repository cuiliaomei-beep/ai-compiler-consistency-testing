"""C++ wrapper (cpp_wrapper=True / AOTInductor) vs Python wrapper: `int(x.item())` for a non-finite float.
Eager and the Python wrapper raise (OverflowError / ValueError, as Python does); the C++ wrapper evaluates the
symbolic expression with a C++ cast, which is undefined for out-of-range values and yields INT64_MIN on x86."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_cwi_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import math
import torch

print("torch", torch.__version__)
torch._dynamo.config.capture_scalar_outputs = True
INF, NAN = float("inf"), float("nan")

PROGS = {
    "int(u)": lambda x: torch.full((2,), int(x.item())),
    "math.trunc(u)": lambda x: torch.full((2,), math.trunc(x.item())),
    "math.floor(u)": lambda x: torch.full((2,), math.floor(x.item())),
    "round(u)": lambda x: torch.full((2,), round(x.item())),
    "int(u) as size": lambda x: torch.zeros(abs(int(x.item())) % 5 + 1),
    "round(u, 1)": lambda x: torch.full((2,), round(x.item(), 1), dtype=torch.float64),
}
VALUES = (2.7, -0.0, 1e20, INF, -INF, NAN)


def show(f, x):
    try:
        out = f(x)
        return repr(out.tolist()) if out.numel() <= 2 else f"shape {tuple(out.shape)}"
    except Exception as e:  # noqa: BLE001
        return "raises " + type(e).__name__


for name, f in PROGS.items():
    for v in VALUES:
        x = torch.tensor(v, dtype=torch.float64)
        res = {"eager": show(f, x)}
        for label, opts in (("py_wrapper", {}), ("cpp_wrapper", {"cpp_wrapper": True})):
            torch._dynamo.reset()
            res[label] = show(torch.compile(f, options=opts), x)
        flag = "  " if res["eager"] == res["py_wrapper"] == res["cpp_wrapper"] else ("!!" if res["cpp_wrapper"] != res["eager"] else "  ")
        print(f"{flag} {name:16s} u={v!s:6s}  eager {res['eager']:28s} py_wrapper {res['py_wrapper']:28s} cpp_wrapper {res['cpp_wrapper']}", flush=True)
