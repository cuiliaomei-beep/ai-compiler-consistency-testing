"""Kaggle jobs: residual stale-float (norm eps) on the newest nightly, Linux CPU and T4; also 2.14.0 for reference."""
import base64
import os
import py_compile

HERE = os.path.dirname(os.path.abspath(__file__))
PLAN = os.path.dirname(HERE)
payload = {}
for name in ("norm_eps_stale_min.py", "layer_norm_eps_stale2.py"):
    p = os.path.join(PLAN, "reports_scalar_seq", name)
    py_compile.compile(p, doraise=True)
    payload[name] = base64.b64encode(open(p, "rb").read()).decode()
JOBS = {
    "staleepslinux": '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]',
    "staleepsgpu": '[["--upgrade", "torch==2.14.0"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cu130"]]',
}
for job, install in JOBS.items():
    path = os.path.join(HERE, "jobs", job + ".py")
    with open(path, "w", encoding="utf-8") as f:
        f.write("# Kaggle script kernel: residual stale-float (norm eps).\n"
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
    py_compile.compile(path, doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"staleepslinux"' not in d:
    d = d.replace('    "int32gpu": ("tcc-int32gpu", True),\n', '    "int32gpu": ("tcc-int32gpu", True),\n    "staleepslinux": ("tcc-staleepslinux", False),\n    "staleepsgpu": ("tcc-staleepsgpu", True),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written")
