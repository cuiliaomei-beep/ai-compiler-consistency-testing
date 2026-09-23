"""Kaggle jobs for scripts/opinfo_edge_sweep.py with extra flags (Linux CPU, torch 2.14.0, resumable)."""
import base64, os, py_compile, sys
HERE = os.path.dirname(os.path.abspath(__file__))
code = open(os.path.join(os.path.dirname(HERE), "scripts", "opinfo_edge_sweep.py"), encoding="utf-8").read()
b = base64.b64encode(code.encode()).decode()
JOBS = {"edgeunsup": ["--unsupported", "--dtypes", "int8,uint8,int16,int32,int64,bool,float16,bfloat16,float32,float64,complex64"],
        "edgedyn": ["--dynamic", "--dtypes", "float32,int64,bool"]}
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
for job, flags in JOBS.items():
    path = os.path.join(HERE, "jobs", job + ".py")
    open(path, "w", encoding="utf-8").write(
        f"# Kaggle script kernel: {job}.\nimport base64, subprocess, sys\n"
        f'open("sweep.py", "wb").write(base64.b64decode("{b}"))\n'
        'subprocess.run(["pip", "-q", "install", "torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"])\n'
        'subprocess.run(["pip", "-q", "install", "expecttest", "hypothesis"])\n'
        "for attempt in range(80):\n"
        f'    r = subprocess.run([sys.executable, "sweep.py", *{flags!r}, "--out", "cases.jsonl"], capture_output=True, text=True)\n'
        '    print(r.stdout[-4000:], flush=True); print("exit", r.returncode, r.stderr[-600:], flush=True)\n'
        '    if "SWEEP DONE" in r.stdout: break\n'
        'print("=====JSONL BEGIN", flush=True)\nprint(open("cases.jsonl").read(), flush=True)\nprint("=====JSONL END", flush=True)\nprint("JOB DONE", flush=True)\n')
    py_compile.compile(path, doraise=True)
    if f'"{job}"' not in d:
        anchor = '    "fxpicklelinux": ("tcc-fxpicklelinux", False),\n'
        d = d.replace(anchor, anchor + f'    "{job}": ("tcc-{job}", False),\n')
open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written")
