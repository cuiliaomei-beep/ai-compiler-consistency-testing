"""Build Kaggle jobs that re-run the python blocks of 0920issues/14-15 (+ the int abs(abs) check) on Linux CPU (2.14 + nightly) and T4 CUDA."""
import base64
import glob
import os
import py_compile
import re
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ISSUES = os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")

parts = ["import torch", "print('torch', torch.__version__, flush=True)"]
for f in sorted(glob.glob(os.path.join(ISSUES, "1[45]-*.md"))):
    blocks = re.findall(r"```python\n(.*?)```", open(f, encoding="utf-8").read(), re.S)
    for i, code in enumerate(blocks):
        if "import torch" not in code:
            continue
        parts += ["print()", "print('===== draft " + os.path.basename(f)[:2] + " block " + str(i) + "', flush=True)",
                  "try:\n" + "\n".join("    " + l for l in code.splitlines()) + "\nexcept Exception as e:\n    print('EXC', type(e).__name__, str(e)[:300])"]
parts.append(r'''
print()
print('===== int abs(abs(x)) (MSVC-only?)', flush=True)
import torch
for dev in (["cpu"] + (["cuda"] if torch.cuda.is_available() else [])):
    for dt in (torch.int8, torch.int16, torch.int32, torch.int64):
        for n in (5, 40):
            x = (torch.arange(n) - n // 2).to(dt).to(dev)
            f = lambda t: t.abs().abs()
            torch._dynamo.reset()
            print(dev, dt, n, "equal", torch.equal(f(x), torch.compile(f)(x)), flush=True)
print()
print('===== draft 15 on CUDA', flush=True)
if torch.cuda.is_available():
    for name, f in (("x / 1.0", lambda x: x / 1.0), ("x * 1.0", lambda x: x * 1.0), ("x + 0", lambda x: x + 0), ("x / 0.9", lambda x: x / 0.9)):
        for backend in ("aot_eager", "inductor"):
            torch._dynamo.reset()
            x = torch.ones(3, device="cuda")
            out = torch.compile(f, backend=backend)(x)
            same = out is x
            out.add_(5)
            print("cuda", name, backend, "out is x:", same, "x afterwards:", x.tolist(), flush=True)
    print('===== draft 14 on CUDA (adaptive_max_pool3d channels_last_3d grad)', flush=True)
    import torch.nn.functional as F
    torch.manual_seed(0)
    x0 = torch.randperm(2 * 3 * 6 * 7 * 8).float().reshape(2, 3, 6, 7, 8).cuda().contiguous(memory_format=torch.channels_last_3d)
    f = lambda t: F.adaptive_max_pool3d(t, (3, 3, 3))
    xe = x0.clone(memory_format=torch.preserve_format).requires_grad_(); f(xe).sum().backward()
    torch._dynamo.reset()
    xc = x0.clone(memory_format=torch.preserve_format).requires_grad_(); torch.compile(f)(xc).sum().backward()
    print("cuda adaptive_max_pool3d chlast grad equal:", torch.equal(xe.grad, xc.grad), "max diff", (xe.grad - xc.grad).abs().max().item())
else:
    print("no cuda")
''')
script = "\n".join(parts)
tmp = os.path.join(tempfile.gettempdir(), "recheck_0921b.py")
open(tmp, "w", encoding="utf-8").write(script)
py_compile.compile(tmp, doraise=True)
b = base64.b64encode(script.encode()).decode()
JOBS = {
    "rewritelinux": '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]',
    "rewritegpu": '[["--upgrade", "torch==2.14.0"]]',
}
for job, install in JOBS.items():
    with open(os.path.join(HERE, "jobs", job + ".py"), "w", encoding="utf-8") as f:
        f.write("# Kaggle script kernel: Linux re-check of 0920 drafts 14-15 and the int abs(abs) lead.\n"
                "import base64, subprocess, sys\n"
                f'open("recheck.py", "wb").write(base64.b64decode("{b}"))\n'
                f"for spec in {install}:\n"
                '    subprocess.run(["pip", "-q", "install", *spec])\n'
                '    subprocess.run([sys.executable, "recheck.py"])\n'
                'print("JOB DONE", flush=True)\n')
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"rewritelinux"' not in d:
    d = d.replace('    "sidegpu": ("tcc-sidegpu", True),\n', '    "sidegpu": ("tcc-sidegpu", True),\n    "rewritelinux": ("tcc-rewritelinux", False),\n    "rewritegpu": ("tcc-rewritegpu", True),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written; syntax ok;", len(script), "bytes")
