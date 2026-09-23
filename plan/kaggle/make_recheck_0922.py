"""Kaggle jobs: safety-mechanism parity (deterministic mode, inference tensors), draft 19 snippet, stale float alpha; Linux CPU 2.14 + nightly, and T4."""
import base64, glob, os, py_compile, re, tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
PLAN = os.path.dirname(HERE)
ISSUES = os.path.join(os.path.dirname(PLAN), "0920issues")
files = {}
for name in ("deterministic_mode_parity.py", "safety_mechanisms_lost.py", "float_arg_cache_matrix.py"):
    files[name] = open(os.path.join(PLAN, "reports_surgery", name), encoding="utf-8").read()
files["draft19.py"] = re.search(r"```python\n(.*?)```", open(glob.glob(os.path.join(ISSUES, "19-*.md"))[0], encoding="utf-8").read(), re.S).group(1)
for n, src in files.items():
    tmp = os.path.join(tempfile.gettempdir(), "chk_" + n)
    open(tmp, "w", encoding="utf-8").write(src)
    py_compile.compile(tmp, doraise=True)
payload = {n: base64.b64encode(s.encode()).decode() for n, s in files.items()}
JOBS = {
    "safetylinux": '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]',
    "safetygpu": '[["--upgrade", "torch==2.14.0"]]',
}
for job, install in JOBS.items():
    with open(os.path.join(HERE, "jobs", job + ".py"), "w", encoding="utf-8") as f:
        f.write("# Kaggle script kernel: safety-mechanism parity + draft 19 + stale float alpha.\n"
                "import base64, subprocess, sys\n"
                f"payload = {payload!r}\n"
                "for n, b in payload.items():\n"
                "    open(n, 'wb').write(base64.b64decode(b))\n"
                f"for spec in {install}:\n"
                '    subprocess.run(["pip", "-q", "install", *spec])\n'
                "    for n in payload:\n"
                "        print('=====', n, flush=True)\n"
                "        subprocess.run([sys.executable, n])\n"
                'print("JOB DONE", flush=True)\n')
    py_compile.compile(os.path.join(HERE, "jobs", job + ".py"), doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"safetylinux"' not in d:
    d = d.replace('    "cxxalgebra": ("tcc-cxxalgebra", False),\n', '    "cxxalgebra": ("tcc-cxxalgebra", False),\n    "safetylinux": ("tcc-safetylinux", False),\n    "safetygpu": ("tcc-safetygpu", True),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written")
