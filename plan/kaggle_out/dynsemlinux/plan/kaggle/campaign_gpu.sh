#!/usr/bin/env bash
# GPU campaigns, in the order of value. Every step resumes (progress.json), so a
# killed session loses at most one program. Outputs go under /kaggle/working/plan/gpu_*.
set -e
cd "${1:-/kaggle/working/plan}"
COMMON="--backend inductor --device cuda --reruns 2 --minimize --max-contexts 12 --test-budget 16 --time-budget 180 --isolate"

# 0. (new, 2026-09-10) the no-compile / compiled-vs-compiled sweeps: cheapest and the most productive on CPU
python run.py decomp --isolate --samples 2 --out gpu_results_decomp || true                  # 5.1/5.2 (uses CPU tensors)
python run.py metamorphic --isolate --samples 1 --device cuda --out gpu_results_meta || true  # 5.3 incl. cudagraphs / persistent reductions
python run.py binding --isolate --samples 1 --device cuda --out gpu_results_binding || true   # 5.4
python run.py metamorphic --isolate --samples 2 --seed 2 --device cuda --relations config --configs max_autotune,cudagraphs,no_persistent_reductions --out gpu_results_meta_cfg || true   # GPU-only configs
python run.py aoti --isolate --samples 1 --device cuda --out gpu_results_aoti || true         # 5.8 export + AOTInductor (Triton)
python run.py diskcache --out gpu_results_diskcache || true                                  # 5.6 (CPU-side keys, quick)

# 1. issue reproducers that were rejected on the CPU box because they need CUDA
python run.py mine --out reproducers_gh_cuda --pages 3 --allow-cuda || true
python run.py campaign --from-dir reproducers_gh_cuda $COMMON --search-duplicates --out gpu_reports_gh
python scripts/gh_summary.py reproducers_gh_cuda gpu_reports_gh || true

# 2. real models (5.7): torchvision small models x {fp32, channels_last, bf16 autocast, train, dynamic} + torchvision.ops
python run.py campaign --from-dir reproducers_models $COMMON --max-contexts 6 --test-budget 8 --out gpu_reports_models || true

# 3. the CPU-mined reproducers again, now on the Triton path
python run.py campaign --from-dir reproducers_gh $COMMON --out gpu_reports_gh_cpu_set || true

# 4. built-in corpus + NNSmith models on CUDA (E3 = Inductor/Triton codegen)
python run.py campaign --nnsmith 10 $COMMON --out gpu_reports_corpus

# 5. OpInfo official samples on CUDA (largest surface; ~2 h on a T4)
python run.py campaign --opinfo 3000 --opinfo-samples 2 --seed 5 --no-corpus $COMMON --out gpu_reports_opinfo
python scripts/gh_summary.py reproducers_gh gpu_reports_opinfo || true

echo "all GPU campaigns finished; download /kaggle/working/plan/gpu_reports_* and gpu_results_*"
