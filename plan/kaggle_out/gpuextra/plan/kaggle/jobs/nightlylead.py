# Kaggle script kernel (CPU): torch nightly -> reproduce the nightly-only grad leads (quantile prime_dim0, nll_loss channels_last).
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
run(sys.executable, "scripts/diag_nightly_grad_leads.py", check=False)
for seed in ("0", "1"):
    for n in ("1", "2"):
        run(sys.executable, "run.py", "decomp", "--grad", "--only", "quantile,nanquantile", "--samples", n, "--seed", seed,
            "--out", f"nightly_lead_quantile_s{seed}_n{n}", check=False)
run(sys.executable, "run.py", "decomp", "--grad", "--isolate", "--only", "quantile,nanquantile", "--samples", "1", "--seed", "0",
    "--out", "nightly_lead_quantile_isolated", check=False)
print("JOB DONE", flush=True)
