"""Kaggle job: Linux CPU re-check (2.14 + nightly) of the python blocks of 0920issues/21-23."""
import base64, glob, os, py_compile, re, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ISSUES = os.path.join(os.path.dirname(os.path.dirname(HERE)), "0920issues")
payload = {}
for f in sorted(glob.glob(os.path.join(ISSUES, "2[123]-*.md"))):
    code = re.search(r"```python\n(.*?)```", open(f, encoding="utf-8").read(), re.S).group(1)
    name = "draft" + os.path.basename(f)[:2] + ".py"
    tmp = os.path.join(tempfile.gettempdir(), name); open(tmp, "w", encoding="utf-8").write(code); py_compile.compile(tmp, doraise=True)
    payload[name] = base64.b64encode(code.encode()).decode()
install = '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]'
path = os.path.join(HERE, "jobs", "symintlinux.py")
with open(path, "w", encoding="utf-8") as f:
    f.write("# Kaggle script kernel: Linux re-check of 0920 drafts 21-23.\n"
            "import base64, subprocess, sys\n"
            f"payload = {payload!r}\n"
            "for n, b in payload.items():\n"
            "    open(n, 'wb').write(base64.b64decode(b))\n"
            f"for spec in {install}:\n"
            '    subprocess.run(["pip", "-q", "install", *spec])\n'
            "    subprocess.run([sys.executable, '-c', 'import torch; print(\"torch\", torch.__version__, flush=True)'])\n"
            "    for n in payload:\n"
            "        print('=====', n, flush=True)\n"
            "        subprocess.run([sys.executable, n])\n"
            'print("JOB DONE", flush=True)\n')
py_compile.compile(path, doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"symintlinux"' not in d:
    d = d.replace('    "safetygpu": ("tcc-safetygpu", True),\n', '    "safetygpu": ("tcc-safetygpu", True),\n    "symintlinux": ("tcc-symintlinux", False),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("job written", list(payload))
