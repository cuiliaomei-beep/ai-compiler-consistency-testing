# Kaggle script kernel (GPU): torchvision real-model reproducers through the pipeline (5.7).
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
run("pip", "-q", "install", "nnsmith", "certifi", "expecttest", "hypothesis", check=False)
run(sys.executable, "run.py", "selfcheck", check=False)
run(sys.executable, "run.py", "campaign", "--from-dir", "reproducers_models", "--backend", "inductor", "--device", "cuda",
    "--reruns", "2", "--minimize", "--max-contexts", "6", "--test-budget", "8", "--time-budget", "300", "--isolate",
    "--child-timeout", "1200", "--out", "gpu_reports_models", check=False)
print("JOB DONE", flush=True)
