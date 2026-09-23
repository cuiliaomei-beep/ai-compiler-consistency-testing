"""Linux confirmation for issue draft 07: backward of F.pdist on zero-row input kills the process.

Self-contained; runs each case in a child interpreter and reports the exit status. On Linux a native
integer-divide-by-zero shows up as returncode -8 (SIGFPE); on Windows as 0xC0000094.

    python pdist_crash_linux.py
"""
import platform
import signal
import subprocess
import sys

import torch

CASE = r'''
import sys, torch
n, d = int(sys.argv[1]), int(sys.argv[2])
x = torch.randn(n, d, requires_grad=True)
y = torch.nn.functional.pdist(x)
print("forward ok, output shape", tuple(y.shape), flush=True)
y.sum().backward()
print("backward ok, grad shape", tuple(x.grad.shape), flush=True)
'''

print("torch", torch.__version__, "|", platform.platform(), "|", sys.version.split()[0])
for n, d in ((0, 1), (0, 4), (1, 4), (2, 4)):
    r = subprocess.run([sys.executable, "-c", CASE, str(n), str(d)], capture_output=True, text=True)
    out = " | ".join(r.stdout.strip().splitlines())
    if r.returncode == 0:
        status = ""
    elif r.returncode < 0:
        try:
            name = signal.Signals(-r.returncode).name
        except ValueError:
            name = "?"
        status = f"   <-- process killed by signal {-r.returncode} ({name})"
    else:
        status = f"   <-- process died, exit code {r.returncode & 0xFFFFFFFF:#x}"
    print(f"pdist on ({n}, {d}): {out}{status}")
