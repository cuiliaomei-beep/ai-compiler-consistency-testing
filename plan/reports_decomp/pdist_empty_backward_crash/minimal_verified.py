"""Eager-side crash: backward of F.pdist on an input with zero rows kills the process (integer division by zero).

Run each case in a child interpreter because the crash is a native abort (Windows exit 0xC0000094):
    python reports_decomp/pdist_empty_backward_crash/minimal_verified.py
Found by the gradient decomposition differential (plan/tcc/decomp_diff.py --grad, variant empty_dim0).
"""
import subprocess
import sys

CASE = r'''
import sys, torch
n, d = int(sys.argv[1]), int(sys.argv[2])
x = torch.randn(n, d, requires_grad=True)
y = torch.nn.functional.pdist(x)
print("forward ok, output shape", tuple(y.shape), flush=True)
y.sum().backward()
print("backward ok, grad shape", tuple(x.grad.shape), flush=True)
'''

print(torch.__version__ if (torch := __import__("torch")) else "")
for n, d in ((0, 1), (0, 4), (1, 4), (2, 4)):
    r = subprocess.run([sys.executable, "-c", CASE, str(n), str(d)], capture_output=True, text=True)
    out = " | ".join(r.stdout.strip().splitlines())
    status = "" if r.returncode == 0 else f"   <-- process died, exit code {r.returncode & 0xFFFFFFFF:#x}"
    print(f"pdist on ({n}, {d}): {out}{status}")
