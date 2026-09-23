# Kaggle script kernel (CPU): 6.1 Inductor config-knob differential (metamorphic 'config' relation) on Linux CPU, torch 2.14.
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
run("pip", "-q", "install", "torch==2.14.0", "--index-url", "https://download.pytorch.org/whl/cpu", check=False)
run("pip", "-q", "install", "nnsmith", "expecttest", "hypothesis", check=False)
run(sys.executable, "-c", "import torch; print('TORCH', torch.__version__)")
P = sys.executable
KNOBS = "base,coordinate_descent,padding,no_layout_opt,decompose_mm,simd8,simd16,cpp_dynamic_threads,cpp_no_tiling,cpp_min_chunk1,scatter_no_fallback,aggressive_fusion,no_reorder,no_caches,no_size_asserts,cpp_wrapper,no_pattern_matcher,emulate_casts,no_fusion,no_vec"
run(P, "run.py", "metamorphic", "--isolate", "--source", "opinfo", "--configs", KNOBS, "--relations", "config", "--out", "knobs_opinfo", check=False)
run(P, "run.py", "metamorphic", "--isolate", "--source", "both", "--models", "60", "--configs", KNOBS, "--relations", "config", "--out", "knobs_programs", check=False)
print("JOB DONE", flush=True)
