# source: https://github.com/pytorch/pytorch/issues/194345
# title: [inductor][cuda] `torch.remainder` / `torch.fmod` wrong results under `torch.compile` on CUDA for large |a/b| ratios
# state: open  created: 2026-08-21
# mined automatically; the harness records the torch.compile target and its first call

import torch

def main():
    cases = [
        (torch.remainder, 1e10, 1e-20, torch.float32),
        (torch.remainder, 65504.0, 6e-8, torch.float32),
        (torch.remainder, 3.4e38, 1.4e-45, torch.float32),
        (torch.fmod, 3.4e38, 1.4e-45, torch.float32),
        (torch.remainder, 3.39e38, 9.2e-41, torch.bfloat16),
    ]
    for fn, a, b, dtype in cases:
        x = torch.tensor([a], dtype=dtype, device="cuda")
        y = torch.tensor([b], dtype=dtype, device="cuda")
        e = fn(x, y)
        torch._dynamo.reset()
        c = torch.compile(fn)(x, y)
        print(fn.__name__, a, b, dtype, "eager=", e.item(), "compiled=", c.item())

main()
