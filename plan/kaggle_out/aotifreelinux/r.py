
import sys, os, gc, tempfile, torch, subprocess
from torch._inductor import aoti_compile_and_package, aoti_load_package
print("torch", torch.__version__, flush=True)
class M(torch.nn.Module):
    def forward(self, x): return x + 1
def run(variant):
    code = f"""
import gc, os, tempfile, torch
from torch._inductor import aoti_compile_and_package, aoti_load_package
class M(torch.nn.Module):
    def forward(self, x): return x + 1
x = torch.randn(4); ep = torch.export.export(M(), (x,)); work = tempfile.mkdtemp()
runner = aoti_load_package(aoti_compile_and_package(ep, package_path=os.path.join(work, 'm.pt2')))
out = runner(x)
if '{variant}' == 'out_alive': del runner; gc.collect(); print('runner freed OK; out =', out.tolist(), flush=True)
if '{variant}' == 'out_freed_first': del out; del runner; gc.collect(); print('freed OK (out freed first)', flush=True)
if '{variant}' == 'del_no_gc': del runner; print('deleted no gc OK; out =', out.tolist(), flush=True)
print('DONE', flush=True)
"""
    r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True)
    print(f"{variant:16s} exit={r.returncode} {r.stdout.strip().splitlines()[-1] if r.stdout.strip() else ''} {r.stderr.strip().splitlines()[-1][:120] if r.stderr.strip() else ''}", flush=True)
for v in ("out_alive", "out_freed_first", "del_no_gc"):
    run(v)
