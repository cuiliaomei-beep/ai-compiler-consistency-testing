# Kaggle script kernel (GPU T4): 6.2 dtype-promotion matrix with Inductor on CUDA (Triton) and Linux CPU (g++).
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
run("pip", "-q", "install", "torch==2.14.0", check=False)
run(sys.executable, "-c", "import torch; print('TORCH', torch.__version__, torch.cuda.get_device_name(0))")
P = sys.executable
run(P, "run.py", "dtypes", "--backend", "inductor", "--device", "cuda", "--pairs", "all", "--forms", "tt,t0", "--out", "gpu_dtypes_cuda", check=False)
run(P, "run.py", "dtypes", "--backend", "inductor", "--device", "cuda", "--pairs", "float", "--forms", "tt", "--autocast", "--out", "gpu_dtypes_cuda_autocast", check=False)
run(P, "run.py", "dtypes", "--backend", "inductor", "--device", "cpu", "--pairs", "lowprec", "--forms", "tt,t0", "--out", "gpu_dtypes_cpu", check=False)
print("JOB DONE", flush=True)
