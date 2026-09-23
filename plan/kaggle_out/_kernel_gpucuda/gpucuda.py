# Kaggle script kernel (GPU T4): only the CUDA-dependent sweeps (the CPU-tensor decomp sweeps already ran).
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
run(sys.executable, "-c", "import torch; print('GPU', torch.cuda.get_device_name(0), torch.__version__); "
    "x = torch.ones(4, device='cuda'); print('cuda ok', (x * 2).sum().item())")
run(sys.executable, "run.py", "selfcheck", check=False)
P = sys.executable
run(P, "run.py", "metamorphic", "--isolate", "--samples", "2", "--seed", "2", "--device", "cuda", "--relations", "config",
    "--configs", "dynamic,max_autotune,cudagraphs,no_persistent_reductions,no_multi_kernel", "--chunk-size", "20",
    "--out", "gpu_results_meta_cfg", check=False)
run(P, "run.py", "aoti", "--isolate", "--samples", "1", "--device", "cuda", "--chunk-size", "20", "--out", "gpu_results_aoti", check=False)
run(P, "run.py", "binding", "--isolate", "--samples", "1", "--device", "cuda", "--chunk-size", "15", "--out", "gpu_results_binding", check=False)
print("JOB DONE", flush=True)
