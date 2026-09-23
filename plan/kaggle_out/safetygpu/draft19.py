import subprocess, sys

child = r'''
import torch
op = {"floor": lambda a, b: a // b, "trunc": lambda a, b: torch.div(a, b, rounding_mode="trunc"), "remainder": lambda a, b: a % b}[__import__("sys").argv[1]]
a = torch.arange(1, 9, dtype=torch.int32); b = torch.ones(8, dtype=torch.int32); b[3] = 0
try:
    torch.compile(op)(a, b)
except RuntimeError as e:
    print("raised RuntimeError, ZeroDivisionError in message:", "ZeroDivisionError" in str(e))
'''
for name in ("floor", "remainder", "trunc"):
    r = subprocess.run([sys.executable, "-c", child, name], capture_output=True, text=True)
    print(f"{name:10s}", r.stdout.strip() or f"process died, return code {r.returncode & 0xFFFFFFFF:#x}")
