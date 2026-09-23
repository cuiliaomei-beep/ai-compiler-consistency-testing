import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
try:
    from tcc.compat import ensure_msvc_env; ensure_msvc_env()
except Exception:
    pass
import sympy, torch
from torch.utils._sympy.functions import PowByNatural
from torch.utils._sympy.printers import PythonPrinter
print("torch", torch.__version__)
s = sympy.Symbol("s0", integer=True, positive=True)
e = PowByNatural(sympy.Integer(-2), s)
print("sympy expr:", e, "| srepr:", sympy.srepr(e))
print("PythonPrinter:", PythonPrinter().doprint(e))
print("subs s0=2 ->", e.subs(s, 2), "| xreplace ->", e.xreplace({s: sympy.Integer(2)}))

for name, f in (("(-2) ** n", lambda x: (-2) ** x.shape[0]), ("(-1) ** n", lambda x: (-1) ** x.shape[0]), ("(-3) ** n", lambda x: (-3) ** x.shape[0]),
                ("(2 - 4) ** n", lambda x: (2 - 4) ** x.shape[0]), ("pow(-2, n)", lambda x: pow(-2, x.shape[0])), ("(-n) ** 2", lambda x: (-x.shape[0]) ** 2),
                ("sign tensor: x * (-1) ** n", lambda x: x * (-1) ** x.shape[0])):
    for backend in ("eager", "inductor"):
        torch._dynamo.reset()
        g = torch.compile(f, backend=backend, dynamic=True)
        outs = []
        for n in (2, 3, 4):
            want, got = f(torch.ones(n)), g(torch.ones(n))
            outs.append(f"n={n}: python {want.tolist() if isinstance(want, torch.Tensor) else want} compiled {got.tolist() if isinstance(got, torch.Tensor) else got}")
        print(f"{name:28s} {backend:9s}", " | ".join(outs))
