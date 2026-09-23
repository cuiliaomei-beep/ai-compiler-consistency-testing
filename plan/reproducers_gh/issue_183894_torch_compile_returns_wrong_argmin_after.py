# source: https://github.com/pytorch/pytorch/issues/183894
# title: torch.compile returns wrong argmin after in-place sin_ followed by transpose
# state: closed  created: 2026-05-15
# mined automatically; the harness records the torch.compile target and its first call

import torch

def f(x):
    x.sin_()
    y = x.t()
    return y.argmin()

torch.manual_seed(21)

x = torch.randn(5, 7)

eager = f(x.clone())
compiled = torch.compile(f, backend="inductor")(x.clone())

print("input_shape:", tuple(x.shape))
print("eager:", eager)
print("compiled:", compiled)

if not torch.equal(eager, compiled):
    raise SystemExit(0)

raise SystemExit(1)
