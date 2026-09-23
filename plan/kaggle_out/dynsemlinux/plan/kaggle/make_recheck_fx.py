"""Kaggle job: Linux CPU re-check (2.14 + nightly) of the python block of 0920issues/23 (torch.fx parameter shadowing)."""
import base64, glob, os, py_compile, re, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
ISSUES = os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")
code = re.search(r"```python\n(.*?)```", open(glob.glob(os.path.join(ISSUES, "23-*.md"))[0], encoding="utf-8").read(), re.S).group(1)
tmp = os.path.join(tempfile.gettempdir(), "draft23.py"); open(tmp, "w", encoding="utf-8").write(code); py_compile.compile(tmp, doraise=True)
b = base64.b64encode(code.encode()).decode()
install = '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]'
path = os.path.join(HERE, "jobs", "fxlinux.py")
open(path, "w", encoding="utf-8").write(
    "# Kaggle script kernel: Linux re-check of 0920 draft 23.\nimport base64, subprocess, sys\n"
    f'open("draft23.py", "wb").write(base64.b64decode("{b}"))\n'
    f"for spec in {install}:\n"
    '    subprocess.run(["pip", "-q", "install", *spec])\n'
    "    subprocess.run([sys.executable, '-c', 'import torch; print(\"torch\", torch.__version__, flush=True)'])\n"
    '    subprocess.run([sys.executable, "draft23.py"])\nprint("JOB DONE", flush=True)\n')
py_compile.compile(path, doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"fxlinux"' not in d:
    d = d.replace('    "staleepslinux": ("tcc-staleepslinux", False),\n', '    "staleepslinux": ("tcc-staleepslinux", False),\n    "fxlinux": ("tcc-fxlinux", False),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("job written")
