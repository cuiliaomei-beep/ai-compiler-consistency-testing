"""Build Kaggle jobs that re-run the python blocks of 0920issues/12-13 on Linux (CPU 2.14 + nightly, and T4 CUDA)."""
import base64
import glob
import os
import py_compile
import re
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ISSUES = os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")

parts = ["import torch", "print('torch', torch.__version__, flush=True)"]
for f in sorted(glob.glob(os.path.join(ISSUES, "1[23]-*.md"))):
    code = re.search(r"```python\n(.*?)```", open(f, encoding="utf-8").read(), re.S).group(1)
    parts += ["print()", "print('===== draft " + os.path.basename(f)[:2] + "', flush=True)", code]
parts.append(r'''
print()
print('===== draft 13 on CUDA', flush=True)
import torch, torch.nn.functional as F
if torch.cuda.is_available():
    def transposed(x):
        return x.transpose(-1, -2).contiguous().transpose(-1, -2)
    for name, f, shape, nd in cases:
        x = transposed(torch.randperm(torch.Size(shape).numel()).float().reshape(shape)).cuda()
        ev, ei = f(x)
        torch._dynamo.reset()
        cv, ci = torch.compile(f)(x)
        xe = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); f(xe)[0].sum().backward()
        torch._dynamo.reset()
        xc = x.detach().clone(memory_format=torch.preserve_format).requires_grad_(); torch.compile(f)(xc)[0].sum().backward()
        print("cuda", name, "values equal", torch.equal(ev, cv), "indices equal", torch.equal(ei, ci), "grad equal", torch.equal(xe.grad, xc.grad))
else:
    print("no cuda")
''')
script = "\n".join(parts)
tmp = os.path.join(tempfile.gettempdir(), "recheck_0921.py")
open(tmp, "w", encoding="utf-8").write(script)
py_compile.compile(tmp, doraise=True)
b = base64.b64encode(script.encode()).decode()
JOBS = {
    "sidelinux": '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]',
    "sidegpu": '[["--upgrade", "torch==2.14.0"]]',
}
for job, install in JOBS.items():
    with open(os.path.join(HERE, "jobs", job + ".py"), "w", encoding="utf-8") as f:
        f.write("# Kaggle script kernel: Linux re-check of 0920 drafts 12-13.\n"
                "import base64, subprocess, sys\n"
                f'open("recheck.py", "wb").write(base64.b64decode("{b}"))\n'
                f"for spec in {install}:\n"
                '    subprocess.run(["pip", "-q", "install", *spec])\n'
                '    subprocess.run([sys.executable, "recheck.py"])\n'
                'print("JOB DONE", flush=True)\n')
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"sidelinux"' not in d:
    d = d.replace('    "intubgpu": ("tcc-intubgpu", True),\n', '    "intubgpu": ("tcc-intubgpu", True),\n    "sidelinux": ("tcc-sidelinux", False),\n    "sidegpu": ("tcc-sidegpu", True),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written; syntax ok;", len(script), "bytes")
