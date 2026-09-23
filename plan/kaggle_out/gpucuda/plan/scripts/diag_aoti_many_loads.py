"""Does loading many AOTI packages in one process (Windows) eventually crash? Mirrors the sweep's pattern:
export -> aoti_compile_and_package -> aoti_load_package -> run, N times, plus a torch.compile in between."""
import os
import sys
import tempfile
import time

HERE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, HERE)
from tcc.compat import ensure_msvc_env  # noqa: E402

ensure_msvc_env()
import torch  # noqa: E402
from torch.export import export  # noqa: E402
from torch._inductor import aoti_compile_and_package, aoti_load_package  # noqa: E402

N = int(sys.argv[1]) if len(sys.argv) > 1 else 60
work = tempfile.mkdtemp(prefix="tcc_many_")
print(torch.__version__, "N =", N, flush=True)
t0 = time.time()
for i in range(N):
    k = float(i + 1)

    class M(torch.nn.Module):
        def forward(self, x):
            return (x * k + 1.0).relu().sum(dim=0)
    x = torch.randn(3 + i % 5, 4)
    m = M()
    ep = export(m, (x,))
    p = aoti_compile_and_package(ep, package_path=os.path.join(work, f"m{i}.pt2"))
    r = aoti_load_package(p)
    out = r(x)
    ok = torch.allclose(out, m(x))
    torch._dynamo.reset()
    c = torch.compile(m)(x)
    if i % 5 == 0 or not ok:
        print(f"[{i}] aoti ok={ok} compile ok={torch.allclose(c, m(x))} elapsed={time.time() - t0:.0f}s", flush=True)
print("done without crash", flush=True)
