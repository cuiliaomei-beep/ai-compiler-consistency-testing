# Kaggle Linux CPU (Python 3.12): 8.7 platform / Python-version differential of the Dynamo semantics corpus
# (run.py dynsem, 185 programs, backend=eager, static + dynamic) on torch 2.14.0 and nightly.  Compare with the local
# Windows / Python 3.14 results in plan/results/dynsem3{,_dynamic}.
import glob, os, shutil, subprocess, sys


def run(*a, check=True):
    print("$", " ".join(a), flush=True)
    r = subprocess.run(list(a))
    if check and r.returncode:
        print(f"!! exit {r.returncode}", flush=True)
    return r.returncode


runs = glob.glob("/kaggle/input/**/run.py", recursive=True)
if not runs:
    import zipfile
    zipfile.ZipFile(glob.glob("/kaggle/input/**/plan_kaggle.zip", recursive=True)[0]).extractall("/kaggle/working/unz")
    runs = glob.glob("/kaggle/working/unz/**/run.py", recursive=True)
shutil.copytree(os.path.dirname(runs[0]), "/kaggle/working/plan", dirs_exist_ok=True)
os.chdir("/kaggle/working/plan")
P = sys.executable
run(P, "-c", "import sys; print(sys.version)")
for tag, spec in (("214", ["torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu"]),
                  ("nightly", ["--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu"])):
    run("pip", "-q", "install", *spec, check=False)
    run(P, "-c", "import torch; print('torch', torch.__version__, flush=True)")
    run(P, "run.py", "dynsem", "--out", f"results/dynsem_linux_{tag}", check=False)
    run(P, "run.py", "dynsem", "--dynamic", "--out", f"results/dynsem_linux_{tag}_dynamic", check=False)
    run(P, "run.py", "dynsem", "--backend", "aot_eager", "--out", f"results/dynsem_linux_{tag}_aot", check=False)
    run(P, "scripts/graph_break_insertion_diff.py", "--backend", "eager", check=False)
    shutil.copytree("results/graph_break_insertion", f"results/graph_break_insertion_{tag}", dirs_exist_ok=True)
print("JOB DONE", flush=True)
