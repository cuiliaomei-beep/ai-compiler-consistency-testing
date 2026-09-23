# Kaggle script kernel (CPU): torch nightly (CPU wheel) -> re-check every candidate + one decomposition sweep.
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
run("pip", "-q", "install", "--pre", "--upgrade", "torch", "--index-url", "https://download.pytorch.org/whl/nightly/cpu", check=False)
run("pip", "-q", "install", "expecttest", "hypothesis", check=False)
run(sys.executable, "-c", "import torch; print('TORCH', torch.__version__, torch.version.git_version)")
run(sys.executable, "scripts/verify_candidates_cuda.py", "cpu", check=False)
run(sys.executable, "run.py", "decomp", "--isolate", "--samples", "1", "--out", "nightly_results_decomp", check=False)
run(sys.executable, "run.py", "decomp", "--isolate", "--grad", "--samples", "1", "--out", "nightly_results_decomp_grad", check=False)
print("JOB DONE", flush=True)
