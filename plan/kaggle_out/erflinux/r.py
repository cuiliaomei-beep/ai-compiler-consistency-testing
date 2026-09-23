import os, sys, tempfile, math
os.environ["TORCHINDUCTOR_CACHE_DIR"] = tempfile.mkdtemp(prefix="tcc_erf_")
import torch
from mpmath import mp, erf as mperf
mp.dps = 30
print("torch", torch.__version__, "capability", torch.backends.cpu.get_cpu_capability())
from torch._inductor import cpu_vec_isa as v; print("inductor isa", v.pick_vec_isa())
vals = [1e-38, 1e-30, 1e-20, 1e-10, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 0.1, 0.5, 1.0, 2.0, 3.0]
for dt in (torch.float32, torch.float64):
    for n in (3, 64):
        x = torch.tensor((vals * 8)[:n], dtype=dt)
        torch._dynamo.reset(); c = torch.compile(torch.erf)(x); e = torch.erf(x)
        print(f"{str(dt):14s} n={n:2d}")
        for i, v in enumerate(vals[:len(x)] if n < len(vals) else vals):
            r = float(mperf(mp.mpf(x[i].item()))); ev, cv = e[i].item(), c[i].item()
            print(f"    x={x[i].item():.3g}: eager rel {abs(ev - r) / abs(r):.1e}  compiled rel {abs(cv - r) / abs(r):.1e}  (compiled {cv:.6g})")