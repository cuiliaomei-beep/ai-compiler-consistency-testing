# source: https://github.com/pytorch/pytorch/issues/185449
# title: Flash attention backend type not stored in inductor cache, causes silent usage of wrong backend
# state: closed  created: 2026-05-27
# mined automatically; the harness records the torch.compile target and its first call

"""Minimal repro: Inductor's FX graph cache key ignores the SDPA backend selection.

A `torch.compile`'d `F.scaled_dot_product_attention` lowers to a backend-specific
aten op (`_scaled_dot_product_flash_attention` vs `_scaled_dot_product_cudnn_attention`),
chosen from the active SDPA backend selection at compile time. But the on-disk FX
graph cache key does NOT include that selection -- neither the
`torch.nn.attention.sdpa_kernel(...)` context manager nor the
`torch.backends.cuda.enable_*_sdp(...)` flags.

So the first process to compile a given graph populates the cache, and later
processes sharing TORCHINDUCTOR_CACHE_DIR get a cache hit and silently reuse that
backend regardless of what they request. Below, one process compiles the graph
under flash, then a second process requesting cuDNN reuses the cached flash
artifact -- you can see it lower to `_scaled_dot_product_flash_attention` despite
asking for cuDNN. Setting TORCHINDUCTOR_FORCE_DISABLE_CACHES=1 makes the second
process correctly lower to cuDNN, confirming the FX graph cache key is the culprit.

We detect the selected backend by capturing Inductor's `output_code` log and
reading the aten op name from the generated wrapper -- this is the compile-time
selection itself, not a heuristic on runtime kernel names. (Note: don't sniff the
profiler's CUDA kernel names for this -- cuDNN's SDPA kernel on sm100 is named
`cudnn_generated_..._flash_fprop_...`, i.e. it contains the substring "flash",
which trips up naive name matching.)

Run:    python compile_sdpa_cache_repro.py
Compare: TORCHINDUCTOR_FORCE_DISABLE_CACHES=1 python compile_sdpa_cache_repro.py
Requires a CUDA GPU with both flash and cuDNN SDPA backends (sm80+).
"""

import io
import logging
import os
import re
import subprocess
import sys
import tempfile

import torch
from torch.nn.attention import SDPBackend, sdpa_kernel


def f(q, k, v):
    return torch.nn.functional.scaled_dot_product_attention(q, k, v)


def worker(backend: str) -> None:
    """Compile `f` under one SDPA backend; print the aten op Inductor selected."""
    bk = {"flash": SDPBackend.FLASH_ATTENTION, "cudnn": SDPBackend.CUDNN_ATTENTION}[backend]

    # Capture Inductor's generated wrapper code so we can read the selected op.
    buf = io.StringIO()
    torch._logging.set_logs(output_code=True)
    logging.getLogger("torch._inductor").addHandler(logging.StreamHandler(buf))

    # Match how a real consumer selects cuDNN: flip the global enable flag AND
    # enter the sdpa_kernel context. (Neither is part of the FX graph cache key.)
    torch.backends.cuda.enable_cudnn_sdp(backend == "cudnn")
    fc = torch.compile(f, dynamic=False)
    q = k = v = torch.randn(2, 8, 1024, 64, device="cuda", dtype=torch.float16)
    with sdpa_kernel(bk):
        fc(q, k, v)
        torch.cuda.synchronize()

    ops = set(re.findall(r"_scaled_dot_product_(\w+?)_attention", buf.getvalue()))
    print(f"OP={ops.pop() if len(ops) == 1 else sorted(ops)}")


def spawn(backend: str, cache_dir: str) -> str:
    """Run a worker in a fresh process sharing `cache_dir`; return the op it lowered to."""
    env = {**os.environ, "TORCHINDUCTOR_CACHE_DIR": cache_dir}
    out = subprocess.run([sys.executable, __file__, backend], env=env, capture_output=True, text=True).stdout
    return next(line[3:] for line in out.splitlines() if line.startswith("OP="))


if __name__ == "__main__":
    if len(sys.argv) > 1:  # worker mode
        worker(sys.argv[1])
        sys.exit()

    print("torch", torch.__version__, "| cuda", torch.version.cuda, "|", torch.cuda.get_device_name())
    print("TORCHINDUCTOR_FORCE_DISABLE_CACHES =", os.environ.get("TORCHINDUCTOR_FORCE_DISABLE_CACHES", "<unset>"))
    with tempfile.TemporaryDirectory() as cache_dir:  # one shared, initially-empty cache
        flash_op = spawn("flash", cache_dir)  # populates the cache
        cudnn_op = spawn("cudnn", cache_dir)  # should lower to cudnn; gets a cache hit instead
    print(f"process 1 requested flash -> lowered to {flash_op}")
    print(f"process 2 requested cudnn -> lowered to {cudnn_op}")
    assert flash_op == "flash", f"expected flash, got {flash_op}"
    if cudnn_op == "flash":
        print("\nBUG: the cuDNN process reused the cached flash artifact. "
              "Rerun with TORCHINDUCTOR_FORCE_DISABLE_CACHES=1 and process 2 correctly lowers to cudnn.")
    else:
        print(f"\nNo bug here: process 2 lowered to {cudnn_op} (cache disabled, or the cache key has been fixed).")
