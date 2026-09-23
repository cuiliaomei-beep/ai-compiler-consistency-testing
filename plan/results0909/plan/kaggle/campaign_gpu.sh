#!/usr/bin/env bash
# GPU campaigns, in the order of value. Every step resumes (progress.json), so a
# killed session loses at most one program. Outputs go under /kaggle/working/plan/gpu_*.
set -e
cd "${1:-/kaggle/working/plan}"
COMMON="--backend inductor --device cuda --reruns 2 --minimize --max-contexts 12 --test-budget 16 --time-budget 180 --isolate"

# 1. issue reproducers that were rejected on the CPU box because they need CUDA
python run.py mine --out reproducers_gh_cuda --pages 3 --allow-cuda || true
python run.py campaign --from-dir reproducers_gh_cuda $COMMON --search-duplicates --out gpu_reports_gh
python scripts/gh_summary.py reproducers_gh_cuda gpu_reports_gh || true

# 2. the CPU-mined reproducers again, now on the Triton path
python run.py campaign --from-dir reproducers_gh $COMMON --out gpu_reports_gh_cpu_set || true

# 3. built-in corpus + NNSmith models on CUDA (E3 = Inductor/Triton codegen)
python run.py campaign --nnsmith 10 $COMMON --out gpu_reports_corpus

# 4. OpInfo official samples on CUDA (largest surface; ~2 h on a T4)
python run.py campaign --opinfo 3000 --opinfo-samples 2 --seed 5 --no-corpus $COMMON --out gpu_reports_opinfo
python scripts/gh_summary.py reproducers_gh gpu_reports_opinfo || true

echo "all GPU campaigns finished; download /kaggle/working/plan/gpu_reports_*"
