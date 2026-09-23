# Kaggle script kernel (GPU): binding-form variants through the full pipeline (corpus + issue reproducers).
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
P = sys.executable
COMMON = ["--binding-variants", "1", "--binding-only", "--backend", "inductor", "--device", "cuda", "--reruns", "2",
          "--max-contexts", "4", "--test-budget", "6", "--isolate", "--child-timeout", "900"]
run(P, "run.py", "campaign", *COMMON, "--out", "gpu_reports_binding_corpus", check=False)
run(P, "run.py", "campaign", "--from-dir", "reproducers_gh", *COMMON, "--out", "gpu_reports_binding_gh", check=False)
print("JOB DONE", flush=True)
