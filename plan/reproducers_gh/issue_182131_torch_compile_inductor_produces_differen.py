# source: https://github.com/pytorch/pytorch/issues/182131
# title: torch.compile/Inductor produces different result for float16 cast before elementwise add
# state: closed  created: 2026-05-01
# mined automatically; the harness records the torch.compile target and its first call

import torch

print(torch.__version__)

x = torch.arange(24, dtype=torch.float32).reshape(2, 3, 4) / 10
c = (torch.arange(24) % 5 == 0).reshape(2, 3, 4)

def f(x, c):
    z = torch.where(c, torch.full_like(x, 0.5), torch.full_like(x, -0.5))
    y = z.to(torch.float16) + x.to(torch.float16)
    return y, y.float().sum()

eager = f(x, c)
compiled = torch.compile(f, backend="inductor", fullgraph=True)(x, c)

print("eager sum:   ", eager[1])
print("compiled sum:", compiled[1])
print("max diff:    ", (eager[0].float() - compiled[0].float()).abs().max())

torch.testing.assert_close(compiled[0], eager[0], rtol=0, atol=0)
torch.testing.assert_close(compiled[1], eager[1], rtol=0, atol=0)
