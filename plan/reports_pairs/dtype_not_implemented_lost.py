"""Ops whose eager kernel raises NotImplementedError / RuntimeError for a dtype or an out-of-range fill value, while the
Inductor-compiled function computes something (a third group of #197554 "Validation lost"; pad value = #198071's wrap)."""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_dn_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch
import torch.nn.functional as F

print("torch", torch.__version__)
b = torch.tensor([True, False, True]); i8 = torch.tensor([[1, -2], [3, 4]], dtype=torch.int8); u8 = torch.tensor([1, 200, 3], dtype=torch.uint8)
cases = {
    "bool_tensor - 1": (lambda x: x - 1, b), "1 - bool_tensor": (lambda x: 1 - x, b), "torch.sub(bool, bool)": (lambda x: torch.sub(x, x), b),
    "round(int8, decimals=-1)": (lambda x: torch.round(x, decimals=-1), i8), "round(uint8, decimals=1)": (lambda x: torch.round(x, decimals=1), u8),
    "ceil(bool)": (lambda x: torch.ceil(x), b), "floor(bool)": (lambda x: torch.floor(x), b), "trunc(bool)": (lambda x: torch.trunc(x), b), "round(bool)": (lambda x: torch.round(x), b),
    "F.glu(int8)": (lambda x: F.glu(x), i8), "adaptive_max_pool2d(int8)": (lambda x: F.adaptive_max_pool2d(x[None], (1, 1)), i8), "max_pool2d(int8)": (lambda x: F.max_pool2d(x[None], 2), i8),
    "F.pad(uint8, value=-1)": (lambda x: F.pad(x, (1, 1), value=-1), u8), "F.pad(int8, value=300)": (lambda x: F.pad(x, (1, 0), value=300), i8), "F.pad(uint8, value=2.5)": (lambda x: F.pad(x, (1, 1), value=2.5), u8),
}
for name, (fn, x) in cases.items():
    row = []
    for backend in (None, "aot_eager", "inductor"):
        torch._dynamo.reset()
        try:
            r = fn(x.clone()) if backend is None else torch.compile(fn, backend=backend)(x.clone())
            row.append(f"returns {r.tolist()} {str(r.dtype).split('.')[-1]}")
        except Exception as e:  # noqa: BLE001
            row.append(f"raises {type(e).__name__}: {str(e).splitlines()[0][:50]}")
    print(f"{name:28s}\n    eager     {row[0]}\n    aot_eager {row[1]}\n    inductor  {row[2]}", flush=True)
