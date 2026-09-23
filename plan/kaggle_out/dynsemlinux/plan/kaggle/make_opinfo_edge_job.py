"""Kaggle jobs: scripts/opinfo_edge_sweep.py on Linux CPU (gcc), torch 2.14.0, one kernel per dtype group; results printed as JSONL between markers."""
import base64, os, py_compile
HERE = os.path.dirname(os.path.abspath(__file__))
code = open(os.path.join(os.path.dirname(HERE), "scripts", "opinfo_edge_sweep.py"), encoding="utf-8").read()
b = base64.b64encode(code.encode()).decode()
GROUPS = {"edgewide": "int64,float64,complex64"}   # edgelowfp (float16,bfloat16) already pushed with the first version
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
for job, dtypes in GROUPS.items():
    path = os.path.join(HERE, "jobs", job + ".py")
    open(path, "w", encoding="utf-8").write(
        f"# Kaggle script kernel: {job}.\nimport base64, subprocess, sys\n"
        f'open("sweep.py", "wb").write(base64.b64decode("{b}"))\n'
        'subprocess.run(["pip", "-q", "install", "torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"])\n'
        'subprocess.run(["pip", "-q", "install", "expecttest", "hypothesis"])\n'
        "for attempt in range(80):   # the sweep process can be killed (SIGFPE on integer division by zero); it resumes and records the pair as CRASH\n"
        f'    r = subprocess.run([sys.executable, "sweep.py", "--dtypes", "{dtypes}", "--out", "cases.jsonl"], capture_output=True, text=True)\n'
        '    print(r.stdout[-4000:], flush=True); print("exit", r.returncode, r.stderr[-600:], flush=True)\n'
        '    if "SWEEP DONE" in r.stdout: break\n'
        'print("=====JSONL BEGIN", flush=True)\nprint(open("cases.jsonl").read(), flush=True)\nprint("=====JSONL END", flush=True)\n'
        'print("JOB DONE", flush=True)\n')
    py_compile.compile(path, doraise=True)
    if f'"{job}"' not in d:
        anchor = '    "fxpicklelinux": ("tcc-fxpicklelinux", False),\n'
        d = d.replace(anchor, anchor + f'    "{job}": ("tcc-{job}", False),\n')
open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written")
