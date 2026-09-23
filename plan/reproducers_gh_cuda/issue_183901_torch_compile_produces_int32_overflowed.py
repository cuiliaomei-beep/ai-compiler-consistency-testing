# source: https://github.com/pytorch/pytorch/issues/183901
# title: torch.compile produces int32-overflowed results for int64 arange multiplication on CUDA
# state: open  created: 2026-05-15
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    return torch.arange(0, 9, device=x.device, dtype=torch.int64) * torch.tensor(
        [1500000000],
        dtype=torch.int64,
        device=x.device,
    )

if not torch.cuda.is_available():
    raise SystemExit(2)

x = torch.zeros(1, device="cuda")

eager = f(x)
compiled = torch.compile(f, backend="inductor")(x)

torch.cuda.synchronize()

print("eager:", eager.cpu())
print("compiled:", compiled.cpu())

if not torch.equal(eager, compiled):
    raise SystemExit(0)

raise SystemExit(1)
