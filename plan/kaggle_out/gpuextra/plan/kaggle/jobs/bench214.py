# Kaggle script kernel: issue reproducers on torch 2.14.0+cpu (same-device pair, side B). CPU only.
import glob, os, shutil, subprocess, sys

TORCH = "2.14.0"
OUT = "reports_gh_cpu_2.14"


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
run("pip", "-q", "install", f"torch=={TORCH}", "--index-url", "https://download.pytorch.org/whl/cpu", check=False)
run("pip", "-q", "install", "nnsmith", "certifi", "expecttest", "hypothesis", check=False)
run(sys.executable, "-c", "import torch; print('TORCH', torch.__version__)")
run(sys.executable, "run.py", "selfcheck", "--offline", check=False)
run(sys.executable, "run.py", "campaign", "--from-dir", "reproducers_gh", "--backend", "inductor", "--reruns", "2",
    "--max-contexts", "12", "--test-budget", "16", "--time-budget", "180", "--isolate", "--child-timeout", "900",
    "--out", OUT, check=False)
run(sys.executable, "scripts/gh_summary.py", "reproducers_gh", OUT, check=False)
print("JOB DONE", flush=True)
