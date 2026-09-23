# Kaggle T4: 8.12 cudagraph (reduce-overhead) stale-output detection only.
import glob, os, shutil, subprocess, sys


def run(*a, check=True, env=None):
    print("$", " ".join(a), flush=True)
    r = subprocess.run(list(a), env=env)
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
run("pip", "-q", "install", "--upgrade", "torch==2.14.0", check=False)
run("pip", "-q", "install", "expecttest", "hypothesis", check=False)
run(P, "-c", "import torch; print('torch', torch.__version__, torch.cuda.get_device_name(0), flush=True)")

run(P, "scripts/cudagraph_stale_sweep.py", check=False)

for d in os.listdir("."):
    if d != "results":
        (shutil.rmtree if os.path.isdir(d) else os.remove)(d)
print("JOB DONE", flush=True)
