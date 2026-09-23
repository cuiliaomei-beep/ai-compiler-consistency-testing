# source: https://github.com/pytorch/pytorch/issues/187284
# title: `torch.compile` with `inductor` backend silently drops forward-mode AD tangents (returns `None`)
# state: closed  created: 2026-06-14
# mined automatically; the harness records the torch.compile target and its first call

import torch
import torch.autograd.forward_ad as fwAD

def fn(x):
    return (x ** 2).sum()

compiled_fn_inductor = torch.compile(fn, backend="inductor")
compiled_fn_cudagraphs = torch.compile(fn, backend="cudagraphs")

x = torch.tensor([0.1, 0.2, 0.3])
v = torch.ones(3)

with fwAD.dual_level():
    dual_input = fwAD.make_dual(x, v)
    out = compiled_fn_inductor(dual_input)
    jvp_inductor = fwAD.unpack_dual(out).tangent

with fwAD.dual_level():
    dual_input = fwAD.make_dual(x, v)
    out = compiled_fn_cudagraphs(dual_input)
    jvp_cudagraphs = fwAD.unpack_dual(out).tangent

with fwAD.dual_level():
    dual_input = fwAD.make_dual(x, v)
    out = fn(dual_input)
    jvp_eager = fwAD.unpack_dual(out).tangent

print("inductor compiled jvp:", jvp_inductor)
print("cudagraphs compiled jvp:", jvp_cudagraphs)
print("eager jvp:", jvp_eager)
