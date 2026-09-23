"""Build the Kaggle jobs that re-run the python blocks of 0920issues/07-11 on Linux (CPU 2.14 + nightly, and T4)."""
import base64
import glob
import os
import py_compile
import re
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ISSUES = os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")

parts = ["import torch", "print('torch', torch.__version__, flush=True)"]
for f in sorted(glob.glob(os.path.join(ISSUES, "0[7-9]-*.md")) + glob.glob(os.path.join(ISSUES, "1[01]-*.md"))):
    code = re.search(r"```python\n(.*?)```", open(f, encoding="utf-8").read(), re.S).group(1)
    parts.append("print()")
    parts.append("print('===== draft " + os.path.basename(f)[:2] + "', flush=True)")
    parts.append(code)
parts.append(r'''
print()
print('===== same checks on CUDA', flush=True)
import torch
if torch.cuda.is_available():
    INF = float("inf")
    a = torch.tensor([1.0, 0.5, 6.0, 1.0, 5.5, 1e20, 7.0, -0.0], device="cuda")
    b = torch.tensor([0.1, 0.1, 0.2, 1 / 3, INF, 3.0, 0.7, 1.0], device="cuda")
    for name, fn in (("a // b", lambda a, b: a // b), ("a % b", lambda a, b: a % b)):
        torch._dynamo.reset()
        print("cuda", name, "eager", fn(a, b).tolist(), "inductor", torch.compile(fn)(a, b).tolist())
    x = torch.tensor([5, 1, 100, 3, 7, 8, 9, 13, 100, 120, 127, 2, 6, 4, 11, 12, 90, 80], dtype=torch.uint8, device="cuda")
    torch._dynamo.reset()
    print("cuda uint8 min/argmin eager", torch.min(x).item(), torch.argmin(x).item(),
          "inductor", torch.compile(torch.min)(x).item(), torch.compile(torch.argmin)(x).item())
    y = torch.tensor([0.1, 70000.0], device="cuda")
    f = lambda t: t.half().float()
    torch._dynamo.reset()
    print("cuda half roundtrip eager", f(y).tolist(), "inductor", torch.compile(f)(y).tolist())
    z = torch.tensor([-128, -3, 0, 5, 127], dtype=torch.int8, device="cuda")
    g = lambda t: torch.clamp(t, -1000, 1000)
    try:
        e = g(z).tolist()
    except Exception as ex:
        e = "raises " + type(ex).__name__
    torch._dynamo.reset()
    print("cuda clamp eager", e, "inductor", torch.compile(g)(z).tolist())
else:
    print("no cuda")
''')
script = "\n".join(parts)
tmp = os.path.join(tempfile.gettempdir(), "recheck_0920.py")
open(tmp, "w", encoding="utf-8").write(script)
py_compile.compile(tmp, doraise=True)
b = base64.b64encode(script.encode()).decode()
JOBS = {
    "intublinux": '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]',
    "intubgpu": '[["--upgrade", "torch==2.14.0"]]',
}
for job, install in JOBS.items():
    with open(os.path.join(HERE, "jobs", job + ".py"), "w", encoding="utf-8") as f:
        f.write("# Kaggle script kernel: Linux re-check of 0920 drafts 07-11.\n"
                "import base64, subprocess, sys\n"
                f'open("recheck.py", "wb").write(base64.b64decode("{b}"))\n'
                f"for spec in {install}:\n"
                '    subprocess.run(["pip", "-q", "install", *spec])\n'
                '    subprocess.run([sys.executable, "recheck.py"])\n'
                'print("JOB DONE", flush=True)\n')
print("jobs written;", len(script), "bytes; syntax ok")
