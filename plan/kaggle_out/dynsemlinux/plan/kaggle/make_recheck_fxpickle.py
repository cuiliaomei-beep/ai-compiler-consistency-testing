"""Kaggle job: Linux CPU re-check (2.14 + nightly) of both python blocks of 0920issues/26 (GraphModule pickle round trip)."""
import base64, glob, os, py_compile, re, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
ISSUES = os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")
blocks = re.findall(r"```python\n(.*?)```", open(glob.glob(os.path.join(ISSUES, "26-*.md"))[0], encoding="utf-8").read(), re.S)
assert len(blocks) == 2, len(blocks)
enc = []
for i, code in enumerate(blocks):
    tmp = os.path.join(tempfile.gettempdir(), f"draft26_{i}.py"); open(tmp, "w", encoding="utf-8").write(code); py_compile.compile(tmp, doraise=True)
    enc.append(base64.b64encode(code.encode()).decode())
install = '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]'
path = os.path.join(HERE, "jobs", "fxpicklelinux.py")
open(path, "w", encoding="utf-8").write(
    "# Kaggle script kernel: Linux re-check of 0920 draft 26.\nimport base64, subprocess, sys\n"
    f"for i, b in enumerate({enc!r}):\n"
    '    open(f"draft26_{i}.py", "wb").write(base64.b64decode(b))\n'
    f"for spec in {install}:\n"
    '    subprocess.run(["pip", "-q", "install", *spec])\n'
    "    subprocess.run([sys.executable, '-c', 'import torch; print(\"torch\", torch.__version__, flush=True)'])\n"
    "    for i in range(2):\n"
    '        print(f"--- block {i}", flush=True)\n'
    '        subprocess.run([sys.executable, f"draft26_{i}.py"])\nprint("JOB DONE", flush=True)\n')
py_compile.compile(path, doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"fxpicklelinux"' not in d:
    assert '    "fxlinux": ("tcc-fxlinux", False),\n' in d
    d = d.replace('    "fxlinux": ("tcc-fxlinux", False),\n', '    "fxlinux": ("tcc-fxlinux", False),\n    "fxpicklelinux": ("tcc-fxpicklelinux", False),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("job written")
