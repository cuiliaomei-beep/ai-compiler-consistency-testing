# source: https://github.com/pytorch/pytorch/issues/183761
# title: torch.compile produces different fp16 results for where + full_like + cast + add pattern
# state: closed  created: 2026-05-14
# mined automatically; the harness records the torch.compile target and its first call

import sys
import torch

x = torch.arange(30, dtype=torch.float32).reshape(2, 3, 5) / 7
m = (torch.arange(30) % 4 == 0).reshape(2, 3, 5)

def f(x, m):
    z = torch.where(m, torch.full_like(x, 0.75), torch.full_like(x, -0.25))
    y = z.to(torch.float16) + x.to(torch.float16)
    return y, y.float().sum()

eager = f(x, m)
compiled = torch.compile(f, backend="inductor", fullgraph=True)(x, m)

diff = (eager[0].float() - compiled[0].float()).abs()

print("input_head:", x.reshape(-1)[:10])
print("mask_head:", m.reshape(-1)[:10])
print("eager_sum:", eager[1])
print("compiled_sum:", compiled[1])
print("max_abs_diff:", diff.max())
print("diff_count:", int((diff != 0).sum()))

sys.exit(0 if (not torch.equal(eager[0], compiled[0]) or not torch.equal(eager[1], compiled[1])) else 1)
