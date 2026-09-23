# source: https://github.com/pytorch/pytorch/issues/184394
# title: [inductor] Merge SymPy printer path into typed ops/CSE path for Triton codegen
# state: open  created: 2026-05-19
# mined automatically; the harness records the torch.compile target and its first call

import torch, math
from torch._inductor.utils import run_and_get_code

def fn(x):
    return x + 2 ** (math.floor(math.log2(x.shape[0]) + 1))

x = torch.arange(10, device="cuda", dtype=torch.float32)
out, codes = run_and_get_code(torch.compile(fn, dynamic=True), x)
print(codes[0])  # shows ks0.to(tl.float64)).to(tl.float32) inside libdevice.log2
