"""Kaggle jobs: reports_pairs/half_intermediates_cpu.py on Linux CPU (halflinux: 2.14 + nightly) and on a T4 (halfgpu: 2.14.0+cu130 + nightly)."""
import base64, os, py_compile
HERE = os.path.dirname(os.path.abspath(__file__))
code = open(os.path.join(os.path.dirname(HERE), "reports_pairs", "half_intermediates_cpu.py"), encoding="utf-8").read()
b = base64.b64encode(code.encode()).decode()
INSTALL = {
    "halflinux": '[["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"]]',
    "halfgpu": '[["--upgrade", "torch==2.14.0"], ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cu130"]]',
}
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
for job, install in INSTALL.items():
    path = os.path.join(HERE, "jobs", job + ".py")
    open(path, "w", encoding="utf-8").write(
        f"# Kaggle script kernel: {job}.\nimport base64, subprocess, sys\n"
        f'open("half.py", "wb").write(base64.b64decode("{b}"))\n'
        f"for spec in {install}:\n"
        '    subprocess.run(["pip", "-q", "install", *spec])\n'
        '    subprocess.run([sys.executable, "half.py"])\nprint("JOB DONE", flush=True)\n')
    py_compile.compile(path, doraise=True)
    if f'"{job}"' not in d:
        anchor = '    "fxpicklelinux": ("tcc-fxpicklelinux", False),\n'
        assert anchor in d
        d = d.replace(anchor, anchor + f'    "{job}": ("tcc-{job}", {job.endswith("gpu")}),\n')
open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("jobs written")
