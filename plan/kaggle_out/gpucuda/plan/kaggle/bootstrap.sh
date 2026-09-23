#!/usr/bin/env bash
# Kaggle / Colab bootstrap for the tcc pipeline.
#   1. upload plan_kaggle.zip as a Kaggle Dataset (e.g. "tcc-plan")
#   2. in a GPU notebook:  !bash /kaggle/input/tcc-plan/bootstrap.sh
set -e
SRC=${1:-/kaggle/input/tcc-plan/plan_kaggle.zip}
WORK=${2:-/kaggle/working/plan}
mkdir -p "$WORK"
unzip -qo "$SRC" -d "$WORK/.."
cd "$WORK"
pip -q install nnsmith certifi expecttest hypothesis 2>/dev/null || true   # expecttest/hypothesis: OpInfo op_db
python - <<'EOF'
import torch
print("torch", torch.__version__, "cuda", torch.cuda.is_available(),
      torch.cuda.get_device_name(0) if torch.cuda.is_available() else "")
try:
    import triton; print("triton", triton.__version__)
except Exception as e:
    print("triton missing:", e)
EOF
python run.py selfcheck --offline
python run.py selfcheck
echo "bootstrap done; next: bash kaggle/campaign_gpu.sh"
