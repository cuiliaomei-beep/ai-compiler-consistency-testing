# source: https://github.com/pytorch/pytorch/issues/189054
# title: [Compile, 2.10 and 2.11, but not in 2.12.1] Compile with `"max-autotune-no-cudagraphs"` could overflow when shape is large
# state: closed  created: 2026-07-06
# mined automatically; the harness records the torch.compile target and its first call

import torch

M, K = 32768, 1024

torch.manual_seed(0)
for N in (65536, 131072):
    x = torch.randn(M, K, device="cuda", dtype=torch.bfloat16)
    w = torch.randn(N, K, device="cuda", dtype=torch.bfloat16)
    ref = x[-64:] @ w.mT
    for mode in (None, "max-autotune-no-cudagraphs"):
        torch._dynamo.reset()
        mm = torch.compile(lambda a, b: a @ b.mT, dynamic=False, fullgraph=True, mode=mode)
        err = (mm(x, w)[-64:] - ref).abs().max().item()
        print(f"out.numel() = 2**{(M * N).bit_length() - 1}, mode = {str(mode):28s} max_abs_err = {err}")
        torch.cuda.empty_cache()
