# source: https://github.com/pytorch/pytorch/issues/181568
# title: torch.compile mismatch for matmul followed by bfloat16 cast and fp32 add
# state: closed  created: 2026-04-27
# mined automatically; the harness records the torch.compile target and its first call

import torch

print(torch.__version__)

torch.manual_seed(119)

def f(x, w, b):
    y = (x @ w).to(torch.bfloat16) + b
    return y, y.mean(-1)

x = torch.randn(2, 15, 32)
w = torch.randn(32, 17)
b = torch.randn(17)

ref = f(x, w, b)
got = torch.compile(
    f,
    backend="inductor",
    fullgraph=True,
    dynamic=True,
)(x, w, b)

for name, r, g in zip(["out", "mean"], ref, got):
    diff = (r.float() - g.float()).abs()
    print(
        name,
        "max_abs_diff =", diff.max().item(),
        "mean_abs_diff =", diff.mean().item(),
        "diff_count =", int((diff != 0).sum()),
        "numel =", r.numel(),
    )
    torch.testing.assert_close(r, g)
