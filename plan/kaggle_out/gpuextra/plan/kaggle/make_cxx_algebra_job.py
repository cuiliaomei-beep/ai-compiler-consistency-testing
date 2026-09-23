"""Build the Kaggle job that runs scripts/cxx_intrinsic_algebra_diff.py with g++ and clang++ on Linux."""
import base64
import os

HERE = os.path.dirname(os.path.abspath(__file__))
src = open(os.path.join(os.path.dirname(HERE), "scripts", "cxx_intrinsic_algebra_diff.py"), encoding="utf-8").read()
b = base64.b64encode(src.encode()).decode()
job = '''# Kaggle script kernel: optimisation-level differential over SIMD intrinsic compositions with g++ / clang++.
import base64, os, subprocess, sys
os.makedirs("plan/scripts", exist_ok=True)
open("plan/scripts/cxx_intrinsic_algebra_diff.py", "wb").write(base64.b64decode("%s"))
flags = open("/proc/cpuinfo").read().split("flags", 1)[1].splitlines()[0]
widths = "128,256,512" if all(f in flags.split() for f in ("avx512f", "avx512bw", "avx512dq", "avx512vl")) else "128,256"
print("cpu widths:", widths, flush=True)
subprocess.run("g++ --version | head -1; (clang++ --version || (apt-get -qq update && apt-get -qq install -y clang >/dev/null 2>&1; clang++ --version)) | head -1", shell=True)
for comp in ("gcc", "clang"):
    print("=====", comp, flush=True)
    subprocess.run([sys.executable, "plan/scripts/cxx_intrinsic_algebra_diff.py", "--compiler", comp, "--widths", widths])
print("===== report", flush=True)
subprocess.run([sys.executable, "plan/scripts/cxx_intrinsic_algebra_diff.py", "--report"])
subprocess.run("rm -rf plan/results/cxx_algebra/*/src plan/results/cxx_algebra/*/algebra_*", shell=True)
print("JOB DONE", flush=True)
''' % b
open(os.path.join(HERE, "jobs", "cxxalgebra.py"), "w", encoding="utf-8").write(job)
import py_compile
py_compile.compile(os.path.join(HERE, "jobs", "cxxalgebra.py"), doraise=True)
d = open(os.path.join(HERE, "drive.py"), encoding="utf-8").read()
if '"cxxalgebra"' not in d:
    d = d.replace('    "rewritegpu": ("tcc-rewritegpu", True),\n', '    "rewritegpu": ("tcc-rewritegpu", True),\n    "cxxalgebra": ("tcc-cxxalgebra", False),\n')
    open(os.path.join(HERE, "drive.py"), "w", encoding="utf-8").write(d)
print("job written")
