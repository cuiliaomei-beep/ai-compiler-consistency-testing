
import sys, subprocess, os
print("torch", __import__("torch").__version__, flush=True)
code = """
import gc, os, sys, time, tempfile, torch
from torch._inductor import aoti_compile_and_package, aoti_load_package
n, variant = int(sys.argv[1]), sys.argv[2]
class M(torch.nn.Module):
    def forward(self, x): return x + 1
x = torch.randn(n); ep = torch.export.export(M(), (x,))
runner = aoti_load_package(aoti_compile_and_package(ep, package_path=os.path.join(tempfile.mkdtemp(), 'm.pt2')))
out = runner(x)
if variant == 'sleep': time.sleep(2)
del runner; gc.collect(); print('runner destroyed OK', flush=True)
"""
for n in (1024, 4096, 65536):
    for variant, env in (("base", {}), ("sleep", {}), ("omp1", {"OMP_NUM_THREADS": "1"})):
        r = subprocess.run([sys.executable, "-c", code, str(n), variant], capture_output=True, text=True, env={**os.environ, **env})
        print(f"n={n:6d} {variant:6s} exit={r.returncode} {(r.stdout.strip().splitlines() or [''])[-1]} {(r.stderr.strip().splitlines() or [''])[-1][:100]}", flush=True)
