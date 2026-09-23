"""Which OpInfo sample of OP kills the interpreter on the export/AOTI path? One child process per sample.

usage: python scripts/find_aoti_crash.py OP [--stage export|aoti|run]
"""
import subprocess
import sys

HERE = __import__("os").path.dirname(__import__("os").path.dirname(__import__("os").path.abspath(__file__)))
op_name = sys.argv[1]

CHILD = r'''
import os, sys, tempfile, torch
sys.path.insert(0, %r)
from tcc.compat import ensure_msvc_env; ensure_msvc_env()
from torch.export import export
from torch._inductor import aoti_compile_and_package, aoti_load_package
from torch.testing._internal.common_methods_invocations import op_db
op = [o for o in op_db if o.name == %r][0]
idx = int(sys.argv[1])
s = list(op.sample_inputs('cpu', torch.float32, requires_grad=False))[idx]
kw = dict(s.kwargs); args = (s.input,) + tuple(s.args)
def short(v): return f"tensor{tuple(v.shape)}" if isinstance(v, torch.Tensor) else repr(v)
print("sample", idx, [short(a) for a in args], {k: short(v) for k, v in kw.items()}, flush=True)
class M(torch.nn.Module):
    def forward(self, *a): return op.op(*a, **kw)
m = M()
e = m(*args); print("  eager ok", flush=True)
ep = export(m, args); print("  export ok", flush=True)
r = ep.module()(*args); print("  ep.module ok", flush=True)
p = aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), "m.pt2")); print("  aoti compile ok", flush=True)
runner = aoti_load_package(p); print("  aoti load ok", flush=True)
out = runner(*args); print("  aoti run ok", torch.allclose(out, e) if isinstance(out, torch.Tensor) else type(out).__name__, flush=True)
''' % (HERE, op_name)

n = int(subprocess.run([sys.executable, "-c", "import torch; from torch.testing._internal.common_methods_invocations import op_db; "
                        f"op=[o for o in op_db if o.name=={op_name!r}][0]; "
                        "print(len(list(op.sample_inputs('cpu', torch.float32, requires_grad=False))))"],
                       capture_output=True, text=True).stdout.strip().splitlines()[-1])
print(f"{op_name}: {n} samples")
for i in range(n):
    r = subprocess.run([sys.executable, "-c", CHILD, str(i)], capture_output=True, text=True, encoding="utf-8", errors="replace")
    lines = [ln for ln in r.stdout.splitlines() if ln.startswith(("sample", "  "))]
    status = "" if r.returncode == 0 else f"   <-- rc {r.returncode & 0xFFFFFFFF:#x}"
    if r.returncode != 0 and not status.endswith("0xc0000005"):
        err = (r.stderr or "").strip().splitlines()
        status += " | " + (err[-1][:120] if err else "")
    print(" | ".join(ln.strip() for ln in lines) + status)
