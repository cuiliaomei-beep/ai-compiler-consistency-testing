"""11.3  Pair audit: same-name ops handlers of the Inductor C++ scalar backend (CppOverrides) and the vector backend
(CppVecOverrides).  Prints both bodies next to each other so that a guard present in only one of them stands out
(the pattern behind #143649 comment / draft 03: floordiv guards division by zero, truncdiv does not)."""
import inspect
import re
import sys

import torch
from torch._inductor.codegen.cpp import CppOverrides, CppVecOverrides

print("torch", torch.__version__)
KEY = re.compile(r"isnan|isinf|nan|inf|zero|== 0|!= 0|overflow|min\(\)|max\(\)|numeric_limits|is_integer|is_floating|signbit|copysign|blendv|mask", re.I)


def body(cls, name):
    f = cls.__dict__.get(name)
    if f is None:
        return None
    f = getattr(f, "__func__", f)
    try:
        return inspect.getsource(f)
    except (OSError, TypeError):
        return None


names = sorted(n for n in set(CppOverrides.__dict__) | set(CppVecOverrides.__dict__) if not n.startswith("_"))
only_scalar, only_vec = [], []
for n in names:
    s, v = body(CppOverrides, n), body(CppVecOverrides, n)
    if s and not v:
        only_scalar.append(n); continue
    if v and not s:
        only_vec.append(n); continue
    if not s or not v:
        continue
    ks, kv = set(m.lower() for m in KEY.findall(s)), set(m.lower() for m in KEY.findall(v))
    flag = "ASYM" if ks != kv else "    "
    if "--all" in sys.argv or ks != kv:
        print(f"\n===== {flag} {n}   scalar-only keys {sorted(ks - kv)}   vec-only keys {sorted(kv - ks)}")
        print("--- scalar"); print(s.rstrip()); print("--- vector"); print(v.rstrip())
print("\nscalar only (vector falls back to scalar loop):", only_scalar)
print("vector only:", only_vec)
