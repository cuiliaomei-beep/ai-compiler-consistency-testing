# Kaggle script kernel (GPU T4): install torch 2.14 (cu128) and re-check every candidate on CUDA and Linux CPU.
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
# the cu128 index stops at 2.11; PyPI carries the default CUDA build of 2.14
run("pip", "-q", "install", "--upgrade", "torch==2.14.0", check=False)
run(sys.executable, "-c", "import torch; print('TORCH', torch.__version__, torch.cuda.get_device_name(0)); "
    "print('cuda ok', (torch.ones(4, device='cuda') * 2).sum().item())")
run(sys.executable, "scripts/verify_candidates_cuda.py", "cuda", check=False)
run(sys.executable, "scripts/verify_candidates_cuda.py", "cpu", check=False)   # same torch 2.14 on Linux CPU
print("JOB DONE", flush=True)
