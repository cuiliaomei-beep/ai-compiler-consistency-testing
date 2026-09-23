"""Inductor's Python wrapper prints complex scalar arguments of fallback kernels with repr().  repr(complex) is not a
value-preserving Python expression:
  * (inf-infj), (1+infj): `infj` is not a name            -> NameError at run time (loud)
  * (-1-0j) evaluates to complex(-1, +0.0); (-0+1j) evaluates to complex(+0.0, 1)   -> the sign of a zero part is lost,
    which moves sqrt / log / pow / angle to the other side of their branch cut       (silent)
"""
import os, sys, tempfile
os.environ.setdefault("TORCHINDUCTOR_CACHE_DIR", tempfile.mkdtemp(prefix="tcc_cx_"))
try:
    sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
    from tcc.compat import ensure_msvc_env
    ensure_msvc_env()
except Exception:  # noqa: BLE001
    pass
import torch
from torch._inductor.utils import run_and_get_code

print("torch", torch.__version__)
inf, nan = float("inf"), float("nan")
a = torch.tensor([1 + 2j, -3 + 0.5j], dtype=torch.complex64)
progs = {
    "sqrt(full_like(a, z))": lambda a, z: torch.full_like(a, z).sqrt(),
    "sqrt(a.fill_(z))": lambda a, z: a.clone().fill_(z).sqrt(),
    "sqrt(where(a.real > 9, a, z))": lambda a, z: torch.where(a.real > 9, a, z).sqrt(),
    "log(masked_fill(a, mask, z))": lambda a, z: a.masked_fill(a.real < 9, z).log(),
    "angle(a * 0 + z)": lambda a, z: (a * 0 + z).angle(),
    "a * z": lambda a, z: a * z,
}
for z in (complex(-1.0, -0.0), complex(-0.0, 1.0), complex(1.0, inf), complex(inf, -inf), complex(0.0, nan)):
    for name, f in progs.items():
        torch._dynamo.reset()
        e = f(a, z)
        try:
            c, codes = run_and_get_code(torch.compile(lambda a: f(a, z)), a)
            line = next((l.strip() for l in codes[0].splitlines() if "j)" in l or "complex(" in l), "")
            same = torch.equal(torch.view_as_real(e).nan_to_num(nan=-7.0), torch.view_as_real(c).nan_to_num(nan=-7.0)) if e.is_complex() else torch.equal(e, c)
            print(f"z={z!r:12s} {name:32s} {'same' if same else 'DIFF'}  eager {e[:1].tolist()}  compiled {c[:1].tolist()}   | {line[:90]}")
        except Exception as ex:  # noqa: BLE001
            print(f"z={z!r:12s} {name:32s} RAISES {type(ex).__name__}: {str(ex)[:70]}   eager {e[:1].tolist()}")
